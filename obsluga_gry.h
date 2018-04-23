#pragma once
#include "talat_obiekty2.h"

int wybor_piona(wierzcholki, wysokosc); //wybor pionka ustawianego na planszy
int koniec_gry(plansza*, plansza*, plansza*, gracz*, gracz*, gracz*);//0 gdy koniec gry
int kolejka(gracz*); //0 - ominiecie kolejki gracza
int zapis(plansza*, plansza*, plansza*, gracz*, gracz*, gracz*); //1 - nie udalo sie zapisac gry, 0 - gra zapisana
char znakowy_kolor(kolor);
kolor znak_na_kolor(char);
int odczyt(plansza*, plansza*, plansza*, gracz*, gracz*, gracz*); //1 - nie udalo sie odczytac gry, -1 - plik uszkodzony, 0 - poprawne odczytanie
int zapis_punktacji(gracz*, gracz*, gracz*); //0 - punktacja zapisana poprawnie, -1 - nie udalo sie zapisac punktacji
int odczyt_punktacji(); //0 - poprawny odczyt, 1 - nie udalo sie otworzyc pliku, 2 - nie udalo sie wyczyscic pliku, 3 - uszkodzony plik zostal wyczyszczony 
int zapis_trybu(gracz*, gracz*, gracz*); //1 - tryb 1, 2 - tryb 2, 3 - tryb 3, -1 - blad zapisu
int rozgrywka(gracz*, gracz*, gracz*, plansza*, plansza*, plansza*);
int rozgrywka_zapisanej(gracz*, gracz*, gracz*, plansza*, plansza*, plansza*);
int przerwanie_gry(gracz*, gracz*, gracz*, plansza*, plansza*, plansza*); //0 - gra zakonczona, 1 - powrot do gry, -1 - blad
int odczyt_trybu(); //-1 - nie udalo sie odczytac, 1 - tryb trzech graczy, 2 - tryb dwoch graczy, 3 - tryb jednego gracza
void wyswietl_piony();
template <typename T>
wierzcholki num_na_wierz(T liczba)
{
	if (liczba == 3)
		return TROJKAT;
	else if (liczba == 4)
		return KWADRAT;
	else if (liczba == 6)
		return SZESCIOKAT;
}

template <typename T>
wysokosc num_na_wys(T liczba)
{
	if (liczba == 1)
		return MALY;
	else if (liczba == 2)
		return SREDNI;
	else if (liczba == 3)
		return DUZY;
}