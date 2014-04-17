/** \file main.cpp
 * \brief Plik zawiera glowna funkcje programu.
 */

#include <iostream>
#include <tablice.hh>
#include <cstdlib>

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

	Tablice liczCzas;
	if (!liczCzas.wczytaj(argv[1])) return 0;
	double czas = liczCzas.benchmark(atoi(argv[3]));
	if (!liczCzas.sprawdz(argv[2])) return 0;


	cout << liczCzas.rozmiar() << "," << atoi(argv[3]) << "," << czas << "s" << endl;
}
