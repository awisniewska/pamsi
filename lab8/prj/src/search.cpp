/** \file search.cpp
 *
 * \brief Plik zawierający funkcje przeszukujące graf wszerz oraz w głąb.
 */

#include "search.hh"
#include <map>
#include <queue>
#include <stack>

using namespace std;

void DFS(Graph<int>* Ptr) {
	stack<int> VertToGo;
	map<int, bool> VertVisited;

	VertToGo.push(1);

	while (!VertToGo.empty()) {
		int current = VertToGo.top();
		VertToGo.pop();

		Graph<int>::EdgeS Edge = Ptr->Neighbors(current);

		for (unsigned int i = 0; i<Edge.size(); i++) {
			int tmp = Edge[i].SecEnd;
			if ( VertVisited.count(tmp) == 0 ) {
				VertToGo.push(tmp);
			}
		}

		VertVisited.insert(pair<int, bool>(current, true));
	}
}

void BFS(Graph<int>* Ptr) {

	queue<int> VertToGo;
	map<int, bool> VertVisited;

	VertToGo.push(1);

	while (!VertToGo.empty()) {
		int current = VertToGo.front();
		VertToGo.pop();

		Graph<int>::EdgeS Edge = Ptr->Neighbors(current);

		for (unsigned int i = 0; i<Edge.size(); i++) {
			int tmp = Edge[i].SecEnd;
			if ( VertVisited.count(tmp) == 0 ) {
				VertToGo.push(tmp);
			}
		}

		VertVisited.insert(pair<int, bool>(current, true));
	}
}


