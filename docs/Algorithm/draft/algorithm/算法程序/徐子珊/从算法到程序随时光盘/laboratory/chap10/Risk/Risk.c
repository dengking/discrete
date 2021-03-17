#include "../../graph/bfs.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
int main(){
	FILE *f1,*f2;
	assert(f1=fopen("chap10/Risk/inputdata.txt","r"));
	assert(f2=fopen("chap10/Risk/outputdata.txt","w"));
	while(!feof(f1)){
		int i, j, k, x, *d, n, A, B, c=0;
		Graph *g=zeroGraph(20);
		pair p;
		for(i=0;i<19;i++){
			fscanf(f1, "%d", &x);
			for(k=0;k<x;k++){
				fscanf(f1, "%d", &j);
				j--;
				addEdge(g,i,j,1.0);
				addEdge(g,j,i,1.0);
			}
		}
		fprintf(f2, "Test Set #%d\n", ++c);
		fscanf(f1, "%d", &n);
		for(i=0;i<n;i++){
			fscanf(f1, "%d%d", &A, &B);
			p=bfs(g, A-1);
			free(p.first);d=(int*)p.second;
			fprintf(f2, "%d to %d: %d\n", A, B,d[B-1]);
			free(d);
		}
		graphClear(g);free(g);
	}
	fclose(f1);fclose(f2);
	return 0;
}