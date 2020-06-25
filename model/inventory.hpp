#ifndef INVENTORY_H
#define INVENTORY_H
#include "core/inventoryitem.h"
#include<iostream>
using namespace std;
/*
 * A FUTURA MEMORIA:
 * Classe container, corrispondente all'inventario composto da più InventoryItem.
 * La classe è templatizzata, ergo, può essere utilizzata anche in altri contesti; nel caso del nostro programma,
 * il tipo T del template corrisponde a un puntatore a InventoryItem.
 * Su InventoryItem* si può poi applicare il polimorfismo per l'utilizzo opportuno della gerarchia.
 * La classe contiene una classe annidata SmartP, ossia un puntatore smart, e implementa nella pratica una lista
 * singolarmente puntata con l'aggiunta del nodo last, non necessario ma utile per diminuire la complessità
 * computazionale di alcune operazioni, tra cui il push in coda di un nuovo smartp.
 */

template<class T>
class Inventory
{
public:
    //COSTRUTTORI INVENTORY
    //Inventory();
    Inventory();
    Inventory(const Inventory&);
    ~Inventory();

    //FUNZIONALITÀ BASE
    bool isEmpty() const;
    void pushFront(const T&);
    void pushBack(const T&);
    void popFront();
    void popBack();
    T getFront() const;
    T getBack() const;
    U_INT getSize() const;

    //OVERLOADING DEGLI OPERATORI



    //ITERATORE

private:
    //CLASSE INTERNA SMART POINTER
    class SmartP {
    public:
        //COSTRUTTORI SMARTP
        SmartP(const T& t, SmartP* n =nullptr) : item(t), next(n) {};
        SmartP(const SmartP& s) : item(s.item != nullptr ? (s.item)->clone() : nullptr) {};
        ~SmartP() {
            cout << "cancellazione?" << endl;
            if(next) delete next;
        };

        //RIDEFINIZIONE OPERATORI SMARTP
        SmartP& operator=(const SmartP& s) {
            if(this != &s) {
                if(item) delete item;
                item = s.item!=nullptr ? (s.item)->clone() : nullptr;
            }
            return *this;
        }

        T* operator->() const { return item; }
        T& operator*() const { return *item; }

        //CAMPI DATI SMARTP
        T item;
        SmartP* next;
    };

    //CAMPI DATI INVENTORY
    SmartP* first;
    SmartP* last; //last per O(1) per il push_back
    U_INT size;

    //METODI DI UTILITÀ PRIVATI
    SmartP* cloneList(SmartP*);
};

//METODO cloneList
template<class T>
typename Inventory<T>::SmartP* Inventory<T>::cloneList(Inventory<T>::SmartP* p) { //clonazione profonda di una lista
    if(!p)
        return nullptr;
    if(!p->next)
        return last = new SmartP(p->item);
    return new SmartP(p->item, cloneList(p->next));
}

//COSTRUTTORI CONTAINER
template<class T>
Inventory<T>::Inventory() : first(nullptr), last(nullptr), size(0) {}

template<class T>
Inventory<T>::Inventory(const Inventory & t) : first(cloneList(t.first)), size(t.size) {}

template<class T>
Inventory<T>::~Inventory() {
    if(first)
        delete first;
}

//FUNZIONALITÀ BASE
template<class T>
bool Inventory<T>::isEmpty() const {
    return size == 0;
}

template<class T>
void Inventory<T>::pushFront(const T& t) {
    if(this->isEmpty()) {
        first = new SmartP(t);
        last = first;
    }
    else
        first = new SmartP(t, first);
    ++size;
}

template<class T>
void Inventory<T>::pushBack(const T& t) {
    if(this->isEmpty()) {
        first = new SmartP(t);
        last = first;
    }
    else {
        last->next = new SmartP(t);
        last = last->next;
    }
    ++size;
}

template<class T>
void Inventory<T>::popFront() {
    if(!this->isEmpty()) {
        if(first == last) {
            delete first;
            first = nullptr;
            last = nullptr;
        } else {
            SmartP* t = first;
            first = t->next;
            t->next = nullptr;
            delete t;
        }
        --size;
    }
}

template<class T>
void Inventory<T>::popBack() {
    if(!(this->isEmpty())) {
        if(first == last) {
            delete first;
            first = nullptr;
            last = nullptr;
        } else {  //OCCHIO A QUESTA CHE POTREBBE ESSERE SBAGLIATA
            SmartP* t = first;
            while(first->next != last)
                first = first->next;
            delete first->next;
            first->next = nullptr;
            last = first;
            first = t;
        }
        --size;
    }
}

template<class T>
T Inventory<T>::getFront() const {
    if(first) {
        return first->item;
    }
}

template<class T>
T Inventory<T>::getBack() const {
    if(last) {
        return last->item;
    }
}

template<class T>
unsigned int Inventory<T>::getSize() const
{
    return size;
}

#endif // INVENTORY_H
