#include "Eveniment.h"
#include <iostream>

Eveniment::Eveniment() {
    this->numeEveniment = "Necunoscut";
    this->data = "Necunoscuta";
}

Eveniment::Eveniment(const std::string& nume, const std::string& data) {
    this->numeEveniment = nume;
    this->data = data;
}

Eveniment::~Eveniment() {
    for (size_t i = 0; i < bileteVandute.size(); i = i + 1) {
        delete bileteVandute[i];
    }
    bileteVandute.clear();
}

Eveniment::Eveniment(const Eveniment& other) {
    this->numeEveniment = other.numeEveniment;
    this->data = other.data;
}

Eveniment& Eveniment::operator=(const Eveniment& other) {
    if (this != &other) {
        this->numeEveniment = other.numeEveniment;
        this->data = other.data;
        
        for (size_t i = 0; i < bileteVandute.size(); i = i + 1) {
            delete bileteVandute[i];
        }
        bileteVandute.clear();
    }
    return *this;
}

void Eveniment::adaugaBilet(Bilet* bilet) {
    if (bilet != nullptr) {
        bileteVandute.push_back(bilet);
    }
}

void Eveniment::afiseazaBilete() const {
    std::cout << "Eveniment: " << numeEveniment << " din " << data << "\n";
    for (size_t i = 0; i < bileteVandute.size(); i = i + 1) {
        bileteVandute[i]->afiseazaDetalii(); 
    }
}
//polimorfismul  
double Eveniment::calculeazaIncasariTotal() const {
    double total = 0.0;
    for (size_t i = 0; i < bileteVandute.size(); i = i + 1) {
        total = total + bileteVandute[i]->calculeazaPretFinal(); 
    }
    return total;
}