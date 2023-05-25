#pragma once
#include"PantalonAbstr.h"
class Pantaloneta :public PantalonAbstr
{
public:
    Pantaloneta(double, std::string, std::string, bool);
    virtual ~Pantaloneta();
private:
    bool estampada;
};