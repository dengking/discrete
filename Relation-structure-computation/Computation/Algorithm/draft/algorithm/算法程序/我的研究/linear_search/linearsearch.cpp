#include<stdlib.h>
#include<stdio.h>
int linearsearch(void* a, int size, int n, void* x,int(* comp)(void *,void *));
int intGreater(int *x, int *y);
int charGreater(char *x, char *y);
int floatGreater(float *x, floart *y);
int doubleGreater(double *x, double *y);

int main()
{

}

int linearsearch(void* a, int size, int n, void* x, int(* comp)(void *, void *))
{
	int i = 0;
	while (i < n)
	{
		if (comp((char *)a + i*size, x) == 0)
			return i;
		i++;
	}
	return -1;
}