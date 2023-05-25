#pragma once
#include"ZapatoAbstr.h"
class Bota :public ZapatoAbstr
{
public:
    Bota(double, std::string, std::string, bool);
    virtual ~Bota();
private:
    bool alta;
};
