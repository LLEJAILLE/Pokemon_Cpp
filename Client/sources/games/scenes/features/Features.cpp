/*
** File description:
** Features
*/

#include "Features.hpp"

rtype::Features::~Features()
{
}

void rtype::Features::parseMap(std::string path, std::string config)
{   
    std::ifstream fileconfg(config);
    std::string lineConf;
    int nbLineConf = 0;

    while (std::getline(fileconfg, lineConf)) {
        nbLineConf++;
        if (lineConf.find("texture:") != std::string::npos) {
            while (std::getline(fileconfg, lineConf) && !lineConf.empty() && lineConf.find("collisions:") == std::string::npos) {
                std::getline(fileconfg, lineConf);
                std::string charac = lineConf.substr(0, lineConf.find(" "));
                std::string path = lineConf.substr(lineConf.find("=") + 2, lineConf.size());

                if (!charac.empty() || !path.empty() || charac != "" || path != "") {
                    this->_indexFilePathText.insert(std::pair<std::string, std::string>(charac, path));
                }
            }
        }


        if (lineConf.find("collisions:") != std::string::npos) {
            while (std::getline(fileconfg, lineConf)) {
                std::string charac = lineConf.substr(0, lineConf.find(" "));
                std::string path = lineConf.substr(lineConf.find("=") + 2, lineConf.size());

                if (!charac.empty() || !path.empty() || charac != "" || path != "") {
                    this->_indexFilePathText.insert(std::pair<std::string, std::string>(charac, path));
                }
            }
        }
    }

    for (auto it = this->_indexFilePathText.begin(); it != this->_indexFilePathText.end(); it++) {
        if (it->first.size() < 1 || it->second.size() < 1) {
            this->_indexFilePathText.erase(it);
        }
    }

    for (auto it = this->_indexFilePathText.begin(); it != this->_indexFilePathText.end(); it++) {
        std::cout << "charac:" << it->first << " path:" << it->second << std::endl;
    }
    

    std::ifstream file(path);
    std::string line;
    int nbLine = 0;
    
    while (std::getline(file, line)) {
        nbLine++;
        for (int i = 0; i < line.size(); i++) {
            float x = i * 50;
            float y = nbLine * 50;

            auto it = _indexFilePathText.find(std::string(1, line[i]));
            const char *file = it->second.c_str();

            if (it != _indexFilePathText.end()) {

                std::cout << "file path:" << file << std::endl;
                // Création de l'entité avec le chemin de fichier associé
                rtype::ECS::Ecs3D::IEntity entity("ground" + std::to_string(i) + std::to_string(this->_map.size()));

                entity.addComponent<rtype::ECS::Ecs3D::PositionComponent2d>(Vector2{x, y}, "texturePosition");
                std::cout << "on va load:" << file << std::endl;
                Image img = LoadImage(file);
                std::cout << "on a load:" << file << std::endl;

                // entity.addComponent<rtype::ECS::Ecs3D::Texture2d>(img, "Texture");

                this->_map.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_map.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));
            }
    

            // if (line[i] == '*') {                
            //     rtype::ECS::Ecs3D::IEntity entity("ground" + std::to_string(i) + std::to_string(this->_map.size()));

            //     entity.addComponent<rtype::ECS::Ecs3D::PositionComponent2d>(Vector2{x, y}, "texturePosition");
            //     Image img = LoadImage("./Media/maps/grounds.png");
            //     entity.addComponent<rtype::ECS::Ecs3D::Texture2d>(img, "Texture");

            //     this->_map.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_map.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));
            // }

            // if (line[i] == '+') {
            //     rtype::ECS::Ecs3D::IEntity entity("herb" + std::to_string(i) + std::to_string(this->_map.size()));

            //     entity.addComponent<rtype::ECS::Ecs3D::PositionComponent2d>(Vector2{x, y}, "texturePosition");
            //     Image img = LoadImage("./Media/maps/herb.png");
            //     entity.addComponent<rtype::ECS::Ecs3D::Texture2d>(img, "Texture");

            //     this->_map.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_map.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));
            // }

            // if (line[i] == '/') {
            //     rtype::ECS::Ecs3D::IEntity entity("herb2" + std::to_string(i) + std::to_string(this->_map.size()));

            //     entity.addComponent<rtype::ECS::Ecs3D::PositionComponent2d>(Vector2{x, y}, "texturePosition");
            //     Image img = LoadImage("./Media/maps/herb2.png");
            //     entity.addComponent<rtype::ECS::Ecs3D::Texture2d>(img, "Texture");

            //     this->_map.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_map.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));
            // }

            // if (line[i] == '1') {
            //     rtype::ECS::Ecs3D::IEntity entity("home1" + std::to_string(i) + std::to_string(this->_map.size()));

            //     entity.addComponent<rtype::ECS::Ecs3D::PositionComponent2d>(Vector2{x, y}, "texturePosition");
            //     Image img = LoadImage("./Media/maps/home1.png");
            //     entity.addComponent<rtype::ECS::Ecs3D::Texture2d>(img, "Texture");

            //     this->_map.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_map.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));

            //     this->_collisions.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_collisions.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));
            // }

            // if (line[i] == '2') {
            //     rtype::ECS::Ecs3D::IEntity entity("home2" + std::to_string(i) + std::to_string(this->_map.size()));

            //     entity.addComponent<rtype::ECS::Ecs3D::PositionComponent2d>(Vector2{x, y}, "texturePosition");
            //     Image img = LoadImage("./Media/maps/home2.png");
            //     entity.addComponent<rtype::ECS::Ecs3D::Texture2d>(img, "Texture");

            //     this->_map.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_map.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));

            //     this->_collisions.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_collisions.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));
            // }

            // if (line[i] == '3') {
            //     rtype::ECS::Ecs3D::IEntity entity("home3" + std::to_string(i) + std::to_string(this->_map.size()));

            //     entity.addComponent<rtype::ECS::Ecs3D::PositionComponent2d>(Vector2{x, y}, "texturePosition");
            //     Image img = LoadImage("./Media/maps/home3.png");
            //     entity.addComponent<rtype::ECS::Ecs3D::Texture2d>(img, "Texture");

            //     this->_map.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_map.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));

            //     this->_collisions.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_collisions.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));
            // }

            // if (line[i] == '4') {
            //     rtype::ECS::Ecs3D::IEntity entity("home4" + std::to_string(i) + std::to_string(this->_map.size()));

            //     entity.addComponent<rtype::ECS::Ecs3D::PositionComponent2d>(Vector2{x, y}, "texturePosition");
            //     Image img = LoadImage("./Media/maps/home4.png");
            //     entity.addComponent<rtype::ECS::Ecs3D::Texture2d>(img, "Texture");

            //     this->_map.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_map.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));

            //     this->_collisions.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_collisions.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));
            // }

            // if (line[i] == '5') {
            //     rtype::ECS::Ecs3D::IEntity entity("home5" + std::to_string(i) + std::to_string(this->_map.size()));

            //     entity.addComponent<rtype::ECS::Ecs3D::PositionComponent2d>(Vector2{x, y}, "texturePosition");
            //     Image img = LoadImage("./Media/maps/home5.png");
            //     entity.addComponent<rtype::ECS::Ecs3D::Texture2d>(img, "Texture");

            //     this->_map.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_map.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));

            //     this->_collisions.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_collisions.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));
            // }

            // if (line[i] == '6') {
            //     rtype::ECS::Ecs3D::IEntity entity("home6" + std::to_string(i) + std::to_string(this->_map.size()));

            //     entity.addComponent<rtype::ECS::Ecs3D::PositionComponent2d>(Vector2{x, y}, "texturePosition");
            //     Image img = LoadImage("./Media/maps/home6.png");
            //     entity.addComponent<rtype::ECS::Ecs3D::Texture2d>(img, "Texture");

            //     this->_map.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_map.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));

            //     this->_collisions.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_collisions.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));
            // }

            // if (line[i] == '7') {
            //     rtype::ECS::Ecs3D::IEntity entity("home7" + std::to_string(i) + std::to_string(this->_map.size()));

            //     entity.addComponent<rtype::ECS::Ecs3D::PositionComponent2d>(Vector2{x, y}, "texturePosition");
            //     Image img = LoadImage("./Media/maps/home7.png");
            //     entity.addComponent<rtype::ECS::Ecs3D::Texture2d>(img, "Texture");

            //     this->_map.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_map.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));

            //     this->_collisions.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_collisions.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));
            // }

            // if (line[i] == '8') {
            //     rtype::ECS::Ecs3D::IEntity entity("home8" + std::to_string(i) + std::to_string(this->_map.size()));

            //     entity.addComponent<rtype::ECS::Ecs3D::PositionComponent2d>(Vector2{x, y}, "texturePosition");
            //     Image img = LoadImage("./Media/maps/home8.png");
            //     entity.addComponent<rtype::ECS::Ecs3D::Texture2d>(img, "Texture");

            //     this->_map.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_map.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));

            //     this->_collisions.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_collisions.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));
            // }

            // if (line[i] == '9') {
            //     rtype::ECS::Ecs3D::IEntity entity("home9" + std::to_string(i) + std::to_string(this->_map.size()));

            //     entity.addComponent<rtype::ECS::Ecs3D::PositionComponent2d>(Vector2{x, y}, "texturePosition");
            //     Image img = LoadImage("./Media/maps/home9.png");
            //     entity.addComponent<rtype::ECS::Ecs3D::Texture2d>(img, "Texture");

            //     this->_map.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_map.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));

            //     this->_collisions.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_collisions.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));
            // }

            // if (line[i] == '.') {
            //     rtype::ECS::Ecs3D::IEntity entity("home10" + std::to_string(i) + std::to_string(this->_map.size()));

            //     entity.addComponent<rtype::ECS::Ecs3D::PositionComponent2d>(Vector2{x, y}, "texturePosition");
            //     Image img = LoadImage("./Media/maps/home10.png");
            //     entity.addComponent<rtype::ECS::Ecs3D::Texture2d>(img, "Texture");

            //     this->_map.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_map.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));

            //     this->_collisions.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_collisions.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));
            // }

            // if (line[i] == '&') {
            //     rtype::ECS::Ecs3D::IEntity entity("home11" + std::to_string(i) + std::to_string(this->_map.size()));

            //     entity.addComponent<rtype::ECS::Ecs3D::PositionComponent2d>(Vector2{x, y}, "texturePosition");
            //     Image img = LoadImage("./Media/maps/home11.png");
            //     entity.addComponent<rtype::ECS::Ecs3D::Texture2d>(img, "Texture");

            //     this->_map.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_map.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));

            //     this->_collisions.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_collisions.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));
            // }

            // if (line[i] == ')') {
            //     rtype::ECS::Ecs3D::IEntity entity("home12" + std::to_string(i) + std::to_string(this->_map.size()));

            //     entity.addComponent<rtype::ECS::Ecs3D::PositionComponent2d>(Vector2{x, y}, "texturePosition");
            //     Image img = LoadImage("./Media/maps/home12.png");
            //     entity.addComponent<rtype::ECS::Ecs3D::Texture2d>(img, "Texture");

            //     this->_map.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_map.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));

            //     this->_collisions.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_collisions.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));
            // }

            // if (line[i] == '"') {
            //     rtype::ECS::Ecs3D::IEntity entity("home13" + std::to_string(i) + std::to_string(this->_map.size()));

            //     entity.addComponent<rtype::ECS::Ecs3D::PositionComponent2d>(Vector2{x, y}, "texturePosition");
            //     Image img = LoadImage("./Media/maps/home13.png");
            //     entity.addComponent<rtype::ECS::Ecs3D::Texture2d>(img, "Texture");

            //     this->_map.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_map.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));

            //     this->_collisions.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_collisions.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));
            // }

            // if (line[i] == '0') {
            //     rtype::ECS::Ecs3D::IEntity entity("home14" + std::to_string(i) + std::to_string(this->_map.size()));

            //     entity.addComponent<rtype::ECS::Ecs3D::PositionComponent2d>(Vector2{x, y}, "texturePosition");
            //     Image img = LoadImage("./Media/maps/home14.png");
            //     entity.addComponent<rtype::ECS::Ecs3D::Texture2d>(img, "Texture");

            //     this->_map.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_map.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));

            //     this->_collisions.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_collisions.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));
            // }

            // if (line[i] == '(') {
            //     rtype::ECS::Ecs3D::IEntity entity("home15" + std::to_string(i) + std::to_string(this->_map.size()));

            //     entity.addComponent<rtype::ECS::Ecs3D::PositionComponent2d>(Vector2{x, y}, "texturePosition");
            //     Image img = LoadImage("./Media/maps/home15.png");
            //     entity.addComponent<rtype::ECS::Ecs3D::Texture2d>(img, "Texture");

            //     this->_map.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_map.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));

            //     this->_collisions.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_collisions.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));
            // }

            // if (line[i] == '-') {
            //     rtype::ECS::Ecs3D::IEntity entity("home16" + std::to_string(i) + std::to_string(this->_map.size()));

            //     entity.addComponent<rtype::ECS::Ecs3D::PositionComponent2d>(Vector2{x, y}, "texturePosition");
            //     Image img = LoadImage("Media/maps/home16.png");
            //     entity.addComponent<rtype::ECS::Ecs3D::Texture2d>(img, "Texture");

            //     this->_map.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_map.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));

            //     this->_collisions.insert(std::pair<int, std::shared_ptr<rtype::ECS::Ecs3D::IEntity>>(this->_collisions.size(), std::make_shared<rtype::ECS::Ecs3D::IEntity>(entity)));

            // }

        }
    }


    file.close();
    fileconfg.close();
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

