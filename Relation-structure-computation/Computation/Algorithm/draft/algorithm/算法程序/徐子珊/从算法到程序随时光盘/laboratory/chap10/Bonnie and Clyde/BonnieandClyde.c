#include "../../graph/articpoint.h"
#include "../../graph/dfs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int numOfTree(Graph *g){
	pair r;
	int *pi, i, nt=0, *d, *f;
	r=dfs(g);
	pi=(int*)r.first;
	d=(int*)(((pair*)r.second)->first);
	f=(int*)(((pair*)r.second)->second);
	for(i=0;i<g->n;i++)
		if(pi[i]==-1)
			nt++;
	free(pi);free(d);free(f);free(r.second);
	return nt;
}
int main(){
	int n, m,count=0;
	FILE *f1,*f2;
	assert(f1=fopen("chap10/Bonnie and Clyde/inputdata.txt","r"));
	assert(f2=fopen("chap10/Bonnie and Clyde/outputdata.txt","w"));
	fscanf(f1,"%d%d", &n, &m);/*读取案例中对象个数n及关系数m*/
	while(n||m){
		Graph *g=zeroGraph(n);
		LinkedList *atps; 
		int i, ways=0, number;
		for(i=0;i<m;i++){
			int u, v;
			fscanf(f1, "%d%d", &u, &v);
			addEdge(g, u-1, v-1, 1.0);
			addEdge(g, v-1, u-1,1.0);
		}
		atps=articPoint(g, 0);
		number=atps->n;clrList(atps,NULL);free(atps);
		if(number)
			for(i=1;i<=number;i++)
				ways+=(n-i);
		else{
			int u, v;
			for(u=0;u<n;u++)
				for(v=u+1;v<n;v++){
					Graph *g1=cloneGraph(g);
					deleteVertex(g1, u);
					deleteVertex(g1, v-1);
					if(numOfTree(g1)>1)
						ways++;
					graphClear(g1);free(g1);
				}
		}
		fprintf(f2, "Case %d: %d\n", ++count, ways);
		graphClear(g);free(g);
		fscanf(f1,"%d%d", &n, &m);
	}
	fclose(f1);fclose(f2);
	return 0;
}