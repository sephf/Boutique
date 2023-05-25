#pragma once
#include"Vista.h"
class Control
{
public:
    Control();
    virtual ~Control();
    void menuPrincipal();
    void ventaDirecta();
    void ventaEnLinea();
    void mantenimiento();
private:
    TiendaEnCostaRica* tienda;
};
