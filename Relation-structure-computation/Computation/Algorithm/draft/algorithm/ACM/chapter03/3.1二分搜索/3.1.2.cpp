//假定一个解，并判断是否可行，因此需要编写判断是否可行的函数
int N,K;//K是分解的条数，N是绳子的总条数
double L[MAX_N];//绳子的长度
bool C(double x){
	int num=0;
	for(int i=0;i<N;i++)
		num+=L(i)/x;
	return num>=K;
}

void solve(){
	//初始化解的范围
	int lb=0,ub=INF;
	//重复循环，直到解的范围足够小
	for(int i=0;i<100;i++){
		double mid=(lb+ub)/2;
		if(C(mid))lb=mid;
		else ub=mid;
	}
	printf("%.2f\n",floor(ub*100)/100);
}

/*二分搜索的结束判断
在输出小数的问题中，一般会指定允许的误差范围或者是指定输出中小数点后面的位数。因此在使用二分搜索法的时候，有必要设置合理的结束条件来满足精度要求。在上面的程序中，我们指定了循环次数作为终止条件
*/