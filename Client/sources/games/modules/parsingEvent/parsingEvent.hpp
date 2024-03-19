/*
** File description:
** ParsingEvent
*/

#ifndef PARSINGEVENT_HPP_
    #define PARSINGEVENT_HPP_
    #include "../../../../includes/MainInclusdes.hpp"
    #include <filesystem>

namespace modules {
    class ParsingEvent {
        ParsingEvent() = default;
        ~ParsingEvent() = default;

        public:
            static void parseAndFillPnj(std::string path, std::map<int, std::shared_ptr<ECS::Ecs3D::IEntity>> &_eventsCol);
    };
}

#endif /* !PARSINGEVENT_HPP_ */
