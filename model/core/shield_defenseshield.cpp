#include "shield_defenseshield.h"

DefenseShield::DefenseShield(string n, U_SHORT il, string d, U_INT pred, U_INT mred, U_INT _speedPenality) :
Shield(n, il, d, pred, mred) {
    setSpeedPenality(_speedPenality);
}

DefenseShield *DefenseShield::clone() const {
    return new DefenseShield(*this);
}

//SETTER
void DefenseShield::setSpeedPenality(const unsigned int & _speedPenality) {
    if(_speedPenality > 0 && _speedPenality < 100)
        speedPenality = _speedPenality;
    else
        speedPenality = 0;
}

//GETTER
unsigned int DefenseShield::getSpeedPenality() const { return speedPenality; }

//METODI
double DefenseShield::getTotalRed() const {
    return Shield::getTotalRed();
}
