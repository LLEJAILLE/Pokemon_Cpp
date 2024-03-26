#include "events.hpp"

namespace modules {
    void Events::lookPlayer(const std::string &action, float deltatime, std::map<int, std::shared_ptr<ECS::IEntity>> &_eventCol, std::shared_ptr<ECS::IEntity> &_thisEvent, Texture2D &dialogBox, ECS::IEntity &_myPlayer, Camera2D &camera, std::map<int, std::shared_ptr<ECS::IEntity>> &_map, std::string &_stateMoving, Rectangle &frameRec) {
        if (_myPlayer.getComponent<ECS::PositionComponent2d>()->position.x > _thisEvent->getComponent<ECS::EventClickComp>()->position.x) {
            _thisEvent->getComponent<ECS::EventClickComp>()->actualTexture = _thisEvent->getComponent<ECS::EventClickComp>()->textureRight;
        } else if (_myPlayer.getComponent<ECS::PositionComponent2d>()->position.x < _thisEvent->getComponent<ECS::EventClickComp>()->position.x) {
            _thisEvent->getComponent<ECS::EventClickComp>()->actualTexture = _thisEvent->getComponent<ECS::EventClickComp>()->textureLeft;
        } else if (_myPlayer.getComponent<ECS::PositionComponent2d>()->position.y > _thisEvent->getComponent<ECS::EventClickComp>()->position.y) {
            _thisEvent->getComponent<ECS::EventClickComp>()->actualTexture = _thisEvent->getComponent<ECS::EventClickComp>()->textureDown;
        } else if (_myPlayer.getComponent<ECS::PositionComponent2d>()->position.y < _thisEvent->getComponent<ECS::EventClickComp>()->position.y) {
            _thisEvent->getComponent<ECS::EventClickComp>()->actualTexture = _thisEvent->getComponent<ECS::EventClickComp>()->textureUp;
        }
    }

    void Events::printEvent(const std::string &action, float deltatime, std::map<int, std::shared_ptr<ECS::IEntity>> &_eventCol, std::shared_ptr<ECS::IEntity> &_thisEvent, Texture2D &dialogBox, ECS::IEntity &_myPlayer, Camera2D &camera, std::map<int, std::shared_ptr<ECS::IEntity>> &_map, std::string &_stateMoving, Rectangle &frameRec) {
        int key = 0;
        std::string formatString = action;
        formatString = formatString.substr(formatString.find("\"") + 1, formatString.rfind("\"") - formatString.find("\"") - 1);
        bool writtingFinished = false;
        bool isSecondLine = false;

        std::string firstLine = formatString.substr(0, 105);
        std::string secondLine;


        if (formatString.length() > 105) {
            isSecondLine = true;
            size_t lastSpace = firstLine.find_last_of(' ');
            firstLine = firstLine.substr(0, lastSpace);

            secondLine = formatString.substr(lastSpace + 1);
        }

        while (key != 32) {
            if (!writtingFinished) {
                for (size_t i = 0; i < firstLine.length(); ++i) {                    
                    std::string partialString = firstLine.substr(0, i + 1);

                    BeginDrawing();
                    DrawTextureEx(dialogBox, { 0, static_cast<float>(GetScreenHeight() - 160) }, 0, 1.023, WHITE);
                    DrawText(partialString.c_str(), 50, GetScreenHeight() - 120, 32, BLACK);
                    EndDrawing();

                    std::this_thread::sleep_for(std::chrono::milliseconds(5));
                }

                for (size_t i = 0; i < secondLine.length(); ++i) {
                    std::string partialString = secondLine.substr(0, i + 1);

                    BeginDrawing();
                    DrawTextureEx(dialogBox, { 0, static_cast<float>(GetScreenHeight() - 160) }, 0, 1.023, WHITE);
                    DrawText(firstLine.c_str(), 50, GetScreenHeight() - 120, 32, BLACK);
                    DrawText(partialString.c_str(), 50, GetScreenHeight() - 90, 32, BLACK);
                    EndDrawing();

                    std::this_thread::sleep_for(std::chrono::milliseconds(15));
                }

                writtingFinished = true;
            }

            BeginDrawing();
            DrawTextureEx(dialogBox, { 0, static_cast<float>(GetScreenHeight() - 160) }, 0, 1.023, WHITE);

            DrawText(firstLine.c_str(), 50, GetScreenHeight() - 120, 32, BLACK);

            if (isSecondLine) {
                DrawText(secondLine.c_str(), 50, GetScreenHeight() - 90, 32, BLACK);
            }
           
            EndDrawing();

            key = GetKeyPressed();
        }
    }

