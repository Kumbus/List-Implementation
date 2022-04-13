#include "Klasy.h"
#include<iostream>
using namespace std;

VPlayer::VPlayer() : imie(""), nazwisko(""), druzyna(""), pozycja(""), wiek(0), wzrost(0), atak(0), punkty_w_sezonie(0) {};

istream& operator>>(istream& in, VPlayer& gracz)
{
	in >> gracz.imie;
	in >> gracz.nazwisko;
	in >> gracz.druzyna;
	in >> gracz.pozycja;
	in >> gracz.wiek;
	in >> gracz.wzrost;
	in >> gracz.atak;
	in >> gracz.punkty_w_sezonie;

	return in;
}

ostream& operator<<(ostream& out, const VPlayer& gracz)
{
	out << "Imie: " << gracz.imie << endl;
	out << "Nazwisko: " << gracz.nazwisko << endl;
	out << "Druzyna: " << gracz.druzyna << endl;
	out << "Pozycja: " << gracz.pozycja << endl;
	out << "Wiek: " << gracz.wiek << endl;
	out << "Wzrost: " << gracz.wzrost << endl;
	out << "Zasieg w ataku: " << gracz.atak << endl;
	out << "Punkty zdobyte w tym sezonie: " << gracz.punkty_w_sezonie << endl << endl;

	return out;
}

bool operator== (const VPlayer& g1,const VPlayer& g2)
{
	if (g1.imie == g2.imie && g1.nazwisko == g2.nazwisko && g1.druzyna == g2.druzyna && g1.pozycja == g2.pozycja && g1.wiek == g2.wiek && g1.wzrost == g2.wzrost && g1.atak == g2.atak && g1.punkty_w_sezonie == g2.punkty_w_sezonie)
		return true;

	return false;
}



CPlayer::CPlayer() : imie(""), nazwisko(""), kraj(""), wiek(0), klasyczne(0), szybkie(0), blyskawiczne(0) {};

istream& operator>>(istream& in, CPlayer& gracz)
{
	in >> gracz.imie;
	in >> gracz.nazwisko;
	in >> gracz.kraj;
	in >> gracz.klasyczne;
	in >> gracz.szybkie;
	in >> gracz.blyskawiczne;
	in >> gracz.wiek;

	return in;
}

ostream& operator<<(ostream& out, const CPlayer& gracz)
{
	out << "Imie: " << gracz.imie << endl;
	out << "Nazwisko: " << gracz.nazwisko << endl;
	out << "Reprezentacja: " << gracz.kraj << endl;
	out << "Wiek: " << gracz.wiek << endl;
	out << "Ranking w szachach klasycznych: " << gracz.klasyczne << endl;
	out << "Ranking w szachach szybkich: " << gracz.szybkie << endl;
	out << "Ranking w szachach blyskawicznych: " << gracz.blyskawiczne << endl << endl;


	return out;
}

bool operator== (const CPlayer& g1, const CPlayer& g2)
{
	if (g1.imie == g2.imie && g1.nazwisko == g2.nazwisko && g1.kraj == g2.kraj && g1.wiek == g2.wiek && g1.klasyczne == g2.klasyczne && g1.szybkie == g2.szybkie && g1.blyskawiczne == g2.blyskawiczne)
		return true;

	return false;
}