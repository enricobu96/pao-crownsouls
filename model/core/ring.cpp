#include "ring.h"

Ring::Ring(string n, U_SHORT il, string d, unsigned int _statsIncreasing) : InventoryItem(n, il, d), statsIncreasing(_statsIncreasing) {}

Ring *Ring::clone() const {
    return new Ring(*this);
}

//SETTER
void Ring::setStatsIncreasing(const U_INT & _statsIncreasing) {
    if(_statsIncreasing > 3)
        statsIncreasing = 0;
    else
        statsIncreasing = _statsIncreasing;
}

//GETTER
unsigned int Ring::getStatsIncreasing() const {
    return statsIncreasing;
}

//METODI
std::string Ring::getType() const {
    return "ring";
}
