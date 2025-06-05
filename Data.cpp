#include <iostream>
#include "Data.h"
using namespace std;
/*
 Constructorul clasei Data valideaza si seteaza ziua, luna si anul unui obiect de tip Data
 Verifica daca luna este intre 1 si 12 si daca ziua este valida in luna si anul respectiv
 Daca datele nu sunt valide, sunt aruncate exceptii corespunzatoare
 :param z: ziua (1-31)
 :param l: luna (1-12)
 :param a: anul
*/
Data::Data(int z, int l, int a)
{
    if (l > 12 || l < 1)
        throw "Luna invalida";
    else
        luna = l;
    if (z > zileInLuna(l, a) || z < 1)
        throw "Zi invalida";
    else
        zi = z;
    an = a;
}
/*
Metoda clasei Data verifica daca un an dat este bisect
 :param an: anul care trebuie verificat
 :return: true daca anul este bisect, false altfel
*/
bool Data::esteAnBisect(int an) {
    return (an % 4 == 0);
}
/*
Metoda clasei Data calculeaza numarul de zile ale unei luni pentru un an dat
 Daca luna este februarie si anul este bisect, se returneaza 29 de zile
 Altfel, se returneaza numarul standard de zile pentru luna respectiva
 :param luna: luna (1-12)
 :param an: anul
 :return: numarul de zile al lunii
*/
int Data::zileInLuna(int luna, int an) {
    static int zile[] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; ///static pentru a se crea o singura data, nu la fiecare apelare
    if (luna == 2 && esteAnBisect(an)) return 29;
    return zile[luna - 1]; ///deoarece se intampla indexarea de la 0
}


/*
 Metoda care returneaza ziua din data curenta
 :return: ziua (intreg)
*/
int Data::getZi()
{
    return zi;
}


int Data::getLuna()
{
    const char luni[12][15] = {
        "Ianuarie", "Februarie", "Martie", "Aprilie",
        "Mai", "Iunie", "Iulie", "August",
        "Septembrie", "Octombrie", "Noiembrie", "Decembrie"
    };
    //cout<< luni[luna-1]<<" ";
    return luna;
}

int Data::getAn()
{
    return an;
}

/*
 Metoda care afiseaza data curenta in formatul dd/mm/yyyy
 Daca ziua sau luna este mai mica decat 10, se adauga un 0 in fata pentru a pastra formatul corect
*/
void Data::afiseaza() const 
{
    cout << (zi < 10 ? "0" : "") << zi << "/"
        << (luna < 10 ? "0" : "") << luna << "/"
        << an << endl;
}

bool Data::operator==(const Data& d)const
{
    return zi == d.zi && luna == d.luna && an == d.an;
}