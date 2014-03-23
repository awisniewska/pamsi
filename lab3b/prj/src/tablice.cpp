/** \file tablice.cpp
 * \brief Plik zawiera implementacje klasy Tablice.
 */

#include <iostream>
#include <fstream>
#include "tablice.hh"
#include "quicksort.hh"
#include <ctime>

using namespace std;

bool Tablice::wczytaj(char *nazwaPliku)
{
	ifstream plikWej(nazwaPliku);

		if (!plikWej.good())
		{ cerr << "Wybrano nieprawidlowy plik wejsciowy." << endl;
			return false;
		}

		unsigned int dlugoscTab;
		plikWej >> dlugoscTab;

		if (!plikWej.good())
				{ cerr << "Blad wczytywania." << endl;
					return false;
				}

		tablica.resize(dlugoscTab);
		tablica2.resize(dlugoscTab);

		for (unsigned int i=0; i<dlugoscTab; i++)
		{
			plikWej >> tablica[i];
			if (!plikWej.good())
					{ cerr << "Blad wczytywania." << endl;
						return false;
					}
		}
		return true;
}

void Tablice::oblicz()
{
tablica2=tablica;
quicksort(tablica2, 0, tablica2.size()-1);
}

bool Tablice::sprawdz(char *nazwaPliku)
{
	ifstream plikSprawdz(nazwaPliku);

			if (!plikSprawdz.good())
			{ cerr << "Wybrano nieprawidlowy plik sprawdzajacy." << endl;
				return false;
			}

			unsigned int dlugoscTab2;
			plikSprawdz >> dlugoscTab2;
			if (!plikSprawdz.good())
					{ cerr << "Blad wczytywania." << endl;
						return false;
					}
			if (tablica2.size()!=dlugoscTab2)
			{ cerr << "Tablice nie sa takiej samej dlugosci." << endl;
				return false;
			}

			for (unsigned int i=0; i<tablica2.size(); i++)
			{
				int tmp;
				plikSprawdz >> tmp;
				if (!plikSprawdz.good())
						{ cerr << "Blad wczytywania." << endl;
							return false;
						}
				if (tmp!=tablica2[i])
				{ cerr << "Porownywane wartosci elementu nr " << i+1 << " nie sa takie same" << endl;
					return false;
				}
			}
			return true;
}

double Tablice::benchmark(int liczbaPowtorzen)
{

	clock_t t = clock();
	for (int i=0; i<liczbaPowtorzen; i++) {
	oblicz();
	}
	t = clock()-t;

	return ( ((double)t)/CLOCKS_PER_SEC );
}

void Tablice::drukujWyjscie() {
	for (unsigned int i=0; i<tablica2.size(); i++) {
cout << tablica2[i] << endl;
	}
}
