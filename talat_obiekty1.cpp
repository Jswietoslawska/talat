#include <iostream>
#include "talat_obiekty2.h"
#include "obsluga_gry.h""
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include <cstdio>

using namespace std;
plansza::plansza(kolor barwa1, kolor barwa2):
	gracz1(barwa1), gracz2(barwa2), zamrozona(1)
{
	for (int i = 0; i < ROZMIAR; i++)
	{
		for (int j = 0; j < ROZMIAR; j++)
		{
			pole_piona[i][j] = NULL;
		}
	}
}

pionek::pionek(wierzcholki wierz, wysokosc wys, kolor barwa):
	dl(-1), szer(-1), wierz_piona(wierz), wys_piona(wys), kolor_piona(barwa)
{
	dl = -1;
	szer = -1;
	wierz_piona = wierz;
	wys_piona = wys;
}

gracz::gracz(plansza*plansz1, plansza* plansz2):
	plansza1(plansz1), plansza2(plansz2)
{
	if ((plansza1->getkolor1() == plansza2->getkolor1()) || (plansza1->getkolor1() == plansza2->getkolor2()))
	{
		kolor_gracza = plansza1->getkolor1();
	}
	else if ((plansza1->getkolor2() == plansza2->getkolor1()) || (plansza1->getkolor2() == plansza2->getkolor2()))
	{
		kolor_gracza = plansza1->getkolor2();
	}
	else
	{
		printf("Ups. Cos poszlo nie tak.\n"); //OBSLUGA WYJATKOW
	}
	punkty = 0;
	piony[0] = new pionek(TROJKAT, MALY, kolor_gracza);
	piony[1] = new pionek(TROJKAT, SREDNI, kolor_gracza);
	piony[2] = new pionek(TROJKAT, DUZY, kolor_gracza);
	piony[3] = new pionek(KWADRAT, MALY, kolor_gracza);
	piony[4] = new pionek(KWADRAT, SREDNI, kolor_gracza);
	piony[5] = new pionek(KWADRAT, DUZY, kolor_gracza);
	piony[6] = new pionek(SZESCIOKAT, MALY, kolor_gracza);
	piony[7] = new pionek(SZESCIOKAT, SREDNI, kolor_gracza);
	piony[8] = new pionek(SZESCIOKAT, DUZY, kolor_gracza);
}

gracz::~gracz()
{
	int i;
	for (i = 0; i < WIEZE; i++)
	{
		delete piony[i];
	}
}

plansza::~plansza()
{
	
}

int gracz::ustaw(szerokosc szero, pionek*pion, plansza*plan)
{
	if (kolor_gracza == plan->getkolor2()) //kolor na dole
	{
		pion->setwspolrz(0, szero - 1);
		plan->setpole_piona(0, szero - 1, pion);
		plan->wyswietl_plansze();
		return 0;
	}
	else if (kolor_gracza == plan->getkolor1()) //kolor na gorze
	{
		pion->setwspolrz(4, szero - 1);
		plan->setpole_piona(4, szero - 1, pion);
		plan->wyswietl_plansze();
		return 0;
	}
	else
	{
		cout << endl << "Cos poszlo nie tak... To nie Twoja plansza!" << endl;
		return 5;
	}
}

int gracz::ruch_piona(pionek*pion, ruch rusza)
{
	plansza*plan;
	int i, j;
	//sprawdzanie na ktorej planszy stoi pionek
	for (i = 0; i < ROZMIAR; i++)
	{
		for (j = 0; j < ROZMIAR; j++)
		{
			if (plansza2->getpole_piona(i, j) == pion)
				plan = plansza2;
			if (plansza1->getpole_piona(i, j) == pion)
				plan = plansza1;
		}
	}
	cout << endl << "Po ruchu:" << endl;
	dlugosc dlug = pion->getdlugosc();
	szerokosc szero = pion->getszerokosc();
	if (kolor_gracza == plan->getkolor2()) //kolor na dole
	{
		if (rusza == 1)
		{
			pion->setwspolrz(dlug + 1, szero - 1);
			plan->setpole_piona(dlug + 1, szero - 1, pion);
			plan->setpole_piona(dlug, szero, NULL);
			plan->wyswietl_plansze();
			return 0;
		}
		else if (rusza == 2)
		{
			pion->setwspolrz(dlug + 1, szero);
			plan->setpole_piona(dlug + 1, szero, pion);
			plan->setpole_piona(dlug, szero, NULL);
			plan->wyswietl_plansze();
			return 0;
		}
		else if (rusza == 3)
		{
			pion->setwspolrz(dlug + 1, szero + 1);
			plan->setpole_piona(dlug + 1, szero + 1, pion);
			plan->setpole_piona(dlug, szero, NULL);
			plan->wyswietl_plansze();
			return 0;
		}
		else
		{
			cout << endl << "Cos poszlo nie tak... Ten ruch nie byl dozwolony!" << endl;
			return 5;
		}
	}
	else if (kolor_gracza == plan->getkolor1()) //kolor na gorze
	{
		if (rusza == 1)
		{
			pion->setwspolrz(dlug - 1, szero - 1);
			plan->setpole_piona(dlug - 1, szero - 1, pion);
			plan->setpole_piona(dlug, szero, NULL);
			plan->wyswietl_plansze();
			return 0;
		}
		else if (rusza == 2)
		{
			pion->setwspolrz(dlug - 1, szero);
			plan->setpole_piona(dlug - 1, szero, pion);
			plan->setpole_piona(dlug, szero, NULL);
			plan->wyswietl_plansze();
			return 0;
		}
		else if (rusza == 3)
		{
			pion->setwspolrz(dlug - 1, szero + 1);
			plan->setpole_piona(dlug - 1, szero + 1, pion);
			plan->setpole_piona(dlug, szero, NULL);
			plan->wyswietl_plansze();
			return 0;
		}
		else
		{
			 cout << endl << "Cos poszlo nie tak... Ten ruch nie byl dozwolony!" << endl;
			return 5;
		}
	}
	else
	{
		cout << endl << "Cos poszlo nie tak... To nie Twoja plansza!" << endl;
		return 5;
	}
}

