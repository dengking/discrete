#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "../overlaprectangle.h"
int main(){
	int i,j,n,m;
	FILE *f1=fopen("chap05/TexasTrip/inputdata.txt","r"), 
		*f2=fopen("chap05/TexasTrip/outputdata.txt","w");
	assert(f1&&f2);
	fscanf(f1, "%d", &m);
	for(i=0;i<m;i++){
		double w,h,squaroot2=sqrt(2.0);
		Rectangle r;
		Point *q;
		fscanf(f1, "%d", &n);
		assert(q=(Point*)calloc(n, sizeof(Point)));
		for(j=0;j<n;j++)
			fscanf(f1, "%lf %lf", &(q[j].x),&(q[j].y));
		r=smallestBoundingRectangle(q, n);
		free(q);
		w=r.height>r.width?r.height:r.width;
		h=r.height+r.width-w;
		if(h>(squaroot2-1)*w)
			fprintf(f2,"%.4f\n",w*w);
		else
			fprintf(f2,"%.4f\n",(w+h)*(w+h)/2);
	}
	fclose(f1);fclose(f2);
	return 0;
}