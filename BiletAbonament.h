#pragma once
#include "Bilet.h"

class BiletAbonament : virtual public Bilet { 
protected:
    int numarZileValabilitate;

public:
    BiletAbonament();
    BiletAbonament(double pret, int zile);
    ~BiletAbonament() override;

    double calculeazaPretFinal() const override;
    void afiseazaDetalii() const override;
};