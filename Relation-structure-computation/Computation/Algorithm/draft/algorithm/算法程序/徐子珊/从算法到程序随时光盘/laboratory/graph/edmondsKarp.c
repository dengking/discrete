#include "edmondskarp.h"
#include "bfs.h"
#include <string.h>
#include<float.h>
#include <stdio.h>
double *edmondsKarp(double *c, int n, int s, int t){
    int u,v, *d, *pi;
    double *f=(double*)calloc(n*n,sizeof(double)),
		*cf=(double*)malloc(n*n*sizeof(double));
    Graph *gf;
    pair p;
	memcpy(cf,c,n*n*sizeof(double));
	gf=createGraph(cf,n);
	p=bfs(gf,s);
	pi=(int*)p.first;d=(int*)p.second;
    while(d[t]<INT_MAX){/*存在增广路*/
        double cp=DBL_MAX;
        v=t;
        u=pi[v];
        while(u!=-1){/*在增广路径扫描求出最小容量*/
            if(cf[u*n+v]<cp)
                cp=cf[u*n+v];
            v=u;
            u=pi[v];
        }
        for(v=t,u=pi[v];u!=-1;v=u,u=pi[v]){
            cf[u*n+v]-=cp;
            cf[v*n+u]+=cp;
            f[u*n+v]+=cp;
            f[v*n+u]-=cp;
        }
		free(pi);free(d);graphClear(gf);free(gf);
        gf=createGraph(cf,n);
		p=bfs(gf, s);pi=(int*)p.first;d=(int*)p.second;
    }
	free(cf);free(pi);free(d);graphClear(gf);free(gf);
    return f;
}