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

                this->frameWidth = 50;
                this->frameHeight = 50;

                this->frameRec = { 0, 0, frameWidth, frameHeight };
            }
            ~Features();

            void draw() override;
            void update(float deltatime, float getTime) override;

            // function of classes no override

            void updateMoving(float deltatime);
            void catchInput();

            // parsing
            void parseMap(std::string path, std::string config);

            // collision
            bool checkCollision();

            // sprite
            void updateTexture(float speed, float deltatime);


            SoundManager &_soundManager;

            _Scene &_scene;


        private:
            float frameWidth = 0;
            float frameHeight = 0;
            int currentFrame = 0;
            int framesCounter = 0;

            Rectangle frameRec;
        
            bool _IsMoving = false;
            float speed = 150;
            float _deltaTime = 0;


            Vector2 _PositionStart = {0, 0};
            Vector2 _PositionEnd = {0, 0};

            std::string _stateMoving = "";

            Camera2D camera;

            std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> _map;

            std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> _collisions;

            std::map<std::string, std::string> _indexFilePathText;

            std::map<std::string, std::string> _indexFilePathColl;
    };
}

#endif /* !FEATURES_HPP_ */
