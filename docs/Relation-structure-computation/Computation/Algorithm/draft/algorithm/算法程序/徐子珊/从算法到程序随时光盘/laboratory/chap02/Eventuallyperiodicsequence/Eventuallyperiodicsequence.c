#include <limits.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include"../../utility/search.h"
 #include "../../datastructure/stack.h"
#include "../../utility/compare.h"
#include "../../utility/strstream.h"
#include "../../utility/output.h"
unsigned calculate(StrInputStream *rpn,unsigned  long long x, unsigned long long N){/*计算逆波兰式rpn表示的函数*/
    Stack* S=createStack(sizeof(unsigned long long));/*创建空栈*/
    char d[20];/*运算对象子串*/
    unsigned long long op1,op2,r;/*运算数和运算结果*/
    while(!sisEof(rpn)){/*RPN非空*/
       readString(rpn, d);/*分析当前运算对象*/
       if(strcmp(d,"+")==0||strcmp(d,"*")==0||strcmp(d,"%")==0){/*运算符*/
           op2=*(unsigned long long*)(pop(S)->key);/*弹出运算数*/
           op1=*(unsigned long long*)(pop(S)->key);/*弹出运算数*/
           if(*d=='+')/*是‘+’*/
               r=op1+op2;/*计算和*/
           else if(*d=='*')/*是‘*’*/
               r=op1*op2;/*计算积*/
           else
               r=op1%op2;/*是‘%’，求余数*/
           push(S,&r);/*运算结果压栈*/
       }else{/*是运算数*/
		   if(strcmp(d,"x")==0)
				push(S,&x);
		   else if(strcmp(d,"N")==0){
			    push(S,&N);
		   }
		   else{
			    r=atoi(d);/*转换为整数*/
			    push(S,&r);/*运算数压栈*/
		   }
       }
    }
    r=*(unsigned long long*)(pop(S)->key);/*栈中唯一元素为函数值*/
    clrStack(S,NULL);/*清理栈空间*/
	free(S);
    return r;/*返回函数值*/
}
int main(){
	unsigned x,N;
    char s[256];/*读取初始表达式的串*/
    FILE *in,*out;
    assert(in=fopen("chap02/Eventuallyperiodicsequence/inputdata.txt","r"));
    assert(out=fopen("chap02/Eventuallyperiodicsequence/outputdata.txt","w"));
    fgets(s,255,in);/*从输入文件中读取一行数据*/
    while(1){
		StrInputStream rpn;
        unsigned*f;
		int  i=0,k=-1;
		initStrInputStream(&rpn,s);
        readInt(&rpn,&N);/*提取N*/
        readInt(&rpn,&x);/*提取x*/
		rpn.begin=rpn.current;
		if(x==0&&N==0)/*N、x均为0，运行结束*/
            break;
        assert(f=(unsigned*)malloc((N+1)*sizeof(unsigned)));/*为数组f分配空间*/
		f[i]=x=calculate(&rpn,x,N);/*计算f(x)*/
        while(k<0){/*f[0..i]中无重复元素*/
			sisRewind(&rpn);
            f[++i]=x=calculate(&rpn,x,N);/*计算fi+1(x)*/
			k=linearSearch(f,sizeof(unsigned),i,&x,unsignedGreater);
        }
		free(f);
        printf("%d\n",i-k);
        fprintf(out,"%d\n",i-k);/*记录周期*/
        fgets(s,255,in);/*从输入文件中读取一行数据*/
    }
    fclose(in);fclose(out);
    return EXIT_SUCCESS;
}
