/* 
 * File:   actsel.h
 * Author: 徐子珊
 *
 * Created on 2008年9月20日, 上午10:38
 */

#ifndef _ACTSEL_H
#define	_ACTSEL_H
int* recurcive_activity_selector(int *s, int *f, int i, int j){
    static int *x=new int[j];
    int m=i+1;
    while(m<j&&s[m]<f[i])
        x[m++]=0;
    if(m<j){
        x[m]=1;
        recurcive_activity_selector(s,f,m,j);
    }
    return x;
}
#endif	/* _ACTSEL_H */

