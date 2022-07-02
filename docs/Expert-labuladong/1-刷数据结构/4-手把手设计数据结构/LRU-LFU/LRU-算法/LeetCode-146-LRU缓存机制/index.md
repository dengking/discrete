# leetcode [146. LRU 缓存机制](https://leetcode.cn/problems/lru-cache/)



## 我的解题

### 使用标准库的linked list

```C++
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

using Node = std::pair<int, int>;

class LRUCache
{
  std::list<Node> nodes_;
  std::unordered_map<int, std::list<Node>::iterator> key2node_;
  int capacity_{0};

public:
  LRUCache(int capacity) : nodes_(capacity), capacity_{capacity}
  {
  }
  /**
   * @brief 在access后，需要调整它的位置至队列首位
   *
   * @param key
   * @return int
   */
  int get(int key)
  {
    if (key2node_.count(key))
    {
      makeRecently(key);
      return nodes_.front().second;
    }
    else
    {
      return -1;
    }
  }

  void put(int key, int value)
  {
    if (key2node_.count(key))
    {
      deleteKey(key);
      addRecently(key, value);
    }
    else
    {
      if (nodes_.size() >= capacity_)
      {
        removeLeastRecently();
      }
      addRecently(key, value);
    }
  }

private:
  /**
   * @brief 将对应的节点放到队首
   *
   * @param key
   */
  void makeRecently(int key)
  {
    auto itor = key2node_[key];
    Node n = *itor; // 直接deep copy一下
    nodes_.erase(itor);
    nodes_.push_front(n);
    key2node_[key] = nodes_.begin();
  }
  void addRecently(int key, int val)
  {
    nodes_.emplace_front(key, val);
    key2node_[key] = nodes_.begin();
  }
  void removeLeastRecently()
  {
    key2node_.erase(nodes_.back().first);
    nodes_.pop_back();
  }
  void deleteKey(int key)
  {
    auto itor = key2node_[key];
    nodes_.erase(itor);
    key2node_.erase(key);
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main()
{
}
```



### 自定义的double linked list

```C++
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int key { 0 }, val { 0 };
	Node *next { nullptr }, *prev { nullptr };
	Node(int k, int v) :
					key { k }, val { v }
	{

	}
	Node() = default;
};
/**
 * @brief 双端链表
 *
 */
class DoubleLinkedList
{
	Node m_head, m_tail; // 使用伪头部和伪尾部节点，避免冗杂的空判断
	int m_size { 0 }; // 节点个数

public:
	DoubleLinkedList()
	{
		m_head.next = &m_tail;
		m_tail.prev = &m_head;
	}

	int size()
	{
		return m_size;
	}

	Node* emplace_front(int key, int val)
	{
		Node *n = new Node { key, val };
		Node *next = m_head.next;
		next->prev = n;

		n->prev = &m_head;
		n->next = next;

		m_head.next = n;

		++m_size;
		return n;
	}
	/**
	 * @brief 将节点n，移到头节点
	 *
	 * @param n
	 */
	void move_to_head(Node *n)
	{
		do_unlink(n);
		insert(&m_head, n);
	}
	void unlink(Node *n)
	{
		if (m_size > 0)
		{
			do_unlink(n);
			--m_size;
		}
	}
	void erase(Node *n)
	{
		unlink(n);
		delete n;
	}
	Node* back()
	{
		if (m_size)
		{
			return m_tail.prev;
		}
		else
		{
			return nullptr;
		}
	}
private:
	/**
	 * @brief 将节点n从链表中移除
	 *
	 * @param n
	 */
	void do_unlink(Node *n)
	{
		Node *prev = n->prev;

		Node *next = n->next;

		prev->next = next;

		next->prev = prev;
	}
	/**
	 * @brief 将node插入到prev 之后
	 *
	 * @param prev
	 * @param n
	 */
	void insert(Node *prev, Node *n)
	{
		Node *next = prev->next;
		next->prev = n;
		prev->next = n;

		n->next = next;
		n->prev = prev;
	}
};

class LRUCache
{
	DoubleLinkedList cache;
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
			Node *n = index[key];
			cache.move_to_head(n);
			return n->val;
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
			Node *n = index[key];
			cache.move_to_head(n);
			n->val = value;
		}
		else
		{
			Node *n { nullptr }; // 指向此次新增的节点
			if (capacity == cache.size()) // 缓存空间满了
			{
				n = cache.back(); // 复用最后一个节点的空间
				index.erase(n->key); // 更新索引: 将原来的key删除
				cache.move_to_head(n); // 移到头
				n->key = key;
				n->val = value;
			}
			else
			{
				n = cache.emplace_front(key, value);
			}
			index[key] = n; // 更新索引
		}
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



### 二刷

```c++
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

class LRUCache
{
  list<pair<int, int>> values_;
  unordered_map<int, list<pair<int, int>>::iterator> key2val_;
  int capacity_{0};

private:
  void makeRecently(int key)
  {
    // 首先取出从前的旧值
    auto itor = key2val_[key];
    int val = itor->second;
    values_.erase(itor);
    values_.emplace_front(key, val);
    // 动态更新
    key2val_[key] = values_.begin();
  }

public:
  LRUCache(int capacity) : capacity_{capacity}
  {
  }

  int get(int key)
  {
    if (key2val_.count(key))
    {
      makeRecently(key);
      return values_.front().second;
    }
    else
    {
      return -1;
    }
  }

  void put(int key, int value)
  {
    if (key2val_.count(key)) // already exist
    {
      makeRecently(key);
      key2val_[key]->second = value;
    }
    else
    {
      if (key2val_.size() >= capacity_) // full
      {
        auto toDelKey = values_.back().first; // 待删除
        values_.pop_back();
        key2val_.erase(toDelKey);
      }
      values_.emplace_front(key, value);
      key2val_[key] = values_.begin();
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```





## [朱雀](https://leetcode.cn/u/zhu-que-3/) # [c++双向链表和哈希表](https://leetcode.cn/problems/lru-cache/solution/cshuang-xiang-lian-biao-he-ha-xi-biao-by-l476/)



```c++
class LRUCache {
private:
  list<pair<int, int>> cache;   ////< @note pair[key]=value
  unordered_map<int, list<pair<int, int>>::iterator> key2node;
  int cap;                      ////< @note 最大容量

public:
  LRUCache(int capacity) : cap(capacity) {}

  int get(int key) {
    if (key2node.find(key) == key2node.end()) {
      return -1;
    }
    pair<int, int> node = *key2node[key];
    cache.erase(key2node[key]); ////< @note 将节点移到链表头部并更新map
    cache.push_front(node);
    key2node[key] = cache.begin();
    return node.second;
  }

  void put(int key, int val) {
    auto newNode = std::make_pair(key, val);

    if (key2node.count(key)) {  ////< @note 若该节点已存在，则删除旧的节点
      cache.erase(key2node[key]);
    } else {
      if (cap == cache.size()) {
        key2node.erase(cache.back().first);
        cache.pop_back();       ////< @note 删除链表最后一个数据
      }
    }

    cache.push_front(newNode);  ////< @node 插入新的节点到头部
    key2node[key] = cache.begin();
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

```

