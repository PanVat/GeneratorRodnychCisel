#include "RodneCislo.h"
#include <iostream>
#include <limits>

using std::cout, std::cin, std::endl;

/* Výchozí konstruktor */
RodneCislo::RodneCislo() {
    this->den = 1;
    this->mesic = 1;
    this->rok = 2000;
    this->pohlavi = 0;
    this->trojcisli = 0;
}

/* Výchozí destruktor */
RodneCislo::~RodneCislo() = default;

/* Setter pro den */
bool RodneCislo::nastavDen(int d) {
    if (jePlatnyDen(d)) {
        this->den = d;
        return true;
    }
    return false;
}

/* Setter pro měsíc */
bool RodneCislo::nastavMesic(int m) {
    if (jePlatnyMesic(m)) {
        this->mesic = m;
        return true;
    }
    return false;
}

/* Setter pro rok */
bool RodneCislo::nastavRok(int r) {
    if (jePlatnyRok(r)) {
        this->rok = r;
        return true;
    }
    return false;
}

/* Setter pro pohlaví */
bool RodneCislo::nastavPohlavi(int p) {
    if (jePlatnePohlavi(p)) {
        this->pohlavi = p;
        return true;
    }
    return false;
}

/* Setter pro trojčíslí */
bool RodneCislo::nastavTrojcisli(int t) {
    if (jePlatneTrojcisli(t)) {
        this->trojcisli = t;
        return true;
    }
    return false;
}

/* Kontrola platnosti dnu v rozsahu 1 až 31 */
bool RodneCislo::jePlatnyDen(int d) {
    return d >= 1 && d <= 31;
}

/* Kontrola platnosti měsíce v rozsahu 1 až 12 */
bool RodneCislo::jePlatnyMesic(int m) {
    return m >= 1 && m <= 12;
}

/* Kontrola platnosti roku v rozsahu 1954 až 2053 */
bool RodneCislo::jePlatnyRok(int r) {
    return r >= 1954 && r <= 2053;
}

/* Kontrola platnosti pohlaví s hodnotama 0 a 1 */
bool RodneCislo::jePlatnePohlavi(int p) {
    return p >= 0 && p <= 1;
}

/* Kontrola platnosti trojčíslí s maximálně 3 ciframi */
bool RodneCislo::jePlatneTrojcisli(int t) {
    return t >= 0 && t <= 999;
}

/* Vyrobí rodné číslo a uloží ho do datové položky 'rodneCislo' */
void RodneCislo::nastavRodneCislo() {
    using namespace std;
    rodneCislo = "";
    int mesicHodnota;
    int cisloBezLomitka;
    int zbytekRodnehoCisla;

    /* Vyextrahuje první poslední 2 cifry roku */
    rodneCislo += to_string(rok).substr(2, 2);
    /* Přidá k měsíci 50, pokud se jedná o ženu */
    mesicHodnota = (pohlavi == 0) ? mesic + 50 : mesic;
    /* Pokud je měsíc menší než deset, přidá se 0 */
    rodneCislo += (mesicHodnota < 10 ? "0" : "") + to_string(mesicHodnota);
    /* Pokud je den menší než 10, přidá se 0 */
    rodneCislo += (den < 10 ? "0" : "") + to_string(den);
    /* Nastaví trojčíslí */
    rodneCislo = rodneCislo + "/" + (trojcisli < 100 ? (trojcisli < 10 ? "00" : "0") : "") + to_string(trojcisli);

    /* Pokud se jedná o osobu narozenou 1. 1. 1954, rodné číslo je devítimístné a neprovádí se validace */
    if (den == 1 && mesic == 1 && rok == 1954) {
        return;
    }

    /* Nastaví poslední číslo */
    cisloBezLomitka = stoi(rodneCislo.substr(0, 6) + rodneCislo.substr(7, 4));
    zbytekRodnehoCisla = cisloBezLomitka % 11;
    rodneCislo += (zbytekRodnehoCisla == 10) ? "0" : to_string(zbytekRodnehoCisla);
}

/* Vrací hotové rodné číslo */
string RodneCislo::vratRodneCislo() {
    nastavRodneCislo();
    return this->rodneCislo;
}
/* Vyčistí neplatný vstup od uživatele */
void RodneCislo::vycistiVstup() {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
/* Načte den narození */
void RodneCislo::nactiDen() {
    int d;
    cout << "Zadej den v intervalu 1 a 31: ";
    while (!(cin >> d) || !nastavDen(d)) {
        cout << "Den musi byt v intervalu 1 a 31: ";
        vycistiVstup();
    }
}
/* Načte měsíc narození */
void RodneCislo::nactiMesic() {
    int m;
    cout << "Zadej mesic v intervalu 1 a 12: ";
    while (!(cin >> m) || !nastavMesic(m)) {
        cout << "Mesic musi byt v intervalu 1 a 12: ";
        vycistiVstup();
    }
}
/* Načte rok narození */
void RodneCislo::nactiRok() {
    int r;
    cout << "Zadej rok v intervalu 1954 a 2053: ";
    while (!(cin >> r) || !nastavRok(r)) {
        cout << "Rok musi byt v intervalu 1954 a 2053: ";
        vycistiVstup();
    }
}
/* Načte pohlaví */
void RodneCislo::nactiPohlavi() {
    int p;
    cout << "Zadej pohlavi (0 - zena, 1 - muz) v intervalu 0 a 1: ";
    while (!(cin >> p) || !nastavPohlavi(p)) {
        cout << "Pohlavi musi byt v intervalu 0 a 1: ";
        vycistiVstup();
    }
}
/* Načte trojčíslí */
void RodneCislo::nactiTrojcisli() {
    int t;
    cout << "Zadej trojcisli za lomitkem v intervalu 0 a 999: ";
    while (!(cin >> t) || !nastavTrojcisli(t)) {
        cout << "Trojcisli musi byt v intervalu 0 a 999: ";
        vycistiVstup();
    }
}