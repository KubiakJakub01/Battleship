#pragma once
#include "Gracz.h"
#include <string>

class Kontroler
{
private:
	Gracz* gracze[2];
	bool flaga;
	int max_wielkosc_statku;
	int min_wielkosc_statku;
	int* statki;
	void konfiguracja();

public:
	Kontroler();
	void graj();
};

