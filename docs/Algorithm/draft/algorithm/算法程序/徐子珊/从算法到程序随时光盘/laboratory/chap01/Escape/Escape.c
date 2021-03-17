#include <stdio.h>
#include <assert.h>
const int MOD=100000007;//这是一个素数
unsigned min(unsigned a, unsigned b, unsigned c, unsigned d){
	unsigned x=a<=b?a:b, y=c<=d?c:d;
	return x<=y?x:y;
}
unsigned escape(unsigned X,unsigned Y, unsigned x, unsigned y){
	unsigned  long long f1=Y-y,f2=X-x,f3=y,f4=x-1,
		P1=f1, P2=f2, P3=f3, P4=f4,
		m=min(Y-y, X-x, y, x-1),j,s;
	if(x==0)
		return 1;
	if(m==0){
		if(Y-y==m)
			return 1;
		if(X-x==m)
			return 1+(unsigned)P1;
		if(y==m)
			return 1+(unsigned)P1+(unsigned)((P1*P2)%MOD);
		return 1+(unsigned)P1+(unsigned)((P1*P2)%MOD)+(unsigned)((((P1*P2)%MOD)*P3)%MOD);
	}
	s=1+P1+(P1*P2)%MOD+(((P1*P2)%MOD)*P3)%MOD;
	for(j=1;j<m;j++){
		s=s+(((P1*P2)%MOD)*((P3*P4)%MOD))%MOD;
		P1=(--f1*P1/2)%MOD;
		s=s+(((P1*P2)%MOD)*((P3*P4)%MOD))%MOD;
		P2=(--f2*P2/2)%MOD;
		s=s+(((P1*P2)%MOD)*((P3*P4)%MOD))%MOD;
		P3=(--f3*P3/2)%MOD;
		s=s+(((P1*P2)%MOD)*((P3*P4)%MOD))%MOD;
		P4=(--f4*P4)%MOD;
	}
	if(Y-y==m)
		return (unsigned)s+(unsigned)((((P1*P2)%MOD)*((P3*P4)%MOD))%MOD);
	if(X-x==m){
		s=s+(((P1*P2)%MOD)*((P3*P4)%MOD))%MOD;
		P1=(--f1*P1/2)%MOD;
		return (unsigned)s+(unsigned)((((P1*P2)%MOD)*((P3*P4)%MOD))%MOD);
	}
	if(y==m){
		s=s+(((P1*P2)%MOD)*((P3*P4)%MOD))%MOD;
		P1=(--f1*P1/2)%MOD;
		s=s+(((P1*P2)%MOD)*((P3*P4)%MOD))%MOD;
		P2=(--f2*P2/2)%MOD;
		return (unsigned)s+(unsigned)((((P1*P2)%MOD)*((P3*P4)%MOD))%MOD);
	}
	s=s+(((P1*P2)%MOD)*((P3*P4)%MOD))%MOD;
	P1=(--f1*P1/2)%MOD;
	s=s+(((P1*P2)%MOD)*((P3*P4)%MOD))%MOD;
	P2=(--f2*P2/2)%MOD;
	s=s+(((P1*P2)%MOD)*((P3*P4)%MOD))%MOD;
	P3=(--f3*P3/2)%MOD;
	return (unsigned)s+(unsigned)((((P1*P2)%MOD)*((P3*P4)%MOD))%MOD);
}
int main(){
	int X, Y, x, y, n, i;
	FILE *f1=fopen("chap01/Escape/inputdata.txt","r"),
		*f2=fopen("chap01/Escape/outputdata.txt","w");
	assert(f1&&f2);
	fscanf(f1,"%d", &n);
	for(i=0;i<n;i++){
		fscanf(f1,"%d%d%d%d",&X, &Y, &x, &y);
		fprintf(f2,"%d\n",escape(X, Y, x, y));
	}
	fclose(f1);fclose(f2);
	return 0;
}