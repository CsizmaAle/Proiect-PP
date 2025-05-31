#ifndef __CATALOG_H
#define __CATALOG_H

#include <iostream>
#include <string>

using namespace std;

class Catalog{
	string nume_elev;
	//Materie informatii_elev[30];
	int numar_materii;

public:
	Catalog(string, int);
	~Catalog();

};



#endif

