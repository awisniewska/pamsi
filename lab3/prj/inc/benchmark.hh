/** \file benchmark.hh
 * \brief Plik zawiera deklaracje zwiazane z szablonem klas BenchStack i BenchQueue.
 */

#ifndef BENCHMARK_HH_
#define BENCHMARK_HH_

#include <ctime>
#include "stack.hh"
#include "stack2.hh"
#include "stOnList.hh"
#include "queue.hh"

/** \brief Szablon klasy BenchStack
 *
 * Definiuje funkcje sluzace do pomiaru czasu wykonywania algorytmu na stosie.
 * \tparam stackClass klasa stosu dla ktorej przeprowadzamy benchmark
 */
template <class stackClass> class BenchStack
{
public:
/** \brief Mierzy czas trwania algorytmu wykonywanego na stosie dla zadanej ilosci powtorzen oraz rozmiaru problemu
 *
 * \param noIteration liczba powtorzen wykonania algorytmu
 * \param problemSize liczba danych wrzucanych na stos podczas jednej iteracji algorytmu
 * \return czas wykonywania algorytmu
 */
	double benchmark(unsigned int noIteration, unsigned int problemSize);
};

/** \brief Szablon klasy BenchQueue
 *
 * Definiuje funkcje sluzace do pomiaru czasu wykonywania algorytmu na kolejce.
 * \tparam queueClass klasa kolejki dla ktorej przeprowadzamy benchmark
 */
template <class queueClass> class BenchQueue
{
public:
/** \brief Mierzy czas trwania algorytmu wykonywanego na kolejce dla zadanej ilosci powtorzen oraz rozmiaru problemu
 *
 * \param noIteration liczba powtorzen wykonania algorytmu
 * \param problemSize liczba danych dodawanych do kolejki podczas jednej iteracji algorytmu
 * \return czas wykonywania algorytmu
 */
	double benchmark(unsigned int noIteration, unsigned int problemSize);
};


template<class stackClass>
double BenchStack<stackClass>::benchmark(unsigned int noIteration,
		unsigned int problemSize)
{

	clock_t t = clock();
	for (int a=0; a<noIteration; a++) {
	stackClass stos;
		for (int b=0; b<problemSize; b++)
		{
			stos.push(b);
		}
	}
	t = clock()-t;

	return ( ((double)t)/CLOCKS_PER_SEC );

}

template<class queueClass>
double BenchQueue<queueClass>::benchmark(unsigned int noIteration,
		unsigned int problemSize)
{
	clock_t t = clock();
	for (int a=0; a<noIteration; a++) {
	queueClass queue;
		for (int b=0; b<problemSize; b++)
		{
			queue.enqueue(b);
		}
	}
	t = clock()-t;

	return ( ((double)t)/CLOCKS_PER_SEC );

}

#endif /* BENCHMARK_HH_ */
