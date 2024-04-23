#ifndef KONTO_ADMINISTRATORA_H
#define KONTO_ADMINISTRATORA_H

#include "Konto.h"
#include "Folder.h"
#include "KontoUzytkownika.h"

class KontoAdministratora : public Konto {
public:
    KontoAdministratora(const std::string &login, const std::string &haslo);

    void usunNotatke(Folder *folder, Notatka *notatka);

    void usunFolder(KontoUzytkownika* konto, Folder *folder);

    virtual std::string getType() override;
};

#endif
