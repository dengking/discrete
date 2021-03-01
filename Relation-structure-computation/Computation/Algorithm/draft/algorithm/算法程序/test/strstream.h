#ifndef _STRSTREAM_H
#define	_STRSTREAM_H

typedef struct{
	char* begin;/*输入流首地址*/
	char* current;/*输入流当前读取位置*/
}StrInputStream;/*串输入流*/
void initStrInputStream(StrInputStream*, char*);/*初始化输入流*/
int sisEof(StrInputStream*);/*检测输入流是否结束*/
int readInt(StrInputStream*, int*);/*从输入流中读取整数*/
int readLong(StrInputStream*, long*);/*从输入流中读取整数*/
int readLongLong(StrInputStream*, long long*);/*从输入流中读取整数*/
int readDouble(StrInputStream*, double*);/*从输入流中读取双精度浮点数*/
int readChar(StrInputStream*, char*);/*从输入流中读取字符*/
int readString(StrInputStream*, char*);/*从输入流中读取字符串*/
void sisRewind(StrInputStream*);/*输入流还原初始设置*/
/*
说明：
1.我们可以应用gets从键盘上接收一行文本，但是如何从该文本中提取信息呢？
我们可以应用库函数sscanf（文本串，格式串，变量地址表）：从文本串中接受对各变量输入指定格式（类型）的数据。
sscanf从一个文本串中类型读取多个数据必须一次性传递指定个数的变量地址而不能通过每次读取一个，多次循环重复来实现。
因为每次重复，sscanf都将从文本串的首地址开始读取数据。
而编程时，可能并不知道需要在文本行中读取多少个数据。因此，需要对sscanf做一个拓展。

*/
typedef struct{
	char* begin;/*输出流首地址*/
	char* current;/*输出流当前读取位置*/
	int length;/*输出流长度*/
}StrOutputStream;/*串输出流*/
void initStrOutputStream(StrOutputStream*, int);/*初始化输出流*/
void freeStrOutputStream(StrOutputStream*);
int sosFull(StrOutputStream*);/*检测输出流*/
int writeInt(StrOutputStream*, int);/**/
int writeDouble(StrOutputStream*, double);/**/
int writeChar(StrOutputStream*, char);/**/
int writeString(StrOutputStream*, char*);/**/
void sosRewind(StrOutputStream*);/*输出流还原初始设置*/
void putInt(int*);/**/
void putChar(char*);/**/
void putDouble(double*);/**/
void putString(char*);/**/
StrOutputStream ssout;/*全局串输出流对象*/
#endif	/* _STRSTREAM_H */