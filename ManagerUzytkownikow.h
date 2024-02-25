#ifndef MANAGER_UZYTKOWNIKOW_H
#define MANAGER_UZYTKOWNIKOW_H

#include <string>

#include "KontoUzytkownika.h"
#include "KontoAdministratora.h"
#include "Folder.h"
#include "Notatka.h"

class ManagerUzytkownikow {
private:
    KontoUzytkownika *kontaUzytkownikow[100];
    KontoAdministratora *kontaAdministratorow[10];

    static ManagerUzytkownikow *instance;

public:
    ManagerUzytkownikow();

    ~ManagerUzytkownikow();

    static ManagerUzytkownikow *getInstance();

    KontoAdministratora *wyszukajDostepnegoAdministratora();

    void przydzielUsuniecieFolderu(KontoUzytkownika* konto, Folder *folder);

    void przydzielUsuniecieNotatki(Folder *folder, Notatka *notatka);

    KontoUzytkownika *utworzUzytkownika(const std::string &login, const std::string &haslo);

    KontoAdministratora *utworzAdministratora(const std::string &login, const std::string &haslo);

    void wyloguj(Konto *konto);

    Konto *zaloguj(const std::string &login, const std::string &haslo);

    Konto *utworzKonto(const std::string &login, const std::string &haslo, const std::string &rodzaj);
};

#endif
