# leetcode [318. 最大单词长度乘积](https://leetcode.cn/problems/maximum-product-of-word-lengths/)

## 我的解题

https://mp.weixin.qq.com/s/gExKZifZziFDEPfibaUu5A

### 第一次解题

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

class Solution
{
public:
  int maxProduct(vector<string> &words)
  {
    vector<int> word_bits;
    for (auto &&w : words)
    {
      int num = 0;
      for (auto &&c : w)
      {
        int mask = 1 << (c - 'a');
        num |= mask;
      }
      word_bits.push_back(num);
    }
    int len = words.size();
    int res = 0;
    for (int i = 0; i < len; ++i)
    {
      for (int j = i + 1; j < len; ++j)
      {
        if (word_bits[i] & word_bits[j] == 0)
        {
          int l = words[i].size() * words[j].size();
          res = max(res, l);
        }
      }
    }
    return res;
  }
};
```



### 第二次解题

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

class Solution
{
public:
  int maxProduct(vector<string> &words)
  {
    vector<int> word_bits;
    for (auto &&w : words)
    {
      int num = 0;
      for (auto &&c : w)
      {
        int mask = 1 << (c - 'a');
        num |= mask;
      }
      word_bits.push_back(num);
    }
    int len = words.size();
    int res = 0;
    for (int i = 0; i < len; ++i)
    {
      for (int j = i + 1; j < len; ++j)
      {
        if ((word_bits[i] & word_bits[j]) == 0)
        {
          int l = words[i].size() * words[j].size();
          res = max(res, l);
        }
      }
    }
    return res;
  }
};
```

