/*
** File description:
** Features
*/

#include "Features.hpp"

rtype::Features::~Features()
{
}

void rtype::Features::parseAndFillPnj(std::string path)
{
    std::ifstream file("./maps/pnj.txt");

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if (line == "-") {
                std::string name;
                Vector2 position;

                std::getline(file, name);
                std::getline(file, line);  // Lire la ligne avec les coordonnées
                std::istringstream iss(line);
                iss >> position.x >> position.y;
                
                rtype::ECS::Ecs3D::IEntity entity("pnj" + std::to_string(this->_pnj.size()));
                entity.addComponent<rtype::ECS::Ecs3D::PnjNameComponent>(name, "pnjName");
                entity.addComponent<rtype::ECS::Ecs3D::PnjPosComponent>(position, "pnjPosition");
                this->_pnj.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_pnj.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));
            }
        }
        file.close();
    } else {
        std::cerr << "Impossible d'ouvrir le fichier.\n";
    }
}

void rtype::Features::draw()
{
    BeginDrawing();
        ClearBackground(Color{255, 255, 255, 255});
        BeginMode2D(this->camera);
            for (int i = 0; i < this->_map.size(); i++) {
                DrawTexture(this->_map[i]->getComponent<rtype::ECS::Ecs3D::Texture2d>()->texture, this->_map[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x, this->_map[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y, WHITE);
            }

            // draw pnj
            for (int i = 0; i < this->_pnj.size(); i++) {
                DrawRectangle(this->_pnj[i]->getComponent<rtype::ECS::Ecs3D::PnjPosComponent>()->position.x, this->_pnj[i]->getComponent<rtype::ECS::Ecs3D::PnjPosComponent>()->position.y, 50, 50, RED);
            }

            rtype::modules::Textures::drawSpritePlayer(this->_myPlayer, this->_stateMoving, this->frameRec);

        EndMode2D();

        DrawFPS(10, 10);
    EndDrawing();
}

void rtype::Features::update(float deltatime, float getTime)
{
    this->_deltaTime = deltatime;
    this->camera.target.x = this->_myPlayer.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x + 25;
    this->camera.target.y = this->_myPlayer.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y + 25;

    // update moving here
    rtype::modules::Textures::updateTexture(30.0f, deltatime, this->_IsMoving, this->currentFrame, this->framesCounter, this->frameRec, this->frameWidth, this->frameHeight);
    rtype::modules::MovingUpdater::updateMoving(this->_myPlayer, this->_stateMoving, this->_PositionEnd, deltatime, 130.0f, this->_IsMoving);

    // catch input here
    rtype::modules::MovingUpdater::catchInput(this->_myPlayer, this->_stateMoving, this->_PositionStart, this->_PositionEnd, this->_IsMoving, this->_collisions);
}
