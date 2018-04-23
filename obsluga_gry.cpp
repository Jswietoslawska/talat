#include "obsluga_gry.h"
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <Windows.h>

int wybor_piona(wierzcholki wierz, wysokosc wys)
{
	if (wierz == TROJKAT&& wys == MALY)
		return 0;
	if (wierz == TROJKAT&&wys == SREDNI)
		return 1;
	if (wierz == TROJKAT&&wys == DUZY)
		return 2;
	if (wierz == KWADRAT&&wys == MALY)
		return 3;
	if (wierz == KWADRAT&&wys == SREDNI)
		return 4;
	if (wierz == KWADRAT&&wys == DUZY)
		return 5;
	if (wierz == SZESCIOKAT&&wys == MALY)
		return 6;
	if (wierz == SZESCIOKAT&&wys == SREDNI)
		return 7;
	if (wierz == SZESCIOKAT&&wys == DUZY)
		return 8;
}

int koniec_gry(plansza*pl1, plansza*pl2, plansza*pl3, gracz*gr1, gracz*gr2, gracz*gr3)
{
	//sprawdzanie czy jakies piony znalazly sie na polu startowym przeciwnika
	//plansza 1
	if (pl1->getzamrozona() == 0 && pl2->getzamrozona() == 0 && pl3->getzamrozona() == 0)
	{
		for (int i = 0; i < ROZMIAR; i++)
		{
			pionek*wsk;
			if ((wsk=pl1->getpole_piona(0, i) )!= NULL)
			{
				if (pl1->getkolor1() == gr1->getkolor() && wsk->getkolor() == pl1->getkolor1())
					gr1->setpunkty(3);
				else if (pl1->getkolor1() == gr2->getkolor() && wsk->getkolor() == pl1->getkolor1())
					gr2->setpunkty(3);
				else if (pl1->getkolor1() == gr3->getkolor() && wsk->getkolor() == pl1->getkolor1())
					gr3->setpunkty(3);
				else
					;
			}
		}
		for (int i = 0; i < ROZMIAR; i++)
		{
			pionek*wsk;
			if ((wsk = pl1->getpole_piona(4, i)) != NULL)
			{
				if (pl1->getkolor2() == gr1->getkolor() && wsk->getkolor() == pl1->getkolor2())
					gr1->setpunkty(3);
				else if (pl1->getkolor2() == gr2->getkolor() && wsk->getkolor() == pl1->getkolor2())
					gr2->setpunkty(3);
				else if (pl1->getkolor2() == gr3->getkolor() && wsk->getkolor() == pl1->getkolor2())
					gr3->setpunkty(3);
				else
					;
			}
		}
			//plansza 2
			for (int i = 0; i < ROZMIAR; i++)
			{
				pionek*wsk;
				if ((wsk = pl2->getpole_piona(0, i)) != NULL)
				{
					if (pl2->getkolor1() == gr1->getkolor() && wsk->getkolor() == pl2->getkolor1())
						gr1->setpunkty(3);
					else if (pl2->getkolor1() == gr2->getkolor() && wsk->getkolor() == pl2->getkolor1())
						gr2->setpunkty(3);
					else if (pl2->getkolor1() == gr3->getkolor() && wsk->getkolor() == pl2->getkolor1())
						gr3->setpunkty(3);
					else
						;
				}
			}
			for (int i = 0; i < ROZMIAR; i++)
			{
				pionek*wsk;
				if ((wsk = pl2->getpole_piona(4,i)) != NULL)
				{
					if (pl2->getkolor2() == gr1->getkolor() && wsk->getkolor() == pl2->getkolor2())
						gr1->setpunkty(3);
					else if (pl2->getkolor2() == gr2->getkolor() && wsk->getkolor() == pl2->getkolor2())
						gr2->setpunkty(3);
					else if (pl2->getkolor2() == gr3->getkolor() && wsk->getkolor() == pl2->getkolor2())
						gr3->setpunkty(3);
					else
						;
				}
			}
			//plansza 3
			for (int i = 0; i < ROZMIAR; i++)
			{
				pionek*wsk;
				if ((wsk = pl3->getpole_piona(0,i)) != NULL)
				{
					if (pl3->getkolor1() == gr1->getkolor() && wsk->getkolor() == pl3->getkolor1())
						gr1->setpunkty(3);
					else if (pl3->getkolor1() == gr2->getkolor() && wsk->getkolor() == pl3->getkolor1())
						gr2->setpunkty(3);
					else if (pl3->getkolor1() == gr3->getkolor() && wsk->getkolor() == pl3->getkolor1())
						gr3->setpunkty(3);
					else
						;
				}
			}
			for (int i = 0; i < ROZMIAR; i++)
			{
				pionek*wsk;
				if ((wsk = pl3->getpole_piona(4, i)) != NULL)
				{
					if (pl3->getkolor2() == gr1->getkolor() && wsk->getkolor() == pl3->getkolor2())
						gr1->setpunkty(3);
					else if (pl3->getkolor2() == gr2->getkolor() && wsk->getkolor() == pl3->getkolor2())
						gr2->setpunkty(3);
					else if (pl3->getkolor2() == gr3->getkolor() && wsk->getkolor() == pl3->getkolor2())
						gr3->setpunkty(3);
					else
						;
				}
			}
		//ogloszenie zwyciezcy
		if (gr1->getpunkty() > gr2->getpunkty()&&gr1->getpunkty() > gr3->getpunkty())
		{
			cout << endl << "\tWygral " << gr1->getnick() << "!" << endl;
			if (gr1->getpunkty() == 3 || (gr1->getpunkty()>20 && ((gr1->getpunkty()) % 10 >= 2 && (gr1->getpunkty()) % 10 <= 4)))
			{
				cout << "Uzyskal " << gr1->getpunkty() << " punkty!";
			}
			else
			{
				cout << "Uzyskal " << gr1->getpunkty() << " punktow!";
			}
		}
		else if (gr2->getpunkty() > gr1->getpunkty() && gr2->getpunkty() > gr3->getpunkty())
		{
			cout << endl << "\tWygral " << gr2->getnick() << "!" << endl;
			if (gr2->getpunkty() == 3 || (gr2->getpunkty()>20 && ((gr2->getpunkty()) % 10 >= 2 && (gr2->getpunkty()) % 10 <= 4)))
			{
				cout << "Uzyskal " << gr2->getpunkty() << " punkty!";
			}
			else
			{
				cout << "Uzyskal " << gr2->getpunkty() << " punktow!";
			}

		}
		else if (gr3->getpunkty() > gr1->getpunkty() && gr3->getpunkty() > gr2->getpunkty())
		{
			cout << endl << "\tWygral " << gr3->getnick() << "!" << endl;
			if (gr3->getpunkty() == 3 || (gr3->getpunkty()>20 && ((gr3->getpunkty()) % 10 >= 2 && (gr3->getpunkty()) % 10 <= 4)))
			{
				cout << "Uzyskal " << gr3->getpunkty() << " punkty!";
			}
			else
			{
				cout << "Uzyskal " << gr3->getpunkty() << " punktow!";
			}
		}
		//remis
		else if (gr1->getpunkty() == gr2->getpunkty() && gr2->getpunkty() == gr3->getpunkty())
		{
			cout << endl << "\tMamy trzech zwyciezcow!" << endl;
		}
		else if (gr1->getpunkty() == gr2->getpunkty())
		{
			cout << endl << "\tRemis!" <<endl << "Pierwsze miejsce zajeli "<< gr1->getnick() <<" i "<<gr2->getnick() << "!" << endl;
			if (gr1->getpunkty() == 3 || (gr1->getpunkty()>20 && ((gr1->getpunkty()) % 10 >= 2 && (gr1->getpunkty()) % 10 <= 4)))
			{
				cout << "Uzyskali " << gr1->getpunkty() << " punkty!";
			}
			else
			{
				cout << "Uzyskali " << gr1->getpunkty() << " punktow!";
			}
		}
		else if (gr3->getpunkty() == gr2->getpunkty())
		{
			cout << endl << "\tRemis!" << endl << "Pierwsze miejsce zajeli " << gr3->getnick() << " i " << gr2->getnick() << "!" << endl;
			if (gr2->getpunkty() == 3 || (gr2->getpunkty()>20 && ((gr2->getpunkty()) % 10 >= 2 && (gr2->getpunkty()) % 10 <= 4)))
			{
				cout << "Uzyskali " << gr2->getpunkty() << " punkty!";
			}
			else
			{
				cout << "Uzyskali " << gr2->getpunkty() << " punktow!";
			}
		}
		else if (gr1->getpunkty() == gr3->getpunkty())
		{
			cout << endl << "\tRemis!" << endl << "Pierwsze miejsce zajeli " << gr1->getnick() << " i " << gr3->getnick() << "!" << endl;
			if (gr1->getpunkty() == 3||(gr1->getpunkty()>20&&((gr1->getpunkty())%10>=2&& (gr1->getpunkty()) % 10 <= 4)))
			{
				cout << "Uzyskali " << gr1->getpunkty() << " punkty!";
			}
			else
			{
				cout << "Uzyskali " << gr1->getpunkty() << " punktow!";
			}
		}
		//punktacja
		cout << endl << endl << "\tPUNKTACJA" << endl;
		cout.width(20);
		cout << left << gr1->getnick();
		cout.width(5);
		cout << gr1->getpunkty() << endl;
		cout.width(20);
		cout << left << gr2->getnick();
		cout.width(5);
		cout << gr2->getpunkty() << endl;
		cout.width(20);
		cout << left << gr3->getnick();
		cout.width(5);
		cout << gr3->getpunkty() << endl;
		return 0;
	}
	else
		return 1;
}

