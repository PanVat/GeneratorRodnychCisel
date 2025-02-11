#ifndef RODNECISLO_H
#define RODNECISLO_H

#include <string>

using std::string;

class RodneCislo {
private:
    /* Ukládá rodné číslo jako řetězec */
    string rodneCislo;
    /* Data načtená od uživatele */
    int den, mesic, rok;
    int pohlavi;
    int trojcisli;

    /* Metody, které kontrolují platnost načtených dat */
    static bool jePlatnyDen(int d) ;

    static bool jePlatnyMesic(int m) ;

    static bool jePlatnyRok(int r) ;

    static bool jePlatnePohlavi(int p) ;

    static bool jePlatneTrojcisli(int t) ;

    /* Nastaví rodné číslo do formátu 'rrmmdd/xxxx' */
    void nastavRodneCislo();

    /* Obnoví neplatný uživatelský vstup */
    static void vycistiVstup();

public:
    /* Výchozí konstruktor */
    RodneCislo();

    /* Výchozí destruktor */
    ~RodneCislo();

    /* Metody, které nastaví uživatelské hodnoty do datových položek */
    bool nastavDen(int d);

    bool nastavMesic(int m);

    bool nastavRok(int r);

    bool nastavPohlavi(int p);

    bool nastavTrojcisli(int t);

    /* Vrací hotové rodné číslo */
    string vratRodneCislo();

    /* Načte uživatelská data do soukromých datových položek */
    void nactiDen();

    void nactiMesic();

    void nactiRok();

    void nactiPohlavi();

    void nactiTrojcisli();
};

#endif