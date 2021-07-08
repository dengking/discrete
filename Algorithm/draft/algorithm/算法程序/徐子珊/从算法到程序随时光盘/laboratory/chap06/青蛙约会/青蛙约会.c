#include <stdio.h>
#include "../../numbertheory/lequation.h"
#include "../../numbertheory/gcd.h"
#include  <assert.h>
int main(){
	long long x=1, y=2, m=3, n=4, L=5, min,a, b, d;
	LinkedList *s;
	ListNode *p;
	FILE *f1=fopen("chap06/青蛙约会/inputdata.txt","r"), 
		*f2=fopen("chap06/青蛙约会/outputdata.txt","w");
	assert(f1&&f2);
	fscanf(f1, "%d %d %d %d %d", &x, &y, &m, &n, &L);
	a=mod(m-n,L);b=mod(y-x,L);d=gcd(a, L);
	if(b%d){
		fprintf(f2, "Impossible\n");
		return 0;
	}
	s=modularLinearEquationSolver(a,b,L);
	min=LONG_MAX;
	p=s->nil->next;
	while(p!=s->nil){
		if(min>*(long long*)(p->key))
			min=*(long long*)(p->key);
		p=p->next;
	}
	fprintf(f2, "%d ",min);
	fputc('\n', f2);
	fclose(f1);fclose(f2);
	return 0;
}