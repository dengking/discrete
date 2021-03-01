#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "../overlaprectangle.h"
int main(){
	int i,n;
	FILE *f1=fopen("chap05/SmallestBoundingRectangle/inputdata.txt","r"), 
		*f2=fopen("chap05/SmallestBoundingRectangle/outputdata.txt","w");
	assert(f1&&f2);
	fscanf(f1, "%d", &n);
	while(n){
		Rectangle r;
		Point *q;
		assert(q=(Point*)calloc(n, sizeof(Point)));
		for(i=0;i<n;i++)
			fscanf(f1, "%lf %lf", &(q[i].x),&(q[i].y));
		r=smallestBoundingRectangle(q, n);
		free(q);
		fprintf(f2,"%.4f\n",r.width*r.height);
		fscanf(f1, "%d", &n);
	}
	fclose(f1);fclose(f2);
	return 0;
}