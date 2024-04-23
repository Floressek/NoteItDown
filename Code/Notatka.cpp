#include "Notatka.h"

Notatka::Notatka(const std::string &tytul, const std::string &tresc) : tytul(tytul), tresc(tresc) {}

std::string Notatka::getTytul() const {
    return tytul;
}

std::string Notatka::getTresc() const {
    return tresc;
}

void Notatka::setTresc(const std::string &tresc) {
    this->tresc = tresc;
}
