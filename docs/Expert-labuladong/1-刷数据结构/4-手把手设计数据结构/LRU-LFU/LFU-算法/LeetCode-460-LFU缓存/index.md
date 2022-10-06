# [LeetCode-460. LFU 缓存](https://leetcode.cn/problems/lfu-cache/)



## [官方解题](https://leetcode.cn/problems/lfu-cache/solution/lfuhuan-cun-by-leetcode-solution/)

### 方法一：哈希表 + 平衡二叉树

> NOTE:
>
> 面试的时候，使用这种算法是最好的

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



```c++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>
// example1.cpp
// new-delete-type-mismatch error
#include <memory>
#include <vector>
struct Node
{
  int cnt, time, key, value;

  Node(int _cnt, int _time, int _key, int _value) : cnt(_cnt), time(_time), key(_key), value(_value) {}

  bool operator<(const Node &rhs) const
  {
    return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
  }
};
class LFUCache
{
  // 缓存容量，时间戳
  int capacity, time;
  unordered_map<int, Node> key_table;
  set<Node> S;

public:
  LFUCache(int _capacity)
  {
    capacity = _capacity;
    time = 0;
    key_table.clear();
    S.clear();
  }

  int get(int key)
  {
    if (capacity == 0)
      return -1;
    auto it = key_table.find(key);
    // 如果哈希表中没有键 key，返回 -1
    if (it == key_table.end())
      return -1;
    // 从哈希表中得到旧的缓存
    Node cache = it->second;
    // 从平衡二叉树中删除旧的缓存
    S.erase(cache);
    // 将旧缓存更新
    cache.cnt += 1;
    cache.time = ++time;
    // 将新缓存重新放入哈希表和平衡二叉树中
    S.insert(cache);
    it->second = cache;
    return cache.value;
  }

  void put(int key, int value)
  {
    if (capacity == 0)
      return;
    auto it = key_table.find(key);
    if (it == key_table.end())
    {
      // 如果到达缓存容量上限
      if (key_table.size() == capacity)
      {
        // 从哈希表和平衡二叉树中删除最近最少使用的缓存
        key_table.erase(S.begin()->key);
        S.erase(S.begin());
      }
      // 创建新的缓存
      Node cache = Node(1, ++time, key, value);
      // 将新缓存放入哈希表和平衡二叉树中
      key_table.insert(make_pair(key, cache));
      S.insert(cache);
    }
    else
    {
      // 这里和 get() 函数类似
      Node cache = it->second;
      S.erase(cache);
      cache.cnt += 1;
      cache.time = ++time;
      cache.value = value;
      S.insert(cache);
      it->second = cache;
    }
  }
};

```

