#ifndef BODY_H
#define BODY_H

#include "armor.h"

class BodyArmor : public Armor {
public:

    BodyArmor(string, U_SHORT, string, U_INT, U_INT, U_SHORT, U_INT =0, U_INT =0);
    virtual BodyArmor* clone() const;

    //SETTER
    void setFallingDef(const U_INT&);
    void setStabbingDef(const U_INT&);

    //GETTER
    virtual U_INT getFallingDef() const;
    virtual U_INT getStabbingDef() const;

    //METODI
    virtual double getTotalDef() const;

private:
    U_INT fallingDef;
    U_INT stabbingDef;
};

#endif // BODY_H
