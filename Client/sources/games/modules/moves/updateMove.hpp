/*
** File description:
** UPDATEMOVE
*/

#ifndef UPDATEMOVE_HPP_
    #define UPDATEMOVE_HPP_
    #include "../../../../includes/MainInclusdes.hpp"
    #include <filesystem>

namespace modules {
    class MovingUpdater {
        MovingUpdater() = default;
        ~MovingUpdater() = default;

        public:
            static bool checkCollision(std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &collisions, ECS::Ecs3D::IEntity& player, std::string& stateMoving, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &pnj);
            static void catchInput(ECS::Ecs3D::IEntity& player, std::string& stateMoving, Vector2& positionStart, Vector2& positionEnd, bool& isMoving, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &collisions, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &pnj);
            static void updateMoving(ECS::Ecs3D::IEntity& player, std::string& stateMoving, Vector2& positionEnd, float deltaTime, float speed, bool& isMoving);
    };
}

#endif /* !UPDATEMOVE_HPP_ */
