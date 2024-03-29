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
    #include "../../modules/parsingEvent/parsingEvent.hpp"
    #include "../../modules/events/events.hpp"
    #include "../../modules/menu/menu.hpp"
    #include <filesystem>

    class Features : public ECS::AScene {
        public:
            Features(_Scene &scene, SoundManager &soundManager, ECS::IEntity &myPlayer, ECS::IEntity &pokemons)
            : _scene(scene), _soundManager(soundManager), _myPlayer(myPlayer), _pokemons(pokemons)
            {
                modules::Map::parseMap("./maps/featuresMap/featuresMap.txt", "./maps/featuresMap/featuresConfig.txt", this->_indexFilePathText, this->_indexFilePathColl, this->_collisions, this->_map);
                modules::ParsingEvent::parseAndFillPnj("./maps/featuresEvents.txt", this->_eventsCol);

                this->_stateMoving = "down";
                this->camera.target = { static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2) };
                this->camera.offset = { static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2) };
                this->camera.rotation = 0.0f;
                this->camera.zoom = 1.5f;
                this->frameWidth = 50;
                this->frameHeight = 50;
                this->frameRec = { 0, 0, frameWidth, frameHeight };

                this->_mapFunction["move_eventUp"] = &modules::Events::moveUpEvent;
                this->_mapFunction["move_eventDown"] = &modules::Events::moveDownEvent;
                this->_mapFunction["move_eventLeft"] = &modules::Events::moveLeftEvent;
                this->_mapFunction["move_eventRight"] = &modules::Events::moveRightEvent;
                this->_mapFunction["text"] = &modules::Events::printEvent;
                this->_mapFunction["lookPlayer"] = &modules::Events::lookPlayer;
            }
            
            ~Features();

            void draw() override;
            void update(float deltatime, float getTime) override;

            void checkEventCol();

            SoundManager &_soundManager;
            _Scene &_scene;

            ECS::IEntity &_myPlayer;
            ECS::IEntity &_pokemons;


            using FuncPtr = void (modules::Events::*)(const std::string &, float deltatime, std::map<int, std::shared_ptr<ECS::IEntity>> &_eventCol, std::shared_ptr<ECS::IEntity> &_thisEvent, Texture2D &dialogBox, ECS::IEntity &_myPlayer, Camera2D &camera, std::map<int, std::shared_ptr<ECS::IEntity>> &_map, std::string &_stateMoving, Rectangle &frameRec);
            std::map<std::string, FuncPtr> _mapFunction;

            modules::Events eventsInstance;

        private:
            Texture2D _dialogBox = LoadTexture("./Media/ui/dialogBox.png");
            Texture2D _menu = LoadTexture("./Media/ui/menu.png");
            Texture2D _cursor = LoadTexture("./Media/ui/focus.png");
            Vector2 _cursorPos = {1670, 50};

            float _deltaTime = 0;
            float frameWidth = 0;
            float frameHeight = 0;
            int currentFrame = 0;
            int framesCounter = 0;

            Rectangle frameRec;
            std::string _stateMoving = "";
            bool _IsMoving = false;
            bool waitBeforeOpenMenu = false;
            float speed = 150;
            Vector2 _PositionStart = {0, 0};
            Vector2 _PositionEnd = {0, 0};


            std::map<int, std::shared_ptr<ECS::IEntity>> _map;
            std::map<int, std::shared_ptr<ECS::IEntity>> _collisions;
            std::map<std::string, std::string> _indexFilePathText;
            std::map<std::string, std::string> _indexFilePathColl;

            std::map<int, std::shared_ptr<ECS::IEntity>> _eventsCol;
            std::map<int, std::shared_ptr<ECS::IEntity>> _eventsHover;

            Camera2D camera;
    };

#endif /* !FEATURES_HPP_ */