bool rtype::Features::checkCollision()
{
    for (int i = 0; i < this->_collisions.size(); i++) {
        if (this->_stateMoving == "right" && CheckCollisionRecs({this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x + 50, this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y, 50, 50}, {this->_collisions[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x, this->_collisions[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y, 50, 50})) {
            return true;
        } else if (this->_stateMoving == "left" && CheckCollisionRecs({this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x - 50, this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y, 50, 50}, {this->_collisions[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x, this->_collisions[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y, 50, 50})) {
            return true;
        } else if (this->_stateMoving == "up" && CheckCollisionRecs({this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x, this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y - 50, 50, 50}, {this->_collisions[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x, this->_collisions[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y, 50, 50})) {
            return true;
        } else if (this->_stateMoving == "down" && CheckCollisionRecs({this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x, this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y + 50, 50, 50}, {this->_collisions[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x, this->_collisions[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y, 50, 50})) {
            return true;
        }
    }
    return false;
}

void rtype::Features::catchInput()
{
    if (IsKeyDown(KEY_RIGHT) && !this->_IsMoving) {
        this->_IsMoving = true;
        this->_stateMoving = "right";

        if (checkCollision()) {
            this->_IsMoving = false;
            this->_stateMoving = "";
            return;
        }

        this->_PositionStart = this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position;
        this->_PositionEnd = {this->_PositionStart.x + 50, this->_PositionStart.y};
    } else if (IsKeyDown(KEY_LEFT) && !this->_IsMoving) {
        this->_IsMoving = true;
        this->_stateMoving = "left";

        if (checkCollision()) {
            this->_IsMoving = false;
            this->_stateMoving = "";
            return;
        }

        this->_PositionStart = this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position;
        this->_PositionEnd = {this->_PositionStart.x - 50, this->_PositionStart.y};
    } else if (IsKeyDown(KEY_UP) && !this->_IsMoving) {
        this->_IsMoving = true;
        this->_stateMoving = "up";

        if (checkCollision()) {
            this->_IsMoving = false;
            this->_stateMoving = "";
            return;
        }

        this->_PositionStart = this->getEntity("player")->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position;
        this->_PositionEnd = {this->_PositionStart.x, this->_PositionStart.y - 50};
    } else if (IsKeyDown(KEY_DOWN) && !this->_IsMoving) {
        this->_IsMoving = true;
        this->_stateMoving = "down";

        if (checkCollision()) {
            this->_IsMoving = false;
            this->_stateMoving = "";
            return;
        }

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
            // DrawTexture(this->_map[i]->getComponent<rtype::ECS::Ecs3D::Texture2d>()->texture, this->_map[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.x, this->_map[i]->getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position.y, WHITE);
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
