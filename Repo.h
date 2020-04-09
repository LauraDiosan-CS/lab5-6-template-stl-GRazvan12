#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include "Prajitura.h"

using namespace std;

template <class T> class Repo {
private:
	vector<T> elemente;
public:
	Repo();
	~Repo();
	virtual void addElem(const T elem);
	virtual void delElem(T& elem);
	virtual void updateElem(T& elemVechi, T& elemNou);
	virtual T readElem(int poz);
	virtual vector<T> getAll();
	virtual void setRepo(vector<T> v);
	virtual int getSize();
	virtual void deleteAll();

	virtual Repo<T>& operator=(const Repo<T>& r);
};

//Desc: creeaza un obiect de tip Repo
//In: -
//Out: o instanta a clasei Repo
template <class T> Repo<T>::Repo()
{
}

//Desc: distruge un obiect de tip Repo
//In: obiectul curent
//Out: -
template <class T> Repo<T>::~Repo()
{
}

//Desc: adauga un element in Repo
//In: elem, T - elementul de adaugat
//Out: -
template <class T> void Repo<T>::addElem(const T elem) {
	this->elemente.push_back(elem);
}

//Desc: sterge un element din Repo
//In: elem, T - elementul care trebuie sters
//Out: -
template <class T> void Repo<T>::delElem(T& elem) {
	typename vector<T>::iterator it;

	it = find(this->elemente.begin(), this->elemente.end(), elem);
	if (!(it == this->elemente.end()))
		this->elemente.erase(it);
}

//Desc: modifica un element din Repo
//In: id, int - id-ul elementului de modificat
//	  elem, T - noul element
//Out: -
template <class T> void Repo<T>::updateElem(T& elemVechi, T& elemNou) {
	typename vector<T>::iterator it;

	it = find(this->elemente.begin(), this->elemente.end(), elemVechi);
	if (!(it == this->elemente.end())) {

		*it = elemNou;
	}
}

//Desc: ia un element de pe o anumita pozitie din repo
//In: poz, int - pozitia elementului de returnat
//Out: elementul de pe pozitia poz
template <class T> T Repo<T>::readElem(int poz) {
	return this->elemente[poz];
}

//Desc: sterge toate elementele din Repo
//In: -
//Out: -
template <class T> void Repo<T>::deleteAll() {
	this->elemente.clear();
}

//Desc: schimba lista de elemente al unui repo
//In: v, vector<T> , noul vector de elemente
//Out: -
template <class T> void Repo<T>::setRepo(vector<T> v) {
	this->elemente = v;
}

//Desc: acceseaza lista de elemente
//In: -
//Out: lista de elemente
template <class T> vector<T> Repo<T>::getAll() {
	return this->elemente;
}

//Desc: acceseaza lungimea listei de elemente unui repo
//In: -
//Out: lungimea listei de elemente
template <class T> int Repo<T>::getSize() {
	return this->elemente.size();
}

//Desc: creeaza un obiect de tip Repo dintr-un obiect de tip Repo dat
//In: un obiect r de tip Repo
//Out: un obiect nou de tip Repo egal cu r
template <class T> Repo<T>& Repo<T>::operator=(const Repo<T>& r) {
	this->elemente = r.elemente;

	return *this;
}