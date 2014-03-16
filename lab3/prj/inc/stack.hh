/** \file stack.hh
 * \brief Plik zawiera deklaracje zwiazane z szablonem klasy Stack
 */

#ifndef STACK_HH_
#define STACK_HH_

#include "array.hh"
#include <stack>


/** \brief Szablon klasy Stack
 *
 * Definiuje funkcje pozwalajace na wykonywanie operacji na stosie
 * \tparam type typ danych przechowywanych na stosie
 */
template <typename type> class Stack
{
	Array<type> array;
	public:
/** \brief Pobiera rozmiar stosu
 *
 *  \return ilosc elementow na stosie
 */
	unsigned int size() const
	{
		return array.size();
	}

/** \brief Dodaje element na szczyt stosu
 *
 *  \param elem element, ktory dodajemy na szczyt stosu
 */
	void push (type elem);

/** \brief Zabiera element ze szczytu stosu
 *
 * \pre stos nie moze byc pusty
 */
	void pop();

/** \brief Sprawdza, czy stos nie jest pusty
 *
 * \return true - jesli stos jest pusty
 * \return false - jesli stos zawiera co najmniej 1 element
 */
	bool isEmpty() const
	{
		return (array.size()==0);
	}

/** \brief Udostepnia element ze szczytu stosu
 *
 * \pre stos nie moze byc pusty
 * \return zawartosc ostatniego elementu stosu
 */
	const type& top() const
	{
		return array[array.size()-1];
	}

};

template<typename type>
void Stack<type>::push(type elem) {

	array.resize(array.size()+1);
	array[array.size()-1]=elem;

}

template<typename type>
void Stack<type>::pop() {

	array.resize(array.size()-1);

}

#endif /* STACK_HH_ */
