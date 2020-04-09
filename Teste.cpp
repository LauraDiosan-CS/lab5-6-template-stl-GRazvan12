#include "Teste.h"
#include "Prajitura.h"
#include "Repo.h"
#include "RepoFile.h"
#include <iostream>
#include <assert.h>
#include "Service.h"

//Desc: testeaza constructorii clasei Prajitura
void constructoriPrajitura() {
	Prajitura p1; //constructor implicit
	assert((p1.getID() == -1) && (p1.getPret() == 0) && (p1.getNume().empty()));

	Prajitura p2(1, "gogoasa", "zahar", 20); //constructor cu parametri
	assert((p2.getID() == 1) && (p2.getNume() == "gogoasa") && (p2.getIngrediente() == "zahar") && (p2.getPret() == 20));

	Prajitura p3(p2); //constructor de copiere
	assert((p3.getID() == 1) && (p3.getNume() == "gogoasa") && (p3.getIngrediente() == "zahar") && (p3.getPret() == 20));


	//constructori pe obiecte dinamice
	Prajitura* pp1;
	pp1 = new Prajitura; //constructor implicit
	assert((pp1->getID() == -1) && (pp1->getPret() == 0) && (pp1->getNume().empty()));

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

//Desc: testeaza constructorii clasei Repo
void constructoriRepo() {
	Repo<Prajitura> r; //constructor implicit
	assert(r.getSize() == 0);

	//constructori pe obiecte dinamice
	Repo<Prajitura>* rp; //constructor implicit
	rp = new Repo<Prajitura>;
	assert(rp->getSize() == 0);

	delete rp;
}

//Desc: testeaza setterii si getterii clasei Repo
void setGetRepo() {
	Repo<Prajitura> r;

	vector<Prajitura> v = r.getAll();
	assert((v.empty()) && (r.getSize() == 0));

	Repo<Prajitura>* rp;
	rp = new Repo<Prajitura>;

	vector<Prajitura> vp = rp->getAll();
	assert((vp.empty()) && (rp->getSize() == 0));

	delete rp;
}

//Desc: testeaza functia de a adauga elemente in repo
void addToRepo() {
	Repo<Prajitura> r;
	Prajitura p1(1, "tarta", "zahar", 40.3);
	Prajitura p2(2, "tort", "ciocolata", 100.5);
	
	r.addElem(p1);
	r.addElem(p2);
	vector<Prajitura> v = r.getAll();
	assert((v.size() == 2) && (v[0] == p1) && (v[1] == p2));
}

//Desc: testeaza functia de a citi un element de pe o anumita pozitie din repo
void readFromRepo() {
	Repo<Prajitura> r;
	Prajitura p1(1, "tarta", "zahar", 40.3);
	Prajitura p2(2, "tort", "ciocolata", 100.5);

	r.addElem(p1);
	r.addElem(p2);
	Prajitura g1 = r.readElem(0);
	Prajitura g2 = r.readElem(1);
	assert((g1 == p1) && (g2 == p2));
}

//Desc: testeaza functia de a sterge elemente din repo
void deleteFromRepo() {
	Repo<Prajitura> r;
	Prajitura p1(1, "tarta", "zahar", 40.3);
	Prajitura p2(2, "tort", "ciocolata", 100.5);

	r.addElem(p1);
	r.addElem(p2);
	vector<Prajitura> v = r.getAll();
	assert(v.size() == 2);

	r.delElem(p1);
	v = r.getAll();
	assert((v.size() == 1) && (v[0] == p2));

	r.deleteAll();
	assert(r.getSize() == 0);
}

//Desc: testeazafunctia de a modifica elemente din repo
void updateFromRepo() {
	Repo<Prajitura> r;
	Prajitura p1(1, "tarta", "zahar", 40.3);
	Prajitura p2(2, "tort", "ciocolata", 100.5);

	r.addElem(p1);
	r.updateElem(p1, p2);
	vector<Prajitura> v = r.getAll();
	assert(v[0] == p2);
}

//Desc: gestioneaza testele pentru clasa Repo care opereaza cu fisiere
void testeRepo() {
	constructoriRepo();
	setGetRepo();
	addToRepo();
	readFromRepo();
	deleteFromRepo();
	updateFromRepo();
}

//Desc: testeaza constructorii clasei RepoFile
void constructoriRepoFile() {
	RepoFile<Prajitura> r; //constructor implicit
	assert((r.getSize() == 0) && (r.getFileName() == NULL));

	RepoFile<Prajitura> r2("test.txt"); //constructor cu parametri
	assert((r2.getSize() == 0) && (strcmp(r2.getFileName(), "test.txt") == 0));

	//constructori pe obiecte dinamice
	RepoFile<Prajitura>* rp; 
	rp = new RepoFile<Prajitura>;//constructor implicit
	assert((rp->getSize() == 0) && (rp->getFileName() == NULL));

	RepoFile<Prajitura>* rp2;
	rp2 = new RepoFile<Prajitura>("test.txt"); //constructor cu parametri
	assert((rp2->getSize() == 0) && (strcmp(rp2->getFileName(), "test.txt") == 0));

	delete rp;
	delete rp2;
}

//Desc: testeaza setterii si getterii clasei RepoFile
void setGetRepoFile() {
	RepoFile<Prajitura> r;

	vector<Prajitura> v = r.getAll();
	assert((v.empty()) && (r.getSize() == 0) && (r.getFileName() == NULL));

	RepoFile<Prajitura>* rp;
	rp = new RepoFile<Prajitura>;

	vector<Prajitura> vp = rp->getAll();
	assert((vp.empty()) && (rp->getSize() == 0) && (rp->getFileName() == NULL));

	delete rp;
}

//Desc: testeaza functia de a adauga elemente in RepoFile
void addToRepoFile() {
	RepoFile<Prajitura> r;
	Prajitura p1(1, "tarta", "zahar", 40.3);
	Prajitura p2(2, "tort", "ciocolata", 100.5);

	r.addElem(p1);
	r.addElem(p2);
	vector<Prajitura> v = r.getAll();
	assert((v.size() == 2) && (v[0] == p1) && (v[1] == p2));
}

//Desc: testeaza functia de a citi un element de pe o anumita pozitie din RepoFile
void readFromRepoFile() {
	RepoFile<Prajitura> r;
	Prajitura p1(1, "tarta", "zahar", 40.3);
	Prajitura p2(2, "tort", "ciocolata", 100.5);

	r.addElem(p1);
	r.addElem(p2);
	Prajitura g1 = r.readElem(0);
	Prajitura g2 = r.readElem(1);
	assert((g1 == p1) && (g2 == p2));
}

//Desc: testeaza functia de a sterge elemente din RepoFile
void deleteFromRepoFile() {
	RepoFile<Prajitura> r;
	Prajitura p1(1, "tarta", "zahar", 40.3);
	Prajitura p2(2, "tort", "ciocolata", 100.5);

	r.addElem(p1);
	r.addElem(p2);
	vector<Prajitura> v = r.getAll();
	assert(v.size() == 2);

	r.delElem(p1);
	v = r.getAll();
	assert((v.size() == 1) && (v[0] == p2));

	r.deleteAll();
	assert(r.getSize() == 0);
}

//Desc: testeazafunctia de a modifica elemente din RepoFile
void updateFromRepoFile() {
	RepoFile<Prajitura> r;
	Prajitura p1(1, "tarta", "zahar", 40.3);
	Prajitura p2(2, "tort", "ciocolata", 100.5);

	r.addElem(p1);
	r.updateElem(p1, p2);
	vector<Prajitura> v = r.getAll();
	assert(v[0] == p2);
}

//Desc: testeaza overload-ul operatorului egal asupra clasei RepoFile
void egalRepoFile() {
	RepoFile<Prajitura> r1;
	RepoFile<Prajitura> r2;

	Prajitura p1(1, "tarta", "zahar", 40.3);
	Prajitura p2(2, "tort", "ciocolata", 100.5);

	r1.addElem(p1);
	r1.addElem(p2);
	
	assert(r2.getSize() == 0);
	r2 = r1;
	assert(r2.getSize() == 2);
}

//Desc: gestioneaza testele pentru clasa RepoFile care opereaza cu fisiere
void testeRepoFile() {
	constructoriRepoFile();
	setGetRepoFile();
	addToRepoFile();
	readFromRepoFile();
	deleteFromRepoFile();
	updateFromRepoFile();
	egalRepoFile();
}

//Desc: testeaza constructorii clasei Service
void constructoriService() {
	Service s; //constructor implicit
	vector<Prajitura> v = s.getAll();
	assert((v.empty()) && (s.getSize() == 0));

	Repo<Prajitura>* r1;
	r1 = new RepoFile<Prajitura>;
	Prajitura p1(1, "tarta", "zahar", 40.3);
	Prajitura p2(2, "tort", "ciocolata", 100.5);
	r1->addElem(p1);
	r1->addElem(p2);
	Service s2(r1); //constructor cu parametri
	v = s2.getAll();
	assert((s2.getSize() == 2) && (v[0] == p1) && (v[1] == p2));

	//constructori pe obiecte dinamice
	Service* sp;
	sp = new Service; //constructor implicit
	v = sp->getAll();
	assert((v.empty()) && (sp->getSize() == 0));

	delete r1;
	delete sp;
}

//Desc: testeaza getterii clasei Service
void getService() {
	Service s;
	assert((s.getAll().empty()) && (s.getSize() == 0));

	Service* sp;
	sp = new Service;
	assert((sp->getAll().empty()) && (sp->getSize() == 0));

	delete sp;
}

//Desc: testeaza functia de a adauga prajituri in service
void addPrajService() {
	Service s;

	bool reusit1 = s.addPrajitura(1, "tarta", "zahar", 40.3);
	bool reusit2 = s.addPrajitura(2, "tort", "ciocolata", 100.5);
	bool reusit3 = s.addPrajitura(2, "tort", "ciocolata", 100.5);

	assert((reusit1 == true) && (reusit2 == true) && (reusit3 == false));
}

//Desc: testeaza functia de a cauta prajituri pe anumite pozitii din service
void readPrajService() {
	Service s;
	Prajitura p1(1, "tarta", "zahar", 40.3);
	Prajitura p2(2, "tort", "ciocolata", 100.5);

	bool reusit1 = s.addPrajitura(1, "tarta", "zahar", 40.3);
	bool reusit2 = s.addPrajitura(2, "tort", "ciocolata", 100.5);

	assert((s.readPrajitura(0) == p1) && (s.readPrajitura(1) == p2));
}

//Desc: testeaza functia de a sterge prajituri din service
void delPrajService() {
	Service s;
	Prajitura p1(1, "tarta", "zahar", 40.3);
	Prajitura p2(2, "tort", "ciocolata", 100.5);

	bool reusit1 = s.addPrajitura(1, "tarta", "zahar", 40.3);
	bool reusit2 = s.addPrajitura(2, "tort", "ciocolata", 100.5);

	bool reusit = s.delPrajitura(1);
	assert((reusit == true) && (s.readPrajitura(0) == p2));
}

//Desc: testeaza functia de a modifica prajituri din service
void updatePrajService() {
	Service s;
	Prajitura p1(1, "tarta", "zahar", 40.3);

	bool reusit1 = s.addPrajitura(1, "tarta", "zahar", 40.3);
	
	bool reusit = s.updatePrajitura(1, "tort", "ciocolata", 100.5);
	Prajitura p2 = s.readPrajitura(0);
	assert((reusit == true) && (p2.getNume() == "tort") && (p2.getIngrediente() == "ciocolata") && (p2.getPret() == 100.5));
}

//Desc: gestioneaza testele pentru clasa Service
void testeService() {
	constructoriService();
	getService();
	addPrajService();
	readPrajService();
	delPrajService();
	updatePrajService();
}

void teste() {
	testePrajitura();
	testeRepo();
	testeRepoFile();
	testeService();
}