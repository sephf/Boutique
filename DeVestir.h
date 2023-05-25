#pragma once
#include<iostream>
#include"PantalonAbstr.h"
class DeVestir :public PantalonAbstr
{
public:
    DeVestir(double, std::string, std::string, bool);
    virtual ~DeVestir();
private:
    bool casimir;
};

