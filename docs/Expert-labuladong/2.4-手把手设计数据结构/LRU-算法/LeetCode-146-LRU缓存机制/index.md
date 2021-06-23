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

