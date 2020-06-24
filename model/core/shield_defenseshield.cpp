#include "shield_defenseshield.h"

DefenseShield::DefenseShield(string n, U_SHORT il, string d, U_INT pred, U_INT mred, U_INT _speedPenality) :
Shield(n, il, d, pred, mred) {
    setSpeedPenality(_speedPenality);
}

void DefenseShield::setSpeedPenality(const unsigned int & _speedPenality) {
    if(_speedPenality > 0 && _speedPenality < 100)
        speedPenality = _speedPenality;
    else
        speedPenality = 0;
}
