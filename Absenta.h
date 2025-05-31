#ifndef __ABSENTA_H
#define __ABSENTA_H
#include "Data.h"
#include <iostream>

using namespace std;

class Absenta {
	Data data;
	bool motivat = false;

public:
	Absenta(int, int, int, bool);
	~Absenta();
};


#endif

