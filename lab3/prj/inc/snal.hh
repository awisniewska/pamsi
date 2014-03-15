
#ifndef SNAL_HH_
#define SNAL_HH_

#include <list>

template <typename typ> class Snal
{
	std::list<typ> lista;

public:

	unsigned int rozmiar() const
		{
			return lista.size();
		}
	void push (typ elem)
	{
		lista.push_back(elem);
	}
	void pop()
	{
		lista.pop_back();
	}

	bool isEmpty() const
	{
		return lista.empty();
	}

	const typ& top() const
	{
		return lista.back();
	}
};


#endif /* SNAL_HH_ */
