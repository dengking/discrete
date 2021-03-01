/* 
 * File:   hanoi.h
 * Author: 徐子珊
 *
 * Created on 2008年10月19日, 下午5:16
 */

#ifndef _HANOI_H
#define	_HANOI_H
#include<stdio.h>
int count=0;
struct disk{
    char current;
    char target;
};
typedef struct disk disk;
int pickTopDisk(disk *disks,char c){
    int i=0;
    while(disks[i].current!=c)
        i++;
    return i;
}
void hanoi(disk *disks,int n, char A,char B, char C){
    int i=0;
    if(n==1){
        i=pickTopDisk(disks,A);
        disks[i].current=C;
        count++;
        printf("move %d disk %d: %c->%c\n",count,i+1,A,C);
        return;
    }
    hanoi(disks,n-1,A,C,B);
    disks[n-1].current=C;
    count++;
    printf("move %d disk %d: %c->%c\n",count,n,A,C);
    hanoi(disks,n-1,B,A,C);
}
void creatHanoi(disk *t,int k){
    if(k==1)//塔由一块盘构成
        return;
    if(k==2){//它有两块盘构成
        if(t[0].current!=t[1].current)//尚未形成塔
            hanoi(t,1,t[0].current,6-t[0].current-t[1].current,t[1].current);
        return;
    }
    if(t[k-3].current!=t[k-2].current&&
       t[k-3].current!=t[k-1].current&&
       t[k-2].current!=t[k-1].current){//塔基，上一层与再上一层分处于三根杆上
        creatHanoi(t,k-2);//创建再上层塔
        count++;
        printf("move %d disk %d: %c -> %c\n",count,k-1,t[k-2].current,t[k-1].current);//移动上层盘
        t[k-2].current=t[k-1].current;
        hanoi(t,k-2,t[k-3].current,t[k-2].current,t[k-1].current);//移动再上层塔
        return;
    }
    creatHanoi(t,k-1);//创建上层塔
    if(t[k-2].current!=t[k-1].current){//上层塔不在本盘所在杆上
        hanoi(t,k-1,t[k-2].current,198-t[k-1].current-t[k-2].current,t[k-1].current);
    }
    return;
}
void newHanoi(disk *t,int n){
    int k=n;
    while(k>=1&&t[k-1].current==t[k-1].target)//从大到小找到第一个需要移动的盘
        k--;
    if(k>1)
        creatHanoi(t,k-1);//将前k-1个盘组成塔
    while(k>1){//从大到小逐一考察是否需要移动
        if(t[k-1].current!=t[k-1].target){//若需要移动
            if(t[k-2].current==t[k-1].current){//若塔在本盘上方则将塔移到过渡杆上
                hanoi(t,k-1,t[k-2].current,t[k-1].target,198-t[k-2].current-t[k-1].target);
            }else if(t[k-2].current==t[k-1].target){//若塔在目标杆上则将塔移到过渡杆上
                hanoi(t,k-1,t[k-2].current,t[k-1].current,198-t[k-2].current-t[k-1].current);
            }
            count++;//记录移动的次数
            printf("move %d disk %d: %c->%c\n",count,k,t[k-1].current,t[k-1].target);//显示移动信息
            t[k-1].current=t[k-1].target;//移动本盘
        }
        k--;
    }
    if(t[0].current!=t[0].target){//最小盘需要移动
        count++;
        printf("move %d disk 1: %c->%c\n",count,t[0].current,t[0].target);
    }
}
#endif	/* _HANOI_H */

