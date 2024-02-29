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
    const int screenHeight = 1080;


    InitWindow(screenWidth, screenHeight, "Pokemon - Rouge");
    SetTargetFPS(240);

    // ------------------ INIT SCENES ------------------ //
    // Font myFont = LoadFontEx("./Media/font/Prototype.ttf", 96, 0, 250);

    rtype::Features featuresScene(this->_scene, _soundManager);
    // Font Spiegel = LoadFontEx("./Media/Fonts_Package/Fonts_Package/Spiegel-TTF/Spiegel_TT_Bold.ttf", 96, 0, 250);

    // ------------------ CREATE ENTITIES ------------------ //

    rtype::ECS::Ecs3D::IEntity player("player");
    Image img = LoadImage("./Media/player.png");
    player.addComponent<rtype::ECS::Ecs3D::PositionComponent2d>(Vector2{0, 0}, "playerPosition");
    player.addComponent<rtype::ECS::Ecs3D::Texture2d>(img, "playerTexture");
    featuresScene.addEntity(std::make_shared<rtype::ECS::Ecs3D::IEntity>(player));

    // ------------------ BUILDER SCENES ------------------ //
    this->allScenes[_Scene::FEATURES] = std::make_unique<rtype::Features>(featuresScene);

    // print all entities of the scene
    
    std::cout << "dans la scene login dans le game:" << std::endl;
    featuresScene.printEntitiesWithComponents();

    // ------------------ MAIN LOOP ------------------ //
    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        this->allScenes[this->_scene]->update(deltaTime, GetTime());
        this->allScenes[this->_scene]->draw();
    }
    CloseWindow();
}