int gracz::bicie(pionek*pion, ruch rusza, plansza* plan)
{
	dlugosc dlug = pion->getdlugosc();
	szerokosc szero = pion->getszerokosc();
	if (kolor_gracza == plan->getkolor2())//kolor z dolu
	{
		if (rusza == 1 && plan->getpole_piona(dlug + 1, szero - 1) == NULL)
			return 1;
		if (rusza == 2 && plan->getpole_piona(dlug + 1, szero) == NULL)
			return 1;
		if (rusza == 3 && plan->getpole_piona(dlug + 1, szero + 1) == NULL)
			return 1;
		for (int i = 0; i < WIEZE; i++) //zabezpieczenie przed zbijaniem wlasnych pionow
		{
			if (rusza == 1 && plan->getpole_piona(dlug + 1, szero - 1) == piony[i])
				return 2;
			if (rusza == 2 && plan->getpole_piona(dlug + 1, szero) == piony[i])
				return 2;
			if (rusza == 3 && plan->getpole_piona(dlug + 1, szero + 1) == piony[i])
				return 2;
		}
		//zbijanie przez wyzsze o oczko
		if (rusza == 1 && plan->getpole_piona(dlug + 1, szero - 1)->getwys() + 1 == pion->getwys())
		{
			plan->getpole_piona(dlug + 1, szero - 1)->setwspolrz(-1, -1);
			pion->setwspolrz(dlug + 1, szero - 1);
			plan->setpole_piona(dlug + 1, szero - 1, pion);
			plan->setpole_piona(dlug, szero, NULL);
			this->setpunkty(5);
			cout << endl << "\tZbiles pionek!" << endl;
			plan->wyswietl_plansze();
			return 0;
		}
		if (rusza == 2 && plan->getpole_piona(dlug + 1, szero)->getwys() + 1 == pion->getwys())
		{
			plan->getpole_piona(dlug + 1, szero)->setwspolrz(-1, -1);
			pion->setwspolrz(dlug + 1, szero);
			plan->setpole_piona(dlug + 1, szero, pion);
			plan->setpole_piona(dlug, szero, NULL);
			this->setpunkty(5);
			cout << endl <<"\tZbiles pionek!" << endl;
			plan->wyswietl_plansze();
			return 0;
		}
		if (rusza == 3 && plan->getpole_piona(dlug + 1, szero + 1)->getwys() + 1 == pion->getwys())
		{
			plan->getpole_piona(dlug + 1, szero + 1)->setwspolrz(-1, -1);
			pion->setwspolrz(dlug + 1, szero + 1);
			plan->setpole_piona(dlug + 1, szero + 1, pion);
			plan->setpole_piona(dlug, szero, NULL);
			this->setpunkty(5);
			cout << endl << "\tZbiles pionek!" << endl;
			plan->wyswietl_plansze();
			return 0;
		}
		//zbijanie przez piony z wieksza iloscia bokow
		if (rusza == 1 && plan->getpole_piona(dlug + 1, szero -1)->getwys() == pion->getwys()&& plan->getpole_piona(dlug + 1, szero - 1)->getwierz() < pion->getwierz())
		{
			plan->getpole_piona(dlug + 1, szero - 1)->setwspolrz(-1, -1);
			pion->setwspolrz(dlug + 1, szero - 1);
			plan->setpole_piona(dlug + 1, szero - 1, pion);
			plan->setpole_piona(dlug, szero, NULL);
			this->setpunkty(5);
			cout << endl << "\tZbiles pionek!" << endl;
			plan->wyswietl_plansze();
			return 0;
		}
		if (rusza == 2 && plan->getpole_piona(dlug + 1, szero)->getwierz() < pion->getwierz()&& plan->getpole_piona(dlug + 1, szero)->getwys()== pion->getwys())
		{
			plan->getpole_piona(dlug + 1, szero)->setwspolrz(-1, -1);
			pion->setwspolrz(dlug + 1, szero);
			plan->setpole_piona(dlug + 1, szero, pion);
			plan->setpole_piona(dlug, szero, NULL);
			this->setpunkty(5);
			cout << endl << "\tZbiles pionek!" << endl;
			plan->wyswietl_plansze();
			return 0;
		}
		if (rusza == 3 && plan->getpole_piona(dlug + 1, szero + 1)->getwierz()< pion->getwierz()&& plan->getpole_piona(dlug + 1, szero + 1)->getwys() == pion->getwys())
		{
			plan->getpole_piona(dlug + 1, szero + 1)->setwspolrz(-1, -1);
			pion->setwspolrz(dlug + 1, szero + 1);
			plan->setpole_piona(dlug + 1, szero + 1, pion);
			plan->setpole_piona(dlug, szero, NULL);
			this->setpunkty(5);
			cout << endl << "\tZbiles pionek!" << endl;
			plan->wyswietl_plansze();
			return 0;
		}
		//zasada Dawida i Goliata
		if (rusza == 1 && plan->getpole_piona(dlug + 1, szero - 1)->getwys() ==3&& pion->getwys()==1 && plan->getpole_piona(dlug + 1, szero - 1)->getwierz() ==6&& pion->getwierz()==3)
		{
			plan->getpole_piona(dlug + 1, szero - 1)->setwspolrz(-1, -1);
			pion->setwspolrz(dlug + 1, szero - 1);
			plan->setpole_piona(dlug + 1, szero - 1, pion);
			plan->setpole_piona(dlug, szero, NULL);
			this->setpunkty(5);
			cout << endl << "\tZbiles pionek!" << endl;
			plan->wyswietl_plansze();
			return 0;
		}
		if (rusza == 2 && plan->getpole_piona(dlug + 1, szero)->getwierz() ==6&& pion->getwierz()==3 && plan->getpole_piona(dlug + 1, szero)->getwys() ==3&& pion->getwys()==1)
		{
			plan->getpole_piona(dlug + 1, szero)->setwspolrz(-1, -1);
			pion->setwspolrz(dlug + 1, szero);
			plan->setpole_piona(dlug + 1, szero, pion);
			plan->setpole_piona(dlug, szero, NULL);
			this->setpunkty(5);
			cout << endl << "\tZbiles pionek!" << endl;
			plan->wyswietl_plansze();
			return 0;
		}
		if (rusza == 3 && plan->getpole_piona(dlug + 1, szero + 1)->getwierz()==6&& pion->getwierz()==3 && plan->getpole_piona(dlug + 1, szero + 1)->getwys() ==3&& pion->getwys()==1)
		{
			plan->getpole_piona(dlug + 1, szero + 1)->setwspolrz(-1, -1);
			pion->setwspolrz(dlug + 1, szero + 1);
			plan->setpole_piona(dlug + 1, szero + 1, pion);
			plan->setpole_piona(dlug, szero, NULL);
			this->setpunkty(5);
			cout << endl << "\tZbiles pionek!" << endl;
			plan->wyswietl_plansze();
			return 0;
		}
	}
	else if (kolor_gracza == plan->getkolor1())//kolor na gorze
	{
		if (rusza == 1 && plan->getpole_piona(dlug - 1, szero - 1) == NULL)
			return 1;
		if (rusza == 2 && plan->getpole_piona(dlug - 1, szero) == NULL)
			return 1;
		if (rusza == 3 && plan->getpole_piona(dlug - 1, szero + 1) == NULL)
			return 1;
		for (int i = 0; i < WIEZE; i++) //zabezpieczenie przed zbijaniem wlasnych pionow
		{
			if (rusza == 1 && plan->getpole_piona(dlug - 1, szero - 1) == piony[i])
				return 2;
			if (rusza == 2 && plan->getpole_piona(dlug - 1, szero) == piony[i])
				return 2;
			if (rusza == 3 && plan->getpole_piona(dlug - 1, szero + 1) == piony[i])
				return 2;
		}
		//zbijanie przez wyzsze o oczko
		if (rusza == 1 && plan->getpole_piona(dlug - 1, szero - 1)->getwys() + 1 == pion->getwys())
		{
			plan->getpole_piona(dlug - 1, szero - 1)->setwspolrz(-1, -1);
			pion->setwspolrz(dlug - 1, szero - 1);
			plan->setpole_piona(dlug - 1, szero - 1, pion);
			plan->setpole_piona(dlug, szero, NULL);
			this->setpunkty(5);
			cout << endl << "\tZbiles pionek!" << endl;
			plan->wyswietl_plansze();
			return 0;
		}
		if (rusza == 2 && plan->getpole_piona(dlug - 1, szero)->getwys() + 1 == pion->getwys())
		{
			plan->getpole_piona(dlug - 1, szero)->setwspolrz(-1, -1);
			pion->setwspolrz(dlug - 1, szero);
			plan->setpole_piona(dlug - 1, szero, pion);
			plan->setpole_piona(dlug, szero, NULL);
			this->setpunkty(5);
			cout << endl << "\tZbiles pionek!" << endl;
			plan->wyswietl_plansze();
			return 0;
		}
		if (rusza == 3 && plan->getpole_piona(dlug - 1, szero + 1)->getwys() + 1 == pion->getwys())
		{
			plan->getpole_piona(dlug - 1, szero + 1)->setwspolrz(-1, -1);
			pion->setwspolrz(dlug - 1, szero + 1);
			plan->setpole_piona(dlug - 1, szero+1, pion);
			plan->setpole_piona(dlug, szero, NULL);
			this->setpunkty(5);
			cout << endl << "\tZbiles pionek!" << endl;
			plan->wyswietl_plansze();
			return 0;
		}
		//zbijanie przez piony z wieksza iloscia bokow
		if (rusza == 1 && plan->getpole_piona(dlug - 1, szero - 1)->getwys() == pion->getwys() && plan->getpole_piona(dlug - 1, szero - 1)->getwierz() < pion->getwierz())
		{
			plan->getpole_piona(dlug - 1, szero - 1)->setwspolrz(-1, -1);
			pion->setwspolrz(dlug - 1, szero - 1);
			plan->setpole_piona(dlug - 1, szero - 1, pion);
			plan->setpole_piona(dlug, szero, NULL);
			this->setpunkty(5);
			cout << endl << "\tZbiles pionek!" << endl;
			plan->wyswietl_plansze();
			return 0;
		}
		if (rusza == 2 && plan->getpole_piona(dlug - 1, szero)->getwierz() < pion->getwierz() && plan->getpole_piona(dlug - 1, szero)->getwys() == pion->getwys())
		{
			plan->getpole_piona(dlug - 1, szero )->setwspolrz(-1, -1);
			pion->setwspolrz(dlug - 1, szero);
			plan->setpole_piona(dlug - 1, szero, pion);
			plan->setpole_piona(dlug, szero, NULL);
			this->setpunkty(5);
			cout << endl << "\tZbiles pionek!" << endl;
			plan->wyswietl_plansze();
			return 0;
		}
		if (rusza == 3 && plan->getpole_piona(dlug - 1, szero + 1)->getwierz()< pion->getwierz() && plan->getpole_piona(dlug - 1, szero + 1)->getwys() == pion->getwys())
		{
			plan->getpole_piona(dlug - 1, szero + 1)->setwspolrz(-1, -1);
			pion->setwspolrz(dlug - 1, szero + 1);
			plan->setpole_piona(dlug - 1, szero + 1, pion);
			plan->setpole_piona(dlug, szero, NULL);
			this->setpunkty(5);
			cout << endl << "\tZbiles pionek!" << endl;
			plan->wyswietl_plansze();
			return 0;
		}
		//zasada Dawida i Goliata
		if (rusza == 1 && plan->getpole_piona(dlug - 1, szero - 1)->getwys() == 3 && pion->getwys() == 1 && plan->getpole_piona(dlug - 1, szero - 1)->getwierz() == 6 && pion->getwierz() == 3)
		{
			plan->getpole_piona(dlug - 1, szero - 1)->setwspolrz(-1, -1);
			pion->setwspolrz(dlug - 1, szero - 1);
			plan->setpole_piona(dlug - 1, szero - 1, pion);
			plan->setpole_piona(dlug, szero, NULL);
			this->setpunkty(5);
			cout << endl << "\tZbiles pionek!" << endl;
			plan->wyswietl_plansze();
			return 0;
		}
		if (rusza == 2 && plan->getpole_piona(dlug - 1, szero)->getwierz() == 6 && pion->getwierz() == 3 && plan->getpole_piona(dlug - 1, szero)->getwys() == 3 && pion->getwys() == 1)
		{
			plan->getpole_piona(dlug - 1, szero)->setwspolrz(-1, -1);
			pion->setwspolrz(dlug - 1, szero);
			plan->setpole_piona(dlug - 1, szero, pion);
			plan->setpole_piona(dlug, szero, NULL);
			this->setpunkty(5);
			cout << endl << "\tZbiles pionek!" << endl;
			plan->wyswietl_plansze();
			return 0;
		}
		if (rusza == 3 && plan->getpole_piona(dlug - 1, szero + 1)->getwierz() == 6 && pion->getwierz() == 3 && plan->getpole_piona(dlug - 1, szero + 1)->getwys() == 3 && pion->getwys() == 1)
		{
			plan->getpole_piona(dlug - 1, szero + 1)->setwspolrz(-1, -1);
			pion->setwspolrz(dlug - 1, szero + 1);
			plan->setpole_piona(dlug - 1, szero + 1, pion);
			plan->setpole_piona(dlug, szero, NULL);
			this->setpunkty(5);
			cout << endl << "\tZbiles pionek!" << endl;
			plan->wyswietl_plansze();
			return 0;
		}
		
	}
	else
	{
			cout << endl << "Cos poszlo nie tak... To nie Twoja plansza!" << endl;
			return 5;
	}

}

