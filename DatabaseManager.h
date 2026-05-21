#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "sqlite3.h"
struct EvenimentData {
    int id;
    std::string nume;
    std::string data;
};
struct BiletData {
    std::string tip;
    double pret;
};
class DatabaseManager {
private:
    sqlite3* db;
    std::string dbName;
    void creeazaTabele();

public:
    //se foloseste explicit pentru a preveni conversiile accidentale de tip
    explicit DatabaseManager(const std::string& numeFisier);
    ~DatabaseManager();

    //CRUD de bază
    bool adaugaEveniment(const std::string& nume, const std::string& data);
    std::vector<EvenimentData> extrageToateEvenimentele();

    bool adaugaBilet(int evenimentId, const std::string& tip, double pret);
    std::vector<BiletData> extrageBiletePentruEveniment(int evenimentId);

    bool stergeUltimulEveniment();
    
    template <typename T>
    T extrageOValoare(const std::string& query);
};