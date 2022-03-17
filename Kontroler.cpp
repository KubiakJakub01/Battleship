#include "Kontroler.h"
#include<iostream>
#include<string>

using namespace std;
Kontroler::Kontroler()
{
	flaga = true;
	string nazwa_gracza;
	int n = 30;
	int typ_gracza;

	for (int i = 0; i < 2; i++)
	{
		cout << "Podaj imie gracza "<<i+1<<": ";
		cin >> nazwa_gracza;

		cout << "\nWybierz typ gracza\n";
		cout << "[0] Komputer\n";
		cout << "[1] Cz³owiek\n";
		cin >> typ_gracza;
		gracze[i] = new Gracz(n, n, nazwa_gracza, (bool)typ_gracza);
	}

	min_wielkosc_statku = 2;
	max_wielkosc_statku = 5;

	statki = new int[max_wielkosc_statku - min_wielkosc_statku];
}

void Kontroler::konfiguracja()
{
	int ilosc = 0;
	int wybor = 1;
	int j = 0;
	cout << "Dokonaj konfiguracji\n";
	for (int i = min_wielkosc_statku; i < max_wielkosc_statku+1; i++)
	{
		cout << "Podaj iloœæ statków o rozmiarze: " << i << ": ";
		cin >> ilosc;
		statki[j] = ilosc;
		j++;
	}
	for (int i = 0; i < 2; i++)
	{
		system("cls");
		cout << "\nWybór rozstawienia statków dla gracza " << gracze[i]->nazwa_gracza << endl;
		cout << "[1]Dodaj statki samemu\n";
		cout << "[2]Dodaj statki automatycznie\n";
		cin >> wybor;
		if (wybor == 1)
		{
			gracze[i]->dodajStatki(min_wielkosc_statku, max_wielkosc_statku, statki);
		}
		else if (wybor == 2)
		{
			gracze[i]->dodajStatkiAutomatycznie(min_wielkosc_statku, max_wielkosc_statku, statki);
		}
		cout << "Rozstawienie staktów gracza: " << gracze[i]->nazwa_gracza << endl;
		gracze[i]->plansza->pokazPlanszeGracza();
		system("pause");
	}

}

void Kontroler::graj()
{
	system("cls");
	cout << "Witaj w grze w statki\n";
	konfiguracja();

	system("cls");

	int x = 0;
	int y = 0;
	bool czy_trafiony;
	int obecny_gracz;

	while (flaga)
	{
		for (int i = 0; i < 2; i++)
		{
			obecny_gracz = (i + 1) % 2;
			do
			{
				system("cls");
				cout << "Tura gracza: " << gracze[obecny_gracz]->nazwa_gracza << endl;
				gracze[i]->plansza->pokazPlansze();
				gracze[obecny_gracz]->wykonajStrzal(x, y);
			} while (!gracze[i]->odbierzStrzal(x, y, czy_trafiony));
			gracze[obecny_gracz]->dodajStrzal(x, y, czy_trafiony);
			cout << endl;
			gracze[i]->plansza->pokazPlansze();


			if (gracze[i]->plansza->ilosc_pozostalych_elementow_statkow == 0)
			{
				cout << "Gracz " << gracze[obecny_gracz]->nazwa_gracza << " wygra³ \n";
				cout << "Plansze przegranego \n";
				gracze[i]->plansza->pokazPlansze();
				cout << endl;
				gracze[i]->plansza->pokazPlanszeGracza();
				cout << "Plansze wygranego \n";
				gracze[obecny_gracz]->plansza->pokazPlansze();
				cout << endl;
				gracze[obecny_gracz]->plansza->pokazPlanszeGracza();
				flaga = false;
				break;
			}
			system("pause");
		}

	}
	cout << "\nKoniec gry\n";
}
