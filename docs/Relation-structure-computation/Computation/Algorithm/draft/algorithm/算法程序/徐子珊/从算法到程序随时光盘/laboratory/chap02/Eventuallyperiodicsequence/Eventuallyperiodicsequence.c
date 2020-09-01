#include <limits.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include"../../utility/search.h"
 #include "../../datastructure/stack.h"
#include "../../utility/compare.h"
#include "../../utility/strstream.h"
#include "../../utility/output.h"
unsigned calculate(StrInputStream *rpn,unsigned  long long x, unsigned long long N){/*�����沨��ʽrpn��ʾ�ĺ���*/
    Stack* S=createStack(sizeof(unsigned long long));/*������ջ*/
    char d[20];/*��������Ӵ�*/
    unsigned long long op1,op2,r;/*��������������*/
    while(!sisEof(rpn)){/*RPN�ǿ�*/
       readString(rpn, d);/*������ǰ�������*/
       if(strcmp(d,"+")==0||strcmp(d,"*")==0||strcmp(d,"%")==0){/*�����*/
           op2=*(unsigned long long*)(pop(S)->key);/*����������*/
           op1=*(unsigned long long*)(pop(S)->key);/*����������*/
           if(*d=='+')/*�ǡ�+��*/
               r=op1+op2;/*�����*/
           else if(*d=='*')/*�ǡ�*��*/
               r=op1*op2;/*�����*/
           else
               r=op1%op2;/*�ǡ�%����������*/
           push(S,&r);/*������ѹջ*/
       }else{/*��������*/
		   if(strcmp(d,"x")==0)
				push(S,&x);
		   else if(strcmp(d,"N")==0){
			    push(S,&N);
		   }
		   else{
			    r=atoi(d);/*ת��Ϊ����*/
			    push(S,&r);/*������ѹջ*/
		   }
       }
    }
    r=*(unsigned long long*)(pop(S)->key);/*ջ��ΨһԪ��Ϊ����ֵ*/
    clrStack(S,NULL);/*����ջ�ռ�*/
	free(S);
    return r;/*���غ���ֵ*/
}
int main(){
	unsigned x,N;
    char s[256];/*��ȡ��ʼ���ʽ�Ĵ�*/
    FILE *in,*out;
    assert(in=fopen("chap02/Eventuallyperiodicsequence/inputdata.txt","r"));
    assert(out=fopen("chap02/Eventuallyperiodicsequence/outputdata.txt","w"));
    fgets(s,255,in);/*�������ļ��ж�ȡһ������*/
    while(1){
		StrInputStream rpn;
        unsigned*f;
		int  i=0,k=-1;
		initStrInputStream(&rpn,s);
        readInt(&rpn,&N);/*��ȡN*/
        readInt(&rpn,&x);/*��ȡx*/
		rpn.begin=rpn.current;
		if(x==0&&N==0)/*N��x��Ϊ0�����н���*/
            break;
        assert(f=(unsigned*)malloc((N+1)*sizeof(unsigned)));/*Ϊ����f����ռ�*/
		f[i]=x=calculate(&rpn,x,N);/*����f(x)*/
        while(k<0){/*f[0..i]�����ظ�Ԫ��*/
			sisRewind(&rpn);
            f[++i]=x=calculate(&rpn,x,N);/*����fi+1(x)*/
			k=linearSearch(f,sizeof(unsigned),i,&x,unsignedGreater);
        }
		free(f);
        printf("%d\n",i-k);
        fprintf(out,"%d\n",i-k);/*��¼����*/
        fgets(s,255,in);/*�������ļ��ж�ȡһ������*/
    }
    fclose(in);fclose(out);
    return EXIT_SUCCESS;
}
