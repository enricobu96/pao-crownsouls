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
    InventoryItem(string ="Nome non definito", U_SHORT =0, string ="Descrizione non definita");

    //copia profonda
    virtual InventoryItem* clone() const =0;

    //setter propri della classe
    virtual void setName(const string&);
    virtual void setItemLevel(const U_SHORT&);
    virtual void setDescription(const string&);

    //getter propri della classe
    virtual string getName() const;
    virtual U_SHORT getItemLevel() const;
    virtual string getDescription() const;

private:
    string name;
    U_SHORT itemLevel;
    string description;
};

#endif // INVENTORYITEM_H
