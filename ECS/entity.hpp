/*
** TALWEB PROJECT, 2023
** ecs_rType
** File description:
** entity
*/

#pragma once
#include "components.hpp"
#include <map>
#include <typeindex>

namespace ECS {
    /**
     * @brief Interface for an entity in the ECS system.
     */
    class IEntity
    {
    public:
        /**
         * @brief Constructs an IEntity object with the given entity name.
         * 
         * @param entityName The name of the entity.
         */
        IEntity(const std::string& entityName) : name(entityName) {}

        /**
         * @brief Destructor for the IEntity object.
         */
        ~IEntity() {}

        /**
         * @brief Gets the name of the entity.
         * 
         * @return The name of the entity.
         */
        std::string getName() const { return name; }

        /**
         * @brief Adds a component of type T to the entity.
         * 
         * @tparam T The type of the component.
         * @tparam Args The types of the arguments to construct the component.
         * @param args The arguments to construct the component.
         */
        template <typename T, typename... Args>
        void addComponent(Args&&... args) {
            components.emplace(typeid(T), std::make_shared<T>(std::forward<Args>(args)...));
        }

        /**
         * @brief Gets the component of type T from the entity.
         * 
         * @tparam T The type of the component to get.
         * @return The component of type T, or nullptr if the component does not exist.
         */
        template <typename T>
        std::shared_ptr<T> getComponent() const {
            try {
                return std::dynamic_pointer_cast<T>(components.at(typeid(T)));
            } catch (const std::out_of_range&) {
                return nullptr;
            }
        }

        //get component by name
    
       std::shared_ptr<IComponent> getComponentByName(const std::string& componentName) const {
            for (const auto& pair : components) {
                // std::cout << "component name: " << componentName << std::endl;
                std::cout << pair.second->getName() << std::endl;

                if (pair.second->getName() == componentName) {
                    return pair.second;
                }
            }
            return nullptr;
        }

        std::map<std::type_index, std::shared_ptr<IComponent>> getComponents() const {
            return components;
        }

        /**
         * @brief Checks if the entity has a component of type T.
         * 
         * @tparam T The type of the component to check.
         * @return True if the entity has a component of type T, false otherwise.
         */
        template <typename T>
        bool hasComponent() const {
            return components.find(typeid(T)) != components.end();
        }

        void printComponents() {
            for (const auto& component : components) {
                std::cout << "Component: " << component.first.name() << std::endl;
            }
        }

    private:
        std::map<std::type_index, std::shared_ptr<IComponent>> components; // Map of components associated with their type index.

        std::string name; // The name of the entity.
    };
}