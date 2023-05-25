#pragma once
#include"Hora.h"
#include"Fecha.h"
#include"Cliente.h"
class Venta
{
public:
    Venta(Hora*, Fecha*, double);
    virtual ~Venta();
    double getValorTraje();
    std::string toString(Cliente*, TrajeAbstracto*);
private:
    Hora* hora;
    Fecha* fecha;
    double valorTraje;
};
