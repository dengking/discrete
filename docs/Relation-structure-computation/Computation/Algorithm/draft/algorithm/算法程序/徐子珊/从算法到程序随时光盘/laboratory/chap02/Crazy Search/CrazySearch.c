#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "../../datastructure/hashtable.h"
int cracySearch(char *s,int n, int nc){
    int i,j,len=strlen(s),v=0,result;
    int b[256]={0};
	HashTable *h;
    i=0;
    while(*(s+i)!='\0'){/*确定组成串s的字符*/
        b[*(s+i)]=1;
        i++;
    }
    for(i=0;i<256;i++)/*对组成串s的各字符确定编码值*/
        if(b[i])
            b[i]=v++;
    h=createTable((int)((len-n)*0.75));
    for(i=0;i<=len-n;i++){
        int key=0;
        for(j=0;j<n;j++)/*计算子串的关键值*/
            key=key*nc+b[*(s+i+j)];
        hashInsert(h,key);
    }
    result=h->n;/*不同的子串数*/
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
