# leetcode [460. LFU 缓存](https://leetcode-cn.com/problems/lfu-cache/)



## 我的解题

```C++
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int key { 0 }, val { 0 }, freq { 1 };
	Node(int k, int v) :
					key { k }, val { v }
	{

	}
	Node() = default;
};

class LFUCache
{
	unordered_map<int, list<Node*>> freq2node; // 根据频率快速地定位到节点，实现在O(1)内更新
	unordered_map<int, Node> key2node; // key node
	int capacity { 0 };
	int minFreq { 0 }; //最小频率，为了实现在O(1)内快速删除最小频率的节点
public:
	LFUCache(int capacity) :
					capacity { capacity }
	{

	}
	/**
	 *
	 * @param key
	 * @return
	 */
	int get(int key)
	{
		if (capacity == 0)
		{
			return -1;
		}
		auto i = key2node.find(key);
		if (i != key2node.end()) // 存在
		{
			increaseFreq(i->second);
			return i->second.val;
		}
		else
		{
			return -1;
		}
	}
	/**
	 *
	 * @param key
	 * @param value
	 */
	void put(int key, int value)
	{
		if (capacity == 0)
		{
			return;
		}
		auto i = key2node.find(key);
		if (i == key2node.end()) // 不存在
		{
			if (key2node.size() == capacity)
			{
				removeMinFreqKey();
			}
			key2node[key] = Node { key, value };
			freq2node[1].push_front(&key2node[key]);
			minFreq = 1;
		}
		else // 存在
		{
			i->second.val = value;
			increaseFreq(i->second);
		}
	}
private:
	/**
	 * @brief 增加节点的频率
	 *
	 * @param i
	 */
	void increaseFreq(Node &n)
	{
		int freq = n.freq;
		int key = n.key;

		freq2node[freq].remove(&n);
		if (freq2node[freq].empty())
		{
			freq2node.erase(freq);
			if (minFreq == n.freq)
			{
				++minFreq;
			}
		}
		++n.freq;
		freq2node[n.freq].push_front(&n);
	}
	/**
	 * @brief 淘汰掉最小频率的节点
	 *
	 */
	void removeMinFreqKey()
	{
		int key = freq2node[minFreq].back()->key;
		freq2node[minFreq].pop_back();
		if (freq2node[minFreq].empty())
		{
			freq2node.erase(minFreq);
		}

		key2node.erase(key);
	}
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// Driver code
int main()
{

	Solution solu;
	vector<int> nums = { 1, 3, 5, 4, 7 };
	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```



## [官方解题](https://leetcode-cn.com/problems/lfu-cache/solution/lfuhuan-cun-by-leetcode-solution/)

### 方法一：哈希表 + 平衡二叉树

本方法需要使用到「平衡二叉树」。在 C++ 语言中，我们可以直接使用 `std::set` 类作为平衡二叉树；同样在 Java 语言中，我们可以直接使用 `TreeSet`。但是在 Python 语言中，并没有内置的库可以用来模拟平衡二叉树。

首先我们定义缓存的数据结构：

```C++
struct Node {
    int cnt; // 频率
    int time; // 插入时间
    int key, value; 
    
    // 我们需要实现一个 Node 类的比较函数
    // 将 cnt（使用频率）作为第一关键字，time（最近一次使用的时间）作为第二关键字
    // 下面是 C++ 语言的一个比较函数的例子
    bool operator< (const Node& rhs) const {
        return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
    }
};

```

> NOTE:
>
> 这是典型的多级排序

```C++
#include <bits/stdc++.h>
using namespace std;

// 缓存的节点信息
struct Node
{
	int key, val, freq;
	Node(int _key, int _val, int _freq) :
					key(_key), val(_val), freq(_freq)
	{
	}
};
class LFUCache
{
	int minfreq, capacity;
	unordered_map<int, list<Node>::iterator> key_table;
	unordered_map<int, list<Node>> freq_table;
public:
	LFUCache(int _capacity)
	{
		minfreq = 0;
		capacity = _capacity;
		key_table.clear();
		freq_table.clear();
	}

	int get(int key)
	{
		if (capacity == 0)
			return -1;
		auto it = key_table.find(key);
		if (it == key_table.end())
			return -1;
		list<Node>::iterator node = it->second;
		int val = node->val, freq = node->freq;
		freq_table[freq].erase(node);
		// 如果当前链表为空，我们需要在哈希表中删除，且更新minFreq
		if (freq_table[freq].size() == 0)
		{
			freq_table.erase(freq);
			if (minfreq == freq)
				minfreq += 1;
		}
		// 插入到 freq + 1 中
		freq_table[freq + 1].push_front(Node(key, val, freq + 1));
		key_table[key] = freq_table[freq + 1].begin();
		return val;
	}

	void put(int key, int value)
	{
		if (capacity == 0)
			return;
		auto it = key_table.find(key);
		if (it == key_table.end())
		{
			// 缓存已满，需要进行删除操作
			if (key_table.size() == capacity)
			{
				// 通过 minFreq 拿到 freq_table[minFreq] 链表的末尾节点
				auto it2 = freq_table[minfreq].back();
				key_table.erase(it2.key);
				freq_table[minfreq].pop_back();
				if (freq_table[minfreq].size() == 0)
				{
					freq_table.erase(minfreq);
				}
			}
			freq_table[1].push_front(Node(key, value, 1));
			key_table[key] = freq_table[1].begin();
			minfreq = 1;
		}
		else
		{
			// 与 get 操作基本一致，除了需要更新缓存的值
			list<Node>::iterator node = it->second;
			int freq = node->freq;
			freq_table[freq].erase(node);
			if (freq_table[freq].size() == 0)
			{
				freq_table.erase(freq);
				if (minfreq == freq)
					minfreq += 1;
			}
			freq_table[freq + 1].push_front(Node(key, value, freq + 1));
			key_table[key] = freq_table[freq + 1].begin();
		}
	}
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// Driver code
int main()
{

	Solution solu;
	vector<int> nums = { 1, 3, 5, 4, 7 };
	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

### 方法二：双哈希表

> NOTE:
>
> 这种算法和 labuladong [算法题就像搭乐高：手把手带你拆解 LFU 算法](https://mp.weixin.qq.com/s/oXv03m1J8TwtHwMJEZ1ApQ) 类似
>
> 