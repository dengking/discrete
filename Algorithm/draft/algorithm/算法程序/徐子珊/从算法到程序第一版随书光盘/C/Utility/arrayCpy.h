/* 
 * File:   arrayCpy.h
 * Author: 徐子珊
 *
 * Created on 2008年11月10日, 下午6:45
 */

#ifndef _ARRAYCPY_H
#define	_ARRAYCPY_H
void assign(void *des,int i,void* src,int j,int size){
    memcpy(des+i*size,src+j*size,size);
}
void arrayCopy(void *des, void *src,int size, int n){
    memcpy(des, src, n*size);
}
void arrayFill(void *a,int size, void *v, int n){
    int i;
    for(i=0;i<n;i++)
        memcpy(a+i*size,v,size);
}
#endif	/* _ARRAYCPY_H */

