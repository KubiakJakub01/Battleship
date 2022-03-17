#include "Plansza.h"

#include <string>
#include <iostream>

using namespace std;



Plansza::Plansza(int size_x, int size_y) :size_x(size_x), size_y(size_y), calkowita_ilosc_statkow(0), symbols{ '*', 'X', 'O' }, ilosc_pozostalych_elementow_statkow(0)
{
	planszaGracza = new string[size_y];
	plansza = new string[size_y];
	initPlansze(); //Wype³nianie tablic znakami pocz¹tkowymi
}

void Plansza::initPlansze()
{
	for (int i = 0; i < size_y; i++)
	{
		planszaGracza[i] = string(size_x, '0');
		//cout << planszaGracza[i] << endl;
		plansza[i] = string(size_x, symbols[0]);
		//cout << plansza[i] << endl;
	}
}

bool Plansza::dodajStatek(int y, int x, int rozmiar, bool poziomo)
{
	if (sprawdzPlansze(y, x, rozmiar, poziomo))
	{
		int next_x = x;
		int next_y = y;

		for (int i = 0; i < rozmiar; i++)
		{
			planszaGracza[next_x][next_y] = '0' + rozmiar;
			if (poziomo)
			{
				next_y++;
			}
			else
			{
				next_x++;
			}
		}
		calkowita_ilosc_statkow++;
		ilosc_pozostalych_elementow_statkow += rozmiar;
		return true;
	}
	return false;
}

bool Plansza::sprawdzPlansze(int y, int x, int rozmiar, bool poziomo)
{
	int next_x = x;
	int next_y = y;

	if (x < 0 || x >= size_x || y < 0 || y >= size_y)
	{
		return false;
	}

	if (poziomo)
	{
		if (next_y != 0)
		{
			if (planszaGracza[next_x][next_y - 1] != '0')
				return false;
		}
	}
	else
	{
		if (next_x != 0)
		{
			if (planszaGracza[next_x-1][next_y] != '0')
				return false;
		}
	}
	//Pêtla sprawdza i dodaje do planszy kolejne elementy statku
	for (int i = 0; i < rozmiar; i++)
	{
		if (next_x < size_x && next_y < size_y)
		{
			if (planszaGracza[next_x][next_y] == '0')
			{
				//planszaGracza[next_x][next_y] = '0' + rozmiar;
				if (poziomo)
				{
					if (next_x != 0)
					{
						if (planszaGracza[next_x - 1][next_y] != '0')
							return false;
					}
					if (next_x < size_x-1)
					{
						if (planszaGracza[next_x + 1][next_y] != '0')
							return false;
					}
					next_y++;
				}
				else
				{
					if (next_y != 0)
					{
						if (planszaGracza[next_x][next_y - 1] != '0')
							return false;
					}
					if (next_y < size_y - 1)
					{
						if (planszaGracza[next_x][next_y + 1] != '0')
							return false;
					}
					next_x++;
				}
			}
			else
				return false;
		}
		else
			return false;
	}
	if (poziomo)
	{
		if (next_y < size_y)
		{
			
			if (planszaGracza[next_x][next_y] != '0')
				return false;
		}
	}
	else
	{
		if (next_x < size_x)
		{
			if (planszaGracza[next_x][next_y] != '0')
				return false;
		}
	}
	return true;
}

bool Plansza::strzal(int y, int x, bool& czy_trafiony)
{
	if (x<0 || x>=size_x || y<0 || y>=size_y)
		return false;
	else if (plansza[x][y] == symbols[0])
	{
		if (planszaGracza[x][y] == '0')
		{
			plansza[x][y] = symbols[2]; //Pud³o
			czy_trafiony = false;
			cout << "\nPud³o\n";
		}
		else
		{
			plansza[x][y] = symbols[1]; //Trafienie
			ilosc_pozostalych_elementow_statkow--;
			czy_trafiony = true;
			cout << "\nTrafienie\n";
			if (ilosc_pozostalych_elementow_statkow == 0) //Jezeli wszystkie statki zosta³y zastrzelone gra siê koñczy
			{
				cout << "\nKONIEC GRY\n";
			}
		}
	}
	else
	{
		cout << "\nW to pole zosta³ ju¿ oddany strza³";
		return false;
	}
	return true;
}

void Plansza::pokazPlansze()
{
	//Pokazuje stan planszy dla opoeneta
	for (int i = 0; i < size_x; i++)
	{
		for (int j = 0; j < size_y; j++)
			cout << plansza[i][j] << " ";
		cout << endl;
	}
}

void Plansza::pokazPlanszeGracza()
{
	//Pokazuje planszê w sposób jawny 
	for (int i = 0; i < size_x; i++)
	{
		for (int j = 0; j < size_y; j++)
			cout << planszaGracza[i][j] << " ";
		cout << endl;
	}
}
