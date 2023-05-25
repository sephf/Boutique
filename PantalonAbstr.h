#pragma once
#include<iostream>

class PantalonAbstr
{
public:
    PantalonAbstr(double, std::string, std::string);
    virtual ~PantalonAbstr();
    virtual double getPrecio();
private:
    double precio;
    std::string color;
    std::string codigo;
};
