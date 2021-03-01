#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include "../../datastructure/pqueue.h"
#include "../../datastructure/list.h"
typedef struct{/*房间类型*/
	int floor;/*楼层*/
	int number;/*房号*/
}Room;
typedef struct{/*事件类型*/
	char code;/*特派员代码*/
	int type;/*事件类型*/
	Room from;/*起点房间*/
	Room to;/*终点房间*/
	int begin;/*开始时间*/
	int lenth;/*持续时间*/
}Event;
PQueue *queues[11][11];/*电梯与房间等待队列*/
LinkedList *schedules[26];/*各特派员的行程表*/
FILE *f1, *f2;/*输入输出文件*/
int compare(ListNode **node1,ListNode **node2){/*等待队列中事件的比较规则*/
	Event *e1=(*node1)->key, *e2=(*node2)->key;/*解析出结点所含事件*/
	if(e1->begin<e2->begin)/*e1的开始时间较小*/
		return 1;
	if(e1->begin==e2->begin)/*开始时间相等*/
		return e2->code-e1->code;
	return -1;
}
ListNode *mini(int *row, int *col){/*计算并返回各等待队列队首中的最小者*/
	Event e={'a',-1,{0,0},{0,0},INT_MAX,0};/*用来创建链表节点的特殊事件*/
	ListNode n={&e,NULL,NULL},*x=&n;
	int i,j;
	for(*row=0,i=1;i<11;i++)
		for(j=0;j<11;j++)
			if(queues[i][j]&&!empty(queues[i][j])&&compare(top(queues[i][j]),&x)>0){/*queues[i][j]的队首小于x*/
				x=*(ListNode**)(top(queues[i][j]));
				*row=i;
				*col=j;
			}
	if(*row)/*有效的最小值*/
		return x;
	return NULL;/*queues中所有的队列均为空*/
}
void printEvent(Event *e){/*输出事件*/
	int hour,minute,second,t=e->begin;
	if(e->lenth==0)/*持续时间为0*/
		return;
	hour=t/3600;t=t%3600;minute=t/60;second=t%60;
	printf("%02d:%02d:%02d ",hour,minute,second);
	fprintf(f2,"%02d:%02d:%02d ",hour,minute,second);/*按hh:mm:ss格式输出开始时间*/
	t=e->begin+e->lenth;
	hour=t/3600;t=t%3600;minute=t/60;second=t%60;
	printf("%02d:%02d:%02d ",hour,minute,second);
	fprintf(f2,"%02d:%02d:%02d ",hour,minute,second);/*按hh:mm:ss格式输出完成时间*/
	switch(e->type){/*按事件类型输出相关信息*/
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
int entry(char code, int begin){/*进入大楼*/
	Event e={code, 0, {0,0},{0,0},begin,30};
	schedules[code-'A']=createList(sizeof(Event),NULL);
	listPushBack(schedules[code-'A'],&e);
	return e.begin+e.lenth;
}
int waitElevator(char code, int begin, int floor){/*等待电梯*/
	Event e={code, 1, {floor,0},{floor,0},begin,begin%5?5-begin%5:0};
	ListNode *tail;
	listPushBack(schedules[code-'A'],&e);
	if(queues[floor][0]==NULL)
		queues[floor][0]=initPQueue(sizeof(ListNode*),26,compare);
	tail=(schedules[code-'A']->nil->prev);
	enQueue(queues[floor][0],&tail);
	return e.begin+e.lenth;
}
int waitFrontRoom(char code, int begin, Room room){/*在房前等待*/
	Event e={code, 2, {room.floor, room.number},{room.floor,room.number},begin, 0};
	ListNode *tail;	
	listPushBack(schedules[code-'A'],&e);
	if(queues[room.floor][room.number]==NULL)
		queues[room.floor][room.number]=initPQueue(sizeof(ListNode*),26,compare);
	tail=(schedules[code-'A']->nil->prev);
	enQueue(queues[room.floor][room.number],&tail);
	return e.begin+e.lenth;
}
int roomToRoom(char code, int begin, Room from, Room to){/*从房间走到房间*/
	Event e={code, 3, {from.floor,from.number}, {to.floor,to.number}, begin, 10};
	listPushBack(schedules[code-'A'],&e);
	return e.begin+e.lenth;
}
int elevatorToRoom(char code, int begin, Room to){/*从电梯走到房间*/
	Event e={code,4,{to.floor,0},{to.floor,to.number},begin,10};
	listPushBack(schedules[code-'A'],&e);
	return e.begin+e.lenth;
}
int roomToElevator(char code, int begin, Room from){/*从房间走到电梯*/
	Event e={code,5,{from.floor,from.number},{from.floor, 0},begin,10};
	listPushBack(schedules[code-'A'],&e);
	return e.begin+e.lenth;
}
int inRoom(char code, int begin, int lenth, Room room){/*呆在房间*/
	Event e={code,6,{room.floor,room.number},{room.floor,room.number},begin,lenth};
	listPushBack(schedules[code-'A'],&e);
	return e.begin+e.lenth;
}
int inElevator(char code, int begin, int floor1, int floor2){/*乘坐电梯*/
	Event e={code,7,{floor1,0},{floor2,0},begin,abs(floor1-floor2)*30};
	listPushBack(schedules[code-'A'],&e);
	return e.begin+e.lenth;
}
void Exit(char code, int begin, Room from){/*离开大楼*/
	Event e={code, 8, {from.floor,from.number},{0,0},0,30};
	if(from.floor>1){/*不在1楼*/
		begin= roomToElevator(code,begin,from);
		begin=waitElevator(code,begin,from.floor);
		begin=inElevator(code,begin,from.floor,1);
	}
	e.begin=begin;
	listPushBack(schedules[code-'A'],&e);
}
int toRoom(char code, int begin, int lenth, Room from, Room to){/*处理一项行程数据*/
	if(from.floor==to.floor){/*起点与终点在同层*/
		if(from.number!=0)
			begin=roomToRoom(code,begin,from,to);
	}else{/*不在同层*/
		if(from.number!=0)/*不是刚进大楼*/
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
	fscanf(f1,"%c %d:%d:%d", &code,&hour,&minute,&second);/*读入特派员代码及来到大楼的时间*/
	while(code!='.'){
		begin=hour*3600+minute*60+second;/*换算开始时间*/
		begin=entry(code,begin);/*创建并在行程表中加入进入大楼事件*/
		from.floor=1,from.number=0;
		fscanf(f1,"%s %d", room,&length);/*读入该特派员下一项行程数据*/
		to.floor=atoi(strncpy(floor,room,2));/*解析目标房间楼层*/
		to.number=atoi(strncpy(floor,room+2,2));/*解析目标房间号码*/
		while(strlen(room)>1){
			begin=toRoom(code,begin,length,from,to);/*在行程表中添加到达并进入目标房间的各事件*/
			from=to;/*设置下一项起始地点*/
			fscanf(f1,"%s %d", room,&length);/*读取下一项行程数据*/
			to.floor=atoi(strncpy(floor,room,2));
			to.number=atoi(strncpy(floor,room+2,2));
		}
		Exit(code,begin,from);/*该特派员离开大楼*/
		fscanf(f1,"%c %d:%d:%d", &code,&hour,&minute,&second);/*读取下一个特派员的代码及来到大楼的时间*/
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
void processSchedules(){/*处理行程表*/
	ListNode *workMatrix[11][11]={NULL};/*工作矩阵*/
	int i,j;
	ListNode *x;
	while(x=mini(&i,&j)){
		if(workMatrix[i][j]){/*不是第一次出队*/
			int flag=0;/*维持时间调整标志，初始化为false*/
			char code=((Event*)(x->key))->code;/*确定特派员*/
			ListNode *p=x, *q=workMatrix[i][j];
			if(((Event*)(x->key))->type==1){/*电梯等待队列*/
				Event *e1=p->key, *e2=q->key;
				if(e1->begin==e2->begin){
					e1->lenth=e2->lenth+5;
					flag=1;
				}
			}
			if(((Event*)(x->key))->type==2){/*是进入房间等待队列*/
				Event *e1=p->key, *e2=q->next->key;
				int t1=e1->begin+e1->lenth,/*本队列本次事件完成时间*/
					t2=e2->begin+e2->lenth;/*上次事件完成时间*/
				if(t1<t2){
					e1->lenth+=t2-t1;
					flag=1;
				}
			}
			if(flag){/*做了调整*/
				Event *e=p->key;
				int begin=e->begin+e->lenth;/*本次事件完成时间*/
				for(p=p->next,e=p->key;p!=schedules[code-'A']->nil;p=p->next,e=p->key){/*对行程表中以后事件扫描*/
					e->begin=begin;/*修改开始时间*/
					if(e->type==1){/*是等待电梯事件*/
						int t=begin%5;
						e->lenth=t?5-t:0;
					}
					begin=e->begin+e->lenth;
					if(e->type==1||e->type==2)/*是等待事件*/
						fix(queues[e->to.floor][e->to.number]);/*维护所在等待队列*/
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