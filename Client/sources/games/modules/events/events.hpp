/*
** File description:
** Events
*/

#ifndef EVENTS_HPP_
    #define EVENTS_HPP_
    #include "../../../../includes/MainInclusdes.hpp"
    #include <filesystem>

namespace rtype::modules {
    class Events {
        public:
            Events() = default;
            ~Events() = default;
            void printEvent(const std::string &action, float deltatime, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_eventCol, std::shared_ptr<ECS::Ecs3D::IEntity> &_thisEvent, Texture2D &dialogBox, rtype::ECS::Ecs3D::IEntity &_myPlayer);
            void moveEvent(const std::string &action, float deltatime, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_eventCol, std::shared_ptr<ECS::Ecs3D::IEntity> &_thisEvent, Texture2D &dialogBox, rtype::ECS::Ecs3D::IEntity &_myPlayer);
            void lookPlayer(const std::string &action, float deltatime, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_eventCol, std::shared_ptr<ECS::Ecs3D::IEntity> &_thisEvent, Texture2D &dialogBox, rtype::ECS::Ecs3D::IEntity &_myPlayer);
            
    };
}

#endif /* !EVENTS_HPP_ */
