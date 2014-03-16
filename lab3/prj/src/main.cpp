/** \file main.cpp
 * \brief Plik zawiera glowna funkcje programu.
 */

#include <iostream>
#include "benchmark.hh"
#include <cstdlib>
#include <string>

using namespace std;

/** \brief Glowna funkcja programu
 *
 *  Pobiera argumenty z linii polecen, przekazuje je do odpowiedniej klasy i wyswietla wyniki pomiarow czasu.
 */

int main(int argc, char **argv) {


	if (argc < 4 )
	{ cerr << "Zbyt mala ilosc argumentow." << endl;
		return 0;
	}

	unsigned int noIteration, problemSize;
	problemSize=atoi(argv[2]);
	noIteration=atoi(argv[3]);
	double time;
	if (string (argv[1])=="stack")
		{
		BenchStack<Stack<int> > benchmark;
		time=benchmark.benchmark(noIteration, problemSize);
		}
	else if (string (argv[1])=="stack2")
		{
		BenchStack<Stack2<int> > benchmark;
		time=benchmark.benchmark(noIteration, problemSize);
		}
	else if (string (argv[1])=="queue")
		{
		BenchQueue<Queue<int> > benchmark;
		time=benchmark.benchmark(noIteration, problemSize);
		}
	else if (string (argv[1])=="stonlist")
		{
		BenchStack<stOnList<int> > benchmark;
		time=benchmark.benchmark(noIteration, problemSize);
		}

	else
		{
			cerr << "Wybrano nieistniejaca nazwe klasy." << endl;
			return 0;
		}

	cout << problemSize << "," << noIteration << "," << time << endl;

}
