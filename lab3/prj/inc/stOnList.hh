/** \file stOnList.hh
 * \brief Plik zawiera deklaracje zwiazane z szablonem klasy stOnList
 */

#ifndef STONLIST_HH_
#define STOLIST_HH_

#include <list>

/** \brief Szablon klasy stOnList
 *
 * Definiuje funkcje pozwalajace na wykonywanie operacji na liscie
 * \tparam type typ danych przechowywanych na liscie
 */
template <typename type> class stOnList
{
	std::list<type> flist;

public:
/** \brief Pobiera rozmiar listy
 *  \return liczba elementow listy
 *
 */
	unsigned int size() const
		{
			return flist.size();
		}

/** \brief Dodaje element na koniec listy
 *  \param elem element dodawany na koniec listy
 *
 */
	void push (type elem)
	{
		flist.push_back(elem);
	}

/** \brief Zabiera element z konca listy
 * \pre lista nie moze byc pusta
 *
 */
	void pop()
	{
		flist.pop_back();
	}

/** \brief Sprawdza, czy lista jest pusta
 * \return true - jesli lista jest pusta
 * \return false - jesli na liscie jest co najmniej 1 element
 *
 */
	bool isEmpty() const
	{
		return flist.empty();
	}

/** \brief Udostepnia ostatni element listy
 * \return zawartosc ostatniego elementu listy
 *
 */
	const type& top() const
	{
		return flist.back();
	}
};


#endif /* STONLIST_HH_ */
