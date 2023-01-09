# [LeetCode-25. K 个一组翻转链表](https://leetcode.cn/problems/reverse-nodes-in-k-group/) 



## 我的解题



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

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *reverseKGroup(ListNode *head, int k)
  {
    ListNode *a = head, *b = head; // b指向下一段起点
    for (int i = 0; i < k; i++)
    {
      if (b)
      {
        b = b->next;
      }
      else // 从head开始的节点数，不足k个，在这种情况下直接返回，不需要进行反转
      {
        return head;
      }
    }
    auto *newHead = reverse(head, b);
    a->next = reverseKGroup(b, k); // 与原链表连接在一起
    return newHead;
  }
  ListNode *reverse(ListNode *head, ListNode *end)
  {
    ListNode *prev = nullptr, *cur = head, *next = nullptr;
    while (cur != end)
    {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    return prev;
  }
};

int main()
{
  auto *one = new ListNode(1);
  auto *two = new ListNode(2);
  auto *three = new ListNode(3);
  auto *four = new ListNode(4);
  auto *five = new ListNode(5);

  one->next = two;
  two->next = three;
  three->next = four;
  four->next = five;

  Solution s;
  s.reverseKGroup(one, 2);
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

