#include "Bilet.h"

int Bilet::contorId = 0; 

Bilet::Bilet() {
    contorId = contorId + 1;
    this->idBilet = contorId;
    this->pretDeBaza = 0.0;
}

Bilet::Bilet(double pret) {
    contorId = contorId + 1;
    this->idBilet = contorId;
    this->pretDeBaza = pret;
}

Bilet::~Bilet() {
    //destructor gol necesar pentru polimorfism
}

Bilet::Bilet(const Bilet& other) {
    //se genereaza un id  nou la copiere
    contorId = contorId + 1;
    this->idBilet = contorId;
    this->pretDeBaza = other.pretDeBaza;
}

Bilet& Bilet::operator=(const Bilet& other) {
    if (this != &other) {
        this->idBilet = other.idBilet; 
        this->pretDeBaza = other.pretDeBaza;
    }
    return *this;
}

void Bilet::afiseazaDetalii() const {
    std::cout << "Bilet ID: " << idBilet << " | Pret: " << pretDeBaza << " RON\n";
}

int Bilet::getContoareBilete() {
    return contorId;
}

double Bilet::getPretDeBaza() const {
    return pretDeBaza;
}

int Bilet::getId() const {
    return idBilet;
}