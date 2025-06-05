#ifndef __ABSENTA_H
#define __ABSENTA_H
#include "Data.h"
#include <iostream>

using namespace std;

class Absenta {
	Data data;
	bool motivat = false;

public:
	Absenta(Data, bool);
	~Absenta();
	void motivareAbsenta();
	void afisare() const;
	bool sameDate(const Data& d) const;
};


#endif

