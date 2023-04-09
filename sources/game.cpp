#include "game.hpp"

using namespace ariel;
using namespace std;

Game::Game(Player& p1, Player& p2): round_number(1), p1(p1), p2(p2) {
    Pile pile = Pile();
    pile.add_all();
    Pile p1_pile;
    Pile p2_pile;
    // split the pile into 2
    pile.split(p1_pile, p2_pile);
    // set both player's piles
    p1.set_pile(p1_pile);
    p2.set_pile(p2_pile);
}
void Game::playTurn() {
    if (&p1 == &p2) {
        throw "both players are the same player???";
    }
    if (this->p1.stacksize() == 0 || this->p2.stacksize() == 0) {
        throw "unable to play turn as the game had already ended";
    }
    Card p1_card = this->p1.draw_card();
    Card p2_card = this->p2.draw_card();

    this->pile.add_card(p1_card);
    this->pile.add_card(p2_card);

    while (p1_card == p2_card) {
        log.push_back("DEBUG: round: " + to_string(round_number) + " tie: " + p1_card.get_symbol() + to_string(p1_card.get_number()));
        if (this->p1.stacksize() == 0 || this->p2.stacksize() == 0) {
            this->p1.take_cards(pile.get_size() / 2);
            this->p2.take_cards(pile.get_size() / 2);
            log.push_back("DEBUG: tie, not enough cards");
            return;
        }
        // place 2 cards upside down
        p1_card = this->p1.draw_card();
        p2_card = this->p2.draw_card();
        this->pile.add_card(p1_card);
        this->pile.add_card(p2_card);
        if (this->p1.stacksize() == 0 || this->p2.stacksize() == 0) {
            this->p1.take_cards(pile.get_size() / 2);
            this->p2.take_cards(pile.get_size() / 2);
            log.push_back("DEBUG: tie, not enough cards");
            return;
        }
        // each player opens a card
        p1_card = this->p1.draw_card();
        p2_card = this->p2.draw_card();
    }
    if (p1_card < p2_card) {
        // if p2's card is higher, he takes the pile
        this->p2.take_cards(pile.get_size());
        
        log.push_back("DEBUG: round: " + to_string(round_number) + " player 2 won: " + p1_card.get_symbol() + to_string(p1_card.get_number()) + "vs" + p2_card.get_symbol() + to_string(p2_card.get_number()));
    }
    else {
        // if p1's card is higher, he takes the pile
        this->p1.take_cards(pile.get_size());

        log.push_back("DEBUG: round: " + to_string(round_number) + " player 1 won: " + p1_card.get_symbol() + to_string(p1_card.get_number()) + "vs" + p2_card.get_symbol() + to_string(p2_card.get_number()));
    }
    // empty the pile
    Pile empty_pile;
    this->pile = empty_pile;
    round_number++;
}
void Game::printLastTurn() {
    cout << log.at(log.size() - 1) << endl;
}
void Game::playAll() {
    while (!(p1.stacksize() == 0 || p2.stacksize() == 0)) {
        this->playTurn();
    }
}
void Game::printWiner() {
    if (p1.cardesTaken() > p2.cardesTaken()) {
        cout << "the winner is: " << p1.get_name() << endl;
    }
    else if (p1.cardesTaken() > p2.cardesTaken()) {
        cout << "the winner is: " << p2.get_name() << endl;
    }
    else {
        cout << "tie!" << endl;
    }
}
void Game::printLog() {
    for (int i = 0 ; i < log.size() ; i++) {
        cout << log.at((u_long)i) << endl;
    }
    if (this->p1.stacksize() == 0 || this->p2.stacksize() == 0) {
        printWiner();
    }
}
void Game::printStats() {
    cout << "player 1 stack size: " << p1.stacksize() << endl;
    cout << "player 1 won: " << p1.cardesTaken() << " cards" << endl;
    cout << "player 2 stack size: " << p2.stacksize() << endl;
    cout << "player 2 won: " << p2.cardesTaken() << " cards" << endl;
    cout << "the total number of rounds was: " << round_number << endl;
}