int kolejka(gracz*gr)
{
	if (gr->getplansza1()->zamrozenie() == 0 && gr->getplansza2()->zamrozenie() == 0)
	{
		cout << "Wszystkie plansze gracza sa zamrozone." << endl;
		return 0;
	}
	else
	{
		return 1;
	}
}

char znakowy_kolor(kolor barwa)
{
	if (barwa == SZARY)
		return 'S';
	if (barwa == BIALY)
		return 'B';
	if (barwa == CZARNY)
		return 'C';
}

int zapis(plansza*pl1, plansza*pl2, plansza*pl3, gracz*gr1, gracz*gr2, gracz*gr3)
{
	if (zapis_trybu(gr1, gr2, gr3) == -1)
	{
		cout << "\tNie udalo sie zapisac gry." << endl;
		return 1;
	}
	FILE*stream;
	if ((stream = fopen("zapis.txt", "w")) == NULL)
	{
		cout << "\tNie udalo sie zapisac gry." << endl;
		return 1;
	}
	else
	{
		int i, j;
		char barwa;
		pionek* pion;
		char kolor_pl1;
		char kolor_pl2;
		char imie[50];
		//gracz 1
		strcpy(imie, gr1->getnick());
		barwa = znakowy_kolor(gr1->getkolor());
		if (gr1->getplansza1()->getkolor1() == gr1->getkolor())
			kolor_pl1 = znakowy_kolor(gr1->getplansza1()->getkolor2());
		else
			kolor_pl1 = znakowy_kolor(gr1->getplansza1()->getkolor1());
		if (gr1->getplansza2()->getkolor1() == gr1->getkolor())
			kolor_pl2 = znakowy_kolor(gr1->getplansza2()->getkolor2());
		else
			kolor_pl2 = znakowy_kolor(gr1->getplansza2()->getkolor1());
		fprintf(stream, "%s %c %c %c %d\n",imie, barwa, kolor_pl1, kolor_pl2, gr1->getpunkty());
		//gracz 2
		strcpy(imie, gr2->getnick());
		barwa = znakowy_kolor(gr2->getkolor());
		if (gr2->getplansza1()->getkolor1() == gr2->getkolor())
			kolor_pl1 = znakowy_kolor(gr2->getplansza1()->getkolor2());
		else
			kolor_pl1 = znakowy_kolor(gr2->getplansza1()->getkolor1());
		if (gr2->getplansza2()->getkolor1() == gr2->getkolor())
			kolor_pl2 = znakowy_kolor(gr2->getplansza2()->getkolor2());
		else
			kolor_pl2 = znakowy_kolor(gr2->getplansza2()->getkolor1());
		fprintf(stream, "%s %c %c %c %d\n", imie, barwa, kolor_pl1, kolor_pl2, gr2->getpunkty());
		//gracz 3
		strcpy(imie, gr3->getnick());
		barwa = znakowy_kolor(gr3->getkolor());
		if (gr3->getplansza1()->getkolor1() == gr3->getkolor())
			kolor_pl1 = znakowy_kolor(gr1->getplansza1()->getkolor2());
		else
			kolor_pl1 = znakowy_kolor(gr3->getplansza1()->getkolor1());
		if (gr3->getplansza2()->getkolor1() == gr3->getkolor())
			kolor_pl2 = znakowy_kolor(gr3->getplansza2()->getkolor2());
		else
			kolor_pl2 = znakowy_kolor(gr3->getplansza2()->getkolor1());
		fprintf(stream, "%s %c %c %c %d\n",imie, barwa, kolor_pl1, kolor_pl2, gr3->getpunkty());
		//plansza 1
		for (i = 0; i < ROZMIAR; i++)
		{
			for (j = 0; j < ROZMIAR; j++)
			{
				if ((pl1->getpole_piona(i, j)) == NULL)
					fprintf(stream, "%d\n", 0);
				else
				{
					pion = pl1->getpole_piona(i, j);
					barwa = znakowy_kolor(pion->getkolor());
					fprintf(stream, "%d %c %d %d\n", 1, barwa, pion->getwys(), pion->getwierz());
				}
			}
		}
		//plansza 2
		for (i = 0; i < ROZMIAR; i++)
		{
			for (j = 0; j < ROZMIAR; j++)
			{
				if ((pl2->getpole_piona(i, j)) == NULL)
					fprintf(stream, "%d\n", 0);
				else
				{
					pion = pl2->getpole_piona(i, j);
					barwa = znakowy_kolor(pion->getkolor());
					fprintf(stream, "%d %c %d %d\n", 1, barwa, pion->getwys(), pion->getwierz());
				}
			}
		}
		//plansza 3
		for (i = 0; i < ROZMIAR; i++)
		{
			for (j = 0; j < ROZMIAR; j++)
			{
				if ((pl3->getpole_piona(i, j)) == NULL)
					fprintf(stream, "%d\n", 0);
				else
				{
					pion = pl3->getpole_piona(i, j);
					barwa = znakowy_kolor(pion->getkolor());
					fprintf(stream, "%d %c %d %d\n", 1, barwa, pion->getwys(), pion->getwierz());
				}
			}
		}
		fclose(stream);
		return 0;
	}
}

