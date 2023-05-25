#pragma once
#include"CamisAbstr.h"
class Camiseta :public CamisAbstr
{
public:
    Camiseta(double, std::string, std::string, bool);
    virtual ~Camiseta();
private:
    bool cuelloV;
};
