/*
** File description:
** Features
*/

#include "Features.hpp"

rtype::Features::~Features()
{
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

void rtype::Features::catchInput()
{
    if (IsKeyDown(KEY_RIGHT) && !this->_IsMoving) {
        this->_IsMoving = true;
        this->_stateMoving = "right";
        this->_PositionStart = this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position;
        this->_PositionEnd = {this->_PositionStart.x + 50, this->_PositionStart.y};
    } else if (IsKeyDown(KEY_LEFT) && !this->_IsMoving) {
        this->_IsMoving = true;
        this->_stateMoving = "left";
        this->_PositionStart = this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position;
        this->_PositionEnd = {this->_PositionStart.x - 50, this->_PositionStart.y};
    } else if (IsKeyDown(KEY_UP) && !this->_IsMoving) {
        this->_IsMoving = true;
        this->_stateMoving = "up";
        this->_PositionStart = this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position;
        this->_PositionEnd = {this->_PositionStart.x, this->_PositionStart.y - 50};
    } else if (IsKeyDown(KEY_DOWN) && !this->_IsMoving) {
        this->_IsMoving = true;
        this->_stateMoving = "down";
        this->_PositionStart = this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position;
        this->_PositionEnd = {this->_PositionStart.x, this->_PositionStart.y + 50};
    }
}

void rtype::Features::draw()
{
    BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode2D(this->camera);

        DrawRectangle(0, 50, 50, 50, RED);

        rlPushMatrix();
            rlTranslatef(0, 25*50, 0);
            rlRotatef(90, 1, 0, 0);
            DrawGrid(100, 50);
        rlPopMatrix();

        // draw trexture 2D here
        
        DrawTexture(this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::Texture2d>()->texture, this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x, this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y, WHITE);

        EndMode2D();

    EndDrawing();
}

void rtype::Features::update(float deltatime, float getTime)
{
    this->camera.target.x = this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x + 25;
    this->camera.target.y = this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y + 25;

    // update moving here
    updateMoving(deltatime);

    // catch input here
    catchInput();
}
