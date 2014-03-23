/*
 * quicksort.hh
 *
 *  Created on: 20 mar 2014
 *      Author: aga
 */

#ifndef QUICKSORT_HH_
#define QUICKSORT_HH_

#include <array.hh>

template <typename type> void quicksort(Array<type> &d, int left, int right)

{
  int i,j;
  type piwot;

  i = (left + right) / 2;
  piwot = d[i]; d[i] = d[right];
  for(j = i = left; i < right; i++)
  if(d[i] < piwot)
  {
	d.changePlaces(i, j);
    j++;
  }
  d[right] = d[j]; d[j] = piwot;
  if(left < j - 1)  quicksort(d, left, j - 1);
  if(j + 1 < right) quicksort(d, j + 1, right);
}


#endif /* QUICKSORT_HH_ */
