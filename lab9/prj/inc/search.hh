/** \file search.hh
 *
 * \brief Plik zawierający definicje funkcji przeszukujących grafy.
 */

#ifndef SEARCH_HH_
#define SEARCH_HH_

#include "graph.hh"

/** \brief Przeszukiwanie grafu w głąb
 * \param Ptr wskaźnik na przeszukiwany graf
 * \param Start wierzchołek początkowy
 * \param End wierzchołek końcowy
 */
void DFS(Graph<int> *Ptr, int Start, int End);

/** \brief Przeszukiwanie grafu wszerz
 * \param Ptr wskaźnik na przeszukiwany graf
 * \param Start wierzchołek początkowy
 * \param End wierzchołek końcowy
 */
void BFS(Graph<int> *Ptr, int Start, int end);

/** \brief Wyszukiwanie najkrótszej ścieżki - A*
 * \param Ptr wskaźnik na przeszukiwany graf
 * \param Side liczba wierzchołków przypadająca na bok planszy
 * \param Start wierzchołek początkowy
 * \param End wierzchołek końcowy
 */
void AStar(Graph<int> *Ptr, int Start, int End, int Side);



#endif /* SEARCH_HH_ */
