#include <stdio.h>
#include <assert.h>
#include "../../numbertheory/bigint.h"
int main(){
	int n,i;
	FILE *f1=fopen("chap06/TheXProblem/inputdata.txt","r"), /*�����ļ�*/
		*f2=fopen("chap06/TheXProblem/outputdata.txt","w");/*����ļ�*/
	assert(f1&&f2);
	fscanf(f1, "%d", &n);/*��ȡ������*/
	for(i=0;i<n;i++){/*����ÿ������*/
		char a[1000], b[1000],*s;
		BigInt A, B, C;
		fscanf(f1, "%s%s", a, b);/*��ȡa��b*/
		A=newIntBystring(a); B=newIntBystring(b);/*���ɴ�����A��B*/
		C=product(A, B);/*C��A*B*/
		s=toString(&C);/*ת��Ϊ��*/
		fprintf(f2,"%s\n",s);/*д������ļ�*/
		free(s);
		clrBigInt(&A);clrBigInt(&B);clrBigInt(&C);
	}
	fclose(f1);fclose(f2);
	return 0;
}