> NOTE:
>
> 一、`key_table` 实现了 labuladong [算法题就像搭乐高：手把手带你拆解 LFU 算法](https://mp.weixin.qq.com/s/oXv03m1J8TwtHwMJEZ1ApQ) 中的：
>
> 1、`keyToVal`
>
> 2、`keyToFreq`
>
> `S` 则实现了 labuladong [算法题就像搭乐高：手把手带你拆解 LFU 算法](https://mp.weixin.qq.com/s/oXv03m1J8TwtHwMJEZ1ApQ) 中的`freqToKeys` ，它保证我们能够以`O(1)`实现找到应该被删除的元素
>
> 二、上述算法相比于 labuladong [算法题就像搭乐高：手把手带你拆解 LFU 算法](https://mp.weixin.qq.com/s/oXv03m1J8TwtHwMJEZ1ApQ) 会简单很多
>
> 三、set是典型的ordered data structure。

### 方法二：双哈希表

> NOTE:
>
> 这种算法和 labuladong [算法题就像搭乐高：手把手带你拆解 LFU 算法](https://mp.weixin.qq.com/s/oXv03m1J8TwtHwMJEZ1ApQ) 类似
>
> 



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



## 我的解题-双哈希表

```C++
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>
// example1.cpp
// new-delete-type-mismatch error
#include <memory>
#include <vector>
using namespace std;

struct Node
{
  int key{0};
  int val{0};
  int freq{0};
  Node(int key_, int val_, int freq_) : key{key_}, val{val_}, freq{freq_}
  {
  }
};
class LFUCache
{
  unordered_map<int, list<Node>> freq2nodes_;
  unordered_map<int, list<Node>::iterator> key2node_;
  int capacity_{0}, minFreq{0};

private:
  /**
   * @brief 增加频率
   *
   * @param key
   */
  void increaseFreq(int key)
  {
    // 首先取出从前的旧值
    auto node = key2node_[key];
    auto freq = node->freq;
    auto val = node->val;
    /// 动态更新cache、index
    // 1、切换freq
    freq2nodes_[freq].erase(node); // 此处是o(1)
    auto newFreq = freq + 1;

    if (freq2nodes_[freq].empty())
    {
      freq2nodes_.erase(freq);
      if (minFreq == freq)
      {
        minFreq = newFreq;
      }
    }
    freq2nodes_[newFreq].emplace_front(key, val, newFreq);
    // 2、更新index
    key2node_[key] = freq2nodes_[newFreq].begin();
  }

public:
  LFUCache(int capacity) : capacity_{capacity}
  {
  }

  int get(int key)
  {
    if (capacity_ == 0)
    {
      return -1;
    }
    if (key2node_.count(key))
    {
      increaseFreq(key);
      return key2node_[key]->val;
    }
    else
    {
      return -1;
    }
  }

  void put(int key, int value)
  {
    if (capacity_ == 0)
    {
      return;
    }
    if (key2node_.count(key))
    {
      increaseFreq(key);
      key2node_[key]->val = value; // 更新value
    }
    else
    {
      if (key2node_.size() == capacity_)
      {
        int toDelKey = freq2nodes_[minFreq].back().key;
        freq2nodes_[minFreq].pop_back();
        if (freq2nodes_[minFreq].empty())
        {
          freq2nodes_.erase(minFreq); // 此处需要注意，需要删除的是 minFreq
        }
        /// 动态更新cache、index

        key2node_.erase(toDelKey);
      }
      freq2nodes_[1].emplace_front(key, value, 1);
      /// 动态更新cache、index
      key2node_[key] = freq2nodes_[1].begin();
      minFreq = 1;
    }
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
  LFUCache lfu(2);
  lfu.put(1, 1); // cache=[1,_], cnt(1)=1
  lfu.put(2, 2); // cache=[2,1], cnt(2)=1, cnt(1)=1
  lfu.get(1);    // 返回 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
  lfu.put(3, 3); // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
  lfu.get(2);    // 返回 -1（未找到）
  lfu.get(3);    // 返回 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
  lfu.put(4, 4); // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
  lfu.get(1);    // 返回 -1（未找到）
  lfu.get(3);    // 返回 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
  lfu.get(4);    // 返回 4
                 // cache=[3,4], cnt(4)=2, cnt(3)=3
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```



### 二刷: 双哈希表，使用map.begin()来取代minFreq

我的思路是不保存`minFreq`，而是使用`freq2node_.begin()`来获得最小的freq，这种写法就需要保证为空的list要及时删除掉，否则它为空，但是还占用一个slot，在这些下面的时候是会抛出exception的：

```c++
        int toDelKey = freq2node_.begin()->second.back().first;
        freq2node_.begin()->second.pop_back();
```

因为对一个empty list 执行 `pop_back` 显然是错误的，是会抛出exception的。

```c++

struct Node
{
  int key{0};
  int val{0};
  int freq{0};
  Node(int key_, int val_, int freq_) : key{key_}, val{val_}, freq{freq_}
  {
  }
};

class LFUCache
{
  map<int, list<Node>> freq2nodes_;
  unordered_map<int, list<Node>::iterator> key2node_;
  int capacity_{0};

private:
  /**
   * @brief 增加频率
   *
   * @param key
   */
  void increaseFreq(int key)
  {
    auto node = key2node_[key];

    // 首先取出从前的旧值
    auto freq = node->freq;
    int val = node->val;
    /// 动态更新cache、index
    // 1、切换freq
    freq2nodes_[freq].erase(node); // 此处是o(1)
    if (freq2nodes_[freq].empty())
    {
      freq2nodes_.erase(freq);
    }
    auto newFreq = freq + 1;
    freq2nodes_[newFreq].emplace_front(key, val, newFreq);
    // 2、更新index
    key2node_[key] = freq2nodes_[newFreq].begin();
  }

public:
  LFUCache(int capacity) : capacity_{capacity}
  {
  }

  int get(int key)
  {
    if (capacity_ == 0)
    {
      return -1;
    }
    if (key2node_.count(key))
    {
      increaseFreq(key);
      return key2node_[key]->val;
    }
    else
    {
      return -1;
    }
  }

  void put(int key, int value)
  {
    if (capacity_ == 0)
    {
      return;
    }
    if (key2node_.count(key))
    {
      increaseFreq(key);
      key2node_[key]->val = value; // 更新value
    }
    else
    {
      if (key2node_.size() >= capacity_)
      {
        auto &minFreqNodes = freq2nodes_.begin()->second;
        int toDelKey = minFreqNodes.back().key;
        minFreqNodes.pop_back(); // 删除最小的key
        if (minFreqNodes.empty())
        {
          freq2nodes_.erase(freq2nodes_.begin());
        }
        /// 动态更新cache、index
        key2node_.erase(toDelKey);
      }
      freq2nodes_[1].emplace_front(key, value, 1);
      /// 动态更新cache、index
      key2node_[key] = freq2nodes_[1].begin();
    }
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

```







