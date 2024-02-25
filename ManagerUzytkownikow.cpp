#include "ManagerUzytkownikow.h"
#include "KontoUzytkownika.h"
#include "KontoAdministratora.h"
#include "Folder.h"
#include "Notatka.h"
#include "Konto.h"

ManagerUzytkownikow* ManagerUzytkownikow::instance = new ManagerUzytkownikow();

ManagerUzytkownikow::ManagerUzytkownikow() {
    for (auto &kontoUzytkownika: kontaUzytkownikow) {
        kontoUzytkownika = nullptr;
    }
    for (auto &kontoAdministratora: kontaAdministratorow) {
        kontoAdministratora = nullptr;
    }
}

ManagerUzytkownikow::~ManagerUzytkownikow() {
    for (auto &kontoUzytkownika: kontaUzytkownikow) {
        if (kontoUzytkownika != nullptr) {
            delete kontoUzytkownika;
        }
    }
    for (auto &kontoAdministratora: kontaAdministratorow) {
        if (kontoAdministratora != nullptr) {
            delete kontoAdministratora;
        }
    }
}

ManagerUzytkownikow* ManagerUzytkownikow::getInstance() {
    return instance;
}

KontoAdministratora* ManagerUzytkownikow::wyszukajDostepnegoAdministratora() {
    for (auto &kontoAdministratora: kontaAdministratorow) {
        if (kontoAdministratora != nullptr && kontoAdministratora->czyZalogowany()) {
            return kontoAdministratora;
        }
    }
    return nullptr;
}

void ManagerUzytkownikow::przydzielUsuniecieFolderu(KontoUzytkownika* konto, Folder *folder) {
    KontoAdministratora* kontoAdministratora = wyszukajDostepnegoAdministratora();
    if (kontoAdministratora == nullptr) {
        return;
    }
    kontoAdministratora->usunFolder(konto, folder);
}

void ManagerUzytkownikow::przydzielUsuniecieNotatki(Folder *folder, Notatka* notatka) {
    KontoAdministratora* kontoAdministratora = wyszukajDostepnegoAdministratora();
    if (kontoAdministratora == nullptr) {
        return;
    }
    kontoAdministratora->usunNotatke(folder, notatka);
}

KontoUzytkownika* ManagerUzytkownikow::utworzUzytkownika(const std::string &login, const std::string &haslo) {
    for (auto &kontoUzytkownika: kontaUzytkownikow) {
        if (kontoUzytkownika == nullptr) {
            kontoUzytkownika = new KontoUzytkownika(login, haslo);
            return kontoUzytkownika;
        }
    }
    return nullptr;
}

KontoAdministratora* ManagerUzytkownikow::utworzAdministratora(const std::string &login, const std::string &haslo) {
    for (auto &kontoAdministratora: kontaAdministratorow) {
        if (kontoAdministratora == nullptr) {
            kontoAdministratora = new KontoAdministratora(login, haslo);
            return kontoAdministratora;
        }
    }
    return nullptr;
}

void ManagerUzytkownikow::wyloguj(Konto* konto) {
    konto->setZalogowany(false);
}

Konto* ManagerUzytkownikow::zaloguj(const std::string &login, const std::string &haslo) {
    for (auto &konto: kontaUzytkownikow) {
        if (konto != nullptr) {
            if (konto->getLogin() == login && konto->getHaslo() == haslo) {
                konto->setZalogowany(true);
                return konto;
            }
        }
    }
    for (auto &konto: kontaAdministratorow) {
        if (konto != nullptr) {
            if (konto->getLogin() == login && konto->getHaslo() == haslo) {
                konto->setZalogowany(true);
                return konto;
            }
        }
    }
    return nullptr;
}

Konto* ManagerUzytkownikow::utworzKonto(const std::string &login, const std::string &haslo, const std::string &rodzaj) {
    if (rodzaj == "uzytkownik") {
        return utworzUzytkownika(login, haslo);
    } else if (rodzaj == "administrator") {
        return utworzAdministratora(login, haslo);
    }
    return nullptr;
}
