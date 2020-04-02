#pragma once
#include <vector>
#include "Prajitura.h"
#include "Vector.h"

class Repo {
private:
	Vector<Prajitura> prajituri;
	//vector<Prajitura> prajituri;
public:
	Repo();
	~Repo();
	void addPrajitura(const Prajitura& p);
	void delPrajitura(int poz);
	void updatePrajitura(int poz, const Prajitura& p);
	Prajitura* getAll();
	Prajitura getPoz(int poz);
	int getSize();
	Repo& operator=(const Repo& r);
};
