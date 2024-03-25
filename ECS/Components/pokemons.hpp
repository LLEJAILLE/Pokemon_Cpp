/*
** EPITECH PROJECT, 2023
** ecs_rType
** File description:
** pokemons
*/

#pragma once
#include "interface.hpp"

namespace ECS {
    class Pokemons : public IComponent {
        public:
            std::string id;
            std::vector<std::vector<std::map<std::string, std::string>>> pokemons;

            std::string getName() const override { return id; }

            // Constructor
            Pokemons(std::string id) : id(id) {
                pokemons.push_back({
                    {
                        {"id", "0"},
                        {"name", "Bulbasaur"},
                        {"description", "A strange seed was planted on its back at birth. The plant sprouts and grows with this POKéMON."},
                        {"type 1", "Grass"},
                        {"type 2", "Poison"},
                        {"pathFront", "Media/pokemons/bulbasaur.png"},
                        {"pathBack", "Media/pokemons/bulbasaur.png"}
                    },
                    {
                        {"id", "1"},
                        {"name", "Ivysaur"},
                        {"description", "When the bulb on its back grows large, it appears to lose the ability to stand on its hind legs."},
                        {"type 1", "Grass"},
                        {"type 2", "Poison"},
                        {"path", "Media/pokemons/ivysaur.png"},
                        {"pathBack", "Media/pokemons/ivysaur.png"}
                    },
                    {
                        {"id", "2"},
                        {"name", "Venusaur"},
                        {"description", "There is a large flower on VENUSAUR's back. The flower is said to take on vivid colors if it gets plenty of nutrition and sunlight."},
                        {"type 1", "Grass"},
                        {"type 2", "Poison"},
                        {"path", "Media/pokemons/venusaur.png"},
                        {"pathBack", "Media/pokemons/venusaur.png"}
                    },
                    {
                        {"id", "3"},
                        {"name", "Charmander"},
                        {"description", "The flame at the tip of its tail makes a sound as it burns. You can only hear it in quiet places."},
                        {"type 1", "Fire"},
                        {"path", "Media/pokemons/charmander.png"},
                        {"pathBack", "Media/pokemons/charmander.png"}
                    },
                    {
                        {"id", "4"},
                        {"name", "Charmeleon"},
                        {"description", "Charmeleon mercilessly destroys its foes using its sharp claws. If it encounters a strong foe, it turns aggressive."},
                        {"type 1", "Fire"},
                        {"path", "Media/pokemons/charmeleon.png"},
                        {"pathBack", "Media/pokemons/charmeleon.png"}
                    },
                    {
                        {"id", "5"},
                        {"name", "Charizard"},
                        {"description", "Charizard flies around the sky in search of powerful opponents. It breathes fire of such great heat that it melts anything."},
                        {"type 1", "Fire"},
                        {"type 2", "Flying"},
                        {"path", "Media/pokemons/charizard.png"},
                        {"pathBack", "Media/pokemons/charizard.png"}
                    },
                    {
                        {"id", "6"},
                        {"name", "Squirtle"},
                        {"description", "Squirtle's shell is not merely used for protection. The shell's rounded shape and the grooves on its surface help minimize resistance in water, enabling this POKéMON to swim at high speeds."},
                        {"type 1", "Water"},
                        {"path", "Media/pokemons/squirtle.png"},
                        {"pathBack", "Media/pokemons/squirtle.png"}
                    },
                    {
                        {"id", "7"},
                        {"name", "Wartortle"},
                        {"description", "Its long, furry tail is a symbol of longevity, making it quite popular among older people."},
                        {"type 1", "Water"},
                        {"path", "Media/pokemons/wartortle.png"},
                        {"pathBack", "Media/pokemons/wartortle.png"}
                    },
                    {
                        {"id", "8"},
                        {"name", "Blastoise"},
                        {"description", "Blastoise has water spouts that protrude from its shell. The water spouts are very accurate. They can shoot bullets of water with enough accuracy to strike empty cans from a distance of over 160 feet."},
                        {"type 1", "Water"},
                        {"path", "Media/pokemons/blastoise.png"},
                        {"pathBack", "Media/pokemons/blastoise.png"}
                    },
                });
            }
    };
}