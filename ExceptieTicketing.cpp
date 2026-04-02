#include "ExceptieTicketing.h"

ExceptieTicketing::ExceptieTicketing(const std::string& mesaj) {
    this->mesajEroare = mesaj;
}

const char* ExceptieTicketing::what() const noexcept {
    return mesajEroare.c_str();
}