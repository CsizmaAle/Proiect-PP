#ifndef NOTA_H
#define NOTA_H

#include "Data.h"

class Nota {
    int valoare;
    Data data;
public:
    Nota(int nota, Data d);
    int getValoare() const;
    Data getData() const;
    void afiseaza() const;
};

#endif
