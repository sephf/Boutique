#include "Empresa.h"

Empresa::Empresa(std::string nom, std::string ced, std::string corr, double pago, std::string ciuda, std::string pai, bool cf) :Cliente(nom, ced, corr, pago, ciuda, pai)
{
	this->clienteFrecuente = cf;
}

Empresa::~Empresa()
{
}
void Empresa::actualizar(TrajeAbstracto* traje)const
{
	Cliente::actualizar(traje);
}
void Empresa::escribirCliente(std::ofstream* f)
{
	*f << nombre << '\n';
	*f << cedula << '\n';
	*f << corrElec << '\n';
	*f << pagoSuscrip << '\n';
	*f << ciudad << '\n';
	*f << pais << '\n';
	*f << clienteFrecuente << '\n';
}
Cliente* Empresa::leerEmpresa(std::ifstream* f)
{
	std::string no, ced, corr, pas, ciu, pai, clf;
	*f >> no;
	*f >> ced;
	*f >> corr;
	*f >> pas;
	*f >> ciu;
	*f >> pai;
	*f >> clf;
	double pag = atof(pas.c_str());
	int cantEs = atoi(clf.c_str());
	return new Empresa(no, ced, corr, pag, ciu, pai, cantEs);
}
