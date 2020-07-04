#include "shield_defenseshield.h"

DefenseShield::DefenseShield(string n, U_INT il, string d, U_INT pred, U_INT mred) :
    InventoryItem(n, il, d), Shield(pred, mred) {}

DefenseShield *DefenseShield::clone() const {
    return new DefenseShield(*this);
}

//METODI
double DefenseShield::getTotalRed() const {
    return Shield::getTotalRed();
}
