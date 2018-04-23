#include <iostream>
#include "talat_obiekty2.h"
#include "obsluga_gry.h"
#include <Windows.h>
#include <ctime>
int wybor_piona(wierzcholki, wysokosc);
int main()
{
	srand(time(0));
	using namespace std;
	bool flaga = 1;
	bool czyta = 0;
	cout << "Autor programu: Joanna Izdebska" << endl << endl;
	while (flaga)
	{
		czyta = 0;
		plansza*p1 = new plansza(BIALY, CZARNY);
		plansza*p2 = new plansza(BIALY, SZARY);
		plansza*p3 = new plansza(CZARNY, SZARY);
		gracz*gr1;
		gracz*gr2;
		gracz*gr3;
		int wybor, gra;
		cout << "\tMENU" << endl << endl;
		cout << "Wybierz numer przypisany do czynnosci, aby ja wykonac" << endl;
		cout << "0 - zakoncz program" << endl;
		cout << "1 - rozpocznij nowa gre" << endl;
		cout << "2 - kontynuuj zapisana rozgrywke" << endl;
		cout << "3 - wyswietl tabele z punktacja" << endl;
		cout << "4 - pokaz wyglad pionkow" << endl;
		while (scanf("%d", &wybor) != 1 || wybor < 0 || wybor>4 || getchar() != '\n')
		{
			cout << "\tWybierz 0, 1, 2, 3 lub 4!" << endl;
			while (getchar() != '\n');
		}
		switch (wybor)
		{
		case 0:flaga = 0;
			break;
		case 1: 	cout << "\tMENU" << endl << endl;
			cout << "Wybierz numer, aby wybrac tryb gry" << endl;
			cout << "1 - tryb trzech graczy" << endl;
			cout << "2 - tryb dwoch graczy z komputerem" << endl;
			cout << "3 - tryb jednego gracza z komputerem" << endl;
			cout << "4 - powrot do menu" << endl;
			while (scanf("%d", &gra) != 1 || gra < 1 || gra>4 || getchar() != '\n')
			{
				cout << "\tWybierz 1, 2, 3 lub 4!" << endl;
				while (getchar() != '\n');
			}
			switch (gra)
			{
				case 1:		
					gr1 = new gracz_czlowiek(p1, p2);
					gr2 = new gracz_czlowiek(p1, p3);
					gr3 = new gracz_czlowiek(p2, p3);
					gr1->pobierz_nick(1);
					gr2->pobierz_nick(2);
					gr3->pobierz_nick(3);
					break;
				case 2:		
					gr1 = new gracz_czlowiek(p1, p2);
					gr2 = new gracz_czlowiek(p1, p3);
					gr3 = new gracz_komputer(p2, p3);
					gr1->pobierz_nick(1);
					gr2->pobierz_nick(2);
					gr3->pobierz_nick(3);
					break;
				case 3:		
					gr1 = new gracz_czlowiek(p1, p2);
					gr2 = new gracz_komputer(p1, p3);
					gr3 = new gracz_komputer(p2, p3);
					gr1->pobierz_nick(1);
					gr2->pobierz_nick(2);
					gr3->pobierz_nick(3);
					break;
				case 4:
					czyta = 1;
					break;
			}
			if (czyta == 1)
				break;
			rozgrywka(gr1, gr2, gr3, p1, p2, p3);
			break;
		case 2:if ((gra = odczyt_trybu()) == -1)
			break;
			switch (gra)
			{
			case 1:		
				gr1 = new gracz_czlowiek(p1, p2);
				gr2 = new gracz_czlowiek(p1, p3);
				gr3 = new gracz_czlowiek(p2, p3);
				break;
			case 2:		
				gr1 = new gracz_czlowiek(p1, p2);
				gr2 = new gracz_czlowiek(p1, p3);
				gr3 = new gracz_komputer(p2, p3);
				break;
			case 3:		
				gr1 = new gracz_czlowiek(p1, p2);
				gr2 = new gracz_komputer(p1, p3);
				gr3 = new gracz_komputer(p2, p3);
				break;
			}
			if(odczyt(p1, p2, p3, gr1, gr2, gr3) != 0)
			break;
			rozgrywka_zapisanej(gr1, gr2, gr3, p1, p2, p3);
			break;
		case 3: odczyt_punktacji();
			czyta = 1;
			break;
		case 4: wyswietl_piony();
			czyta = 1;
			break;
		}
		if (flaga == 0)
			break;
		if (czyta == 1)
			continue;
		delete gr1;
		delete gr2;
		delete gr3;
		delete p1;
		delete p2;
		delete p3;
	}
	return 0;
}