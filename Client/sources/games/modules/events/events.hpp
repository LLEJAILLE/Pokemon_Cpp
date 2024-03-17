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
            void printEvent(const std::string &action, float deltatime);
            void moveEvent(const std::string &action, float deltatime);


            // ui
            Texture2D _dialogBox = LoadTexture("./Media/ui/dialogBox.png");
    };
}

#endif /* !EVENTS_HPP_ */
