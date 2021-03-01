#include "merge.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>

/*�˺����Ĺ����ǣ�����a[p....r]��a[p.....q]��a[q+1......r]������ģ�ͨ���˺����ܹ��������Ԫ�ؽ������ģ�ʹ��������*/
void merge(void *a, int size, int p, int q, int r,int(*comp)(void *,void *)){//sizeָ���洢������a�е�Ԫ�ص�ʵ�ʳ���
   int i, j, k, n1=q-p+1, n2=r-q;//n1������a[p.....q]�ĳ���
   void *L=(void*)malloc(n1*size);//fp����洢�ռ�
   void *R=(void*)malloc(n2*size);
   assert(L&&R);
   memcpy((char*)L,(char*)a+p*size,n1*size);/*��a[p..q]������L[1..n1]��(char*)a+p*size��ʾ��p��ʼ*/
   memcpy((char*)R,(char*)a+(q+1)*size,n2*size);/*��a[q+1..r]������R[1..n2]*/
   i=j=0;
   k=p;
   while(i<n1&&j<n2)
       if(comp((char*)L+i*size,(char*)R+j*size)<0)/*L[i]<R[j]*/
           memcpy((char*)a+(k++)*size,(char*)L+(i++)*size,size);/*a[k]��L[i]*/
       else
           memcpy((char*)a+(k++)*size,(char*)R+(j++)*size,size);/*a[k] ��R[j]*/
   if(i<n1)
       memcpy((char*)a+k*size,(char*)L+i*size,(n1-i)*size);/*��L[i..n1]������a[k..r]*/
   if(j<n2)
       memcpy((char*)a+k*size,(char*)R+j*size,(n2-j)*size);/*��R[j..n2]������a[k..r]*/
   free(L);L=NULL;
   free(R);R=NULL;
}
/*���㷨�ǵ��͵Ľ������㷨��������
1.������һ��ѭ���ṹ
2.�����ֽ���չ��������
*/
/*������ 
1.Ϊʲômemcpy((char*)L,(char*)a+p*size,n1*size)��Ҫ��(char*)����ǿת��*/