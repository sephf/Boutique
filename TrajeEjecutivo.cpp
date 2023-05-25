#include "TrajeEjecutivo.h"

TrajeEjecutivo::TrajeEjecutivo(double pre, std::string tip, std::string cod) :TrajeAbstracto(pre, tip, cod)
{
}
TrajeEjecutivo::TrajeEjecutivo() :TrajeAbstracto()
{
}
TrajeEjecutivo::~TrajeEjecutivo()
{
}
CamisAbstr* TrajeEjecutivo::creaCamisa()
{
    std::cout << "a-Grande\n"<<"b-mediano\n"<<"c-pequenio\n"<<"d-ninio\n";
    char medida = Servicio::ingresoDato("Seleccione la medida de la camisa: ", 'a', 'd');
    bool lisa = Servicio::ingresoDato("La camisa manga larga es lisa (1:si , 0:no)?: ", 0, 1);
    std::cin.clear();
    std::cin.ignore(255, '\n');
    std::string color;
    std::cout << "Ingrese el color: ";
    std::getline(std::cin, color);
    std::string codigo1 = Servicio::generaCodigo();
    double precio = Servicio::precioMangaLarga(medida, lisa);
    return new MangaLarga(precio, color, codigo1, lisa);
}
PantalonAbstr* TrajeEjecutivo::creaPantalon()
{
    std::cout << "a-Grande\n"<<"b-mediano\n"<<"c-pequenio\n"<<"d-ninio\n";
    char medida = Servicio::ingresoDato("Seleccione la medida del pantalon: ", 'a', 'd');
    bool casimir = Servicio::ingresoDato("El pantalon es casimir (1:si , 0:no)?: ", 0, 1);
    std::cin.clear();
    std::cin.ignore(255, '\n');
    std::string color;
    std::cout << "Ingrese el color: ";
    std::getline(std::cin, color);
    std::string codigo1 = Servicio::generaCodigo();
    double precio = Servicio::precioDeVestir(medida, casimir);
    return new DeVestir(precio, color, codigo1, casimir);
}
ZapatoAbstr* TrajeEjecutivo::creaCalzado()
{
    std::cout << "a-Grande\n"<<"b-mediano\n"<<"c-pequenio\n"<<"d-ninio\n";
    char medida = Servicio::ingresoDato("Seleccione la medida del calzado: ", 'a', 'd');
    bool fino = Servicio::ingresoDato("El zapato es fino (1:si , 0:no)?: ", 0, 1);
    std::cin.clear();
    std::cin.ignore(255, '\n');
    std::string color;
    std::cout << "Ingrese el color: ";
    std::getline(std::cin, color);
    double precio = Servicio::precioEjecutivo(medida, fino);
    std::string codigo1 = Servicio::generaCodigo();
    return new Ejecutivo(precio, color, codigo1, fino);
}
