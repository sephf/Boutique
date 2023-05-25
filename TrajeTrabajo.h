#pragma once
#include"TrajeAbstracto.h"
#include"ConCuadros.h"
#include"Jeans.h"
#include"Bota.h"
class TrajeTrabajo :public TrajeAbstracto
{
public:
    TrajeTrabajo();
    TrajeTrabajo(double, std::string, std::string);
    virtual ~TrajeTrabajo();
    CamisAbstr* creaCamisa()override;
    PantalonAbstr* creaPantalon()override;
    ZapatoAbstr* creaCalzado()override;
};
