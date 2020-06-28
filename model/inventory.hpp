#ifndef INVENTORY_H
#define INVENTORY_H
#include "core/inventoryitem.h"
#include<iostream>
using namespace std;

/*
 * A FUTURA MEMORIA:
 * Classe container, corrispondente all'inventario composto da più InventoryItem.
 * La classe è templatizzata, ergo può essere utilizzata anche in altri contesti; nel caso del nostro programma,
 * il tipo T del template corrisponde a un puntatore a InventoryItem.
 * Su InventoryItem* si può poi applicare il polimorfismo per l'utilizzo opportuno della gerarchia.
 * La classe contiene una classe annidata SmartP, ossia un puntatore smart, e implementa nella pratica una lista
 * singolarmente puntata con l'aggiunta del nodo last, non necessario ma utile per diminuire la complessità
 * computazionale di alcune operazioni, tra cui il push in coda di un nuovo smartp.
 */

template<class T>
class Inventory
{
    friend class Iterator;
private:

    //CLASSE INTERNA SMART POINTER
    class SmartP {
    public:
        //COSTRUTTORI SMARTP
        SmartP(const T&, SmartP* =nullptr);
        SmartP(const SmartP&);
        ~SmartP();

        //RIDEFINIZIONE OPERATORI SMARTP
        SmartP& operator=(const SmartP&);
        T* operator->() const;
        T& operator*() const;
        bool operator== (const SmartP&) const;
        bool operator!= (const SmartP&) const;

        //CAMPI DATI SMARTP
        T item;
        SmartP* next;
    };

    //CAMPI DATI INVENTORY
    SmartP* first;
    SmartP* last;
    U_INT size;

    //METODI DI UTILITÀ PRIVATI
    SmartP* cloneList(SmartP*);
    bool isSame(SmartP*, SmartP*) const;

public:

    //COSTRUTTORI INVENTORY
    Inventory();
    Inventory(const Inventory&);
    ~Inventory();

    //OVERLOADING DEGLI OPERATORI
    bool operator== (const Inventory&) const;
    bool operator!= (const Inventory&) const;
    Inventory<T> operator= (const Inventory&);
    T& operator[] (U_INT) const; //DA SISTEMARE

    //FUNZIONALITÀ BASE
    bool isEmpty() const;
    void pushFront(const T&);
    void pushBack(const T&);
    void popFront();
    void popBack();
    void popAtPosition(U_INT);
    T getFront() const;
    T getBack() const;
    U_INT getSize() const;

    //ITERATORE
    class Iterator{
        friend class Inventory<T>;
    private:
        const typename Inventory<T>::SmartP* p;
        bool isFinished;
    public:

        //COSTRUTTORI
        Iterator(Inventory<T>::SmartP* =nullptr, bool =true);
        ~Iterator() =default;

        //RIDEFINIZIONE OPERATORI ITERATOR
        Iterator& operator++();
        const T& operator* () const;
        const T* operator-> () const;
        bool operator== (const Iterator&) const;
        bool operator!= (const Iterator&) const;

        //METODI
        bool hasFinished() const;

    };

    //METODI PER ITERATORE
    Iterator begin() const;
    Iterator end() const;
};


/**************************
 * DEFINIZIONE DEI METODI *
 **************************/


//METODI E OVERLOADING OPERATORI CLASSE INTERNA SmartP
template<class T>
Inventory<T>::SmartP::SmartP(const T & i, SmartP * n) : item(i), next(n) {}

template<class T>
Inventory<T>::SmartP::SmartP(const Inventory::SmartP &s) : item(s.item != nullptr ? (s.item)->clone() : nullptr) {}

template<class T>
Inventory<T>::SmartP::~SmartP() {
    if(next) delete next;
}

template<class T>
typename Inventory<T>::SmartP &Inventory<T>::SmartP::operator=(const Inventory::SmartP &s) {
    if(this != &s) {
        if(item) delete item;
        item = s.item!=nullptr ? (s.item)->clone() : nullptr;
    }
    return *this;
}

