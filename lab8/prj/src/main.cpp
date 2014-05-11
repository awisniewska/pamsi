/** \file main.cpp
 *
 * \brief Plik zawierający główną funkcję programu.
 */


#include "benchmark.hh"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


/** \brief Główna funkcja programu
 *
 *  Pozwala na zmierzenie czasu dla poszczególnych implementacji tablicy asocjacyjnej na różnych strukturach danych.
 */
int main(int argc, char **argv) {
	srand(time(NULL));
	if (argc < 4 )
	{ cerr << "Zbyt mala ilosc argumentow." << endl;
		return 0;
	}
	Benchmark timeCount;
	string whichType=argv[1];
	sType make;

	if (whichType == "aarray") make = aarray;
	else if (whichType == "hash") make = hash;
	else if (whichType == "tree") make = tree;
	else { cerr << "Wybrano nieprawidłową strukturę." << endl;
	return 0;}

	int problemSize = atoi(argv[2]);
	int noIterations = atoi(argv[3]);

	double time = timeCount.benchmark(noIterations, make, problemSize);

	cout << problemSize << "," << noIterations << "," << time << endl;


}