int plansza::wyswietl_plansze()
{
	HANDLE kolor;
	kolor = GetStdHandle(STD_OUTPUT_HANDLE);
	if (zamrozona == 0)
		return 2;
	char*kolor1;
	char*kolor2;
	if (this->getkolor1() == BIALY)
	{
		kolor1 = "BIALY";
	}
	else if(this->getkolor1() == CZARNY)
	{
		kolor1 = "CZARNY";
	}
	else if(this->getkolor1() == SZARY)
	{
		kolor1 = "SZARY";
	}
	else
	{
		cout << endl << "Ups... Co to za kolor?" << endl;
		return 1;
	}
	if (this->getkolor2() == BIALY)
	{
		kolor2 = "BIALY";
	}
	else if (this->getkolor2() == CZARNY)
	{
		kolor2 = "CZARNY";
	}
	else if (this->getkolor2() == SZARY)
	{
		kolor2 = "SZARY";
	}
	else
	{
		cout << endl << "Ups... Co to za kolor?" << endl;
		return 1;
	}
	cout << endl;
	for (int i = ROZMIAR-1; i >=0; i--)
	{
		for (int j =0; j<ROZMIAR; j++)
		{
			char znak='_';
			if (pole_piona[i][j] != NULL)
			{
				if (pole_piona[i][j]->getwierz() == 3)
					znak = 'V';
				if (pole_piona[i][j]->getwierz() == 4)
					znak = 'X';
				if (pole_piona[i][j]->getwierz() == 6)
					znak = 'O';
			}
			else
				znak = '_';
			//bialy
			putchar('|');
			if (pole_piona[i][j] != NULL&&pole_piona[i][j]->getkolor() == BIALY)
			{
				if (pole_piona[i][j]->getwys() == 1)
					SetConsoleTextAttribute(kolor, 0x07);
				else if (pole_piona[i][j]->getwys() == 2)
					SetConsoleTextAttribute(kolor, 0x08);
				else
					SetConsoleTextAttribute(kolor, 0x06);
				cout << znak;
				SetConsoleTextAttribute(kolor, 7);
			}
			else if (pole_piona[i][j] != NULL&&pole_piona[i][j]->getkolor() == SZARY)
			{
				if (pole_piona[i][j]->getwys() == 1)
					SetConsoleTextAttribute(kolor, 0x37);
				else if (pole_piona[i][j]->getwys() == 2)
					SetConsoleTextAttribute(kolor, 0x38);
				else
					SetConsoleTextAttribute(kolor, 0x36);
				cout << znak;
				SetConsoleTextAttribute(kolor, 7);
			}
			else if (pole_piona[i][j] != NULL&&pole_piona[i][j]->getkolor() == CZARNY)
			{
				if (pole_piona[i][j]->getwys() == 1)
					SetConsoleTextAttribute(kolor, 0x03);
				else if (pole_piona[i][j]->getwys() == 2)
					SetConsoleTextAttribute(kolor, 0x09);
				else
					SetConsoleTextAttribute(kolor, 0x01);
				cout << znak;
				SetConsoleTextAttribute(kolor, 7);
			}
			else
				cout << znak;
		}
		if (i == 0)
		{
			cout << "| " << kolor2 << endl;
		}
		else if (i == 4)
		{
			cout << "| " << kolor1 << endl;
		}
		else
			cout << "|" << endl;
	}
}

