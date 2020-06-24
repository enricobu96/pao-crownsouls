#ifndef FULL_H
#define FULL_H

#include "shield.h"

class DefenseShield : public Shield {
public:
    DefenseShield(string, U_SHORT, string, U_INT, U_INT, U_INT =0);
    virtual DefenseShield* clone() const;

    //SETTER
    void setSpeedPenality(const U_INT&);

    //GETTER
    U_INT getSpeedPenality() const;

    //METODI
    virtual double getTotalRed() const;
private:
    U_INT speedPenality;
};

#endif // FULL_H
