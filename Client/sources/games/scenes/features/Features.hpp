/*
** File description:
** FEATURES
*/

#ifndef FEATURES_HPP_
    #define FEATURES_HPP_
    #include "../../../../includes/MainInclusdes.hpp"
    #include <filesystem>

namespace rtype {

    class Features : public ECS::Ecs3D::AScene {
        public:
            Features(_Scene &scene, SoundManager &soundManager) : _scene(scene), _soundManager(soundManager) {
                this->camera.target = { static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2) };
                this->camera.offset = { static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2) };
                this->camera.rotation = 0.0f;
                this->camera.zoom = 1.0f;
                parseMap("./maps/1.txt", "./maps/config1.txt");
            }
            ~Features();

            void draw() override;
            void update(float deltatime, float getTime) override;

            // function of classes no override

            void updateMoving(float deltatime);
            void catchInput();

            // parsing
            void parseMap(std::string path, std::string config);

            std::map<std::string, std::string> parseConfig(std::ifstream &config)
            {
                std::map<std::string, std::string> configMap;
                std::string line;

                while (std::getline(config, line)) {
                    // i want to store the parsing of the config in std::map<std::string, std::string> (config is write like char path)
                    // split the line with the first ' '
                    // store the first part in the map as the key and the second part as the value

                    std::string key = line.substr(0, line.find(' '));
                    std::string value = line.substr(line.find(' ') + 1);

                    configMap.insert(std::pair<std::string, std::string>(key, value));
                }
                return configMap;
            }

            // collision
            bool checkCollision();


            SoundManager &_soundManager;

            _Scene &_scene;


        private:
            bool _IsMoving = false;
            float speed = 150;

            Vector2 _PositionStart = {0, 0};
            Vector2 _PositionEnd = {0, 0};

            std::string _stateMoving = "";

            Camera2D camera;

            std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> _map;

            std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> _collisions;

            std::map<std::string, std::string> _indexFilePathText;
    };
}

#endif /* !FEATURES_HPP_ */
