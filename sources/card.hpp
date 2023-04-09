#include <array>

#pragma once

namespace ariel {

    class Card {
        
        public:
            Card(char, int);
            char get_symbol() const;
            int get_number() const;
            constexpr static std::array<char, 4> symbols = {'c', 'd', 'h', 's'};
            const bool operator<(const Card&);
            bool operator==(const Card&) const;
        private:
            char symbol;
            int number;
            
    };
}