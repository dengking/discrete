#include "fft.h"
#include<stdlib.h>
#include<string.h>
#include <assert.h>
#include<math.h>
#include<stdio.h>
#define PI 3.14159
static int lg(int n){/*计算n的以2为底的对数*/
	int l=1,r=0;
	do{
		r++;
		l*=2;
	}while(l<n);
	return r;
}
static Complex* bitReverseCopy(Complex *a, int n){
	int bit,i,k,lgn,c,d;
	Complex *A=(Complex*)calloc(n,sizeof(Complex));
	lgn=lg(n);/*计算n的2进制位数*/
	for(k=0;k<n;k++){
		bit=1;c=0;
		for(i=0;i<lgn;i++){/*对k逐位转换到对称位得到c*/
			if(k&bit){/*k的第i位为1*/
				d=1;d<<=(lgn-i-1);/*将d的对称位置为1其它位均为0*/
				c|=d;/*将d添加到c的对应位上*/
			}
			bit<<=1;/*bit左移1位*/
		}
		A[c]=a[k];
	}
	return A;
}
Complex* fft(Complex *a, int n, int inv){//非递归的FFT
	int s,m=1,lgn,j,k;
	Complex *A=bitReverseCopy(a,n);//A赋值为本多项式的比特反转置换
	lgn=lg(n);
	for(s=1;s<=lgn;s++){
		Complex wm;
		m*=2;
		wm.real=cos(2*PI/m);wm.magic=inv*sin(2*PI/m);
		for(k=0;k<n;k+=m){
			Complex w={1.0,0.0},t,u;
			for(j=0;j<m/2;j++){
				t=compProd(w,A[k+j+m/2]);//t←wA[k+j+m/2]
				u=A[k+j];//u←A[k+j]
				A[k+j]=compSum(u,t);//A[k+j]←u+t
				A[k+j+m/2]=compDiff(u,t);//A[k+j+m/2]←u-t
				w=compProd(w,wm);//计算旋转因子
			}
		}
	}
	return A;
}
Complex* fftInverse(Complex *a, int n){//非递归DFT逆
	Complex *b, x={1.0/n,0.0};
	int i;
	b=fft(a,n,-1);
	for(i=0;i<n;i++)
		b[i]=compProd(b[i],x);
	return b;
}
