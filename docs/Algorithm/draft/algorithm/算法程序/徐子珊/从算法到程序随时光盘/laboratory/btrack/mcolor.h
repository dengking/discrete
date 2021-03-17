#include "combineproblem.h"
int *G,/*图G的邻接矩阵*/
	n,/*图G的顶点个数*/
	m;/*颜色种数*/
ValueSet *newSet();
ValueSet** makeOMG();