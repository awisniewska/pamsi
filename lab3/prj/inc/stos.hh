#ifndef STOS_HH_
#define STOS_HH_

#include "tablica.hh"
#include <stack>

template <typename typ> class Stos
{
	Tablica<typ> tabElem;
	public:
	unsigned int rozmiar() const
	{
		return tabElem.rozmiar();
	}

	void push (typ elem);
	void pop();
	bool isEmpty() const
	{
		return (tabElem.rozmiar()==0);
	}
	const typ& top() const
	{
		return tabElem[tabElem.rozmiar()-1];
	}

};

template<typename typ>
void Stos<typ>::push(typ elem) {

	tabElem.zmienRozmiar(tabElem.rozmiar()+1);
	tabElem[tabElem.rozmiar()-1]=elem;

}

template<typename typ>
void Stos<typ>::pop() {

	tabElem.zmienRozmiar(tabElem.rozmiar()-1);

}

#endif /* STOS_HH_ */
