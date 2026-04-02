#include "BiletAbonament.h"
#include <iostream>

BiletAbonament::BiletAbonament() : Bilet() {
    this->numarZileValabilitate = 1;
}

BiletAbonament::BiletAbonament(double pret, int zile) : Bilet(pret) {
    this->numarZileValabilitate = zile;
}

BiletAbonament::~BiletAbonament() {}

double BiletAbonament::calculeazaPretFinal() const {
    double pretTotal = pretDeBaza * numarZileValabilitate;
    double reducere = pretTotal * 0.10;
    return pretTotal - reducere;
}

void BiletAbonament::afiseazaDetalii() const {
    Bilet::afiseazaDetalii();
    std::cout << "Abonament -> Zile: " << numarZileValabilitate << "\n";
}