#include <string>
#include <iostream>
#include "pile.hpp"
#include "player.hpp"

namespace ariel {
    class Game {
        
        public:
            Game(Player&, Player&);
            void playTurn();
            void printLastTurn();
            void playAll();
            void printWiner();
            void printLog();
            void printStats();
        private:
            Player &p1;
            Player &p2;
            Pile pile;
            int round_number;
            std::vector<std::string> log;
    };
}