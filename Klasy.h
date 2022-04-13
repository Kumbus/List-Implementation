#pragma once
#include<iostream>
using namespace std;

class VPlayer
{
public:
	string imie, nazwisko, druzyna, pozycja;
	int wiek, atak, wzrost, punkty_w_sezonie;


	VPlayer();

	friend istream& operator>> (istream& in, VPlayer& gracz);
	friend ostream& operator<< (ostream& out, const VPlayer& gracz);
	friend bool operator== (const VPlayer& g1,const VPlayer& g2);
};

class CPlayer
{
public:
	string imie, nazwisko, kraj;
	int wiek;
	float klasyczne, szybkie, blyskawiczne;


	CPlayer();

	friend istream& operator>> (istream& in, CPlayer& gracz);
	friend ostream& operator<< (ostream& out, const CPlayer& gracz);
	friend bool operator== (const CPlayer& g1, const CPlayer& g2);
};