#pragma once
#include"Cliente.h"

class Empresa :public Cliente
{
public:
    Empresa(std::string, std::string, std::string, double, std::string, std::string, bool);
    virtual ~Empresa();
    void actualizar(TrajeAbstracto*)const;
    void escribirCliente(std::ofstream*)override;
    static Cliente* leerEmpresa(std::ifstream*);
private:
    bool clienteFrecuente;
};
