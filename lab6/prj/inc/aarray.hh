/** \file aarray.hh
 * \brief Plik zawiera definicje szablonu klasy Aarray
 */

#ifndef AARRAY_HH_
#define AARRAY_HH_

#include <vector>
#include <string>

/* \brief Szablon klasy Aarray
 *
 * Definiuje funkcje pozwalające na wykonywanie operacji na tablicy asocjacyjnej.
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
	void Add(Value value, std::string key);

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
	void ChangeValue(Value newValue, std::string key);

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
void Aarray<Value>::Add(Value value, std::string key) {
	Pair newValue;
	newValue.key=key;
	newValue.value=value;
	PairVec.push_back(newValue);
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
void Aarray<Value>::ChangeValue(Value newValue, std::string key) {
	PairVec[Search(key)].value=newValue;
}

template<class Value>
unsigned int Aarray<Value>::Size() {
	return PairVec.size();
}

template<class Value>
unsigned int Aarray<Value>::Search(std::string key) {
	for (unsigned int i=0; i<PairVec.size(); i++)
	{
		if (PairVec[i].key == key)
		{
			return i;
		}
	}
}

template<class Value>
bool Aarray<Value>::IsEmpty() {
	if (PairVec.size()==0)
			return true;
	else return false;
}

#endif /* AARRAY_HH_ */
