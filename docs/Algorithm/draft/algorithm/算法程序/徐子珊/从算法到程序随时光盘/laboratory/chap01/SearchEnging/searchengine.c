/*��C�����ж������ļ�ָ������FILE,��������ʹ�õ�ÿһ���ļ��������Ӧһ��FILE���͵�ָ�������
fopen(�ļ���������ģʽ��������дģʽ��ָ���ļ��������ļ�ָ��
feof(�ļ�ָ�룩����ļ���дָ���Ƿ�ָ���ļ�β
fgetc(�ļ�ָ�룩��ָ���ļ��ĵ�ǰλ�ö�ȡһ���ַ������䷵��
fputc���ַ����ʽ���ļ�ָ�룩���ַ����ʽ��ֵд��ָ���ļ���ǰ��дλ�ô�
fgets(�ַ����飬�г��ȣ��ļ�ָ�룩��ָ���ļ��ĵ�ǰ��дλ�ÿ�ʼ��ȡһ��������ָ�����ȵ��ı��е�ָ���ַ�������
fputs(�ı��У��ļ�ָ�룩��ָ���ı���д��ָ���ļ��ĵ�ǰ��дλ�ô�
fscanf(�ļ�ָ�룬��ʽ����������ַ����ָ���ļ��а�ָ����ʽ��ȡ���ݵ�ָ��������ַ
fprintf���ļ�ָ�룬��ʽ�������ʽ����ָ�����ʽ��ָ����ʽд��ָ���ļ���
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
    fgets(first,80,f1);/*������1����������ĵ�1��*/
    while(!feof(f1)){/*ֻҪ������*/
		int i;
        StrInputStream sin;
		char type, second[250];
        initStrInputStream(&sin,first);/*����������ĵ�1�д���һ������*/
        readChar(&sin,&type);/*��ȡ�����е�������Ϣ*/
        switch(type){
            case 'i':{/*��������Ϊ����*/
                int key,a[80],n=0;
                readInt(&sin,&key);/*��ȡ�ؼ�ֵ*/
                fgets(second,80,f1);
                initStrInputStream(&sin,second);/*Ϊ�������ݴ�����������*/
                while(!sisEof(&sin))
                    readInt(&sin,&a[n++]);/*�����ж�ȡ��������*/
                i=linearSearch(a,sizeof(int),n,&key,intGreater);
                break;
            }
            case 'f':{/*��������Ϊ������*/
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
            case 'c':{/*��������Ϊ�ַ�*/
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
            case 's':{/*��������Ϊ�ַ���*/
				char *key,*a[80];
                int n=0, j;
				key=(char*)malloc(80*sizeof(char));/*Ϊkey����ռ�*/
                for(j=0;j<80;j++)/*Ϊ����a��Ԫ�ط���ռ�*/
                    a[j]=(char*)malloc(80*sizeof(char));
                readString(&sin,key);/*��ȡ�ؼ�ֵ*/
                fgets(second,80,f1);
                initStrInputStream(&sin,second);
                while(!sisEof(&sin)){
                    readString(&sin,a[n++]);
                }
                i=linearSearch(a,sizeof(char*),n,key,strcmp);
                free(key);/*�ͷ�keyָ���Ŀռ�*/
                for(j=0;j<80;j++)
                    free(a[j]);
            }
        }
        if(i>-1)/*������*/
            fprintf(f2,"%d\n",i);
        else
            fprintf(f2,"not found!\r\n");
        fgets(first,80,f1);/*��ȡ��һ����������ĵ�1��*/
    }
	fclose(f1);/*�ر��ļ�ָ��ָ����ļ�*/
    fclose(f2);
    return (EXIT_SUCCESS);
}
