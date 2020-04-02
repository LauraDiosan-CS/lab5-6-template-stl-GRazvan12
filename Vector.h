#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

template <class T, int CAP = 10>
class Vector {
private:
	T elem[CAP];
	int size;
public:
	Vector();
	Vector(const Vector<T, CAP>& v);
	~Vector();
	void addElem(T el);
	void deleteElem(int pos);
	T getElemPos(int pos);
	void setElemPos(int pos, T el);
	int getSize();
	T* getAll();
};

//Desc: creeaza un nou vector
//In: -
//Out: un obiect de tip Vector fara elemente
template <class T, int CAP> Vector<T, CAP>::Vector() {
	this->size = 0;
}

//Descr: constructor de copiere
//In: alt vector
//Out: un nou vector cu elementele din alt vector
template <class T, int CAP> Vector<T, CAP>::Vector(const Vector<T, CAP>& v) {
	//TO DO
	this->size = v.size;
	for (int i = 0; i < v.size; i++) {
		this->elem[i] = v.elem[i];
	}
}
//Descr: distruge un vector
//In: un vector
//Out: -
template <class T, int CAP> Vector<T, CAP>::~Vector() {
	this->size = 0;
}
//Descr: aduaga un element in vector
//In:un element
//Out:-
template <class T, int CAP> void Vector<T, CAP>::addElem(T e) {
	if (this->size < CAP)
		this->elem[this->size++] = e;
}
//Descr:elimina un element din vector
//In:o pozitie
//Out:-
template <class T, int CAP> void Vector<T, CAP>::deleteElem(int pos) {
	this->elem[pos] = this->elem[--this->size];
}
//Descr:ia elementul de pe o pozitie
//In:o pozitie
//Out:elementul de pe pozitia data
template <class T, int CAP> T Vector<T, CAP>::getElemPos(int pos) {
	return this->elem[pos];
}
//Descr:schimba elementul de pe o pozitie in vector
//In: 0 pozitie si un element
//Out:-
template <class T, int CAP>
void Vector<T, CAP>::setElemPos(int pos, T e) {
	this->elem[pos] = e;
}
//Descr: acceseaza lungimea vectorului
//In:-
//Out:lungimea vectorului
template <class T, int CAP> int Vector<T, CAP>::getSize() {
	return this->size;
}
//Descr:acceseaza lista din vector
//In:	-
//Out:	lista din vector
template <class T, int CAP> T* Vector<T, CAP>::getAll() {
	return this->elem;
}
#endif