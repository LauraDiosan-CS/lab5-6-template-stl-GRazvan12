#pragma once
#include <iostream>
#include <string>

using namespace std;

class Prajitura {
private:
	int id;
	string nume;
	string ingrediente;
	double pret;
public:
	Prajitura();
	Prajitura(int id, string nume, string ingrediente, double pret);
	Prajitura(const Prajitura& p);
	~Prajitura();
	void setID(int id);
	void setNume(string nume);
	void setIngrediente(string ingrediente);
	void setPret(double pret);
	int getID();
	string getNume();
	string getIngrediente();
	double getPret();
	
	Prajitura& operator=(const Prajitura& p);
	bool operator==(const Prajitura& p);

	friend istream& operator>>(istream& is, Prajitura& p);
	friend ostream& operator<<(ostream& os, const Prajitura& p);
};