int plansza::czy_puste_pole(dlugosc a, szerokosc b)
{
	if (pole_piona[a][b] != NULL)
		return 1;
	else 
		return 0;
};

int plansza::zamrozenie()
{
	int j,i;
	bool flaga = 0;
	for (i = 0; i<ROZMIAR; i++)
	{
		for (j = 0; j < ROZMIAR; j++)
		{
			if (pole_piona[i][j] == NULL)
				continue;
			if (mozliwosc_ruchu(pole_piona[i][j]) == 1)
				flaga = 1;
		}
	}
	if (flaga == 0)
	{
		zamrozona = 0;
		return 0;
	}
	for ( i=0;i<ROZMIAR;i++)
	{
		for (j = 0; j < ROZMIAR; j++)
		{
			if (pole_piona[i][j] == NULL)
				continue;
			if (mozliwosc_bicia(pole_piona[i][j]) == 1)
				return 1;
		}
	}
	zamrozona = 0;
	return 0;
}

int plansza::mozliwosc_bicia(pionek*pion)
{
	dlugosc dl =pion->getdlugosc();
	szerokosc szer = pion->getszerokosc();
	kolor barwa = pion->getkolor();
	wierzcholki wierz = pion->getwierz();
	wysokosc wys = pion->getwys();
	if (barwa == gracz2) //kolor na dole
	{
		int j;
		for (int i = 0; i < ROZMIAR;i++ )
		{
			for (j = 0; j <=i; j++)
			{
				if (dl + 1 + i >= ROZMIAR)
					return 0;
				if (pole_piona[dl + 1 + i][szer] != NULL&&pole_piona[dl + 1+i][szer]->getkolor() != barwa)
				{
					if (pole_piona[dl + 1+i][szer]->getwys() + 1 == wys || (pole_piona[dl + 1+i][szer]->getwys() == wys&&pole_piona[dl + 1+i][szer]->getwierz() < wierz))
						return 1;
					if (pole_piona[dl + 1+i][szer]->getwys() == 3 && pole_piona[dl + 1+i][szer]->getwierz() == 6 && wys == 1 && wierz == 3)
						return 1;
				}
				if (szer - 1 -j>= 0 && pole_piona[dl + 1 + i][szer - 1-j] != NULL&&pole_piona[dl + 1+i][szer - 1-j]->getkolor() != barwa)
				{
					if (pole_piona[dl + 1+i][szer - 1-j]->getwys() + 1 == wys || (pole_piona[dl + 1+i][szer - 1-j]->getwys() == wys&&pole_piona[dl + 1+i][szer - 1-j]->getwierz() < wierz))
						return 1;
					if (pole_piona[dl + 1+i][szer - 1-j]->getwys() == 3 && pole_piona[dl + 1+i][szer - 1-j]->getwierz() == 6 && wys == 1 && wierz == 3)
						return 1;
				}
				if (szer + 1 +j < ROZMIAR && pole_piona[dl + 1 + i][szer + 1+j] != NULL&&pole_piona[dl + 1+i][szer + 1+j]->getkolor() != barwa)
				{
					if (pole_piona[dl + 1+i][szer + 1+j]->getwys() + 1 == wys || (pole_piona[dl + 1+i][szer + 1+j]->getwys() == wys&&pole_piona[dl + 1+i][szer + 1+j]->getwierz() < wierz))
						return 1;
					if (pole_piona[dl + 1+i][szer + 1+j]->getwys() == 3 && pole_piona[dl + 1+i][szer + 1+j]->getwierz() == 6 && wys == 1 && wierz == 3)
						return 1;
				}
			}
		}
		return 0;
	}
	else if (barwa == gracz1) //kolor na gorze
	{
		int j;
		for (int i = 0; i < ROZMIAR; i++)
		{
			for (j = 0; j <=i; j++)
			{
				if (dl - 1 - i < 0)
					return 0;
				if (pole_piona[dl - 1-i][szer] != NULL&&pole_piona[dl - 1-i][szer]->getkolor() != barwa)
				{
					if (pole_piona[dl - 1-i][szer]->getwys() + 1 == wys || (pole_piona[dl - 1-i][szer]->getwys() == wys&&pole_piona[dl - 1-i][szer]->getwierz() < wierz))
						return 1;
					if (pole_piona[dl - 1-i][szer]->getwys() == 3 && pole_piona[dl - 1-i][szer]->getwierz() == 6 && wys == 1 && wierz == 3)
						return 1;
				}
				if (szer - 1-j >= 0 && pole_piona[dl - 1-i][szer - 1-j] != NULL&&pole_piona[dl - 1-i][szer - 1-j]->getkolor() != barwa)
				{
					if (pole_piona[dl - 1-i][szer - 1-j]->getwys() + 1 == wys || (pole_piona[dl - 1-i][szer - 1-j]->getwys() == wys&&pole_piona[dl - 1-i][szer - 1-j]->getwierz() < wierz))
						return 1;
					if (pole_piona[dl - 1-i][szer - 1-j]->getwys() == 3 && pole_piona[dl - 1-i][szer - 1-j]->getwierz() == 6 && wys == 1 && wierz == 3)
						return 1;
				}
				if (szer + 1+j < ROZMIAR && pole_piona[dl - 1-i][szer + 1+j] != NULL&&pole_piona[dl - 1-i][szer + 1+j]->getkolor() != barwa)
				{
					if (pole_piona[dl - 1-i][szer + 1+j]->getwys() + 1 == wys || (pole_piona[dl - 1-i][szer + 1+j]->getwys() == wys&&pole_piona[dl - 1-i][szer + 1+j]->getwierz() < wierz))
						return 1;
					if (pole_piona[dl - 1-i][szer + 1+j]->getwys() == 3 && pole_piona[dl - 1-i][szer + 1+j]->getwierz() == 6 && wys == 1 && wierz == 3)
						return 1;
				}
			}
		}
		return 0;
	}
}

