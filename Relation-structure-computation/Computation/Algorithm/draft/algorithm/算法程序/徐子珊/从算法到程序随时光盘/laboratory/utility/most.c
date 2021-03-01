#include <string.h>
#include <stdlib.h>
#include "most.h"
int most(void *a, int n, int size, int(*comp)(void *,void *)){
	void *m=malloc(size);
	int i, k=0;
	memcpy(m,a,size);
	for(i=1;i<n;i++)
		if(comp(((char*)a+i*size),m)>0){
			memcpy(m, ((char*)a+i*size), size);
			k=i;
		}
	free(m);
	return k;
}
