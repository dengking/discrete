#include "./strstream.h"
#include<stdlib.h>
#include <stdio.h>
#include<string.h>
void initStrInputStream(StrInputStream* ssin, char* s){/*初始化输入流*/
	while (*s == ' ' || *s == '\t')/*掠过空格*/
		s++;
	ssin->begin = ssin->current = s;
}
int readInt(StrInputStream* ssin, int* x){
	char s[80];
	int n;
	while (*(ssin->current) == ' ' || *(ssin->current) == '\t')/*掠过空格*/
		(ssin->current)++;
	sscanf(ssin->current, "%s", s);/*从当前位置读取数据项*/
	n = strlen(s);
	if (!n)/*未读到数据*/
		return 0;
	ssin->current += n;/*读到数据，调整读取位置*/
	*x = atoi(s);/*将数据转换成整数*/
	return 1;
}
int readDouble(StrInputStream* ssin, double* x){
	char s[80];
	int n;
	while (*(ssin->current) == ' ' || *(ssin->current) == '\t')/**/
		(ssin->current)++;
	sscanf(ssin->current, "%s", s);/**/
	n = strlen(s);
	if (!n)/**/
		return 0;
	ssin->current += n;/**/
	*x = atof(s);/**/
	return 1;
}
int readChar(StrInputStream* ssin, char* x){
	char s[80];
	int n;
	while (*(ssin->current) == ' ' || *(ssin->current) == '\t')/**/
		(ssin->current)++;
	sscanf(ssin->current, "%s", s);/**/
	n = strlen(s);
	if (n != 1)/**/
		return 0;
	ssin->current += n;/**/
	*x = s[0];
	return 1;
}
int readString(StrInputStream* ssin, char* x){
	int n;
	while (*(ssin->current) == ' ' || *(ssin->current) == '\t')/**/
		(ssin->current)++;
	sscanf(ssin->current, "%s", x);/**/
	n = strlen(x);
	if (!n)/**/
		return 0;
	ssin->current += n;/**/
	return 1;
}
int sisEof(StrInputStream* ssin){/**/
	return (strlen(ssin->current) == 0) || (*(ssin->current) == '\r' || (*(ssin->current) == '\n'));
}
void sisRewind(StrInputStream* ssin){
	ssin->current = ssin->begin;
}
int sosEof(StrOutputStream* sout){/**/
	return sout->current - sout->begin >= sout->length;
}
void initStrOutputStream(StrOutputStream* sout, int size){/**/
	if (sout->begin = (char*)malloc(size*sizeof(char))){/*分配串输出流空间*/
		sout->length = size;
		memset(sout->begin, 0, size*sizeof(char));
		sout->current = sout->begin;
	}
}
int writeInt(StrOutputStream* sout, int x){/**/
	if (sosEof(sout))/**/
		return 0;
	if (sout->current == sout->begin)/*����ͷ*/
		sprintf(sout->current, "%d", x);
	else
		sprintf(sout->current, "%c%d", ' ', x);
	sout->current += strlen(sout->current);/**/
	return 1;
}
int writeDouble(StrOutputStream* sout, double x){/**/
	if (sosEof(sout))/**/
		return 0;
	if (sout->current == sout->begin)/*����ͷ*/
		sprintf(sout->current, "%f", x);
	else
		sprintf(sout->current, "%c%f", ' ', x);
	sout->current += strlen(sout->current);/**/
	return 1;
}
int writeChar(StrOutputStream* sout, char x){/**/
	if (sosEof(sout))/**/
		return 0;
	if (sout->current == sout->begin)/*����ͷ*/
		sprintf(sout->current, "%c", x);
	else
		sprintf(sout->current, "%c%c", ' ', x);
	sout->current += strlen(sout->current);/**/
	return 1;
}
int writeString(StrOutputStream* sout, char *s){
	if (sosEof(sout))
		return 0;
	if (sout->current == sout->begin)
		sprintf(sout->current, "%s", s);
	else
		sprintf(sout->current, "%c%s", ' ', s);
	sout->current += strlen(sout->current);
	return 1;
}
void freeStrOutputStream(StrOutputStream* sout){/*�ͷ����ռ�*/
	sout->length = 0;
	sout->current = NULL;
	if (sout->begin)
		free(sout->begin);
}
void sosRewind(StrOutputStream* sout){
	sout->current = sout->begin;
}
void putInt(int *data){
	writeInt(&ssout, *data);
}
void putChar(char *data){
	writeChar(&ssout, *data);
}
void putDouble(double *data){
	writeDouble(&ssout, *data);
}
void putString(char *data){
	writeString(&ssout, data);
}
