#include "TiendaEnCostaRica.h"

TiendaEnCostaRica::TiendaEnCostaRica()
{
    contenedor = new ContenedorDeVentas();
    catalogo = new CatalogoEnLinea();
}

TiendaEnCostaRica::~TiendaEnCostaRica()
{
    (contenedor)? (delete contenedor, nullptr) : ((catalogo) ? (delete catalogo , nullptr):nullptr);
}
std::ostream& operator<<(std::ostream& os, const TiendaEnCostaRica* tienda)
{
    return (tienda->catalogo->trajeMasComprado())? os << tienda->catalogo->trajeMasComprado()->toString(): os << "Aun no hay traje mas vendido";
}
void TiendaEnCostaRica::imprimirClientesEmpresa()
{
    std::cout << "\tClientes Empresariales:\n" << catalogo->clientesEmpresa() << std::endl;
}
void TiendaEnCostaRica::imprimirClientesFisico()
{
    std::cout << "\tClientes Fisicos:\n" << catalogo->clientesFisicos() << std::endl;
}
void TiendaEnCostaRica::imprimirTrajes()const
{
    std::cout << "\tTrajes en stock:\n" << catalogo->toString() << std::endl;
}
std::string TiendaEnCostaRica::eliminarTraje(std::string codigo)
{
    return (catalogo->eliminaTraje(codigo)) ? "\nEl traje se ha eliminado con exito!\n" : "\nEl traje no existe.\n";
}
void TiendaEnCostaRica::ingresaTrajeEjecutivo()
{
    TrajeEjecutivo t;
    CamisAbstr* c = t.creaCamisa();
    PantalonAbstr* p = t.creaPantalon();
    ZapatoAbstr* z = t.creaCalzado();
    double precio = c->getPrecio() + p->getPrecio() + z->getPrecio();
    delete c;
    delete p;
    delete z;
    std::string codigo = Servicio::generaCodigo();
    TrajeAbstracto* traje = new TrajeEjecutivo(precio, "EJECUTIVO", codigo);
    if (catalogo->ingresaTraje(traje))
    {
        std::cout << "\nEl traje se registro con exito!\nCodigo del traje: " << codigo << std::endl;
    }
    else
    {
        std::cout << "\nEl traje no se pudo registrar.\n";
        delete traje;
    }
}
void TiendaEnCostaRica::ingresaTrajeDeportivo()
{
    TrajeDeportivo t;
    CamisAbstr* c = t.creaCamisa();
    PantalonAbstr* p = t.creaPantalon();
    ZapatoAbstr* z = t.creaCalzado();
    double precio = c->getPrecio() + p->getPrecio() + z->getPrecio();
    delete c;
    delete p;
    delete z;
    std::string codigo = Servicio::generaCodigo();
    TrajeAbstracto* traje = new TrajeDeportivo(precio, "DEPORTIVO", codigo);
    if (catalogo->ingresaTraje(traje))
    {
        std::cout << "\nEl traje se registro con exito!\nCodigo del traje: " << codigo << std::endl;
    }
    else
    {
        std::cout << "\nEl traje no se pudo registrar.\n";
        delete traje;
    }
}
void TiendaEnCostaRica::ingresaTrajeTrabajo()
{
    TrajeTrabajo t;
    CamisAbstr* c = t.creaCamisa();
    PantalonAbstr* p = t.creaPantalon();
    ZapatoAbstr* z = t.creaCalzado();
    double precio = c->getPrecio() + p->getPrecio() + z->getPrecio();
    delete c;
    delete p;
    delete z;
    std::string codigo = Servicio::generaCodigo();
    TrajeAbstracto* traje = new TrajeTrabajo(precio, "TRABAJO", codigo);
    if (catalogo->ingresaTraje(traje))
    {
        std::cout << "\nEl traje se registro con exito!\nCodigo del traje: " << codigo << std::endl;
    }
    else
    {
        std::cout << "\nEl traje no se pudo registrar.\n";
        delete traje;
    }
}
TrajeAbstracto* TiendaEnCostaRica::personalizarTraje()
{
    TrajeTrabajo t1;
    TrajeDeportivo t2;
    TrajeEjecutivo t3;
    CamisAbstr* camisa=nullptr;
    PantalonAbstr* pantalon=nullptr;
    ZapatoAbstr* zapato=nullptr;
    std::cout << "a-Con Cuadros\nb-Camiseta\nC-Manga Larga\n";
    switch (Servicio::ingresoDato("Seleccione el tipo de camisa: ", 'a', 'c'))
    {
    case 1: camisa = t1.creaCamisa(); break;
    case 2: camisa = t2.creaCamisa(); break;
    case 3: camisa = t3.creaCamisa(); break;
    default: break;
    }
    std::cout << "a-Jeams\nb-Pantaloneta\nC-De vestir\n";
    switch (Servicio::ingresoDato("Seleccione el tipo de pantalon: ", 'a', 'c'))
    {
    case 1: pantalon = t1.creaPantalon(); break;
    case 2: pantalon = t2.creaPantalon(); break;
    case 3: pantalon = t3.creaPantalon(); break;
    default: break;
    }
    std::cout << "a-Botas\nb-Tennis\nC-Ejecutivo\n";
    switch (Servicio::ingresoDato("Seleccione el tipo de calzado: ", 'a', 'c'))
    {
    case 1: zapato = t1.creaCalzado(); break;
    case 2: zapato = t2.creaCalzado(); break;
    case 3: zapato = t3.creaCalzado(); break;
    default:break;
    }
    double precio = camisa->getPrecio() + pantalon->getPrecio() + zapato->getPrecio();
    delete camisa;
    delete pantalon;
    delete zapato;
    return new TrajeAbstracto(precio, "Personalizado", Servicio::generaCodigo());
}
void TiendaEnCostaRica::suscribirPersona(Cliente* c)
{
    if (catalogo->agregaSuscriptor(c))
    {
        std::cout << "La suscripcion anual tiene un coste de 200 dolares.. Ahora puedes hacer compras en nuestra tienda en linea.\n";
    }
    else
    {
        std::cout << "El Cliente ya existe!\n";
        delete c;
    }
}
void TiendaEnCostaRica::suscribirEmpresa(Cliente* c)
{
    if (catalogo->agregaSuscriptor(c))
    {
        std::cout << "La suscripcion anual tiene un coste de 400 dolares.. Ahora la empresa puede hacer compras en nuestra tienda en linea.\n";

    }
    else
    {
        std::cout << "El Cliente ya existe!\n";
        delete c;
    }
}
void TiendaEnCostaRica::iniciaSesion()
{
    std::string cedula;
    std::cout << "Digite la cedula cliente: ";
    getline(std::cin, cedula);
    std::cin.ignore(255, '\n');
    Cliente* cliente = (Cliente*)(catalogo->getSuscriptor(cedula));
    if (cliente != NULL)
    {
        char opcion = 'x';
        while (opcion != 'c') {
            std::cout << "a-Comprar trajes en stock.\n"<< "b-Personalizar un traje.\n"<< "c-Cerrar sesion.";
            switch (Servicio::ingresoDato("Digite una opcion: ", 'a', 'c'))
            {
            case 'a': {
                std::string codigo;
                imprimirTrajes();
                std::cout << "Ingrese el codigo del traje que desee comprar: ";
                getline(std::cin, codigo);
                ejecutarVenta(cliente, codigo);
            }; break;
            case 'b': {
                TrajeAbstracto* traje = this->personalizarTraje();
                if (catalogo->ingresaTraje(traje)) {
                    ejecutarVenta(cliente, traje->getCodigo());
                }
                else {
                    std::cout << "\nCodigo en stock no disponible!\n";
                }
            }; break;
            default: break;
            }
        }
    }
    else {
        std::cout << "El cliente no esta suscrito, por favor suscribirse primero.\n";
    }
}
void TiendaEnCostaRica::ejecutarVenta(Cliente* cliente, std::string codigo)
{
    TrajeAbstracto* traje = catalogo->getTraje(codigo);
    if (traje)
    {
        Hora* hora = Hora::creaHora();
        Fecha* fecha = Fecha::creaFecha();
        Venta* venta = new Venta(hora, fecha, traje->getPrecio());
        std::cout << venta->toString(cliente, traje);
        traje->setvecesComprado();
        contenedor->agregaVenta(venta);
    }
    else {

        std::cout << "\nCodigo en stock no disponible!\n";
    }
}
double TiendaEnCostaRica::ventasSinGanacia()
{
    return contenedor->totalVentas();
}
double TiendaEnCostaRica::ventasConGanancia()
{
    return Servicio::calculaPrecioFinal(ventasSinGanacia());
}
double TiendaEnCostaRica::GananciaNeta()
{
    return ventasConGanancia() - ventasSinGanacia();
}
void TiendaEnCostaRica::leerArchivos()
{
    contenedor->leerVentas();
    catalogo->recuperarATodos();
    catalogo->recuperarClientes();
}
void TiendaEnCostaRica::salvarArchivos()
{
    contenedor->salvarVentas();
    catalogo->guardarATodos();
    catalogo->guardarClientes();
}
