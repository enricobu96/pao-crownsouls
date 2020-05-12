#include "inventoryitem.h"


InventoryItem::InventoryItem(std::string _name, unsigned short _itemLevel, std::string _description, unsigned short _duration, double _weight) :
    name(_name), itemLevel(_itemLevel), description(_description), duration(_duration), weight(_weight) {}

void InventoryItem::setName(const std::string & _name) {
    name=_name;
}

void InventoryItem::setItemLevel(const unsigned short & _itemLevel) {
    itemLevel=_itemLevel;
}

void InventoryItem::setDescription(const std::string & _description) {
    description=_description;
}

void InventoryItem::setDuration(const unsigned short & _duration) {
    duration=_duration;
}

void InventoryItem::setWeight(const double & _weight) {
    weight=_weight;
}

std::string InventoryItem::getName() const {
    return name;
}

unsigned short InventoryItem::getItemLevel() const {
    return itemLevel;
}

std::string InventoryItem::getDescription() const {
    return description;
}

unsigned short InventoryItem::getDuration() const {
    return duration;
}

double InventoryItem::getWeight() const {
    return weight;
}
