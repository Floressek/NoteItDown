#include "KontoAdministratora.h"
#include "Notatka.h"


KontoAdministratora::KontoAdministratora(const std::string &login, const std::string &haslo) : Konto(login, haslo) {}

void KontoAdministratora::usunNotatke(Folder* folder, Notatka *notatka) {
    folder->usunNotatke(notatka);
}

void KontoAdministratora::usunFolder(KontoUzytkownika* konto, Folder *folder) {
    konto->usunFolder(folder);
}

std::string KontoAdministratora::getType() {
    return "admin";
}
