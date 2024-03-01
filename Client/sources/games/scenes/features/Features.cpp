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

void rtype::Features::updateMoving(float deltatime)
{
    if (this->_IsMoving) {
        if (this->_stateMoving == "right") {
            this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x += 1 * deltatime * this->speed;
            if (this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x >= this->_PositionEnd.x) {
                this->_IsMoving = false;
                this->_stateMoving = "";
                this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position = this->_PositionEnd;   
            }
        } else if (this->_stateMoving == "left") {
            this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x -= 1 * deltatime * this->speed;
            if (this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x <= this->_PositionEnd.x) {
                this->_IsMoving = false;
                this->_stateMoving = "";
                this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position = this->_PositionEnd;   
            }
        } else if (this->_stateMoving == "up") {
            this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y -= 1 * deltatime * this->speed;
            if (this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y <= this->_PositionEnd.y) {
                this->_IsMoving = false;
                this->_stateMoving = "";
                this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position = this->_PositionEnd;   
            }
        } else if (this->_stateMoving == "down") {
            this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y += 1 * deltatime * this->speed;
            if (this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y >= this->_PositionEnd.y) {
                this->_IsMoving = false;
                this->_stateMoving = "";
                this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position = this->_PositionEnd;   
            }
        }
    }
}

bool rtype::Features::checkCollision()
{
    for (int i = 0; i < this->_collisions.size(); i++) {
        if (this->_stateMoving == "right" && CheckCollisionRecs({this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x + 50, this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y, 50, 50}, {this->_collisions[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x, this->_collisions[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y, 50, 50})) {
            return true;
        } else if (this->_stateMoving == "left" && CheckCollisionRecs({this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x - 50, this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y, 50, 50}, {this->_collisions[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x, this->_collisions[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y, 50, 50})) {
            return true;
        } else if (this->_stateMoving == "up" && CheckCollisionRecs({this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x, this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y - 50, 50, 50}, {this->_collisions[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x, this->_collisions[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y, 50, 50})) {
            return true;
        } else if (this->_stateMoving == "down" && CheckCollisionRecs({this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x, this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y + 50, 50, 50}, {this->_collisions[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x, this->_collisions[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y, 50, 50})) {
            return true;
        }
    }
    return false;
}

void rtype::Features::catchInput()
{
    if (IsKeyDown(KEY_RIGHT) && !this->_IsMoving) {
        this->_IsMoving = true;
        this->_stateMoving = "right";

        if (checkCollision()) {
            this->_IsMoving = false;
            this->_stateMoving = "";
            return;
        }

        this->_PositionStart = this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position;
        this->_PositionEnd = {this->_PositionStart.x + 50, this->_PositionStart.y};
    } else if (IsKeyDown(KEY_LEFT) && !this->_IsMoving) {
        this->_IsMoving = true;
        this->_stateMoving = "left";

        if (checkCollision()) {
            this->_IsMoving = false;
            this->_stateMoving = "";
            return;
        }

        this->_PositionStart = this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position;
        this->_PositionEnd = {this->_PositionStart.x - 50, this->_PositionStart.y};
    } else if (IsKeyDown(KEY_UP) && !this->_IsMoving) {
        this->_IsMoving = true;
        this->_stateMoving = "up";

        if (checkCollision()) {
            this->_IsMoving = false;
            this->_stateMoving = "";
            return;
        }

        this->_PositionStart = this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position;
        this->_PositionEnd = {this->_PositionStart.x, this->_PositionStart.y - 50};
    } else if (IsKeyDown(KEY_DOWN) && !this->_IsMoving) {
        this->_IsMoving = true;
        this->_stateMoving = "down";

        if (checkCollision()) {
            this->_IsMoving = false;
            this->_stateMoving = "";
            return;
        }

        this->_PositionStart = this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position;
        this->_PositionEnd = {this->_PositionStart.x, this->_PositionStart.y + 50};
    }
}

void rtype::Features::updateTexture(float speed, float deltaTime)
{
    if (!this->_IsMoving) {
        this->currentFrame = 0;
        frameRec.x = frameWidth*currentFrame;
        frameRec.y = frameHeight;
        return;
    }

    this->framesCounter++;
    if (this->framesCounter > 20) {
        this->currentFrame++;
        if (this->currentFrame >= 4) {
            this->currentFrame = 0;
        }
        framesCounter = 0;
    }
    frameRec.x = frameWidth*currentFrame;
    frameRec.y = frameHeight;
}



void rtype::Features::draw()
{
    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawFPS(10, 10);
        BeginMode2D(this->camera);

            for (int i = 0; i < this->_map.size(); i++) {
                DrawTexture(this->_map[i]->getComponent<rtype::ECS::Ecs3D::Texture2d>()->texture, this->_map[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x, this->_map[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y, WHITE);
            }
            
            DrawTextureRec(this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::Texture2d>()->texture, frameRec, this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position, WHITE);

        EndMode2D();
    EndDrawing();
}

void rtype::Features::update(float deltatime, float getTime)
{
    this->_deltaTime = deltatime;

    this->camera.target.x = this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x + 25;
    this->camera.target.y = this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y + 25;

    // update moving here
    updateTexture(30.0f, deltatime);
    updateMoving(deltatime);

    // catch input here
    catchInput();
}
