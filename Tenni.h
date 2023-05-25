#pragma once
#include"ZapatoAbstr.h"
class Tenni :public ZapatoAbstr
{
public:
    Tenni(double, std::string, std::string, bool);
    virtual ~Tenni();
private:
    bool adidas;
};
