#pragma once
#include<iostream>
#include"Cliente.h"
class Persona :public Cliente
{
public:
    Persona(std::string, std::string, std::string, double, std::string, std::string, std::string);
    virtual ~Persona();
    void actualizar(TrajeAbstracto*)const;
    void escribirCliente(std::ofstream*)override;
    static Cliente* leerPersona(std::ifstream*);
private:
    std::string nacionalidad;
};
