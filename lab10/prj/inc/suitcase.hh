/** \file suitcase.hh
 * \brief Plik zawierający metody oraz definicje klasy Suitcase
 */
#ifndef SUITCASE_HH_
#define SUITCASE_HH_

#include "itemlist.hh"

class Suitcase: public Itemlist{
	int WeightLimit;
	int ActWeight;
	int ActValue;

public:
/** \brief Konstruktor klasy Suitcase
 *
 * \param iWeightLimit maksymalna wartość wagowa
 *
 */
	Suitcase(int iWeightLimit);

/** \brief Funkcja dodająca przedmiot do walizki
 *
 * \param item obiekt klasy Item
 * \return true , gdy dodano obiekt do walizki
 * \return false , gdy nie można dodać obiektu (np.: przekracza pozostałą wagę)
 */
	bool PutIn(const Item item);

/** \brief Funkcja zwracająca pozsotałą masę do wypełnienia walizki
 *
 * \return pozostała masa
 */
	int WeightLeft();

/** \brief Funkcja opróżniająca walizkę
 *
 */
	void Clear();

/** \brief Funkcja zwracająca wartość przedmiotów znajdujących się w walizce
 *
 * \return aktualna wartość przedmiotów w walizce
 */
	int Worth();
};

/** \brief Funkcja pakująca rzeczy do walizki tak, aby ich wartość była jak największa, a waga nie została przekroczona
 *
 * \param myitems wskaźnik na listę przedmiotów do zapakowania
 * \param mysuitcase wskaźnik na walizkę do której będziemy pakować przedmioty
 */
void Knapsack(Itemlist* myitems, Suitcase* mysuitcase);



#endif /* SUITCASE_HH_ */
