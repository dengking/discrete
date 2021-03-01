#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../graph/tpsort.h"
int main(){
	int n, m;
	FILE *f1,*f2;
	assert(f1=fopen("chap10/SortingItAllOut/inputdata.txt","r"));
	assert(f2=fopen("chap10/SortingItAllOut/outputdata.txt","w"));
	fscanf(f1,"%d%d", &n, &m);/*��ȡ�����ж������n����ϵ��m*/
	while(n||m){
		Graph *g=zeroGraph(n);/*����n�������ƽ����*/
		char line[4];
		pair p={NULL,NULL};
		int u, v, i=0, count=0,success=0,failed=100,
			*accessed=(int*)calloc(n, sizeof(int));/*������ʱ�־*/
		for(i=1;i<=m;i++){/*����������ÿһ����ϵ*/
			fscanf(f1, "%s", line);/*��ȡ��ϵ*/
			if(failed<=m)/*�Ѿ�֪��ʧ��*/
				continue;
			u=line[0]-'A';v=line[2]-'A';/*�����ϵ�ж����Ӧ�Ķ���*/
			addEdge(g, u, v, 1.0);/*��ͼ����ӱ�*/
			if(p.first)free(p.first);
			if(p.second)free(p.second);
			p=toplogicalSort(g);/*����ͼ����������*/
			if(*((int*)p.first)==0){/*������Ȧͼ������ʧ��*/
				failed=i;
				continue;
			}
			if(accessed[u]==0){/*�������ʹ��Ķ��㣨����*/
				accessed[u]=1;
				count++;
			}
			if(accessed[v]==0){/*�������ʹ��Ķ��㣨����*/
				accessed[v]=1;
				count++;
			}
			if(count<n)/*�����ɹ�����*/
				success++;
		}
		if(failed<=m)/*����ʧ��*/
			fprintf(f2,"Inconsistency found aftter %d relations.\n",failed);
        else if(count<n){/*��������*/
			fprintf(f2,"Sorted sequence cannot be determined.\n");
		}else{/*����ɹ�*/
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