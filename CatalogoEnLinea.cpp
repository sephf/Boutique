#include "CatalogoEnLinea.h"

CatalogoEnLinea::CatalogoEnLinea()
{
    ppio = nullptr;
}

CatalogoEnLinea::~CatalogoEnLinea()
{
    Nodo* p;
    while (ppio)
    {
        p = ppio;
        ppio = ppio->getSiguiente();
        delete p;
    }
}
void CatalogoEnLinea::notificar(TrajeAbstracto* traje, std::string notificacion)
{
    for (std::vector<Observa*>::iterator it = contenedor.begin(); it < contenedor.end(); it++)
    {
        std::cout << notificacion << std::endl;
        (*it)->actualizar(traje);
    }
}
bool CatalogoEnLinea::ingresaTraje(TrajeAbstracto* traje)
{
    ppio = new Nodo(traje, ppio);
    notificar(traje, "<<NUEVO TRAJE>>");
    return true;
}
bool CatalogoEnLinea::eliminaTraje(std::string codigo)
{
    Nodo* p = ppio;
    while (p)
    {
        if (p->getSiguiente()->getTraje()->getCodigo() == codigo)
        {
            Nodo* aux = p->getSiguiente();
            p->setSiguiente(p->getSiguiente()->getSiguiente());
            notificar(aux->getTraje(), "<<SE VENDIO UN TRAJE>>");
            delete aux;
            return true;
        }
        p = p->getSiguiente();
    }
    return false;
}
TrajeAbstracto* CatalogoEnLinea::getTraje(std::string codigo)
{
    Nodo* p = ppio;
    while (p)
    {
        if (p->getTraje()->getCodigo() == codigo)
        {
            return p->getTraje();
        }
        p = p->getSiguiente();
    }
    return NULL;
}
TrajeAbstracto* CatalogoEnLinea::trajeMasComprado()
{
    Nodo* p = ppio,* aux = ppio;
    while (p)
    {
        if (p->getTraje()->getVecesComprado() >= aux->getTraje()->getVecesComprado())
        {
            aux = p;
        }
        p = p->getSiguiente();
    }
    return aux->getTraje();
}
std::string CatalogoEnLinea::toString()
{
    std::stringstream s;
    Nodo* p = ppio;
    while (p)
    {
        s << p->getTraje()->toString() << std::endl;
        p = p->getSiguiente();
    }
    return s.str();
}
void CatalogoEnLinea::guardarATodos()
{
    ofstream* arch = new ofstream("stock.txt");
    Nodo* aux = ppio;
    if (arch) {
        while (aux) {
            aux->getTraje()->escribirTraje(arch);
            if (aux->getSiguiente()) {
                *arch << endl;
            }
            aux = aux->getSiguiente();
        }
        arch->close();
    }
    delete arch;
}

void CatalogoEnLinea::recuperarATodos()
{
    ifstream arch("stock.txt");
    if (!arch) {
    }
    else {
        while (!arch.eof()) {
            ingresaTraje(TrajeAbstracto::leerTraje(&arch));
        }
        arch.close();
    }
}
