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
		BFS(&benchGraph, rand() % Vertices, rand() % Vertices);
		break;
	case dfs:
		DFS(&benchGraph, rand() % Vertices, rand() % Vertices);
		break;
	case astar:
		AStar(&benchGraph, rand() % Vertices, rand() % Vertices, Side);
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
	Side = VertCount;
	Vertices = VertCount*VertCount;
	Edges = 0;

	for (unsigned int i = 0; i<Vertices; i++) {
		benchGraph.AddVert(i);
	}

	for (unsigned int i = 0; i<Side; i++) {
		for (unsigned int j = 0; j<Side; j++) {
			int currentVert = i*Side+j;
			int rightVert = i*Side+(j+1);
			int bottomVert = (i+1)*Side+j;

			if (j<Side-1) {
				benchGraph.AddEdge(currentVert, rightVert, 100 + (rand() % 101) );
				Edges++;
			}
			if (i<Side-1) {
				benchGraph.AddEdge(currentVert, bottomVert, 100 + (rand() % 101) );
				Edges++;
			}

		}
	}
}


