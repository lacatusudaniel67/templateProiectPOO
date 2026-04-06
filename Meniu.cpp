#include "Meniu.h"
#include "ExceptieTicketing.h"
#include "BiletStandard.h"
#include <iostream>
#include <string>

Meniu::Meniu() {}

void Meniu::afiseazaOptiuni() const {
    std::cout << "\n=== MENIU AGENTIE TICKETING ===\n";
    std::cout << "1. Creare: Adauga eveniment nou\n";
    std::cout << "2. Creare: Vinde bilet pentru un eveniment\n";
    std::cout << "3. Afisare: Arata toate evenimentele si biletele\n";
    std::cout << "4. Actualizare: Adauga un text la numele evenimentului\n";
    std::cout << "5. Stergere: Anuleaza (sterge) ultimul eveniment\n";
    std::cout << "0. Iesire\n";
    std::cout << "Alege o optiune: ";
}

void Meniu::adaugaEvenimentNou() {
    std::string nume, data;
    std::cout << "Nume eveniment: ";
    std::cin >> nume;
    std::cout << "Data eveniment: ";
    std::cin >> data;

    Eveniment evNou(nume, data);
    agentie.adaugaEveniment(evNou);
    std::cout << "Eveniment adaugat cu succes!\n";
}

void Meniu::vindeBilet() {
    if (agentie.getNumarEvenimente() == 0) {
        std::cout << "Nu exista evenimente! Adauga unul mai intai.\n";
        return;
    }

    int indexEveniment;
    std::cout << "Alege indexul evenimentului (de la 0): ";
    std::cin >> indexEveniment;

    try {
        Eveniment& ev = agentie.getEveniment(indexEveniment);

        double pret;
        std::cout << "Introdu pretul biletului: ";
        std::cin >> pret;
        if (pret <= 0) {
            throw ExceptieTicketing("Eroare: Pretul nu poate fi zero sau negativ!");
        }
        Bilet* biletNou = new BiletStandard(pret, 1, 1);
        ev.adaugaBilet(biletNou);
        std::cout << "Bilet vandut cu succes!\n";

    } catch (const ExceptieTicketing& e) {
        std::cout << "Exceptie prinsa: " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Eroare standard: " << e.what() << "\n";
    }
}

void Meniu::afiseazaBazaDeDate() const {
    if (agentie.getNumarEvenimente() == 0) {
        std::cout << "Baza de date este goala.\n";
    } else {
        agentie.afiseazaToateEvenimentele();
    }
}

void Meniu::actualizeazaEveniment() {
    if (agentie.getNumarEvenimente() > 0) {
        std::cout << "Actualizam primul eveniment cu date noi\n";
        Eveniment evActualizat("Festival_Modificat", "Azi");
        agentie.getEveniment(0) = evActualizat;
        std::cout << "Actualizare completa.\n";
    } else {
        std::cout << "Nu ai ce actualiza.\n";
    }
}

void Meniu::stergeUltimulEveniment() {
    std::cout << "Stergem ultimul eveniment adaugat...\n";
    if (agentie.getNumarEvenimente() > 0) {
        agentie.stergeUltimulEvenimentDinMemorie();
        std::cout << "Eveniment sters cu succes!\n";
    } else {
        std::cout << "Nu exista evenimente de sters.\n";
    }
}

void Meniu::ruleaza() {
    int optiune = -1;

    while (optiune != 0) {
        afiseazaOptiuni();
        if (!(std::cin >> optiune)) {
            break; 
        }

        if (optiune == 1) {
            adaugaEvenimentNou();
        } else if (optiune == 2) {
            vindeBilet();
        } else if (optiune == 3) {
            afiseazaBazaDeDate();
        } else if (optiune == 4) {
            actualizeazaEveniment();
        } else if (optiune == 5) {
            stergeUltimulEveniment();
        } else if (optiune == 0) {
            std::cout << "La revedere!\n";
        } else {
            std::cout << "Optiune invalida!\n";
        }
    }
}