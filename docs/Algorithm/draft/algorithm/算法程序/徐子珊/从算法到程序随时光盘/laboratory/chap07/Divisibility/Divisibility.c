#include "../../btrack/combineproblem.h"
#include <assert.h>
#include <stdio.h>
int n,k,*numbers;
int isPartial(void* x, int k1){/*部分合法判断*/
	return k1<n;
}
int isComplete(int* x, int k1){/*完整合法解判断*/
	if(k1==n-1){
		int i,y=numbers[0];
		for(i=0;i<n;i++){
			if(x[i]==0)
				y+=numbers[i+1];
			else
				y-=numbers[i+1];
		}
		return y%k==0;
	}
	return 0;
}
int main(){
	int i;
	LinkedList *s;
	FILE *f1=fopen("chap07/Divisibility/inputdata.txt","r"), 
		*f2=fopen("chap07/Divisibility/outputdata.txt","w");
	assert(f1&&f2);
	fscanf(f1,"%d%d",&n,&k);
	numbers=(int*)calloc(n,sizeof(int));
	for(i=0;i<n;i++)
		fscanf(f1, "%d", numbers+i);
	n--;
	s=subSetTree(n);
	if(!listEmpty(s))
		fprintf(f2,"Divisible\n");
	else
		fprintf(f2,"Not divisible\n");
	clrList(s,clrSolution);free(s);
	fclose(f1);fclose(f2);
	return 0;
}