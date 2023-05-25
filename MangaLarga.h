#pragma once
#include"CamisAbstr.h"

class MangaLarga : public CamisAbstr
{
public:
    MangaLarga(double, std::string, std::string, bool);
    virtual ~MangaLarga();
private:
    bool lisa;
};