int odczyt(plansza*pl1, plansza*pl2, plansza*pl3, gracz*gr1, gracz*gr2, gracz*gr3)
{
	FILE*stream;
	if ((stream = fopen("zapis.txt", "r")) == NULL)
	{
		cout << "\tNie udalo sie odczytac zapisanej gry." << endl;
		return 1;
	}
	else
	{
		int temp;
		int i, j;
		char barwa;
		kolor kolory;
		pionek* pion;
		char imie[50];

		//gracz 1
		if (fscanf(stream, "%s", imie) == EOF)
		{
			cout << endl << "Brak zapisanych rozgrywek" << endl;
			return 1;
		}
		gr1->setnick(imie);
		//kolor gracza
		if (fscanf(stream, " %c", &barwa) == EOF)
		{
			cout << "\nPlik uszkodzony." << endl;
			return -1;
		}
		kolory = znak_na_kolor(barwa);
		if (isalpha(barwa)==0)
		{
			cout << "\nBledne dane, nie mozna odczytac pliku!" << endl;
			return -1;
		}
		if (gr1->getkolor() != kolory)
		{
			cout << "\nPlik uszkodzony." << endl;
			return -1;
		}
		//kolor planszy 1
		if (fscanf(stream, " %c", &barwa) == EOF)
		{
			cout << "\nPlik uszkodzony." << endl;
			return -1;
		}
		kolory = znak_na_kolor(kolory);
		if (isalpha(barwa)==0)
		{
			cout << "\nBledne dane, nie mozna odczytac pliku!" << endl;
			return -1;
		}
		if (gr1->getplansza1()->getkolor1() != kolory&&gr1->getplansza1()->getkolor2()!=kolory)
		{
			cout << "\nPlik uszkodzony." << endl;
			return -1;
		}
		//kolor planszy 2
		if(fscanf(stream, " %c", &barwa)==EOF)
		{
			cout << "\nPlik uszkodzony." << endl;
			return -1;
		}
		kolory = znak_na_kolor(kolory);
		if (isalpha(barwa)==0)
		{
			cout << "\nBledne dane, nie mozna odczytac pliku!" << endl;
			return -1;
		}
		if (gr1->getplansza2()->getkolor1() != kolory&&gr1->getplansza2()->getkolor2() != kolory)
		{
			cout << "\nPlik uszkodzony." << endl;
			return -1;
		}
		//punkty
		if(fscanf(stream, " %d", &temp)==EOF)
		{
			cout << "\nPlik uszkodzony." << endl;
			return -1;
		}
		if (temp<0)
		{
			cout << "\nBledne dane, nie mozna odczytac plku!" << endl;
			return -1;
		}
		gr1->setpunkty(temp);
		//gracz 2
		if(fscanf(stream, "\n%s", imie)==EOF)
		{
			cout << "\nPlik uszkodzony." << endl;
			return -1;
		}
		gr2->setnick(imie);
		//kolor gracza
		if(fscanf(stream, " %c", &barwa)==EOF)
		{
			cout << "\nPlik uszkodzony." << endl;
			return -1;
		}
		kolory = znak_na_kolor(barwa);
		if (isalpha(barwa)==0)
		{
			cout << "\nBledne dane, nie mozna odczytac pliku!" << endl;
			return -1;
		}
		if (gr2->getkolor() != kolory)
		{
			cout << "\nPlik uszkodzony." << endl;
			return -1;
		}
		//kolor planszy 1
		if(fscanf(stream, " %c", &barwa)==EOF)
		{
			cout << "\nPlik uszkodzony." << endl;
			return -1;
		}
		kolory = znak_na_kolor(kolory);
		if (isalpha(barwa)==0)
		{
			cout << "\nBledne dane, nie mozna odczytac pliku!" << endl;
			return -1;
		}
		if (gr2->getplansza1()->getkolor1() != kolory&&gr2->getplansza1()->getkolor2()!=kolory)
		{
			cout << "\nPlik uszkodzony." << endl;
			return -1;
		}
		//kolor planszy 2
		if(fscanf(stream, " %c", &barwa)==EOF)
		{
			cout << "\nPlik uszkodzony." << endl;
			return -1;
		}
		kolory = znak_na_kolor(kolory);
		if (isalpha(barwa)==0)
		{
			cout << "\nBledne dane, nie mozna odczytac pliku!" << endl;
			return -1;
		}
		if (gr2->getplansza2()->getkolor1() != kolory&&gr2->getplansza2()->getkolor2() != kolory)
		{
			cout << "\nPlik uszkodzony." << endl;
			return -1;
		}
		//punkty
		if(fscanf(stream, " %d", &temp)==EOF)
		{
			cout << "\nPlik uszkodzony." << endl;
			return -1;
		}
		if (temp<0)
		{
			cout << "\nBledne dane, nie mozna odczytac plku!" << endl;
			return -1;
		}
		gr2->setpunkty(temp);
		//gracz 3
		if(fscanf(stream, "\n%s", imie)==EOF)
		{
			cout << "\nPlik uszkodzony." << endl;
			return -1;
		}
		gr3->setnick(imie);
		//kolor gracza
		if(fscanf(stream, " %c", &barwa)==EOF)
		{
			cout << "\nPlik uszkodzony." << endl;
			return -1;
		}
		kolory = znak_na_kolor(barwa);
		if (isalpha(barwa)==0)
		{
			cout << "\nBledne dane, nie mozna odczytac pliku!" << endl;
			return -1;
		}
		if (gr3->getkolor() != kolory)
		{
			cout << "\nPlik uszkodzony." << endl;
			return -1;
		}
		//kolor planszy 1
		if(fscanf(stream, " %c", &barwa)==EOF)
		{
			cout << "\nPlik uszkodzony." << endl;
			return -1;
		}
		kolory = znak_na_kolor(kolory);
		if (isalpha(barwa)==0)
		{
			cout << "\nBledne dane, nie mozna odczytac pliku!" << endl;
			return -1;
		}
		if (gr3->getplansza1()->getkolor1() != kolory&&gr3->getplansza1()->getkolor2()!=kolory)
		{
			cout << "\nPlik uszkodzony." << endl;
			return -1;
		}
		//kolor planszy 2
		if(fscanf(stream, " %c", &barwa)==EOF)
		{
			cout << "\nPlik uszkodzony." << endl;
			return -1;
		}
		kolory = znak_na_kolor(kolory);
		if (isalpha(barwa)==0)
		{
			cout << "\nBledne dane, nie mozna odczytac pliku!" << endl;
			return -1;
		}
		if (gr3->getplansza2()->getkolor1() != kolory&&gr3->getplansza2()->getkolor2() != kolory)
		{
			cout << "\nPlik uszkodzony." << endl;
			return -1;
		}
		//punkty
		if(fscanf(stream, " %d", &temp)==EOF)
		{
			cout << "\nPlik uszkodzony." << endl;
			return -1;
		}
		if (temp<0)
		{
			cout << "\nBledne dane, nie mozna odczytac plku!" << endl;
			return -1;
		}
		gr3->setpunkty(temp);
		//plansza 1
		wysokosc wys;
		wierzcholki wierz;
		for (i = 0; i < ROZMIAR; i++)
		{
			for (j = 0; j < ROZMIAR; j++)
			{
				if(fscanf(stream, "%d", &temp)==EOF)
				{
					cout << "\nPlik uszkodzony." << endl;
					return -1;
				}
				if (temp!=0&&temp!=1)
				{
					cout << "\nBledne dane, nie mozna odczytac pliku!" << endl;
					return -1;
				}
				if (temp == 0)
					pl1->setpole_piona(i, j, NULL);
				else if (temp == 1)
				{
					if(fscanf(stream, " %c", &barwa)==EOF)
					{
						cout << "\nPlik uszkodzony." << endl;
						return -1;
					}
					if (isalpha(barwa)==0)
					{
						cout << "\nBlede dane, nie mozna odczytac pliku!" << endl;
						return -1;
					}
					kolory = znak_na_kolor(barwa);
					if (gr1->getkolor() == kolory)
					{
						if(fscanf(stream, "%d", &temp)==EOF)
						{
							cout << "\nPlik uszkodzony." << endl;
							return -1;
						}
						if (temp != 1&&temp != 2&&temp != 3)
						{
							cout << "\nPlik jest uszkodzony" << endl;
							return -1;
						}
						wys = num_na_wys(temp);
						if(fscanf(stream, "%d", &temp)==EOF)
						{
							cout << "\nPlik uszkodzony." << endl;
							return -1;
						}
						if (temp != 3&&temp != 4&&temp != 6)
						{
							cout << "\nPlik jest uszkodzony" << endl;
							return -1;
						}
						wierz = num_na_wierz(temp);
						pion = gr1->getpiony(wybor_piona(wierz, wys));
						pl1->setpole_piona(i, j, pion);
						pion->setwspolrz(i, j);
					}
					else if (gr2->getkolor() == kolory)
					{
						if(fscanf(stream, "%d", &temp)==EOF)
						{
							cout << "\nPlik uszkodzony." << endl;
							return -1;
						}
						if (temp != 1 && temp != 2 && temp != 3)
						{
							cout << "\nPlik jest uszkodzony" << endl;
							return -1;
						}
						wys = num_na_wys(temp);
						if(fscanf(stream, "%d", &temp)==EOF)
						{
							cout << "\nPlik uszkodzony." << endl;
							return -1;
						}
						if (temp != 3 && temp != 4 && temp != 6)
						{
							cout << "\nPlik jest uszkodzony" << endl;
							return -1;
						}
						wierz = num_na_wierz(temp);
						pion = gr2->getpiony(wybor_piona(wierz, wys));
						pl1->setpole_piona(i, j, pion);
						pion->setwspolrz(i, j);
					}
					else if (gr3->getkolor() == kolory)
					{
						if(fscanf(stream, "%d", &temp)==EOF)
						{
							cout << "\nPlik uszkodzony." << endl;
							return -1;
						}
						if (temp != 1 && temp != 2 && temp != 3)
						{
							cout << "\nPlik jest uszkodzony" << endl;
							return -1;
						}
						wys = num_na_wys(temp);
						if(fscanf(stream, "%d", &temp)==EOF)
						{
							cout << "\nPlik uszkodzony." << endl;
							return -1;
						}
						if (temp != 3 && temp != 4 && temp != 6)
						{
							cout << "\nPlik jest uszkodzony" << endl;
							return -1;
						}
						wierz = num_na_wierz(temp);
						pion = gr3->getpiony(wybor_piona(wierz, wys));
						pl1->setpole_piona(i, j, pion);
						pion->setwspolrz(i, j);
					}
					else
					{
						cout << "\nPlik uszkodzony." << endl;
						return -1;
					}
				}
				else
				{
					cout << "\nPlik uszkodzony." << endl;
					return -1;
				}
			}
		}
		//plansza 2
		for (i = 0; i < ROZMIAR; i++)
		{
			for (j = 0; j < ROZMIAR; j++)
			{
				if(fscanf(stream, "%d", &temp)==EOF)
				{
					cout << "\nPlik uszkodzony." << endl;
					return -1;
				}
				if (temp!=0&&temp!=1)
				{
					cout << "\nBledne dane, nie mozna odczytac pliku!" << endl;
					return -1;
				}
				if (temp == 0)
					pl2->setpole_piona(i, j, NULL);
				else if (temp == 1)
				{
					if(fscanf(stream, " %c", &barwa)==EOF)
					{
						cout << "\nPlik uszkodzony." << endl;
						return -1;
					}
					if (isalpha(barwa)==0)
					{
						cout << "\nBlede dane, nie mozna odczytac pliku!" << endl;
						return -1;
					}
					kolory = znak_na_kolor(barwa);
					if (gr1->getkolor() == kolory)
					{
						if(fscanf(stream, "%d", &temp)==EOF)
						{
							cout << "\nPlik uszkodzony." << endl;
							return -1;
						}
						if (temp != 1 && temp != 2 && temp != 3)
						{
							cout << "\nPlik jest uszkodzony" << endl;
							return -1;
						}
						wys = num_na_wys(temp);
						if(fscanf(stream, "%d", &temp)==EOF)
						{
							cout << "\nPlik uszkodzony." << endl;
							return -1;
						}
						if (temp != 3 && temp != 4 && temp != 6)
						{
							cout << "\nPlik jest uszkodzony" << endl;
							return -1;
						}
						wierz = num_na_wierz(temp);
						pion = gr1->getpiony(wybor_piona(wierz, wys));
						pl2->setpole_piona(i, j, pion);
						pion->setwspolrz(i, j);
					}
					else if (gr2->getkolor() == kolory)
					{
						if(fscanf(stream, "%d", &temp)==EOF)
						{
							cout << "\nPlik uszkodzony." << endl;
							return -1;
						}
						if (temp != 1 && temp != 2 && temp != 3)
						{
							cout << "\nPlik jest uszkodzony" << endl;
							return -1;
						}
						wys = num_na_wys(temp);
						if(fscanf(stream, "%d", &temp)==EOF)
						{
							cout << "\nPlik uszkodzony." << endl;
							return -1;
						}
						if (temp != 3 && temp != 4 && temp != 6)
						{
							cout << "\nPlik jest uszkodzony" << endl;
							return -1;
						}
						wierz = num_na_wierz(temp);
						pion = gr2->getpiony(wybor_piona(wierz, wys));
						pl2->setpole_piona(i, j, pion);
						pion->setwspolrz(i, j);
					}
					else if (gr3->getkolor() == kolory)
					{
						if(fscanf(stream, "%d", &temp)==EOF)
						{
							cout << "\nPlik uszkodzony." << endl;
							return -1;
						}
						if (temp != 1 && temp != 2 && temp != 3)
						{
							cout << "\nPlik jest uszkodzony" << endl;
							return -1;
						}
						wys = num_na_wys(temp);
						if(fscanf(stream, "%d", &temp)==EOF)
						{
							cout << "\nPlik uszkodzony." << endl;
							return -1;
						}
						if (temp != 3 && temp != 4 && temp != 6)
						{
							cout << "\nPlik jest uszkodzony" << endl;
							return -1;
						}
						wierz = num_na_wierz(temp);
						pion = gr3->getpiony(wybor_piona(wierz, wys));
						pl2->setpole_piona(i, j, pion);
						pion->setwspolrz(i, j);
					}
					else
					{
						cout << "\nPlik uszkodzony." << endl;
						return -1;
					}
				}
				else
				{
					cout << "\nPlik uszkodzony." << endl;
					return -1;
				}
			}
		}
		//plansza 3
		for (i = 0; i < ROZMIAR; i++)
		{
			for (j = 0; j < ROZMIAR; j++)
			{
				if(fscanf(stream, "%d", &temp)==EOF)
				{
					cout << "\nPlik uszkodzony." << endl;
					return -1;
				}
				if (temp!=0&&temp!=1)
				{
					cout << "\nBledne dane, nie mozna odczytac pliku!" << endl;
					return -1;
				}
				if (temp == 0)
					pl3->setpole_piona(i, j, NULL);
				else if (temp == 1)
				{
					if(fscanf(stream, " %c", &barwa)==EOF)
					{
						cout << "\nPlik uszkodzony." << endl;
						return -1;
					}
					if (isalpha(barwa)==0)
					{
						cout << "\nBlede dane, nie mozna odczytac pliku!" << endl;
						return -1;
					}
					kolory = znak_na_kolor(barwa);
					if (gr1->getkolor() == kolory)
					{
						if(fscanf(stream, "%d", &temp)==EOF)
						{
							cout << "\nPlik uszkodzony." << endl;
							return -1;
						}
						if (temp != 1 && temp != 2 && temp != 3)
						{
							cout << "\nPlik jest uszkodzony" << endl;
							return -1;
						}
						wys = num_na_wys(temp);
						if(fscanf(stream, "%d", &temp)==EOF)
						{
							cout << "\nPlik uszkodzony." << endl;
							return -1;
						}
						if (temp != 3 && temp != 4 && temp != 6)
						{
							cout << "\nPlik jest uszkodzony" << endl;
							return -1;
						}
						wierz = num_na_wierz(temp);
						pion = gr1->getpiony(wybor_piona(wierz, wys));
						pl3->setpole_piona(i, j, pion);
						pion->setwspolrz(i, j);
					}
					else if (gr2->getkolor() == kolory)
					{
						if(fscanf(stream, "%d", &temp)==EOF)
						{
							cout << "\nPlik uszkodzony." << endl;
							return -1;
						}
						if (temp != 1 && temp != 2 && temp != 3)
						{
							cout << "\nPlik jest uszkodzony" << endl;
							return -1;
						}
						wys = num_na_wys(temp);
						if(fscanf(stream, "%d", &temp)==EOF)
						{
							cout << "\nPlik uszkodzony." << endl;
							return -1;
						}
						if (temp != 3 && temp != 4 && temp != 6)
						{
							cout << "\nPlik jest uszkodzony" << endl;
							return -1;
						}
						wierz = num_na_wierz(temp);
						pion = gr2->getpiony(wybor_piona(wierz, wys));
						pl3->setpole_piona(i, j, pion);
						pion->setwspolrz(i, j);
					}
					else if (gr3->getkolor() == kolory)
					{
						if(fscanf(stream, "%d", &temp)==EOF)
						{
							cout << "\nPlik uszkodzony." << endl;
							return -1;
						}
						if (temp != 1 && temp != 2 && temp != 3)
						{
							cout << "\nPlik jest uszkodzony" << endl;
							return -1;
						}
						wys = num_na_wys(temp);
						if(fscanf(stream, "%d", &temp)==EOF)
						{
							cout << "\nPlik uszkodzony." << endl;
							return -1;
						}
						if (temp != 3 && temp != 4 && temp != 6)
						{
							cout << "\nPlik jest uszkodzony" << endl;
							return -1;
						}
						wierz = num_na_wierz(temp);
						pion = gr3->getpiony(wybor_piona(wierz, wys));
						pl3->setpole_piona(i, j, pion);
						pion->setwspolrz(i, j);
					}
					else
					{
						cout << "\nPlik uszkodzony." << endl;
						return -1;
					}
				}
				else
				{
					cout << "\nPlik uszkodzony." << endl;
					return -1;
				}
			}
		}
		fclose(stream);
		return 0;
	}
}

