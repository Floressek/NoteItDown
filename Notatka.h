#ifndef NOTATKA_H
#define NOTATKA_H

#include <string>

class Notatka {
private:
    std::string tytul;
    std::string tresc;

public:
    Notatka(const std::string &tytul, const std::string &tresc);

    std::string getTytul() const;

    std::string getTresc() const;

    void setTresc(const std::string &tresc);
};

#endif
