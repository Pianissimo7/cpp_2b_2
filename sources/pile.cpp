#include "pile.hpp"
using namespace ariel;
using namespace std;
Pile::Pile(): size(0) {

}
void Pile::add_all() {
    Card c = Card(0, 0);
    for (int j = 0; j < 4 ; j++) {
        for (int i = 1; i <= 13 ; i++) {
            this->add_card(Card(c.symbols.at((u_long)j), i));
        }
    }
    this->size = 52;
}
void Pile::split(Pile &p1, Pile &p2) {
    p1 = *this;
    int half_size = p1.size / 2;
    for (int i = 0 ; i < half_size ; i++) {
        p2.add_card(p1.draw_card());
    }
}
void Pile::combine(Pile p) {
    for (int i = 0 ; i < p.size ; i++) {
        this->add_card(p.draw_card());
    }
}
Card Pile::draw_card() {
    int index = std::rand() % this->size;
    Card ret = this->pile.at((u_long)index);
    this->pile.erase(this->pile.begin() + index);
    this->size--;
    return ret;
}
void Pile::add_card(Card c) {
    this->pile.push_back(c);
    this->size++;
}
int Pile::get_size() {
    return this->size;
}