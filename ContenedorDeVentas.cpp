#include "ContenedorDeVentas.h"

ContenedorDeVentas::ContenedorDeVentas()
{
}

ContenedorDeVentas::~ContenedorDeVentas()
{
    if (!cola.empty())
    {
        cola.clear();
    }
}
void ContenedorDeVentas::agregaVenta(Venta* v)
{
    cola.push_back(v);
}
double ContenedorDeVentas::totalVentas()
{
    double sum = 0.0;
    for (size_t i = 0; i < cola.size(); i++)
    {
        sum += cola[i]->getValorTraje();
    }
    return sum;
}
void ContenedorDeVentas::leerVentas()
{
    std::ifstream file("ventas.bin", std::ios::binary);
    if (file.good())
    {
        while (!file.eof()) {
            Venta* v = nullptr;
            file.read((char*)v, sizeof(Venta));
            agregaVenta(v);
        }
    }
    file.close();
}
void ContenedorDeVentas::salvarVentas()
{
    std::ofstream file("ventas.bin", std::ios::binary);
    for (size_t i = 0; i < cola.size(); i++)
    {
        file.write((char*)cola[i], sizeof(Venta));
    }
    file.close();
}
