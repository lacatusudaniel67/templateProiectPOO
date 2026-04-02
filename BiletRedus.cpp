#include "BiletRedus.h"
#include <iostream>

BiletRedus::BiletRedus() : Bilet() {
    this->procentReducere = 0.0;
    this->tipDocumentDoveditor = "N/A";
}

BiletRedus::BiletRedus(double pret, double reducere, const std::string& document) : Bilet(pret) {
    this->procentReducere = reducere;
    this->tipDocumentDoveditor = document;
}

BiletRedus::~BiletRedus() {}

double BiletRedus::calculeazaPretFinal() const {
    double sumaRedusa = (pretDeBaza * procentReducere) / 100.0;
    return pretDeBaza - sumaRedusa;
}

void BiletRedus::afiseazaDetalii() const {
    Bilet::afiseazaDetalii();
    std::cout << "Redus -> Reducere: " << procentReducere << "% | Document: " << tipDocumentDoveditor << "\n";
}