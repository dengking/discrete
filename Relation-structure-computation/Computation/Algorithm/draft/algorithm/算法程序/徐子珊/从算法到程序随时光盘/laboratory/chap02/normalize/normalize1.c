/* 
 * File:   normalize.c
 * Author: 徐子珊
 *
 * Created on 2010年11月26日, 下午9:02
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<assert.h>
#include "..\..\datastructure\redblacktree.h"
#include "..\..\utility\strstream.h"
#include "..\..\utility\compare.h"
char *intProccess(char *s){/*整型数据处理函数*/
    StrInputStream ssin;/*创建串输入流*/
    RBTree *t=creatRBTree(sizeof(int),intGreater);/*t存放处理后的数据*/
    int x;
    initStrInputStream(&ssin,s);
    initStrOutputStream(&ssout,250);
    while(!sisEof(&ssin)){/*处理数据*/
        readInt(&ssin,&x);
        if(rbSearch(t,&x)==t->nil)/*若x没有出现在树t中*/
			rbInsert(t,&x);
    }
	inorderRBWalk(t,putInt);
	clrRBTree(t,NULL);free(t);
    writeString(&ssout,"\n");
    return ssout.begin;
}
char* charProccess(char *s){/*字符型数据处理*/
    StrInputStream ssin;/*创建串输入流*/
    RBTree *t=creatRBTree(sizeof(char),charGreater);/*t存放处理后的数据*/
    char x;
    initStrInputStream(&ssin,s);
    initStrOutputStream(&ssout,250);
    while(!sisEof(&ssin)){
        readChar(&ssin,&x);
        if(rbSearch(t,&x)==t->nil)/*若x没有出现在表l中*/
			rbInsert(t,&x);
   }
 	inorderRBWalk(t,putChar);
    writeString(&ssout,"\n");
	clrRBTree(t,NULL);free(t);
    return  ssout.begin;
}
char* doubleProccess(char *s){/*浮点型数据处理*/
    StrInputStream ssin;/*创建串输入流*/
    RBTree *t=creatRBTree(sizeof(double),doubleGreater);/*t存放处理后的数据*/
    double x;
    initStrInputStream(&ssin,s);
    initStrOutputStream(&ssout,250);
    while(!sisEof(&ssin)){
        readDouble(&ssin,&x);
        if(rbSearch(t,&x)==t->nil)/*若x没有出现在表l中*/
			rbInsert(t,&x);
   }
 	inorderRBWalk(t,putDouble);
	clrRBTree(t,NULL);free(t);
    writeString(&ssout,"\n");
    return  ssout.begin;
}
char* stringProccess(char *s){/*字符串型数据处理*/
    StrInputStream ssin;/*创建串输入流*/
    RBTree *t=creatRBTree(40,strcmp);/*t存放处理后的数据*/
    char x[20];
    initStrInputStream(&ssin,s);
    initStrOutputStream(&ssout,250);
    while(!sisEof(&ssin)){/*逐一读取流中数据*/
        readString(&ssin,x);
        if(rbSearch(t,&x)==t->nil)/*若x没有出现在表l中*/
			rbInsert(t,x);
    }
 	inorderRBWalk(t,putString);
	clrRBTree(t,NULL);free(t);
    writeString(&ssout,"\n");
    return  ssout.begin;
}
char* proccess(char type,char* s){/*按type表示的数据类型处理存储在s中的数据*/
    switch(type){
        case 'i': return intProccess(s);
        case 'c': return charProccess(s);
        case 'f': return doubleProccess(s);
        case 's': return stringProccess(s);
    }
	freeStrOutputStream(&ssout);
}
int main(int argc, char** argv) {
    FILE *inputfile,*outputfile;
    char s[250];
	assert((inputfile=fopen("chap02/normalize/inputdata.txt","r"))!=NULL);/*打开输入数据文件*/
    assert((outputfile=fopen("chap02/normalize/outputdata.txt","w"))!=NULL);/*打开输出数据文件*/
    while(!feof(inputfile)){/*还有输入数据*/
        char type,*t;
        fgets(s,250,inputfile);/*从中读取一行s*/
		type=*s;
        t=proccess(type,s+2);
        fputs(t,outputfile);/*将处理好的数据作为一行写入输出文件*/
    }
    fclose(inputfile);fclose(outputfile);/*关闭数据文件*/
    return (EXIT_SUCCESS);
}
