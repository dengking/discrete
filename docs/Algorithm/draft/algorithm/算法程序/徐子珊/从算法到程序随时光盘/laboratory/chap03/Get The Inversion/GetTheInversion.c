#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <assert.h>
int count;
void inversMerge(int *a, int p, int q, int r){
   int i=0, j=0, k=p, n1=q-p+1, n2=r-q;
   int *L=(int*)malloc(n1*sizeof(int));
   int *R=(int*)malloc(n2*sizeof(int));
   assert(L&&R);
   memcpy(L,a+p,n1*sizeof(int));/*将a[p..q]拷贝到L[1..n1]*/
   memcpy(R,a+(q+1),n2*sizeof(int));/*将a[q+1..r]拷贝到R[1..n2]*/
   while(i<n1&&j<n2)
       if(L[i]<R[j])
           a[k++]=L[i++];/*a[k]←L[i]*/
	   else{
           a[k++]=R[j++];/*a[k] ←R[j]*/
		   count+=n1-i;/*记录逆序*/
	   }
   if(i<n1)
       memcpy(a+k, L+i,(n1-i)*sizeof(int));/*将L[i..n1]拷贝到a[k..r]*/
   if(j<n2)
       memcpy(a+k,R+j,(n2-j)*sizeof(int));/*将R[j..n2]拷贝到a[k..r]*/
   free(L);L=NULL;
   free(R);R=NULL;
}
void getTheInvers(int *a, int p, int r){
     if(p<r){
         int q=(p+r)/2;
         getTheInvers(a,p,q);
         getTheInvers(a,q+1,r);
         inversMerge(a,p,q,r);
     }
}
int main(){
	int *a,n,i;
	FILE *f1=fopen("chap03/Get The Inversion/inputdata.txt","r"), 
		*f2=fopen("chap03/Get The Inversion/outputdata.txt","w");
	assert(f1&&f2);
	fscanf(f1,"%d",&n);
	while(n){
		count=0;
		a=(int*)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
			fscanf(f1,"%d", a+i);
		getTheInvers(a,0,n-1);
		free(a);
		fprintf(f2,"%d\n",count);
		fscanf(f1,"%d",&n);
	}
	return 0;
}