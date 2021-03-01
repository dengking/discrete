void matrixChain(int *p,int n,int **m,int **s){
	//init  the array
	for(int i=1;i<=n;i++)m[i][i]=0;
	//r is the span
	for(int r=2;r<=n;r++)
		for(i=1;i<=n-r+1;i++){
			int j=i+r-1;
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];//断开位置从i开始
			s[i][j]=i;
			for(int k=i+1;k<j;k++){
				int min=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(min<m[i][j]){
					m[i][j]=min;
					s[i][j]=k;
				}
			}
		}
}

void traceBack(int i,int j;int **s){
	if(i==j)return;
	traceBack(i,s[i][j],s);
	traceBack(s[i][j]+1,j,s);
	cout<<"Mutiply A["<<i<<","<<s[i][j]<<"]";
	cout<<"Mutip A["<<s[i][j]<<","<<j<<"j"<<endl;
}