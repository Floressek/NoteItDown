#ifndef KONTO_UZYTKOWNIKA_H
#define KONTO_UZYTKOWNIKA_H

#include "Konto.h"
#include "Folder.h"

class KontoUzytkownika : public Konto {
private:
    Folder *foldery[10];

public:
    KontoUzytkownika(const std::string &login, const std::string &haslo);

    ~KontoUzytkownika();

    Notatka *utworzNotatke(const std::string &tytul, const std::string &tresc, const std::string &nazwaFolderu);

    void edytujNotatke(Notatka *notatka, const std::string &nowaTresc);

    void zglosUsuniecieFolderu(Folder *folder);

    void zglosUsuniecieNotatki(Folder *folder, Notatka *notatka);

    Folder **wyswietlFoldery();

    Notatka **wyswietlNotatki(Folder *folder);

    Folder *wyszukajFolder(const std::string &nazwa);

    Folder *utworzFolder(const std::string &nazwa);

    void usunFolder(Folder* folder);

    virtual std::string getType() override;
};

#endif
