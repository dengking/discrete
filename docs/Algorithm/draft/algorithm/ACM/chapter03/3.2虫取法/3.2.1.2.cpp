//对于这个问题我认为他的本质是让我查出数组中所有不相同的数的个数，我的解决思路是使用一个新的数组来保存这些不相同的数，原数组中的数要想加入这个新数组必须和这个新数组中的每个数进行比较，只有和新数组中的每个数都不相同的情况下才将这个数插入到新数组中。这是一种比较笨的方法
//刚刚又把问题看了一遍，发现我对问题的理解是有误的，题目的要求是“阅读一些连续的页将所有的知识点覆盖到”，注意到“连续”也就是说所求的和前一题类似

//输入
int P;
int a[MAX_P];

void solve(){
	//计算全部知识点的总数
	set<int> all;
	for(int i=0;i<P;i++)
		all.insert(a[i]);
	int n=all.size();
	//利用尺取法来求解
	int s=0;//起始下标
	int t=0;//终止下标
	int num=0;//在所取段中知识点出现的次数
	map<int,int> count;//知识点->出现次数的映射
	int res=P;
	for(;;){
		while(t<P&&num<n)
			if(count[a[t++]]++==0)//注意执行的次序是先判断相等，然后count再自加1
				num++;
		if(num<n)break;
		res=min(res,t-s);
		if(--count[a[s++]]==0)
			num--;
	}
	printf("%d\n",res);
}
