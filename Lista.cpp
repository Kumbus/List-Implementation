#include"Lista.h"
#include<iostream>
#include<fstream>
using namespace std;

template<typename T>
Lista<T>::Lista() : licznik(0), glowa(nullptr), ogon(nullptr) {};

template<typename T>
Lista<T>::Lista(const Lista& lista) : licznik(0), glowa(nullptr), ogon(nullptr)
{
	shared_ptr<Element<T>> pom = lista.glowa;
	for (int i = 0; i < lista.licznik; i++)
	{
		push_back(pom->element);
		pom = pom->nastepny;
	}
}

template<typename T>
Lista<T>::Lista(Lista&& lista) : licznik(lista.licznik), glowa(lista.glowa), ogon(lista.ogon)
{	
	lista.glowa = nullptr;
	lista.ogon = nullptr;
	lista.licznik = 0;

}

template<typename T>
void Lista<T>::push_back(const T& obiekt)
{
	auto nowy = make_shared<Element<T>>();
	nowy->element = obiekt;
	nowy->nastepny = nullptr;
	if (licznik == 0)
	{
		nowy->poprzedni = nullptr;
		glowa = nowy;
	}
	else
	{
		nowy->poprzedni = ogon;
		ogon->nastepny = nowy;
	}
	ogon = nowy;

	licznik++;
}

template <typename T>
void Lista<T>::push_front(const T& obiekt)
{
	auto nowy = make_shared<Element<T>>();
	nowy->element = obiekt;
	nowy->poprzedni = nullptr;
	if (licznik == 0)
	{
		nowy->nastepny = nullptr;
		ogon = nowy;
	}
	else
	{
		nowy->nastepny = glowa;
		glowa->poprzedni = nowy;
	}
	glowa = nowy;

	licznik++;
}

template <typename T>
void Lista<T>::pop_front()
{
	if (licznik == 0)
		return;

	glowa = glowa->nastepny;

	if (licznik > 1)
		glowa->poprzedni = nullptr;
	else
		ogon = nullptr;
	

	licznik--;
}

template <typename T>
void Lista<T>::pop_back()
{
	if (licznik == 0)
		return;

	ogon = ogon->poprzedni;

	if (licznik > 1)
		ogon->nastepny = nullptr;
	else
		glowa = nullptr;


	licznik--;
}

template <typename T>
void Lista<T>::erase(int indeks)
{
	if (licznik == 0)
		return;

	if (indeks == 0)
		pop_front();
	else if (indeks == licznik - 1)
		pop_back();
	else if (indeks > 0 && indeks < licznik - 1)
	{
		shared_ptr<Element<T>> pom = glowa;
		for (int i = 0; i < indeks; i++)
			pom = pom->nastepny;

		//shared_ptr<Element<T>> pom2 = pom->poprzedni;
		pom->poprzedni->nastepny = pom->nastepny;
		pom->nastepny->poprzedni = pom->poprzedni;
	}
	else
		return;

	licznik--;
}


template <typename T>
int Lista<T>::search(const T& obiekt)
{
	shared_ptr<Element<T>> pom = glowa;
	for (int i = 0; i < licznik; i++)
	{
		if (pom->element == obiekt)
			return i;

		pom = pom->nastepny;
	}
	return -1;
}

template <typename T>
void Lista<T>::print()
{
	shared_ptr<Element<T>> pom = glowa;
	for (int i = 0; i < licznik; i++)
	{
		cout << pom->element << " ";
		pom = pom->nastepny;
	}

	cout << endl;
}

template <typename T>
void Lista<T>::sort()
{
	if (licznik <= 1)
		return;

	shared_ptr<Element<T>> pom1 = glowa;
	shared_ptr<Element<T>> pom2 = glowa->nastepny;
	bool dalej = true;

	while (dalej)
	{
		dalej = false;

		for (int i = 0; i < licznik - 1; i++)
		{
			if (pom1->element < pom2->element)
			{
				auto bufor = make_shared<Element<T>>();
				bufor->element = pom1->element;
				pom1->element = pom2->element;
				pom2->element = bufor->element;
				dalej = true;
			}
			pom1 = pom1->nastepny;
			pom2 = pom2->nastepny;
			
		}

		pom1 = glowa;
		pom2 = glowa->nastepny;
	}
}