kolor znak_na_kolor(char barwa)
{
	if (barwa == 'S')
		return SZARY;
	if (barwa == 'B')
		return BIALY;
	if (barwa == 'C')
		return CZARNY;
}

int zapis_trybu(gracz*gr1, gracz*gr2, gracz*gr3)
{
	FILE*stream;
	if ((stream = fopen("tryb.txt", "w")) == NULL)
	{
		cout << "Nie mozna zapisac trybu gry." << endl;
		return -1;
	}
	else
	{
		int flaga = 0;
		if (strcmp(gr1->getnick(), "komputer") == 0)
			flaga += 1;
		if (strcmp(gr2->getnick(), "komputer") == 0)
			flaga += 1;
		if (strcmp(gr3->getnick(), "komputer") == 0)
			flaga += 1;
		fprintf(stream, "%d", flaga);
		fclose(stream);
	}
}

int zapis_punktacji(gracz*gr1, gracz*gr2, gracz*gr3)
{
	FILE* stream;
	if ((stream = fopen("punkty.txt", "a+")) == NULL)
	{
		cout << "\n\tNie mozna zapisac punktacji." << endl;
		return -1;
	}
	else
	{
		fprintf(stream, "%c ", 'R');
		fprintf(stream, "\n%s %d", gr1->getnick(), gr1->getpunkty());
		fprintf(stream, "\n%s %d", gr2->getnick(), gr2->getpunkty());
		fprintf(stream, "\n%s %d", gr3->getnick(), gr3->getpunkty());
		fclose(stream);
		return 0;
	}
}

