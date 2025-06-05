#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

Student::Student(const string& nume, int nr):nume_elev(nume), numar_materii(nr)
{

}
Student::~Student()
{

}

Student::Student(const string& nume) : nume_elev(nume){ }



string Student::getNume() const
{
	return this->nume_elev;
}

vector <Materie>& Student::getMaterii() 
{
	return informatii_elev;
}

Student adaugaStudent(const string& nume, const Student& model) {
	Student nou(nume);
	for (const auto& materie : model.informatii_elev) {
		Materie copieMaterie(materie.getDenumire());
		nou.informatii_elev.push_back(copieMaterie);
	}
	nou.numar_materii = model.numar_materii;
	return nou;
}



void Student::afisare() const
{
	cout << endl<<"Elev: " << nume_elev << "\n";
	for (const auto& m : informatii_elev)
	{
		cout << m.getDenumire() << endl;
		 m.afiseazaNote();
		 m.afiseazaAbsente();
		cout << endl;
	}
	
}
Materie* Student::gasireMaterie(const string& nume)
{
	for (auto& m : informatii_elev)
		if (m.getDenumire() == nume)
			return &m;
	return nullptr;
}

void Student::adaugaMaterie(const Materie& m) {
	informatii_elev.push_back(m);
}
