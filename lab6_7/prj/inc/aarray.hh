/** \file aarray.hh
 * \brief Plik zawiera definicje szablonu klasy Aarray
 */

#ifndef AARRAY_HH_
#define AARRAY_HH_

#include <vector>
#include <string>
#include <stdexcept>

/* \brief Szablon klasy Aarray
 *
 * Definiuje funkcje pozwalające na wykonywanie operacji na tablicy asocjacyjnej stworzonej na wektorze.
 * \param Value typ wartości przechowywanych w tablicy
 *
 */
template<class Value> class Aarray {
	struct Pair{
		std::string key;
		Value value;
	};

	std::vector<Pair> PairVec;
	unsigned int Search(std::string key);

public:
/** \brief Funkcja dodająca parę klucz-wartość do tablicy
 * \param value wartość dla dodawanego klucza
 * \param key unikatowy klucz, do którego przypisujemy wartość
 *
 */
	void Add(std::string key, Value value);

/** \brief Funkcja usuwająca wybraną parę klucz-wartość z tablicy
 * \param key klucz, który usuwamy wraz z jego wartością
 *
 */
	void Delete(std::string key);

/** \brief Funkcja pobierająca wartość wybranego klucza
 * \param key klucz, którego wartość chcemy znać
 *
 */
	Value GetValue(std::string key);

/** \brief Funkcja zmieniająca wartość pod wybranym kluczem
 * \param newValue nowa wartość dla klucza
 * \param key unikatowy klucz, którego wartość zmieniamy
 */
	void ChangeValue(std::string key, Value newValue);

/** \brief Funkcja zwraca ilość par klucz-wartość
 *
 */
	unsigned int Size();

/** \brief Funkcja sprawdzająca, czy tablica jest pusta
 * \return true jeśli tablica jest pusta
 * \return false jeśli na tablicy są jakieś pary klucz-wartość
 */
	bool IsEmpty();


};


template<class Value>
void Aarray<Value>::Add(std::string key, Value value) {
	Pair newValue;
	newValue.key=key;
	newValue.value=value;
	unsigned int i=0;
	for (;;)
	{
		if (i>=PairVec.size())
		{
			break;
		}
		else if(PairVec[i].key > key)
		{
			break;
		}
		else {
			i++;
		}
	}

	PairVec.insert(PairVec.begin()+i, newValue);

}

template<class Value>
void Aarray<Value>::Delete(std::string key) {
	PairVec.erase(PairVec.begin()+Search(key));
}

template<class Value>
Value Aarray<Value>::GetValue(std::string key) {
	return PairVec[Search(key)].value;
}

template<class Value>
void Aarray<Value>::ChangeValue(std::string key, Value newValue) {
	PairVec[Search(key)].value=newValue;
}

template<class Value>
unsigned int Aarray<Value>::Size() {
	return PairVec.size();
}

template<class Value>
unsigned int Aarray<Value>::Search(std::string key) {
int first = 0;
int last = PairVec.size()-1;
int i = 0;
while(first<=last){
	i = (first+last)/2;

	if (PairVec[i].key == key)
	{
		return i;
	}

	else if (PairVec[i].key < key)
	{
		first = i + 1;
	}
	else
	{
		last = i - 1;
	}
}
throw std::runtime_error("Nie ma takiego klucza.");
}

template<class Value>
bool Aarray<Value>::IsEmpty() {
	if (PairVec.size()==0)
			return true;
	else return false;
}

#endif /* AARRAY_HH_ */
