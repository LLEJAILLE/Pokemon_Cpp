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

        void run();
        void loadSave();

    protected:

    private:
        SoundManager _soundManager;

    private:
        _Scene _scene;
        std::map<_Scene, std::shared_ptr<ECS::AScene>> allScenes;
        std::map<std::string, std::vector<int>> _historyValues;

        // from load save
        std::string _playerName;
        std::string _playerId;
        int hourPlayed;
        int minutePlayed;
        Vector2 _playerPosition;
        std::vector<std::pair<int, int>> _inventoryPlayer;
};
