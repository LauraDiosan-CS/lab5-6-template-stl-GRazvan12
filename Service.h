#pragma once
#include "RepoFile.h"

class Service {
private:
	Repo<Prajitura>* repo;
public:
	Service();
	Service(Repo<Prajitura>*& r);
	~Service();
	void setRepo(vector<Prajitura> v);
	bool addPrajitura(int id, string nume, string ingrediente, double pret);
	Prajitura readPrajitura(int poz);
	bool delPrajitura(int id);
	bool updatePrajitura(int idVechi, string numeNou, string ingredienteNoi, double pretNou);
	vector<Prajitura> getAll();
	int getSize();
	Service& operator=(Service& s);
};
