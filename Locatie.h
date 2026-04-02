#pragma once
#include <string>

class Locatie {
private:
    std::string numeSala;
    int capacitateMaxima;
    std::string adresa;

public:
    Locatie();
    Locatie(const std::string& nume, int capacitate, const std::string& adresa);

    void afiseazaLocatie() const;
    int getCapacitate() const;
};