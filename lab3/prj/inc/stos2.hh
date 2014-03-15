#ifndef STOS2_HH_
#define STOS2_HH_

#include "tablica.hh"
#include <stack>

template <typename typ> class Stos2
{
	Tablica<typ> tabElem;
	unsigned int dlugoscTab;
	public:
	Stos2(): dlugoscTab(0) {}
	unsigned int rozmiar() const
	{
		return dlugoscTab;
	}

	void push (typ elem);
	void pop();
	bool isEmpty() const
	{
		return (dlugoscTab==0);
	}
	const typ& top() const
	{
		return tabElem[dlugoscTab-1];
	}

};

template<typename typ>
void Stos2<typ>::push(typ elem) {
	dlugoscTab++;
	if (dlugoscTab > tabElem.rozmiar())

	{ 	if (tabElem.rozmiar()==0)
			tabElem.zmienRozmiar(1);
		else
			tabElem.zmienRozmiar(tabElem.rozmiar()*2);
	}
	tabElem[dlugoscTab-1]=elem;

}

template<typename typ>
void Stos2<typ>::pop() {
	dlugoscTab--;
	if (dlugoscTab*4 < tabElem.rozmiar())
	{
		tabElem.zmienRozmiar(dlugoscTab);
	}

}

#endif /* STOS2_HH_ */
