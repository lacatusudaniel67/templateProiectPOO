#pragma once
#include <vector>
#include "Eveniment.h"

class AgentieTicketing {
private:
    std::vector<Eveniment> evenimente;

public:
    AgentieTicketing();
    
    void adaugaEveniment(const Eveniment& ev);
    void afiseazaToateEvenimentele() const;
    
    Eveniment& getEveniment(size_t index);
    size_t getNumarEvenimente() const;
};