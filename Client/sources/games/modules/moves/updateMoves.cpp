#include "updateMove.hpp"

void modules::MovingUpdater::updateMoving(ECS::IEntity& player, std::string& stateMoving, Vector2& positionEnd, float deltaTime, float speed, bool& isMoving)
{
    if (isMoving) {
        if (stateMoving == "right") {
            player.getComponent<ECS::PositionComponent2d>()->position.x += speed * deltaTime;
            if (player.getComponent<ECS::PositionComponent2d>()->position.x >= positionEnd.x) {
                isMoving = false;
                stateMoving = "right";
                player.getComponent<ECS::PositionComponent2d>()->position = positionEnd;
            }
        } else if (stateMoving == "left") {
            player.getComponent<ECS::PositionComponent2d>()->position.x -= speed * deltaTime;
            if (player.getComponent<ECS::PositionComponent2d>()->position.x <= positionEnd.x) {
                isMoving = false;
                stateMoving = "left";
                player.getComponent<ECS::PositionComponent2d>()->position = positionEnd;
            }
        } else if (stateMoving == "up") {
            player.getComponent<ECS::PositionComponent2d>()->position.y -= speed * deltaTime;
            if (player.getComponent<ECS::PositionComponent2d>()->position.y <= positionEnd.y) {
                isMoving = false;
                stateMoving = "up";
                player.getComponent<ECS::PositionComponent2d>()->position = positionEnd;
            }
        } else if (stateMoving == "down") {
            player.getComponent<ECS::PositionComponent2d>()->position.y += speed * deltaTime;
            if (player.getComponent<ECS::PositionComponent2d>()->position.y >= positionEnd.y) {
                isMoving = false;
                stateMoving = "down";
                player.getComponent<ECS::PositionComponent2d>()->position = positionEnd;
            }
        }
    }
}

bool modules::MovingUpdater::checkCollision(std::map<int, std::shared_ptr<ECS::IEntity>> &collisions, ECS::IEntity& player, std::string& stateMoving, std::map<int, std::shared_ptr<ECS::IEntity>> &pnj)
{
    for (int i = 0; i < collisions.size(); i++) {
        if (stateMoving == "right" && CheckCollisionRecs({player.getComponent<ECS::PositionComponent2d>()->position.x + 50, player.getComponent<ECS::PositionComponent2d>()->position.y, 50, 50}, {collisions[i]->getComponent<ECS::PositionComponent2d>()->position.x, collisions[i]->getComponent<ECS::PositionComponent2d>()->position.y, 50, 50})) {
            return true;
        } else if (stateMoving == "left" && CheckCollisionRecs({player.getComponent<ECS::PositionComponent2d>()->position.x - 50, player.getComponent<ECS::PositionComponent2d>()->position.y, 50, 50}, {collisions[i]->getComponent<ECS::PositionComponent2d>()->position.x, collisions[i]->getComponent<ECS::PositionComponent2d>()->position.y, 50, 50})) {
            return true;
        } else if (stateMoving == "up" && CheckCollisionRecs({player.getComponent<ECS::PositionComponent2d>()->position.x, player.getComponent<ECS::PositionComponent2d>()->position.y - 50, 50, 50}, {collisions[i]->getComponent<ECS::PositionComponent2d>()->position.x, collisions[i]->getComponent<ECS::PositionComponent2d>()->position.y, 50, 50})) {
            return true;
        } else if (stateMoving == "down" && CheckCollisionRecs({player.getComponent<ECS::PositionComponent2d>()->position.x, player.getComponent<ECS::PositionComponent2d>()->position.y + 50, 50, 50}, {collisions[i]->getComponent<ECS::PositionComponent2d>()->position.x, collisions[i]->getComponent<ECS::PositionComponent2d>()->position.y, 50, 50})) {
            return true;
        }
    }

    for (int j = 0; j < pnj.size(); j++) {
        if (stateMoving == "right" && CheckCollisionRecs({player.getComponent<ECS::PositionComponent2d>()->position.x + 50, player.getComponent<ECS::PositionComponent2d>()->position.y, 50, 50}, {pnj[j]->getComponent<ECS::EventClickComp>()->position.x, pnj[j]->getComponent<ECS::EventClickComp>()->position.y, 50, 50})) {
            return true;
        } else if (stateMoving == "left" && CheckCollisionRecs({player.getComponent<ECS::PositionComponent2d>()->position.x - 50, player.getComponent<ECS::PositionComponent2d>()->position.y, 50, 50}, {pnj[j]->getComponent<ECS::EventClickComp>()->position.x, pnj[j]->getComponent<ECS::EventClickComp>()->position.y, 50, 50})) {
            return true;
        } else if (stateMoving == "up" && CheckCollisionRecs({player.getComponent<ECS::PositionComponent2d>()->position.x, player.getComponent<ECS::PositionComponent2d>()->position.y - 50, 50, 50}, {pnj[j]->getComponent<ECS::EventClickComp>()->position.x, pnj[j]->getComponent<ECS::EventClickComp>()->position.y, 50, 50})) {
            return true;
        } else if (stateMoving == "down" && CheckCollisionRecs({player.getComponent<ECS::PositionComponent2d>()->position.x, player.getComponent<ECS::PositionComponent2d>()->position.y + 50, 50, 50}, {pnj[j]->getComponent<ECS::EventClickComp>()->position.x, pnj[j]->getComponent<ECS::EventClickComp>()->position.y, 50, 50})) {
            return true;
        }
    }

    return false;           
}

void modules::MovingUpdater::catchInput(ECS::IEntity& player, std::string& stateMoving, Vector2& positionStart, Vector2& positionEnd, bool& isMoving, std::map<int, std::shared_ptr<ECS::IEntity>> &collisions, std::map<int, std::shared_ptr<ECS::IEntity>> &pnj)
{
    if (IsKeyDown(KEY_RIGHT) && !isMoving) {
        isMoving = true;
        stateMoving = "right";

        if (checkCollision(collisions, player, stateMoving, pnj)) {
            isMoving = false;
            stateMoving = "right";
            return;
        }

        positionStart = player.getComponent<ECS::PositionComponent2d>()->position;
        positionEnd = {positionStart.x + 50, positionStart.y};
    } else if (IsKeyDown(KEY_LEFT) && !isMoving) {
        isMoving = true;
        stateMoving = "left";

        if (checkCollision(collisions, player, stateMoving, pnj)) {
            isMoving = false;
            stateMoving = "left";
            return;
        }

        positionStart = player.getComponent<ECS::PositionComponent2d>()->position;
        positionEnd = {positionStart.x - 50, positionStart.y};
    } else if (IsKeyDown(KEY_UP) && !isMoving) {
        isMoving = true;
        stateMoving = "up";

        if (checkCollision(collisions, player, stateMoving, pnj)) {
            isMoving = false;
            stateMoving = "up";
            return;
        }

        positionStart = player.getComponent<ECS::PositionComponent2d>()->position;
        positionEnd = {positionStart.x, positionStart.y - 50};
    } else if (IsKeyDown(KEY_DOWN) && !isMoving) {
        isMoving = true;
        stateMoving = "down";

        if (checkCollision(collisions, player, stateMoving, pnj)) {
            isMoving = false;
            stateMoving = "down";
            return;
        }

        positionStart = player.getComponent<ECS::PositionComponent2d>()->position;
        positionEnd = {positionStart.x, positionStart.y + 50};
    }
}