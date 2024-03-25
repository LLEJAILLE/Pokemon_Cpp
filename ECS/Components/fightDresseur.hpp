/*
** EPITECH PROJECT, 2023
** ecs_rType
** File description:
** fightDresseur
*/

#pragma once
#include "interface.hpp"

struct Pokemon {
    std::string name;
    int level;
};

struct Trainer {
    std::string name;
    std::string id;
    std::vector<Pokemon> pokemons;
};

namespace ECS {
    class FightDresseur : public IComponent {
        public:
            float rotation;
            std::string id;
            std::vector<Trainer> trainers;

            // Constructor
            FightDresseur(std::string id, float rotation) : id(id), rotation(rotation) {
                // parse trainer file and fill trainers vector
                std::ifstream file("./maps/trainers.txt");
                std::string line;


            }

            std::string getName() const override { return id; }
    };
}