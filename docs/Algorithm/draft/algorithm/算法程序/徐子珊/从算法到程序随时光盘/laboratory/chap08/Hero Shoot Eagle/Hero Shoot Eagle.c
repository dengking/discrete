#include <assert.h>
#include <string.h>
#include<stdio.h>
#include "../../utility/compare.h"
#include "../../dprog/lcs.h"
#include "../../utility/strstream.h"
#include "../../utility/quicksort.h"
int heroShootEagle(int *a, int n){
	int *b=(int*)malloc(n*sizeof(int)),*c,x;
	assert(b);
	memcpy(b,a,n*sizeof(int));
	quickSort(b,sizeof(int),0,n-1,intLess);
	c=lcsLength(b,a,sizeof(n),n,n,intLess);
	x=c[n*(n+1)+n];
	printLcs(c,n,b,a,sizeof(int),n,n,intLess,putInt);
	free(b);free(c);
	return x;
}
int main(){
	FILE *f1=fopen("chap04/Hero Shoot Eagle/inputdata.txt","r"),
		*f2=fopen("chap04/Hero Shoot Eagle/outputdata.txt","w");
	int n,*a,i;
	assert(f1&&f2);
	initStrOutputStream(&ssout,500);
	while(!feof(f1)){
		fscanf(f1,"%d",&n);
		a=(int*)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
			fscanf(f1, "%d", a+i);
		fprintf(f2,"%d\n",heroShootEagle(a,n));
		free(a);
		fputs(ssout.begin,f2);
		fputc('\n',f2);
		sosRewind(&ssout);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}