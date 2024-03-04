/*
** EPITECH PROJECT, 2023
** ecs_rType
** File description:
** buttonmenu
*/

#pragma once
#include "interface.hpp"

namespace rtype::ECS::Ecs3D {
    class TextureRight : public IComponent {
        public:
            Texture2D texture;
            std::string id;

            // Constructor
            TextureRight(Image Image, std::string id) {
                texture = LoadTextureFromImage(Image);
                this->id = id;
            }

            std::string getName() const override { return id; }
    };
}