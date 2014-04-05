/** \file main.cpp
 *
 * \brief Plik zawierający główną funkcję programu.
 */


#include "aarray.hh"
#include <iostream>

using namespace std;


/** \brief Główna funkcja programu
 *
 *  Obecnie służy wyłącznie do testów.
 */
int main(){
	Aarray<int> Array;
	Array.Add(4, "kot");
	Array.Add(2, "kura");
	Array.Add(0, "ryba");
	Array.Add(8, "osmiornica");
	Array.Add(4, "pies");
	cout << "Zwierzak ma: " << Array.GetValue("kura") << " nog" << endl;
Array.ChangeValue(6, "kura");
cout << "Zwierzak ma: " << Array.GetValue("kura") << " nog" << endl;
}



