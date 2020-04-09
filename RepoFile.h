#pragma once
#include "Repo.h"

template <class T> class RepoFile : public Repo<T> {
private:
	char* fileName;
public:
	//Desc: creeaza un obiect de tip RepoFile
	//In: -
	//Out: o instanta a clasei RepoFile
	RepoFile() :Repo<T>() {
		this->fileName = NULL;
	}

	//Desc: creeaza un obiect de tip RepoFile
	//In: fileName, const char* - numele fisierului
	//Out: o instanta a clasei RepoFile
	RepoFile(const char* fileName) :Repo<T>() {
		this->fileName = new char[strlen(fileName) + 1];
		strcpy_s(this->fileName, strlen(fileName) + 1, fileName);

		this->loadFromFile();
	}

	//Desc: distruge un obiect de tip RepoFile
	//In: obiectul curent
	//Out: -
	~RepoFile(){
		if (this->fileName) {
			delete[] this->fileName;
			this->fileName = NULL;
		}
	}

	//Desc: incarca lista de elemente din RepoFile cu elemente din fisier
	//In: -
	//Out: -
	void loadFromFile() {
		if (this->fileName != NULL) {
			ifstream f(this->fileName);
			T elem;

			while (f >> elem)
				Repo<T>::addElem(elem);
			
			f.close();
		}
		else
			Repo<T>::deleteAll();
	}

	//Desc: salveaza lista de elemente din Repo in fisier
	//In: -
	//Out: -
	void saveToFile() {
		if (this->fileName != NULL) {
			ofstream g(this->fileName);

			int size = Repo<T>::getSize();
			for (int i = 0; i < size; i++)
				g << Repo<T>::readElem(i);

			g.close();
		}
	}

	//Desc: schimba fisierul de intrare al unui RepoFile
	//In: fileName - const char*, noul fisier de intrare
	//Out: -
	void setFileName(const char* fileName) {
		if (this->fileName)
			delete[] this->fileName;

		if (fileName != NULL) {
			this->fileName = new char[strlen(fileName) + 1];
			strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
		}
		else
			this->fileName = NULL;
	}

	//Desc: acceseaza numele fisierului din RepoFile
	//In: -
	//Out: numele fisierului
	char* getFileName() {
		return this->fileName;
	}

	//Desc: adauga un element in RepoFile
	//In: elem, T - elementul de adaugat
	//Out: -
	void addElem(const T elem) {
		Repo<T>::addElem(elem);
		this->saveToFile();
	}

	//Desc: sterge un element din RepoFile
	//In: elem, T - elementul care trebuie sters
	//Out: -
	void delElem(T& elem) {
		Repo<T>::delElem(elem);
		this->saveToFile();
	}

	//Desc: modifica un element din RepoFile
	//In: id, int - id-ul elementului de modificat
	//	  elem, T - noul element
	//Out: -
	void updateElem(T& elemVechi, T& elemNou) {
		Repo<T>::updateElem(elemVechi, elemNou);
		this->saveToFile();
	}

	//Desc: acceseaza lista de elemente
	//In: -
	//Out: lista de elemente
	vector<T> getAll() {
		return Repo<T>::getAll();
	}

	//Desc: creeaza un obiect de tip RepoFile dintr-un obiect de tip RepoFile dat
	//In: un obiect r de tip RepoFile
	//Out: un obiect nou de tip RepoFile egal cu r
	RepoFile<T>& operator=(RepoFile<T>& r) {
		this->Repo<T>::setRepo(r.getAll());

		this->setFileName(r.fileName);

		return *this;
	}
};