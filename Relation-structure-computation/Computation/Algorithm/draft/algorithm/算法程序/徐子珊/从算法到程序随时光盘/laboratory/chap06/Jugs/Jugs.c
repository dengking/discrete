#include "..\..\numbertheory\gcd.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>
void getxy(int a, int b, int n, int *x, int *y){
	long long x0, y0, t=0, i=1, min=LONG_MAX,f ,x1, y1, x2, y2;
	egcd(a, b, &x0, &y0);
	f=x0<0?1:-1;
	x0*=n; y0*=n;
	x1=x0;y1=y0;
	x2=x1+f*b*i;y2=y1-f*a*i;
	while(abs(x2)<abs(x1)||abs(y2)<abs(y1)){
		if(x2<0&&-x2*a<min){
			min=-x2*a;
			t=i;
		}
		if(y2<0&&-y2<min){
			min=-y2*b;
			t=i;
		}
		x1=x2;y1=y2;
		i++;
		x2=x1+f*b*i;y2=y1+f*a*i;
	}
	*x=x0+f*b*t;*y=y0-f*a*t;
}
char *jugs1(int a, int b, int n, int x, int y){/*x<0, y>0*/
	int a1=0, b1=0;
	char *s=(char*)calloc(1000, sizeof(char));
	while(b1!=n){
		if(y&&b1==0){/*B桶汲水*/
			b1=b;y--;
			strcat(s, "fill B\n");
			continue;
		}
		if(x&&a1==a){/*将A桶中水倒掉*/
			a1=0;x++;
			strcat(s,"empty A\n");
			continue;
		}
		if(b1<=a-a1){/*B桶中的水可全部倒入A桶*/
			a1=b1+a1;b1=0;
		}else{/*B桶中的水只能部分倒入A桶*/
			b1=b1-(a-a1);a1=a;
		}
		strcat(s,"pore B A\n");
	}
	strcat(s, "succes\n");
	return s;
}
char *jugs2(int a, int b, int n, int x, int y){/*x>0, y<0*/
	int a1=0, b1=0;
	char *s=(char*)calloc(1000, sizeof(char));
	while(b1!=n){/*目标未达到*/
		if(x&&a1==0){/*A桶汲水*/
			a1=a;x--;
			strcat(s,"fiil A\n");
			continue;
		}
		if(y&&b1==b){/*倒掉B桶*/
			b1=0;y++;
			strcat(s,"empty B\n");
			continue;
		}
		if(a1<=b-b1){/*A桶中的水可全部倒入B桶*/
			b1=b1+a1;
			a1=0;
		}else{/*A桶中的水只能部分倒入B桶*/
			a1=a1-(b-b1);
			b1=b;
		}
		strcat(s,"pore A B\n");
	}
	strcat(s, "succes\n");
	return s;
}
char *jugs(int a, int b, int n, int x, int y){
	int a1=0, b1=0, a2, b2,x1,y1,*bb;
	char A[2], B[2], *s=(char*)calloc(1000, sizeof(char));
	if(x<0){
		a2=a;b2=b;bb=&b1;
		strcpy(A,"A");strcpy(B,"B");
		x1=x;y1=y;
	}else{
		a2=b;b2=a;bb=&a1;
		strcpy(A,"B");strcpy(B,"A");
		x1=y;y1=x;
	}
	while(*bb!=n){
		if(y1&&b1==0){/*B桶汲水*/
			b1=b2;y1--;
			strcat(s, "fill ");strcat(s,B);strcat(s,"\n");
			continue;
		}
		if(x1&&a1==a2){/*将A桶中水倒掉*/
			a1=0;x1++;
			strcat(s,"empty ");strcat(s,A);strcat(s,"\n");
			continue;
		}
		if(b1<=a2-a1){/*B桶中的水可全部倒入A桶*/
			a1=b1+a1;b1=0;
		}else{/*B桶中的水只能部分倒入A桶*/
			b1=b1-(a2-a1);a1=a2;
		}
		strcat(s,"pore ");strcat(s,B);strcat(s," ");strcat(s,A);strcat(s,"\n");
	}
	strcat(s, "succes\n");
	return s;
}
int main(){
	int a, b, n;
	FILE *f1=fopen("chap06/Jugs/inputdata.txt","r"), 
		*f2=fopen("chap06/Jugs/outputdata.txt","w");
	assert(f1&&f2);
	while(fscanf(f1,"%d%d%d",&a, &b, &n)!=EOF){
		int x,y;
		char *s;
		getxy(a,b,n,&x, &y);
		s=jugs(a,b,n,x,y);
		fputs(s,f2);
		free(s);
	}
	fclose(f1);fclose(f2);
	return 0;
}