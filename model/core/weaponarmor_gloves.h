#ifndef GLOVES_H
#define GLOVES_H

#include "weaponarmor.h"

class Gloves : public WeaponArmor {
public:

    Gloves(string, U_INT, string, U_INT, U_INT, U_INT, U_INT, U_INT, U_INT =0);
    virtual Gloves* clone() const;

    //SETTER
    void setStrScaling(const U_INT&);

    //GETTER
    U_INT getStrScaling() const;

    //METODI
    virtual double getTotalDef() const;

private:
    U_INT strScaling;
};

#endif // GLOVES_H
