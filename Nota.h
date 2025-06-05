#ifndef __NOTA_H
#define __NOTA_H

#include "Data.h"

class Nota {
    int valoare;
    Data data;
public:
    Nota(int, Data );
    int getValoare() const;
    Data getData() const;
    void afiseaza() const;
};

#endif