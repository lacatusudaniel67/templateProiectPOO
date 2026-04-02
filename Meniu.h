#pragma once
#include "AgentieTicketing.h"

class Meniu {
private:
    AgentieTicketing agentie;
    void afiseazaOptiuni() const;
    void adaugaEvenimentNou();
    void vindeBilet();
    void afiseazaBazaDeDate() const;
    void actualizeazaEveniment();
    void stergeUltimulEveniment();

public:
    Meniu();
    void ruleaza();
};