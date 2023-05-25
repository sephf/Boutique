#include "Control.h"

Control::Control()
{
    tienda = new TiendaEnCostaRica();
    tienda->leerArchivos();
}

Control::~Control()
{
    tienda->salvarArchivos();
    tienda ? (delete tienda, nullptr) : nullptr;
}
void Control::menuPrincipal()
{
    int opcion = 0;
    while (opcion != 4)
    {
        opcion = Vista::interfazMenu0();
        system("cls");
        switch (opcion)
        {
        case 1: ventaDirecta(); break;
        case 2: ventaEnLinea(); break;
        case 3: mantenimiento(); break;
        default:break;
        }
        system("PAUSE");
        system("cls");
    }
    std::cout << "Gracias por usar el programa. :)";
}
void Control::ventaDirecta()
{
    tienda->imprimirTrajes();
    std::string codigo = Vista::solicitudCodigo();
    tienda->ejecutarVenta(nullptr, codigo);
}
void Control::ventaEnLinea()
{
    system("cls");
    int opcion2 = Vista::menuVentaEnLinea();
    switch (opcion2)
    {
    case 1:tienda->iniciaSesion();break;
    case 2: {
        char subOpcion1 = Vista::subMenuVentaEnLinea();
        (subOpcion1 == 'a') ? tienda->suscribirPersona(Vista::creaPersona()) : tienda->suscribirEmpresa(Vista::creaEmpresa());
    }; break;
    default: break;
    }
}
void Control::mantenimiento()
{
    int opcion3 = Vista::menuMantenimiento();
    system("cls");
    switch (opcion3)
    {
    case 1: {
        int subopcion = Vista::subMenuTraje();
        switch (subopcion)
        {
        case 1: tienda->ingresaTrajeEjecutivo();break;
        case 2:tienda->ingresaTrajeDeportivo();break;
        case 3:tienda->ingresaTrajeTrabajo();break;
        default: break;
        }
    }; break;
    case 2:std::cout << tienda->eliminarTraje(Vista::codigoDelTraje()) << std::endl;break;
    case 3: {
        system("cls");
        int subOpcion = Vista::menuInformacion();
        switch (subOpcion)
        {
        case 1:std::cout << tienda; break;
        case 2:std::cout << "Ventas totales sin ganancia: " << tienda->ventasSinGanacia(); break;
        case 3:std::cout << "Ventas totales con ganancia: " << tienda->ventasConGanancia(); break;
        case 4:std::cout << "Ganancia neta: " << tienda->GananciaNeta(); break;
        case 5:tienda->imprimirTrajes(); break;
        case 6:tienda->imprimirClientesEmpresa(); break;
        case 7:tienda->imprimirClientesFisico(); break;
        default: break;
        }
    };
    default: break;
    }
}
