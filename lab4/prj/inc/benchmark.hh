/** \file benchmark.hh
 * \brief Plik zawiera definicje klasy Benchmark oraz typu sortingType.
 */


#ifndef BENCHMARK_HH
#define BENCHMARK_HH

#include "array.hh"

/** \brief Typ danych przechowujacy rodzaj sortowania
 *
 */
enum sortingType { quick, merge, heap };

/** \brief Definicja klasy Benchmark
 *
 *  Klasa obiektow umozliwiajaca wczytywanie danych z plikow do tablicy, wykonania wybranych obliczen oraz kontrole poprawnosci wykonywania obliczen z plikiem sprawdzajacym. Glownym zadaniem klasy jest mierzenie czasu wykonywanych algorytmow.
 *
 */
class Benchmark
{

private:
	Array<int> array1;
	Array<int> array2;

	void calculate(sortingType type);

public:
	/** \brief Funkcja wczytujaca dane z wybranego pliku.
	 *
	 */
	bool load(char *fileName);

	/** \brief Funkcja porownujaca dane z pliku zrodlowego po wykonaniu wybranego sortowania z danym z pliku sprawdzajacego.
	 *
	 */
	bool check(char *fileName);

	/** \brief
	 * Funkcja mierzaca czas wykonywania algorytmu sortowania.
	 */
	double benchmark(int noIteration, sortingType type);

	/** \brief
	 *  \return Zwraca dlugosc tablicy.
	 */
	int size() { return array1.size(); }

};

#endif /* BENCHMARK_HH_ */
