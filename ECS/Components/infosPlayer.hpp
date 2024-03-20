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

            // Constructor
            InfosPlayer(std::string id): id(id) {
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