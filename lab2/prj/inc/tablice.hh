/** \file tablice.hh
 * \brief Plik zawiera definicje klasy Tablice.
 */


#ifndef TABLICE_HH
#define TABLICE_HH

#include "tablica.hh"

/** \brief Klasa mierzaca czas mnozenia tablicy przez 2
 *
 *  Klasa obiektow umozliwiajaca wczytywanie danych z plikow do tablicy, mnozenie tablicy o i-elementach razy dwa oraz porownanie jej z danymi z pliku sprawdzajacego.
 *
 */
class Tablice
{

private:
	Tablica tablica;
	Tablica tablica2;
	/** \brief
	*  Funkcja realizujaca wybrany algorytm.
	*/
	void oblicz();

public:
	/** \brief Funkcja wczytujaca dane z wybranego pliku.
	 *
	 */
	bool wczytaj(char *nazwaPliku);
	/** \brief Funkcja porownujaca dane z pliku zrodlowego po wykonaniu operacji mnozenia z danym z pliku sprawdzajacego.
	 *
	 */
	bool sprawdz(char *nazwaPliku);
	/** \brief
	 * Funkcja mierzaca czas wykonywania algorytmu mnozenia.
	 */
	double benchmark(int liczbaPowtorzen);
	/** \brief
	 *  \return Zwraca dlugosc tablicy.
	 */
	int rozmiar() { return tablica.rozmiar(); }
};

#endif
