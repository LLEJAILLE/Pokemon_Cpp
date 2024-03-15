/*
** File description:
** Events
*/

#ifndef EVENTS_HPP_
    #define EVENTS_HPP_
    #include "../../../../includes/MainInclusdes.hpp"
    #include <filesystem>

namespace rtype::modules {
    class Events {
        public:
            Events() = default;
            ~Events() = default;
            void printEvent(const std::string &action);
            void moveEvent(const std::string &action);
    };
}

#endif /* !EVENTS_HPP_ */
