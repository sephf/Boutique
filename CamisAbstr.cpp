#include "CamisAbstr.h"

CamisAbstr::CamisAbstr(double pre, std::string colo, std::string cod) :precio(pre), color(colo), codigo(cod)
{
}

CamisAbstr::~CamisAbstr()
{
}
double CamisAbstr::getPrecio()
{
    return this->precio;
}
