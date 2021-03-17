#include <stdio.h>
#include <stdlib.h>
//#include "graph.h"
//int main(){
//	double a[]={0, 1, 0, 0, 1,
//						  1, 0, 1, 1, 1,
//	                      0, 1, 0, 1, 0,
//						  0, 1, 1, 0, 1,
//						  1, 1, 0, 1, 0};
//	Graph *g=createGraph(a, 5);
//	printGraph(g);
//	graphClear(g);
//	return 0;
//}
/*
*程序6-5
*/
//#include "bfs.h"
//int main(int argc, char** argv) {
//    int i,s=1,n=8,*pi,*d;
//    pair r;
//    double a[]={0,1,0,0,1,0,0,0,
//            1,0,0,0,0,1,0,0,
//            0,0,0,1,0,1,1,0,
//            0,0,1,0,0,0,1,1,
//            1,0,0,0,0,0,0,0,
//            0,1,1,0,0,0,1,0,
//            0,0,1,1,0,1,0,1,
//            0,0,0,1,0,0,1,0};
//    Graph *g=createGraph(a,8);
//    r=bfs(g,1);
//    pi=(int*)(r.first);
//    d=(int*)(r.second);
//    for(i=0;i<n;i++)
//        if(i!=s){
//            printPath(pi,s,i);
//            printf(" length: %d\n",d[i]);
//        }
//    graphClear(g);
//    free(g);
//    return (EXIT_SUCCESS);
//}

/*
*程序6-16
*/
//#include "stronglyconnectedcomponents.h"
//int main(int argc, char** argv) {
//    double a[]={0,1,0,0,0,0,0,0,
//             0,0,1,0,1,1,0,0,
//             0,0,0,1,0,0,1,0,
//             0,0,1,0,0,0,0,1,
//             1,0,0,0,0,1,0,0,
//             0,0,0,0,0,0,1,0,
//             0,0,0,0,0,1,0,1,
//             0,0,0,0,0,0,0,1};
//    int n=8;
//    Graph *g=createGraph(a,n);
//    strongConnectedComponents(g);
//    return (EXIT_SUCCESS);
//}
//#include "dfs.h"
//int main(int argc, char** argv) {
//    double a[]={0,1,0,0,1,1,
//            1,0,0,0,0,1,
//            0,0,0,1,0,1,
//            0,0,1,0,0,1,
//            1,0,0,0,0,1,
//            1,1,1,1,1,0};
//    int i,n=6,*pi,*d,*f;
//    pair r;
//    Graph *g=createGraph(a,n);
//    r=dfs(g);
//    pi=(int*)r.first;
//	d=(int*)((pair*)r.second)->first;
//	f=(int*)((pair*)r.second)->second;
//    for(i=0;i<n;i++){
//        printf("%d:parent %d discover/finish: %d/%d\n",i, pi[i],d[i],f[i]);
//    }
//    return (EXIT_SUCCESS);
//}
//#include "tpsort.h"
//int main(){
//    double a[]={0,1,1,1,0,0,0,0,0,0,
//                0,0,0,0,0,0,0,0,0,0,
//                0,0,0,0,0,0,0,0,0,0,
//                0,1,1,0,0,0,0,0,1,0,
//                0,0,0,0,0,1,1,0,0,0,
//                0,0,0,1,0,0,0,0,0,0,
//                0,0,0,0,0,0,0,1,0,0,
//                0,0,0,0,0,0,0,0,1,0,
//                0,0,0,0,0,0,0,0,0,0,
//                0,0,0,0,0,0,0,0,0,0};
//    char* name[]={"程序设计","编译原理","数据库原理",
//		"数据结构", "高等数学", "离散数学","普通物理",
// 		"计算机原理","操作系统","政治经济学"};
//    int n=10;
//    int *topLogic;
//    int acyclicity;
//    Graph *g=createGraph(a,n);
//    pair r=toplogicalSort(g);
//    acyclicity=*(int*)r.first;
//    topLogic=(int*)(r.second);
//    if(acyclicity){
//		int u;
//        for(u=0;u<n;u++)
//            printf("%s ",name[topLogic[u]]);
//        printf("\n");
//    }
//	return 0;
//}
//#include "articpoint.h"
//#include "../utility/output.h"
//int main(int argc, char** argv) {
//    int i,s;
//    char *name="abcdefghij";
//    LinkedList *a;
//    double b[]={0,1,0,0,0,0,1,0,0,0,
//             1,0,1,0,0,1,0,0,0,0,
//             0,1,0,1,1,0,0,0,0,0,
//             0,0,1,0,1,0,0,0,0,0,
//             0,0,1,1,0,0,0,0,0,0,
//             0,1,0,0,0,0,1,0,0,0,
//             1,0,0,0,0,1,0,1,0,0,
//             0,0,0,0,0,0,1,0,1,1,
//             0,0,0,0,0,0,0,1,0,1,
//             0,0,0,0,0,0,0,1,1,0};
//    Graph *g=createGraph(b,10);
//    for(s=0;s<10;s++){
//        a=articPoint(g,s);
//		listTraverse(a,intOutput);
//		putchar('\n');
//    }
//    return (EXIT_SUCCESS);
//}
#include "edmondskarp.h"
int main(){
    double c[]={0,16,13,0,0,0,
                0,0,10,12,0,0,
                0,4,0,0,14,0,
                0,0,9,0,0,20,
                0,0,0,7,0,4,
                0,0,0,0,0,0},*f;
    int n=6, i;
    double value=0.0;
    f=edmondsKarp(c, n, 0, n-1);
    for(i=0;i<n;i++)
        value+=f[i];
    printf("%f\n",value);
	return 0;
}