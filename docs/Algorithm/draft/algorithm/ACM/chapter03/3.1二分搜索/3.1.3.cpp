//最大化最小值或最小化最大值
int M;//M是牛的数目
int N;//N是牛舍的数目
int X[MAX_N];//牛舍的位置

//采用贪心算法来判断能否将所有的M头牛安排到牛舍中，并且保证容易两头牛之间的间隔是不小于d的
bool C(int d){
	int last=0;//前一头牛
	for(int i=1;i<M;i++){
		int crt=last+1;//第二头牛
		while(crt<N&&x[crt]-x[last]<d)//为第crt头牛安排牛舍
			crt++;
		if(crt==N)return false;//循环退出的原因是crt<N,表示尝试了所有的牛舍，都没有找到符合条件的牛舍
		last=crt;//进行迭代
	}
	return true;
}

void solve(){
	sort(x,x+N);
	//初始化解的存在范围
	while(ub-lb>1){
		int mid=(ub+lb)/2;
		if(C(mid))lb=mid;
		else ub=mid;
	}
	printf("%d\n",lb);
}
