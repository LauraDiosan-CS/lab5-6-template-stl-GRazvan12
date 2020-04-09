#pragma once
#include "Service.h"

class UI {
private:
	Service serv;
	void meniuPrincipal();
	void adaugare();
	void stergere();
	void modificare();
	void afisare();
public:
	UI();
	UI(Service& s);
	~UI();
	void runUI();
};
