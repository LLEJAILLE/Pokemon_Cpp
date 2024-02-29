/*
** TALWEB PROJECT, 2023
** ecs_rType
** File description:
** entity
*/

#include "./common.hpp"

enum Place {
    LOBBY,               // Represents the lobby place
    LOADING,             // Represents the loading place
    STORE,               // Represents the store place
    VIDEOSETTINGS,       // Represents the video settings place
    MOUSESETTINGS,       // Represents the mouse settings place
    CONTROLSSETTINGS,    // Represents the controls settings place
    AUDIOSETTINGS,       // Represents the audio settings place
    PROFILSETTINGS       // Represents the profile settings place
};

namespace rtype {
    class Game {
        public:
            Place currentPlace;
            
            Game() : currentPlace(LOBBY) {}

            void setPlace(Place place) { currentPlace = place; }

            Place getPlace() { return currentPlace; }

        private:
    };
}

