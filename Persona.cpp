#include "Persona.h"

Persona::Persona(std::string nom, std::string ced, std::string corr, double pago, std::string ciuda, std::string pai, std::string nacion) :Cliente(nom, ced, corr, pago, ciuda, pai)
{
	this->nacionalidad = nacion;
}

Persona::~Persona()
{
}
void Persona::actualizar(TrajeAbstracto* traje)const
{
	Cliente::actualizar(traje);
}
void Persona::escribirCliente(std::ofstream* f)
{
	*f << nombre << '\n';
	*f << cedula << '\n';
	*f << corrElec << '\n';
	*f << pagoSuscrip << '\n';
	*f << ciudad << '\n';
	*f << pais << '\n';
	*f << nacionalidad << '\n';
}
Cliente* Persona::leerPersona(std::ifstream* f)
{
	std::string no, ced, corr, pas, ciu, pai, nac;
	*f >> no;
	*f >> ced;
	*f >> corr;
	*f >> pas;
	*f >> ciu;
	*f >> pai;
	*f >> nac;
	double pag = atof(pas.c_str());
	return new Persona(no, ced, corr, pag, ciu, pai, nac);
}
