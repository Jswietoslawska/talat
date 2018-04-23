#pragma once
#define ROZMIAR 5
#define WIEZE 9
#include <iostream>
using namespace std;
enum kolor
{
	SZARY,
	CZARNY,
	BIALY
};

enum wierzcholki
{
	TROJKAT = 3,
	KWADRAT = 4,
	SZESCIOKAT = 6
};

enum ruch
{
	LEWO_SKOS = 1,
	PRZOD = 2,
	PRAWO_SKOS = 3
};

enum wysokosc
{
	MALY = 1,
	SREDNI = 2,
	DUZY = 3
};

typedef int dlugosc;
typedef int szerokosc;


class pionek
{
public:
	pionek(wierzcholki, wysokosc, kolor);
	void setwspolrz(dlugosc a, szerokosc b) { dl = a; szer = b; };
	dlugosc getdlugosc() { return dl; };
	szerokosc getszerokosc() { return szer; };
	wierzcholki getwierz() { return wierz_piona; };
	wysokosc getwys() { return wys_piona; };
	kolor getkolor() { return kolor_piona; };
private:
	dlugosc dl;
	szerokosc szer;
	wierzcholki wierz_piona;
	wysokosc wys_piona;
	kolor kolor_piona;
};

class plansza
{
public:
	friend class gracz_czlowiek;
	friend class gracz;
	plansza(kolor, kolor);
	~plansza();
	kolor getkolor1() { return gracz1; };
	kolor getkolor2() { return gracz2; };
	void setpole_piona(dlugosc a, szerokosc b, pionek*pi) { pole_piona[a][b] = pi; };
	int czy_puste_pole(dlugosc a, szerokosc b); //1 - zajete pole, 0 - puste pole
	pionek* getpole_piona(dlugosc a, szerokosc b) { return pole_piona[a][b]; };
	int wyswietl_plansze();
	int zamrozenie(); //0 gdy zamrozona
	int getzamrozona() { return zamrozona; };
	void setkolor1(kolor barwa) { gracz1 = barwa; };
	void setkolor2(kolor barwa) { gracz2 = barwa; };
private:
	int mozliwosc_bicia(pionek*); //1 gdy bicie mozliwe, 0 gdy nie, -1 - gdy pion poza plansza
	int mozliwosc_ruchu(pionek*); //1 gdy ruch mozliwy, 0 gdy ruch niemozliwy
	int zbije(pionek*, pionek*); //1 gdy moze zbic drugiego piona, 0 gdy nie, -1 gdy brak zbijanego piona
	pionek* pole_piona[ROZMIAR][ROZMIAR];
	kolor gracz1;
	kolor gracz2;
	int zamrozona; //0 gdy zamrozona
};

class gracz
{
public:
	friend class plansza;
	gracz(plansza *, plansza *);
	~gracz();
	const kolor getkolor() { return kolor_gracza; };
	virtual int ustaw(szerokosc, pionek*, plansza*);
	virtual int ruch_piona(pionek*, ruch);//1-niemozliwy ruch, 2-brak piona, 3-pole zajete, 4-pionek innego gracza
	int bicie(pionek*, ruch, plansza*); //0-bicie mozliwe
	void setpunkty(int x) { punkty += x; };
	int getpunkty() { return punkty; };
	pionek* getpiony(int a) { return piony[a]; };
	plansza* getplansza1() { return plansza1; };
	plansza* getplansza2() { return plansza2; };
	virtual int ustawianie() = 0;
	virtual int ruch_gracza() = 0;
	void wyswietl_plansze_gracza() { plansza1->wyswietl_plansze(); plansza2->wyswietl_plansze(); };
	void setkolor(kolor barwa) { kolor_gracza = barwa; };
	virtual void pobierz_nick( int)=0;
	char* getnick() { return nick; };
	void setnick(char*nazwa) { strcpy(nick, nazwa); };
protected:
	char nick[50];
	pionek* piony[WIEZE];
	int punkty;
	kolor kolor_gracza;
	plansza *plansza1;
	plansza* plansza2;
};

class gracz_czlowiek :public gracz
{
public:
	friend class plansza;
	~gracz_czlowiek() { gracz::~gracz(); };
	int ustaw(szerokosc, pionek*, plansza*);//1-niemozliwe ustwaienie, 2-nie mozna drugi raz ustawiac tego samego piona, 3-pole jest zajete
	gracz_czlowiek(plansza *p1, plansza *p2) : gracz(p1, p2) {};
	int ruch_piona(pionek*, ruch);
	int ruch_gracza(); //0 - poprawny ruch, 1 - koniec gry
	int ustawianie();
	void pobierz_nick( int);
};

class gracz_komputer :public gracz
{
public:
	friend class plansza;
	~gracz_komputer() { gracz::~gracz(); };
	gracz_komputer(plansza*p1, plansza*p2) : gracz(p1, p2) {};
	int ruch_gracza();
	int ustawianie();
	void pobierz_nick( int);
};
