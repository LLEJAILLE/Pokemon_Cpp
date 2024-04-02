/*
** EPITECH PROJECT, 2023
** ecs_rType
** File description:
** infosPlayer
*/

#pragma once
#include "interface.hpp"

namespace ECS {
    class InfosPlayer : public IComponent {
        public:
            std::string id;
            std::string name;
            std::string idPlayer;
            int pokeDollar;
            int nbBadges;
            int hoursPlayed;
            int minutesPlayed;
            std::vector<std::pair<int, int>> _inventoryPlayer;
            std::vector<std::vector<std::map<std::string, std::string>>> playerPokemons;

            // Constructor
            InfosPlayer(std::string id, std::string name, std::string idPlayer, int hoursPlayed, int minutesPlayed, std::vector<std::pair<int, int>> _inventoryPlayer) : id(id), name(name), idPlayer(idPlayer), hoursPlayed(hoursPlayed), minutesPlayed(minutesPlayed), _inventoryPlayer(_inventoryPlayer) {
                this->pokeDollar = 0;
                this->nbBadges = 0;

                // add pokemons
                this->playerPokemons.push_back({
                    {
                        {"name", "Bulbasaur"},
                        {"type 1", "Grass"},
                        {"type 2", "Poison"},
                        {"level", "5"},
                        {"xp", "0"},
                        {"hp", "45"},
                        {"hpMax", "45"},
                        {"attack", "49"},
                        {"defense", "49"},
                        {"speed", "45"},
                        {"special-attack", "65"},
                        {"special-defense", "65"},
                        {"moves", "0, 1, 2"},
                        {"ivs", "0, 0, 0, 0, 0, 0"},
                        {"evs", "0, 0, 0, 0, 0, 0"}
                    },
                    {
                        {"name", "Charmander"},
                        {"type 1", "Fire"},
                        {"level", "5"},
                        {"xp", "0"},
                        {"hp", "39"},
                        {"hpMax", "45"},
                        {"attack", "52"},
                        {"defense", "43"},
                        {"speed", "65"},
                        {"special-attack", "60"},
                        {"special-defense", "50"},
                        {"moves", "0, 1, 2"},
                        {"ivs", "0, 0, 0, 0, 0, 0"},
                        {"evs", "0, 0, 0, 0, 0, 0"}
                    },
                });
            }

            InfosPlayer(std::string id, std::string name): id(id), name(name) {
                auto now = std::chrono::system_clock::now();
                auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
                auto epoch = now_ms.time_since_epoch();
                auto value = std::chrono::duration_cast<std::chrono::milliseconds>(epoch);

                // Convert the time to a string
                std::string timestamp = std::to_string(value.count());

                // Generate a random number
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dis(0, 9999);
                std::string random = std::to_string(dis(gen));

                // Concatenate the timestamp and random number to form the UID
                this->idPlayer = timestamp + random;
            }

            std::string getName() const override { return id; }
    };
}