int gracz_czlowiek::ustaw(szerokosc szero, pionek*pion, plansza*plan)
{
	if (pion->getdlugosc() != -1)
	{
		return 2;
	}
	if (szero <= 0 || szero > ROZMIAR)
	{
		return 1;
	}
	if (kolor_gracza == plan->getkolor2()&& (plan->czy_puste_pole(0, szero - 1) == 1)) //kolor na dole
	{
		return 3;
	}
	else if (kolor_gracza == plan->getkolor1()&& (plan->czy_puste_pole(4, szero - 1) == 1)) //kolor na gorze
	{
		return 3;
	}
	else
	{
		gracz::ustaw(szero, pion, plan);
		return 0;
	}
}


int gracz_komputer::ustawianie()
{
	srand(time(0));
	//losowanie piona
	int los = rand() % 9;
	while(piony[los]->getszerokosc()!=-1)
		los = rand() % 9;
	pionek * pion = piony[los];

	//losowanie planszy
	los = rand() % 2;
	plansza*plan;
	if (los == 1)
		plan = plansza1;
	else
		plan = plansza2;
	int i;
	//sprawdzenie czy na planszy sa wolne miejsca 
	if (kolor_gracza == plan->getkolor2()) //kolor na dole
	{
		for (i = 0; i < ROZMIAR;)
		{
			if (plan->czy_puste_pole(0, i) == 1)
				i++;
			else
				break;
		}
		if (i == ROZMIAR&&plan == plansza1)
			plan = plansza2;
		else if (i == ROZMIAR&&plan == plansza2)
			plan = plansza1;
		else;
	}
	else if (kolor_gracza == plan->getkolor1()) //kolor na gorze
	{
		for (i = 0; i < ROZMIAR;)
		{
			if (plan->czy_puste_pole(4, i) == 1)
				i++;
			else
				break;
		}
		if (i == ROZMIAR&&plan == plansza1)
			plan = plansza2;
		else if (i == ROZMIAR&&plan == plansza2)
			plan = plansza1;
		else;
	}
	//losowanie szerokosci
	szerokosc szero = rand() % 5 + 1;
	for (i = 0; kolor_gracza == plan->getkolor2() && plan->czy_puste_pole(0, szero - 1) == 1 && i < ROZMIAR;i++) //kolor na dole
	{
		szero = rand() % 5 + 1;
	}
	for (i = 0; kolor_gracza == plan->getkolor1() && plan->czy_puste_pole(4, szero - 1) == 1 && i < ROZMIAR; i++) //kolor na gorze
	{
		szero = rand() % 5 + 1;
	}
	//ustawianie piona
	gracz::ustaw(szero, pion, plan);
	return 0;
}

