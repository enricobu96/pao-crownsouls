#include "weaponarmor.h"

WeaponArmor::WeaponArmor(string n, U_SHORT il, string d, U_INT pdef, U_INT mdef, U_SHORT b, U_INT pdmg, U_INT mdmg) :
    InventoryItem(n, il, d), Armor(n, il, d, pdef, mdef, b), Weapon(n, il, d, pdmg, mdmg) {}
