#include "KontoUzytkownika.h"
#include "ManagerUzytkownikow.h"
#include "KontoAdministratora.h"
#include "Folder.h"
#include "Notatka.h"

#include <iostream>

KontoUzytkownika::KontoUzytkownika(const std::string &login, const std::string &haslo) : Konto(login, haslo) {
    for (auto &folder: foldery) {
        folder = nullptr;
    }
}

KontoUzytkownika::~KontoUzytkownika() {
    for (auto &folder: foldery) {
        if (folder != nullptr) {
            delete folder;
        }
    }
}

Notatka *KontoUzytkownika::utworzNotatke(const std::string &tytul, const std::string &tresc, const std::string &nazwaFolderu) {
    Folder* folder = wyszukajFolder(nazwaFolderu);
    if (folder == nullptr) {
        folder = utworzFolder(nazwaFolderu);
    }

    if (folder == nullptr) {
        return nullptr;
    }

    return folder->utworzNotatke(tytul, tresc);
}

void KontoUzytkownika::edytujNotatke(Notatka *notatka, const std::string &nowaTresc) {
    if (notatka != nullptr) {
        notatka->setTresc(nowaTresc);
    }
}

void KontoUzytkownika::zglosUsuniecieFolderu(Folder *folder) {
    ManagerUzytkownikow* managerUzytkownikow = ManagerUzytkownikow::getInstance();
    managerUzytkownikow->przydzielUsuniecieFolderu(this, folder);
}

void KontoUzytkownika::zglosUsuniecieNotatki(Folder* folder, Notatka *notatka) {
    ManagerUzytkownikow* managerUzytkownikow = ManagerUzytkownikow::getInstance();
    managerUzytkownikow->przydzielUsuniecieNotatki(folder, notatka);
}

Folder **KontoUzytkownika::wyswietlFoldery() {
    for (auto &folder: foldery) {
        if (folder != nullptr) {
            std::cout << "Folder: " << folder->getNazwa() << std::endl;
        }
    }
    return foldery;
}

Notatka **KontoUzytkownika::wyswietlNotatki(Folder *folder) {
    return folder->wyswietlNotatki();
}

Folder *KontoUzytkownika::wyszukajFolder(const std::string &nazwa) {
    for (auto &folder: foldery) {
        if (folder != nullptr && folder->getNazwa() == nazwa) {
            return folder;
        }
    }
    return nullptr;
}

Folder *KontoUzytkownika::utworzFolder(const std::string &nazwa) {
    for (auto &folder: foldery) {
        if (folder == nullptr) {
            folder = new Folder(nazwa);
            return folder;
        }
    }
    return nullptr;
}

void KontoUzytkownika::usunFolder(Folder* pFolder) {
    for (auto &folder: foldery) {
        if (folder == pFolder) {
            delete folder;
            folder = nullptr;
        }
    }
}

std::string KontoUzytkownika::getType() {
    return "user";
}