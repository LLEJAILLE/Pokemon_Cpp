#include "map.hpp"

void modules::Map::parseMap(std::string path, std::string config, std::map<std::string, std::string> &indexFilePathText, std::map<std::string, std::string> &indexFilePathColl, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &collisions, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &map)
{
    std::ifstream fileconfg(config);
    std::string lineConf;
    int nbLineConf = 0;

    while (std::getline(fileconfg, lineConf)) {
        nbLineConf++;
        if (lineConf.find("texture:") != std::string::npos) {
            while (std::getline(fileconfg, lineConf) && !lineConf.empty() && lineConf.find("collisions:") == std::string::npos) {
                std::string charac = lineConf.substr(0, lineConf.find(" "));
                std::string path = lineConf.substr(lineConf.find("=") + 2, lineConf.size());

                if (path.find(".png") != std::string::npos) {
                    path = path.substr(0, path.find(".png") + 4);
                }

                if (!charac.empty() || !path.empty() || charac != "" || path != "") {
                    indexFilePathText.insert(std::pair<std::string, std::string>(charac, path));
                }
            }
        }

        if (lineConf.find("collisions:") != std::string::npos) {
            while (std::getline(fileconfg, lineConf)) {
                std::string charac = lineConf.substr(0, lineConf.find(" "));
                std::string path = lineConf.substr(lineConf.find("=") + 2, lineConf.size());

                if (path.find(".png") != std::string::npos) {
                    path = path.substr(0, path.find(".png") + 4);
                }

                if (!charac.empty() || !path.empty() || charac != "" || path != "") {
                    indexFilePathColl.insert(std::pair<std::string, std::string>(charac, path));
                }
            }
        }
    }

    std::ifstream file(path);
    std::string line;
    int nbLine = 0;

    while (std::getline(file, line)) {
        nbLine++;
        for (int i = 0; i < line.size(); i++) {
            float x = i * 50;
            float y = nbLine * 50;
            
            auto it = indexFilePathText.find(std::string(1, line[i]));
            const char *file = it->second.c_str();

            if (it != indexFilePathText.end()) {
                ECS::Ecs3D::IEntity entity("ground" + std::to_string(i) + std::to_string(map.size()));
                entity.addComponent<ECS::Ecs3D::PositionComponent2d>(Vector2 {x, y}, "texturePosition");
                entity.addComponent<ECS::Ecs3D::Texture2d>(LoadImage(file), "texture");
                map.insert(std::pair<int, std::shared_ptr<ECS::Ecs3D::IEntity>>(map.size(), std::make_shared<ECS::Ecs3D::IEntity>(entity)));
            }

            auto itColl = indexFilePathColl.find(std::string(1, line[i]));
            const char *fileColl = itColl->second.c_str();

            if (itColl != indexFilePathColl.end()) {
                ECS::Ecs3D::IEntity entity("coll" + std::to_string(i) + std::to_string(collisions.size()));
                entity.addComponent<ECS::Ecs3D::PositionComponent2d>(Vector2 {x, y}, "texturePosition");
                entity.addComponent<ECS::Ecs3D::Texture2d>(LoadImage(fileColl), "texture");

                map.insert(std::pair<int, std::shared_ptr<ECS::Ecs3D::IEntity>>(map.size(), std::make_shared<ECS::Ecs3D::IEntity>(entity)));
                collisions.insert(std::pair<int, std::shared_ptr<ECS::Ecs3D::IEntity>>(collisions.size(), std::make_shared<ECS::Ecs3D::IEntity>(entity)));
            }

        }
    }

    file.close();
    fileconfg.close();
}