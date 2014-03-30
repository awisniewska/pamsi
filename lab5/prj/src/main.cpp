/** \file main.cpp
 * \brief Plik zawiera glowna funkcje programu.
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdlib>
#include <ctime>
#include "benchmark.hh"

using namespace std;

/** \brief Glowna funkcja programu
 *
 *  Pobiera argumenty z linii polecen, przekazuje je do odpowiedniej klasy i wyswietla wyniki pomiarow czasu.
 */

int main(int argc, char **argv) {
	srand(time(NULL));


	if (argc < 5 )
	{ cerr << "Zbyt mala ilosc argumentow." << endl;
		return 0;
	}

	Benchmark timeCount;
	string sortType=argv[1];
	sortingType convert;

	if (sortType == "quick") convert = quick;
	else if (sortType == "merge") convert = merge;
	else if (sortType == "heap") convert = heap;
	else { cerr << "Nie ma takiego sortowania!" << endl;
	return 0;}

	if (!timeCount.load(argv[2])) return 0;
	double time = timeCount.benchmark(atoi(argv[4]), convert);
	if (!timeCount.check(argv[3])) return 0;

	cout << timeCount.size() << "," << atoi(argv[4]) << "," << time << endl;


}
