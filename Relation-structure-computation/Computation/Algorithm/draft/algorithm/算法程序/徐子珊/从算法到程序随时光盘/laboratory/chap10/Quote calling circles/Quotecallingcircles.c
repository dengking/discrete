#include "../../graph/scc.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
int find(char **name, char *s, int index){
	int i;
	for(i=0;i<index;i++)
		if(strcmp(name[i],s)==0)
			return i;
	return -1;
}
int main(){
	int n, m,count=0;
	FILE *f1,*f2;
	assert(f1=fopen("chap10/Quote calling circles/inputdata.txt","r"));
	assert(f2=fopen("chap10/Quote calling circles/outputdata.txt","w"));
	fscanf(f1,"%d%d", &n, &m);
	while(n||m){
		int i,index=0;
		Graph *g=zeroGraph(n);
		LinkedList *forest;
		ListNode *p;
		char **name=(char**)malloc(n*sizeof(char*));
		for(assert(name),i=0;i<n;i++)
			name[i]=(char*)calloc(26, sizeof(char));
		for(i=0;i<m;i++){
			char A[26], B[26];
			int u, v, k;
			fscanf(f1, "%s%s", A, B);
			k=find(name, A, index);
			if(k==-1){
				u=index;
				strcpy(name[index++],A);
			}else{
				u=k;
			}
			k=find(name, B, index);
			if(k==-1){
				v=index;
				strcpy(name[index++],B);
			}else{
				v=k;
			}
			addEdge(g, u, v, 1.0);
		}
		forest=strongConnectedComponents(g);
		fprintf(f2, "Calling circles for data set %d:\n",++count);
		p=forest->nil->next;
		while(p!=forest->nil){
			LinkedList *tree=*((LinkedList**)p->key);
			ListNode *q=tree->nil->next;
			while(q!=tree->nil){
				int u=*((int*)q->key);
				fprintf(f2, "%s ", name[u]);
				q=q->next;
			}
			fputc('\n',f2);
			clrList(tree,NULL);free(tree);
			p=p->next;
		}
		clrList(forest,NULL);free(forest);
		fprintf(f2,"\n");
		for(i=0;i<n;i++)
			free(name[i]);
		free(name);
		fscanf(f1,"%d%d", &n, &m);
	}
	fclose(f1);fclose(f2);
	return 0;
}