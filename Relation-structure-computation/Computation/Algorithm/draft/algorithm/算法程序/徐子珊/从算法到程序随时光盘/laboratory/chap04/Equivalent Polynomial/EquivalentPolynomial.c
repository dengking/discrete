#include "../../algebra/poly.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
Poly tyler(Poly f, double t){
	int k,n=f.degree;
	Poly f1=newPolyByArry(f.coeff,n+1), tf={NULL,-1},g=newPoly(n+1);
	double factor=1.0;
	for(k=0;k<=n;k++){
		if(k!=0)
			factor*=k;
		g.coeff[k]=horner(f1,t)/factor;
		polyAssign(&tf,f1);clrPoly(f1);
		f1=derivative(tf);
	}
	clrPoly(f1);clrPoly(tf);
	return g;
}
int main(void){
	double  t;
	Poly f={NULL,-1},b={NULL,-1};
	int k,n;
	FILE *f1=fopen("chap04/Equivalent Polynomial/inputdata.txt","r"), 
		*f2=fopen("chap04/Equivalent Polynomial/outputdata.txt","w");
	assert(f1&&f2);
	while(!feof(f1)){
		fscanf(f1,"%d%lf",&n,&t);
		if(f.coeff)
			free(f.coeff);
		f=newPoly(n+1);
		for(k=0;k<=n;k++)
			fscanf(f1, "%lf",f.coeff+k);
		if(b.coeff)clrPoly(b);
		b=tyler(f,t);
		for(k=0;k<=n;k++)
			fprintf(f2, "%.0f ",b.coeff[k]);
		fputc('\n',f2);
	}
	clrPoly(f);clrPoly(b);
	fclose(f1);fclose(f2);
	return 0;
}