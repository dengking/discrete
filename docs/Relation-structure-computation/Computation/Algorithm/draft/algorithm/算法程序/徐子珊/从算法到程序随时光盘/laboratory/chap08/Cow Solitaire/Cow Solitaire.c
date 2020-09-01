#include<stdio.h>
#include<assert.h>
#include <stdlib.h>
int cowSolitaire(int *a, int n){
	int *f=(int*)malloc((n+2)*(n+1)*sizeof(int)),/*为数表f分配空间*/
		i,j,q;
	assert(f);
	for(i=0;i<n+2;i++)
		f[i*(n+1)]=0;/*f[i,0]←0*/
	for(j=1;j<n+1;j++)
		f[(n+1)*(n+1)+j]=0;/*f[n+1,j]←0*/
	for(i=n;i>0;i--)
		for(j=1;j<=n;j++){
			q=f[(i+1)*(n+1)+j]>=f[i*(n+1)+j-1]?/*q←max{f[i+1,j],f[i,j-1]}*/
				f[(i+1)*(n+1)+j]:
			    f[i*(n+1)+j-1];
			f[i*(n+1)+j]=q+a[(i-1)*n+j-1];/*f[i,j]←q+a[i,j]*/
		}
	q=f[n+1+n];/*返回f[1,n]*/
	free(f);
	return q;
}
int getValue(char x){/*将x中记录的牌点符号转换成整数值*/
		if(x>='2'&&x<='9')
			return x-'0';
		if(x=='A')
			return 1;
		if(x=='T')
			return 10;
		if(x=='J')
			return 11;
		if(x=='Q')
			return 12;
		return 13;
}
int main(){
	FILE *f1=fopen("chap04/Cow Solitaire/inputdata.txt","r"),
		*f2=fopen("chap04/Cow Solitaire/outputdata.txt","w");
	char s[4];
	int *a,n,i,j;
	fscanf(f1,"%d",&n);
	a=(int*)malloc(n*n*sizeof(int));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			fscanf(f1,"%s",s);
			a[i*n+j]=getValue(s[0]);
		}
	fprintf(f2,"%d\n",cowSolitaire(a,n));
	free(a);
	fclose(f1);fclose(f2);
	return 0;
}