int odczyt_punktacji()
{
	FILE *stream;
	if ((stream = fopen("punkty.txt", "r")) == NULL)
	{
		cout << "\n\tNie mozna odczytac punktacji." << endl;
		return 1;
	}
	else
	{
		int i;
		char znak;
		int punkty1, punkty2, punkty3;
		char nazwa1[50], nazwa2[50], nazwa3[50];
		for (i=0;feof(stream) == 0;i++)
		{
			if (fscanf(stream, "%c", &znak) ==EOF)
			{
				if (i == 0)
				{
					cout << "\n\tBrak rozgrywek." << endl;
					fclose(stream);
					return 0;
				}
				else
				{
					fclose(stream);
					return 0;
				}
			}
			if (znak != 'R')
			{
				cout << "\nPlik uszkodzony." << endl;
				//czyszczenie pliku
				fclose(stream);
				if ((stream = fopen("punkty.txt", "w")) == NULL)
					return 2;
				fclose(stream);
				return 3;
			}
			//gracz 1
			fscanf(stream, "%s %d", nazwa1, &punkty1);
			if (punkty1 < 0)
			{
				cout << "\nPlik uszkodzony." << endl;
				//czyszczenie pliku
				fclose(stream);
				if ((stream = fopen("punkty.txt", "w")) == NULL)
					return 2;
				fclose(stream);
				return 3;
			}
			//gracz 2
			fscanf(stream, "%s %d", nazwa2, &punkty2);
			if (punkty2 < 0)
			{
				cout << "\nPlik uszkodzony." << endl;
				//czyszczenie pliku
				fclose(stream);
				if ((stream = fopen("punkty.txt", "w")) == NULL)
					return 2;
				fclose(stream);
				return 3;
			}
			//gracz 3
			fscanf(stream, "%s %d", nazwa3, &punkty3);
			if (punkty3 < 0)
			{
				cout << "\nPlik uszkodzony." << endl;
				//czyszczenie pliku
				fclose(stream);
				if ((stream = fopen("punkty.txt", "w")) == NULL)
					return 2;
				fclose(stream);
				return 3;
			}
			cout << "\tROZGRYWKA " << i + 1 << endl;
			cout.width(20);
			cout << left << nazwa1;
			cout.width(2);
			cout << punkty1 << endl;
			cout.width(20);
			cout << left << nazwa2;
			cout.width(2);
			cout << punkty2 << endl;
			cout.width(20);
			cout << left << nazwa3;
			cout.width(2);
			cout << punkty3 << endl;
		}
		return 0;
		fclose(stream);
	}
}

