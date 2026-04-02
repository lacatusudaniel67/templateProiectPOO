#pragma once
#include "BiletVIP.h"
#include "BiletAbonament.h"

class AbonamentVIP : public BiletVIP, public BiletAbonament { // Moștenire multiplă 
private:
    bool turGhidatBackstage;

public:
    AbonamentVIP();
    AbonamentVIP(double pret, const std::string& pachet, bool lounge, int zile, bool turBackstage);
    ~AbonamentVIP() override;

    double calculeazaPretFinal() const override;
    void afiseazaDetalii() const override;
};