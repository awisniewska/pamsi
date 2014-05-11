/*
 * graph.hh
 *
 *  Created on: 8 maj 2014
 *      Author: aga
 */

#ifndef GRAPH_HH_
#define GRAPH_HH_

#include <vector>
template<typename type>class Graph {
	std::vector<type> VertVec;
	struct Edge {
		type Start;
		type End;
		int Weight;
	};
	std::vector<Edge> EdgeVec;
public:
/** \brief Funkcja dodająca nowy wierzchołek
 * \param Vert wartość dodawanego wierzchołka
 */
	void AddVert(type Vert);

/** \brief Funkcja dodająca nową krawędź
 * \param Start współrzędna pierwszego wierzchołka
 * \param End współrzędna drugiego wierzchołka
 * \param Weight waga krawędzi
 */
	void AddEdge(type Start, type End, int Weight);

/** \brief Funkcja usuwająca wybrany wierzchołek
 * \param Vert wartość usuwanego wierzchołka
 */
	void RemoveVert(type Vert);

/** \brief Funkcja usuwająca daną krawędź
 * \param Start współrzędna pierwszego wierzchołka
 * \param End współrzędna drugiego wierzchołka
 */
	void RemoveEdge(type Start, type End);


/** \brief Funkcja sprawdzająca, czy wierzchołki są ze sobą bezpośrednio połączone
 * \param Start współrzędna pierwszego wierzchołka
 * \param End współrzędna drugiego wierzchołka
 * \return true jeśli wierzchołki są połączone
 * \return false jeśli wierzchołki nie są połączone
 */
	bool IfConnected(type Start, type End);

/** \brief Funkcja znajdująca sąsiednie wierzchołki
 * \param Vert wierzchołek, którego sąsiadów poszukujemy
 * \return wektor wierzchołków sąsiadujących
 */
	std::vector<type> Neighbors(type Vert);
};

template<typename type>
 void Graph<type>::AddVert(type Vert) {
}

template<typename type>
 void Graph<type>::AddEdge(type Start, type End, int Weight) {
}

template<typename type>
 void Graph<type>::RemoveVert(type Vert) {
}

template<typename type>
 void Graph<type>::RemoveEdge(type Start, type End) {
}

template<typename type>
 bool Graph<type>::IfConnected(type Start, type End) {
}

template<typename type>
 std::vector<type> Graph<type>::Neighbors(type Vert) {
}

#endif /* GRAPH_HH_ */
