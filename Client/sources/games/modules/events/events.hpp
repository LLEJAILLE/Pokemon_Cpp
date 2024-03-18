/*
** File description:
** Events
*/

#ifndef EVENTS_HPP_
    #define EVENTS_HPP_
    #include "../../../../includes/MainInclusdes.hpp"
    #include "../textures/textures.hpp"
    #include <filesystem>

namespace rtype::modules {
    class Events {
        public:
            Events() = default;
            ~Events() = default;

            void draw(Camera2D &camera, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_map, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_eventsCol, rtype::ECS::Ecs3D::IEntity &_myPlayer, std::string &_stateMoving, Rectangle &frameRec, std::shared_ptr<ECS::Ecs3D::IEntity> &_thisEvent, float deltatime);
            void updateFrameRec(float speed, float deltatime, bool isMoving, int& currentFrame, int& framesCounter, Rectangle& frameRec, float frameWidth, float frameHeight);

            void printEvent(const std::string &action, float deltatime, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_eventCol, std::shared_ptr<ECS::Ecs3D::IEntity> &_thisEvent, Texture2D &dialogBox, rtype::ECS::Ecs3D::IEntity &_myPlayer, Camera2D &camera, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_map, std::string &_stateMoving, Rectangle &frameRec);
            void lookPlayer(const std::string &action, float deltatime, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_eventCol, std::shared_ptr<ECS::Ecs3D::IEntity> &_thisEvent, Texture2D &dialogBox, rtype::ECS::Ecs3D::IEntity &_myPlayer, Camera2D &camera, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_map, std::string &_stateMoving, Rectangle &frameRec);
            void moveUpEvent(const std::string &action, float deltatime, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_eventCol, std::shared_ptr<ECS::Ecs3D::IEntity> &_thisEvent, Texture2D &dialogBox, rtype::ECS::Ecs3D::IEntity &_myPlayer, Camera2D &camera, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_map, std::string &_stateMoving, Rectangle &frameRec);
            void moveDownEvent(const std::string &action, float deltatime, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_eventCol, std::shared_ptr<ECS::Ecs3D::IEntity> &_thisEvent, Texture2D &dialogBox, rtype::ECS::Ecs3D::IEntity &_myPlayer, Camera2D &camera, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_map, std::string &_stateMoving, Rectangle &frameRec);
            void moveLeftEvent(const std::string &action, float deltatime, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_eventCol, std::shared_ptr<ECS::Ecs3D::IEntity> &_thisEvent, Texture2D &dialogBox, rtype::ECS::Ecs3D::IEntity &_myPlayer, Camera2D &camera, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_map, std::string &_stateMoving, Rectangle &frameRec);
            void moveRightEvent(const std::string &action, float deltatime, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_eventCol, std::shared_ptr<ECS::Ecs3D::IEntity> &_thisEvent, Texture2D &dialogBox, rtype::ECS::Ecs3D::IEntity &_myPlayer, Camera2D &camera, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_map, std::string &_stateMoving, Rectangle &frameRec);
            void changeSwitch(const std::string &action, float deltatime, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_eventCol, std::shared_ptr<ECS::Ecs3D::IEntity> &_thisEvent, Texture2D &dialogBox, rtype::ECS::Ecs3D::IEntity &_myPlayer, Camera2D &camera, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_map, std::string &_stateMoving, Rectangle &frameRec);
    
    };
}

#endif /* !EVENTS_HPP_ */
