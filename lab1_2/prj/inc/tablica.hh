/** \file tablica.hh
 * \brief Plik zawiera definicje klasy Tablica.
 */
#include <cstdlib>


#ifndef TABLICA_HH
#define TABLICA_HH

/** \brief Klasa implementujaca tablice dynamiczna
 *
 *  Klasa przechowuje tablice liczb calkowitych oraz umozliwia podstawowe operacje na nich.
 *
 */
class Tablica
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
	void dodaj_element(int e);
/** \brief
 * Funkcja laczaca dwie tablice.
 */
	void dodaj_tablice(const Tablica &TL);

/** \brief
 * Przeciazenie operatora indeksujacego.
 * \param nr Indeks wybranego elementu
 * \return Wartosc pod wskazanym indeksem
 */
	int& operator[](const unsigned int nr) {return T[nr];}
	const int& operator[](const unsigned int nr) const {return T[nr];}

/** \brief Przeciazenie operatora przypisania
 * \param wart tablica z ktorej wartosci zostana przypisane
 * \return referencje na obiekt wywolujacy
 */
	Tablica& operator=(const Tablica &wart);
/** \brief Przeciazenie operatora dodawania
 * \return tablice zawieraja elementy z obu tablic
 */
	Tablica& operator+(const Tablica &wart) const;
/** \brief Przeciazenie operatora porownania
 * \return true - gdy tablice sa takie same
 * \return false - gdy tablice sie roznia
 *
 */
	bool operator==(const Tablica &wart) const;

};

#endif
