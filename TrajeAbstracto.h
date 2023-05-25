#pragma once
#include"ZapatoAbstr.h"
#include"PantalonAbstr.h"
#include"CamisAbstr.h"
#include"Servicio.h"
#include<fstream>
class TrajeAbstracto
{
public:
    TrajeAbstracto();
    TrajeAbstracto(double, std::string, std::string);
    virtual ~TrajeAbstracto();
    virtual CamisAbstr* creaCamisa();
    virtual PantalonAbstr* creaPantalon();
    virtual ZapatoAbstr* creaCalzado();
    virtual std::string getCodigo()const;
    virtual std::string getTipo()const;
    virtual std::string toString()const;
    virtual double getPrecio()const;
    virtual void setvecesComprado();
    virtual unsigned int getVecesComprado();
    virtual void escribirTraje(std::ofstream*);
    static TrajeAbstracto* leerTraje(std::ifstream* f);
private:
    double precio;
    std::string tipo;
    std::string codigo;
    unsigned int vecesComprado;
};

