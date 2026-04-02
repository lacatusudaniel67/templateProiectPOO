#pragma once
#include "Bilet.h"
#include <string>

class BiletVIP : virtual public Bilet { 
protected:
    std::string pachetBauturi;
    bool accesLounge;

public:
    BiletVIP();
    BiletVIP(double pret, const std::string& pachet, bool lounge);
    ~BiletVIP() override;

    // polimorfism-suprascriem metodele din clasa de baza 
    double calculeazaPretFinal() const override; 
    void afiseazaDetalii() const override;
};