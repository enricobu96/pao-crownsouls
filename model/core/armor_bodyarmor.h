#ifndef BODY_H
#define BODY_H

#include "armor.h"

class BodyArmor : public Armor {
public:
    BodyArmor(string, U_SHORT, string, U_INT, U_INT, U_SHORT, U_INT =0, U_INT =0);

    //metodi setter
    void setFallingDef(const U_INT&);
    void setStabbingDef(const U_INT&);

private:
    U_INT fallingDef;
    U_INT stabbingDef;
};

#endif // BODY_H
