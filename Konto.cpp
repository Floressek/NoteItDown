#include "Konto.h"

Konto::Konto(const std::string &login, const std::string &haslo) : login(login), haslo(haslo), zalogowany(false) {}

bool Konto::czyZalogowany() const {
    return zalogowany;
}

std::string Konto::getLogin() const {
    return login;
}

std::string Konto::getHaslo() const {
    return haslo;
}

void Konto::setZalogowany(bool value) {
    zalogowany = value;
}
