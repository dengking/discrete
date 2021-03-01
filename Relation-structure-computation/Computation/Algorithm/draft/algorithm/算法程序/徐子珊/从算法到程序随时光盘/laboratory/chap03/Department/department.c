#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include "../../datastructure/pqueue.h"
#include "../../datastructure/list.h"
typedef struct{/*��������*/
	int floor;/*¥��*/
	int number;/*����*/
}Room;
typedef struct{/*�¼�����*/
	char code;/*����Ա����*/
	int type;/*�¼�����*/
	Room from;/*��㷿��*/
	Room to;/*�յ㷿��*/
	int begin;/*��ʼʱ��*/
	int lenth;/*����ʱ��*/
}Event;
PQueue *queues[11][11];/*�����뷿��ȴ�����*/
LinkedList *schedules[26];/*������Ա���г̱�*/
FILE *f1, *f2;/*��������ļ�*/
int compare(ListNode **node1,ListNode **node2){/*�ȴ��������¼��ıȽϹ���*/
	Event *e1=(*node1)->key, *e2=(*node2)->key;/*��������������¼�*/
	if(e1->begin<e2->begin)/*e1�Ŀ�ʼʱ���С*/
		return 1;
	if(e1->begin==e2->begin)/*��ʼʱ�����*/
		return e2->code-e1->code;
	return -1;
}
ListNode *mini(int *row, int *col){/*���㲢���ظ��ȴ����ж����е���С��*/
	Event e={'a',-1,{0,0},{0,0},INT_MAX,0};/*������������ڵ�������¼�*/
	ListNode n={&e,NULL,NULL},*x=&n;
	int i,j;
	for(*row=0,i=1;i<11;i++)
		for(j=0;j<11;j++)
			if(queues[i][j]&&!empty(queues[i][j])&&compare(top(queues[i][j]),&x)>0){/*queues[i][j]�Ķ���С��x*/
				x=*(ListNode**)(top(queues[i][j]));
				*row=i;
				*col=j;
			}
	if(*row)/*��Ч����Сֵ*/
		return x;
	return NULL;/*queues�����еĶ��о�Ϊ��*/
}
void printEvent(Event *e){/*����¼�*/
	int hour,minute,second,t=e->begin;
	if(e->lenth==0)/*����ʱ��Ϊ0*/
		return;
	hour=t/3600;t=t%3600;minute=t/60;second=t%60;
	printf("%02d:%02d:%02d ",hour,minute,second);
	fprintf(f2,"%02d:%02d:%02d ",hour,minute,second);/*��hh:mm:ss��ʽ�����ʼʱ��*/
	t=e->begin+e->lenth;
	hour=t/3600;t=t%3600;minute=t/60;second=t%60;
	printf("%02d:%02d:%02d ",hour,minute,second);
	fprintf(f2,"%02d:%02d:%02d ",hour,minute,second);/*��hh:mm:ss��ʽ������ʱ��*/
	switch(e->type){/*���¼�������������Ϣ*/
		case 0: printf("Entry\n");
			fprintf(f2,"Entry\n");
			break;
		case 1:printf("Waiting in elevator queue\n");
			fprintf(f2,"Waiting in elevator queue\n");
			break;
		case 2:printf("Waiting in front of room %02d%02d\n",e->from.floor,e->from.number);
			fprintf(f2,"Waiting in front of room %02d%02d\n",e->from.floor,e->from.number);
			break;
		case 3:printf("Transfer from room %02d%02d to room %02d%02d\n",e->from.floor,e->from.number,e->to.floor,e->to.number);
			fprintf(f2,"Transfer from room %02d%02d to room %02d%02d\n",e->from.floor,e->from.number,e->to.floor,e->to.number);
			break;
		case 4:printf("Transfer from elevator to room %02d%02d\n",e->to.floor,e->to.number);
			fprintf(f2,"Transfer from elevator to room %02d%02d\n",e->to.floor,e->to.number);
			break;
		case 5:printf("Transfer from  room %02d%02d to elevator\n",e->from.floor,e->from.number);
			fprintf(f2,"Transfer from  room %02d%02d to elevator\n",e->from.floor,e->from.number);
			break;
		case 6:printf("Stay in room %02d%02d\n",e->from.floor,e->from.number);
			fprintf(f2,"Stay in room %02d%02d\n",e->from.floor,e->from.number);
			break;
		case 7:printf("Stay in elevator\n");
			fprintf(f2,"Stay in elevator\n");
			break;
		case 8:printf("Exit\n");fprintf(f2,"Exit\n");
	}
}
int entry(char code, int begin){/*�����¥*/
	Event e={code, 0, {0,0},{0,0},begin,30};
	schedules[code-'A']=createList(sizeof(Event),NULL);
	listPushBack(schedules[code-'A'],&e);
	return e.begin+e.lenth;
}
int waitElevator(char code, int begin, int floor){/*�ȴ�����*/
	Event e={code, 1, {floor,0},{floor,0},begin,begin%5?5-begin%5:0};
	ListNode *tail;
	listPushBack(schedules[code-'A'],&e);
	if(queues[floor][0]==NULL)
		queues[floor][0]=initPQueue(sizeof(ListNode*),26,compare);
	tail=(schedules[code-'A']->nil->prev);
	enQueue(queues[floor][0],&tail);
	return e.begin+e.lenth;
}
int waitFrontRoom(char code, int begin, Room room){/*�ڷ�ǰ�ȴ�*/
	Event e={code, 2, {room.floor, room.number},{room.floor,room.number},begin, 0};
	ListNode *tail;	
	listPushBack(schedules[code-'A'],&e);
	if(queues[room.floor][room.number]==NULL)
		queues[room.floor][room.number]=initPQueue(sizeof(ListNode*),26,compare);
	tail=(schedules[code-'A']->nil->prev);
	enQueue(queues[room.floor][room.number],&tail);
	return e.begin+e.lenth;
}
int roomToRoom(char code, int begin, Room from, Room to){/*�ӷ����ߵ�����*/
	Event e={code, 3, {from.floor,from.number}, {to.floor,to.number}, begin, 10};
	listPushBack(schedules[code-'A'],&e);
	return e.begin+e.lenth;
}
int elevatorToRoom(char code, int begin, Room to){/*�ӵ����ߵ�����*/
	Event e={code,4,{to.floor,0},{to.floor,to.number},begin,10};
	listPushBack(schedules[code-'A'],&e);
	return e.begin+e.lenth;
}
int roomToElevator(char code, int begin, Room from){/*�ӷ����ߵ�����*/
	Event e={code,5,{from.floor,from.number},{from.floor, 0},begin,10};
	listPushBack(schedules[code-'A'],&e);
	return e.begin+e.lenth;
}
int inRoom(char code, int begin, int lenth, Room room){/*���ڷ���*/
	Event e={code,6,{room.floor,room.number},{room.floor,room.number},begin,lenth};
	listPushBack(schedules[code-'A'],&e);
	return e.begin+e.lenth;
}
int inElevator(char code, int begin, int floor1, int floor2){/*��������*/
	Event e={code,7,{floor1,0},{floor2,0},begin,abs(floor1-floor2)*30};
	listPushBack(schedules[code-'A'],&e);
	return e.begin+e.lenth;
}
void Exit(char code, int begin, Room from){/*�뿪��¥*/
	Event e={code, 8, {from.floor,from.number},{0,0},0,30};
	if(from.floor>1){/*����1¥*/
		begin= roomToElevator(code,begin,from);
		begin=waitElevator(code,begin,from.floor);
		begin=inElevator(code,begin,from.floor,1);
	}
	e.begin=begin;
	listPushBack(schedules[code-'A'],&e);
}
int toRoom(char code, int begin, int lenth, Room from, Room to){/*����һ���г�����*/
	if(from.floor==to.floor){/*������յ���ͬ��*/
		if(from.number!=0)
			begin=roomToRoom(code,begin,from,to);
	}else{/*����ͬ��*/
		if(from.number!=0)/*���Ǹս���¥*/
			begin=roomToElevator(code,begin,from);
		begin=waitElevator(code,begin,from.floor);
		begin=inElevator(code,begin,from.floor,to.floor);
		begin=elevatorToRoom(code, begin, to);
	}
	begin=waitFrontRoom(code,begin,to);
	return inRoom(code,begin,lenth,to);
}
void initSchedules(){
	char code,room[5],floor[3];
	int hour,minute,second,length,begin;
	Room from, to;
	fscanf(f1,"%c %d:%d:%d", &code,&hour,&minute,&second);/*��������Ա���뼰������¥��ʱ��*/
	while(code!='.'){
		begin=hour*3600+minute*60+second;/*���㿪ʼʱ��*/
		begin=entry(code,begin);/*���������г̱��м�������¥�¼�*/
		from.floor=1,from.number=0;
		fscanf(f1,"%s %d", room,&length);/*���������Ա��һ���г�����*/
		to.floor=atoi(strncpy(floor,room,2));/*����Ŀ�귿��¥��*/
		to.number=atoi(strncpy(floor,room+2,2));/*����Ŀ�귿�����*/
		while(strlen(room)>1){
			begin=toRoom(code,begin,length,from,to);/*���г̱�����ӵ��ﲢ����Ŀ�귿��ĸ��¼�*/
			from=to;/*������һ����ʼ�ص�*/
			fscanf(f1,"%s %d", room,&length);/*��ȡ��һ���г�����*/
			to.floor=atoi(strncpy(floor,room,2));
			to.number=atoi(strncpy(floor,room+2,2));
		}
		Exit(code,begin,from);/*������Ա�뿪��¥*/
		fscanf(f1,"%c %d:%d:%d", &code,&hour,&minute,&second);/*��ȡ��һ������Ա�Ĵ��뼰������¥��ʱ��*/
	}
}
void printSchedules(){
	int i;
	for(i=0;i<26;i++)
		if(schedules[i]){
			printf("%c\n",'A'+i);
			fprintf(f2,"%c\n",'A'+i);
			listTraverse(schedules[i],printEvent);
			printf("\n");
			fprintf(f2,"\n");
			clrList(schedules[i], NULL);
			free(schedules[i]);
		}
}
void processSchedules(){/*�����г̱�*/
	ListNode *workMatrix[11][11]={NULL};/*��������*/
	int i,j;
	ListNode *x;
	while(x=mini(&i,&j)){
		if(workMatrix[i][j]){/*���ǵ�һ�γ���*/
			int flag=0;/*ά��ʱ�������־����ʼ��Ϊfalse*/
			char code=((Event*)(x->key))->code;/*ȷ������Ա*/
			ListNode *p=x, *q=workMatrix[i][j];
			if(((Event*)(x->key))->type==1){/*���ݵȴ�����*/
				Event *e1=p->key, *e2=q->key;
				if(e1->begin==e2->begin){
					e1->lenth=e2->lenth+5;
					flag=1;
				}
			}
			if(((Event*)(x->key))->type==2){/*�ǽ��뷿��ȴ�����*/
				Event *e1=p->key, *e2=q->next->key;
				int t1=e1->begin+e1->lenth,/*�����б����¼����ʱ��*/
					t2=e2->begin+e2->lenth;/*�ϴ��¼����ʱ��*/
				if(t1<t2){
					e1->lenth+=t2-t1;
					flag=1;
				}
			}
			if(flag){/*���˵���*/
				Event *e=p->key;
				int begin=e->begin+e->lenth;/*�����¼����ʱ��*/
				for(p=p->next,e=p->key;p!=schedules[code-'A']->nil;p=p->next,e=p->key){/*���г̱����Ժ��¼�ɨ��*/
					e->begin=begin;/*�޸Ŀ�ʼʱ��*/
					if(e->type==1){/*�ǵȴ������¼�*/
						int t=begin%5;
						e->lenth=t?5-t:0;
					}
					begin=e->begin+e->lenth;
					if(e->type==1||e->type==2)/*�ǵȴ��¼�*/
						fix(queues[e->to.floor][e->to.number]);/*ά�����ڵȴ�����*/
				}
			}
		}
		workMatrix[i][j]=x;
		deQueue(queues[i][j]);
	}
}
void freeQueues(){
	int i,j;
	for(i=0;i<11;i++)
		for(j=0;j<11;j++)
			if(queues[i][j])
				free(queues[i][j]);
}
int main(){
	assert((f1=fopen("chap03/Department/inputdata.txt","r"))&&
		(f2=fopen("chap03/Department/outputdata.txt","w")));
	initSchedules();
	processSchedules();
	printSchedules();
	freeQueues();
	fclose(f1);fclose(f2);
	return 0;
}