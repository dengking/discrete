#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "../../utility/swap.h"
#include "../../greedy/huffman.h"
void inversestr(char *s){
	int i=0,j=strlen(s)-1;
	while(i<j){
		swap(s+i,s+j,sizeof(char));
		i++;j--;
	}
}
double Calculate(HTree T){
	int i,sum=0;
	double ave=0.0;
	for(i=0;i<T.N;i++){
		int j,node=i,parent=T.Nodes[i].parent,index=0;
		while(parent!=-1){
			j=0;
			while(T.Nodes[parent].child[j]!=node)j++;
			T.Nodes[i].code[index++]='0'+j;
			node=parent;
			parent=T.Nodes[node].parent;
		}
		inversestr(T.Nodes[i].code);
		ave+=T.Nodes[i].f*strlen(T.Nodes[i].code);
		sum+=T.Nodes[i].f;
	}
	return ave/sum;
}
int main(){
	int r,n,count=1;
	FILE *f1=fopen("chap09/Variable Radix Huffman Encoding/inputdata.txt","r"),
		*f2=fopen("chap09/Variable Radix Huffman Encoding/outputdata.txt","w");
	assert(f1&&f2);
	fscanf(f1,"%d%d",&r,&n);
	while(r){
		int i, *f;
		char *C;
		HTree T;
		double ave;
		assert(C=(char*)malloc(n*sizeof(char)));
		assert(f=(int*)malloc(n*sizeof(int)));
		for(i=0;i<n;i++){
			C[i]='A'+i;
			fscanf(f1,"%d",f+i);
		}
		T=Huffman(C,f,n,r);
		ave=Calculate(T);
		fprintf(f2, "Set %d; average length %.2f\n",count++,ave);
		for(i=0;i<T.N;i++)
			fprintf(f2, "%c: %s\n", T.Nodes[i].ch,T.Nodes[i].code);
		fprintf(f2, "\n");
		free(C);free(f);
		clrHTree(&T);
		fscanf(f1,"%d%d",&r,&n);
	}
	fclose(f1);fclose(f2);
	return 0;
}