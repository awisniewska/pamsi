/** \file tree.hh
 * \brief Plik zawiera definicje szablonu klasy Tree
 */
#ifndef TREE_HH_
#define TREE_HH_

#include <stdexcept>
#include <string>

/** \brief Szablon klasy Hash
 *
 * Definiuje funkcje pozwalające na wykonywanie operacji na tablicy asocjacyjnej stworzonej na drzewie binarnym.
 * \param Value typ wartości przechowywanych danych
 */
template <class Value> class Tree {
	class TreeElement{
	public:
		std::string key;
		Value value;
		TreeElement *left;
		TreeElement *right;
		TreeElement(const std::string &newKey, const Value &newValue): key(newKey), value(newValue), left(NULL), right(NULL) {}
	};

	unsigned int arrSize;
	TreeElement *root;
	void* find(const std::string &key) const;
	static void Deletee(TreeElement *pointer);

public:
/** \brief Konstruktor klasy Tree
 */
	Tree(): arrSize(0), root(NULL) {}

/** \brief Destruktor klasy Tree
 */
	~Tree();

/** \brief Funkcja dodająca parę klucz-wartość
 *
 * \param value wartość dla dodawanego klucza
 * \param key unikatowy klucz, do którego przypisujemy wartość
 */
	void Add(const std::string &key, const Value &value);

/** \brief Funkcja zwraca ilość par klucz-wartość
 * \return aktualny rozmiar tablicy
 */
	int Size() const { return arrSize; }

/** \brief Funkcja sprawdzająca, czy tablica jest pusta
 * \return true jeśli tablica jest pusta
 * \return false jeśli na tablicy są jakieś pary klucz-wartość
 */
	bool isEmpty() const { return (Size() == 0); }

/** \brief Operator indeksujący tablicę
 * \param key klucz wybranego elementu
 * \return referencja na wybrany element
 */
	Value& operator[](const std::string &key);
	const Value& operator[](const std::string &key) const;
};

template<class Value>
void Tree<Value>::Add(const std::string& key,
		const Value& value) {
	TreeElement *newElement = new TreeElement(key, value);
	TreeElement **tmp = &root;
	while (*tmp != NULL) {
		if( key < (**tmp).key ) {
			tmp = &(**tmp).left;
		}
		else {
			tmp = &(**tmp).right;
		}
	}
	*tmp = newElement;
}

template<class Value>
void* Tree<Value>::find(const std::string& key) const{
	TreeElement * const *tmp = &root;
	while (*tmp != NULL) {
		if( key == (**tmp).key ) {
			return *tmp;
		}
		else if( key < (**tmp).key ) {
			tmp = &(**tmp).left;
		}
		else {
			tmp = &(**tmp).right;
		}
	}
	throw std::runtime_error("Nie odnaleziono klucza.");
}


template<class Value>
Value& Tree<Value>::operator [](const std::string& key) {
	TreeElement *tmp;
	tmp = static_cast<TreeElement *>(find(key));
	return tmp->value;
}

template<class Value>
void Tree<Value>::Deletee(TreeElement* pointer) {
	if (pointer==NULL) return;
	else
	{
		Deletee(pointer->right);
		Deletee(pointer->left);
		delete pointer;
	}
}

template<class Value>
Tree<Value>::~Tree() {
	Deletee(root);
}

template<class Value>
const Value& Tree<Value>::operator [](
		const std::string& key) const {
	TreeElement *tmp;
	tmp = static_cast<TreeElement *>(find(key));
	return tmp->value;
}

#endif /* TREE_HH_ */
