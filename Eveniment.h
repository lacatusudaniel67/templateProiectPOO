#pragma once
#include <string>
#include <vector>
#include "Bilet.h"

class Eveniment {
private:
    std::string numeEveniment;
    std::string data;
    std::vector<Bilet*> bileteVandute; // vector de pointeri pentru polimorfism 

public:
    Eveniment();
    Eveniment(const std::string& nume, const std::string& data);
    ~Eveniment();
    Eveniment(const Eveniment& other);
    Eveniment& operator=(const Eveniment& other);

    void adaugaBilet(Bilet* bilet);
    void afiseazaBilete() const;
    double calculeazaIncasariTotal() const;
};