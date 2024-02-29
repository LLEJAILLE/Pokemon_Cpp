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
            }
            ~Features();

            void draw() override;
            void update(float deltatime, float getTime) override;

            // function of classes no override

            void updateMoving(float deltatime);
            void catchInput();

            SoundManager &_soundManager;

            _Scene &_scene;


        private:
            bool _IsMoving = false;
            float speed = 150;

            Vector2 _PositionStart = {0, 0};
            Vector2 _PositionEnd = {0, 0};

            std::string _stateMoving = "";

            Camera2D camera;
    };
}

#endif /* !FEATURES_HPP_ */
