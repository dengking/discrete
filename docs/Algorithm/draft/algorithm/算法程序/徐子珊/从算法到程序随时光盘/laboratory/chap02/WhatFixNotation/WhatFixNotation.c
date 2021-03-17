#include<string.h>
#include<assert.h>
#include "../../datastructure/binarytree.h"
#include "../../utility/strstream.h"
#include "../../utility/output.h"
char operators[]="$*/+-&|!";
StrOutputStream sout;
BTreeNode *restorTree(StrInputStream* sin){
	char item[10];
	BTreeNode  *left, *right;
	readString(sin,item);
	if(strstr(operators,item)){
		if(item[0]=='!')
			left=NULL;
		else
			left=restorTree(sin);
		right=restorTree(sin);
	}else
		left=right=NULL;
	return creatBTree(item, 10, left, right);
}
void ptorderTreeWalk(BTreeNode *r){
	if(!r)
		return;
	ptorderTreeWalk(r->left);
	ptorderTreeWalk(r->right);
	writeString(&sout,(char*)r->key);
}
int main(){
	FILE *f1, *f2;
	char s1[80],s2[80];
	StrInputStream sin;
	BTreeNode *root;
	initStrOutputStream(&sout,80);
	assert((f1=fopen("chap02/WhatFixNotation/inputdata.txt","r")));
	assert((f2=fopen("chap02/WhatFixNotation/outputdata.txt","w")));
	fgets(s1,80,f1);
	fgets(s2,80,f1);
	fprintf(f2,"%s%s","INFIX   =>",s1);
	fprintf(f2,"%s%s","PREFIX  =>",s2);
	initStrInputStream(&sin, s2);
	root=restorTree(&sin);
	ptorderTreeWalk(root);
	fprintf(f2,"%s%s","POSTFIX =>",sout.begin);
	fputc('\n',f2);
	freeStrOutputStream(&sout);
	fclose(f1);
	fclose(f2);
	clrBTree(root, NULL);
	return 0;
}
