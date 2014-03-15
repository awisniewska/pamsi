#ifndef KOLEJKA_HH_
#define KOLEJKA_HH_

#include <list>

template <typename typ> class Kolejka
{
	std::list<typ> lista;

public:

	unsigned int rozmiar() const
		{
			return lista.size();
		}

	bool isEmpty() const
	{
		return lista.empty();
	}

	const typ& top() const
	{
		return lista.front();
	}

	void enqueue (const typ elem)
	{
		lista.push_back(elem);
	}
	void dequeue ()
	{
		lista.pop_front();
	}
};


#endif /* KOLEJKA_HH_ */
