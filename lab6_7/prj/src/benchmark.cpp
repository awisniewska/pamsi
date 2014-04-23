/** \file benchmark.cpp
 * \brief Plik zawiera implementacje klasy Benchmark.
 */

#include <iostream>
#include <fstream>
#include <ctime>
#include "benchmark.hh"
#include <sstream>
#include <string>
#include <cstdlib>


using namespace std;

void Benchmark::Calculate(sType type)
{
	switch(type){
	case aarray:
		(*aarrayptr).GetValue(Tmp);
		break;
	case hash:
		(*hashptr)[Tmp];
		break;
	case tree:
		(*treeptr)[Tmp];
		break;
	}

}

double Benchmark::benchmark(int noIteration, sType type, int problemSize)
{
	switch(type)
	{
	case aarray:
		aarrayptr = new Aarray<int>;
		for (int i=0; i<problemSize; i++)
		{
			std::ostringstream ss;
			for (int j = 0; j<5; j++)
			{
				ss << (char)(rand() % 127);
			}
			ss << i;
			if (i == problemSize/2)
			{
				Tmp = ss.str();
			}
			aarrayptr->Add(ss.str(), 0);
		}
		break;
	case hash:
		hashptr = new Hash<int>(problemSize);
		for (int i=0; i<problemSize; i++)
		{
			std::ostringstream ss;
			for (int j = 0; j<5; j++)
			{
				ss << (char)(rand() % 127);
			}
			ss << i;
			if (i == problemSize/2)
			{
				Tmp = ss.str();
			}
			hashptr->Add(ss.str(), 0);
		}
		break;
	case tree:
		treeptr = new Tree<int>;
		for (int i=0; i<problemSize; i++)
		{
			std::ostringstream ss;
			for (int j = 0; j<5; j++)
			{
				ss << (char)(rand() % 127);
			}
			ss << i;
			if (i == problemSize/2)
			{
				Tmp = ss.str();
			}
			treeptr->Add(ss.str(), 0);
		}
		break;
	}
	clock_t t = clock();
	for (int i=0; i<noIteration; i++) {
	Calculate(type);
	}
	t = clock()-t;

	switch(type)
	{
	case aarray:
		delete aarrayptr;
		break;
	case hash:
		delete hashptr;
		break;
	case tree:
		delete treeptr;
		break;
	}
	return ( ((double)t)/CLOCKS_PER_SEC );
}
