#include "Locatie.h"
#include <iostream>

Locatie::Locatie() {
    this->numeSala = "Nedefinit";
    this->capacitateMaxima = 0;
    this->adresa = "Nedefinita";
}

Locatie::Locatie(const std::string& nume, int capacitate, const std::string& adr) {
    this->numeSala = nume;
    this->capacitateMaxima = capacitate;
    this->adresa = adr;
}

void Locatie::afiseazaLocatie() const {
    std::cout << "Sala: " << numeSala << " | Capacitate: " << capacitateMaxima << " locuri\n";
}

int Locatie::getCapacitate() const {
    return capacitateMaxima;
}