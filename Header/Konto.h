#ifndef KONTO_H
#define KONTO_H

#include <string>

class Konto {
private:
    std::string login;
    std::string haslo;
    bool zalogowany;

public:
    Konto(const std::string &login, const std::string &haslo);

    bool czyZalogowany() const;

    std::string getLogin() const;

    std::string getHaslo() const;

    void setZalogowany(bool value);

    virtual std::string getType() = 0;
};

#endif
