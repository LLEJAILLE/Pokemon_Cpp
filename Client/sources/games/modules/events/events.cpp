#include "events.hpp"

namespace rtype::modules {
    void Events::lookPlayer(const std::string &action, float deltatime, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_eventCol, std::shared_ptr<ECS::Ecs3D::IEntity> &_thisEvent, Texture2D &dialogBox, rtype::ECS::Ecs3D::IEntity &_myPlayer, Camera2D &camera, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_map, std::string &_stateMoving, Rectangle &frameRec) {
        if (_myPlayer.getComponent<ECS::Ecs3D::PositionComponent2d>()->position.x > _thisEvent->getComponent<ECS::Ecs3D::EventClickComp>()->position.x) {
            _thisEvent->getComponent<ECS::Ecs3D::EventClickComp>()->actualTexture = _thisEvent->getComponent<ECS::Ecs3D::EventClickComp>()->textureRight;
        } else if (_myPlayer.getComponent<ECS::Ecs3D::PositionComponent2d>()->position.x < _thisEvent->getComponent<ECS::Ecs3D::EventClickComp>()->position.x) {
            _thisEvent->getComponent<ECS::Ecs3D::EventClickComp>()->actualTexture = _thisEvent->getComponent<ECS::Ecs3D::EventClickComp>()->textureLeft;
        } else if (_myPlayer.getComponent<ECS::Ecs3D::PositionComponent2d>()->position.y > _thisEvent->getComponent<ECS::Ecs3D::EventClickComp>()->position.y) {
            _thisEvent->getComponent<ECS::Ecs3D::EventClickComp>()->actualTexture = _thisEvent->getComponent<ECS::Ecs3D::EventClickComp>()->textureDown;
        } else if (_myPlayer.getComponent<ECS::Ecs3D::PositionComponent2d>()->position.y < _thisEvent->getComponent<ECS::Ecs3D::EventClickComp>()->position.y) {
            _thisEvent->getComponent<ECS::Ecs3D::EventClickComp>()->actualTexture = _thisEvent->getComponent<ECS::Ecs3D::EventClickComp>()->textureUp;
        }
    }

    void Events::printEvent(const std::string &action, float deltatime, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_eventCol, std::shared_ptr<ECS::Ecs3D::IEntity> &_thisEvent, Texture2D &dialogBox, rtype::ECS::Ecs3D::IEntity &_myPlayer, Camera2D &camera, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_map, std::string &_stateMoving, Rectangle &frameRec) {
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

    void Events::moveUpEvent(const std::string &action, float deltatime, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_eventCol, std::shared_ptr<ECS::Ecs3D::IEntity> &_thisEvent, Texture2D &dialogBox, rtype::ECS::Ecs3D::IEntity &_myPlayer, Camera2D &camera, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_map, std::string &_stateMoving, Rectangle &frameRec) {
        Vector2 newPosition = { _thisEvent->getComponent<rtype::ECS::Ecs3D::EventClickComp>()->position.x, _thisEvent->getComponent<rtype::ECS::Ecs3D::EventClickComp>()->position.y - 50 };

        while (_thisEvent->getComponent<rtype::ECS::Ecs3D::EventClickComp>()->position.y > newPosition.y) {
            _thisEvent->getComponent<rtype::ECS::Ecs3D::EventClickComp>()->position.y -= 130 * deltatime;
            _thisEvent->getComponent<rtype::ECS::Ecs3D::EventClickComp>()->actualTexture = _thisEvent->getComponent<rtype::ECS::Ecs3D::EventClickComp>()->textureUp;
            draw(camera, _map, _eventCol, _myPlayer, _stateMoving, frameRec);
        }

    }

    void Events::draw(Camera2D &camera, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_map, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_eventsCol, rtype::ECS::Ecs3D::IEntity &_myPlayer, std::string &_stateMoving, Rectangle &frameRec) {
        BeginDrawing();
        ClearBackground(Color{255, 255, 255, 255});
        BeginMode2D(camera);
            for (int i = 0; i < _map.size(); i++) {
                DrawTexture(_map[i]->getComponent<ECS::Ecs3D::Texture2d>()->texture, _map[i]->getComponent<ECS::Ecs3D::PositionComponent2d>()->position.x, _map[i]->getComponent<ECS::Ecs3D::PositionComponent2d>()->position.y, WHITE);
            }

            // draw pnj
            for (int i = 0; i < _eventsCol.size(); i++) {
                //draw the rect
                DrawTextureRec(_eventsCol[i]->getComponent<ECS::Ecs3D::EventClickComp>()->actualTexture, {0, 0, 50, 50}, _eventsCol[i]->getComponent<ECS::Ecs3D::EventClickComp>()->position, WHITE);
            }

            rtype::modules::Textures::drawSpritePlayer(_myPlayer, _stateMoving, frameRec);
        EndMode2D();

        EndDrawing();
    }
}