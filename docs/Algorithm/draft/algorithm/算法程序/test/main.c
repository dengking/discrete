#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include "strstream.h"
#include "compare.h"
#include "search.h"
int main(int argc, char** argv) {
	char first[80];
	FILE *f1 = fopen("chap01/SearchEnging/inputdata.txt", "r"),
		*f2 = fopen("chap01/SearchEnging/outputdata.txt", "w");
	assert(f1&&f2);
	fgets(first, 80, f1);/*读出第1个搜索任务的第1行*/
	while (!feof(f1)){/*只要有任务*/
		int i;
		StrInputStream sin;
		char type, second[250];
		initStrInputStream(&sin, first);/*用搜索任务的第1行创建一个串流*/
		readChar(&sin, &type);/*读取串流中的类型信息*/
		switch (type){
		case 'i':{/*数据类型为整数*/
					 int key, a[80], n = 0;
					 readInt(&sin, &key);/*读取关键值*/
					 fgets(second, 80, f1);
					 initStrInputStream(&sin, second);/*为搜索数据创建串输入流*/
					 while (!sisEof(&sin))
						 readInt(&sin, &a[n++]);/*从流中读取整型数据*/
					 i = linearSearch(a, sizeof(int), n, &key, intGreater);
					 break;
		}
		case 'f':{/*数据类型为浮点数*/
					 double key, a[80];
					 int n = 0;
					 readDouble(&sin, &key);
					 fgets(second, 80, f1);
					 initStrInputStream(&sin, second);
					 while (!sisEof(&sin))
						 readDouble(&sin, &a[n++]);
					 i = linearSearch(a, sizeof(double), n, &key, doubleGreater);
					 break;
		}
		case 'c':{/*数据类型为字符*/
					 char key, a[80];
					 int n = 0;
					 readChar(&sin, &key);
					 fgets(second, 80, f1);
					 initStrInputStream(&sin, second);
					 while (!sisEof(&sin))
						 readChar(&sin, &a[n++]);
					 i = linearSearch(a, sizeof(char), n, &key, charGreater);
					 break;
		}
		case 's':{/*数据类型为字符串*/
					 char *key, *a[80];
					 int n = 0, j;
					 key = (char*)malloc(80 * sizeof(char));/*为key分配空间*/
					 for (j = 0; j<80; j++)/*为数组a中元素分配空间*/
						 a[j] = (char*)malloc(80 * sizeof(char));
					 readString(&sin, key);/*读取关键值*/
					 fgets(second, 80, f1);
					 initStrInputStream(&sin, second);
					 while (!sisEof(&sin)){
						 readString(&sin, a[n++]);
					 }
					 i = linearSearch(a, sizeof(char*), n, key, strcmp);
					 free(key);/*释放key指引的空间*/
					 for (j = 0; j<80; j++)
						 free(a[j]);
		}
		}
		if (i>-1)/*搜索到*/
			fprintf(f2, "%d\n", i);
		else
			fprintf(f2, "not found!\r\n");
		fgets(first, 80, f1);/*读取下一个搜索任务的第1行*/
	}
	fclose(f1);
	fclose(f2);
	return (EXIT_SUCCESS);
}
