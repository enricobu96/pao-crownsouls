#include "inventoryitem.h"

//costruttore
InventoryItem::InventoryItem(std::string _name, U_SHORT _itemLevel, std::string _description) {
    setName(_name);
    setItemLevel(_itemLevel);
    setDescription(_description);
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


//metodi getter
std::string InventoryItem::getName() const { return name; }
U_SHORT InventoryItem::getItemLevel() const { return itemLevel; }
std::string InventoryItem::getDescription() const { return description; }
