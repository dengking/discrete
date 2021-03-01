#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../graph/tpsort.h"
int main(){
	int n, m;
	FILE *f1,*f2;
	assert(f1=fopen("chap10/SortingItAllOut/inputdata.txt","r"));
	assert(f2=fopen("chap10/SortingItAllOut/outputdata.txt","w"));
	fscanf(f1,"%d%d", &n, &m);/*读取案例中对象个数n及关系数m*/
	while(n||m){
		Graph *g=zeroGraph(n);/*创建n个顶点的平凡树*/
		char line[4];
		pair p={NULL,NULL};
		int u, v, i=0, count=0,success=0,failed=100,
			*accessed=(int*)calloc(n, sizeof(int));/*顶点访问标志*/
		for(i=1;i<=m;i++){/*处理本案例的每一个关系*/
			fscanf(f1, "%s", line);/*读取关系*/
			if(failed<=m)/*已经知道失败*/
				continue;
			u=line[0]-'A';v=line[2]-'A';/*计算关系中对象对应的顶点*/
			addEdge(g, u, v, 1.0);/*向图中添加边*/
			if(p.first)free(p.first);
			if(p.second)free(p.second);
			p=toplogicalSort(g);/*计算图的拓扑排序*/
			if(*((int*)p.first)==0){/*若是有圈图，排序失败*/
				failed=i;
				continue;
			}
			if(accessed[u]==0){/*计数访问过的顶点（对象）*/
				accessed[u]=1;
				count++;
			}
			if(accessed[v]==0){/*计数访问过的顶点（对象）*/
				accessed[v]=1;
				count++;
			}
			if(count<n)/*计数成功步骤*/
				success++;
		}
		if(failed<=m)/*排序失败*/
			fprintf(f2,"Inconsistency found aftter %d relations.\n",failed);
        else if(count<n){/*不能排序*/
			fprintf(f2,"Sorted sequence cannot be determined.\n");
		}else{/*排序成功*/
			int k, *s=(int*)p.second;
			fprintf(f2,"Sorted sequence determined after %d relations:",success+1);
			for(k=0;k<n;k++){
				fputc('A'+s[k],f2);
			}
			fputc('\n',f2);
		}
		free(accessed);free(p.first);free(p.second);
		fscanf(f1, "%d%d", &n, &m);
	}
	fclose(f1);fclose(f2);
	return 0;
}