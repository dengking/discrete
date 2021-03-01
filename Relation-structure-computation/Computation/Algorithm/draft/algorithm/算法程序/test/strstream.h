#ifndef _STRSTREAM_H
#define	_STRSTREAM_H

typedef struct{
	char* begin;/*�������׵�ַ*/
	char* current;/*��������ǰ��ȡλ��*/
}StrInputStream;/*��������*/
void initStrInputStream(StrInputStream*, char*);/*��ʼ��������*/
int sisEof(StrInputStream*);/*����������Ƿ����*/
int readInt(StrInputStream*, int*);/*���������ж�ȡ����*/
int readLong(StrInputStream*, long*);/*���������ж�ȡ����*/
int readLongLong(StrInputStream*, long long*);/*���������ж�ȡ����*/
int readDouble(StrInputStream*, double*);/*���������ж�ȡ˫���ȸ�����*/
int readChar(StrInputStream*, char*);/*���������ж�ȡ�ַ�*/
int readString(StrInputStream*, char*);/*���������ж�ȡ�ַ���*/
void sisRewind(StrInputStream*);/*��������ԭ��ʼ����*/
/*
˵����
1.���ǿ���Ӧ��gets�Ӽ����Ͻ���һ���ı���������δӸ��ı�����ȡ��Ϣ�أ�
���ǿ���Ӧ�ÿ⺯��sscanf���ı�������ʽ����������ַ�������ı����н��ܶԸ���������ָ����ʽ�����ͣ������ݡ�
sscanf��һ���ı��������Ͷ�ȡ������ݱ���һ���Դ���ָ�������ı�����ַ������ͨ��ÿ�ζ�ȡһ�������ѭ���ظ���ʵ�֡�
��Ϊÿ���ظ���sscanf�������ı������׵�ַ��ʼ��ȡ���ݡ�
�����ʱ�����ܲ���֪����Ҫ���ı����ж�ȡ���ٸ����ݡ���ˣ���Ҫ��sscanf��һ����չ��

*/
typedef struct{
	char* begin;/*������׵�ַ*/
	char* current;/*�������ǰ��ȡλ��*/
	int length;/*���������*/
}StrOutputStream;/*�������*/
void initStrOutputStream(StrOutputStream*, int);/*��ʼ�������*/
void freeStrOutputStream(StrOutputStream*);
int sosFull(StrOutputStream*);/*��������*/
int writeInt(StrOutputStream*, int);/**/
int writeDouble(StrOutputStream*, double);/**/
int writeChar(StrOutputStream*, char);/**/
int writeString(StrOutputStream*, char*);/**/
void sosRewind(StrOutputStream*);/*�������ԭ��ʼ����*/
void putInt(int*);/**/
void putChar(char*);/**/
void putDouble(double*);/**/
void putString(char*);/**/
StrOutputStream ssout;/*ȫ�ִ����������*/
#endif	/* _STRSTREAM_H */