/* 
 * File:   normalize.cpp
 * Author: ����ɺ
 *
 * Created on 2010��11��26��, ����9:02
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<assert.h>
#include "..\..\datastructure\list.h"
#include "..\..\utility\strstream.h"
#include "..\..\utility\compare.h"
char *intProccess(char *s){/*�������ݴ�����*/
    StrInputStream ssin;/*������������*/
    LinkedList *L=createList(sizeof(int),intGreater);/*����L��Ŵ���������*/
    int x;
    initStrInputStream(&ssin,s);
    initStrOutputStream(&ssout,250);
    while(!sisEof(&ssin)){/*��������*/
        readInt(&ssin,&x);
		if(listSearch(L,&x)==L->nil){/*��xû�г����ڱ�L��*/
			ListNode *a = L->nil->next;/*��aָ��L��ͷ*/
			while(a!=L->nil&&*((int*)(a->key))<x)/*�ҵ�����λ��*/
				a=a->next;
			listInsert(L,a,&x);
		}
    }
    listTraverse(L,putInt);
    clrList(L,NULL);
    writeString(&ssout,"\n");
    return ssout.begin;
}
char* charProccess(char *s){/*�ַ������ݴ���*/
    StrInputStream ssin;/*������������*/
    LinkedList *L=createList(sizeof(char),charGreater);/*����L��Ŵ���������*/
    char x;
    initStrInputStream(&ssin,s);
    initStrOutputStream(&ssout,250);
    while(!sisEof(&ssin)){
        readChar(&ssin,&x);
		if(listSearch(L,&x)==L->nil){
			ListNode *a=L->nil->next;
			while(a!=L->nil&&*((char*)(a->key))<x)
				a=a->next;
			listInsert(L,a,&x);
		}
    }
	listTraverse(L,putChar);
	clrList(L,NULL);
    writeString(&ssout,"\n");
    return  ssout.begin;
}
char* doubleProccess(char *s){/*���������ݴ���*/
    StrInputStream ssin;/*������������*/
    LinkedList *L=createList(sizeof(double),doubleGreater);/*����L��Ŵ���������*/
    double x;
    initStrInputStream(&ssin,s);
    initStrOutputStream(&ssout,250);
    while(!sisEof(&ssin)){
        readDouble(&ssin,&x);
		if(listSearch(L,&x)==L->nil){
			ListNode *a=L->nil->next;
			while(a!=L->nil&&*((double*)(a->key))<x)
				a=a->next;
			listInsert(L,a,&x);
		}
    }
	listTraverse(L,putDouble);
	clrList(L,NULL);
    writeString(&ssout,"\n");
    return  ssout.begin;
}
char* stringProccess(char *s){/*�ַ��������ݴ���*/
    StrInputStream ssin;/*������������*/
    LinkedList *L=createList(20,strcmp);/*����L��Ŵ���������*/
    char x[20];
    initStrInputStream(&ssin,s);
    initStrOutputStream(&ssout,250);
    while(!sisEof(&ssin)){/*��һ��ȡ��������*/
        readString(&ssin,x);
		if(listSearch(L,x)==L->nil){
			ListNode *a=L->nil->next;
			while(a!=L->nil&&strcmp((char*)a->key,x)<0)
				a=a->next;
			listInsert(L,a,x);
		}
    }
	listTraverse(L,putString);
	clrList(L,NULL);
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
    FILE *inputfile=fopen("chap02/normalize/inputdata.txt","r"),/*�����������ļ�*/
		*outputfile=fopen("chap02/normalize/outputdata.txt","w");/*����������ļ�*/
    char s[250];
    assert(inputfile&&outputfile);
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