int gracz_komputer::ruch_gracza()
{
	if (plansza1->getzamrozona() == 0 && plansza2->getzamrozona() == 0)
		return 1;
	ruch rusza;
	int i, j;
	plansza *plan=NULL;
	pionek*pion;
	int los;
	while (plan == NULL)
	{
		//losowanie piona
		los = rand() % 9;
		while (piony[los]->getszerokosc() == -1)
			los = rand() % 9;
		pion = piony[los];
		//sprawdzanie na ktorej planszy stoi pionek
		for (i = 0; i < ROZMIAR; i++)
		{
			for (j = 0; j < ROZMIAR; j++)
			{
				if (plansza1->getpole_piona(i, j) == piony[los])
				{
					if (plansza1->getzamrozona() != 0)
						plan = plansza1;
				}
			}
		}

		if (plan == NULL)
		{
			for (i = 0; i < ROZMIAR; i++)
			{
				for (j = 0; j < ROZMIAR; j++)
				{
					if (plansza2->getpole_piona(i, j) == piony[los])
					{
						if (plansza2->getzamrozona() != 0)
							plan = plansza2;
					}
				}
			}
		}
		if (plan == NULL)
			continue;
		dlugosc dlug = pion->getdlugosc();
		szerokosc szero = pion->getszerokosc();
		int rusz;
		bool flaga = 1;
		while (flaga)
		{
			flaga = 0;
			//losowanie ruchu
			rusz = rand() % 3 + 1;
			if (rusz == 1)
				rusza = LEWO_SKOS;
			if (rusz == 2)
				rusza = PRZOD;
			if (rusz == 3)
				rusza = PRAWO_SKOS;

			if (kolor_gracza == plan->getkolor2()) //kolor na dole
			{
				//mozliwosc ruchu
				if (dlug + 1 >= ROZMIAR)
				{
					plan = NULL;
					break;
				}
				if (rusza == 1 && (szero - 1 < 0))
					flaga = 1;
				if (rusza == 3 && (szero + 1 >= ROZMIAR))
					flaga = 1;
				//bicie
				if (flaga == 1)
					continue;
				if (this->bicie(pion, rusza, plan) == 0)
					return 0;
				if (rusza == 1 && plan->czy_puste_pole(dlug + 1, szero - 1) == 1)
					plan = NULL;
				if (plan == NULL)
					break;
				if (rusza == 2 && plan->czy_puste_pole(dlug + 1, szero) == 1)
					plan = NULL;
				if (plan == NULL)
					break;
				if (rusza == 3 && plan->czy_puste_pole(dlug + 1, szero + 1) == 1)
					plan = NULL;
				if (plan == NULL)
					break;
			}
			else if (kolor_gracza == plan->getkolor1()) //kolor na gorze
			{
				//mozliwosc ruchu
				if (dlug - 1 < 0)
					plan = NULL;
				if (plan == NULL)
					break;
				if (rusza == 1 && (szero - 1 < 0))
					flaga = 1;
				if (rusza == 3 && (dlug - 1 < 0 || szero + 1 >= ROZMIAR))
					flaga = 1;
				//bicie
				if (flaga == 1)
					continue;
				if (this->bicie(pion, rusza, plan) == 0)
					return 0;
				if (rusza == 1 && plan->czy_puste_pole(dlug - 1, szero - 1) == 1)
					plan = NULL;
				if(plan==NULL)
					break;
				if (rusza == 2 && plan->czy_puste_pole(dlug - 1, szero) == 1)
					plan = NULL;
				if (plan == NULL)
					break;
				if (rusza == 3 && plan->czy_puste_pole(dlug - 1, szero + 1) == 1)
					plan = NULL;
				if (plan == NULL)
					break;
			}
			else
			{
				cout << endl << "Cos poszlo nie tak... To nie Twoja plansza!" << endl;
				return 5;
			}
		}
	}
	gracz::ruch_piona(pion, rusza);
	return 0;
}

