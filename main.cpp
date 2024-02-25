#include <iostream>
#include "Folder.h"
#include "Notatka.h"
#include "ManagerUzytkownikow.h"
#include "KontoAdministratora.h"
#include "KontoUzytkownika.h"
#include "Konto.h"

int main() {
    auto mu = ManagerUzytkownikow::getInstance();

    auto adm = mu->utworzAdministratora("admin1", "pa1");
    auto u = mu->utworzUzytkownika("user1", "pu1");

    mu->zaloguj("admin1", "pa1");
    auto logged = mu->zaloguj("user1", "pu1");

    if (logged == nullptr) {
        // todo invalid credentials
    }

    if (logged->getType() == "user") {
        std::cout << "todo user code" << std::endl;
        KontoUzytkownika* user = (KontoUzytkownika*) logged;

        auto n1 = user->utworzNotatke("tyt1", "tre1", "fu1");
        auto n2 = user->utworzNotatke("tyt2", "tre2", "fu1");
        auto n3 = user->utworzNotatke("tyt1.1", "tre1.1", "fu1.1");
        user->wyswietlFoldery();
        auto f1 = user->wyszukajFolder("fu1");
        if (f1 != nullptr) {
            f1->wyswietlNotatki();
        }
        user->edytujNotatke(n2, "tre2-updated");
        f1->wyswietlNotatki();
        user->zglosUsuniecieNotatki(f1, n2);
        f1->wyswietlNotatki();
        user->zglosUsuniecieFolderu(f1);
        user->wyswietlFoldery();
    }

    mu->wyloguj(logged);

    delete mu;

    return 0;
}
