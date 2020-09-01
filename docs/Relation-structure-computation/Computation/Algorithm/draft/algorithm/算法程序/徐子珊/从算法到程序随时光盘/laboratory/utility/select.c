#include "select.h"
void* select(void* a, int size, int p, int r,int i,int(*comp)(void *,void *)){
	int q, k;
	if(p==r)
		return (char*)a+p*size;
	q=randmizedPartition(a,size,p,r,comp);
	k=q-p;
	if(k==i)
		return (char*)a+q*size;
	if(i<k)
		return select(a,size,p,q-1,i,comp);
	return select(a,size,q+1,r,i-k-1,comp);
}
