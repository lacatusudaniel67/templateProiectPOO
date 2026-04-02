#include "Client.h"
#include <iostream>

Client::Client() {
    this->nume = "Anonim";
    this->email = "N/A";
}

Client::Client(const std::string& n, const std::string& e) {
    this->nume = n;
    this->email = e;
}

void Client::adaugaInIstoric(int idBilet) {
    istoricIdBilete.push_back(idBilet);
}

void Client::afiseazaClient() const {
    std::cout << "Client: " << nume << " | Bilete cumparate: " << istoricIdBilete.size() << "\n";
}