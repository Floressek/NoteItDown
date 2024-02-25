#ifndef FOLDER_H
#define FOLDER_H

#include <string>
#include "Notatka.h"

class Folder {
private:
    Notatka *notatki[10];
    std::string nazwa;

public:
    Folder(const std::string &nazwa);

    ~Folder();

    Notatka *utworzNotatke(const std::string &tytul, const std::string &tresc);

    Notatka **wyswietlNotatki();

    std::string getNazwa() const;

    void usunNotatke(Notatka *pNotatka);
};

#endif
