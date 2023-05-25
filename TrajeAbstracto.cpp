#include "TrajeAbstracto.h"

TrajeAbstracto::TrajeAbstracto(double pr, std::string t, std::string c) :precio(pr), tipo(t), codigo(c)
{
	vecesComprado = 0;
}
TrajeAbstracto::TrajeAbstracto()
{
	precio = 0.0;
	tipo = "";
	codigo = "";
	vecesComprado = 0;
}
TrajeAbstracto::~TrajeAbstracto()
{
}
CamisAbstr* TrajeAbstracto::creaCamisa()
{
	return new CamisAbstr(0.0, "", "");
}
PantalonAbstr* TrajeAbstracto::creaPantalon()
{
	return new PantalonAbstr(0.0, "", "");
}
ZapatoAbstr* TrajeAbstracto::creaCalzado()
{
	return new ZapatoAbstr(0.0, "", "");
}
std::string TrajeAbstracto::getCodigo()const
{
	return codigo;
}
std::string TrajeAbstracto::getTipo()const
{
	return tipo;
}
std::string TrajeAbstracto::toString()const
{
	std::stringstream s;
	s << ", Codigo: " << getCodigo() << ", Tipo: " << getTipo() << "Precio: " << getPrecio() << '\n';
	return s.str();
}
double TrajeAbstracto::getPrecio()const
{
	return precio;
}
void TrajeAbstracto::setvecesComprado()
{
	vecesComprado++;
}
unsigned int TrajeAbstracto::getVecesComprado()
{
	return vecesComprado;
}
void TrajeAbstracto::escribirTraje(std::ofstream* f)
{
	*f << precio << 'n';
	*f << tipo << '\n';
	*f << codigo << '\n';
	*f << vecesComprado;
}
TrajeAbstracto* TrajeAbstracto::leerTraje(std::ifstream* f)
{
	std::string preci, tip, cod, vComprado;
	int vc;
	double val;
	*f >> preci;
	*f >> tip;
	*f >> cod;
	*f >> vComprado;
	val = atof(preci.c_str());
	vc = atoi(vComprado.c_str());
	TrajeAbstracto* t = new TrajeAbstracto(val, tip, cod);
	t->vecesComprado = vc;
	return t;
}