int gracz_czlowiek::ruch_piona(pionek*pion, ruch rusza)
{
	plansza*plan=NULL;
	int i, j;
	if (pion->getdlugosc() == -1)
	{
		return 2;
	}
	//sprawdzanie na ktorej planszy stoi pionek
		for (i = 0; i < ROZMIAR; i++)
		{
			for (j = 0; j < ROZMIAR; j++)
			{
				if (plansza2->getpole_piona(i, j) == pion)
					plan = plansza2;
				if (plansza1->getpole_piona(i, j) == pion)
					plan = plansza1;
			}
		}
	plan->zamrozenie();
	if (plan->zamrozona == 0)
		return 4;
	dlugosc dlug = pion->getdlugosc();
	szerokosc szero = pion->getszerokosc();
	if (kolor_gracza == plan->getkolor2()) //kolor na dole
	{
		//mozliwosc ruchu
		if (rusza == 1 && (dlug + 1 >= ROZMIAR || szero - 1 < 0))
			return 1;
		if (rusza == 2 && dlug + 1 >= ROZMIAR)
			return 1;
		if (rusza == 3 && (dlug + 1 >= ROZMIAR || szero + 1 >= ROZMIAR))
			return 1;
		//bicie
		if (this->bicie(pion, rusza, plan) == 0)
			return 0;
		if (rusza == 1 && plan->czy_puste_pole(dlug + 1, szero - 1) == 1)
			return 3;
		if (rusza == 2 && plan->czy_puste_pole(dlug + 1, szero) == 1)
			return 3;
		if (rusza == 3 && plan->czy_puste_pole(dlug + 1, szero + 1) == 1)
			return 3;
	}
	else if (kolor_gracza == plan->getkolor1()) //kolor na gorze
	{
		//mozliwosc ruchu
		if (rusza == 1 && (dlug - 1 < 0 || szero - 1 < 0))
			return 1;
		if (rusza == 2 && dlug - 1<0)
			return 1;
		if (rusza == 3 && (dlug - 1 <0 || szero + 1 >= ROZMIAR))
			return 1;
		//bicie
		if (this->bicie(pion, rusza, plan) == 0)
			return 0;
		if (rusza == 1 && plan->czy_puste_pole(dlug - 1, szero - 1) == 1)
			return 3;
		if (rusza == 2 && plan->czy_puste_pole(dlug - 1, szero) == 1)
			return 3;
		if (rusza == 3 && plan->czy_puste_pole(dlug - 1, szero + 1) == 1)
			return 3;
	}
	else
	{
		cout << endl << "Cos poszlo nie tak... To nie Twoja plansza!" << endl;
		return 5;
	}
	gracz::ruch_piona(pion, rusza);
	return 0;
}

int gracz_czlowiek::ruch_gracza()
{
	bool flaga = 1;
	wysokosc wys;
	wierzcholki ile_wierz;
	int pion;
	int mjsc;
	while (flaga)
	{
		flaga = 0;
		cout << endl << "PLANSZA 1" <<endl;
		if (plansza1->wyswietl_plansze() == 2)
		{
			cout << endl << "Plansza zamrozona." << endl;
		}
		cout << endl << "PLANSZA 2" << endl;
		if (plansza2->wyswietl_plansze() == 2)
		{
			cout << endl << "Plansza zamrozona." << endl;
		}
		cout << "Podaj wysokosc piona: 1 - maly, 2 - sredni, 3 - duzy"<< endl;
		while (scanf("%d", &wys) != 1 || wys < 1 || wys>3 || getchar() != '\n')
		{
			cout << "Nieporawna wysokosc... Wybierz 1, 2 albo 3!\n";
			while (getchar() != '\n');
		}
		cout << "Podaj ilosc wierzcholkow piona: 3, 4 albo 6." << endl;
		while (scanf("%d", &ile_wierz) != 1 || (ile_wierz != 3 && ile_wierz != 4 && ile_wierz != 6) || getchar() != '\n')
		{
			cout << "Nieporawna ilosc wierzcholkow... Wybierz 3, 4 albo 6!"<< endl;
			while (getchar() != '\n');
		}
		cout << "Podaj ruch. 1-lewoskos, 2-prosto, 3-prawoskos" << endl;
		while (scanf("%d", &mjsc) != 1 || mjsc < 1 || mjsc>3 || getchar() != '\n')
		{
			cout << "Wybierz wartosc od 1 do 3!\n" << endl;
			while (getchar() != '\n');
		}
		int sprawdzenie;
		pion = wybor_piona(ile_wierz, wys);
		ruch rusza;
		if (mjsc == 1)
			rusza = LEWO_SKOS;
		if (mjsc == 2)
			rusza = PRZOD;
		if (mjsc == 3)
			rusza = PRAWO_SKOS;
		if ((sprawdzenie = (this->ruch_piona(piony[pion], rusza))) == 0)
		{
				return 0;
			}
			else if (sprawdzenie == 1)
			{
				cout << endl << "Nie mozna ustawic piona poza plansza! Podaj nowe wartosci:" << endl;
				flaga = 1;
			}
			else if (sprawdzenie == 2)
			{
				cout << endl << "Ten pionek zostal juz zbity! Podaj inny:" << endl;
				flaga = 1;
			}
			else if (sprawdzenie == 3)
			{
				cout << endl << "To pole jest juz zajete. Podaj nowe wartosci:" << endl;
				flaga = 1;
			}
			else if (sprawdzenie == 4)
			{
				cout << endl << "Plansza zamrozona. Wybierz inna." << endl;
				flaga = 1;
			}
			else if (sprawdzenie == 5)
			{
				cout << endl << "Podaj nowe wartosci:" << endl;
				flaga = 1;
			}
	}
}

