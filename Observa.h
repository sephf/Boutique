#pragma once
#include<iostream>
#include"TrajeAbstracto.h"
class Observa
{
public:
    Observa();
    virtual ~Observa();
    virtual void actualizar(TrajeAbstracto*)const = 0;
};
