#include "card.hpp"

using namespace ariel;

Card::Card(char symbol, int number): symbol(symbol), number(number) {
    
}
char Card::get_symbol() const {
    return this->symbol;
}
int Card::get_number() const {
    return this->number;
}
const bool Card::operator<(const Card& other) {
    return this->get_number() < other.get_number();
}
bool Card::operator==(const Card& other) const {
    return this->get_number() == other.get_number();
}