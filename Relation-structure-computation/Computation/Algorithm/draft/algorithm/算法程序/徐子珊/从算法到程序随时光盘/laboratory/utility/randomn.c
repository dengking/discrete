#include <stdlib.h>
#include "randomn.h"
int randomNumber(int p, int q){
    return p+(int)((double)(q-p)*rand()/(RAND_MAX));
}
unsigned long long RangedRandom( unsigned long long range_min, unsigned long long range_max){
	unsigned long long u = (double)rand() / (RAND_MAX + 1) * (range_max - range_min)+ range_min;
	return u;
}