int gracz_czlowiek::ustawianie()
{
	bool flaga = 1;
	wysokosc wys;
	wierzcholki ile_wierz;
	int pion;
	int mjsc;
	int plansz;
	this->wyswietl_plansze_gracza();
	while (flaga)
	{
		flaga = 0;
		cout << "Podaj wysokosc piona: 1 - maly, 2 - sredni, 3 - duzy" << endl;
		while (scanf("%d", &wys) != 1 || wys < 1 || wys>3 || getchar() != '\n')
		{
			cout << "Nieporawna wysokosc... Wybierz 1, 2 albo 3!" << endl;
			while (getchar() != '\n');
		}
		cout << "Podaj ilosc wierzcholkow piona: 3, 4 albo 6." << endl;
		while (scanf("%d", &ile_wierz) != 1 || (ile_wierz != 3 && ile_wierz != 4 && ile_wierz != 6) || getchar() != '\n')
		{
			cout << "Nieporawna ilosc wierzcholkow... Wybierz 3, 4 albo 6!" << endl;
			while (getchar() != '\n');
		}
		cout << "Podaj miejsce na planszy. 1-5" << endl;
		while (scanf("%d", &mjsc) != 1 || mjsc < 1 || mjsc>5 || getchar() != '\n')
		{
			cout << "Wybierz wartosc od 1 do 5!" << endl;
			while (getchar() != '\n');
		}
		cout << "Podaj plansze, 1 lub 2." << endl;
		while (scanf("%d", &plansz) != 1 || (plansz != 1 && plansz != 2) || getchar() != '\n')
		{
			cout << "Wybierz wartosc 1 lub 2!" << endl;
			while (getchar() != '\n');
		}
		int sprawdzenie;
		pion = wybor_piona(ile_wierz, wys);
		if (plansz == 1)
		{
			sprawdzenie = (this->ustaw(mjsc, piony[pion], plansza1));
		}
		if (plansz == 2)
		{
			sprawdzenie = (this->ustaw(mjsc, piony[pion], plansza2));
		}
		if (sprawdzenie == 0)
		{
			return 0;
		}
		else if (sprawdzenie == 1)
		{
			cout << endl << "Nie mozna ustawic piona poza plansza! Podaj nowe wartosci:" << endl;
			flaga = 1;
		}
		else if (sprawdzenie == 2)
		{
			cout << endl << "Ten pionek byl juz ustawiany! Podaj wartosci dla innego piona:" << endl;
			flaga = 1;
		}
		else if (sprawdzenie == 3)
		{
			cout << endl << "To pole jest juz zajete. Podaj nowe wartosci:" << endl;
			flaga = 1;
		}
		else if (sprawdzenie == 5)
		{
			cout << endl << "Podaj nowe wartosci:" << endl;
			flaga = 1;
		}
	}
}

void gracz_czlowiek::pobierz_nick(int nr)
{
	char imie[50];
	cout << "Nick gracza " << nr << ":" << endl;
	while (scanf("%s", imie) != 1|| strcmp(imie, "komputer") == 0)
	{
		cout << "Podaj nazwe! Pamietaj, ze musi byc ona rozna od \"komputer\""<<endl;
		while (getchar() != '\n');
	}
	setnick(imie);
}

void gracz_komputer::pobierz_nick(int nr)
{
	setnick("komputer");
}

int plansza::mozliwosc_ruchu(pionek*pion)
{
	dlugosc dl= pion->getdlugosc();
	szerokosc szer = pion->getszerokosc();
	kolor barwa = pion->getkolor();
	if (barwa == gracz2) //kolor na dole
	{
		if (dl + 1 >= ROZMIAR)
			return 0;
		//sprawdzenie czy nie ma bicia
		if (zbije(pion, pole_piona[dl + 1][szer]) == 1)
		{
			return 1;
		}
		if (szer + 1 < ROZMIAR&&zbije(pion, pole_piona[dl + 1][szer + 1])==1)
		{
			return 1;
		}
		if (szer - 1 >= 0 && zbije(pion, pole_piona[dl + 1][szer - 1]) == 1)
		{
			return 1;
		}
		if (szer + 1 >= ROZMIAR&&czy_puste_pole(dl + 1, szer - 1) && czy_puste_pole(dl + 1, szer))
		{
			return 0;
		}
		else if (szer - 1 < 0 && czy_puste_pole(dl + 1, szer + 1) && czy_puste_pole(dl + 1, szer))
		{
			return 0;
		}
		else if (szer - 1 >= 0 && szer + 1 < ROZMIAR&&czy_puste_pole(dl + 1, szer + 1) && czy_puste_pole(dl + 1, szer) && czy_puste_pole(dl + 1, szer - 1))
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else if (barwa == gracz1) //kolor na gorze
	{
		if (dl - 1 < 0)
			return 0;
		//sprawdzenie czy nie ma bicia
		if (zbije(pion, pole_piona[dl - 1][szer]) == 1)
		{
			return 1;
		}
		if (szer + 1 < ROZMIAR&&zbije(pion, pole_piona[dl - 1][szer + 1]) == 1)
		{
			return 1;
		}
		if (szer - 1 >= 0 && zbije(pion, pole_piona[dl - 1][szer - 1]) == 1)
		{
			return 1;
		}
		if (szer + 1 >= ROZMIAR&&czy_puste_pole(dl - 1, szer - 1) && czy_puste_pole(dl - 1, szer))
		{
			return 0;
		}
		else if (szer - 1 < 0 && czy_puste_pole(dl - 1, szer + 1) && czy_puste_pole(dl - 1, szer))
		{
			return 0;
		}
		else if (szer - 1 >= 0 && szer + 1 < ROZMIAR&&czy_puste_pole(dl - 1, szer + 1) && czy_puste_pole(dl - 1, szer) && czy_puste_pole(dl - 1, szer - 1))
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		cout << "Czy ten pion stoi na wlasciwej planszy?" << endl;
		return -1;
	}
}

int plansza::zbije(pionek*pion, pionek*zbijany)
{
	if (zbijany == NULL)
	{
		return -1;
	}
	kolor barwa1 = pion->getkolor();
	wierzcholki wierz1 = pion->getwierz();
	wysokosc wys1 = pion->getwys();
	kolor barwa2 = zbijany->getkolor();
	wierzcholki wierz2 = zbijany->getwierz();
	wysokosc wys2 = zbijany->getwys();
	if (barwa1 == barwa2)
	{
		return 0;
	}
	if (wys2 + 1 == wys1)
	{
		return 1;
	}
	else if (wys1 == wys2&&wierz2 < wierz1)
	{
		return 1;
	}
	else if (wys1 == 3 && wierz1 == 6 && wys2 == 1 && wierz2 == 3)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}