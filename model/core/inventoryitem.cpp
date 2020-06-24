#include "inventoryitem.h"

//costruttore
InventoryItem::InventoryItem(std::string _name, U_SHORT _itemLevel, std::string _description, U_SHORT _duration, double _weight) {
    setName(_name);
    setItemLevel(_itemLevel);
    setDescription(_description);
    setDuration(_duration);
    setWeight(_weight);
}

//metodi setter
void InventoryItem::setName(const std::string & _name) {
    if(_name.size() > 100)
        name="unknown";
    else
        name=_name;
}

void InventoryItem::setItemLevel(const U_SHORT & _itemLevel) {
    if(_itemLevel < 0 || _itemLevel > 99)
        itemLevel = 0;
    else
        itemLevel=_itemLevel;
}

void InventoryItem::setDescription(const std::string & _description) {
    if(_description.size() > 500)
        description = "";
    else
        description=_description;
}

void InventoryItem::setDuration(const U_SHORT & _duration) {
    if(_duration < 0 || _duration > 500)
        duration=0;
    else
        duration=_duration;
}

void InventoryItem::setWeight(const double & _weight) {
    if(_weight < 0 || _weight > 250)
        weight = 0;
    else
        weight=_weight;
}

//metodi getter
std::string InventoryItem::getName() const { return name; }
U_SHORT InventoryItem::getItemLevel() const { return itemLevel; }
std::string InventoryItem::getDescription() const { return description; }
U_SHORT InventoryItem::getDuration() const { return duration; }
double InventoryItem::getWeight() const { return weight; }
