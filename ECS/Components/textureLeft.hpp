/*
** EPITECH PROJECT, 2023
** ecs_rType
** File description:
** buttonmenu
*/

#pragma once
#include "interface.hpp"

namespace ECS {
    class TextureLeft : public IComponent {
        public:
            Texture2D texture;
            std::string id;

            // Constructor
            TextureLeft(Image Image, std::string id) {
                texture = LoadTextureFromImage(Image);
                this->id = id;
            }

            std::string getName() const override { return id; }
    };
}