int rozgrywka(gracz*gr1, gracz*gr2, gracz*gr3, plansza*p1, plansza*p2, plansza*p3)
{
	int i;
	for (i = 0; i <= 8; i++)
	{
		cout << endl << "\tKOLEJKA " << i + 1 << endl;
		cout << endl << gr1->getnick() << endl;
		gr1->ustawianie();
		cout << endl << gr2->getnick() << endl;
		gr2->ustawianie();
		cout << endl << gr3->getnick() << endl;
		gr3->ustawianie();
	}
	while (1)
	{
		int koniec = 1;
		if (koniec_gry(p1, p2, p3, gr1, gr2, gr3) == 0)
			break;
		cout << endl << "\n\tPodaj 0 - jesli chcesz przerwac rozgrywke, 1 - jesli chcesz kontynuowac";
		while (scanf("%d", &koniec) != 1 || koniec != 0 && koniec != 1 || getchar() != '\n')
		{
			cout << endl << "Podaj 0, aby zakonczyc lub 1, aby kontynuowac rozgrywke" << endl;
			while (getchar() != '\n');
		}
		if (koniec == 0)
		{
			if (przerwanie_gry(gr1, gr2, gr3, p1, p2, p3) == 0)
				return 0;
		}
		cout << endl << "\tKOLEJKA " << i + 1 << endl;
		if (kolejka(gr1))
		{
			cout << endl << gr1->getnick() << endl;
			gr1->ruch_gracza();
		}
		if (koniec_gry(p1, p2, p3, gr1, gr2, gr3) == 0)
			break;
		if (kolejka(gr2))
		{
			cout << endl << gr2->getnick() << endl;
			gr2->ruch_gracza() == 1;
		}
		if (koniec_gry(p1, p2, p3, gr1, gr2, gr3) == 0)
			break;
		if (kolejka(gr3))
		{
			cout << endl << gr3->getnick() << endl;
			gr3->ruch_gracza();
		}
		if (koniec_gry(p1, p2, p3, gr1, gr2, gr3) == 0)
			break;
		i++;
	}
	zapis_punktacji(gr1, gr2, gr3);
	return 0;
}

