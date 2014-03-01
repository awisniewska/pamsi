#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv) {

	if (argc < 3 )
	{ cerr << "Zbyt mala ilosc argumentow." << endl;
		return 0;
	}
	ifstream plikWej(argv[1]);

	if (!plikWej.good())
	{ cerr << "Wybrano nieprawidlowy plik wejsciowy." << endl;
		return 0;
	}

	int dlugoscTab;
	plikWej >> dlugoscTab;

	int *tablica = new int[dlugoscTab];

	for (int i=0; i<dlugoscTab; i++)
	{
		plikWej >> tablica[i];
	}

	clock_t t = clock();
	for (int i=0; i<dlugoscTab; i++)
	{
		tablica[i] = tablica[i]*2;
	}

	t = clock()-t;

	ifstream plikSprawdz(argv[2]);

		if (!plikSprawdz.good())
		{ cerr << "Wybrano nieprawidlowy plik sprawdzajacy." << endl;
			return 0;
		}

		int dlugoscTab2;
		plikSprawdz >> dlugoscTab2;

		if (dlugoscTab!=dlugoscTab2)
		{ cerr << "Tablice nie sa takiej samej dlugosci." << endl;
			return 0;
		}

		for (int i=0; i<dlugoscTab; i++)
		{
			int tmp;
			plikSprawdz >> tmp;
			if (tmp!=tablica[i])
			{ cerr << "Porownywane wartosci elementu nr " << i+1 << " nie sa takie same" << endl;
				return 0;
			}
		}

	cout << t << " " << ((double)t)/CLOCKS_PER_SEC << endl;
}
