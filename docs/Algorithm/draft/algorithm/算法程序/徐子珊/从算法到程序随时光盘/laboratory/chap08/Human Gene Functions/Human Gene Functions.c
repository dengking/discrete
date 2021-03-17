#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
int a[5][5]={5,-1,-2,-1,-3,/*联配矩阵*/
					 -1,5,-3,-2,-4,
					 -2,-3,5,-2,-2,
					 -1,-2,-2,5,-1,
					 -3,-4,-2,-1,0};
int max3(int a,int b,int c){/*计算3个整数的最大值*/
	int max=a;
	if(b>max)
		max=b;
	if(c>max)
		max=c;
	return max;
}
int index(char A){/*将字符A、C、G、T转换为下标0、1、2、3*/
	switch(A){
		case 'A': return 0;
		case 'C': return 1;
		case 'G': return 2;
		case 'T': return 3;
	}
}
int humanGenuFunctions(char *x, char *y){/*联配记分*/
	int *s,i,j,m,n,r;
	m=strlen(x);n=strlen(y);
	assert(s=(int *)malloc((m+1)*(n+1)*sizeof(int)));
	s[0]=0;
	for(i=1;i<=m;i++)
		s[i*(n+1)]=s[(i-1)*(n+1)]+a[index(x[i-1])][4];
	for(j=1;j<=n;j++)
		s[j]=s[j-1]+a[4][index(y[j-1])];
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			s[i*(n+1)+j]=max3(s[(i-1)*(n+1)+j-1]+a[index(x[i-1])][index(y[j-1])],
											 s[(i-1)*(n+1)+j]+a[index(x[i-1])][4],
											 s[i*(n+1)+j-1]+a[4][index(y[j-1])]);
	r=s[m*(n+1)+n];
	free(s);
	return r;
}
int main(){
	FILE *f1=fopen("chap08/Human Gene Functions/inputdata.txt","r"),
		*f2=fopen("chap08/Human Gene Functions/outputdata.txt","w");
	char x[101],y[101];
	int t,i,a;
	assert(f1&&f2);
	fscanf(f1,"%d",&t);
	for(i=0;i<t;i++){
		fscanf(f1,"%d%s",&a,x);
		fscanf(f1,"%d%s",&a,y);
		fprintf(f2,"%d\n",humanGenuFunctions(x,y));
	}
	fclose(f1),fclose(f2);
	return 0;
}