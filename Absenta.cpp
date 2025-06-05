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

Absenta::Absenta(int zi, int luna, int an, bool motiv):data(Data(zi,luna,an)),motivat(motiv)
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
	data.afiseaza();
	if (this->motivat)
		cout << " (motivata); ";
	else
		cout << " (nemotivata); ";
}

Data Absenta::getData() const {
	return data;
}

bool Absenta::getMotivata() const {
	return motivat;
}