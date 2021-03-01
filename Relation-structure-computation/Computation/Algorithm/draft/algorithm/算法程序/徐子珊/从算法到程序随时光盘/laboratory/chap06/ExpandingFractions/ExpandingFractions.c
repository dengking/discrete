#include <stdio.h>
#include <assert.h>
#include "..\..\datastructure\list.h"
typedef struct{/*������ʾ�����̺�����������������*/
	int u;
	int index;
}Item;
int comp(Item *a, Item *b){/*�����������������в���ʱ�ıȽϹ���*/
	return a->u-b->u;
}
int place(int n, int d){/*�������е�ǰ��0����*/
	int p=-1;
	do{
		p++;
		n*=10;
	}while(n<d);
	return p;
}
int quotien(int *u, int d){/*����1λ�̣�������u����*/
	int v=*u/d;
	*u=*u-v*d;
	*u*=10;
	return v;
}

int main(){
	int n, d;/*���ӡ���ĸ*/
	FILE *f1=fopen("chap06/ExpandingFractions/inputdata.txt","r"), 
		*f2=fopen("chap06/ExpandingFractions/outputdata.txt","w");
	assert(f1&&f2);
	fscanf(f1, "%d %d",&n, &d);/*��ȡ�����ķ��ӡ���ĸ*/
	while(d*n){/*d, nȫ��Ϊ0*/
		int x=place(n,d),p=x+1,q=0,i=0,u=n;/**/
		LinkedList *quot=createList(sizeof(int),NULL);/*����̵ĸ�λ����*/
		LinkedList *remainder=createList(sizeof(Item),comp);/*��Ÿ���������*/
		ListNode *digt, *remi;/*�������и�λ���֣������������ָ��*/
		Item item;
		while(p){/*�Ŵ󱻳���ֱ������Ϊֹ*/
			u*=10;
			p--;
		}
		item.u=u;item.index=i;/*��¼�״���������������*/
		listPushBack(remainder, &item);
		do{/*��λ������*/
			q=quotien(&u, d);/*�����̵ĵ�ǰλq��������u����*/
			listPushBack(quot,&q);/*��q������*/
			item.u=u;item.index=++i;/*��¼��������*/
			if((u==0)||(remi=listSearch(remainder,&item))!=remainder->nil)/*�������������ظ�����*/
				break;
			listPushBack(remainder,&item);/*�洢��������*/
			while(u<d){/*�Ŵ��´α�������ֱ������Ϊֹ*/
				int q=0;
				listPushBack(quot,&q);
				u*=10;++i;
			}
		}while(1);
		fprintf(f2,".");/*���С����*/
		p=x;
		while(p){/*����̵�ǰ��0*/
			fprintf(f2, "0");
			p--;
		}
		digt=quot->nil->next;/*���̵���߷�0λ����λ���*/
		while(digt!=quot->nil){
			fprintf(f2, "%d", *((int*)(digt->key)));
			digt=digt->next;
		}
		if(u)/*����u��0������ѭ��*/
			fprintf(f2, "\nThe last %d digits repeat forever.\n", i-((Item*)(remi->key))->index);
		else/*����*/
			fprintf(f2, "\nThis expansion terminates.\n");
		clrList(quot,NULL);free(quot);/*��������ռ�*/
		clrList(remainder,NULL);free(remainder);
		fscanf(f1, "%d %d",&n, &d);/*��ȡ��һ����������*/
	}
	fclose(f1);fclose(f2);
	return 0;
}