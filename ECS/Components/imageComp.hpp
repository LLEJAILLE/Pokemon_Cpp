/*
** EPITECH PROJECT, 2023
** ecs_rType
** File description:
** buttonmenu
*/

#pragma once
#include "interface.hpp"

namespace ECS {
    class ImageComp : public IComponent {
        public:
            Image image;
            std::string id;

            // Constructor
            ImageComp(std::string filePath, std::string id) {
                image = LoadImage(filePath.c_str());
                this->id = id;
            }
            std::string getName() const override { return id; }
    };
}