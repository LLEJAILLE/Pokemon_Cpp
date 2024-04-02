/*
** EPITECH PROJECT, 2023
** ecs_rType
** File description:
** MovePokemons
*/

#pragma once
#include "interface.hpp"

namespace ECS {
    class MovePokemons : public IComponent {
        public:
            std::string id;
            std::vector<std::vector<std::map<std::string, std::string>>> movesPokemons;

            // Constructor
            MovePokemons(std::string id) : id(id) {
                // add moves
                this->movesPokemons.push_back({
                    {
                        {"id", "0"},
                        {"name", "Tackle"},
                        {"type", "Normal"},
                        {"category", "Physical"},
                        {"power", "40"},
                        {"accuracy", "100"},
                        {"pp", "35"},
                        {"priority", "0"},
                        {"effect", "None"},
                        {"description", "A physical attack in which the user charges and slams into the target with its whole body."}
                    },
                    {
                        {"id", "1"},
                        {"name", "Growl"},
                        {"type", "Normal"},
                        {"category", "Status"},
                        {"power", "0"},
                        {"accuracy", "100"},
                        {"pp", "40"},
                        {"priority", "0"},
                        {"effect", "Lowers the target's Attack by one stage."},
                        {"description", "The user growls in an endearing way, making opposing Pokémon less wary. This lowers their Attack stat."}
                    },
                    {
                        {"id", "2"},
                        {"name", "Leech Seed"},
                        {"type", "Grass"},
                        {"category", "Status"},
                        {"power", "0"},
                        {"accuracy", "90"},
                        {"pp", "10"},
                        {"priority", "0"},
                        {"effect", "Seeds the target, stealing some HP from it every turn."},
                        {"description", "A seed is planted on the target. It steals some HP from the target every turn."}
                    },
                    {
                        {"id", "3"},
                        {"name", "Vine Whip"},
                        {"type", "Grass"},
                        {"category", "Physical"},
                        {"power", "45"},
                        {"accuracy", "100"},
                        {"pp", "25"},
                        {"priority", "0"},
                        {"effect", "None"},
                        {"description", "The target is struck with slender, whiplike vines to inflict damage."}
                    }
                });
            }

            std::string getName() const override { return id; }
    };
}