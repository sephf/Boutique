#include "PantalonAbstr.h"

PantalonAbstr::PantalonAbstr(double pre, std::string colo, std::string cod) :precio(pre), color(colo), codigo(cod)
{
}

PantalonAbstr::~PantalonAbstr()
{
}
double PantalonAbstr::getPrecio()
{
    return precio;
}
