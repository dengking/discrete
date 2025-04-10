# [LeetCode-415. 字符串相加](https://leetcode.cn/problems/add-strings/)

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

class Solution
{
  int toInt(char c)
  {
    return c - '0';
  }

public:
  string addStrings(string num1, string num2)
  {
    auto len1 = num1.size();
    auto len2 = num2.size();
    auto len = max(len1, len2) + 1; //结果的最大长度，需要注意+1，这是因为可能会产生最终的进位
    vector<int> num(len, 0);        //两数的和

    for (int index = len - 1, //和的索引
         first = len1 - 1,    //第一个数的索引
         second = len2 - 1    //第二个数的索引
         ;
         index >= 1; // 需要注意 index >=1，在循环体中有index-1的进位的
         --index, --first, --second)
    {
      int sum = 0;
      if (first >= 0 && second >= 0)
      {
        sum = toInt(num1[first]) + toInt(num2[second]) + num[index];
      }
      else if (first >= 0)
      {
        sum = toInt(num1[first]) + num[index];
      }
      else if (second >= 0)
      {
        sum = toInt(num2[second]) + num[index];
      }
      else
      {
        sum = num[index];
      }
      num[index] = sum % 10;
      num[index - 1] += sum / 10; //进位
    }
    auto itor = num[0] ? num.begin() : num.begin() + 1;
    string res;
    std::transform(itor, num.end(), std::back_inserter(res), [](int n) -> char
                   { return '0' + n; });
    return res;
  }
};

int main()
{
  string num1 = "6";
  string num2 = "507";
  Solution s;
  s.addStrings(num1, num2);
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

## 官方解题

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

class Solution
{
public:
  string addStrings(string num1, string num2)
  {
    int i = num1.length() - 1, j = num2.length() - 1, add = 0;
    string ans = "";
    while (i >= 0 || j >= 0 || add != 0)
    {
      int x = i >= 0 ? num1[i] - '0' : 0;
      int y = j >= 0 ? num2[j] - '0' : 0;
      int result = x + y + add;
      ans.push_back('0' + result % 10);
      add = result / 10;
      i -= 1;
      j -= 1;
    }
    // 计算完以后的答案需要翻转过来
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main()
{
  string num1 = "6";
  string num2 = "507";
  Solution s;
  s.addStrings(num1, num2);
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

上述写法比我的写法要简洁很多。