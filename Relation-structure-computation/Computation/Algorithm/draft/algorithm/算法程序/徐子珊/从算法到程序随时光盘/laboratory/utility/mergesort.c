#include "merge.h"
void mergeSort(void *a,int size,int p,int r,int(*comp)(void *,void *)){
     if(p<r){
         int q=(p+r)/2;
         mergeSort(a,size,p,q,comp);
         mergeSort(a,size,q+1,r,comp);
         merge(a,size,p,q,r,comp);
     }
}

/*�˺����ǹ鲢��������������̷����ں���merge�У����õ��Ƿ����㷨��*/
/*�������㷨�ıȽϺõķ����ǻ��ݹ���*/
/*���㷨��������Ҫ�Ľ��ĵط�����θ��õ���չ�ݹ�Ľ�����*/
/*�㷨���Ӷȣ�T(n)=2T(n/2)+O(n)ע��O(n)��merge�����ĸ��Ӷ�*/