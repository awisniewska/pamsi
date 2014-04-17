/** \file main.cpp
 *
 * \brief Plik zawierający główną funkcję programu.
 */


#include "tree.hh"
#include <iostream>

using namespace std;


/** \brief Główna funkcja programu
 *
 *  Obecnie służy wyłącznie do testów.
 */
int main(){
	Tree<int> Sample;
	Sample.Add("a", 2);
	Sample.Add("b", 8);
	Sample.Add("g", 4);
	Sample.Add("d", 10);
cout << Sample[string ("a")] << endl;

}


