/**
 * \file tree.hh
 *
 */
#ifndef TREE_HH_
#define TREE_HH_

#include <stdexcept>
#include <string>


template <class Value> class Tree {
	class TreeElement{
	public:
		std::string key;
		Value value;
		TreeElement *left;
		TreeElement *right;
		TreeElement(const std::string &newKey, const Value &newValue): key(newKey), value(newValue), left(NULL), right(NULL) {}
	};

	unsigned int count;
	TreeElement *root;
	void* find(const std::string &key) const;

public:
	Tree(): count(0), root(NULL) {}

	void Add(const std::string &key, const Value &value);
	void Delete(const std::string &key);
	int Size() const { return count; }
	bool IsEmpty() const { return (Size() == 0); }
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
void Tree<Value>::Delete(const std::string& key) {

}

template<class Value>
Value& Tree<Value>::operator [](const std::string& key) {
	TreeElement *tmp;
	tmp = static_cast<TreeElement *>(find(key));
	return tmp->value;
}

template<class Value>
const Value& Tree<Value>::operator [](
		const std::string& key) const {
	TreeElement *tmp;
	tmp = static_cast<TreeElement *>(find(key));
	return tmp->value;
}

#endif /* TREE_HH_ */
