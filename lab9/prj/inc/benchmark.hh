/** \file benchmark.hh
 * \brief Plik zawiera definicje klasy Benchmark oraz typu Implementation.
 */


#ifndef BENCHMARK_HH
#define BENCHMARK_HH

#include "graph.hh"

/** \brief Typ danych przechowujacy rodzaj wyszukiwania.
 *
 */
enum Implementation { bfs, dfs, astar };

/** \brief Definicja klasy Benchmark
 *
 * Klasa służy do pomiaru czasu wykonywania algorytmu dla wybranych implementacji.
 */
class Benchmark
{

private:

	Graph<int> benchGraph;
	unsigned int Edges, Vertices, Side;
	void calculate(Implementation Type);

public:

	/** \brief
	 * Funkcja mierzaca czas wykonywania algorytmu przeszukiwania grafu.
	 * \param noIteration liczba powtórzeń algorytmu
	 * \param Type rodzaj przeszukiwania
	 */
	double benchmark(int noIteration, Implementation Type);

	/** \brief
	 * Funkcja wypełniając graf testowymi danymi.
	 * \param VertCount ilość wierzchołków w grafie
	 */
	void SampleGraph(const unsigned int VertCount);

	/** \brief
	 *  Funkcja pobierająca ilość krawędzi w grafie
	 *  \return liczba krawędzi w grafie
	 */
	unsigned int GetEdges()
	{
		return Edges;
	}


};

#endif /* BENCHMARK_HH_ */
