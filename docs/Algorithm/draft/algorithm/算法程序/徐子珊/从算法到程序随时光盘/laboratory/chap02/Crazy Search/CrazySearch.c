#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "../../datastructure/hashtable.h"
int cracySearch(char *s,int n, int nc){
    int i,j,len=strlen(s),v=0,result;
    int b[256]={0};
	HashTable *h;
    i=0;
    while(*(s+i)!='\0'){/*ȷ����ɴ�s���ַ�*/
        b[*(s+i)]=1;
        i++;
    }
    for(i=0;i<256;i++)/*����ɴ�s�ĸ��ַ�ȷ������ֵ*/
        if(b[i])
            b[i]=v++;
    h=createTable((int)((len-n)*0.75));
    for(i=0;i<=len-n;i++){
        int key=0;
        for(j=0;j<n;j++)/*�����Ӵ��Ĺؼ�ֵ*/
            key=key*nc+b[*(s+i+j)];
        hashInsert(h,key);
    }
    result=h->n;/*��ͬ���Ӵ���*/
    clrTable(h);
    free(h);
    return result;
}
int main(){
	FILE *f1, *f2;
    char text[800];
	int n,nc;
	assert((f1=fopen("chap02/Crazy Search/inputdata.txt","r")));
	assert((f2=fopen("chap02/Crazy Search/outputdata.txt","w")));
	fscanf(f1,"%d %d",&n, &nc);
	fscanf(f1,"%s",text);
    fprintf(f2,"%d\n",cracySearch(text,n,nc));
	fclose(f1);
	fclose(f2);
    return 0;
}
