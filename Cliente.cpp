#include "Cliente.h"

Cliente::Cliente(std::string nombr, std::string cedul, std::string corr, double pagoSuscri, std::string ciuda, std::string pai)
{
    this->nombre = nombr;
    this->cedula = cedul;
    this->corrElec = corr;
    this->pagoSuscrip = pagoSuscri;
    this->ciudad = ciuda;
    this->pais = pai;
}

Cliente::~Cliente()
{
}
void Cliente::actualizar(TrajeAbstracto* traje)const
{
    std::cout << "Cedula cliente: " << cedula << ", Codigo del traje: " << traje->getCodigo() << " tipo: " << traje->getTipo();
}
std::string Cliente::toString()const
{
    std::stringstream s;
    s << "Nombre: " << nombre
    << "\nCedula: " << cedula
    << "\nCorreo electronico: " << corrElec;
    return s.str();
}
std::string Cliente::getCedula()const
{
    return cedula;
}
std::string Cliente::getPais()const
{
    return pais;
}
std::string Cliente::getCiudad()const
{
    return ciudad;
}
