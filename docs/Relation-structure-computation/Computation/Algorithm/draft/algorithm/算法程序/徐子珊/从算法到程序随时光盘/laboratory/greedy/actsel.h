#ifndef _ACTSEL_H
#define _ACTSEL_H
	typedef struct{
		double s;
		double f;
	}Active;
	int *greedyActivitySelector(Active *a, int n);
#endif	/* _ACTSEL_H */