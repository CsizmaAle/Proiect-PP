#ifndef MATERIE_H
#define MATERIE_H

#include <string>
#include <vector>
#include "Nota.h"
#include "Absenta.h"

using namespace std;

class Materie {
    string denumire;
    vector<Nota> note;
    vector<Absenta> absente;

public:
    Materie(string nume);

    void adaugaNota(const Nota&);
    void stergeNota(const Nota&);

    void adaugaAbsenta(const Absenta&);

    void afiseazaNote() const;
    void afiseazaNumarAbsente() const;
    void afiseazaAbsente() const;
    string getDenumire() const;

};

#endif