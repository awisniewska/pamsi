/** \file array.hh
 * \brief Plik zawiera definicje szablonu klasy Array.
 */
#include <cstdlib>
#include <iostream>


#ifndef ARRAY_HH
#define ARRAY_HH


/** \brief Szablon klasy Array
 *
 *  Definiuje funkcje pozwalajace na wykonywaniu operacji na tablicy
 *  \tparam type typ danych przechowywanych w tablicy
 */
template <typename type> class Array
{
	int *T;
	unsigned int arraySize;

public:
/** \brief
 * Konstruktor tworzacy obiekty klasy Array.
 */
	Array(): T(0), arraySize(0) {};
/** \brief
 * Destruktor usuwajacy obiekt klasy Array.
 */
	~Array() { free(T); };

/** \brief Zwraca dlugosc tablicy.
 *
 * \return liczbe elementow tablicy
 */
	unsigned int size() const
	{
		return arraySize;
	}

/** \brief Zmienia ilosc elementow tablicy.
 *
 * \param newSize rozmiar tablicy
*/
	void resize(unsigned int newSize);

/** \brief Zamienia miejscami dwa wybrane elementy
 *
 * \param a pierwszy z elementow, ktore zamieniamy miejscami
 * \param b drugi element, ktory zamieniamy z a
 */
	void changePlaces(unsigned int a, unsigned int b);

/** \brief Odwraca kolejnosc elementow tablicy.
 */
	void reverse();

/** \brief Dodaje nowy element na koniec tablicy.
 *
 * \param e element dodawany na koniec tablicy
 */
	void addElem(type e);

/** \brief Laczy dwie tablice.
 *
 * \param CA tablica, ktorej zawartosc chcemy dolaczyc
 */
	void addArrays(const Array<type> &CA);

/** \brief Przeciazenie operatora indeksujacego.
 *
 * \param nr Indeks wybranego elementu
 * \return Wartosc pod wskazanym indeksem
 */
	type& operator[](const unsigned int nr) {return T[nr];}
	const type& operator[](const unsigned int nr) const {return T[nr];}

/** \brief Przeciazenie operatora przypisania
 *
 * \param value tablica z ktorej wartosci zostana przypisane
 * \return referencje na obiekt wywolujacy
 */
	Array<type>& operator=(const Array<type> &value);

/** \brief Przeciazenie operatora dodawania
 *
 * \return tablica zawierajaca elementy z obu tablic
 */
	Array<type>& operator+(const Array<type> &value) const;

/** \brief Przeciazenie operatora porownania
 *
 * \return true - gdy tablice sa takie same
 * \return false - gdy tablice sie roznia
 */
	bool operator==(const Array<type> &value) const;

};

template<typename type>
void Array<type>::resize(unsigned int newSize) {

	T = (type*)realloc(T, newSize * sizeof(type));
		arraySize=newSize;

}

template<typename type>
void Array<type>::changePlaces(unsigned int a, unsigned int b) {

	type tmp1, tmp2;
	tmp1=T[a];
	tmp2=T[b];
	T[a]=tmp2;
	T[b]=tmp1;

}

template<typename type>
void Array<type>::reverse() {

	for (unsigned int i=0; i<(arraySize/2); i++)
	{
		changePlaces(i, arraySize-i-1);
	}

}

template<typename type>
void Array<type>::addElem(type e) {

	resize(size()+1);
	T[arraySize-1] = e;

}

template<typename type>
void Array<type>::addArrays(const Array<type>& CA) {

	unsigned int last = size();
	resize(size()+CA.size());
	for (unsigned int i=0; i<CA.size(); i++)
	{
		T[last+i] = CA[i];
	}

}

template<typename type>
Array<type>& Array<type>::operator =(const Array<type>& value) {

	resize(value.size());
	for (unsigned i=0; i<size(); i++)
	{
		T[i] = value[i];
	}
	return *this;

}

template<typename type>
Array<type>& Array<type>::operator +(const Array<type>& value) const {

		Array<type> *temp = new Array<type>;
		temp->addArrays(*this);
		temp->addArrays(value);
		return *temp;

}

template<typename type>
bool Array<type>::operator ==(const Array<type>& value) const {

	if (size() != value.size())
		return false;
	for (unsigned int i=0; i<size(); i++)
	{
		if (T[i] != value[i])
		return false;
	}
	return true;

}

#endif /* ARRAY_HH_ */
