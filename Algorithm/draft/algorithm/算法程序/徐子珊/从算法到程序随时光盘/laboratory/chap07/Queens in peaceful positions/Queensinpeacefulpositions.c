#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include "../../btrack/combineproblem.h"
int *origin,/*棋盘原始格局*/
	n;/*棋盘规模*/
int isPartial(int *x, int k){
	int i,j;
	for(i=0;i<k;i++)
		for(j=i+1;j<=k;j++)
			if((x[i]-x[j]==j-i)||(x[j]-x[i]==j-i))
				return 0;
	return 1;
}
int isComplete(int *x, int k){
	return k==n-1;
}
int compare(int *x, int *y){
	int i,different=0;
	for(i=0;i<n;i++)
		if(x[i]!=y[i])
			different++;
	return different;
}
int main(){
	LinkedList *ss;
	ListNode *p;
	int i,*configuration,x,y,count=0;
	FILE *f1=fopen("chap07/Queens in peaceful positions/inputdata.txt","r"), 
		*f2=fopen("chap07/Queens in peaceful positions/outputdata.txt","w");
	assert(f1&&f2);
	fscanf(f1,"%d",&n);
	assert(origin=(int*)malloc(n*sizeof(int)));
	assert(configuration=(int*)malloc(n*sizeof(int)));
	for(i=0;i<n;i++){
		origin[i]=i+1;
		fscanf(f1, "%d %d",&x, &y);
		configuration[y-1]=x;
	}
	ss=permutTree(origin, sizeof(int), n);
	p=ss->nil->next;
	while(p!=ss->nil){
		if(compare(configuration,(int*)((Solution*)(p->key))->x)==3)
			count++;
		p=p->next;
	}
	fprintf(f2, "%d\n",count);
	printf("%d\n",count);
	free(configuration);free(origin);
	clrList(ss, clrSolution);
	free(ss);
	fclose(f1);fclose(f2);
	return 0;
}