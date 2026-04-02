#include "AbonamentVIP.h"
#include <iostream>

AbonamentVIP::AbonamentVIP() 
    : Bilet(), BiletVIP(), BiletAbonament() {
    this->turGhidatBackstage = false;
}

AbonamentVIP::AbonamentVIP(double pret, const std::string& pachet, bool lounge, int zile, bool turBackstage) 
    : Bilet(pret), BiletVIP(pret, pachet, lounge), BiletAbonament(pret, zile) {
    this->turGhidatBackstage = turBackstage;
}

AbonamentVIP::~AbonamentVIP() {}

double AbonamentVIP::calculeazaPretFinal() const {
    double pretFinal = pretDeBaza * numarZileValabilitate;
    pretFinal = pretFinal * 0.85;
    
    if (accesLounge == true) {
        pretFinal = pretFinal + 150.0;
    }
    if (turGhidatBackstage == true) {
        pretFinal = pretFinal + 200.0;
    }
    
    pretFinal = pretFinal + 100.0; // taxa extra
    return pretFinal;
}

void AbonamentVIP::afiseazaDetalii() const {
    Bilet::afiseazaDetalii(); 
    std::cout << "Abonament VIP -> Zile: " << numarZileValabilitate << " | Bauturi: " << pachetBauturi << "\n";
    
    if (turGhidatBackstage == true) {
        std::cout << "Are tur backstage.\n";
    }
}