#include "Data.h"
#include <iostream>
#include "Absenta.h"

using namespace std;

Absenta::Absenta(int zi, int luna, int an, bool motivat): data(Data(zi,luna, an))
{
	this->motivat = motivat;
}

Absenta::~Absenta()
{

}
