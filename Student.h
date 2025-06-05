#ifndef __STUDENT_H
#define __STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include "Materie.h"

using namespace std;

class Student{
	string nume_elev;
	vector <Materie> informatii_elev;
	int numar_materii=0;

public:
	Student(const string&, int);
	Student(const string&);
	//Student();
	~Student();

	string getNume() const;
	vector <Materie>& getMaterii();
	friend Student adaugaStudent(const string&, const Student&);

	void afisare() const;
	Materie* gasireMaterie(const string&);
	void adaugaMaterie(const Materie&);
};



#endif

