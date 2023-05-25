#pragma once
#include"ZapatoAbstr.h"

class Ejecutivo :public ZapatoAbstr
{
public:
    Ejecutivo(double, std::string, std::string, bool);
    virtual ~Ejecutivo();
private:
    bool fino;
};
