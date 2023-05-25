#include "Subject.h"

Subject::Subject()
{
}

Subject::~Subject()
{
    if (!contenedor.empty())
    {
        contenedor.clear();
    }
}
bool Subject::agregaSuscriptor(Cliente* c)
{
    if (this->getSuscriptor(c->getCedula()) == nullptr) {
        Observa* observ = c;
        contenedor.push_back(observ);
        contenedor.shrink_to_fit();
        return true;
    }
    return false;
}
std::string Subject::clientesFisicos()
{
    std::stringstream s;
    std::string tipo;
    Persona* fi = nullptr;
    for (std::vector<Observa*>::iterator it = contenedor.begin(); it < contenedor.end(); it++)
    {
        //tipo = abi::__cxa_demangle(typeid(*(*it)).name(), 0, 0, 0);
        tipo = typeid(*(*it)).name();
        if (tipo == "Persona")
        {
            fi = (Persona*)((*it));
            s << fi->toString() << '\n';
        }
    }
    return s.str();
}
std::string Subject::clientesEmpresa()
{
    std::stringstream s;
    std::string tipo;
    Empresa* em = nullptr;
    for (std::vector<Observa*>::iterator it = contenedor.begin(); it < contenedor.end(); it++)
    {
        //tipo = abi::__cxa_demangle(typeid(*(*it)).name(), 0, 0, 0);
        tipo = typeid(*(*it)).name();        
        if (tipo == "Empresa") {
            em = (Empresa*)((*it));
            s << em->toString() << '\n';
        }
    }
    return s.str();
}
Observa* Subject::getSuscriptor(std::string cedula)
{
    Cliente* pObserva = nullptr;
    for (std::vector<Observa*>::iterator it = contenedor.begin(); it < contenedor.end(); it++)
    {
        pObserva = (Cliente*)(*it);
        if (pObserva->getCedula() == cedula)
        {
            return pObserva;
        }
    }
    return nullptr;
}
void Subject::guardarClientes()
{
    std::ofstream* arch = new std::ofstream("personas.txt");
    std::ofstream* arch2 = new std::ofstream("empresas.txt");
    if (arch && arch2) {
        Empresa* em = nullptr;
        Persona* fi = nullptr;
        std::string tipo;
        for (std::vector<Observa*>::iterator it = contenedor.begin(); it < contenedor.end(); it++)
        {
            //tipo = abi::__cxa_demangle(typeid(*(*it)).name(), 0, 0, 0);
            tipo = typeid(*(*it)).name();
            if (tipo == "Empresa") {
                em = (Empresa*)((*it));
                em->escribirCliente(arch2);
            }
            else
            {
                fi = (Persona*)((*it));
                fi->escribirCliente(arch);
            }
        }
        arch->close();
        arch2->close();
    }
    delete arch;
    delete arch2;
}

void Subject::recuperarClientes()
{
    std::ifstream arch("personas.txt");
    if (!arch) {
    }
    else {
        while (!arch.eof()) {
            agregaSuscriptor(Persona::leerPersona(&arch));
        }
        arch.close();
    }
    std::ifstream arch2("empresas.txt");
    if (!arch2) {
    }
    else {
        while (!arch2.eof()) {
            agregaSuscriptor(Empresa::leerEmpresa(&arch2));
        }
        arch2.close();
    }
}
