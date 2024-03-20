/*
** EPITECH PROJECT, 2023
** ecs_rType
** File description:
** itemsPlayer
*/

#pragma once
#include "interface.hpp"

namespace ECS {
    class ItemsPlayer : public IComponent {
        public:
            std::string id;
            std::vector<std::vector<std::variant<int, std::string>>> items;
            std::vector<int> inventory;

            // Constructor
            ItemsPlayer(std::string id): id(id) {
                items.push_back({0, "Potion", "Heal 20 HP", 200, 100, "Town", true});
                items.push_back({1, "Super Potion", "Heal 50 HP", 700, 350, "Town", true});
                items.push_back({2, "Hyper Potion", "Heal 200 HP", 1200, 600, "Town", true});
                items.push_back({3, "Max Potion", "Heal all HP", 2500, 1250, "Town", true});
                items.push_back({4, "Revive", "Revive 50% HP", 1500, 750, "Town", true});
                items.push_back({5, "Max Revive", "Revive all HP", 3000, 1500, "Town", true});
                items.push_back({6, "Pokedex", "Show all pokemon", 0, 0, "Town", false});
            }

            std::string getName() const override { return id; }
    };
}