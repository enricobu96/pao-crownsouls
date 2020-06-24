#ifndef RING_H
#define RING_H

#include "inventoryitem.h"
#include "string"

using std::string;

class Ring : public InventoryItem {
public:
    Ring(string ="");

    string getFlavour() const;
private:
    string flavour;
};

#endif // RING_H
