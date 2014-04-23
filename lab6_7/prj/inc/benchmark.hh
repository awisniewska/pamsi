/** \file benchmark.hh
 * \brief Plik zawiera definicje klasy Benchmark oraz typu sType.
 */


#ifndef BENCHMARK_HH
#define BENCHMARK_HH

#include "aarray.hh"
#include "hash.hh"
#include "tree.hh"
#include <string>

/** \brief Typ danych przechowujacy poszczególne struktury danych.
 *
 */
enum sType { aarray, hash, tree };

/** \brief Definicja klasy Benchmark
 *
 *  Glownym zadaniem klasy jest mierzenie czasu wykonywanych algorytmow. Klasa obiektow umozliwiaja także wykonywanie zadanych obliczen.
 *
 */
class Benchmark
{

private:

	void Calculate(sType type);
	Aarray<int> *aarrayptr;
	Hash<int> *hashptr;
	Tree<int> *treeptr;
	std::string Tmp;


public:
	/** \brief
	 * Funkcja mierzaca czas wykonywania algorytmu sortowania.
	 */
	double benchmark(int noIteration, sType type, int problemSize);


};

#endif /* BENCHMARK_HH_ */
