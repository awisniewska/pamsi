/*
 * merge.hh
 * \brief Plik zawiera definicje funkcji sortowania przez scalanie dla klasy Array.
 */

#ifndef MERGE_HH_
#define MERGE_HH_

#include "array.hh"

/* \brief Szablon funkcji tylko do uzytku wewnetrznego. Nie powinna byc uruchamiana osobno.
 *
 */
template <typename type> void mergeSort(Array<type>& arr, Array<type>& tmp, unsigned int start, unsigned int end)
{
  unsigned int split,h1,h2,i;

  split = (start + end + 1) / 2;
  if(split - start > 1) mergeSort(arr, tmp, start, split - 1);
  if(end - split > 0) mergeSort(arr, tmp, split, end);
  h1 = start; h2 = split;
  for(i = start; i <= end; i++)
    tmp[i] = ((h1 == split) || ((h2 <= end) && (arr[h1] > arr[h2]))) ? arr[h2++] : arr[h1++];
  for(i = start; i <= end; i++) arr[i] = tmp[i];
}

/* \brief Szablon funkcji sortowania przez scalanie dla klasy Array.
 * \param value referencja na tablice do posortowania
 *
 */
template <typename type> void mergeSort(Array<type>& value) {
	Array<type> tmp;
	tmp.resize(value.size());
	mergeSort(value, tmp, 0, value.size());
}


#endif /* MERGE_HH_ */
