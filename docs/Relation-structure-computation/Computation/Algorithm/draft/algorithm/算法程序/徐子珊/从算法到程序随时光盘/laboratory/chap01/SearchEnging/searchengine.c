/*在C语言中定义了文件指针类型FILE,程序中所使用的每一个文件都必须对应一个FILE类型的指针变量。
fopen(文件名串，打开模式串）按读写模式打开指定文件，返回文件指针
feof(文件指针）检测文件读写指针是否指向文件尾
fgetc(文件指针）从指定文件的当前位置读取一个字符并将其返回
fputc（字符表达式，文件指针）将字符表达式的值写到指定文件当前读写位置处
fgets(字符数组，行长度，文件指针）从指定文件的当前读写位置开始读取一个不超过指定长度的文本行到指定字符数组中
fputs(文本行，文件指针）将指定文本行写到指定文件的当前读写位置处
fscanf(文件指针，格式串，变量地址表）从指定文件中按指定格式读取数据到指定变量地址
fprintf（文件指针，格式串，表达式表）将指定表达式按指定格式写到指定文件中
*/

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include "../../utility/strstream.h"
#include "../../utility/compare.h"
#include "../../utility/search.h"
int main(int argc, char** argv) {
    char first[80];
    FILE *f1=fopen("chap01/SearchEnging/inputdata.txt","r"),
		*f2 = fopen("chap01/SearchEnging/outputdata.txt", "w");
    assert(f1&&f2);
    fgets(first,80,f1);/*读出第1个搜索任务的第1行*/
    while(!feof(f1)){/*只要有任务*/
		int i;
        StrInputStream sin;
		char type, second[250];
        initStrInputStream(&sin,first);/*用搜索任务的第1行创建一个串流*/
        readChar(&sin,&type);/*读取串流中的类型信息*/
        switch(type){
            case 'i':{/*数据类型为整数*/
                int key,a[80],n=0;
                readInt(&sin,&key);/*读取关键值*/
                fgets(second,80,f1);
                initStrInputStream(&sin,second);/*为搜索数据创建串输入流*/
                while(!sisEof(&sin))
                    readInt(&sin,&a[n++]);/*从流中读取整型数据*/
                i=linearSearch(a,sizeof(int),n,&key,intGreater);
                break;
            }
            case 'f':{/*数据类型为浮点数*/
				double key,a[80];
                int n=0;
                readDouble(&sin,&key);
                fgets(second,80,f1);
                initStrInputStream(&sin,second);
                while(!sisEof(&sin))
                    readDouble(&sin,&a[n++]);
                i=linearSearch(a,sizeof(double),n,&key,doubleGreater);
                break;
            }
            case 'c':{/*数据类型为字符*/
                char key,a[80];
                int n=0;
                readChar(&sin,&key);
                fgets(second,80,f1);
                initStrInputStream(&sin,second);
                while(!sisEof(&sin))
                    readChar(&sin,&a[n++]);
                i=linearSearch(a,sizeof(char),n,&key,charGreater);
                break;
            }
            case 's':{/*数据类型为字符串*/
				char *key,*a[80];
                int n=0, j;
				key=(char*)malloc(80*sizeof(char));/*为key分配空间*/
                for(j=0;j<80;j++)/*为数组a中元素分配空间*/
                    a[j]=(char*)malloc(80*sizeof(char));
                readString(&sin,key);/*读取关键值*/
                fgets(second,80,f1);
                initStrInputStream(&sin,second);
                while(!sisEof(&sin)){
                    readString(&sin,a[n++]);
                }
                i=linearSearch(a,sizeof(char*),n,key,strcmp);
                free(key);/*释放key指引的空间*/
                for(j=0;j<80;j++)
                    free(a[j]);
            }
        }
        if(i>-1)/*搜索到*/
            fprintf(f2,"%d\n",i);
        else
            fprintf(f2,"not found!\r\n");
        fgets(first,80,f1);/*读取下一个搜索任务的第1行*/
    }
	fclose(f1);/*关闭文件指针指向的文件*/
    fclose(f2);
    return (EXIT_SUCCESS);
}
