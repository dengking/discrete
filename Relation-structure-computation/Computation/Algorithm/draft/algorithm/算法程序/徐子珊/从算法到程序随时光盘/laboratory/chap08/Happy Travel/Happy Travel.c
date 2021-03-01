#include<stdio.h>
#include<assert.h>
#include "../../dprog/knapsack.h"
int main(){
	FILE *f1=fopen("chap04/Happy Travel/inputdata.txt","r"),
		*f2=fopen("chap04/Happy Travel/outputdata.txt","w");
	int n, *w, c, i, k=1, *m;
	assert(f1&&f2);
	while(!feof(f1)){
		fscanf(f1,"%d",&n);/*��ȡ�������*/
		assert(w=(int*)malloc(n*sizeof(int)));
		for(i=0,c=0;i<n;i++){/*��ȡÿ�����������*/
			fscanf(f1,"%d", w+i);
			c+=w[i];/*����������*/
		}
		m=knapsack(w,w,n,c/2);/*���㲻����������һ������ֵ*/
		fprintf(f2,"Case %d: %d %d\n",k++,m[n*(c/2+1)+c/2],c-m[n*(c/2+1)+c/2]);
		free(w);
	}
	fclose(f1),fclose(f2);
	return 0;
}