#ifndef GLOVES_H
#define GLOVES_H

#include "weaponarmor.h"

class Gloves : public WeaponArmor {
public:

    Gloves(string, U_SHORT, string, U_INT, U_INT, U_SHORT, U_INT, U_INT, U_SHORT =0);
    virtual Gloves* clone() const;

    //SETTER
    void setStrScaling(const U_SHORT&);

    //GETTER
    U_SHORT getStrScaling() const;

    //METODI
    virtual double getTotalDef() const;

private:
    U_SHORT strScaling;
};

#endif // GLOVES_H
