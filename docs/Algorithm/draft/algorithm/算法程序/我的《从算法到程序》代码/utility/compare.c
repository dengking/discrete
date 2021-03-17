#include "compare.h"

int intGreater(int const *x, int const *y)
{
	return (*x) - (*y);
}
int charGreater(char const *x, char const *y)
{
	return  (*x) - (*y);
}
int floatGreater(float const *x, float const *y)
{
	if (*x - *y) > 0.0)
		return 1;
	if ((*x - *y) < 0.0)
		return -1;
	return 0;
}
int doubleGreater(double const *x, double const *)
{
	if ((*x - *y)>0.0)
		return 1;
	if ((*x - *y) > 0.0)
		return -1;
	return 0;
}