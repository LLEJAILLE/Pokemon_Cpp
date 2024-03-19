/*
** File description:
** Map
*/

#ifndef MAP_HPP_
    #define MAP_HPP_
    #include "../../../../includes/MainInclusdes.hpp"
    #include <filesystem>

namespace modules {
    class Map {
        Map() = default;
        ~Map() = default;

        public:
            static void parseMap(std::string path, std::string config, std::map<std::string, std::string> &indexFilePathText, std::map<std::string, std::string> &indexFilePathColl, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &collisions, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &map);
    };
}

#endif /* !MAP_HPP_ */
