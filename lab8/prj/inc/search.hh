/** \file search.hh
 *
 * \brief Plik zawierający definicje funkcji przeszukujących grafy.
 */

#ifndef SEARCH_HH_
#define SEARCH_HH_

#include "graph.hh"

/** \brief Przeszukiwanie grafu w głąb
 * \param Ptr wskaźnik na przeszukiwany graf
 */
void DFS(Graph<int> *Ptr);

/** \brief Przeszukiwanie grafu wszerz
 * \param Ptr wskaźnik na przeszukiwany graf
 */
void BFS(Graph<int> *Ptr);



#endif /* SEARCH_HH_ */
