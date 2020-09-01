#include "combineproblem.h"
void clrSolution(Solution* s){/*清理解s的存储空间*/
	if(s->x)
		free(s->x);
}
