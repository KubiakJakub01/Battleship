// po_lab_5.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Plansza.h"
#include "Kontroler.h"

using namespace std;
int main()
{
    /*Plansza* plansza = new Plansza(10, 10);
    cout << "Plansza gracza\n";
    plansza->pokazPlanszeGracza();
    cout << "\nPlansza\n";
    plansza->pokazPlansze();
    cout << "\Dodaj statek\n";
    plansza->dodajStatek(1, 5, 4, 1);
    plansza->dodajStatek(7, 3, 5, 0);
    cout << "\nPlansza gracza\n";
    plansza->pokazPlanszeGracza();
    cout << "\nStrzal\n";
    plansza->strzal(3, 5);
    plansza->strzal(1, 5);
    plansza->strzal(8, 4);
    cout << "Plansza gracza\n";
    plansza->pokazPlanszeGracza();
    cout << "\nPlansza\n";
    plansza->pokazPlansze();*/
    setlocale(LC_CTYPE, "pl_Pl");

    Kontroler con = Kontroler();
    con.graj();
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
