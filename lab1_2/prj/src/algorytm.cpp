/** \file algorytm.cpp
 * \brief Plik zawiera implementacje klasy Algorytm.
 */

#include <iostream>
#include <fstream>
#include <algorytm.hh>
#include <ctime>

using namespace std;

bool Algorytm::wczytaj(char *nazwaPliku)
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
		
		tablica.zmienRozmiar(dlugoscTab);
		tablica2.zmienRozmiar(dlugoscTab);

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

void Algorytm::oblicz()
{
	for (unsigned int i=0; i<tablica.rozmiar(); i++)
		{
			tablica2[i] = tablica[i]*2;
		}
}

bool Algorytm::sprawdz(char *nazwaPliku)
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
			if (tablica2.rozmiar()!=dlugoscTab2)
			{ cerr << "Tablice nie sa takiej samej dlugosci." << endl;
				return false;
			}

			for (unsigned int i=0; i<tablica2.rozmiar(); i++)
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

double Algorytm::benchmark(int liczbaPowtorzen)
{
	
	clock_t t = clock();
	for (int i=0; i<liczbaPowtorzen; i++) {
	oblicz();
	}
	t = clock()-t;
	
	return ( ((double)t)/CLOCKS_PER_SEC );
}
