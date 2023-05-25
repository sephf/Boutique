#pragma once
#include"CamisAbstr.h"
class ConCuadros :public CamisAbstr
{
    bool grandes;
public:
    ConCuadros(double, std::string, std::string, bool);
    virtual ~ConCuadros();
};
