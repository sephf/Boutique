#pragma once
#include"TrajeAbstracto.h"

class Nodo
{
public:
    Nodo(TrajeAbstracto*, Nodo*);
    virtual ~Nodo();
    TrajeAbstracto* getTraje();
    Nodo* getSiguiente();
    void setTraje(TrajeAbstracto*);
    void setSiguiente(Nodo*);
private:
    TrajeAbstracto* traje;
    Nodo* siguiente;
};