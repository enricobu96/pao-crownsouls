#ifndef FULL_H
#define FULL_H

#include "shield.h"

class DefenseShield : public Shield {
public:

    DefenseShield(string, U_SHORT, string, U_INT, U_INT);
    virtual DefenseShield* clone() const;

    //METODI
    virtual double getTotalRed() const;

};

#endif // FULL_H
