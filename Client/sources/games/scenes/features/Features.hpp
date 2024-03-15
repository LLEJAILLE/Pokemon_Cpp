/*
** File description:
** FEATURES
*/

#ifndef FEATURES_HPP_
    #define FEATURES_HPP_
    #include "../../../../includes/MainInclusdes.hpp"
    #include "../../modules/moves/updateMove.hpp"
    #include "../../modules/textures/textures.hpp"
    #include "../../modules/map/map.hpp"
    #include "../../modules/events/events.hpp"
    #include <filesystem>

namespace rtype {

    class Features : public ECS::Ecs3D::AScene {
        public:
            Features(_Scene &scene, SoundManager &soundManager, ECS::Ecs3D::IEntity &myPlayer)
            : _scene(scene), _soundManager(soundManager), _myPlayer(myPlayer)
            {
                rtype::modules::Map::parseMap("./maps/featuresMap/featuresMap.txt", "./maps/featuresMap/featuresConfig.txt", this->_indexFilePathText, this->_indexFilePathColl, this->_collisions, this->_map);

                this->parseAndFillPnj("./maps/featuresEvents.txt");

                this->_stateMoving = "down";
                this->camera.target = { static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2) };
                this->camera.offset = { static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2) };
                this->camera.rotation = 0.0f;
                this->camera.zoom = 1.0f;
                this->frameWidth = 50;
                this->frameHeight = 50;
                this->frameRec = { 0, 0, frameWidth, frameHeight };

                this->_mapFunction["move"] = &modules::Events::moveEvent;
                this->_mapFunction["text"] = &modules::Events::printEvent;
            }
            
            ~Features();

            void draw() override;
            void update(float deltatime, float getTime) override;

            void parseAndFillPnj(std::string path);
            void checkEventCol();

            SoundManager &_soundManager;
            _Scene &_scene;

            ECS::Ecs3D::IEntity &_myPlayer;

            using FuncPtr = void (modules::Events::*)(const std::string &);
            std::map<std::string, FuncPtr> _mapFunction;

        private:
            float _deltaTime = 0;

            float frameWidth = 0;
            float frameHeight = 0;
            int currentFrame = 0;
            int framesCounter = 0;

        
            Rectangle frameRec;
            std::string _stateMoving = "";
            bool _IsMoving = false;
            float speed = 150;
            Vector2 _PositionStart = {0, 0};
            Vector2 _PositionEnd = {0, 0};


            std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> _map;
            std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> _collisions;
            std::map<std::string, std::string> _indexFilePathText;
            std::map<std::string, std::string> _indexFilePathColl;

            std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> _eventsCol;
            std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> _eventsHover;

            Camera2D camera;
    };
}

#endif /* !FEATURES_HPP_ */
