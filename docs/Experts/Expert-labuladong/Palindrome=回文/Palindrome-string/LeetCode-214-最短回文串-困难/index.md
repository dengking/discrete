# [LeetCode-214. 最短回文串-困难](https://leetcode.cn/problems/shortest-palindrome/) 

解题思路: [LeetCode-Clean KMP solution with super detailed explanation](https://leetcode.com/problems/shortest-palindrome/discuss/60113/clean-kmp-solution-with-super-detailed-explanation)  

> This problem asks us to add string before the input so the result string will be a palindrome.We can convert it to an alternative problem"find the **longest palindrome substring** starts from index 0".If we can get the length of such substring, then we can easily build a palindrome string by inserting the reverse part of substring after such substring before the original string.

所以问题就归结为如何"find the **longest palindrome substring** starts from index 0"？

## KMP LPS

充分运用

### [LeetCode-Clean KMP solution with super detailed explanation](https://leetcode.com/problems/shortest-palindrome/discuss/60113/clean-kmp-solution-with-super-detailed-explanation)  

This problem asks us to add string before the input so the result string will be a palindrome.We can convert it to an alternative problem"find the **longest palindrome substring** starts from index 0".If we can get the length of such substring, then we can easily build a palindrome string by inserting the reverse part of substring after such substring before the original string.

Example:

input string:

> abacd

longest palindrome substring starts from 0:

> aba

Insert the reverse part of substring after palindrome substring before the head:

> dcabacd

Now the problem becomes how to find the **longest palindrome substring** starts from 0. We can solve it by using a trick + KMP.

The trick is to build a temp string like this:

> s + "#" + reverse(s)

Then we run KMP on it, the value in last cell will be our solution. In this problem, we don't need to use KMP to match strings but instead we use the lookup table in KMP to find the palindrome.

We add "#" here to force the match in reverse(s) starts from its first index What we do in KMP here is trying to find a match between prefix in s and a postfix in reverse(s). The match part will be palindrome substring.

Example:
input:

> catacb

Temp String:

> catacb # bcatac

KMP table:

> c a t a c b # b c a t a c
>
> 0 0 0 0 1 0 0 0 1 2 3 4 5

In the last cell, we got a value 5. It means in `s` we have a substring of length 5 that is palindrome.

So, above is my understanding of KMP any solution towards this problem. Below is my code



### 解释

是参考的 [LeetCode-Clean KMP solution with super detailed explanation](https://leetcode.com/problems/shortest-palindrome/discuss/60113/clean-kmp-solution-with-super-detailed-explanation) 写的，下面是我的总结:

一、题目要求只能在字符串的前面添加字符来将它转换为回文串，按照这种方式，直接的做法是: 找到从0开始的最长回文串，然后在head处添加剩余串的reverse，这样就现成了一个回文串了。

二、如何查找最长回文子串？回文串的特性是: 正着读和反着读都是一样的，那我就可以将原串和它的reverse拼接起来，使用KMP查找它们的公共前缀后缀，这样就能够得到它的长度。

### 完整代码



```c++
#include <iostream>
#include <string>
#include <unordered_map>
#include <array>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
#include <cstdlib>

using namespace std;

class Solution
{
public:
    string shortestPalindrome(string s)
    {
        auto failureArray = getFailureArray(s);
        int palindromeSubStrSize = failureArray.back();
        auto palindromeSubStr = s.substr(palindromeSubStrSize, s.size() - palindromeSubStrSize);
        std::reverse(palindromeSubStr.begin(), palindromeSubStr.end());
        return palindromeSubStr + s;
    }
    vector<int> getFailureArray(const string &s)
    {
        string tmp = s + "#" + string(s.rbegin(), s.rend());
        vector<int> failureArray(tmp.size(), 0);
        int i = 0, j = 1;
        while (j < tmp.size())
        {
            if (tmp[i] == tmp[j])
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
// Driver program to test above functions
int main()
{
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

