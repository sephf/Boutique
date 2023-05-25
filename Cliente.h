#pragma once
#include"Observa.h"
class Cliente :public Observa
{
public:
    Cliente(std::string, std::string, std::string, double, std::string, std::string);
    virtual ~Cliente();
    virtual void actualizar(TrajeAbstracto*)const override;
    virtual std::string toString()const;
    virtual std::string getCedula()const;
    virtual std::string getPais()const;
    virtual std::string getCiudad()const;
    virtual void escribirCliente(std::ofstream*) = 0;
protected:
    std::string nombre;
    std::string cedula;
    std::string corrElec;
    double pagoSuscrip;
    std::string ciudad;
    std::string pais;
};
