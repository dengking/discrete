class Triangle{
	friend int Compute(int);
private:
	void Backtrack(int t);
	int n,//第一行符号个数
		half,//half=n*（n+1）/2，即最终结果中“+”的个数
		count,//当前“+”的个数
		**p;//符号三角形矩阵
	long sum;//已经找到的符合条件的三角形的个数
};

void Triangle::Backtrack(int t){
	if (count > half || t*(t - 1) / 2 - count > half)return;//如果在已经确定的t-1行三角形中，“+”或“-”的个数超过half，则显然不可能包含可行解，可以直接剪掉
	if (t > n)sum++;//可以把最终结果输出来
	else{
		for (int i = 0; i < 2; i++){//每个当前扩展结点可以取两个值0，1取0表示“-”，取1表示“+”
			p[1][t] = i;//对第一行进行赋值
			count += i;
			for (int j = 2; j <= t; j++){//按照斜线方向有上网下进行填值
				p[j][t - j + 1] = p[j - 1][t - j + 1] * p[j - 1][t - j + 2];
				count += p[j][t - j + 1];
			}
			Backtrack(t + 1);
			for (int j = 2; j <= t; j++){//这三句进行回滚
				count -= p[j][t - j + 1];
			}
			count -= i;
		}
	}
    
}