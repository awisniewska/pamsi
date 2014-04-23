/** \file hash.hh
 *
 * \brief Plik zawiera definicje szablonu klasy Hash
 */
#ifndef HASH_HH_
#define HASH_HH_

#include <stdexcept>
#include <string>
#include <vector>
#include <list>

/** \brief Szablon klasy Hash
 *
 * Definiuje funkcje pozwalające na wykonywanie operacji na tablicy asocjacyjnej stworzonej na tablicy haszującej.
 * Tablica ta przechowuje dane indeksowane unikatowymi kluczami typu string (ze standardowej biblioteki)
 * \param Value typ wartości przechowywanych danych
 */
template <class Value> class Hash {
	struct Pair {
	public:
		std::string key;
		Value value;
	};
	unsigned int currentSize;
	std::vector<std::list<Pair> > arr;
	static unsigned long hash(const std::string &key);
public:
/** \brief Konstruktor klasy Hash
 *\param problemSize docelowy rozmiar problemu
 */
	Hash(const unsigned int problemSize): currentSize(0) { arr.resize(problemSize); };

/** \brief Funkcja dodająca parę klucz-wartość do tablicy
 *
 * \param value wartość dla dodawanego klucza
 * \param key unikatowy klucz, do którego przypisujemy wartość
 */
	void Add(const std::string &key, const Value &value);

/** \brief Funkcja zwraca ilość par klucz-wartość
 * \return aktualny rozmiar tablicy
 */
	int Size() const { return currentSize; }

/** \brief Funkcja sprawdzająca, czy tablica jest pusta
 * \return true jeśli tablica jest pusta
 * \return false jeśli na tablicy są jakieś pary klucz-wartość
 */
	bool Empty() const { return (Size() == 0); }

/** \brief Operator indeksujący tablicę
 * \param key klucz wybranego elementu
 * \return referencja na wybrany element
 */
	Value& operator[](const std::string &key);
	const Value& operator[](const std::string &key) const;
};

template<class Value>
unsigned long Hash<Value>::hash(const std::string& key) {
    unsigned long hash = 0;
    int tmp;
    int pos = 0;
    while ((tmp = key[pos++]))
        hash = tmp + (hash << 6) + (hash << 16) - hash;

    return hash;
}

template<class Value>
void Hash<Value>::Add(const std::string& key,
		const Value& value) {
	Pair newPair;
	newPair.key = key;
	newPair.value = value;
	unsigned int vectPos = hash(key) % arr.size();
	arr[vectPos].push_back(newPair);
}



template<class Value>
Value& Hash<Value>::operator [](const std::string& key) {
	unsigned int vectPos = hash(key) % arr.size();
	typename std::list<Pair>::iterator it;
	for(it=arr[vectPos].begin(); it!=arr[vectPos].end(); ++it ) {
		if ((*it).key == key) {
			return (*it).value;
		}
	}
	throw std::runtime_error("Nie znaleziono klucza.");
}

template<class Value>
const Value& Hash<Value>::operator [](
		const std::string& key) const {
	unsigned int vectPos = hash(key) % arr.size();
	typename std::list<Pair>::const_iterator it;
	for(it=arr[vectPos].begin(); it!=arr[vectPos].end(); ++it ) {
		if ((*it).key == key) {
			return (*it).value;
		}
	}
	throw std::runtime_error("Nie znaleziono klucza.");
}

#endif /* HASH_HH_ */
