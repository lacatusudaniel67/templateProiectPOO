#pragma once
#include <exception>
#include <string>

class ExceptieTicketing : public std::exception {
private:
    std::string mesajEroare;

public:
    explicit ExceptieTicketing(const std::string& mesaj);
    
    // se suprascrie metoda what() pentru a afisa eroarea
    const char* what() const noexcept override;
};