/*the recursive function to caculate the combination of C(n,k)
use c(n,k)=c(n-1,k-1)+c(n-1,k);
*/
int combination(int n,int k){
	if(n==r||k==0)return 1;
	if(k==1)
		return n;
	else
		return combination(n-1,k-1)+combination(n-1,k);
}

/*the dynamic programming algorithm to caculate the combination of C(n,k)
use c(n,k)=c(n-1,k-1)+c(n-1,k);
*/
unsigned long combination(int n,int k){
	int r[k+1]={1};
	for(int i=1;i<=n-k;i++)
		for(int j=1;i<=k;j++){
			r[j]=r[j]+r[j-1];
		}
	return r[k];
}

