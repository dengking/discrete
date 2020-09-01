#include <stdio.h>
#include <assert.h>
#include "../../numbertheory/bigint.h"
int main(){
	int n,i;
	FILE *f1=fopen("chap06/TheXProblem/inputdata.txt","r"), /*输入文件*/
		*f2=fopen("chap06/TheXProblem/outputdata.txt","w");/*输出文件*/
	assert(f1&&f2);
	fscanf(f1, "%d", &n);/*读取案例数*/
	for(i=0;i<n;i++){/*处理每个案例*/
		char a[1000], b[1000],*s;
		BigInt A, B, C;
		fscanf(f1, "%s%s", a, b);/*读取a，b*/
		A=newIntBystring(a); B=newIntBystring(b);/*生成大整数A，B*/
		C=product(A, B);/*C←A*B*/
		s=toString(&C);/*转换为串*/
		fprintf(f2,"%s\n",s);/*写入输出文件*/
		free(s);
		clrBigInt(&A);clrBigInt(&B);clrBigInt(&C);
	}
	fclose(f1);fclose(f2);
	return 0;
}