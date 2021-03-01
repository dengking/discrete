#include "fft.h"
#include<stdlib.h>
#include<string.h>
#include <assert.h>
#include<math.h>
#include<stdio.h>
#define PI 3.14159
static int lg(int n){/*����n����2Ϊ�׵Ķ���*/
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
	lgn=lg(n);/*����n��2����λ��*/
	for(k=0;k<n;k++){
		bit=1;c=0;
		for(i=0;i<lgn;i++){/*��k��λת�����Գ�λ�õ�c*/
			if(k&bit){/*k�ĵ�iλΪ1*/
				d=1;d<<=(lgn-i-1);/*��d�ĶԳ�λ��Ϊ1����λ��Ϊ0*/
				c|=d;/*��d��ӵ�c�Ķ�Ӧλ��*/
			}
			bit<<=1;/*bit����1λ*/
		}
		A[c]=a[k];
	}
	return A;
}
Complex* fft(Complex *a, int n, int inv){//�ǵݹ��FFT
	int s,m=1,lgn,j,k;
	Complex *A=bitReverseCopy(a,n);//A��ֵΪ������ʽ�ı��ط�ת�û�
	lgn=lg(n);
	for(s=1;s<=lgn;s++){
		Complex wm;
		m*=2;
		wm.real=cos(2*PI/m);wm.magic=inv*sin(2*PI/m);
		for(k=0;k<n;k+=m){
			Complex w={1.0,0.0},t,u;
			for(j=0;j<m/2;j++){
				t=compProd(w,A[k+j+m/2]);//t��wA[k+j+m/2]
				u=A[k+j];//u��A[k+j]
				A[k+j]=compSum(u,t);//A[k+j]��u+t
				A[k+j+m/2]=compDiff(u,t);//A[k+j+m/2]��u-t
				w=compProd(w,wm);//������ת����
			}
		}
	}
	return A;
}
Complex* fftInverse(Complex *a, int n){//�ǵݹ�DFT��
	Complex *b, x={1.0/n,0.0};
	int i;
	b=fft(a,n,-1);
	for(i=0;i<n;i++)
		b[i]=compProd(b[i],x);
	return b;
}
