#pragma once
#include"TiendaEnCostaRica.h"
class Vista
{
public:
    static int interfazMenu0();
    static int menuVentaEnLinea();
    static char subMenuVentaEnLinea();
    static int menuMantenimiento();
    static int subMenuTraje();
    static std::string codigoDelTraje();
    static int menuInformacion();
    static Cliente* creaPersona();
    static Cliente* creaEmpresa();
    static std::string solicitudCodigo();
};
