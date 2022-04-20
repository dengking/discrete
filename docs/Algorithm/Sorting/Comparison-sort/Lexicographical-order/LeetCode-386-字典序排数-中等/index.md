# LeetCode [386. 字典序排数](https://leetcode-cn.com/problems/lexicographical-numbers/) 中等

例子:

```c++
[1,10,100,101,102,103,104,105,106,107,108,109,11,110,111,112,113,12,13,14,15,16,17,18,19,2,20,21,22,23,24,25,26,27,28,29,3,30,31,32,33,34,35,36,37,38,39,4,40,41,42,43,44,45,46,47,48,49,5,50,51,52,53,54,55,56,57,58,59,6,60,61,62,63,64,65,66,67,68,69,7,70,71,72,73,74,75,76,77,78,79,8,80,81,82,83,84,85,86,87,88,89,9,90,91,92,93,94,95,96,97,98,99]
```



## [PPPPjcute](https://leetcode-cn.com/u/ppppjcute/)  # [java 字典序的遍历](https://leetcode-cn.com/problems/lexicographical-numbers/solution/java-zi-dian-xu-de-bian-li-by-ppppjqute/)

字典序可以抽象为一棵树

![QQ20201028-170405@2x.png](https://pic.leetcode-cn.com/1603875858-aRThUF-QQ20201028-170405@2x.png)

所以，有小到大输出其实就是输出他的先序遍历，参考二叉搜索树的先序遍历写法。

> NOTE: 
>
> 一、这个算法的本质是通过**剪枝**一棵完全十叉树来生成字典树，它的第一棵子树是所有以1打头的，第二棵子树是所有以2打头的
>
> 需要注意的是，这个tree的特殊性：它的第一层节点的范围是1-9，后面的是0-9
>
> 二、它采用的是pre-order即先序遍历，它的模式非常类似于append-to-tail模式，即将每个node（一个数）append到result中去

一、递归：
此处不一样的是需要舍去头结点0，以1-9分别为根节点进行遍历输出：

1.递归结束条件，当前结点＞n则递归结束

2.将元素值添加进入res,遍历其10个兄弟结点，进入递归其子节点

二、迭代:

见注释

### 递归

```Java
class Solution {
    // public List<Integer> lexicalOrder(int n) {
    //     List<Integer> list = new ArrayList<>();
    //     int curr = 1;
    //     //10叉树的先序遍历
    //     for(int i=0;i<n;i++){
    //         list.add(curr);
    //         if(curr*10<=n){
    //             curr*=10;//进入下一层
    //         }else{
    //             if(curr>=n)   curr/=10;//如果这一层结束了
    //             curr+=1;
    //             while(curr%10==0) curr/=10;//如果>10就要返回上一层
    //         }
    //     }
    //     return list;
    // }
    public List<Integer> lexicalOrder(int n) {
        List<Integer> list = new ArrayList<>();
        for (int i = 1; i < 10; i++){
             dfs(n, i, list);
        }
        return list;
    }
    private void dfs(int n,int i,List<Integer>list){
        if(i>n){
            return ;
        }
        list.add(i);
        for(int j=0;j<=9;j++){
            dfs(n,i*10+j,list);
        }
    }

}

```
> NOTE:
>
> 对应的c++代码如下：
>
> ```c++
> // #include <bits/stdc++.h>
> #include <iostream>
> #include <string>
> #include <algorithm>
> #include <vector>
> #include <bitset>
> #include <map>
> #include <list>
> #include <stack>
> #include <unordered_map>
> #include <unordered_set>
> #include <queue>
> #include <cmath>
> #include <numeric>
> #include <climits>
> #include <random>
> // example1.cpp
> // new-delete-type-mismatch error
> #include <memory>
> #include <vector>
> using namespace std;
> 
> class Solution
> {
> public:
>   vector<int> lexicalOrder(int n)
>   {
>     vector<int> res;
>     std::function<void(int)> dfs = [&](int num)
>     {
>       if (num > n) // 剪枝
>       {
>         return;
>       }
>       res.push_back(num); // 典型的pre-order traversal
>       for (int i = 0; i <= 9; ++i)
>       {
>         dfs(num * 10 + i);
>       }
>     };
>     for (int num = 1; num <= 9; ++num)
>     {
>       dfs(num);
>     }
>     return res;
>   }
> };
> 
> int main()
> {
>   Solution s;
> }
> // g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g
> 
> ```
>
> 

### 迭代

```Java
class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> list = new ArrayList<>();
		int curr = 1;
		//10叉树的先序遍历
		for(int i=0;i<n;i++)
		{
			list.add(curr);
			if(curr*10<=n)
			{
				curr*=10; //进入下一层
			}
			else
			{
				if(curr>=n) curr/=10; //如果这一层结束了
				curr+=1;
				while(curr%10==0) curr/=10;//如果>10就要返回上一层
			}
		}
		return list;       
    }
}
```

> NOTE:
>
> C++代码如下：
>
> ```c++
> // #include <bits/stdc++.h>
> #include <iostream>
> #include <string>
> #include <algorithm>
> #include <vector>
> #include <bitset>
> #include <map>
> #include <list>
> #include <stack>
> #include <unordered_map>
> #include <unordered_set>
> #include <queue>
> #include <cmath>
> #include <numeric>
> #include <climits>
> #include <random>
> // example1.cpp
> // new-delete-type-mismatch error
> #include <memory>
> #include <vector>
> using namespace std;
> 
> class Solution
> {
> public:
>   vector<int> lexicalOrder(int n)
>   {
>     vector<int> res;
>     int curr = 1;
>     // 10叉树的先序遍历
>     for (int i = 0; i < n; i++)
>     {
>       res.push_back(curr);
>       if (curr * 10 <= n)
>       {
>         curr *= 10; //进入下一层
>       }
>       else
>       {
>         if (curr >= n)
>           curr /= 10; //如果这一层结束了
>         curr += 1;
>         while (curr % 10 == 0)
>           curr /= 10; //如果>10就要返回上一层
>       }
>     }
>     return res;
>   }
> };
> 
> int main()
> {
>   Solution s;
> }
> // g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g
> 
> ```
>
> 



## 我的解题

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<int> lexicalOrder(int n)
	{
		vector<int> ret; // 结果
		for (int number = 1; number <= 9; ++number)
		{
			DFS(number, n, ret);
		}
		return ret;
	}
	void DFS(int number, int n, vector<int> &ret) // pre-order
	{
		if (number > n)
		{
			return;
		}
		ret.push_back(number);
		for (int i = 0; i <= 9; ++i)
		{
			DFS(number * 10 + i, n, ret);
		}
	}
};

int main()
{
	Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```

