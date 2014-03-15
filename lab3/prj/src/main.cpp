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
 *  Pobiera argumenty z linii polecen, przekazuje je do klasy Tablice i wyswietla wyniki pomiarow czasu.
 */

int main(int argc, char **argv) {


	if (argc < 4 )
	{ cerr << "Zbyt mala ilosc argumentow." << endl;
		return 0;
	}

	unsigned int iloscPowtorzen, rozmiarProblemu;
	rozmiarProblemu=atoi(argv[2]);
	iloscPowtorzen=atoi(argv[3]);
	double czas;
	if (string (argv[1])=="stos")
		{
		BenchStosu<Stos<int> > benchmark;
		czas=benchmark.benchmark(iloscPowtorzen, rozmiarProblemu);
		}
	else if (string (argv[1])=="stos2")
		{
		BenchStosu<Stos2<int> > benchmark;
		czas=benchmark.benchmark(iloscPowtorzen, rozmiarProblemu);
		}
	else if (string (argv[1])=="kolejka")
		{
		BenchKolejki<Kolejka<int> > benchmark;
		czas=benchmark.benchmark(iloscPowtorzen, rozmiarProblemu);
		}
	else if (string (argv[1])=="snal")
		{
		BenchStosu<Snal<int> > benchmark;
		czas=benchmark.benchmark(iloscPowtorzen, rozmiarProblemu);
		}

	else
		{
			cerr << "Wybrano nieistniejaca nazwe klasy." << endl;
			return 0;
		}

	cout << rozmiarProblemu << "," << iloscPowtorzen << "," << czas << "s" << endl;

}
