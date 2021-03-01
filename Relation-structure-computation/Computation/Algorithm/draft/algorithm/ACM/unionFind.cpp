define MAX_N 1000
int par[MAX_N];
int rank[MAX_N];

//int the the array
void init(int n){
	for(int i=1;i<n;i++){
		par[i]=i;
		rank[i]=0;
	}
}

//find the root of x
int find(int x){
	if(par[x]==x)
		return x;//x is root;
	else
		return par[x]=find(par[x]);
}

//unit the set that x belong to and the set that y do
void unit(int ,x,int y){
	x=find(x);
	y=find(y);
	if(x==y)return;
	if(rank[x]<rank[y])
		par[x]=y;
	else{
		par[y]=x;
		if(rank(x)==rank(y))
			rank[x]++;
	}
}

//to determain whether x and y belong to the same set
bool same(int x,int y){
	return find(x)==find(y);
}