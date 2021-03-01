#ifndef _PARTITION_H
#define	_PARTITION_H

#ifdef	__cplusplus
extern "C" {
#endif
long partition(void *a,int size,int p,int r,int(*comp)(void *,void *));
long randmizedPartition(void *a,int size,long p,long r,int(*comp)(void *,void *));
#ifdef	__cplusplus
}
#endif

#endif	/* _PARTITION_H */
