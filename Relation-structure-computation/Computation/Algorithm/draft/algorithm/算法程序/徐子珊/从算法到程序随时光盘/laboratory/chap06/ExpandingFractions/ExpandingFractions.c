#include <stdio.h>
#include <assert.h>
#include "..\..\datastructure\list.h"
typedef struct{/*用来表示各次商后余数的数据项类型*/
	int u;
	int index;
}Item;
int comp(Item *a, Item *b){/*用来在余数项链表中查找时的比较规则*/
	return a->u-b->u;
}
int place(int n, int d){/*计算商中的前导0个数*/
	int p=-1;
	do{
		p++;
		n*=10;
	}while(n<d);
	return p;
}
int quotien(int *u, int d){/*计算1位商，余数由u带回*/
	int v=*u/d;
	*u=*u-v*d;
	*u*=10;
	return v;
}

int main(){
	int n, d;/*分子、分母*/
	FILE *f1=fopen("chap06/ExpandingFractions/inputdata.txt","r"), 
		*f2=fopen("chap06/ExpandingFractions/outputdata.txt","w");
	assert(f1&&f2);
	fscanf(f1, "%d %d",&n, &d);/*读取案例的分子、分母*/
	while(d*n){/*d, n全不为0*/
		int x=place(n,d),p=x+1,q=0,i=0,u=n;/**/
		LinkedList *quot=createList(sizeof(int),NULL);/*存放商的各位数字*/
		LinkedList *remainder=createList(sizeof(Item),comp);/*存放各次余数项*/
		ListNode *digt, *remi;/*访问商中各位数字，各次余数项的指针*/
		Item item;
		while(p){/*放大被除数直至够除为止*/
			u*=10;
			p--;
		}
		item.u=u;item.index=i;/*记录首次余数（被除数）*/
		listPushBack(remainder, &item);
		do{/*逐位计算商*/
			q=quotien(&u, d);/*计算商的当前位q，余数由u带回*/
			listPushBack(quot,&q);/*将q插入商*/
			item.u=u;item.index=++i;/*记录本次余数*/
			if((u==0)||(remi=listSearch(remainder,&item))!=remainder->nil)/*被整除或遇到重复余数*/
				break;
			listPushBack(remainder,&item);/*存储本次余数*/
			while(u<d){/*放大下次被除数，直至够除为止*/
				int q=0;
				listPushBack(quot,&q);
				u*=10;++i;
			}
		}while(1);
		fprintf(f2,".");/*输出小数点*/
		p=x;
		while(p){/*输出商的前导0*/
			fprintf(f2, "0");
			p--;
		}
		digt=quot->nil->next;/*从商的最高非0位起逐位输出*/
		while(digt!=quot->nil){
			fprintf(f2, "%d", *((int*)(digt->key)));
			digt=digt->next;
		}
		if(u)/*余数u非0，无限循环*/
			fprintf(f2, "\nThe last %d digits repeat forever.\n", i-((Item*)(remi->key))->index);
		else/*整除*/
			fprintf(f2, "\nThis expansion terminates.\n");
		clrList(quot,NULL);free(quot);/*清理链表空间*/
		clrList(remainder,NULL);free(remainder);
		fscanf(f1, "%d %d",&n, &d);/*读取下一个案例数据*/
	}
	fclose(f1);fclose(f2);
	return 0;
}