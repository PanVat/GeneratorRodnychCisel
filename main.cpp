#include <iostream>
#include <limits>
#include "RodneCislo.h"

int main() {
    using std::cout, std::cin, std::endl;
    RodneCislo rodneCislo;
    string opakovat;

    do {
        cout << "Generovani fiktivniho rodneho cisla" << endl;
        cout << "-----------------------------------" << endl << endl;

        /* Získá data od uživatele */
        rodneCislo.nactiRok();
        rodneCislo.nactiMesic();
        rodneCislo.nactiDen();
        rodneCislo.nactiPohlavi();
        rodneCislo.nactiTrojcisli();

        /* Vypíše hotové rodné číslo */
        cout << "Bylo vytvoreno validni rodne cislo: " << rodneCislo.vratRodneCislo() << endl << endl;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        /* Požádá uživatele o opakování */
        cout << "Pro opakovane zadani rodneho cisla stiskni Enter, pro ukonceni jiny znak: ";

        std::getline(cin, opakovat);
        /* Pokud "je zmáčknutý Enter" (řetězec je prázdný), program se ukončí */
    } while (opakovat.empty());

    cout << "\nDekuji za pouziti programu, preji hezky den!" << endl;
    return 0;
}
