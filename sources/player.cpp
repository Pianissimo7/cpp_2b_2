#include "player.hpp"
using namespace ariel;

Player::Player(std::string name): cards_taken(0), name(name) {
    
}
int Player::stacksize() {
    return this->pile.get_size();
}
int Player::cardesTaken() {
    return this->cards_taken;
}
void Player::set_pile(Pile p) {
    this->pile = p;
}
Card Player::draw_card() {
    if (this->stacksize() == 0) {
        throw "cant draw from an empty stack";
    }
    return this->pile.draw_card();
}
void Player::take_cards(int n) {
    this->cards_taken += n;
}
std::string Player::get_name() {
    return this->name;
}