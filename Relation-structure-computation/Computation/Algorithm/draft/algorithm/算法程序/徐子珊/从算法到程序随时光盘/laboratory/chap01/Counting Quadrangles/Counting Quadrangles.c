#include<stdio.h>
#include<assert.h>
int countingQuadrangles(int n){
	int k,count=0;
	count=n*(2*n*n-n);/*��Ϊ1*/
	for(k=2;k<=n;k++){/*��Ϊk*/
		count+=(n-k+1)*(
			n*(n+1)/2/*���θ���*/
			+3*(n-k+1)*(n-k)/2/*ˮƽƽ���ı��Ρ�ֱ����*/
			+3*(k-1)*(2*n-k+2)/2/*��ֱ���Ρ�ƽ���ı���*/
			+2*(n-k+1)*(k-1)/*��������*/
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