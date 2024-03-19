/*
** TALWEB PROJECT, 2023
** ecs_rType
** File description:
** ecs
*/

#pragma once
#include "common.hpp"
#include "entity.hpp"
#include "IScene.hpp"

namespace ECS {
    class AScene {
    public:
        virtual ~AScene() = default;

        virtual void draw() = 0;

        virtual void update(float deltatime, float getTime) = 0;

        void addEntity(std::shared_ptr<IEntity> entity) {
            entities.insert(std::pair<std::string, std::shared_ptr<IEntity>>(entity->getName(), entity));
        }

        void addEntity(std::vector<std::shared_ptr<IEntity>> entities) {
            for (auto &entity : entities) {
                addEntity(entity);
            }
        }

        void removeEntity(std::shared_ptr<IEntity> entity) {
            entities.erase(entity->getName());
        }


        std::map<std::string, std::shared_ptr<IEntity>> getEntities() {
            return entities;
        }


        std::shared_ptr<IEntity> getEntity(std::string nameTag) {
            try {
                return entities.at(nameTag);
            } catch (const std::out_of_range &e) {
                std::cerr << "Entity not found: " << nameTag << std::endl;
                return nullptr;
            }
        }

        void printEntitiesWithComponents() {
            for (const auto &entity : entities) {
                std::cout << "Entity: " << entity.first << std::endl;
                const auto &components = entity.second->getComponents();
                for (const auto &component : components) {
                    std::cout << "    Component: " << component.first.name() << std::endl;
                }
            }
        }

    protected:
        std::map<std::string, std::shared_ptr<IEntity>> entities; /**< The map of entities in the scene. */
    };
}