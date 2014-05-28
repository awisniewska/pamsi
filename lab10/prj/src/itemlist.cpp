/** \file itemlist.cpp
 * Plik zawierający implementacje funkcji klasy Itemlist.
 */

#include "itemlist.hh"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

bool Itemlist::Load(char* FileName) {
	ifstream Loading;
	Loading.open(FileName);
	if(!Loading.good()){
		return false;
	}
	string tmpName;
	int tmpWeight;
	int tmpValue;
	while(1){
		Loading >> tmpName;
		Loading >> tmpWeight;
		Loading >> tmpValue;
		if(!Loading.good()){
			break;
		}
		push_back(Item(tmpName, tmpWeight, tmpValue));
	}
	return true;
}

void Itemlist::Show() {
	for(unsigned int i=0; i<size(); i++){
		cout << (*this)[i].GetName() << ": " << (*this)[i].GetWeight() << " g, "
				<< (*this)[i].GetValue() << " zł" << endl;
	}
}
