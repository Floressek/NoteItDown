#include "Folder.h"
#include "Notatka.h"

#include <iostream>
#include <string>

Folder::Folder(const std::string &nazwa) : nazwa(nazwa) {
    for (auto &notatka: notatki) {
        notatka = nullptr;
    }
}

Folder::~Folder() {
    for (auto &notatka: notatki) {
        if (notatka != nullptr) {
            delete notatka;
        }
    }
}

Notatka *Folder::utworzNotatke(const std::string &tytul, const std::string &tresc) {
    for (auto &notatka: notatki) {
        if (notatka == nullptr) {
            notatka = new Notatka(tytul, tresc);
            return notatka;
        }
    }
    return nullptr;
}

Notatka **Folder::wyswietlNotatki() {
    for (auto &notatka: notatki) {
        if (notatka != nullptr) {
            // todo dodaj treść
            std::cout << "Notatka: " << notatka->getTytul() << ", " << notatka->getTresc() << std::endl;
        }
    }
    return notatki;
}

std::string Folder::getNazwa() const {
    return nazwa;
}

void Folder::usunNotatke(Notatka *pNotatka) {
    for (auto &notatka: notatki) {
        if (notatka == pNotatka) {
            delete notatka;
            notatka = nullptr;
        }
    }
}
