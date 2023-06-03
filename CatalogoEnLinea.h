#pragma once
#include"Nodo.h"
#include"Subject.h"
#define archivo2 "catalogo.bin"
class CatalogoEnLinea :public Subject
{
public:
    CatalogoEnLinea();
    virtual ~CatalogoEnLinea();
    void notificar(TrajeAbstracto*, std::string);
    bool ingresaTraje(TrajeAbstracto*);
    bool eliminaTraje(std::string);
    TrajeAbstracto* getTraje(std::string);
    TrajeAbstracto* trajeMasComprado();
    std::string toString();
    void guardarATodos();
    void recuperarATodos();

private:
    Nodo* ppio;
};
