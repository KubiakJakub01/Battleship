#pragma once

#include "Plansza.h"
#include <vector>
#include <string>


class Gracz
{
private:
	std::vector<struct Strzal> strzaly;
	std::vector<struct Strzal> strzaly_do_oddania;
	int size_x;
	int size_y;
	bool czy_czlowiek;
	bool czy_statek_namierzony;

public:
	Gracz(int, int, std::string, bool);
	std::string nazwa_gracza;
	Plansza* plansza;
	void dodajStrzal(int, int, bool);
	bool odbierzStrzal(int,int, bool& czy_trafiony);
	void wykonajStrzal(int&,int&);
	void dodajStatki(int, int, int*);
	bool czyStrzalDozwolony(int, int);
	void dodajStatkiAutomatycznie(int, int, int*);
};

