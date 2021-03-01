#include<stdio.h>
#include<assert.h>
int countingQuadrangles(int n){
	int k,count=0;
	count=n*(2*n*n-n);/*高为1*/
	for(k=2;k<=n;k++){/*高为k*/
		count+=(n-k+1)*(
			n*(n+1)/2/*矩形个数*/
			+3*(n-k+1)*(n-k)/2/*水平平行四边形、直梯形*/
			+3*(k-1)*(2*n-k+2)/2/*竖直梯形、平行四边形*/
			+2*(n-k+1)*(k-1)/*等腰梯形*/
			);
	}
	return count;
}
int main(){
	int n;
	FILE *f1=fopen("chap01/Counting Quadrangles/inputdata.txt","r"),
		*f2=fopen("chap01/Counting Quadrangles/outputdata.txt","w");
	assert(f1&&f2);
	fscanf(f1,"%d",&n);
	while(n){
		fprintf(f2,"%d\n",countingQuadrangles(n));
		fscanf(f1,"%d",&n);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}