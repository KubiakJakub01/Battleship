#pragma once

#include <string>
class Plansza
{
private:
	int size_x;
	int size_y;
	int calkowita_ilosc_statkow;
	std::string *planszaGracza;
	std::string *plansza;
	char const symbols[3];
	void initPlansze();
	bool sprawdzPlansze(int, int, int, bool);

public:
	Plansza(int size_x, int size_y);
	int ilosc_pozostalych_elementow_statkow;
	bool dodajStatek(int x, int y, int rozmiar, bool pionowo);
	bool strzal(int x, int y, bool&);
	void pokazPlansze();
	void pokazPlanszeGracza();
};

