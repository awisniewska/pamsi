#ifndef GRAPH_HH_
#define GRAPH_HH_

/** \file graph.hh
 * Plik zawierający szablon klasy Graph.
 */
#include <vector>
#include <map>

/** \brief class Graph
 *  Jest to klasa definiująca graf nieskierowany z wagą pozwalająca na wykonywaniu wybranych funkcji.
 */
template <typename Type> class Graph {
public:
	struct Edge {
		Type SecEnd;
		int Weight;
		Edge(const Type newEnd, const int newWeight): SecEnd(newEnd), Weight(newWeight) {};
	};
	typedef std::vector<Edge> EdgeS;
private:
	std::map< Type, EdgeS > graph;
public:
/** \brief Funkcja dodająca nowy wierzchołek
 * \param vert wartość dodawanego wierzchołka
 */
	void AddVert(const Type &vert);

/** \brief Funkcja usuwająca wybrany wierzchołek
 * \param vert wartość usuwanego wierzchołka
 */
	void RemoveVert(const Type &vert);

/** \brief Funkcja dodająca nową krawędź
 * \param vert1 współrzędna pierwszego wierzchołka
 * \param vert2 współrzędna drugiego wierzchołka
 * \param Weight waga krawędzi
 */
	void AddEdge(const Type &vert1, const Type &vert2, const int Weight = 0);

/** \brief Funkcja usuwająca daną krawędź
 * \param vert1 współrzędna pierwszego wierzchołka
 * \param vert2 współrzędna drugiego wierzchołka
 */
	void RemoveEdge(const Type &vert1, const Type &vert2);

/** \brief Funkcja sprawdzająca, czy wierzchołki są ze sobą bezpośrednio połączone
 * \param vert1 współrzędna pierwszego wierzchołka
 * \param vert2 współrzędna drugiego wierzchołka
 * \return true jeśli wierzchołki są połączone
 * \return false jeśli wierzchołki nie są połączone
 */
	bool IfConnected(const Type &vert1, const Type &vert2);

/** \brief Funkcja znajdująca sąsiednie wierzchołki
 * \param vert wierzchołek, którego sąsiadów poszukujemy
 * \return wektor wierzchołków sąsiadujących
 */
	EdgeS Neighbors(const Type &vert);
};

template<typename Type>
void Graph<Type>::AddVert(const Type& vert) {
	graph.insert(std::pair< Type, EdgeS>(vert, std::vector<Edge>() ) );
}

template<typename Type>
void Graph<Type>::RemoveVert(const Type& vert) {
	EdgeS *tmp = &graph[vert];
	for (typename EdgeS::iterator it = tmp->begin(); it != tmp->end(); it++) {
		RemoveEdge(vert, (*it).SecEnd);
	}
	graph.erase(vert);
}

template<typename Type>
void Graph<Type>::AddEdge(const Type& vert1,
		const Type& vert2, const int Weight) {
	graph[vert1].push_back(Edge(vert2, Weight));
	graph[vert2].push_back(Edge(vert1, Weight));
}

template<typename Type>
void Graph<Type>::RemoveEdge(const Type& vert1,
		const Type& vert2) {
	EdgeS *tmp1 = &graph[vert1];
	EdgeS *tmp2 = &graph[vert2];
	for (typename EdgeS::iterator it = tmp1->begin(); it != tmp1->end(); it++) {
		if ((*it).SecEnd == vert2) {
			tmp1->erase(it);
			break;
		}
	}
	for (typename EdgeS::iterator it = tmp2->begin(); it != tmp2->end(); it++) {
		if ((*it).SecEnd == vert1) {
			tmp2->erase(it);
			break;
		}
	}
}

template<typename Type>
bool Graph<Type>::IfConnected(const Type& vert1,
		const Type& vert2) {
	EdgeS *tmp = &graph[vert1];
	for (typename EdgeS::iterator it = tmp->begin(); it != tmp->end(); it++) {
		if ((*it).SecEnd == vert2) {
			return true;
		}
	}
	return false;
}

template<typename Type>
typename Graph<Type>::EdgeS Graph<Type>::Neighbors(
		const Type& vert) {
	return graph[vert];
}

#endif /* GRAPH_HH_ */
