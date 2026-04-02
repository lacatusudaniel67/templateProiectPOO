#include "AgentieTicketing.h"
#include <iostream>
#include <stdexcept>

AgentieTicketing::AgentieTicketing() {}

void AgentieTicketing::adaugaEveniment(const Eveniment& ev) {
    evenimente.push_back(ev);
}

void AgentieTicketing::afiseazaToateEvenimentele() const {
    std::cout << "\nToate Evenimentele\n";
    for (size_t i = 0; i < evenimente.size(); i = i + 1) {
        std::cout << "[" << i << "] ";
        evenimente[i].afiseazaBilete();
    }
}

Eveniment& AgentieTicketing::getEveniment(size_t index) {
    if (index >= evenimente.size()) {
        throw std::out_of_range("index invalid!");
    }
    return evenimente[index];
}

size_t AgentieTicketing::getNumarEvenimente() const {
    return evenimente.size();
}