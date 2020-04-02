#include "Teste.h"
#include "Prajitura.h"
#include <iostream>
#include <assert.h>

//Desc: testeaza constructorii clasei Prajitura
void constructoriPrajitura() {
	Prajitura p1; //constructor implicit
	assert((p1.getID() == -1) && (p1.getPret() == 0));

	Prajitura p2(1, "gogoasa", "zahar", 20); //constructor cu parametri
	assert((p2.getID() == 1) && (p2.getNume() == "gogoasa") && (p2.getIngrediente() == "zahar") && (p2.getPret() == 20));

	Prajitura p3(p2); //constructor de copiere
	assert((p3.getID() == 1) && (p3.getNume() == "gogoasa") && (p3.getIngrediente() == "zahar") && (p3.getPret() == 20));


	//constructori pe obiecte dinamice
	Prajitura* pp1;
	pp1 = new Prajitura; //constructor implicit
	assert((pp1->getID() == -1) && (pp1->getPret() == 0));

	Prajitura* pp2 = new Prajitura(1, "ciocolata", "zahar", 40); //constructor cu parametri
	assert((pp2->getID() == 1) && (pp2->getNume() == "ciocolata") && (pp2->getIngrediente() == "zahar") && (pp2->getPret() == 40));

	Prajitura* pp3 = new Prajitura(*pp2); //constructor de copiere
	assert((pp3->getID() == 1) && (pp3->getNume() == "ciocolata") && (pp3->getIngrediente() == "zahar") && (pp3->getPret() == 40));

	if (pp1 != NULL) {
		delete pp1; //se apeleaza destructorul
		pp1 = NULL;
	}
	if (pp2 != NULL) {
		delete pp2;
		pp2 = NULL;
	}
	if (pp3 != NULL) {
		delete pp3;
		pp3 = NULL;
	}
}

//Desc : testeaza setterii si getterii clasei Prajitura
void setGetPrajitura() {
	Prajitura p;

	p.setID(12);
	p.setNume("tort");
	p.setIngrediente("zahar");
	p.setPret(200);
	assert((p.getID() == 12) && (p.getNume() == "tort") && (p.getIngrediente() == "zahar") && (p.getPret() == 200));

	Prajitura* p2;
	p2 = new Prajitura;

	p2->setID(7);
	p2->setNume("baton");
	p2->setIngrediente("zahar");
	p2->setPret(10);
	assert((p2->getID() == 7) && (p2->getNume() == "baton")  && (p2->getIngrediente() == "zahar") && (p2->getPret() == 10));

	delete p2;
}

//Desc: testeaza operatorul de egalitate asupra clasei Prajitura
void egalPrajitura() {
	Prajitura p1(1, "vafe", "zahar", 40);
	Prajitura p2(7, "ciocolata", "zahar", 50);

	assert((p1.getID() == 1) && (p1.getNume() == "vafe") && (p1.getIngrediente() == "zahar") && (p1.getPret() == 40));
	p1 = p2;
	assert((p1.getID() == 7) && (p1.getNume() == "ciocolata") && (p1.getIngrediente() == "zahar") && (p1.getPret() == 50));
}

//Desc: gestioneaza testele pentru clasa Prajitura
void testePrajitura() {
	constructoriPrajitura();
	setGetPrajitura();
	egalPrajitura();
}

void teste() {
	testePrajitura();
}