#pragma once
#include"ContenedorDeVentas.h"
#include"CatalogoEnLinea.h"
#include"TrajeDeportivo.h"
#include"TrajeTrabajo.h"
#include"TrajeEjecutivo.h"
#include"Persona.h"
#include"Empresa.h"
class TiendaEnCostaRica
{
public:
    TiendaEnCostaRica();
    virtual ~TiendaEnCostaRica();
    std::string eliminarTraje(std::string);
    friend std::ostream& operator<<(std::ostream&, const TiendaEnCostaRica*);
    void imprimirClientesEmpresa();
    void imprimirClientesFisico();
    void imprimirTrajes()const;
    void ingresaTrajeEjecutivo();
    void ingresaTrajeDeportivo();
    void ingresaTrajeTrabajo();
    TrajeAbstracto* personalizarTraje();
    void suscribirPersona(Cliente*);
    void suscribirEmpresa(Cliente*);
    void iniciaSesion();
    void ejecutarVenta(Cliente*, std::string);
    double ventasSinGanacia();
    double ventasConGanancia();
    double GananciaNeta();
    void leerArchivos();
    void salvarArchivos();
private:
    ContenedorDeVentas* contenedor;
    CatalogoEnLinea* catalogo;
};

