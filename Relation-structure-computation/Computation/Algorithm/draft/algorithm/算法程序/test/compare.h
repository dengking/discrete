#ifndef _COMPARE_H
#define	_COMPARE_H

int intGreater(int const *x, int const *y);
int intLess(int const *x, int const *y);
int charGreater(char const *x, char const *y);
int charLess(char const *x, char const *y);
int strGreater(char const **x, char const **y);
int strLess(char const **x, char const **y);
int floatGreater(float const *x, float const *y);
int floatLess(float const *x, float const *y);
int doubleGreater(double const *x, double const *y);
int doubleLess(double const *x, double const *y);
int unsignedGreater(unsigned const *x, unsigned const *y);
int unsigned_long_longGreater(unsigned long long const *x, unsigned long long const *y);
int dblLess(double const **x, double const **y);
#endif	/* _COMPARE_H */
