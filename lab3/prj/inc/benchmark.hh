#ifndef BENCHMARK_HH_
#define BENCHMARK_HH_

#include <ctime>
#include "stos.hh"
#include "stos2.hh"
#include "snal.hh"
#include "kolejka.hh"

template <class klasaStosu> class BenchStosu
{
public:
	double benchmark(unsigned int iloscPowtorzen, unsigned int rozmiarProblemu);
};

template <class klasaKolejki> class BenchKolejki
{
public:
	double benchmark(unsigned int iloscPowtorzen, unsigned int rozmiarProblemu);
};

template<class klasaStosu>
double BenchStosu<klasaStosu>::benchmark(unsigned int iloscPowtorzen,
		unsigned int rozmiarProblemu)
{

	clock_t t = clock();
	for (int a=0; a<iloscPowtorzen; a++) {
	klasaStosu stos;
		for (int b=0; b<rozmiarProblemu; b++)
		{
			stos.push(b);
		}
	}
	t = clock()-t;

	return ( ((double)t)/CLOCKS_PER_SEC );

}

template<class klasaKolejki>
double BenchKolejki<klasaKolejki>::benchmark(unsigned int iloscPowtorzen,
		unsigned int rozmiarProblemu)
{
	clock_t t = clock();
	for (int a=0; a<iloscPowtorzen; a++) {
	klasaKolejki kolejka;
		for (int b=0; b<rozmiarProblemu; b++)
		{
			kolejka.enqueue(b);
		}
	}
	t = clock()-t;

	return ( ((double)t)/CLOCKS_PER_SEC );

}

#endif /* BENCHMARK_HH_ */
