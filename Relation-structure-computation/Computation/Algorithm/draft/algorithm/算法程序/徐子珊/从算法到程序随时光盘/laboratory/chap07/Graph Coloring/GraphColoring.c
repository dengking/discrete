#include "../../btrack/combineproblem.h"
#include <assert.h>
#include <stdio.h>
int *G,
	n,
	max=0,
	obj;
int isPartial(int* x, int k){/*部分合法判断*/
	int i;
	for(i=0,obj=0;i<k;i++){
		obj+=x[i];
		if(G[i*n+k]&&x[i]==1&&x[k]==1)
			return 0;
	}
	if(obj+n-k<=max)
		return 0;
	return 1;
}
int isComplete(int* x, int k){/*完整合法解判断*/
	int i;
	if(k<n-1)
		return 0;
	max=obj;
	return 1;
}
void oneCase(FILE *f1, FILE *f2){
	int i, j, t, m;
	LinkedList *s;
	fscanf(f1,"%d%d",&n, &m);
	G=(int*)calloc(n*n,sizeof(int));
	assert(G);
	for(t=0;t<m;t++){
		fscanf(f1,"%d%d",&i,&j);
		G[(i-1)*n+j-1]=1;
		G[(j-1)*n+i-1]=1;
	}
	s=subSetTree(n);
	if(!listEmpty(s)){
		ListNode *p=s->nil->prev;
		Solution *ss=p->key;
		int *x=(int*)(ss->x);
		for(t=0,i=0;i<n;i++)
			t+=x[i];
		fprintf(f2,"%d\n",t);
		for(i=0;i<n;i++)
			if(x[i])
				fprintf(f2,"%d ",i+1);
		fputc('\n',f2);
		clrList(s,clrSolution);
	}
	free(s);free(G);
}
int main(){
	int i,c;
	FILE *f1=fopen("chap07/Graph Coloring/inputdata.txt","r"), 
		*f2=fopen("chap07/Graph Coloring/outputdata.txt","w");
	assert(f1&&f2);
	fscanf(f1,"%d",&c);
	for(i=0;i<c;i++)
		oneCase(f1,f2);
	fclose(f1);fclose(f2);
	return 0;
}