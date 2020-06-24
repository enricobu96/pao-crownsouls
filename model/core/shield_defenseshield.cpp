#include "shield_defenseshield.h"

Full::Full(U_INT _speedPenality) {
    setSpeedPenality(_speedPenality);
}

void Full::setSpeedPenality(const unsigned int & _speedPenality) {
    if(_speedPenality > 0 && _speedPenality < 100)
        speedPenality = _speedPenality;
    else
        speedPenality = 0;
}
