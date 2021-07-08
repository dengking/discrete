#include "search.h"
int linearSearch(void* a, int size, int n, void* x, int(*comp)(void*, void*)){
	int i = 0;
	while (i<n){
		if (comp((char*)a + i*size, x) == 0)/*找到关键值为x的元素，其下标为i*/
			return i;
		i++;
	}
	return -1;
}
int binSearch(void *a, int size, int n, void *x, int(*comp)(void*, void*)){
	int p = 0, r = n - 1, q, c;
	while (p <= r){
		q = (p + r) / 2;
		c = comp(x, (char*)a + q*size);
		if (c == 0)
			return q;
		if (c>0)
			p = q + 1;
		if (c<0)
			r = q - 1;
	}
	return -1;
}