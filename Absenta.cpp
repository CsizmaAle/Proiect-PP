#include "Data.h"
#include <iostream>
#include "Absenta.h"

using namespace std;

Absenta::Absenta(Data d, bool motivat): data(Data(d))
{
	this->motivat = motivat;
}

Absenta::~Absenta()
{

}

void Absenta::motivareAbsenta()
{
	this->motivat = true;
}

bool Absenta::sameDate(const Data& d) const
{
	return d == data;
}

void Absenta::afisare() const
{
	cout << "Data: ";
	data.afiseaza();
	if (this->motivat)
		cout << "(motivata); ";
	else
		cout << "(nemotivata); ";
}