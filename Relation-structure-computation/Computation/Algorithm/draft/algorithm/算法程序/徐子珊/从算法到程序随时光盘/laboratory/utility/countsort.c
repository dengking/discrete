#include <stdlib.h>
void countSort(unsigned *a,int n){
	unsigned *b=(unsigned *)malloc((n)*sizeof(unsigned)),*c,k=a[0];
	int i;
	for(i=1;i<n;i++)
		if(a[i]>k)
			k=a[i];
	c=(unsigned *)malloc((k+1)*sizeof(unsigned));
	for(i=0;i<=k;i++)
		c[i]=0;
	for(i=0;i<n;i++)
		c[a[i]]++;
	for(i=1;i<=k;i++)
		c[i]=c[i-1]+c[i];
	for(i=n-1;i>-1;i--){
		b[c[a[i]]-1]=a[i];
		c[a[i]]--;
	}
	memcpy(a,b,n*sizeof(unsigned));
	free(b);free(c);
}
