#include "Service.h"

//Desc: creeaza un obiect de tip Service
//In: -
//Out: o instanta a clasei Service
Service::Service()
{
	this->repo = new Repo<Prajitura>;
}

//Desc: creeaza un obiect de tip Service
//In: un obiect de tip RepoFile
//Out: o instanta a clasei Service cu datele din r
Service::Service(Repo<Prajitura>*& r) {
	this->repo = r;
}

//Desc: distruge un obiect de tip Service
//In: obiectul curent
//Out: -
Service::~Service()
{
}

//Desc: adauga o prajitura in repo
//In: id, int - id-ul prajiturii
//	  nume, string - numele prajiturii
//    ingrediente, string - ingredientele prajiturii
//    pret, double - pretul prajiturii
//Out: true, daca prajitura a fost adaugata, false altfel
bool Service::addPrajitura(int id, string nume, string ingrediente, double pret) {
	vector<Prajitura> prajituri = this->repo->getAll();

	for (auto it = prajituri.begin(); it != prajituri.end(); it++)
		if ((*it).getID() == id)
			return false;
	Prajitura p(id, nume, ingrediente, pret);
	this->repo->addElem(p);

	return true;
}

//Desc: acceseaza prajitura de pe o anumita pozitie
//In: poz, int - pozitie prajiturii de cautat
//Out: prajitura de pe pozitia poz
Prajitura Service::readPrajitura(int poz) {
	return this->repo->readElem(poz);
}

//Desc: sterge o prajitura din repo
//In: id, int - id-ul prajiturii de sters
//Out: true, daca prajitura a fost stearsa, false altfel
bool Service::delPrajitura(int id) {
	vector<Prajitura> prajituri = this->repo->getAll();

	for(auto it = prajituri.begin(); it != prajituri.end(); it++)
		if ((*it).getID() == id) {
			Prajitura p = *it;
			this->repo->delElem(p);

			return true;
		}

	return false;
}

//Desc: modifica o prajitura din repo
//In: idVechi, int - id-ul prajiturii de modificat
//    numeNou, string - numele nou al prajiturii
//    ingredienteNoi, string - ingredientele noi ale prajiturii
//    pretNou, double - nou pret al prajiturii
//Out: true, daca prajitura a fost modificata, false altfel
bool Service::updatePrajitura(int idVechi, string numeNou, string ingredienteNoi, double pretNou) {
	vector<Prajitura> prajituri = this->repo->getAll();

	for(auto it = prajituri.begin(); it != prajituri.end(); it++)
		if ((*it).getID() == idVechi) {
			Prajitura vechi = *it;
			string nume, ingrediente;
			double pret;

			if (!numeNou.empty())
				nume = numeNou;
			else
				nume = vechi.getNume();

			if (!ingredienteNoi.empty())
				ingrediente = ingredienteNoi;
			else
				ingrediente = vechi.getIngrediente();

			if (pretNou != -1)
				pret = pretNou;
			else
				pret = vechi.getPret();

			Prajitura nou(idVechi, nume, ingrediente, pret);
			this->repo->updateElem(vechi, nou);

			return true;
		}

	return false;
}

//Desc: schimba lista de prajituri unui Service
//In: noul vector de prajituri
//Out: -
void Service::setRepo(vector<Prajitura> v) {
	this->repo->setRepo(v);
}

//Desc: acceseaza lista de prajituri din repo
//In: -
//Out: lista de prajituri
vector<Prajitura> Service::getAll() {
	return this->repo->getAll();
}

//Desc: acceseaza lungimea listei de prajituri din repo
//In: -
//Out: lungimea listei de prajituri
int Service::getSize() {
	return this->repo->getSize();
}

//Desc: creeaza un obiect de tip Service dintr-un obiect de tip Service dat
//In: un obiect s de tip Service
//Out: un obiect nou de tip Service egal cu s
Service& Service::operator=(Service& s) {
	this->repo = s.repo;

	return *this;
}
