#include "AgentieTicketing.h"
#include "BiletFactory.h"
#include <iostream>
#include <stdexcept>

AgentieTicketing::AgentieTicketing() {
    dbManager = new DatabaseManager("agentie.db");
    
    std::vector<EvenimentData> dateSalvate = dbManager->extrageToateEvenimentele();
    
    for (size_t i = 0; i < dateSalvate.size(); i = i + 1) {
        Eveniment ev(dateSalvate[i].nume, dateSalvate[i].data);
        std::vector<BiletData> bileteSalvate = dbManager->extrageBiletePentruEveniment(dateSalvate[i].id);
        
        for (size_t j = 0; j < bileteSalvate.size(); j = j + 1) {
            // factory ul recreeaza biletul pe baza textului din SQLite
            Bilet* biletRecuperat = BiletFactory::creeazaBiletDinDB(bileteSalvate[j].tip, bileteSalvate[j].pret);
            ev.adaugaBilet(biletRecuperat); 
        }
        evenimente.push_back(ev);
    }
}
AgentieTicketing::~AgentieTicketing() {
    delete dbManager;
}

void AgentieTicketing::adaugaEveniment(const Eveniment& ev) {
    // salvam in memoria RAM
    evenimente.push_back(ev);
    
    // salvam permanent in baza de date SQLite
    dbManager->adaugaEveniment(ev.getNume(), ev.getData());
}


void AgentieTicketing::afiseazaToateEvenimentele() const {
    std::cout << "\nToate Evenimentele\n";
    for (size_t i = 0; i < evenimente.size(); i = i + 1) {
        std::cout << "[" << i << "] ";
        evenimente[i].afiseazaBilete();
    }
}

void AgentieTicketing::stergeUltimulEvenimentDinMemorie() {
    if (evenimente.size() > 0) {
        evenimente.pop_back();
        dbManager->stergeUltimulEveniment(); 
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
void AgentieTicketing::vindeBiletLaEveniment(size_t indexEveniment, Bilet* bilet, const std::string& tip, double pret) {
    if (indexEveniment >= evenimente.size()) {
        throw std::out_of_range("Index invalid!");
    }
    
    // salvez biletul in memoria RAM (in vectorul evenimentului ales)
    evenimente[indexEveniment].adaugaBilet(bilet);

    int idEvenimentDinDB = indexEveniment + 1;
    
    //trimit textul si pretul catre SQLite pentru salvare permanenta
    dbManager->adaugaBilet(idEvenimentDinDB, tip, pret);
}