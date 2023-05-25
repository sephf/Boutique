#pragma once
#include"TrajeAbstracto.h"
#include"Camiseta.h"
#include"Pantaloneta.h"
#include"Tenni.h"
class TrajeDeportivo :public TrajeAbstracto
{
public:
    TrajeDeportivo();
    TrajeDeportivo(double, std::string, std::string);
    virtual ~TrajeDeportivo();
    CamisAbstr* creaCamisa()override;
    PantalonAbstr* creaPantalon()override;
    ZapatoAbstr* creaCalzado()override;
};
