#include "events.hpp"

namespace rtype::modules {
    void Events::printEvent(const std::string &action) {
        std::cout << action << std::endl;
    }

    void Events::moveEvent(const std::string &action) {
        std::cout << action << std::endl;
    }
}