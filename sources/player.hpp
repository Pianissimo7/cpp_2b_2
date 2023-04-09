#include "pile.hpp"
#include <string>

#pragma once

namespace ariel {
    class Player {
        
        public:
            Player(std::string);
            int stacksize();
            int cardesTaken();
            void set_pile(Pile);
            Card draw_card();
            void take_cards(int);
            std::string get_name();
        private:
            std::string name;
            Pile pile;
            int cards_taken;
    };
}