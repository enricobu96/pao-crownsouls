#include "inventory.h"

Inventory::Inventory()
{

}

Inventory::SmartP::SmartP(InventoryItem *q): p(q != nullptr ? q->clone() : nullptr) {}

Inventory::SmartP::SmartP(const Inventory::SmartP &s): p(s.p != nullptr ? (s.p)->clone() : nullptr) {}

Inventory::SmartP &Inventory::SmartP::operator=(const Inventory::SmartP &s) {
    if(this!= &s) {
        if(p) delete p;
        p = s.p !=nullptr ? (s.p)->clone() : nullptr;
    }
    return *this;
}

Inventory::SmartP::~SmartP() {if(p) delete p;}

InventoryItem *Inventory::SmartP::operator->() const {return p;}

InventoryItem &Inventory::SmartP::operator*() const {return *p;}
