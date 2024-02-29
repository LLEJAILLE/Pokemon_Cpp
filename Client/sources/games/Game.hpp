/*
** EPITECH PROJECT, 2023
** RType
** File description:
** Game
*/

#pragma once
    #include "../../includes/MainInclusdes.hpp"

    //? includes of all the scenes
    #include "scenes/features/Features.hpp"

    #include "soundManager/soundManager.hpp"

class Game {
    public:
        Game();
        ~Game();
        void detach()
        {
            // create the thread
        }

        void run();

    protected:

    private:
        rtype::SoundManager _soundManager;

    private:
        _Scene _scene;
        std::map<_Scene, std::shared_ptr<rtype::ECS::Ecs3D::AScene>> allScenes;
        std::map<std::string, std::vector<int>> _historyValues;

    private:
};
