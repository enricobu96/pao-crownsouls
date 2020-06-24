#include "ring.h"

Ring::Ring(string n, U_SHORT il, string d, string _flavour) : InventoryItem(n, il, d), flavour(_flavour) {}

std::string Ring::getFlavour() const
{
    return flavour;
}
