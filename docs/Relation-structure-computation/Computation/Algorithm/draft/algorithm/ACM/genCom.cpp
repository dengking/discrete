#include <stdio.h>
#include <stdlib.h>

void print(int*,int);
void combination(int*,int,int,int);
int main()
{
    FILE *fin = fopen("bemenet.txt","r");
    if(!fin){printf("Error opening file @!!!");return 0;}
    int *a,i,n,p = 3;
    fscanf(fin,"%i ",&n);
    a = (int*)malloc(n*sizeof(int));
    for(i = 0; i < n; ++i){
        fscanf(fin,"%i ",&a[i]);
    }
    combination(a,n,p,0);

    return 0;
}

/*
a is the array that contain the numbers to be combined
n is the length of array a
p is the number chosen from array a
*/
void combination(int *a,int n,int p,int k)
{
    int i;
    if(k == p){//terminate the recursion
        print(a,k);
    }
    else{
        for(a[k + 1] = a[k] + 1 ; a[k+1] < n; ++a[k+1]){
            combination(a,n,p,k+1);
        }
    }
}
void print(int *a,int k)
{
    int i;
    for(i = 0; i < k; ++i){
        printf("%i ",a[i]);
    }
    printf("\n");
}