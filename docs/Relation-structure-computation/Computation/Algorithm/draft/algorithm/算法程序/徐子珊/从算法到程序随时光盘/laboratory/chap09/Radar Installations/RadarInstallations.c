#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "../../greedy/actsel.h"
int main(){
	FILE *f1=fopen("chap09/Radar Installations/inputdata.txt","r"),
		*f2=fopen("chap09/Radar Installations/outputdata.txt","w");
	int n,d,count=0;
	assert(f1&&f2);
	fscanf(f1,"%d%d",&n,&d);
	while(n&&d){
		int i,*s,min=0;
		double x, y, z;
		Active *a=(Active*)malloc(n*sizeof(Active));
		for(i=0;i<n;i++){
			fscanf(f1,"%lf%lf",&x, &y);
			z=sqrt(d*d-y*y);
			a[i].s=x-z;
			a[i].f=x+z;
		}
		s=greedyActivitySelector(a,n);
		for(i=0;i<n;i++)
			min+=s[i];
		fprintf(f2,"Case %d:%d\n",++count,min);
		free(a);free(s);
		fscanf(f1,"%d%d",&n,&d);
	}
	fclose(f1);fclose(f2);
	return 0;
}