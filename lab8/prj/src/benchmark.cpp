/** \file benchmark.cpp
 *
 * \brief Plik zawierający funkcję mierzącą czas wykonywania algorytmu.
 */

#include <ctime>
#include "search.hh"
#include "benchmark.hh"
#include <cstdlib>


void Benchmark::calculate(Implementation Type) {
	switch(Type){
	case bfs:
		BFS(&benchGraph);
		break;
	case dfs:
		DFS(&benchGraph);
		break;
	}
}

double Benchmark::benchmark(int noIteration, Implementation Type) {
	clock_t t = clock();
	for (int i=0; i<noIteration; i++) {
		calculate(Type);
	}
	t = clock()-t;

	return ( ((double)t)/CLOCKS_PER_SEC );
}

void Benchmark::SampleGraph(const unsigned int VertCount) {

	if (VertCount < 1) return;
	Edges = 0;
	for (unsigned int i = 1; i<VertCount; i++) {
		benchGraph.AddVert(i);
	}
	for (unsigned int i = 1; i<VertCount+1; i++) {
		for (unsigned int j = 0; j<3; j++) {
			while (true) {
				unsigned int tmp = (rand() % VertCount) + 1;
				if (tmp == i) continue;
				else if (benchGraph.IfConnected(tmp, i)) continue;
				else {
					benchGraph.AddEdge(i, tmp);
					Edges++;
					break;
				}
			}
		}
	}

}


