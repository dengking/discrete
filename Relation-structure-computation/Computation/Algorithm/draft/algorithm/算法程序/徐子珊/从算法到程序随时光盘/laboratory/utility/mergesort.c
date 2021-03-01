#include "merge.h"
void mergeSort(void *a,int size,int p,int r,int(*comp)(void *,void *)){
     if(p<r){
         int q=(p+r)/2;
         mergeSort(a,size,p,q,comp);
         mergeSort(a,size,q+1,r,comp);
         merge(a,size,p,q,r,comp);
     }
}

/*此函数是归并排序函数，排序过程发生在函数merge中，采用的是分制算法。*/
/*理解分制算法的比较好的方法是画递归树*/
/*此算法还存在需要改进的地方：如何更好地扩展递归的结束？*/
/*算法复杂度：T(n)=2T(n/2)+O(n)注：O(n)是merge函数的复杂度*/