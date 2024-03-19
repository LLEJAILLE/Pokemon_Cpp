#include "parsingEvent.hpp"

void modules::ParsingEvent::parseAndFillPnj(std::string path, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_eventsCol)
{
    std::ifstream file("./maps/featuresMap/featuresEvents.txt");
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            if (line.empty()) {
                continue;
            }

            if (line == "OnClick") {
                std::string type;
                int numberEvent;
                std::string nameEvent;
                float x, y;
                std::string pathTextUp;
                std::string pathTextDown;
                std::string pathTextLeft;
                std::string pathTextRight;
                int numberOfCommonSwitch;

                type = line;
                std::getline(file, line);
                numberEvent = std::stoi(line);
                std::getline(file, line);
                nameEvent = line;
                std::getline(file, line);
                std::istringstream iss(line);
                iss >> x >> y;
                x *= 50;
                y *= 50;
                std::getline(file, line);
                pathTextUp = line.substr(line.find("\"") + 1, line.rfind("\"") - line.find("\"") - 1);
                std::getline(file, line);
                pathTextDown = line.substr(line.find("\"") + 1, line.rfind("\"") - line.find("\"") - 1);
                std::getline(file, line);
                pathTextLeft = line.substr(line.find("\"") + 1, line.rfind("\"") - line.find("\"") - 1);
                std::getline(file, line);
                pathTextRight = line.substr(line.find("\"") + 1, line.rfind("\"") - line.find("\"") - 1);
                std::getline(file, line);
                numberOfCommonSwitch = std::stoi(line);
                
                int eventTmp = 0;
                std::map<int, std::vector<std::string>> events;
                while (std::getline(file, line) && !line.empty()) {
                    std::string tmp = "--" + std::to_string(eventTmp);

                    if (line.find(tmp) == 0) {
                        std::getline(file, line);
                        while (line.find(tmp) != 0) {
                            events[eventTmp].push_back(line);
                            std::getline(file, line);
                        }

                        eventTmp++;
                    }
                }

                ECS::Ecs3D::IEntity event("event " + std::to_string(numberEvent));
                Texture2D textureUp = LoadTexture(pathTextUp.c_str());
                Texture2D textureDown = LoadTexture(pathTextDown.c_str());
                Texture2D textureLeft = LoadTexture(pathTextLeft.c_str());
                Texture2D textureRight = LoadTexture(pathTextRight.c_str());

                event.addComponent<ECS::Ecs3D::EventClickComp>("event " + std::to_string(numberEvent), type, numberEvent, nameEvent, Vector2{x, y}, textureUp, textureDown, textureLeft, textureRight, numberOfCommonSwitch, events);

                _eventsCol.insert(std::pair<int, std::shared_ptr<ECS::Ecs3D::IEntity>>(_eventsCol.size(), std::make_shared<ECS::Ecs3D::IEntity>(event)));
            }
        }
    }

    file.close();
}