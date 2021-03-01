#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../../datastructure/queue.h"
typedef struct{/*像素点数据结构*/
	int x;
	int y;
}Point;
void pixelTransform(int* G, int m, int n, int i0, int j0, int newColor){
	Point p={i0, j0};
	int oldColor=G[i0*n+j0];
	Queue* Q=createQueue(sizeof(Point));
	if(G[i0*n+j0]==newColor)
		return;
	enQueue(Q,&p);
	while(!queueEmpty(Q)){
		memcpy(&p,deQueue(Q)->key,sizeof(Point));
		G[p.x*n+p.y]=newColor;
		if(p.y-1>=0&&G[p.x*n+p.y-1]==oldColor){
			Point p0={p.x, p.y-1};
			enQueue(Q,&p0);
		}
		if(p.y+1<n&&G[p.x*n+p.y+1]==oldColor){
			Point p0={p.x, p.y+1};
			enQueue(Q,&p0);
		}
		if(p.x-1>=0&&G[(p.x-1)*n+p.y]==oldColor){
			Point p0={p.x-1, p.y};
			enQueue(Q,&p0);
		}
		if(p.x+1<m&&G[(p.x+1)*n+p.y]==oldColor){
			Point p0={p.x+1, p.y};
			enQueue(Q,&p0);
		}
	}
}
int main(){
	FILE *f1=fopen("chap02/pixeltransform/inputdata.txt","r"),
		*f2=fopen("chap02/pixeltransform/outputdata.txt","w");
	assert(f1&&f2);
	while(!feof(f1)){
		int m,n,*G,i0,j0,newColor,i,j;
		fscanf(f1,"%d %d %d %d %d", &m, &n, &i0, &j0, &newColor);/*读取案例第1行数据*/
		G=(int*)malloc(m*n*sizeof(int));/*分配列阵空间*/
		for(i=0;i<m;i++)/*读取案例的列阵G数据*/
			for(j=0;j<n;j++)
				fscanf(f1,"%d",G+i*n+j);
		pixelTransform(G,m,n,i0-1,j0-1,newColor);
		for(i=0;i<m;i++){
			for(j=0;j<n;j++)
				fprintf(f2,"%d ",G[i*n+j]);
			fputc('\n',f2);
		}
		free(G);
	}
	fclose(f1);fclose(f2);
	return 0;
}