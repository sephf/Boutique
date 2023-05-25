#pragma once
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<sstream>
#include <conio.h>
#include <clocale>
#include<cstring>
#include<random>
class Servicio
{
public:
    static double calculaPrecioFinal(double);
    static double calculoIVA(double);
    static std::string generaCodigo();
    static double precioConCuadros(char, bool);
    static double precioCamiseta(char, bool);
    static double precioMangaLarga(char, bool);
    static double precioJeams(char, bool);
    static double precioPantaloneta(char, bool);
    static double precioDeVestir(char, bool);
    static double precioBota(char, bool);
    static double precioTenni(char, bool);
    static double precioEjecutivo(char, bool);
    static int codigoTraslado(std::string, std::string);
    static double precioTraslado(int);
    template <typename T>
    static T ingresoDato(std::string solicitud, T minimo, T maximo)
    {
        T dato;
        bool finalizado = false;
        while (!finalizado) {
            try {
                std::cout << solicitud;
                if (std::cin >> dato)
                {
                    if (dato >= minimo && dato <= maximo) { finalizado = true; }
                    else { throw dato; }
                }
                else { throw dato; }
            }
            catch (...)
            {
                std::cout << " -Ocurrio una excepcion!\n";
            }
            if (!finalizado) {
                std::cin.clear();
                std::cin.ignore(255, '\n');
            }
        }
        return dato;
    }
};