int przerwanie_gry(gracz*gr1, gracz*gr2, gracz*gr3, plansza*p1, plansza*p2, plansza*p3)
{
	int wybor;
	cout << "\tCzy chcesz zapisac przerwna gre?\n0 - zapisz, 1 - nie zapisuj, 2 - wroc do gry" << endl;
	while(scanf("%d", &wybor)!=1||wybor<0||wybor>2||getchar()!='\n')
	{
		cout << "Wybierz 0, aby zapisac albo 1, aby nie zapisywac, 2 - wroc do gry." << endl;
		while (getchar() != '\n');
	}
	if (wybor == 0)
	{
		zapis(p1, p2, p3, gr1, gr2, gr3);
		return 0;
	}
	else if (wybor == 1)
	{
		return 0;
	}
	else if (wybor == 2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int rozgrywka_zapisanej(gracz*gr1, gracz*gr2, gracz*gr3, plansza*p1, plansza*p2, plansza*p3)
{
	int i = 0;
	while (1)
	{
		int koniec = 1;
		if (koniec_gry(p1, p2, p3, gr1, gr2, gr3) == 0)
			break;
		cout << endl << "\tKOLEJKA " << i + 1 << endl;
		if (kolejka(gr1))
		{
			cout << endl << gr1->getnick() << endl;
			gr1->ruch_gracza();
		}
		if (koniec_gry(p1, p2, p3, gr1, gr2, gr3) == 0)
			break;
		if (kolejka(gr2))
		{
			cout << endl << gr2->getnick() << endl;
			gr2->ruch_gracza() == 1;
		}
		if (koniec_gry(p1, p2, p3, gr1, gr2, gr3) == 0)
			break;
		if (kolejka(gr3))
		{
			cout << endl << gr3->getnick() << endl;
			gr3->ruch_gracza();
		}
		if (koniec_gry(p1, p2, p3, gr1, gr2, gr3) == 0)
			break;
		cout << endl << "\n\tPodaj 0 - jesli chcesz przerwac rozgrywke, 1 - jesli chcesz kontynuowac" << endl;
		while (scanf("%d", &koniec) != 1 || koniec != 0 && koniec != 1 || getchar() != '\n')
		{
			cout << endl << "Podaj 0, aby zakonczyc lub 1, aby kontynuowac rozgrywke" << endl;
			while (getchar() != '\n');
		}
		if (koniec == 0)
		{
			if (przerwanie_gry(gr1, gr2, gr3, p1, p2, p3) == 0)
				return 0;
		}
		i++;
	}
	zapis_punktacji(gr1, gr2, gr3);
	return 0;
}

int odczyt_trybu()
{
	FILE*stream1;
	int tryb;
	if ((stream1 = fopen("tryb.txt", "r")) == NULL)
	{
		cout << "\tNie udalo sie odczytac trybu zapisanej gry." << endl;
		return -1;
	}
	else
	{
		fscanf(stream1, "%d", &tryb);
		if (tryb ==0)
		{
			return 1;
		}
		else if (tryb == 1)
		{
			return 2;
		}
		else if (tryb == 2)
		{
			return 3;
		}
		else
		{
			cout << "\tNie udalo sie odczytac trybu zapisanej gry." << endl;
			return -1;
		}
	}
}

void wyswietl_piony()
{
	HANDLE kolor;
	kolor = GetStdHandle(STD_OUTPUT_HANDLE);
	cout.width(15);
	cout << endl << "TROJKAT - V";
	cout.width(15);
	cout << "CZWOROKAT - X";
	cout.width(15);
	cout << "SZESCIOBOK - O" << endl;
	cout << endl << "\tSZARE PIONY" << endl << endl;
	cout << "\tMale piony:";
	cout << "\t";
	SetConsoleTextAttribute(kolor, 0x37);
	cout << "V";
	cout << "X";
	cout << "O";
	SetConsoleTextAttribute(kolor, 7);
	cout << endl << "\tSrednie piony:";
	cout << "\t";
	SetConsoleTextAttribute(kolor, 0x38);
	cout << "V";
	cout << "X";
	cout << "O";
	SetConsoleTextAttribute(kolor, 7);
	cout << endl << "\tDuze piony:";
	cout << "\t";
	SetConsoleTextAttribute(kolor, 0x36);
	cout << "V";
	cout << "X";
	cout << "O";
	SetConsoleTextAttribute(kolor, 7);
	cout << endl << endl << "\tBIALE PIONY" << endl << endl;
	cout << "\tMale piony:";
	cout << "\t";
	SetConsoleTextAttribute(kolor, 0x07);
	cout << "V";
	cout << "X";
	cout << "O" << endl;
	SetConsoleTextAttribute(kolor, 7);
	cout << "\tSrednie piony:";
	cout << "\t";
	SetConsoleTextAttribute(kolor, 0x08);
	cout << "V";
	cout << "X";
	cout << "O" << endl;
	SetConsoleTextAttribute(kolor, 7);
	cout << "\tDuze piony:";
	cout << "\t";
	SetConsoleTextAttribute(kolor, 0x06);
	cout << "V";
	cout << "X";
	cout << "O" << endl;
	SetConsoleTextAttribute(kolor, 7);
	cout << endl << "\tCZARNE PIONY" << endl << endl;
	cout << "\tMale piony:";
	cout << "\t";
	SetConsoleTextAttribute(kolor, 0x03);
	cout << "V";
	cout << "X";
	cout << "O" << endl;
	SetConsoleTextAttribute(kolor, 7);
	cout << "\tSrednie piony:";
	cout << "\t";
	SetConsoleTextAttribute(kolor, 0x09);
	cout << "V";
	cout << "X";
	cout << "O" << endl;
	SetConsoleTextAttribute(kolor, 7);
	cout << "\tDuze piony:";
	cout << "\t";
	SetConsoleTextAttribute(kolor, 0x01);
	cout << "V";
	cout << "X";
	cout << "O" << endl << endl;
	SetConsoleTextAttribute(kolor, 7);
}