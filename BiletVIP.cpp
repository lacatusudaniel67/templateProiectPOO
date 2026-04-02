#include "BiletVIP.h"
#include <iostream>

BiletVIP::BiletVIP() : Bilet() {
    this->pachetBauturi = "Standard";
    this->accesLounge = false;
}

BiletVIP::BiletVIP(double pret, const std::string& pachet, bool lounge) : Bilet(pret) {
    this->pachetBauturi = pachet;
    this->accesLounge = lounge;
}

BiletVIP::~BiletVIP() {}

double BiletVIP::calculeazaPretFinal() const {
    double pretFinal = pretDeBaza + 50.0; // taxa VIP de baza
    
    if (accesLounge == true) {
        pretFinal = pretFinal + 150.0;
    }
    
    return pretFinal;
}

void BiletVIP::afiseazaDetalii() const {
    Bilet::afiseazaDetalii();
    std::cout << "VIP -> Bauturi: " << pachetBauturi << " | Acces Lounge: ";
    if (accesLounge == true) {
        std::cout << "Da\n";
    } else {
        std::cout << "Nu\n";
    }
}