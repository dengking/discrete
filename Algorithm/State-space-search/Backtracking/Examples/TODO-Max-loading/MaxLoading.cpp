#include<iostream>

class Loading{
public:
	Loading();
	friend int MaxLoading(int[], int, int);
private:
	void BackTrack(int i);
	int n;//
	int *w;////集装箱的重量数组
	int *x;//记录解
	int *bestx;//记录最优解
	int c;//第一艘船的载重量
	int cw;//记录当前值
	int bestw;//记录当前最优值
	int r=0;//记录剩余集装箱的重量
};


Loading::Loading(){
	for (int j = 0; j<n; j++){//剩余重量初始化为集装箱总重量
		r += w[j];
	}
	bestw=cw = 0;
}

void Loading::BackTrack(int i){//在本函数中，i是从0开始的
	if (i >=n){
		if (cw > bestw){
			for (int j = 0; j < n; j++){
				bestx[j] = x[j];
				bestw = cw;
			}
		}
	}
	r -= w[i];
	if (cw + w[i] <= c){//搜索左子树
		x[i] = 1;
		cw += w[i];
		BackTrack(i + 1);
		x[i] = 1;
		cw -= w[i];
	}
	if (cw + r > bestw){//此处也使用了剪枝，只有当右枝的剩余重量值比当前最优值大时才到右枝去搜索
		x[i] = 0;
		BackTrack(i + 1);
	}
	r += w[i];

}
