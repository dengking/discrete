#include "compare.h"
#include <string.h>
int intGreater(int const *x,int const *y){
    return (*x)-(*y);
}
int intLess(int const *x,int const *y){
    return intGreater(y,x);
}
int charGreater(char const *x,char const *y){
    return (*x)-(*y);
 }
int charLess(char const *x,char const *y){
    return charGreater(y,x);
}
int strGreater(char const **x,char const **y){
    return strcmp(*x,*y);
}
 int strLess(char const **x,char const **y){
    return strGreater(y, x);
}
int floatGreater(float const *x,float const *y){
   if((*x)-*(y)>0.0)
       return 1;
   if((*x)-*(y)<0.0)
       return -1;
   return 0;
}
int floatLess(float const *x,float const *y){
   return floatGreater(y,x);
}
int doubleGreater(double const *x,double const *y){
   if((*x)-(*y)>0.0)
       return 1;
   if((*x)-(*y)<0.0)
       return -1;
   return 0;
}
int doubleLess(double const *x,double const *y){
   return doubleGreater(y,x);
}
int unsignedGreater(unsigned const *x,unsigned const *y){
    return (*x)-(*y);
}
int unsigned_long_longGreater(unsigned long long const *x,unsigned long long const *y){
	if((*x)-(*y)>0)
		return 1;
	if((*x)-(*y)<0)
		return -1;
    return 0;
}
int dblLess(double const **x,double const **y){
   if((**x-**y)<0.0)
       return 1;
   if((**x-**y)>0.0)
       return -1;
   return 0;
}