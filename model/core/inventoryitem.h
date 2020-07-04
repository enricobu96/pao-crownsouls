#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H


#include<string>
using std::string;

//just some macros
#define U_INT unsigned int

class InventoryItem {
public:

    InventoryItem(string ="Nome non definito", U_INT =0, string ="Descrizione non definita");
    virtual ~InventoryItem() =default;
    virtual InventoryItem* clone() const =0;

    //SETTER
    virtual void setName(const string&);
    virtual void setItemLevel(const U_INT&);
    virtual void setDescription(const string&);

    //GETTER
    virtual string getName() const;
    virtual U_INT getItemLevel() const;
    virtual string getDescription() const;

    //METODI
    virtual string getType() const =0;

private:
    string name;
    U_INT itemLevel;
    string description;
};

#endif // INVENTORYITEM_H
