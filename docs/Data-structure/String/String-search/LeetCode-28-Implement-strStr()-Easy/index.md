# [LeetCode-28. 实现 strStr()](https://leetcode.cn/problems/implement-strstr/)



## 我的解题



### KMP

```c++

class Solution
{
public:
  int strStr(string haystack, string needle)
  {
    if (needle.empty())
    {
      return 0;
    }
    else
    {
      return kmp(haystack, needle);
    }
  }
  int kmp(const string &haystack, const string &needle)
  {
    auto failureArray = getFailureArray(needle);
    int i = 0, j = 0;
    while (i < haystack.size())
    {
      if (haystack[i] == needle[j])
      {
        if (j == needle.size() - 1)
        {
          return i - j;
        }
        ++j;
      }
      else if (j > 0)
      {
        j = failureArray[j - 1];
        continue;
      }
      ++i;
    }
    return -1;
  }
  std::vector<int> getFailureArray(const string &needle)
  {
    std::vector<int> failureArray(needle.size());
    int i = 0, j = 1;
    while (j < needle.size())
    {
      if (needle[i] == needle[j])
      {
        ++i;
      }
      else if (i > 0)
      {
        i = failureArray[i - 1];
        continue;
      }
      failureArray[j++] = i;
    }
    return failureArray;
  }
};
```

