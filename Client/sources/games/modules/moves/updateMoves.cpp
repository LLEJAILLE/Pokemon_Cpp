#include "updateMove.hpp"

void rtype::modules::MovingUpdater::updateMoving(ECS::Ecs3D::IEntity& player, std::string& stateMoving, Vector2& positionEnd, float deltaTime, float speed, bool& isMoving)
{
    if (isMoving) {
        if (stateMoving == "right") {
            player.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x += speed * deltaTime;
            if (player.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x >= positionEnd.x) {
                isMoving = false;
                stateMoving = "right";
                player.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position = positionEnd;
            }
        } else if (stateMoving == "left") {
            player.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x -= speed * deltaTime;
            if (player.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x <= positionEnd.x) {
                isMoving = false;
                stateMoving = "left";
                player.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position = positionEnd;
            }
        } else if (stateMoving == "up") {
            player.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y -= speed * deltaTime;
            if (player.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y <= positionEnd.y) {
                isMoving = false;
                stateMoving = "up";
                player.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position = positionEnd;
            }
        } else if (stateMoving == "down") {
            player.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y += speed * deltaTime;
            if (player.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y >= positionEnd.y) {
                isMoving = false;
                stateMoving = "down";
                player.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position = positionEnd;
            }
        }
    }
}

bool rtype::modules::MovingUpdater::checkCollision(std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &collisions, ECS::Ecs3D::IEntity& player, std::string& stateMoving)
{
    for (int i = 0; i < collisions.size(); i++) {
        if (stateMoving == "right" && CheckCollisionRecs({player.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x + 50, player.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y, 50, 50}, {collisions[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x, collisions[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y, 50, 50})) {
            return true;
        } else if (stateMoving == "left" && CheckCollisionRecs({player.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x - 50, player.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y, 50, 50}, {collisions[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x, collisions[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y, 50, 50})) {
            return true;
        } else if (stateMoving == "up" && CheckCollisionRecs({player.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x, player.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y - 50, 50, 50}, {collisions[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x, collisions[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y, 50, 50})) {
            return true;
        } else if (stateMoving == "down" && CheckCollisionRecs({player.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x, player.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y + 50, 50, 50}, {collisions[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x, collisions[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y, 50, 50})) {
            return true;
        }
    }
    return false;
}

void rtype::modules::MovingUpdater::catchInput(ECS::Ecs3D::IEntity& player, std::string& stateMoving, Vector2& positionStart, Vector2& positionEnd, bool& isMoving, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &collisions)
{
    if (IsKeyDown(KEY_RIGHT) && !isMoving) {
        isMoving = true;
        stateMoving = "right";

        if (checkCollision(collisions, player, stateMoving)) {
            isMoving = false;
            stateMoving = "right";
            return;
        }

        positionStart = player.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position;
        positionEnd = {positionStart.x + 50, positionStart.y};
    } else if (IsKeyDown(KEY_LEFT) && !isMoving) {
        isMoving = true;
        stateMoving = "left";

        if (checkCollision(collisions, player, stateMoving)) {
            isMoving = false;
            stateMoving = "left";
            return;
        }

        positionStart = player.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position;
        positionEnd = {positionStart.x - 50, positionStart.y};
    } else if (IsKeyDown(KEY_UP) && !isMoving) {
        isMoving = true;
        stateMoving = "up";

        if (checkCollision(collisions, player, stateMoving)) {
            isMoving = false;
            stateMoving = "up";
            return;
        }

        positionStart = player.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position;
        positionEnd = {positionStart.x, positionStart.y - 50};
    } else if (IsKeyDown(KEY_DOWN) && !isMoving) {
        isMoving = true;
        stateMoving = "down";

        if (checkCollision(collisions, player, stateMoving)) {
            isMoving = false;
            stateMoving = "down";
            return;
        }

        positionStart = player.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position;
        positionEnd = {positionStart.x, positionStart.y + 50};
    }
}