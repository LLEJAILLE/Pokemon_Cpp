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
    std::ifstream file("./maps/featuresMap/featuresEvents.txt");
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            if (line.empty()) {
                continue;
            }

            if (line == "OnClick") {
                std::string type;
                int numberEvent;
                std::string nameEvent;
                float x, y;
                std::string pathTextUp;
                std::string pathTextDown;
                std::string pathTextLeft;
                std::string pathTextRight;
                int numberOfCommonSwitch;

                type = line;
                std::getline(file, line);
                numberEvent = std::stoi(line);
                std::getline(file, line);
                nameEvent = line;
                std::getline(file, line);
                std::istringstream iss(line);
                iss >> x >> y;
                x *= 50;
                y *= 50;
                std::getline(file, line);
                pathTextUp = line.substr(line.find("\"") + 1, line.rfind("\"") - line.find("\"") - 1);
                std::getline(file, line);
                pathTextDown = line.substr(line.find("\"") + 1, line.rfind("\"") - line.find("\"") - 1);
                std::getline(file, line);
                pathTextLeft = line.substr(line.find("\"") + 1, line.rfind("\"") - line.find("\"") - 1);
                std::getline(file, line);
                pathTextRight = line.substr(line.find("\"") + 1, line.rfind("\"") - line.find("\"") - 1);
                std::getline(file, line);
                numberOfCommonSwitch = std::stoi(line);
                
                int eventTmp = 0;
                std::map<int, std::vector<std::string>> events;
                while (std::getline(file, line) && !line.empty()) {
                    std::string tmp = "--" + std::to_string(eventTmp);

                    if (line.find(tmp) == 0) {
                        std::getline(file, line);
                        while (line.find(tmp) != 0) {
                            events[eventTmp].push_back(line);
                            std::getline(file, line);
                        }

                        eventTmp++;
                    }
                }

                rtype::ECS::Ecs3D::IEntity event("event " + std::to_string(numberEvent));
                Texture2D textureUp = LoadTexture(pathTextUp.c_str());
                Texture2D textureDown = LoadTexture(pathTextDown.c_str());
                Texture2D textureLeft = LoadTexture(pathTextLeft.c_str());
                Texture2D textureRight = LoadTexture(pathTextRight.c_str());

                event.addComponent<rtype::ECS::Ecs3D::EventClickComp>("event " + std::to_string(numberEvent), type, numberEvent, nameEvent, Vector2{x, y}, textureUp, textureDown, textureLeft, textureRight, numberOfCommonSwitch, events);

                this->_eventsCol.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_eventsCol.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(event)));
            }
        }
    }

    file.close();
}

void rtype::Features::checkEventCol()
{
    auto eventsInstance = rtype::modules::Events();
    if (IsKeyPressed(KEY_SPACE)) {
        for (int i = 0; i < this->_eventsCol.size(); i++) {
            if (this->_myPlayer.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x + 50 >= this->_eventsCol[i]->getComponent<rtype::ECS::Ecs3D::EventClickComp>()->position.x && this->_myPlayer.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x <= this->_eventsCol[i]->getComponent<rtype::ECS::Ecs3D::EventClickComp>()->position.x + 50 && this->_myPlayer.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y + 50 >= this->_eventsCol[i]->getComponent<rtype::ECS::Ecs3D::EventClickComp>()->position.y && this->_myPlayer.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y <= this->_eventsCol[i]->getComponent<rtype::ECS::Ecs3D::EventClickComp>()->position.y + 50) {                
                for (const auto &event : this->_eventsCol[i]->getComponent<rtype::ECS::Ecs3D::EventClickComp>()->events) {
                    if (event.first == this->_eventsCol[i]->getComponent<rtype::ECS::Ecs3D::EventClickComp>()->actualNumberOfCommonSwitch) {
                        for (const auto &action : event.second) {
                            std::string firstWord;
                            std::istringstream iss(action);
                            iss >> firstWord;

                            auto it = this->_mapFunction.find(firstWord);
                            if (it != this->_mapFunction.end()) {
                                (eventsInstance.*it->second)(action, this->_deltaTime, this->_eventsCol, this->_eventsCol[i], this->_dialogBox, this->_myPlayer, this->camera, this->_map, this->_stateMoving, this->frameRec);

                                draw();
                            } else {
                                std::cout << "Function not found" << std::endl;
                            }
                        }
                    }
                }
            }
        }
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
            for (int i = 0; i < this->_eventsCol.size(); i++) {
                //draw the rect
                DrawTextureRec(this->_eventsCol[i]->getComponent<rtype::ECS::Ecs3D::EventClickComp>()->actualTexture, {0, 0, 50, 50}, this->_eventsCol[i]->getComponent<rtype::ECS::Ecs3D::EventClickComp>()->position, WHITE);
            }

            rtype::modules::Textures::drawSpritePlayer(this->_myPlayer, this->_stateMoving, this->frameRec);
        EndMode2D();
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
    rtype::modules::MovingUpdater::catchInput(this->_myPlayer, this->_stateMoving, this->_PositionStart, this->_PositionEnd, this->_IsMoving, this->_collisions, this->_eventsCol);

    checkEventCol();
}
