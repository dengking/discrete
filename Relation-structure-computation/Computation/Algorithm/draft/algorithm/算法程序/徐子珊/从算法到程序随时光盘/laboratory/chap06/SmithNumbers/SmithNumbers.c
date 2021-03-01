#include <stdio.h>
#include <assert.h>
#include "../../utility/compare.h"
#include "../../numbertheory/factor.h"
#include "../../numbertheory/primetest.h"
int s2;
int sumdigit(unsigned long n){
	int s=0,m=n;
	do{
		s+=m%10;
		m/=10;
	}while(m);
	return s;
}
void sumdigits(unsigned long *a){
	s2+=sumdigit(*a);
}
int main(){
	int a;
	FILE *f1=fopen("chap06/SmithNumbers/inputdata.txt","r"), 
		*f2=fopen("chap06/SmithNumbers/outputdata.txt","w");
	assert(f1&&f2);
	fscanf(f1,"%d", &a);
	while(a){
		unsigned long s1,b=a;
		while(1){
			RBTree *factors=creatRBTree(sizeof(unsigned long),unsignedGreater);
			if(isPrime(b)){
				b++;
				continue;
			}
			s1=sumdigit(b);
			s2=0;
			factor(b,factors);
			inorderRBWalk(factors,sumdigits);clrRBTree(factors,NULL);
			if(s1==s2){
				fprintf(f2,"%d\n",b);
				break;
			}
			b++;
		}
		fscanf(f1,"%d",&a);
	}
	fclose(f1);fclose(f2);
	return 0;
}