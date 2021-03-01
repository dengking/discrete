/* 
 * File:   normalize.c
 * Author: ����ɺ
 *
 * Created on 2010��11��26��, ����9:02
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<assert.h>
#include "..\..\datastructure\redblacktree.h"
#include "..\..\utility\strstream.h"
#include "..\..\utility\compare.h"
char *intProccess(char *s){/*�������ݴ�����*/
    StrInputStream ssin;/*������������*/
    RBTree *t=creatRBTree(sizeof(int),intGreater);/*t��Ŵ���������*/
    int x;
    initStrInputStream(&ssin,s);
    initStrOutputStream(&ssout,250);
    while(!sisEof(&ssin)){/*��������*/
        readInt(&ssin,&x);
        if(rbSearch(t,&x)==t->nil)/*��xû�г�������t��*/
			rbInsert(t,&x);
    }
	inorderRBWalk(t,putInt);
	clrRBTree(t,NULL);free(t);
    writeString(&ssout,"\n");
    return ssout.begin;
}
char* charProccess(char *s){/*�ַ������ݴ���*/
    StrInputStream ssin;/*������������*/
    RBTree *t=creatRBTree(sizeof(char),charGreater);/*t��Ŵ���������*/
    char x;
    initStrInputStream(&ssin,s);
    initStrOutputStream(&ssout,250);
    while(!sisEof(&ssin)){
        readChar(&ssin,&x);
        if(rbSearch(t,&x)==t->nil)/*��xû�г����ڱ�l��*/
			rbInsert(t,&x);
   }
 	inorderRBWalk(t,putChar);
    writeString(&ssout,"\n");
	clrRBTree(t,NULL);free(t);
    return  ssout.begin;
}
char* doubleProccess(char *s){/*���������ݴ���*/
    StrInputStream ssin;/*������������*/
    RBTree *t=creatRBTree(sizeof(double),doubleGreater);/*t��Ŵ���������*/
    double x;
    initStrInputStream(&ssin,s);
    initStrOutputStream(&ssout,250);
    while(!sisEof(&ssin)){
        readDouble(&ssin,&x);
        if(rbSearch(t,&x)==t->nil)/*��xû�г����ڱ�l��*/
			rbInsert(t,&x);
   }
 	inorderRBWalk(t,putDouble);
	clrRBTree(t,NULL);free(t);
    writeString(&ssout,"\n");
    return  ssout.begin;
}
char* stringProccess(char *s){/*�ַ��������ݴ���*/
    StrInputStream ssin;/*������������*/
    RBTree *t=creatRBTree(40,strcmp);/*t��Ŵ���������*/
    char x[20];
    initStrInputStream(&ssin,s);
    initStrOutputStream(&ssout,250);
    while(!sisEof(&ssin)){/*��һ��ȡ��������*/
        readString(&ssin,x);
        if(rbSearch(t,&x)==t->nil)/*��xû�г����ڱ�l��*/
			rbInsert(t,x);
    }
 	inorderRBWalk(t,putString);
	clrRBTree(t,NULL);free(t);
    writeString(&ssout,"\n");
    return  ssout.begin;
}
char* proccess(char type,char* s){/*��type��ʾ���������ʹ���洢��s�е�����*/
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
	assert((inputfile=fopen("chap02/normalize/inputdata.txt","r"))!=NULL);/*�����������ļ�*/
    assert((outputfile=fopen("chap02/normalize/outputdata.txt","w"))!=NULL);/*����������ļ�*/
    while(!feof(inputfile)){/*������������*/
        char type,*t;
        fgets(s,250,inputfile);/*���ж�ȡһ��s*/
		type=*s;
        t=proccess(type,s+2);
        fputs(t,outputfile);/*������õ�������Ϊһ��д������ļ�*/
    }
    fclose(inputfile);fclose(outputfile);/*�ر������ļ�*/
    return (EXIT_SUCCESS);
}
