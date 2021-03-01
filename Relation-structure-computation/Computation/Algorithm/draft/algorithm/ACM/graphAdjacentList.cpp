struct vertex{
	vector<vertex*> edge;//
};

define MAX_V 1000
vertex G[MAX_V];

int main(){
	int V,E;
	scanf("%d %d",&V,&E);
	for(int i=0;i<E;i++){
		int s,t;
		scanf("%d %d",&s,&t);
		G[s].edge.push_back(&G[t]);
	}
	return 0;
}