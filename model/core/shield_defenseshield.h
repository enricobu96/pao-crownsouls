#ifndef FULL_H
#define FULL_H

#include "shield.h"

class DefenseShield : public Shield {
public:
    DefenseShield(string, U_SHORT, string, U_INT, U_INT, U_INT =0);

    void setSpeedPenality(const U_INT&);
private:
    U_INT speedPenality;
};

#endif // FULL_H
