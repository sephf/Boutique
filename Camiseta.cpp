#include "Camiseta.h"

Camiseta::Camiseta(double pre, std::string colo, std::string cod, bool cv) :cuelloV(cv), CamisAbstr(pre, colo, cod)
{
}

Camiseta::~Camiseta()
{
}
