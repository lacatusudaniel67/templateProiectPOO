#pragma once
#include <string>
#include <stdexcept>

// includem clasa de baza si toate clasele derivate pe care factory ul le poate construi
#include "Bilet.h"
#include "BiletStandard.h"
#include "BiletVIP.h"
#include "BiletRedus.h"
#include "BiletAbonament.h"
#include "AbonamentVIP.h"

class BiletFactory {
public:
    // metoda este de tip static , nu trebuie sa instantiem factory ul(nu facem "new BiletFactory")
    // O vom apela direct: BiletFactory::creeazaBiletDinDB(...)
    static Bilet* creeazaBiletDinDB(const std::string& tip, double pret);
};