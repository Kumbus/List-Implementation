#pragma once
#include<memory>
#include<iostream>
using namespace std;

template <typename T>
class Element
{
public:
	shared_ptr<Element<T>> nastepny;
	shared_ptr<Element<T>> poprzedni;
	T element;
};

template <typename T>
class Lista
{
	size_t licznik;
	shared_ptr<Element<T>> glowa;
	shared_ptr<Element<T>> ogon;

public:
	Lista();
	Lista(const Lista& lista);
	Lista(Lista&& lista);
	~Lista() {};

	void push_front(const T& obiekt);
	void push_back(const T& obiekt);
	void pop_front();
	void pop_back();
	void erase(int indeks);
	int search(const T& obiekt);
	void sort();
	void reverse_sort();

	template <class P>
	void sort(P cmp);

	template <class P>
	void reverse_sort(P cmp);

	void print();
	void read_binary(const string& plik);
	void save_binary(const string& plik);
	Lista& operator= (const Lista& lista);
	Lista& operator= (Lista&& lista);

	T get(int indeks);
	


};
