/** \file tablica.cpp
 * \brief Plik zawiera implementacje klasy Tablica.
 */

#include <iostream>
#include <tablica.hh>

using namespace std;

void Tablica::zmienRozmiar(unsigned int nRozmiar)
{
	T = (int*)realloc(T, nRozmiar * sizeof(int));
	dlugoscTablicy=nRozmiar;
}

void Tablica::zamien_elementy(unsigned int a, unsigned int b)
{
	int zm1, zm2;
	zm1=T[a];
	zm2=T[b];
	T[a]=zm2;
	T[b]=zm1;
}

void Tablica::odwroc_kolejnosc()
{
	for (unsigned int i=0; i<(dlugoscTablicy/2); i++)
	{
		zamien_elementy(i, dlugoscTablicy-i-1);
	}
}

void Tablica::dodaj_element(int e)
{
	zmienRozmiar(rozmiar()+1);
	T[dlugoscTablicy-1] = e;
}

void Tablica::dodaj_tablice(const Tablica &TL)
{
	unsigned int ostatni = rozmiar();
	zmienRozmiar(rozmiar()+TL.rozmiar());
	for (unsigned int i=0; i<TL.rozmiar(); i++)
	{
		T[ostatni+i] = TL[i];
	}
}

Tablica& Tablica::operator=(const Tablica &wart)
{
	zmienRozmiar(wart.rozmiar());
	for (unsigned i=0; i<rozmiar(); i++)
	{
		T[i] = wart[i];
	}
	return *this;
}

Tablica& Tablica::operator+(const Tablica &wart) const
{
	Tablica *chwilowy = new Tablica;
	chwilowy->dodaj_tablice(*this);
	chwilowy->dodaj_tablice(wart);
	return *chwilowy;
}

bool Tablica::operator==(const Tablica &wart) const
{
	if (rozmiar() != wart.rozmiar())
		return false;
	for (unsigned int i=0; i<rozmiar(); i++)
	{
		if (T[i] != wart[i])
		return false;
	}
	return true;
}
