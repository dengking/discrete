# [LeetCode-剑指 Offer 41. 数据流中的中位数](https://leetcode.cn/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/) 、[295. 数据流的中位数](https://leetcode.cn/problems/find-median-from-data-stream/)

> NOTE: 
>
> [295. 数据流的中位数](https://leetcode.cn/problems/find-median-from-data-stream/) 中给出的官方解题是更加详细的

## 我的解题

```C++
/* Program to implement a stack
 using two queue */
#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
	priority_queue<int> low; // max heap
	priority_queue<int, vector<int>, greater<int>> high; // min heap
public:
	/** initialize your data structure here. */
	MedianFinder()
	{

	}

	void addNum(int num)
	{
		if (low.size() >= high.size())
		{
			low.push(num);
			high.push(low.top());
			low.pop();
		}
		else
		{
			high.push(num);
			low.push(high.top());
			high.pop();
		}
	}

	double findMedian()
	{
		if (low.size() > high.size())
		{
			return low.top();
		}
		else if (low.size() < high.size())
		{
			return high.top();
		}
		return (low.top() + high.top()) * 0.5;
	}
};

// Driver code
int main()
{
	MedianFinder m;
	m.addNum(1);
	m.addNum(2);
	cout << m.findMedian() << endl;
	m.addNum(3);
	cout << m.findMedian() << endl;
	return 0;
}
// g++ test.cpp

```

## [295. 数据流的中位数](https://leetcode.cn/problems/find-median-from-data-stream/) # [官方解题](https://leetcode.cn/problems/find-median-from-data-stream/solution/shu-ju-liu-de-zhong-wei-shu-by-leetcode/)