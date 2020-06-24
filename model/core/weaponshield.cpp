#include "weaponshield.h"

WeaponShield::WeaponShield(string n, U_SHORT il, string d, U_INT pdmg, U_INT mdmg, U_INT pred, U_INT mred) :
InventoryItem(n, il, d), Weapon(n, il, d, pdmg, mdmg), Shield(n, il, d, pred, mred) {}
