/** \file main.cpp
 * Plik zawierający główną funkcję programu.
 */

#include "itemlist.hh"
#include "suitcase.hh"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv) {

	if (argc < 3 )
		{ cerr << "Zbyt mala ilosc argumentow." << endl;
			return 0;
		}
Itemlist TestObj;
TestObj.Load(argv[1]);
//TestObj.Show();
Suitcase MySuitcase(atoi(argv[2]));
Knapsack(&TestObj, &MySuitcase);
MySuitcase.Show();
std::cout << MySuitcase.Worth() << std::endl;
std::cout << MySuitcase.WeightLeft() << std::endl;
}
