#include "Fecha.h"

Fecha::Fecha(int dd, int mm, int aa) :dia(dd), mes(mm), annio(aa)
{
}

Fecha::~Fecha()
{
}
std::string Fecha::toString()const
{
    std::stringstream s;
    s << "Fecha: " << dia << "/" << mes << "/" << annio;
    return s.str();
}
Fecha* Fecha::creaFecha()
{
    int dia = Servicio::ingresoDato("Fecha actual\n(dd): ", 1, 32);
    int mes = Servicio::ingresoDato("(mm): ", 1, 12);
    int anio = Servicio::ingresoDato("(aaaa): ", 1, 9999);
    return new Fecha(dia, mes, anio);
}
