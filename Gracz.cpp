#include "Gracz.h"
#include<vector>
#include<iostream>
#include<string>
#include <stdlib.h>    
#include <time.h>   

using namespace std;

struct Strzal
{
	int x;
	int y;
	bool czy_trafiony;
};

Gracz::Gracz(int size_x, int size_y, string imie, bool czy_czlowiek): nazwa_gracza(imie), size_x(size_x), size_y(size_y), czy_czlowiek(czy_czlowiek), czy_statek_namierzony(false)
{
    plansza = new Plansza(size_x, size_y);
	//nazwa_gracza = imie;
}

bool Gracz::odbierzStrzal(int x, int y, bool& czy_trafiony)
{
    if (plansza->strzal(x, y, czy_trafiony))
    {
		return true;
    }
    else
    {
        cout << "\nPonów strza³\n";
		system("pause");
    }
    return false;
}

void Gracz::wykonajStrzal(int& x, int& y)
{
	bool flag = true;
	if (czy_czlowiek)
	{
		//Wybór przez gracza
		while (flag)
		{
			cout << "Podaj x: ";
			cin >> x;
			cout << "Podaj y: ";
			cin >> y;
			if (x < 0 || x >= size_x || y < 0 || y >= size_y)
			{
				cout << "Niepoprawne wspó³rzêdne strza³u \n";
			}
			else
				flag = false;
		}
	}
	else
	{
		struct Strzal s;
		bool flag = 0;
		struct Strzal next_s;
		int random;
		//Wybór przez komputer
		/*cout << "Historia strza³ów\n";
		for(int i = 0; i<strzaly.size(); i++)
		{
			cout << "x: " << strzaly[i].x << " y: " << strzaly[i].y << " czy trafiony: " << strzaly[i].czy_trafiony << endl;
		}*/

		if (!strzaly.empty())
		{
			if (strzaly[strzaly.size() - 1].czy_trafiony)
			{
				czy_statek_namierzony = true;
				s = strzaly[strzaly.size() - 1];
				next_s.x = s.x + 1;
				next_s.y = s.y;
				if(czyStrzalDozwolony(next_s.x, next_s.y))
					strzaly_do_oddania.push_back(next_s);
				next_s.x = s.x - 1;
				next_s.y = s.y;
				if (czyStrzalDozwolony(next_s.x, next_s.y))
					strzaly_do_oddania.push_back(next_s);
				next_s.x = s.x;
				next_s.y = s.y + 1;
				if (czyStrzalDozwolony(next_s.x, next_s.y))
					strzaly_do_oddania.push_back(next_s);
				next_s.x = s.x;
				next_s.y = s.y - 1;
				if (czyStrzalDozwolony(next_s.x, next_s.y))
					strzaly_do_oddania.push_back(next_s);

				if (!strzaly_do_oddania.empty())
				{
					s = strzaly_do_oddania[0];
					x = s.x;
					y = s.y;
					strzaly_do_oddania.erase(strzaly_do_oddania.begin());
				}
				else
				{
					do
					{
						x = rand() % (size_x - 1);
						y = rand() % (size_y - 1);
					} while (!czyStrzalDozwolony(x, y));
				}
			}
			else if (!strzaly_do_oddania.empty())
			{
				s = strzaly_do_oddania[0];
				x = s.x;
				y = s.y;
				strzaly_do_oddania.erase(strzaly_do_oddania.begin());
			}
			else if(strzaly_do_oddania.empty())
			{
				do
				{
					x = rand() % (size_x - 1);
					y = rand() % (size_y - 1);
				} while (!czyStrzalDozwolony(x, y));
			}
		}
		else
		{
			do
			{
				x = rand() % (size_x - 1);
				y = rand() % (size_y - 1);
			} while (!czyStrzalDozwolony(x, y));
		}

		cout << "\nStrza³ komputera\n";
		cout << "x: " << x << endl;
		cout << "y: " << y << endl;
	}
}

void Gracz::dodajStrzal(int x, int y, bool czy_trafiony)
{
	struct Strzal s = { x,y,czy_trafiony };
	strzaly.push_back(s);
}

void Gracz::dodajStatki(int min, int max, int* statki)
{
	int x;
	int y;
	int j = 0;
	int poziom;
	bool czy_dodalo = false;

	//cout << "Min: " << min << " max " << max << endl;
	for (int i = min; i < max + 1; i++)
	{
		//cout << "Statki: " << i << " ilosc " << statki[j] << endl;
		if (statki[j] != 0)
		{
			cout << "\nDodawanie statków o rozmiarze: " << i << endl;
			for (int z = 0; z < statki[j]; z++)
			{
				while (!czy_dodalo)
				{
					plansza->pokazPlanszeGracza();
					cout << "\nPodaj x: ";
					cin >> x;
					cout << "\nPodaj y: ";
					cin >> y;
					cout << "\n[0]Pionowo [1]Poziomo: ";
					cin >> poziom;

					czy_dodalo = plansza->dodajStatek(x, y, i, (bool)poziom);

					if (!czy_dodalo)
					{
						cout << "Nie uda³o siê dodaæ statku, spróbój jeszcze raz\n";
					}
				}
				czy_dodalo = false;
			}

		}
		j++;
	}

	//system("cls");
}

bool Gracz::czyStrzalDozwolony(int x, int y)
{
	if (x < 0 || x >= size_x || y < 0 || y >= size_y)
		return false;
	else
	{
		for (int i = 0; i < strzaly.size(); i++)
		{
			if (strzaly[i].x == x && strzaly[i].y == y)
				return false;
		}
	}
	return true;
}

void Gracz::dodajStatkiAutomatycznie(int min, int max, int* statki)
{
	srand(time(NULL));
	int j = 0;
	int x = 0;
	int y = 0;

	for (int i = min; i < max + 1; i++)
	{
		if (statki[j] != 0)
		{
			for (int z = 0; z < statki[j]; z++)
			{
				do {
					x = rand() % (size_x - i) + i;
					y = rand() % (size_y - i) + i;
				} while (!(plansza->dodajStatek(x, y, i, (bool)(rand() % 2))));
			}
		}
		j++;
	}
}
