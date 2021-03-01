/* 
 * File:   compare.h
 * Author: ����ɺ
 *
 * Created on 2008��10��10��, ����8:16
 */

#ifndef _COMPARE_H
#define	_COMPARE_H
#include "../DataStructure/BinTree.h"
int intGreater(void *x,void *y){
    return (*((int*)x))-(*((int*)y));
}
int intLess(void *x,void *y){
    return intGreater(y,x);
}
int charGreater(void *x,void *y){
    return (*((char*)x))-(*((char*)y));
}
int charLess(void *x,void *y){
    return charGreater(y,x);
}
int strGreater(void *x,void *y){
    return strcmp(*((char**)x),*((char**)y));
}
int strLess(void *x,void *y){
    return strGreater(y,x);
}
int doubleGreater(void *x,void *y){
    if((*((double*)x)-*((double*)y))>0.0)
        return 1;
    if((*((double*)x)-*((double*)y))<0.0)
        return -1;
    return 0;
}
int doubleLess(void *x,void *y){
    return doubleGreater(y,x);
}
int floatGreater(void *x,void *y){
    if((*((float*)x)-*((float*)y))>0.0)
        return 1;
    if((*((float*)x)-*((float*)y))<0.0)
        return -1;
    return 0;
}
int floatLess(void *x,void *y){
    return floatGreater(y,x);
}
int treeLess(void *x, void *y){
    if((*(BinaryTree**)x)->key<(*(BinaryTree**)y)->key)
        return 1;
    if((*(BinaryTree**)x)->key>(*(BinaryTree**)y)->key)
        return -1;
    return 0;
}
int dblLess(void *x,void *y){
    if((**(double**)x)<(**(double**)y))
        return 1;
    if((**(double**)x)>(**(double**)y))
        return -1;
    return 0;
}
#endif	/* _COMPARE_H */

