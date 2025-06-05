#ifndef __DATA_H
#define __DATA_H
#include <iostream>
class Data {
    int zi, luna, an;
public:
    Data(int z, int l, int a);
    int getZi();
    int getLuna();
    int getAn();
    void afiseaza() const;
    bool operator==(const Data&)const;
private:
    bool esteAnBisect(int an);
    int zileInLuna(int luna, int an);
};

#endif