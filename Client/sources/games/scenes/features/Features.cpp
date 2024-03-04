/*
** File description:
** Features
*/

#include "Features.hpp"

rtype::Features::~Features()
{
}

void rtype::Features::parseMap(std::string path, std::string config)
{   
    std::ifstream fileconfg(config);
    std::string lineConf;
    int nbLineConf = 0;

    while (std::getline(fileconfg, lineConf)) {
        nbLineConf++;
        if (lineConf.find("texture:") != std::string::npos) {
            while (std::getline(fileconfg, lineConf) && !lineConf.empty() && lineConf.find("collisions:") == std::string::npos) {
                std::string charac = lineConf.substr(0, lineConf.find(" "));
                std::string path = lineConf.substr(lineConf.find("=") + 2, lineConf.size());

                if (path.find(".png") != std::string::npos) {
                    path = path.substr(0, path.find(".png") + 4);
                }

                if (!charac.empty() || !path.empty() || charac != "" || path != "") {
                    this->_indexFilePathText.insert(std::pair<std::string, std::string>(charac, path));
                }
            }
        }

        if (lineConf.find("collisions:") != std::string::npos) {
            while (std::getline(fileconfg, lineConf)) {
                std::string charac = lineConf.substr(0, lineConf.find(" "));
                std::string path = lineConf.substr(lineConf.find("=") + 2, lineConf.size());

                if (path.find(".png") != std::string::npos) {
                    path = path.substr(0, path.find(".png") + 4);
                }

                if (!charac.empty() || !path.empty() || charac != "" || path != "") {
                    this->_indexFilePathColl.insert(std::pair<std::string, std::string>(charac, path));
                }
            }
        }
    }

    std::ifstream file(path);
    std::string line;
    int nbLine = 0;
    
    while (std::getline(file, line)) {
        nbLine++;
        for (int i = 0; i < line.size(); i++) {
            float x = i * 50;
            float y = nbLine * 50;

            auto it = _indexFilePathText.find(std::string(1, line[i]));
            const char *file = it->second.c_str();

            if (it != _indexFilePathText.end()) {
                rtype::ECS::Ecs3D::IEntity entity("ground" + std::to_string(i) + std::to_string(this->_map.size()));
                entity.addComponent<rtype::ECS::Ecs3D::PositionComponent2d>(Vector2{x, y}, "texturePosition");
                Image img = LoadImage(file);
                entity.addComponent<rtype::ECS::Ecs3D::Texture2d>(img, "Texture");
                this->_map.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_map.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));
            }

            auto itColl = _indexFilePathColl.find(std::string(1, line[i]));
            const char *fileColl = itColl->second.c_str();

            if (itColl != _indexFilePathColl.end()) {
                rtype::ECS::Ecs3D::IEntity entity("coll" + std::to_string(i) + std::to_string(this->_collisions.size()));
                entity.addComponent<rtype::ECS::Ecs3D::PositionComponent2d>(Vector2{x, y}, "texturePosition");
                Image img = LoadImage(fileColl);
                entity.addComponent<rtype::ECS::Ecs3D::Texture2d>(img, "Texture");
                
                this->_map.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_map.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));
                this->_collisions.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_collisions.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));
            }
        }
    }

    file.close();
    fileconfg.close();
}

void rtype::Features::drawSpritePlayer()
{
    if (this->_stateMoving == "right") {
        DrawTextureRec(this->_myPlayer.getComponent<rtype::ECS::Ecs3D::TextureRight>()->texture, frameRec, this->_myPlayer.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position, WHITE);
    } else if (this->_stateMoving == "left") {
        DrawTextureRec(this->_myPlayer.getComponent<rtype::ECS::Ecs3D::TextureLeft>()->texture, frameRec, this->_myPlayer.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position, WHITE);
    } else if (this->_stateMoving == "up") {
        DrawTextureRec(this->_myPlayer.getComponent<rtype::ECS::Ecs3D::TextureUp>()->texture, frameRec, this->_myPlayer.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position, WHITE);
    } else if (this->_stateMoving == "down") {
        DrawTextureRec(this->_myPlayer.getComponent<rtype::ECS::Ecs3D::TextureDown>()->texture, frameRec, this->_myPlayer.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position, WHITE);
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
            
            drawSpritePlayer();

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
