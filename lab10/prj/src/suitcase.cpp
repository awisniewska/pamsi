/** \file suitcase.cpp
 * Plik zawierający implementacje funkcji klasy Suitcase.
 */

#include "suitcase.hh"
//#include <cstdlib>
#include <algorithm>

Suitcase::Suitcase(int iWeightLimit) {
	WeightLimit=iWeightLimit;
	ActWeight=0;
	ActValue=0;
}

bool Suitcase::PutIn(const Item item) {
	if(item.GetWeight()<=WeightLeft())
	{
		push_back(item);
		ActWeight=ActWeight+item.GetWeight();
		ActValue=ActValue+item.GetValue();
		return true;
	}
	else return false;
}

int Suitcase::WeightLeft() {
	return WeightLimit-ActWeight;
}

void Suitcase::Clear() {
	ActWeight=0;
	ActValue=0;
	clear();
}

int Suitcase::Worth() {
	return ActValue;
}

bool CompareByValue(Item item1, Item item2){
	return (item1.GetValuePerWeigt() > item2.GetValuePerWeigt());
}

void Knapsack(Itemlist* item, Suitcase* suitcase) {
	Itemlist temp(*item);
	std::sort(temp.begin(), temp.end(), CompareByValue);
	for(unsigned int i=0; i<temp.size(); i++){
		suitcase->PutIn(temp[i]);
	}
}