    void Events::moveUpEvent(const std::string &action, float deltatime, std::map<int, std::shared_ptr<ECS::IEntity>> &_eventCol, std::shared_ptr<ECS::IEntity> &_thisEvent, Texture2D &dialogBox, ECS::IEntity &_myPlayer, Camera2D &camera, std::map<int, std::shared_ptr<ECS::IEntity>> &_map, std::string &_stateMoving, Rectangle &frameRec) {
        Vector2 newPosition = { _thisEvent->getComponent<ECS::EventClickComp>()->position.x, _thisEvent->getComponent<ECS::EventClickComp>()->position.y - 50 };

        while (_thisEvent->getComponent<ECS::EventClickComp>()->position.y > newPosition.y) {
            _thisEvent->getComponent<ECS::EventClickComp>()->position.y -= 100 * deltatime;
            _thisEvent->getComponent<ECS::EventClickComp>()->actualTexture = _thisEvent->getComponent<ECS::EventClickComp>()->textureUp;
            draw(camera, _map, _eventCol, _myPlayer, _stateMoving, frameRec, _thisEvent, deltatime);
        }
    }

    void Events::moveDownEvent(const std::string &action, float deltatime, std::map<int, std::shared_ptr<ECS::IEntity>> &_eventCol, std::shared_ptr<ECS::IEntity> &_thisEvent, Texture2D &dialogBox, ECS::IEntity &_myPlayer, Camera2D &camera, std::map<int, std::shared_ptr<ECS::IEntity>> &_map, std::string &_stateMoving, Rectangle &frameRec) {
        Vector2 newPosition = { _thisEvent->getComponent<ECS::EventClickComp>()->position.x, _thisEvent->getComponent<ECS::EventClickComp>()->position.y + 50 };

        while (_thisEvent->getComponent<ECS::EventClickComp>()->position.y < newPosition.y) {
            _thisEvent->getComponent<ECS::EventClickComp>()->position.y += 100 * deltatime;
            _thisEvent->getComponent<ECS::EventClickComp>()->actualTexture = _thisEvent->getComponent<ECS::EventClickComp>()->textureDown;
            draw(camera, _map, _eventCol, _myPlayer, _stateMoving, frameRec, _thisEvent, deltatime);
        }
    }

    void Events::moveLeftEvent(const std::string &action, float deltatime, std::map<int, std::shared_ptr<ECS::IEntity>> &_eventCol, std::shared_ptr<ECS::IEntity> &_thisEvent, Texture2D &dialogBox, ECS::IEntity &_myPlayer, Camera2D &camera, std::map<int, std::shared_ptr<ECS::IEntity>> &_map, std::string &_stateMoving, Rectangle &frameRec) {
        Vector2 newPosition = { _thisEvent->getComponent<ECS::EventClickComp>()->position.x - 50, _thisEvent->getComponent<ECS::EventClickComp>()->position.y };

        while (_thisEvent->getComponent<ECS::EventClickComp>()->position.x > newPosition.x) {
            _thisEvent->getComponent<ECS::EventClickComp>()->position.x -= 100 * deltatime;
            _thisEvent->getComponent<ECS::EventClickComp>()->actualTexture = _thisEvent->getComponent<ECS::EventClickComp>()->textureLeft;
            draw(camera, _map, _eventCol, _myPlayer, _stateMoving, frameRec, _thisEvent, deltatime);
        }
    }

