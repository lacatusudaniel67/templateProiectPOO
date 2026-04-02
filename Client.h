#pragma once
#include <string>
#include <vector>

class Client {
private:
    std::string nume;
    std::string email;
    std::vector<int> istoricIdBilete; // se stocheaza obiecte in vector

public:
    Client();
    Client(const std::string& nume, const std::string& email);

    void adaugaInIstoric(int idBilet);
    void afiseazaClient() const;
};