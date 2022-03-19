# [**HJ51** **输出单向链表中倒数第k个结点**](https://www.nowcoder.com/practice/54404a78aec1435a81150f15f899417d?tpId=37&tqId=21274&rp=1&ru=/ta/huawei&qru=/ta/huawei&difficulty=&judgeStatus=&tags=/question-ranking)



```c++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;

struct ListNode
{
  int m_nKey;
  ListNode *m_pNext;
};
int main()
{
  int node_count;
  while (cin >> node_count)
  {
    int node_val;
    ListNode dummy;
    ListNode *tail = &dummy;
    while (node_count--)
    {
      cin >> node_val;
      auto *nd = new ListNode();
      nd->m_nKey = node_val;
      nd->m_pNext = nullptr;
      tail->m_pNext = nd;
      tail = nd;
    }
    int k;
    cin >> k;
    ListNode *fast = dummy.m_pNext, *slow = dummy.m_pNext;
    for (int i = 0; i < k; ++i)
    {
      fast = fast->m_pNext;
    }
    while (fast != nullptr)
    {
      fast = fast->m_pNext;
      slow = slow->m_pNext;
    }
    if (slow)
      cout << slow->m_nKey << endl;
    else
    {
      cout << 0 << endl;
    }
  }
}
```

