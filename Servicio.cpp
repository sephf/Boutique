#include "Servicio.h"
double Servicio::calculaPrecioFinal(double precioBase)
{
    return (precioBase * 80 / 100) + precioBase;
}
double Servicio::calculoIVA(double valor)
{
    return valor * 15 / 100;
}
std::string Servicio::generaCodigo()
{
    std::string codigo;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(33, 126);
    for (int i = 0; i < 6; ++i) {
        int ascii = dist(gen);
        codigo += static_cast<char>(ascii);
    }
    return codigo;
}
double Servicio::precioConCuadros(char medida, bool grandes)
{
    if (grandes)
    {
        switch (medida)
        {
        case 'a': return 300.00; break;
        case 'b': return 250.00; break;
        case 'c': return 175.00; break;
        case 'd': return 150.00; break;
        }
    }
    else
    {
        switch (medida)
        {
        case 'a': return 250.00; break;
        case 'b': return 200.00; break;
        case 'c': return 155.00; break;
        case 'd': return 100.00; break;
        }
    }
    return 0.0;
}
double Servicio::precioCamiseta(char medida, bool cuelloV)
{
    if (cuelloV)
    {
        switch (medida)
        {
        case 'a': return 200.00; break;
        case 'b': return 150.00; break;
        case 'c': return 125.00; break;
        case 'd': return 75.00; break;
        }
    }
    else
    {
        switch (medida)
        {
        case 'a': return 150.00; break;
        case 'b': return 100.00; break;
        case 'c': return 75.00; break;
        case 'd': return 50.00; break;
        }
    }
    return 0.0;
}
double Servicio::precioMangaLarga(char medida, bool lisa)
{
    if (lisa)
    {
        switch (medida)
        {
        case 'a': return 375.00; break;
        case 'b': return 315.00; break;
        case 'c': return 175.00; break;
        case 'd': return 165.00; break;
        }
    }
    else
    {
        switch (medida)
        {
        case 'a': return 325.00; break;
        case 'b': return 280.00; break;
        case 'c': return 150.00; break;
        case 'd': return 125.00; break;
        }
    }
    return 0.0;
}
double Servicio::precioJeams(char medida, bool ajustado)
{
    if (ajustado)
    {
        switch (medida)
        {
        case 'a': return 200.00; break;
        case 'b': return 150.00; break;
        case 'c': return 75.00; break;
        case 'd': return 90.00; break;
        }
    }
    else
    {
        switch (medida)
        {
        case 'a': return 150.00; break;
        case 'b': return 100.00; break;
        case 'c': return 50.00; break;
        case 'd': return 25.00; break;
        }
    }
    return 0.0;
}
double Servicio::precioPantaloneta(char medida, bool estampado)
{
    if (estampado)
    {
        switch (medida)
        {
        case 'a': return 150.00; break;
        case 'b': return 130.00; break;
        case 'c': return 80.00; break;
        case 'd': return 75.00; break;
        }
    }
    else
    {
        switch (medida)
        {
        case 'a': return 110.00; break;
        case 'b': return 85.00; break;
        case 'c': return 50.00; break;
        case 'd': return 45.00; break;
        }
    }
    return 0.0;
}
double Servicio::precioDeVestir(char medida, bool casimir)
{
    if (casimir)
    {
        switch (medida)
        {
        case 'a': return 500.00; break;
        case 'b': return 450.00; break;
        case 'c': return 260.00; break;
        case 'd': return 200.00; break;
        }
    }
    else
    {
        switch (medida)
        {
        case 'a': return 300.00; break;
        case 'b': return 250.00; break;
        case 'c': return 125.00; break;
        case 'd': return 100.00; break;
        }
    }
    return 0.0;
}
double Servicio::precioBota(char medida, bool altas)
{
    if (altas)
    {
        switch (medida)
        {
        case 'a': return 250.00; break;
        case 'b': return 225.00; break;
        case 'c': return 175.00; break;
        case 'd': return 90.00; break;
        }
    }
    else
    {
        switch (medida)
        {
        case 'a': return 220.00; break;
        case 'b': return 200.00; break;
        case 'c': return 150.00; break;
        case 'd': return 75.00; break;
        }
    }
    return 0.0;
}
double Servicio::precioTenni(char medida, bool adidas)
{
    if (adidas)
    {
        switch (medida)
        {
        case 'a': return 335.00; break;
        case 'b': return 300.00; break;
        case 'c': return 200.00; break;
        case 'd': return 150.00; break;
        }
    }
    else
    {
        switch (medida)
        {
        case 'a': return 225.00; break;
        case 'b': return 200.00; break;
        case 'c': return 150.00; break;
        case 'd': return 75.00; break;
        }
    }
    return 0.0;
}
double Servicio::precioEjecutivo(char medida, bool fino)
{
    if (fino)
    {
        switch (medida)
        {
        case 'a': return 450.00; break;
        case 'b': return 400.00; break;
        case 'c': return 325.00; break;
        case 'd': return 200.00; break;
        }
    }
    else
    {
        switch (medida)
        {
        case 'a': return 400.00; break;
        case 'b': return 350.00; break;
        case 'c': return 250.00; break;
        case 'd': return 175.00; break;
        }
    }
    return 0.0;
}
int Servicio::codigoTraslado(std::string pais, std::string ciudad)
{
    for (long long unsigned int i = 0; i < pais.length(); i++)
    {
        pais[i] = toupper(pais[i]);
    }
    for (long long unsigned int i = 0; i < ciudad.size(); i++)
    {
        ciudad[i] = toupper(ciudad[i]);
    }
    if (pais == "EE-UU")
    {
        if (ciudad == "NEW YORK")
        {
            return 1;
        }
        else
        {
            return 8;
        }
    }
    if (pais == "FRANCIA")
    {
        return 2;
    }
    if (pais == "ITALIA")
    {
        return 3;
    }
    if (pais == "BRASILIA")
    {
        return 4;
    }
    if (pais == "ARGENTINA")
    {
        return 5;
    }
    if (pais == "CANADA")
    {
        return 6;
    }
    if (pais == "INGLATERRA")
    {
        return 7;
    }
    else return 9;
}
double Servicio::precioTraslado(int codigo)
{
    switch (codigo)
    {
    case 1: return 100.00; break;
    case 2: return 200.00; break;
    case 3: return 250.00; break;
    case 4:return 150.00; break;
    case 5:return 175.00; break;
    case 6:return 160.00; break;
    case 7:return 200.00; break;
    case 8:return 150.00; break;
    case 9: return 50.00; break;
    default: return 0.0; break;
    }
}
