# leetcode [146. LRU 缓存机制](https://leetcode-cn.com/problems/lru-cache/)



## 我的解题

### 使用标准库的linked list

```C++
#include <bits/stdc++.h>
using namespace std;

//class Node
//{
//public:
//	int key, val;
//	Node *next { nullptr }, *prev { nullptr };
//	Node(int k, int v) :
//					key { k }, val { v }
//	{
//
//	}
//};

class LRUCache
{
	using Node = pair<int, int>; // key, value
	list<Node> cache;
	unordered_map<int, Node*> index; // key node
	int capacity;
public:
	LRUCache(int capacity) :
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
		if (index.count(key))
		{
			makeRecently(key);
			return cache.front().second;
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
		if (index.count(key))
		{
			deleteKey(key);
			addRecently(key, value);
		}
		else
		{
			if (capacity == cache.size())
			{
				removeLeastRecently();
			}
			addRecently(key, value);
		}
	}

private:
	/**
	 * @brief 将key对应的节点，放到队首
	 *
	 * @param key
	 */
	void makeRecently(int key)
	{
		if (index.count(key))
		{
			Node n = *(index[key]);
			cache.remove(n);
			cache.push_front(n);
			index[key] = &cache.front();
		}
	}

	/* 添加最近使用的元素 */
	void addRecently(int key, int val)
	{
		cache.emplace_front(key, val);
		// 别忘了在 map 中添加 key 的映射
		index[key] = &cache.front();
	}

	void deleteKey(int key)
	{
		if (index.count(key))
		{
			Node* x = index[key];
			// 从链表中删除
			cache.remove(*x);
			// 从 map 中删除
			index.erase(key);
		}
	}
	/* 删除最久未使用的元素 */
	void removeLeastRecently()
	{
		int key = cache.back().first;
		cache.pop_back(); // 删除最后一个元素
		// 同时别忘了从 map 中删除它的 key
		index.erase(key);
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
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

超时。