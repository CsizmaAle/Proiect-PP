#include "Nota.h"
#include "Data.h"
#include <iostream>
using namespace std;

Nota::Nota(int nota, Data d) : valoare(nota), data(d) {}

int Nota::getValoare() const {
    return valoare;
}

Data Nota::getData() const {
    return data;
}

void Nota::afiseaza() const {
    cout << "Nota: " << valoare << " | Data: ";
    data.afiseaza();
}