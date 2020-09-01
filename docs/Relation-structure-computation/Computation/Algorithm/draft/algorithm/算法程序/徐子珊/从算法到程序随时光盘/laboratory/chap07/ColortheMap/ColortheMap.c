#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../../datastructure/list.h"
#include "../../geometry/point.h"
#include "../../btrack/mcolor.h"
typedef struct{
	LinkedList *territories;
	char name[21];
}Contry;
typedef struct{
	Point a;
	Point b;
}Edge;
void clrMap(Contry *a, int n){
	int i;
	for(i=0;i<n;i++){
		LinkedList *p=a[i].territories, *q;
		ListNode *t=p->nil->next;
		while(t!=p->nil){
			q=*(LinkedList **)(t->key);
			clrList(q,NULL);
			t=t->next;
		}
		clrList(p,NULL);
		free(p);
	}
}
int edgeComp(Edge *x, Edge *y){
	if(((x->a).x==(y->a).x&&(x->a).y==(y->a).y&&
		(x->b).x==(y->b).x&&(x->b).y==(y->b).y)||
		((x->a).x==(y->b).x&&(x->a).y==(y->b).y&&
		(x->b).x==(y->a).x&&(x->b).y==(y->a).y))
		return 0;
	if(direction(&(x->a),&(x->b),&(y->a))||direction(&(x->a),&(x->b),&(y->b)))
		return 1;
	if(InBox(&(x->a),&(x->b),&(y->a))||InBox(&(x->a),&(x->b),&(y->b))||
		InBox(&(y->a),&(y->b),&(x->a))||InBox(&(y->a),&(y->b),&(x->b)))
		return 0;
	return 1;
}
int searchContry(Contry *c, int n, char *name){
	int i;
	for(i=0;i<n;i++)
		if(strcmp(c[i].name,name)==0)
			return i;
	return -1;
}
Contry* makeMap(FILE *f){
		int i,num=0,index;
		Contry *contries=(Contry*)malloc(n*sizeof(Contry));
		for(i=0;i<n;i++){
			int c=0,x,y,x0,y0;
			LinkedList *territory=createList(sizeof(Edge),edgeComp);
			Edge e;
			char s[50];
			fscanf(f,"%s\n",s);
			if((index=searchContry(contries,num,s))==-1){
				index=num++;
				strcpy(contries[index].name,s);
				contries[index].territories=createList(sizeof(LinkedList*),NULL);
			}
			fgets(s,40,f);
			sscanf(s,"%d%d",&x,&y);
			e.b.x=x0=x;e.b.y=y0=y;
			fgets(s,40,f);
			sscanf(s,"%d%d",&x,&y);
			while(x>-1){
				e.a=e.b;
				e.b.x=x;e.b.y=y;
				listPushBack(territory,&e);
				fgets(s,40,f);
				sscanf(s,"%d%d",&x,&y);
			}
			e.a=e.b;
			e.b.x=x0;e.b.y=y0;
			listPushBack(territory,&e);
			listPushBack(contries[index].territories,&territory);
		}
		n=num;
		return contries;
}
int* map2Graph(Contry *map){
	int i, j;
	G=(int*)calloc(n*n,sizeof(int));
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			int find=0;
			LinkedList *territories=map[i].territories,
				*territory;
			ListNode *t=(territories->nil->next),*p;
			while(t!=territories->nil){
				territory=*(LinkedList**)((t->key));
				p=territory->nil->next;
				while(p!=territory->nil){
					Edge e=*((Edge*)(p->key));
					LinkedList *territoriesj=map[j].territories,
						*territoryj;
					ListNode *tj=(territoriesj->nil->next),*q;
					while(tj!=territoriesj->nil){
						territoryj=*(LinkedList**)((tj->key));
						q=listSearch(territoryj,&e);
						if(q!=territoryj->nil){
							G[i*n+j]=1;
							G[j*n+i]=1;
							find=1;
							break;
						}
						tj=tj->next;
					}
					if(find==1)
						break;
					p=p->next;
				}
				t=t->next;
				if(find==1)
					break;
			}
		}
	}
	return G;
}
int main(){
	FILE *f1=fopen("chap07/ColortheMap/inputdata.txt","r"), 
		*f2=fopen("chap07/ColortheMap/outputdata.txt","w");
	assert(f1&&f2);
	fscanf(f1,"%d",&n);
	while(n){/**/
		LinkedList *ss=NULL;
		Contry *Map= makeMap(f1);
		G=map2Graph(Map);
		clrMap(Map,n);free(Map);
		m=0;
		do{
			ValueSet **OMG;
			m++;
			OMG=makeOMG();
			if(ss)
				clrList(ss,clrSolution);
			ss=backtrackiter(OMG, n);
			clrOMG(OMG,n,NULL);
			free(OMG);
		}while(listEmpty(ss));
		fprintf(f2,"%d\n",m);
		free(G);
		clrList(ss,clrSolution);free(ss);
		fscanf(f1,"%d",&n);
	}
	fclose(f1);fclose(f2);
	return 0;
}