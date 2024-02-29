/*
** File description:
** Features
*/

#include "Features.hpp"

rtype::Features::~Features()
{
}

void rtype::Features::parseMap(std::string path)
{
    std::ifstream file(path);
    std::string line;
    int nbLine = 0;

    while (std::getline(file, line)) {
        nbLine++;
        for (int i = 0; i < line.size(); i++) {
            float x = i * 50;
            float y = nbLine * 50;

            if (line[i] == '*') {                
                rtype::ECS::Ecs3D::IEntity entity("ground" + std::to_string(i) + std::to_string(this->_map.size()));

                entity.addComponent<rtype::ECS::Ecs3D::PositionComponent2d>(Vector2{x, y}, "texturePosition");
                Image img = LoadImage("./Media/maps/ground.png");
                entity.addComponent<rtype::ECS::Ecs3D::Texture2d>(img, "playerTexture");

                this->_map.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_map.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));
            }

            if (line[i] == '+') {
                rtype::ECS::Ecs3D::IEntity entity("herb" + std::to_string(i) + std::to_string(this->_map.size()));

                entity.addComponent<rtype::ECS::Ecs3D::PositionComponent2d>(Vector2{x, y}, "texturePosition");
                Image img = LoadImage("./Media/maps/herb.png");
                entity.addComponent<rtype::ECS::Ecs3D::Texture2d>(img, "playerTexture");

                this->_map.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_map.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));
            }

            if (line[i] == '/') {
                rtype::ECS::Ecs3D::IEntity entity("herb2" + std::to_string(i) + std::to_string(this->_map.size()));

                entity.addComponent<rtype::ECS::Ecs3D::PositionComponent2d>(Vector2{x, y}, "texturePosition");
                Image img = LoadImage("./Media/maps/herb2.png");
                entity.addComponent<rtype::ECS::Ecs3D::Texture2d>(img, "playerTexture");

                this->_map.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_map.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));
            }

        }
    }

    file.close();
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
        DrawFPS(10, 10);

        rlPushMatrix();
            rlTranslatef(0, 25*50, 0);
            rlRotatef(90, 1, 0, 0);
            DrawGrid(100, 50);
        rlPopMatrix();

        // draw map here
        for (int i = 0; i < this->_map.size(); i++) {
            DrawTexture(this->_map[i]->getComponent<rtype::ECS::Ecs3D::Texture2d>()->texture, this->_map[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x, this->_map[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y, WHITE);
        }
        
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
