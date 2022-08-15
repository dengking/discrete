# [LeetCode-752. 打开转盘锁-中等](https://leetcode.cn/problems/open-the-lock/) 



## 我的解题

这道题是在阅读 labuladong [BFS 算法框架套路详解](https://mp.weixin.qq.com/s/WH_XGm1-w5882PnenymZ7g) 时发现的，它的典型的state- space-search，"每次旋转都只能旋转一个拨轮的一位数字"，在每个拨轮有如下两个选择:

1、上拨

2、下拨

它的state-space如下: 

![](./751660574877_.pic.jpg)

可以看到，它是一棵"八叉树"，上述state-space罗列了它的所有的可能state，这些state之间的转换是按照题目要求的"每次旋转都只能旋转一个拨轮的一位数字"而生成的，显然实际的旋转也是需要按照这个规则进行，所以上述state-space是正确的，题目要求的最短路径其实就是从source到goal的最短路径，显然这是可以通过BFS实现的。



```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int openLock(vector<string> &deadends, string target)
	{
		unordered_set<string> deadend_set;
		deadend_set.insert(deadends.begin(), deadends.end());

		string start = "0000"; // 起始

		queue<string> q;
		q.push(start);

		unordered_set<string> vis;
		vis.insert(start);

		int depth = 1;
		while (!q.empty())
		{
			int sz = q.size();
			for (int i = 0; i < sz; ++i)
			{
				string cur = q.front();
				q.pop();
				if (cur == target)
				{
					return depth - 1;
				}
				if (deadend_set.count(cur)) // 是deadend，需要摒弃
				{
					continue;
				}
				for (int i = 0; i < 4; ++i)
				{
					string newNode = AddOne(cur, i);
					if (!vis.count(newNode))
					{
						q.push(newNode);
						vis.emplace(newNode);
					}
					newNode = MinusOne(cur, i);
					if (!vis.count(newNode))
					{
						q.push(newNode);
						vis.emplace(newNode);
					}
				}

			}
			++depth;
		}
		return -1;
	}

	string AddOne(string s, int location)
	{
		if (s[location] == '9')
		{
			s[location] = '0';
		}
		else
		{
			s[location] += 1;
		}
		return s;
	}
	string MinusOne(string s, int location)
	{
		if (s[location] == '0')
		{
			s[location] = '9';
		}
		else
		{
			s[location] -= 1;
		}
		return s;
	}
};

// Driver code
int main()
{

	Solution solu;
	vector<int> nums = { 1, 3, 5, 4, 7 };
	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```



## leetcode[【中规中矩】752. 打开转盘锁（宽度优先搜索）](https://leetcode.cn/problems/open-the-lock/solution/zhong-gui-zhong-ju-kuan-du-you-xian-sou-suo-by-jyj/)



```C++
// With deadends
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q{{"0000"}};
        unordered_set<string> visited;
        unordered_set<string> deads(deadends.begin(), deadends.end());

        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto cur = q.front(); q.pop();
                if (cur == target) {
                    return steps;
                }

                if (deads.count(cur) || visited.count(cur)) { //只多了前半部分的check deadends
                    continue;
                }
                visited.insert(cur);

                for (int i = 0; i < 4; i++) {
                    q.push(plusOne(cur, i));
                    q.push(minusOne(cur, i));
                }
            }
            steps++;
        }

        return -1;
    }

private:
    string plusOne(string cur, int j) {
        auto res = cur;
        res[j] = ((res[j] - '0' + 1) % 10) + '0';
        return res;
    }

    string minusOne(string cur, int j) {
        auto res = cur;
        res[j] = ((res[j] - '0' - 1 + 10) % 10) + '0';
        return res;
    }
};

```





## leetcode [C++ BFS 转动开锁](https://leetcode.cn/problems/open-the-lock/solution/c-bfs-jie-jue-zhuan-dong-kai-suo-by-bei-lpvye/)

```C++
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // 哈希表vis中存储不可能入队的结点，包括deadends和已访问过的结点
        unordered_set<string> vis;
        vis.insert(deadends.begin(), deadends.end()); 
        if(vis.count("0000")) 
            return -1;
        int step = 0;
        queue<string> st;
        st.push("0000");
        while(!st.empty()){            
            int length = st.size();
            for(int i = 0; i < length; i++){
                string curr = st.front();
                st.pop();
                // 找到目标元素，直接返回答案
                if(curr == target)
                    return step;
                // 处理curr周围的八个相邻结点
                for(int j = 0; j < 4; ++j){
                    // 自增1与自减1
                    for(int t = -1; t < 2; t += 2){
                        // 完美的字符处理方式，利用ascⅡ码之差之后加上t并取余作为新得到的整型，然后再加上0的ascⅡ码值返回字符
                        char a = (curr[j] -'0' + 10 + t) % 10 + '0';
                        string newOne = curr;
                        newOne[j] = a;
                        // 若哈希集中找不到此状态，则加入哈希集同时入队
                        if(!vis.count(newOne)){
                            st.push(newOne);
                            vis.emplace(newOne);
                        }
                    }                 
                }
            }
            // 本层队列中元素处理完成，到达下一转动步数，步数加1
            step++;
        }
        return -1;
    }
};

```





## 两种往visited array中添加节点的方式



1、先判断是否visited，如果是，则不入queue

"leetcode [752. 打开转盘锁](https://leetcode.cn/problems/open-the-lock/) 中等 # 我的解"题中，就是采用的这种方式

2、先入queue，然后再入visited

"leetcode[【中规中矩】752. 打开转盘锁（宽度优先搜索）](https://leetcode.cn/problems/open-the-lock/solution/zhong-gui-zhong-ju-kuan-du-you-xian-sou-suo-by-jyj/) "中，就是使用的这种方式



