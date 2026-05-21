#include "BiletFactory.h"

Bilet* BiletFactory::creeazaBiletDinDB(const std::string& tip, double pret) {
    if (tip == "STANDARD") {
        // am pus 1, 1 (rand, loc) implicite daca nu le salvam si pe ele in baza de date
        return new BiletStandard(pret, 1, 1); 
    } 
    else if (tip == "VIP") {
        // am pus true pentru acces lounge
        return new BiletVIP(pret, "Pachet VIP", true); 
    } 
    else if (tip == "REDUS") {
        // am pus 0.5 pentru reducerea de 50%
        return new BiletRedus(pret, 0.5, "Elev/Student"); 
    }
    else if (tip == "ABONAMENT_VIP") {
        // parametri pret, pachet, lounge, zile, turBackstage
        return new AbonamentVIP(pret, "Premium", true, 3, true); 
    }
    // daca in baza de date ajunge un cuvant gresit
    throw std::invalid_argument("Tip de bilet necunoscut in baza de date: " + tip);
}