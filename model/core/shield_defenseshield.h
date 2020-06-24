#ifndef FULL_H
#define FULL_H

#include "shield.h"

class Full : public Shield {
public:
    Full(U_INT =0);

    void setSpeedPenality(const U_INT&);
private:
    U_INT speedPenality;
};

#endif // FULL_H
