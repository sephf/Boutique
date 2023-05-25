#include "TrajeDeportivo.h"

TrajeDeportivo::TrajeDeportivo(double pre, std::string tip, std::string cod) :TrajeAbstracto(pre, cod, cod)
{
}
TrajeDeportivo::TrajeDeportivo() :TrajeAbstracto()
{
}
TrajeDeportivo::~TrajeDeportivo()
{
}
CamisAbstr* TrajeDeportivo::creaCamisa()
{
    std::cout << "a-Grande\n"<<"b-mediano\n"<<"c-pequenio\n"<<"d-ninio\n";
    char medida = Servicio::ingresoDato("Seleccione la medida de la camisa: ", 'a', 'd');
    bool cuelloV = Servicio::ingresoDato("La camiseta tiene cuello V (1:si , 0:no)?: ", 0, 1);
    std::cin.clear();
    std::cin.ignore(255, '\n');
    std::string color;
    std::cout << "Ingrese el color: ";
    std::getline(std::cin, color);
    double precio = Servicio::precioCamiseta(medida, cuelloV);
    std::string codigo1 = Servicio::generaCodigo();
    return new Camiseta(precio, color, codigo1, cuelloV);
}
PantalonAbstr* TrajeDeportivo::creaPantalon()
{
    std::cout << "a-Grande\n"<<"b-mediano\n"<<"c-pequenio\n"<<"d-ninio\n";
    char medida = Servicio::ingresoDato("Seleccione la medida del pantalon: ", 'a', 'd');
    bool estampado = Servicio::ingresoDato("La pantaloneta tiene estampado (1:si , 0:no)?: ", 0, 1);
    std::cin.clear();
    std::cin.ignore(255, '\n');
    std::string color;
    std::cout << "Ingrese el color: ";
    std::getline(std::cin, color);
    std::string codigo1 = Servicio::generaCodigo();
    double precio = Servicio::precioPantaloneta(medida, estampado);
    return new Pantaloneta(precio, color, codigo1, estampado);
}
ZapatoAbstr* TrajeDeportivo::creaCalzado()
{
    std::cout << "a-Grande\n"<<"b-mediano\n"<<"c-pequenio\n"<<"d-ninio\n";
    char medida = Servicio::ingresoDato("Seleccione la medida del calzado: ", 'a', 'd');
    bool adidas = Servicio::ingresoDato("El tenni es Adidas (1:si , 0:no)?: ", 0, 1);
    std::cin.clear();
    std::cin.ignore(255, '\n');
    std::string color;
    std::cout << "Ingrese el color: ";
    std::getline(std::cin, color);
    std::string codigo1 = Servicio::generaCodigo();
    double precio = Servicio::precioTenni(medida, adidas);
    return new Tenni(precio, color, codigo1, adidas);
}
