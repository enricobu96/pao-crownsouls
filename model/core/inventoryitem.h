#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H


#include<string>
using std::string;

//just some macros
#define U_INT unsigned int
#define U_SHORT unsigned short

class InventoryItem
{
public:
    InventoryItem(string ="Nome non definito", U_SHORT =0, string ="Descrizione non definita", U_SHORT =0, double =0.0);

    //copia profonda
    virtual InventoryItem* clone() const =0;

    //setter propri della classe
    virtual void setName(const string&);
    virtual void setItemLevel(const U_SHORT&);
    virtual void setDescription(const string&);
    virtual void setDuration(const U_SHORT&);
    virtual void setWeight(const double&);

    //getter propri della classe
    virtual string getName() const;
    virtual U_SHORT getItemLevel() const;
    virtual string getDescription() const;
    virtual U_SHORT getDuration() const;
    virtual double getWeight() const;

private:
    string name;
    U_SHORT itemLevel;
    string description;
    U_SHORT duration;
    double weight;
};

#endif // INVENTORYITEM_H
