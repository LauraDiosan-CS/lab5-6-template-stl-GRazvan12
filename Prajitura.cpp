#include "Prajitura.h"
#include <string.h>

//Desc: creeaza un obiect de tip Prajitura
//In: -
//Out: o instanta a clasei Prajitura
Prajitura::Prajitura() {
	this->id = -1;
	this->pret = 0;
}

//Desc: creeaza un obiect de tip Prajitura
//In: id, int - id-ul prajiturii
//	  nume, string - numele prajiturii
//	  ingrediente, string - ingredientele prajiturii
//    pret, double - pretul prajiturii
//Out: o instanta a clasei Prajitura cu atributele id, nume, ingrediente, pret
Prajitura::Prajitura(int id, string nume, string ingrediente, double pret) {
	this->id = id;
	this->nume = nume;
	this->ingrediente = ingrediente;
	this->pret = pret;
}

//Desc: creeaza un obiect de tip Prajitura
//In: un produs
//Out: o instanta a clasei Prajitura cu atributele lui p
Prajitura::Prajitura(const Prajitura& p) {
	this->id = p.id;
	this->nume = p.nume;
	this->ingrediente = p.ingrediente;
	this->pret = p.pret;
}

//Desc: distruge un obiect de tip Prajitura
//In: obiectul curent
//Out: -
Prajitura::~Prajitura()
{
	this->nume.clear();
	this->ingrediente.clear();
}

//Desc: schimba id-ul unei prajituri
//In: id, int - noul id
//Out: prajitura cu id-ul schimbat
void Prajitura::setID(int id) {
	this->id = id;
}

//Desc: schimba numele unei prajituri
//In: nume, string - noul nume
//Out: prajitura cu numele schimbat
void Prajitura::setNume(string nume) {
	this->nume = nume;
}

//Desc: schimba ingredientele unei prajituri
//In: ingrediente, string - noile ingrediente
//Out: prajitura cu ingredientele schimbate
void Prajitura::setIngrediente(string ingrediente) {
	this->ingrediente = ingrediente;
}

//Desc: schimba pretul unei prajituri
//In: pret, double - noul pret
//Out: prajitura cu pretul schimbat
void Prajitura::setPret(double pret) {
	this->pret = pret;
}

//Desc: Acceseaza id- ul unei prajituri
//In: o prajitura
//Out: id-ul prajiturii
int Prajitura::getID() {
	return this->id;
}

//Desc: Acceseaza numele unei prajituri
//In: o prajitura
//Out: numele prajiturii
string Prajitura::getNume() {
	return this->nume;
}

//Desc: Acceseaza ingredientele unei prajituri
//In: o prajitura
//Out: ingredientele prajiturii
string Prajitura::getIngrediente() {
	return this->ingrediente;
}

//Desc: Acceseaza pretul unui produs
//In: un produs
//Out: pretul produsului
double Prajitura::getPret() {
	return this->pret;
}

//Desc: creeaza o prajitura egala cu o prajitura data
//In: o prajitura
//Out: un prajitura noua egala cu p
Prajitura& Prajitura::operator=(const Prajitura& p) {
	this->id = p.id;
	this->nume = p.nume;
	this->ingrediente = p.ingrediente;
	this->pret = p.pret;

	return *this;
}

//Overload pentru operatorii IO

//Desc: incarca o prajitura dintr-un stream de intrare
//In: un stream de intrare
//Out: un obiect nou de tip Prajitura
istream& operator>>(istream& is, Prajitura& p) {
	int id;
	cout << "id = ";
	is >> id;

	string nume;
	cout << "nume = ";
	is >> nume;

	string ingrediente;
	cout << "ingrediente = ";
	is >> ingrediente;

	double pret;
	cout << "pret: ";
	is >> pret;

	p.setID(id);
	p.setNume(nume);
	p.setIngrediente(ingrediente);
	p.setPret(pret);

	return is;
}

//Desc: salveaza o prajitura intr-un stream de iesire
//In: un stream de iesire si un produs
//Out: streamul de iesire incarcat cu informatia din prajitura
ostream& operator<<(ostream& os, const Prajitura& p) {
	os << "ID: " << p.id << " Nume: " << p.nume << " Ingrediente: " << p.ingrediente << "  Pret: " << p.pret << '\n';

	return os;
}