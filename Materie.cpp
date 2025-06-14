
#include "Materie.h"
#include <iostream>
#include <algorithm>

using namespace std;

Materie::Materie(string nume) : denumire(nume) {}

void Materie::adaugaNota(const Nota& n) {
    note.push_back(n);
}

void Materie::stergeNota(const Nota& n) {
    note.erase(remove_if(note.begin(), note.end(), [&](const Nota& x) {
        return x.getValoare() == n.getValoare() &&
            x.getData().getZi() == n.getData().getZi() &&
            x.getData().getLuna() == n.getData().getLuna() &&
            x.getData().getAn() == n.getData().getAn();
        }), note.end());
}

void Materie::adaugaAbsenta(const Absenta& a) {
    absente.push_back(a);
}


void Materie::afiseazaNote() const {
    cout << "Note: ";
    for (const auto& n : note)
        n.afiseaza();
    cout << endl;
}

void Materie::afiseazaNumarAbsente() const {
    cout << "Numar absente la " << denumire << ": " << absente.size() << endl;
}

string Materie::getDenumire() const {
    return denumire;
}


void Materie::afiseazaAbsente() const 
{
    cout << "Absente: ";
    for (const auto &a : absente)
    {
        a.afisare();
    }
    cout << endl;
}

vector<Nota> Materie::getNote() const {
    return note;
}

vector<Absenta>& Materie::getAbsente() {
    return absente;
}