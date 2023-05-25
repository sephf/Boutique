#include "Venta.h"

Venta::Venta(Hora* h, Fecha* f, double pt) :hora(h), fecha(f), valorTraje(pt)
{
}

Venta::~Venta()
{
    hora ? (delete hora, nullptr) : (fecha ? (delete fecha, nullptr) : nullptr);
}
double Venta::getValorTraje()
{
    return valorTraje;
}
std::string Venta::toString(Cliente* c, TrajeAbstracto* t)
{
    std::stringstream s;
    int codigo;
    s << "---------------------Factura------------------------\n";
    s << fecha->toString() << std::endl;
    s << hora->toString() << std::endl;
    if (c != NULL)
    {
        s << c->toString();
        std::string pais = c->getPais();
        std::string ciudad = c->getCiudad();
        codigo = Servicio::codigoTraslado(pais, ciudad);

    }
    else
    {
        codigo = 0;
    }
    double precioFinal = Servicio::calculaPrecioFinal(getValorTraje());
    double conIva = Servicio::calculoIVA(precioFinal);
    double traslado = Servicio::precioTraslado(codigo);
    s << t->toString();
    s << "\nCosto final del traje: " << precioFinal;
    s << "\nIVA: " << conIva;
    s << "\nTraslado: " << traslado;
    s << "\nTotal a pagar: " << precioFinal + conIva + traslado;
    s << "\n-------------------------------------------------------\n";
    return s.str();
}

