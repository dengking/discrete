/* 
 * File:   pair.h
 * Author: ?����???
 *
 * Created on 2008��11��4��, ����11:28
 */

#ifndef _PAIR_H
#define	_PAIR_H
struct pair{//用来存储两个整数数组的结构体
    void *first;
    void *second;
};
typedef struct pair pair;
pair make_pair(void *f, void *d){
    pair p={f,d};
    return p;
}
#endif	/* _PAIR_H */

