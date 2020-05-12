#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H

#include<string>
using std::string;

class InventoryItem
{
public:
    InventoryItem(string ="Nome non definito", unsigned short =0, string ="Descrizione non definita", unsigned short =0, double =0.0);

    //setter propri della classe
    virtual void setName(const string&);
    virtual void setItemLevel(const unsigned short&);
    virtual void setDescription(const string&);
    virtual void setDuration(const unsigned short&);
    virtual void setWeight(const double&);

    //getter propri della classe
    virtual string getName() const;
    virtual unsigned short getItemLevel() const;
    virtual string getDescription() const;
    virtual unsigned short getDuration() const;
    virtual double getWeight() const;

private:
    string name;
    unsigned short itemLevel;
    string description;
    unsigned short duration;
    double weight;
};

#endif // INVENTORYITEM_H
