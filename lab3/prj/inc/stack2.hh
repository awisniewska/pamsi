/** \file stack2.hh
 * \brief Plik zawiera deklaracje zwiazane z szablonem klasy Stack2
 */

#ifndef STACK2_HH_
#define STACK2_HH_

#include "array.hh"
#include <stack>

/** \brief Szablon klasy Stack2
 *
 * Definiuje funkcje pozwalajace na wykonywanie operacji na stosie
 * \tparam type typ danych przechowywanych na stosie
 */
template <typename type> class Stack2
{
	Array<type> array;
	unsigned int arrSize;
	public:
/** \brief Konstruktor tworzacy obiekt klasy Stack2
 */
	Stack2(): arrSize(0) {}

/** \brief Pobiera rozmiar stosu
 *
 *  \return ilosc elementow na stosie
 */
	unsigned int size() const
	{
		return arrSize;
	}

/** \brief Dodaje element na stos
 *
 * \param elem element, ktory dodajemy na szczyt stosu
 */
	void push (type elem);

/** \brief Zabiera element ze szczytu stosu
 *
 * \pre stos nie moze byc pusty
 */
	void pop();

/** \brief Sprawdza, czy stos jest pusty
 *
 *  \return true - jesli stos jest pusty
 *  \return false - jesli stos zawiera co najmniej 1 element
 */
	bool isEmpty() const
	{
		return (arrSize==0);
	}

/** \brief Udostepnia element ze szczytu stosu
 *
 * \pre stos nie moze byc pusty
 * \return zawartosc ostatniego elementu stosu
 */
	const type& top() const
	{
		return array[arrSize-1];
	}
};

template<typename type>
void Stack2<type>::push(type elem) {
	arrSize++;
	if (arrSize > array.size())

	{ 	if (array.size()==0)
			array.resize(1);
		else
			array.resize(array.size()*2);
	}
	array[arrSize-1]=elem;

}

template<typename type>
void Stack2<type>::pop() {
	arrSize--;
	if (arrSize*4 < array.size())
	{
		array.resize(arrSize);
	}

}

#endif /* STACK2_HH_ */
