/** \file main.cpp
 *
 * \brief Plik zawierający główną funkcję programu.
 */


#include "graph.hh"
#include "benchmark.hh"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


/** \brief Główna funkcja programu
 *
 * Pozwala na zmierzenie czasu dla wybranego wyszukiwania.
 */
int main(int argc, char **argv) {

	srand(time(NULL));


	if (argc < 4 )
	{ cerr << "Zbyt mala ilosc argumentow." << endl;
		return 0;
	}

	Benchmark timeCount;
	string Type=argv[1];
	Implementation convert;

	if (Type == "bfs") convert = bfs;
	else if (Type == "dfs") convert = dfs;
	else if (Type == "astar") convert = astar;
	else { cerr << "Nie ma takiego wyszukiwania!" << endl;
	return 0;}

	timeCount.SampleGraph(atoi(argv[2]));
	double time = timeCount.benchmark(atoi(argv[3]), convert);
	cout << atoi(argv[2])*atoi(argv[2])+timeCount.GetEdges() << "," << atoi(argv[3]) << "," << time << endl;

}



