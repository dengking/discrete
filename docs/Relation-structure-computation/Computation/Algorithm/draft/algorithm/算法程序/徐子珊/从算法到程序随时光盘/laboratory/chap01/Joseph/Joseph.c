#include<stdio.h>
#include<assert.h>
int joseph(int k){
	int m,t,a=1,b,i,n;
	while(1){
		for(b=1;b<=k;b++){
			m=a*k+b,t=0,n=2*k;
			for(i=1;i<=k;i++){
				t=(t+m-1)%n;
				if(t<k)
					break;
				n--;
			}
			if(i>k)
				return m;
		}
		a+=2;
	}
}
int main(){
	int k;
	FILE *f1=fopen("chap01/Joseph/inputdata.txt","r"),
		*f2=fopen("chap01/Joseph/outputdata.txt","w");
	assert(f1&&f2);
	fscanf(f1,"%d",&k);
	while(k){
		fprintf(f2,"%d\n",joseph(k));
		fscanf(f1,"%d",&k);
	}
	fclose(f1);fclose(f2);
	return 0;
}