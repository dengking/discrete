#include "combineproblem.h"
void clrSolution(Solution* s){/*�����s�Ĵ洢�ռ�*/
	if(s->x)
		free(s->x);
}
