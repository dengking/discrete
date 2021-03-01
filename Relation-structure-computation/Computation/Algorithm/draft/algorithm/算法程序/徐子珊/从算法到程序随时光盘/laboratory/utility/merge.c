#include "merge.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>

/*此函数的功能是：数组a[p....r]中a[p.....q]和a[q+1......r]是有序的，通过此函数能够对数组的元素进行重拍，使数组有序*/
void merge(void *a, int size, int p, int q, int r,int(*comp)(void *,void *)){//size指定存储在数组a中的元素的实际长度
   int i, j, k, n1=q-p+1, n2=r-q;//n1是序列a[p.....q]的长度
   void *L=(void*)malloc(n1*size);//fp分配存储空间
   void *R=(void*)malloc(n2*size);
   assert(L&&R);
   memcpy((char*)L,(char*)a+p*size,n1*size);/*将a[p..q]拷贝到L[1..n1]，(char*)a+p*size表示从p开始*/
   memcpy((char*)R,(char*)a+(q+1)*size,n2*size);/*将a[q+1..r]拷贝到R[1..n2]*/
   i=j=0;
   k=p;
   while(i<n1&&j<n2)
       if(comp((char*)L+i*size,(char*)R+j*size)<0)/*L[i]<R[j]*/
           memcpy((char*)a+(k++)*size,(char*)L+(i++)*size,size);/*a[k]←L[i]*/
       else
           memcpy((char*)a+(k++)*size,(char*)R+(j++)*size,size);/*a[k] ←R[j]*/
   if(i<n1)
       memcpy((char*)a+k*size,(char*)L+i*size,(n1-i)*size);/*将L[i..n1]拷贝到a[k..r]*/
   if(j<n2)
       memcpy((char*)a+k*size,(char*)R+j*size,(n2-j)*size);/*将R[j..n2]拷贝到a[k..r]*/
   free(L);L=NULL;
   free(R);R=NULL;
}
/*此算法是典型的渐增型算法，特征：
1.主体是一个循环结构
2.将部分解扩展成完整解
*/
/*问题解答： 
1.为什么memcpy((char*)L,(char*)a+p*size,n1*size)中要用(char*)进行强转？*/