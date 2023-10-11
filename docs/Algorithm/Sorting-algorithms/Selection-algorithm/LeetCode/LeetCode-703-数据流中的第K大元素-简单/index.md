# [LeetCode-703. 数据流中的第 K 大元素-简单](https://leetcode.cn/problems/kth-largest-element-in-a-stream/)



csdn [【leetcode/BST】数据流中的第k大元素（BST综合+优先队列引入）](https://blog.csdn.net/qq_43338695/article/details/102645827)

## 写法一

```C++
#include <vector>
#include <queue>

using namespace std;
class KthLargest
{
    priority_queue<int, vector<int>, std::greater<int>> q;
    int k{0};

public:
    KthLargest(int k, vector<int> &nums) : k{k}
    {
        for (auto &&n : nums)
        {
            addImpl(n);
        }
    }

    int add(int val)
    {
        addImpl(val);
        return q.top();
    }

private:
    void addImpl(int val)
    {
        q.emplace(val);
        if (q.size() > k)
        {
            q.pop();
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
int main()
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



## 写法二

```c++
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class KthLargest
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> q; // 最小堆
    int k;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        for (auto &&num : nums)
        {
            addImpl(num);
        }
    }

    int add(int val)
    {
        addImpl(val);
        return q.top();
    }

private:
    void addImpl(int val)
    {
        if (q.size() < k || val > q.top())
        {
            if (q.size() == k)
            {
                q.pop();
            }
            q.push(val);
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main()
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```

