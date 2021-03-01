#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
char *decode(char *cipher){
	int n=strlen(cipher),i;
	char *plain=(char*)calloc(n+1, sizeof(char));
	for(i=0;i<n;i++)
		if(cipher[i]<='Z'&&cipher[i]>='A')
			plain[i]=(cipher[i]-'A'+21)%26+'A';/*21��-5����ģ26�ȼ�*/
		else
			plain[i]=cipher[i];
	return plain;
}
int main(){
	char s[201],*t=NULL;
	FILE *f1=fopen("chap06/TheHardestProblemEver/inputdata.txt","r"), 
		*f2=fopen("chap06/TheHardestProblemEver/outputdata.txt","w");
	assert(f1&&f2);
	fgets(s, 200,f1);/*��ȡ����"START"*/
	while(strcmp(s,"ENDOFINPUT")){
		fgets(s, 200,f1);/*��ȡ����*/
		t=decode(s);/*����*/
		fputs(t,f2);
		free(t);
		fgets(s, 200,f1);/*�ӹ���"END"*/
		fgets(s, 200,f1);/*��ȡ��һ��*/
	}
	fclose(f1);fclose(f2);
	return 0;
}