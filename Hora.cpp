#include "Hora.h"

Hora::Hora(int hh, int mm, int ss) :hora(hh), minutos(mm), segundos(ss)
{
}

Hora::~Hora()
{
}
std::string Hora::toString()const
{
    std::stringstream s;
    s << "Hora: " << hora << "/" << minutos << "/" << segundos;
    return s.str();
}
Hora* Hora::creaHora()
{
    int hora = Servicio::ingresoDato("Hora actual\n(HH): ", 0, 23);
    int minuto = Servicio::ingresoDato("(MM): ", 0, 59);
    int segundo = Servicio::ingresoDato("(SS): ", 0, 59);
    return new Hora(hora, minuto, segundo);
}
