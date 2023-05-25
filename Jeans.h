#pragma once
#include"PantalonAbstr.h"
class Jeans :public PantalonAbstr
{
public:
    Jeans(double, std::string, std::string, bool);
    virtual ~Jeans();
private:
    bool ajustado;
};
