/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Game
*/

#include "Game.hpp"

Game::Game()
{
    this->_scene = _Scene::FEATURES;
}

Game::~Game()
{
}

void Game::loadSave()
{
    std::ifstream file("./save/save.txt");
    std::string line;
    int nbLine = 0;

    std::string name;
    std::string id;
    std::string time;
    int hour, minute;
    std::vector<std::pair<int, int>> inventory;

    while (std::getline(file, line)) {
        nbLine++;
        if (line.find("[Player Infos]") != line.npos) {
            std::getline(file, line);

            // Extraire le nom entre les guillemets
            size_t first_quote_pos = line.find("\"");
            size_t last_quote_pos = line.find_last_of("\"");
            name = line.substr(first_quote_pos + 1, last_quote_pos - first_quote_pos - 1);

            std::getline(file, line);

            // Extraire l'ID entre les guillemets
            first_quote_pos = line.find("\"");
            last_quote_pos = line.find_last_of("\"");
            id = line.substr(first_quote_pos + 1, last_quote_pos - first_quote_pos - 1);

            std::getline(file, line);

            // Extraire le temps de jeu
            time = line.substr(line.find(": ") + 2);
            hour = std::stoi(time.substr(0, time.find(" ")));
            minute = std::stoi(time.substr(time.find(" ") + 1));

            // Ignorer les lignes suivantes
            std::getline(file, line);
            std::getline(file, line);
            std::getline(file, line);

            // Lire l'inventaire du joueur
            while (std::getline(file, line)) {
                // Format de la ligne : "1: 10"
                int idItem = std::stoi(line.substr(0, line.find(":")));
                int nbItem = std::stoi(line.substr(line.find(":") + 2));
                inventory.push_back(std::make_pair(idItem, nbItem));
            }
        }
    }

    this->_playerName = name;
    this->_playerId = id;
    this->hourPlayed = hour;
    this->minutePlayed = minute;
    this->_inventoryPlayer = inventory;

    file.close();
}

void Game::run()
{
    const int screenWidth = 1920;
    const int screenHeight = 1000;


    InitWindow(screenWidth, screenHeight, "Pokemon - Rouge");
    
    // enlever les bordures de la fenetre
    SetWindowState(FLAG_WINDOW_UNDECORATED);

    SetTargetFPS(240);

    // ------------------ INIT SCENES ------------------ //
    // Font myFont = LoadFontEx("./Media/font/Prototype.ttf", 96, 0, 250);

    
    // Font Spiegel = LoadFontEx("./Media/Fonts_Package/Fonts_Package/Spiegel-TTF/Spiegel_TT_Bold.ttf", 96, 0, 250);

    // ------------------ CREATE ENTITIES ------------------ //
    loadSave();

    ECS::IEntity player("player");
    Image img = LoadImage("./Media/sprite_down.png");
    Image img2 = LoadImage("./Media/sprite_left.png");
    Image img3 = LoadImage("./Media/sprite_right.png");
    Image img4 = LoadImage("./Media/sprite_up.png");
    player.addComponent<ECS::PositionComponent2d>(Vector2{150, 150}, "playerPosition");

    player.addComponent<ECS::TextureDown>(img, "player_down");
    player.addComponent<ECS::TextureLeft>(img2, "player_left");
    player.addComponent<ECS::TextureRight>(img3, "player_right");
    player.addComponent<ECS::TextureUp>(img4, "player_up");
    
    player.addComponent<ECS::ItemsPlayer>("itemsPlayer");
    player.addComponent<ECS::InfosPlayer>("infosPlayer", this->_playerName, this->_playerId, this->hourPlayed, this->minutePlayed, this->_inventoryPlayer);

    Features featuresScene(this->_scene, _soundManager, player);
    
    featuresScene.addEntity(std::make_shared<ECS::IEntity>(player));

    // ------------------ BUILDER SCENES ------------------ //
    this->allScenes[_Scene::FEATURES] = std::make_unique<Features>(featuresScene);
    
    
    // ------------------ MAIN LOOP ------------------ //
    float deltaTime = 0.0f;

    while (!WindowShouldClose()) {
        deltaTime = GetFrameTime();
        this->allScenes[this->_scene]->update(deltaTime, GetTime());
        this->allScenes[this->_scene]->draw();
    }
    CloseWindow();
}
