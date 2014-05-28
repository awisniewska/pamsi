/** \file itemlist.hh
 * \brief  Plik zawierający metody oraz definicje klasy Itemlist
 */

#ifndef ITEMLIST_HH_
#define ITEMLIST_HH_

#include <vector>
#include <item.hh>

class Itemlist: public std::vector<Item>{
public:
/** \brief Funkcja wczytująca dane z pliku
 *
 * \return true , gdy plik zostanie wczytany poprawnie
 * \return false , gdy przy wczytywaniu pliku wystąpi błąd
 */
	bool Load(char *FileName);

/** \brief Funkcja pomocnicza, wyświetlająca listę przedmiotów
 *
 */
	void Show();
};



#endif /* ITEMLIST_HH_ */
