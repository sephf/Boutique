#pragma once
#include<sstream>
#include"Servicio.h"
class Hora
{
public:
    Hora(int, int, int);
    virtual ~Hora();
    std::string toString()const;
    static Hora* creaHora();
private:
    int hora;
    int minutos;
    int segundos;
};
