/** \file queue.hh
 * \brief Plik zawiera deklaracje zwiazane z szablonem klasy Queue
 */

#ifndef QUEUE_HH_
#define QUEUE_HH_

#include <list>

/** \brief Szablon klasy Queue
 *
 * Definiuje funkcje pozwalajace na wykonywaniu operacji na kolejce
 * \tparam type typ danych przechowywanych na liscie
 */
template <typename type> class Queue
{
	std::list<type> flist;

public:
/** \brief Pobiera rozmiar kolejki
 *
 * \return ilosc elementow kolejki
 */
	unsigned int size() const
		{
			return flist.size();
		}

/** \brief Sprawdza, czy kolejka jest pusta
 *
 *  \return true - jesli lista jest pusta
 *  \return false - jesli na liscie jest co najmniej 1 element
 */
	bool isEmpty() const
	{
		return flist.empty();
	}

/** \brief Udostepnia pierwszy element listy(kolejki)
 *
 * \return zawartosc pierwszego elementu kolejki
 */
	const type& top() const
	{
		return flist.front();
	}

/** \brief Dodaje element na koniec kolejki
 *
 * \param elem element dodawany na koniec kolejki
 */
	void enqueue (const type elem)
	{
		flist.push_back(elem);
	}

/** \brief Zabiera element z poczatku listy
 */
	void dequeue ()
	{
		flist.pop_front();
	}
};


#endif /* QUEUE_HH_ */
