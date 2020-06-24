#include "ring.h"

Ring::Ring(string n, U_SHORT il, string d, string _flavour) : InventoryItem(n, il, d), flavour(_flavour) {}

Ring *Ring::clone() const {
    return new Ring(*this);
}

//SETTER
void Ring::setFlavour(const std::string & _flavour) {
    if(_flavour.size() > 100)
        flavour = "unknown";
    else
        flavour = _flavour;
}

//GETTER
std::string Ring::getFlavour() const { return flavour; }
