#pragma once
class StrategiePret {
public:
    // destructor virtual  care este obligatoriu cand folosim  polimorfism si virtual
    virtual ~StrategiePret() = default; 
    
    // metoda pur virtuala pe care fiecare clasa fiica o va suprascrie
    virtual double calculeaza(double pretBaza) const = 0;
};

class StrategieStudent : public StrategiePret {
public:
    double calculeaza(double pretBaza) const override {
        return pretBaza * 0.5;
    }
};

class StrategieEco : public StrategiePret {
public:
    double calculeaza(double pretBaza) const override {
        return pretBaza + 5.0;
    }
};

class StrategieEarlyBird : public StrategiePret {
public:
    double calculeaza(double pretBaza) const override {
        return pretBaza * 0.8; 
    }
};