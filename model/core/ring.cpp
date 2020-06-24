#include "ring.h"

Ring::Ring(string _flavour) : flavour(_flavour) {}

std::string Ring::getFlavour() const
{
    return flavour;
}
