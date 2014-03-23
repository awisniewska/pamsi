/** \file benchmark.cpp
 * \brief Plik zawiera implementacje klasy Benchmark.
 */

#include <iostream>
#include <fstream>
#include <ctime>
#include "benchmark.hh"
#include "merge.hh"
#include "quicksort.hh"
#include "heap.hh"


using namespace std;

bool Benchmark::load(char *fileName)
{
	ifstream inFile(fileName);

		if (!inFile.good())
		{ cerr << "Wybrano nieprawidlowy plik wejsciowy." << endl;
			return false;
		}

		unsigned int arrLength;
		inFile >> arrLength;

		if (!inFile.good())
				{ cerr << "Blad wczytywania." << endl;
					return false;
				}

		array1.resize(arrLength);
		array2.resize(arrLength);

		for (unsigned int i=0; i<arrLength; i++)
		{
			inFile >> array1[i];
			if (!inFile.good())
					{ cerr << "Blad wczytywania." << endl;
						return false;
					}
		}
		return true;
}

void Benchmark::calculate(sortingType type)
{
array2=array1;
switch (type) {
case quick:
	quicksort(array2);
	break;
case merge:
	mergeSort(array2);
	break;
case heap:
	heapSort(array2);
	break;
}
}

bool Benchmark::check(char *fileName)
{
	ifstream checkFile(fileName);

			if (!checkFile.good())
			{ cerr << "Wybrano nieprawidlowy plik sprawdzajacy." << endl;
				return false;
			}

			unsigned int arr2Length;
			checkFile >> arr2Length;
			if (!checkFile.good())
					{ cerr << "Blad wczytywania." << endl;
						return false;
					}
			if (array2.size()!=arr2Length)
			{ cerr << "Tablice nie sa takiej samej dlugosci." << endl;
				return false;
			}

			for (unsigned int i=0; i<array2.size(); i++)
			{
				int tmp;
				checkFile >> tmp;
				if (!checkFile.good())
						{ cerr << "Blad wczytywania." << endl;
							return false;
						}
				if (tmp!=array2[i])
				{ cerr << "Porownywane wartosci elementu nr " << i+1 << " nie sa takie same" << endl;
					return false;
				}
			}
			return true;
}

double Benchmark::benchmark(int noIteration, sortingType type)
{

	clock_t t = clock();
	for (int i=0; i<noIteration; i++) {
	calculate(type);
	}
	t = clock()-t;

	return ( ((double)t)/CLOCKS_PER_SEC );
}

