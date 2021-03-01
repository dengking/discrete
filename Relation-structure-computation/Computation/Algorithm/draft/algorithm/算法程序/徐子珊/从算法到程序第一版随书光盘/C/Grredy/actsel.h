/* 
 * File:   actsel.h
 * Author: 徐子珊
 *
 * Created on 2008年9月20日, 上午10:38
 */

#ifndef _ACTSEL_H
#define	_ACTSEL_H
#include <stdlib.h>
//int *x;
void recurcive_activity_selector(int *s, int *f, int *x, int i, int j){
    int m=i+1;
    while(m<j&&s[m]<f[i])
        x[m++]=0;
    if(m<j){
        x[m]=1;
        recurcive_activity_selector(s,f,x,m,j);
    }
}
#endif	/* _ACTSEL_H */

