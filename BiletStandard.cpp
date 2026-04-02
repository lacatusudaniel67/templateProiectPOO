#include "BiletStandard.h"
#include <iostream>

BiletStandard::BiletStandard() : Bilet() {
    this->rand = 0;
    this->loc = 0;
}

BiletStandard::BiletStandard(double pret, int r, int l) : Bilet(pret) {
    this->rand = r;
    this->loc = l;
}

BiletStandard::~BiletStandard() {}

double BiletStandard::calculeazaPretFinal() const {
    return pretDeBaza;
}

void BiletStandard::afiseazaDetalii() const {
    Bilet::afiseazaDetalii();
    std::cout << "Standard -> Rand: " << rand << " | Loc: " << loc << "\n";
}