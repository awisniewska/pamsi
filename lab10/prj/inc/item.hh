/** \file item.hh
 * \brief Plik zawierający metody oraz definicje klasy Item.
 */

#ifndef ITEM_HH_
#define ITEM_HH_

#include <string>

class Item {
	std::string ItemName;
	int ItemWeight;
	int ItemValue;

public:
/** \brief Funkcja pobierająca nazwę przedmiotu
 *
 * \return nazwę przedmiotu
 */
	std::string GetName() const { return ItemName; }

/** \brief Funkcja pobierająca wagę przedmiotu
 *
 * \return waga przedmiotu w gramach
 */
	int GetWeight() const { return ItemWeight; }

/** \brief Funkcja pobierająca wartość przedmiotu
 *
 * \return wartość przedmiotu w złotówkach
 */
	int GetValue() const { return ItemValue; }

/** \brief Funkcja pobierająca warość przedmiotu na 1 g
 *
 * \return wartość przedmiotu na 1 g
 */
	float GetValuePerWeigt() const { return (ItemValue / ItemWeight); }

/** \brief Konstruktor parametyczny klasy Item
 *
 */
	Item(std::string iName, int iWeight, int iValue );

};


#endif /* ITEM_HH_ */
