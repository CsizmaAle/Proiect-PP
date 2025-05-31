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
    void afiseaza();
private:
    bool esteAnBisect(int an);
    int zileInLuna(int luna, int an);
};

#endif