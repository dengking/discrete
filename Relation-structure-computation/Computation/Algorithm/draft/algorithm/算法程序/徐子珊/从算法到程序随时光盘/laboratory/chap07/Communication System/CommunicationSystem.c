#include <stdio.h>
#include <assert.h>
#include "../../btrack/combineproblem.h"
int n,*m=NULL,**b=NULL,**p=NULL;
double max,obj;
void Free(int **x){
	int i;
	for(i=0;i<n;i++)
		free(x[i]);
	free(x);
}
ValueSet *newSet(int m){/*创建集合X*/
	int i;
	ValueSet *s=(ValueSet*)malloc(sizeof(ValueSet));
	assert(s!=NULL);
	s->list=createList(sizeof(int),NULL);
	for(i=0;i<m;i++)
		listPushBack(s->list,&i);
	s->current=s->list->nil;
	return s;
}
ValueSet** makeOMG(int n){/*创建Ω*/
	int i;
	ValueSet **OMG=(ValueSet**)malloc(n*sizeof(ValueSet*));
	assert(OMG!=NULL);
	for(i=0;i<n;i++)
		OMG[i]=newSet(m[i]);
	return OMG;
}
int isPartial(int *x, int k){
	return k<n;
}
int isComplete(int *x, int k){
	int minb=INT_MAX,sump=0,i;
	if(k<n-1)
		return 0;
	for(i=0;i<n;i++){
		sump+=p[i][x[i]];
		if(b[i][x[i]]<minb)
			minb=b[i][x[i]];
	}
	obj=(double)minb/sump;
	if(obj<=max)
		return 0;
	max=obj;
	return 1;
}
int main(){
	int i,j,k,t;
	FILE *f1=fopen("chap07/Communication System/inputdata.txt","r"), 
		*f2=fopen("chap07/Communication System/outputdata.txt","w");
	assert(f1&&f2);
	fscanf(f1,"%d",&t);
	for(k=0;k<t;k++){
		ValueSet **OMG;
		LinkedList *s;
		fscanf(f1,"%d",&n);
		m=(int*)calloc(n,sizeof(int));
		b=(int**)calloc(n,sizeof(int*));
		p=(int**)calloc(n,sizeof(int*));
		for(i=0;i<n;i++){
			fscanf(f1,"%d",m+i);
			b[i]=(int*)calloc(m[i],sizeof(int));
			p[i]=(int*)calloc(m[i],sizeof(int));
			for(j=0;j<m[i];j++)
				fscanf(f1,"%d%d",b[i]+j,p[i]+j);
		}
		OMG=makeOMG(n);
		s=backtrackiter(OMG,n);
		fprintf(f2,"%.3f\n",max);
		free(m);Free(b);Free(p);
		clrOMG(OMG,n,NULL);
		clrList(s,clrSolution);free(s);
	}
	fclose(f1);fclose(f2);
	return 0;
}