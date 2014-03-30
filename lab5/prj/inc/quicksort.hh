/*
 * quicksort.hh
 * \brief Plik zawiera definicje szablonu sortowania szybkiego dla klasy Array.
 */

#ifndef QUICKSORT_HH_
#define QUICKSORT_HH_

#include <array.hh>
#include <cstdlib>

/* \brief Szablon funkcji tylko do uzytku wewnetrznego. Nie powinna byc uruchamiana osobno.
 *
 */
template <typename type> void quicksort(Array<type> &d, unsigned int left, unsigned int right)

{

	if (right>left)
	{return 0;}

  int i,j;
  type tmp;

  i = rand()%(right-left)+left;
  tmp = d[i]; d[i] = d[right];
  for(j = i = left; i < right; i++)
  if(d[i] < tmp)
  {
	d.changePlaces(i, j);
    j++;
  }
  d[right] = d[j]; d[j] = tmp;
  if(left < j - 1)  quicksort(d, left, j - 1);
  if(j + 1 < right) quicksort(d, j + 1, right);

}


/* \brief Szablon funkcji sortowania szybkiego dla klasy Array.
 * \param value referencja na tablice do posortowania
 *
 */
template<typename type> void quicksort(Array<type> &value)
{
	quicksort(value,0,value.size()-1);
}


#endif /* QUICKSORT_HH_ */
