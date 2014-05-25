/** \file search.cpp
 *
 * \brief Plik zawierający funkcje przeszukujące graf wszerz oraz w głąb.
 */

#include "search.hh"
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(Graph<int>* Ptr, int Start, int End) {
	stack<int> VertToGo;
	map<int, bool> VertVisited;

	VertToGo.push(Start);
	VertVisited.insert(pair<int, bool>(Start, true));

	while (!VertToGo.empty()) {
		int current = VertToGo.top();
		if (current == End) return;
		VertToGo.pop();
		Graph<int>::EdgeS Edge = Ptr->Neighbors(current);

		for (unsigned int i = 0; i<Edge.size(); i++) {
			int tmp = Edge[i].SecEnd;
			if ( VertVisited.count(tmp) == 0 ) {
				VertToGo.push(tmp);
				VertVisited.insert(pair<int, bool>(tmp, true));
			}
		}

	}
}

void BFS(Graph<int>* Ptr, int Start, int End) {

	queue<int> VertToGo;
	map<int, bool> VertVisited;

	VertToGo.push(Start);
	VertVisited.insert(pair<int, bool>(Start, true));

	while (!VertToGo.empty()) {
		int current = VertToGo.front();
		if (current == End) return;
		VertToGo.pop();
		Graph<int>::EdgeS Edge = Ptr->Neighbors(current);

		for (unsigned int i = 0; i<Edge.size(); i++) {
			int tmp = Edge[i].SecEnd;
			if ( VertVisited.count(tmp) == 0 ) {
				VertToGo.push(tmp);
				VertVisited.insert(pair<int, bool>(tmp, true));
			}
		}
	}
}

/** \brief Struktura pomocnicza do użycia przez algorytm A*
 *
 */
struct VertStruct {
	int Value;
	int G, H, F;
	VertStruct(const int initValue, const int initG, const int initH, const int initF): Value(initValue), G(initG), H(initH), F(initF) {}
};

/**\brief Struktura pomocnicza do użycia przez algorytm A*
 *
 */
struct LessF {
	bool operator()(const VertStruct &Vert1, const VertStruct &Vert2) {
		return (Vert1.F > Vert2.F);
	}
};

void AStar(Graph<int>* Ptr, int Start, int End, int Side) {
	int endI = End / Side;
	int endJ = End % Side;

	std::vector<VertStruct> OpenList;
	std::map<int, bool> ClosedList;

	OpenList.push_back(VertStruct(Start, 0, 0, 0));
	push_heap(OpenList.begin(), OpenList.end(), LessF());

	while (!OpenList.empty()) {
		pop_heap(OpenList.begin(), OpenList.end(), LessF());
		VertStruct CurrentLabel = OpenList.back();
		OpenList.pop_back();

		int current = CurrentLabel.Value;

		ClosedList.insert(std::pair<int, bool>(current, true));

		if (current == End) {
			return;
		}

		Graph<int>::EdgeS Edges = Ptr->Neighbors(current);
		for (unsigned int i = 0; i<Edges.size(); i++) {
			int tmp = Edges[i].SecEnd;
			int tmpCost = Edges[i].Weight;
			if ( ClosedList.count(tmp) != 0 ) {
				continue;
			}

			int Find = -1;
			for (unsigned int j = 0; j<OpenList.size(); j++) {
				if (OpenList[j].Value == tmp) {
					Find = j;
					break;
				}
			}

			int newG = CurrentLabel.G + tmpCost;
			if (Find == -1) {

				int currentI = tmp / Side;
				int currentJ = tmp % Side;

				int newH = (abs(endI-currentI) + abs(endJ-currentJ))*100;

				OpenList.push_back(VertStruct(tmp, newG, newH, newG+newH));
				push_heap(OpenList.begin(), OpenList.end(), LessF());
			}
			else {
				if (newG < OpenList[Find].G) {
					OpenList[Find].G = newG;
					OpenList[Find].F = newG + OpenList[Find].H;
				}
			}
		}
	}
}