    void Events::moveRightEvent(const std::string &action, float deltatime, std::map<int, std::shared_ptr<ECS::IEntity>> &_eventCol, std::shared_ptr<ECS::IEntity> &_thisEvent, Texture2D &dialogBox, ECS::IEntity &_myPlayer, Camera2D &camera, std::map<int, std::shared_ptr<ECS::IEntity>> &_map, std::string &_stateMoving, Rectangle &frameRec) {
        Vector2 newPosition = { _thisEvent->getComponent<ECS::EventClickComp>()->position.x + 50, _thisEvent->getComponent<ECS::EventClickComp>()->position.y };

        while (_thisEvent->getComponent<ECS::EventClickComp>()->position.x < newPosition.x) {
            _thisEvent->getComponent<ECS::EventClickComp>()->position.x += 100 * deltatime;
            _thisEvent->getComponent<ECS::EventClickComp>()->actualTexture = _thisEvent->getComponent<ECS::EventClickComp>()->textureRight;
            draw(camera, _map, _eventCol, _myPlayer, _stateMoving, frameRec, _thisEvent, deltatime);
        }
    }

    void Events::changeSwitch(const std::string &action, float deltatime, std::map<int, std::shared_ptr<ECS::IEntity>> &_eventCol, std::shared_ptr<ECS::IEntity> &_thisEvent, Texture2D &dialogBox, ECS::IEntity &_myPlayer, Camera2D &camera, std::map<int, std::shared_ptr<ECS::IEntity>> &_map, std::string &_stateMoving, Rectangle &frameRec) {
        std::string number = action.substr(action.find(" ") + 1);
        int numberInt = std::stoi(number);

        _thisEvent->getComponent<ECS::EventClickComp>()->actualNumberOfCommonSwitch = numberInt;
    }


    ///-----------------UTILS-----------------///

    void Events::updateFrameRec(float speed, float deltatime, bool isMoving, int& currentFrame, int& framesCounter, Rectangle& frameRec, float frameWidth, float frameHeight) {
        framesCounter += static_cast<int>(speed * deltatime);
        if (framesCounter > 40) {
            currentFrame++;
            frameRec.x = frameWidth * currentFrame;
            if (currentFrame >= 4) {
                currentFrame = 0;
                frameRec.x = frameWidth * currentFrame;
            }
            framesCounter = 0;
        }
    }


    void Events::draw(Camera2D &camera, std::map<int, std::shared_ptr<ECS::IEntity>> &_map, std::map<int, std::shared_ptr<ECS::IEntity>> &_eventsCol, ECS::IEntity &_myPlayer, std::string &_stateMoving, Rectangle &frameRec, std::shared_ptr<ECS::IEntity> &_thisEvent, float deltatime) {
        BeginDrawing();
        ClearBackground(Color{255, 255, 255, 255});

        BeginMode2D(camera);
            for (int i = 0; i < _map.size(); i++) {
                DrawTexture(_map[i]->getComponent<ECS::Texture2d>()->texture, _map[i]->getComponent<ECS::PositionComponent2d>()->position.x, _map[i]->getComponent<ECS::PositionComponent2d>()->position.y, WHITE);
            }

            for (int i = 0; i < _eventsCol.size(); i++) {
                auto eventComp = _eventsCol[i]->getComponent<ECS::EventClickComp>();

                if (_eventsCol[i] == _thisEvent) {
                    updateFrameRec(200, deltatime, eventComp->isMoving, eventComp->currentFrame, eventComp->framesCounter, eventComp->frameRec, eventComp->frameWidth, eventComp->frameHeight);
                    DrawTextureRec(eventComp->actualTexture, eventComp->frameRec, eventComp->position, WHITE);
                } else {
                    DrawTextureRec(eventComp->actualTexture, frameRec, eventComp->position, WHITE);
                }
            }

            modules::Textures::drawSpritePlayer(_myPlayer, _stateMoving, frameRec);
        EndMode2D();

        EndDrawing();
    }
}