#include <vector>
#include "card.hpp"

#pragma once

namespace ariel {
    class Pile {
        
        public:
            Pile();
            void add_all();
            void split(Pile&, Pile&);
            void combine(Pile);
            Card draw_card();
            void add_card(Card);
            int get_size();
        private:
            std::vector<Card> pile;
            int size;
    };
}