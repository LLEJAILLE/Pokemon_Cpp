/*
** File description:
** Features
*/

#include "Features.hpp"

Features::~Features()
{
}

void Features::checkEventCol()
{
    if (IsKeyPressed(KEY_SPACE)) {
        for (int i = 0; i < this->_eventsCol.size(); i++) {
            if (this->_myPlayer.getComponent<ECS::PositionComponent2d>()->position.x + 50 >= this->_eventsCol[i]->getComponent<ECS::EventClickComp>()->position.x && this->_myPlayer.getComponent<ECS::PositionComponent2d>()->position.x <= this->_eventsCol[i]->getComponent<ECS::EventClickComp>()->position.x + 50 && this->_myPlayer.getComponent<ECS::PositionComponent2d>()->position.y + 50 >= this->_eventsCol[i]->getComponent<ECS::EventClickComp>()->position.y && this->_myPlayer.getComponent<ECS::PositionComponent2d>()->position.y <= this->_eventsCol[i]->getComponent<ECS::EventClickComp>()->position.y + 50) {                
                for (const auto &event : this->_eventsCol[i]->getComponent<ECS::EventClickComp>()->events) {
                    if (event.first == this->_eventsCol[i]->getComponent<ECS::EventClickComp>()->actualNumberOfCommonSwitch) {
                        for (const auto &action : event.second) {
                            std::string firstWord;
                            std::istringstream iss(action);
                            iss >> firstWord;

                            auto it = this->_mapFunction.find(firstWord);
                            if (it != this->_mapFunction.end()) {
                                (this->eventsInstance.*it->second)(action, this->_deltaTime, this->_eventsCol, this->_eventsCol[i], this->_dialogBox, this->_myPlayer, this->camera, this->_map, this->_stateMoving, this->frameRec);
                                draw();
                            }
                        }

                        std::string lastAction = event.second.back();
                        if (lastAction.find("changeSwitch") != lastAction.npos) {
                            std::string number = lastAction.substr(lastAction.find(" ") + 1);
                            int numberSwitch = std::stoi(number);
                            this->_eventsCol[i]->getComponent<ECS::EventClickComp>()->actualNumberOfCommonSwitch = numberSwitch;
                            break;
                        }
                    }
                }
            }
        }
    }
}

void Features::draw()
{
    BeginDrawing();
        ClearBackground(Color{255, 255, 255, 255});
        DrawFPS(10, 10);
        BeginMode2D(this->camera);

            for (int i = 0; i < this->_map.size(); i++) {
                DrawTexture(this->_map[i]->getComponent<ECS::Texture2d>()->texture, this->_map[i]->getComponent<ECS::PositionComponent2d>()->position.x, this->_map[i]->getComponent<ECS::PositionComponent2d>()->position.y, WHITE);
            }

            // draw pnj
            for (int i = 0; i < this->_eventsCol.size(); i++) {
                DrawTextureRec(this->_eventsCol[i]->getComponent<ECS::EventClickComp>()->actualTexture, {0, 0, 50, 50}, this->_eventsCol[i]->getComponent<ECS::EventClickComp>()->position, WHITE);
            }

            modules::Textures::drawSpritePlayer(this->_myPlayer, this->_stateMoving, this->frameRec);


        EndMode2D();
    EndDrawing();
}

void Features::update(float deltatime, float getTime)
{
    this->_deltaTime = deltatime;
    this->camera.target.x = this->_myPlayer.getComponent<ECS::PositionComponent2d>()->position.x + 25;
    this->camera.target.y = this->_myPlayer.getComponent<ECS::PositionComponent2d>()->position.y + 25;

    // update moving here
    modules::Textures::updateTexture(30.0f, deltatime, this->_IsMoving, this->currentFrame, this->framesCounter, this->frameRec, this->frameWidth, this->frameHeight);
    modules::MovingUpdater::updateMoving(this->_myPlayer, this->_stateMoving, this->_PositionEnd, deltatime, 130.0f, this->_IsMoving);

    // catch input here
    modules::MovingUpdater::catchInput(this->_myPlayer, this->_stateMoving, this->_PositionStart, this->_PositionEnd, this->_IsMoving, this->_collisions, this->_eventsCol);

    checkEventCol();

    modules::Menu::openMenu(this->waitBeforeOpenMenu, this->_IsMoving, this->_menu, this->_cursor, this->_cursorPos);
}
