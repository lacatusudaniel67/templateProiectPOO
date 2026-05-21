#pragma once
#include <iostream>
#include "StrategiePret.h"

class Bilet {
private:
    static int contorId; // membru static    

protected:
    int idBilet;
    double pretDeBaza;
    StrategiePret* strategie =nullptr;
public:
    Bilet();
    Bilet(double pret);
    virtual ~Bilet(); // destructorul trebuie sa fie virtual pentru polimorfism 
    Bilet(const Bilet& other);
    Bilet& operator=(const Bilet& other);

    // metoda virtuala pura face clasa sa fie abstracta 
    virtual double calculeazaPretFinal() const = 0;
    
    virtual void afiseazaDetalii() const;

    static int getContoareBilete(); // metoda statica
    double getPretDeBaza() const;
    int getId() const;
    //seteaza strategia noua la runtime
    void setStrategie(StrategiePret* nouaStrategie) {
        strategie = nouaStrategie;
    }

    // functie pe care o vor folosi clasele derivate pentru a aplica reducerea sau taxa  
    double aplicaStrategie(double pretCurent) const {
        if (strategie != nullptr) {
            return strategie->calculeaza(pretCurent);
        }
        return pretCurent;
    }
};