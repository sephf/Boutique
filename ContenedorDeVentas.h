#pragma once
#include<deque>
#include<iterator>
#include<algorithm>
#include<fstream>
#include"Venta.h"
class ContenedorDeVentas
{
public:
    ContenedorDeVentas();
    virtual ~ContenedorDeVentas();
    void agregaVenta(Venta*);
    double totalVentas();
    void leerVentas();
    void salvarVentas();
private:
    std::deque<Venta*> cola;
};
