#include "Nodo.h"
Nodo::Nodo(TrajeAbstracto* t, Nodo* s) :traje(t), siguiente(s)
{
}

Nodo::~Nodo()
{
    if (traje)
    {
        delete traje;
    }
}
TrajeAbstracto* Nodo::getTraje()
{
    return traje;
}
Nodo* Nodo::getSiguiente()
{
    return siguiente;
}
void Nodo::setTraje(TrajeAbstracto* t)
{
    traje = t;
}
void Nodo::setSiguiente(Nodo* s)
{
    siguiente = s;
}
