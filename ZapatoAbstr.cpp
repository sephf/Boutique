#include "ZapatoAbstr.h"

ZapatoAbstr::ZapatoAbstr(double pre, std::string colo, std::string cod) :precio(pre), color(colo), codigo(cod)
{
}

ZapatoAbstr::~ZapatoAbstr()
{
}
double ZapatoAbstr::getPrecio()
{
    return precio;
}
