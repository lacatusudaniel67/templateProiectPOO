#pragma once
#include "Bilet.h"

class BiletStandard : public Bilet {
private:
    int rand;
    int loc;

public:
    BiletStandard();
    BiletStandard(double pret, int rand, int loc);
    ~BiletStandard() override;

    double calculeazaPretFinal() const override;
    void afiseazaDetalii() const override;
};