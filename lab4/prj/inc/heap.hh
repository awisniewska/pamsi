/*
 * heap.hh
 *  \brief Plik zawiera definicje szablonu sortowania przez kopcowanie dla klasy Array.
 */

#ifndef HEAP_HH_
#define HEAP_HH_

/* \brief Szablon funkcji sortowania przez kopcowania dla klasy Array.
 * \param value referencja na tablice do posortowania
 */
template<typename type> void heapSort(Array<type>& value)
{
		type tmp;
	    unsigned int n = value.size(), parent = value.size()/2, index, child;
	    while (1) {
	        if (parent > 0) {

	            tmp = value[--parent];
	        } else {

	            n--;
	            if (n == 0) {
	                return;
	            }
	            tmp = value[n];
	            value[n] = value[0];
	        }

	        index = parent;
	        child = index * 2 + 1;
	        while (child < n) {

	            if (child + 1 < n  &&  value[child + 1] > value[child]) {
	                child++;
	            }

	            if (value[child] > tmp) {
	                value[index] = value[child];
	                index = child;
	                child = index * 2 + 1;
	            } else {
	                break;
	            }
	        }

	        value[index] = tmp;
	    }
}


#endif /* HEAP_HH_ */
