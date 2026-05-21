#pragma once
#include <vector>
#include "Eveniment.h"
#include "DatabaseManager.h"

class AgentieTicketing {
private:
    std::vector<Eveniment> evenimente;
    DatabaseManager* dbManager;

public:
    AgentieTicketing();
    ~AgentieTicketing();
    void adaugaEveniment(const Eveniment& ev);
    void afiseazaToateEvenimentele() const;
    void stergeUltimulEvenimentDinMemorie();
    Eveniment& getEveniment(size_t index);
    size_t getNumarEvenimente() const;
    void vindeBiletLaEveniment(size_t indexEveniment, Bilet* bilet, const std::string& tip, double pret);
};