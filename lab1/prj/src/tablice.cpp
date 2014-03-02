/** \file tablice.cpp
 * \brief Plik zawiera implementacje klasy tablica.
 */

#include <iostream>
#include <fstream>
#include <tablice.hh>
#include <ctime>

using namespace std;

bool Tablice::wczytaj(char *nazwaPliku)
{
	ifstream plikWej(nazwaPliku);

		if (!plikWej.good())
		{ cerr << "Wybrano nieprawidlowy plik wejsciowy." << endl;
			return false;
		}

		plikWej >> dlugoscTab;

		if (!plikWej.good())
				{ cerr << "Blad wczytywania." << endl;
					return false;
				}
		
		tablica = new int[dlugoscTab];
		tablica2 = new int[dlugoscTab];

		for (int i=0; i<dlugoscTab; i++)
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
	for (int i=0; i<dlugoscTab; i++)
		{
			tablica2[i] = tablica[i]*2;
		}
}

bool Tablice::sprawdz(char *nazwaPliku)
{
	ifstream plikSprawdz(nazwaPliku);

			if (!plikSprawdz.good())
			{ cerr << "Wybrano nieprawidlowy plik sprawdzajacy." << endl;
				return false;
			}

			int dlugoscTab2;
			plikSprawdz >> dlugoscTab2;
			if (!plikSprawdz.good())
					{ cerr << "Blad wczytywania." << endl;
						return false;
					}
			if (dlugoscTab!=dlugoscTab2)
			{ cerr << "Tablice nie sa takiej samej dlugosci." << endl;
				return false;
			}

			for (int i=0; i<dlugoscTab; i++)
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

Tablice::~Tablice() 
{
	delete tablica;
	delete tablica2;
}