#pragma once
#include <iostream>

class Bilet {
private:
    static int contorId; // membru static    

protected:
    int idBilet;
    double pretDeBaza;

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
};