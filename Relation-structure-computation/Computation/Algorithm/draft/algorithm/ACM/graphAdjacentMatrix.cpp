#define MAX_V 1000	
vector<int> G[MAX_V];//这是一个数组，数组的元素的类型是vector<int>
/*
if the edge has attribute
struct edge{
	int to;
	int cost;
}
*/

int main(){
	int V,E;
	scanf("%d %d",&V,&E);
	for(int i=0;i<E;i++){
		//the start node is s,and the end node is t
		int s,t;
		scanf("%d %d",&s,&t);
		G[s].push_back(t);//
	}
	return 0;
}