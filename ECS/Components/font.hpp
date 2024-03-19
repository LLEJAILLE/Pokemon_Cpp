/*
** EPITECH PROJECT, 2024
** RType
** File description:
** font
*/

#pragma once
#include "interface.hpp"

    namespace ECS {
            class FontComponent : public IComponent {
                public:
                    std::string id;
                    float size;
                    std::string filepath;
                    Font font;

                    // Constructor
                    FontComponent(std::string id, float size, std::string filepath)
                        : id(id), size(size), filepath(filepath) {
                            font = LoadFontEx(filepath.c_str(), size, 0, 250);
                        }

                        std::string getName() const override { return id; }
            };
        }
