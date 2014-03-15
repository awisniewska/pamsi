/** \file tablica.hh
 * \brief Plik zawiera definicje klasy Tablica.
 */
#include <cstdlib>
#include <iostream>


#ifndef TABLICA_HH
#define TABLICA_HH

/** \brief Klasa implementujaca tablice dynamiczna
 *
 *  Klasa przechowuje tablice liczb calkowitych oraz umozliwia podstawowe operacje na nich.
 *
 */
template <typename typ> class Tablica
{
	int *T;
	unsigned int dlugoscTablicy;

public:
/** \brief
 * Konstruktor tworzacy obiekt klasy Tablica.
 */
	Tablica(): T(0), dlugoscTablicy(0) {};
/** \brief
 * Destruktor usuwajacy obiekt klasy Tablica.
 */
	~Tablica() { free(T); };

/** \brief
 * Funkcja zwracajaca dlugosc tablicy.
 * \return liczba elementow tablicy
 */
	unsigned int rozmiar() const
	{
		return dlugoscTablicy;
	}
/** \brief
 * Funkcja zmieniajaca ilosc elementow tablicy.
*/
	void zmienRozmiar(unsigned int nRozmiar);
/** \brief
 * Funkcja zamieniajaca miejscami dwa wybrane elementy.
 */
	void zamien_elementy(unsigned int a, unsigned int b);
/** \brief
 * Funkcja odwracajaca kolejnosc elementow tablicy.
 */
	void odwroc_kolejnosc();
/** \brief
 * Funkcja dodajaca nowy element na koniec tablicy.
 */
	void dodaj_element(typ e);
/** \brief
 * Funkcja laczaca dwie tablice.
 */
	void dodaj_tablice(const Tablica<typ> &TL);

/** \brief
 * Przeciazenie operatora indeksujacego.
 * \param nr Indeks wybranego elementu
 * \return Wartosc pod wskazanym indeksem
 */
	typ& operator[](const unsigned int nr) {return T[nr];}
	const typ& operator[](const unsigned int nr) const {return T[nr];}

/** \brief Przeciazenie operatora przypisania
 * \param wart tablica z ktorej wartosci zostana przypisane
 * \return referencje na obiekt wywolujacy
 */
	Tablica<typ>& operator=(const Tablica<typ> &wart);
/** \brief Przeciazenie operatora dodawania
 * \return tablice zawieraja elementy z obu tablic
 */
	Tablica<typ>& operator+(const Tablica<typ> &wart) const;
/** \brief Przeciazenie operatora porownania
 * \return true - gdy tablice sa takie same
 * \return false - gdy tablice sie roznia
 *
 */
	bool operator==(const Tablica<typ> &wart) const;

};

template<typename typ>
void Tablica<typ>::zmienRozmiar(unsigned int nRozmiar) {

	T = (typ*)realloc(T, nRozmiar * sizeof(typ));
		dlugoscTablicy=nRozmiar;

}

template<typename typ>
void Tablica<typ>::zamien_elementy(unsigned int a, unsigned int b) {

	typ zm1, zm2;
	zm1=T[a];
	zm2=T[b];
	T[a]=zm2;
	T[b]=zm1;

}

template<typename typ>
void Tablica<typ>::odwroc_kolejnosc() {

	for (unsigned int i=0; i<(dlugoscTablicy/2); i++)
	{
		zamien_elementy(i, dlugoscTablicy-i-1);
	}

}

template<typename typ>
void Tablica<typ>::dodaj_element(typ e) {

	zmienRozmiar(rozmiar()+1);
	T[dlugoscTablicy-1] = e;

}

template<typename typ>
void Tablica<typ>::dodaj_tablice(const Tablica<typ>& TL) {

	unsigned int ostatni = rozmiar();
	zmienRozmiar(rozmiar()+TL.rozmiar());
	for (unsigned int i=0; i<TL.rozmiar(); i++)
	{
		T[ostatni+i] = TL[i];
	}

}

template<typename typ>
Tablica<typ>& Tablica<typ>::operator =(const Tablica<typ>& wart) {

	zmienRozmiar(wart.rozmiar());
	for (unsigned i=0; i<rozmiar(); i++)
	{
		T[i] = wart[i];
	}
	return *this;

}

template<typename typ>
Tablica<typ>& Tablica<typ>::operator +(const Tablica<typ>& wart) const {

		Tablica<typ> *chwilowy = new Tablica<typ>;
		chwilowy->dodaj_tablice(*this);
		chwilowy->dodaj_tablice(wart);
		return *chwilowy;

}

template<typename typ>
bool Tablica<typ>::operator ==(const Tablica<typ>& wart) const {

	if (rozmiar() != wart.rozmiar())
		return false;
	for (unsigned int i=0; i<rozmiar(); i++)
	{
		if (T[i] != wart[i])
		return false;
	}
	return true;

}

#endif