template<class T>
T *Inventory<T>::SmartP::operator->() const { return item; }

template<class T>
T &Inventory<T>::SmartP::operator*() const { return *item; }

template<class T>
bool Inventory<T>::SmartP::operator==(const SmartP & s) const {
    return (this->item==s.item && this->next == s.next);
}

template<class T>
bool Inventory<T>::SmartP::operator!=(const SmartP & s) const {
    return !(*this==s);
}


//METODI D'UTILITÀ PRIVATI
template<class T>
typename Inventory<T>::SmartP* Inventory<T>::cloneList(Inventory<T>::SmartP* p) {
    if(!p)
        return nullptr;
    if(!p->next)
        return last = new SmartP(p->item);
    return new SmartP(p->item, cloneList(p->next));
}

template<class T>
bool Inventory<T>::isSame(SmartP* a, SmartP* b) const {
    if(!a && !b) return true;
    if(a->item != b->item) return false;
    return isSame(a->next, b->next);
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
        } else {
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
void Inventory<T>::popAtPosition(unsigned int i) {
    if(!this->isEmpty()) {
        if(i == 0) return popFront();
        if(first == last) {
            delete first;
            first = nullptr;
            last = nullptr;
        } else if(size<=i+1) {
            popBack();
        } else {
            SmartP* t = first;
            while(first && i>1) {
                first = first->next;
                --i;
            }
            SmartP* tt = first->next;
            if(first->next->next) first->next = first->next->next;
            else first->next = nullptr;
            if(tt->next) tt->next = nullptr;
            if(tt) delete tt;
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
    return nullptr;
}

template<class T>
T Inventory<T>::getBack() const {
    if(last) {
        return last->item;
    }
    return nullptr;
}

template<class T>
unsigned int Inventory<T>::getSize() const {
    return size;
}


//RIDEFINIZIONE DEGLI OPERATORI DI INVENTORY
template<class T>
bool Inventory<T>::operator==(const Inventory& s) const {
    if(size != s.size) return false;
    return isSame(first, s.first);
}

template<class T>
bool Inventory<T>::operator!=(const Inventory & s) const {
    return !(*this==s);
}

template<class T>
Inventory<T> Inventory<T>::operator=(const Inventory & s) {
    if(this != &s) {
        if(first)
            delete first;
        first = cloneList(s.first);
        size = s.size;
    }
    return *this;
}

template<class T>
T& Inventory<T>::operator[](unsigned int i) const { //potrebbe non funzionare, occhio!
    SmartP* t = first;
    while(i-- && t != nullptr)
        t=t->next;
    return t->item;
}

//COSTRUTTORI ITERATOR
template<class T>
Inventory<T>::Iterator::Iterator(Inventory<T>::SmartP* _p, bool status) : p(_p), isFinished(status) {}

template<class T>
typename Inventory<T>::Iterator& Inventory<T>::Iterator::operator++() {
    if(!isFinished) {
        if(p->next == nullptr)
            isFinished = true;
        else
            p = p->next;
    } return *this;
}

//RIDEFINIZIONE OPERATORI ITERATOR
template<class T>
const T& Inventory<T>::Iterator::operator*() const {
    return p->item;
}

template<class T>
const T* Inventory<T>::Iterator::operator->() const {
    return &(p->item);
}

template<class T>
bool Inventory<T>::Iterator::operator== (const Iterator& s) const {
    return p == s.p;
}

template<class T>
bool Inventory<T>::Iterator::operator!= (const Iterator& s) const {
    return (p != s.p);
}

//METODI ITERATOR
template<class T>
typename Inventory<T>::Iterator Inventory<T>::begin() const {
    return Iterator(first, false);
}

template<class T>
typename Inventory<T>::Iterator Inventory<T>::end() const {
    return Iterator(last, true);
}

template<class T>
bool Inventory<T>::Iterator::hasFinished() const {
    return isFinished;
}

#endif // INVENTORY_H