template <typename T>
void Lista<T>::reverse_sort()
{
	if (licznik <= 1)
		return;

	shared_ptr<Element<T>> pom1 = glowa;
	shared_ptr<Element<T>> pom2 = glowa->nastepny;
	bool dalej = true;

	while (dalej)
	{
		dalej = false;

		for (int i = 0; i < licznik - 1; i++)
		{
			if (pom1->element > pom2->element)
			{
				auto bufor = make_shared<Element<T>>();
				bufor->element = pom1->element;
				pom1->element = pom2->element;
				pom2->element = bufor->element;
				dalej = true;
			}

			pom1 = pom1->nastepny;
			pom2 = pom2->nastepny;
		}

		pom1 = glowa;
		pom2 = glowa->nastepny;
	}
}

template <class T>
Lista<T>&Lista<T>::operator= (const Lista& lista)
{
	glowa = nullptr;
	ogon = nullptr;
	licznik = 0;

	shared_ptr<Element<T>> pom = lista.glowa;
	for (int i = 0; i < lista.licznik; i++)
	{
		push_back(pom->element);
		pom = pom->nastepny;
	}
	return *this;
}

template <class T>
Lista<T>& Lista<T>::operator= (Lista&& lista)
{
	if (&lista == this)
		return *this;

	glowa = lista.glowa;
	ogon = lista.ogon;
	licznik = lista.licznik;
	lista.glowa = nullptr;
	lista.ogon = nullptr;
	lista.licznik = 0;

	return *this;

}



template <typename T>
void Lista<T>::read_binary(const string& plik)
{
	ifstream plo(plik, ios::binary);
	T pom;
	size_t licznikp;

	plo.read((char*)&licznikp, sizeof licznikp);

	for (int i = 0; i < licznikp; i++)
	{
		plo.read((char*)&pom, sizeof pom);
		push_back(pom);
	}
	plo.close();
}

template <typename T>
void Lista<T>::save_binary(const string& plik)
{
	ofstream plz(plik, ios::binary);

	shared_ptr<Element<T>> pom = glowa;

	plz.write((const char*)&licznik, sizeof licznik);
	for (int i = 0; i < licznik; i++)
	{
		plz.write((const char *) &(pom->element), sizeof(pom->element));
		pom = pom->nastepny;
	}
	plz.close();
}

template<typename T>
template<class P>
void Lista<T>::sort(P cmp)
{
	if (licznik <= 1)
		return;

	shared_ptr<Element<T>> pom1 = glowa;
	shared_ptr<Element<T>> pom2 = glowa->nastepny;
	bool dalej = true;

	while (dalej)
	{
		dalej = false;

		for (int i = 0; i < licznik - 1; i++)
		{
			if (cmp(pom1->element, pom2->element))
			{
				auto bufor = make_shared<Element<T>>();;
				bufor->element = pom1->element;
				pom1->element = pom2->element;
				pom2->element = bufor->element;
				dalej = true;
			}
			pom1 = pom1->nastepny;
			pom2 = pom2->nastepny;
		}

		pom1 = glowa;
		pom2 = glowa->nastepny;
	}
}

template<typename T>
template<class P>
void Lista<T>::reverse_sort(P cmp)
{
	if (licznik <= 1)
		return;

	shared_ptr<Element<T>> pom1 = glowa;
	shared_ptr<Element<T>> pom2 = glowa->nastepny;
	bool dalej = true;

	while (dalej)
	{
		dalej = false;
		
		for (int i = 0; i < licznik - 1; i++)
		{
			if (!cmp(pom1->element, pom2->element))
			{
				auto bufor = make_shared<Element<T>>();
				bufor->element = pom1->element;
				pom1->element = pom2->element;
				pom2->element = bufor->element;
				dalej = true;
			}
			pom1 = pom1->nastepny;
			pom2 = pom2->nastepny;
		}

		pom1 = glowa;
		pom2 = glowa->nastepny;
	}
}

template <typename T>
T Lista<T>::get(int indeks)
{
	shared_ptr<Element<T>> pom = glowa;
	
	for (int i = 0; i < indeks; i++)
		pom = pom->nastepny;

	return pom->element;
}
