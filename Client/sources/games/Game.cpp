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


    ECS::Ecs3D::IEntity player("player");
    Image img = LoadImage("./Media/sprite_down.png");
    Image img2 = LoadImage("./Media/sprite_left.png");
    Image img3 = LoadImage("./Media/sprite_right.png");
    Image img4 = LoadImage("./Media/sprite_up.png");
    player.addComponent<ECS::Ecs3D::PositionComponent2d>(Vector2{150, 150}, "playerPosition");

    player.addComponent<ECS::Ecs3D::TextureDown>(img, "player_down");
    player.addComponent<ECS::Ecs3D::TextureLeft>(img2, "player_left");
    player.addComponent<ECS::Ecs3D::TextureRight>(img3, "player_right");
    player.addComponent<ECS::Ecs3D::TextureUp>(img4, "player_up");


    Features featuresScene(this->_scene, _soundManager, player);
    
    featuresScene.addEntity(std::make_shared<ECS::Ecs3D::IEntity>(player));

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
