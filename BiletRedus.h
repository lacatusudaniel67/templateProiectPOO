#pragma once
#include "Bilet.h"
#include <string>

class BiletRedus : public Bilet {
private:
    double procentReducere;
    std::string tipDocumentDoveditor;

public:
    BiletRedus();
    BiletRedus(double pret, double reducere, const std::string& document);
    ~BiletRedus() override;

    double calculeazaPretFinal() const override;
    void afiseazaDetalii() const override;
};