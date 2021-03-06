#include "./strstream.h"
#include<stdlib.h>
#include <stdio.h>
#include<string.h>


///////////////////////////////输入流///////////////////////////////////////////////////////
void initStrInputStream(StrInputStream* ssin,char* s){/*初始化输入流*/
    while(*s==' '||*s=='\t')/*掠过空格*/
        s++;
    ssin->begin=ssin->current=s;  //z注意此操作是实质是指针的赋值，即让current和begin也指向s数组 。这样后续的许多操作就可以通过current来完成。
}
/*此函数的功能是把ssin的begin和current皆设置为s。假如输入流中的数据之间用空格作为分隔符。
初始化时，作为流载体的串即s可能存在前导空格，这会影响数据的正确读出，因此第二三行的while负责掠过前导空格
s是流载体
*/

/*从串输入流中读取数据*/
int readInt(StrInputStream* ssin,int* x){
    char s[80];
    int n;
    while(*(ssin->current)==' '||*(ssin->current)=='\t')/*掠过空格*/
        (ssin->current)++;
    sscanf(ssin->current,"%s",s);/*从当前位置读取数据项。通过调用库函数sscanf，从current指向的位置开始，以串格式%s将数据读取到s中*/
    n=strlen(s);
    if(!n)/*未读到数据*/
        return 0;
    ssin->current+=n;/*读到数据，调整读取位置*/
    *x=atoi(s);/*将数据转换成整数，赋值给x指向的动态变量*/
    return 1;
}
/*ssin是一个指向串输入流的指针，x是指向接收数据的整形变量的指针。读取成功则返回1，否则返回0*/
int readDouble(StrInputStream* ssin,double* x){
    char s[80];
    int n;
    while(*(ssin->current)==' '||*(ssin->current)=='\t')/**/
        (ssin->current)++;
    sscanf(ssin->current,"%s",s);/**/
    n=strlen(s);
    if(!n)/**/
        return 0;
    ssin->current+=n;/**/
    *x=atof(s);/**/
    return 1;
}
int readChar(StrInputStream* ssin,char* x){
    char s[80];
    int n;
    while(*(ssin->current)==' '||*(ssin->current)=='\t')/**/
        (ssin->current)++;
    sscanf(ssin->current,"%s",s);/**/
    n=strlen(s);
    if(n!=1)/**/
        return 0;
    ssin->current+=n;/**/
    *x=s[0];
    return 1;
}
int readString(StrInputStream* ssin,char* x){
    int n;
    while(*(ssin->current)==' '||*(ssin->current)=='\t')/**/
        (ssin->current)++;
    sscanf(ssin->current,"%s",x);/**/
    n=strlen(x);
    if(!n)/**/
        return 0;
    ssin->current+=n;/**/
    return 1;
}
int sisEof(StrInputStream* ssin){/**/
    return (strlen(ssin->current)==0)||(*(ssin->current)=='\r'||(*(ssin->current)=='\n'));
}
/*
输入流为空则返回1否则返回0.通过检测current指向的串长度是否为0或current指向的字符为回车或换行符来判断串输入流是否为空。
*/
void sisRewind(StrInputStream* ssin){
	ssin->current=ssin->begin;
}
/*恢复输入流的初始状态*/
///////////////////////////////输入流///////////////////////////////////////////////////////



//////////////////////////////////输出流//////////////////////////////////////////////////
/*这些操作的实质是将输出流读入到一个数组中*/
int sosEof(StrOutputStream* sout){/*检测输出流空间是否满。通过检测输出流中的current指针是否指向空间的末尾来判断输出流是否满*/
    return sout->current-sout->begin>=sout->length;
}
void initStrOutputStream(StrOutputStream* sout,int size){/*size用来指定输出流的长度*/
    if(sout->begin=(char*)malloc(size*sizeof(char))){/*分配串输出流空间*/
        sout->length=size;
        memset(sout->begin,0,size*sizeof(char));//将流载体初始化
        sout->current=sout->begin;
    }
}
int writeInt(StrOutputStream* sout,int x){/*sout是指向串输出流的指针，把sout->current指向的数据写入x中*/
    if(sosEof(sout))/**/
        return 0;
    if(sout->current==sout->begin)/*如果读取的是第一个，则前面无需空格*/
        sprintf(sout->current,"%d",x);
    else
        sprintf(sout->current,"%c%d",' ',x);//读取的不是第一个，则需要在每个前面加上空格
    sout->current+=strlen(sout->current);/*刷新写入位置current*/
    return 1;
}
int writeDouble(StrOutputStream* sout,double x){/**/
    if(sosEof(sout))/**/
        return 0;
    if(sout->current==sout->begin)/**/
        sprintf(sout->current,"%f",x);
    else
        sprintf(sout->current,"%c%f",' ',x);
    sout->current+=strlen(sout->current);/**/
    return 1;
}
int writeChar(StrOutputStream* sout,char x){/**/
    if(sosEof(sout))/**/
        return 0;
    if(sout->current==sout->begin)/**/
        sprintf(sout->current,"%c",x);
    else
        sprintf(sout->current,"%c%c",' ',x);
    sout->current+=strlen(sout->current);/**/
    return 1;
}
int writeString(StrOutputStream* sout,char *s){
    if(sosEof(sout))
        return 0;
    if(sout->current==sout->begin)
        sprintf(sout->current,"%s",s);
    else
        sprintf(sout->current,"%c%s",' ',s);
    sout->current+=strlen(sout->current);
    return 1;
}
void freeStrOutputStream(StrOutputStream* sout){/**/
    sout->length=0;
    sout->current=NULL;
    if(sout->begin)
        free(sout->begin);
}
void sosRewind(StrOutputStream* sout){
	sout->current=sout->begin;
}
void putInt(int *data){
	writeInt(&ssout,*data);
}
void putChar(char *data){
	writeChar(&ssout,*data);
}
void putDouble(double *data){
	writeDouble(&ssout,*data);
}
void putString(char *data){
	writeString(&ssout,data);
}
