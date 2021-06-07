# labuladong [经典面试题：最长回文子串](https://mp.weixin.qq.com/s/ux6VSWAPwgOS32xlScr2kQ)

首先，明确一下什：**回文串就是正着读和反着读都一样的字符串**。

> NOTE: 
>
> 1、对称

比如说字符串`aba`和`abba`都是回文串，因为它们对称，反过来还是和本身一样。反之，字符串`abac`就不是回文串。

## 一、思考

可以看到回文串的的长度可能是奇数，也可能是偶数，这就添加了回文串问题的难度，解决该类问题的核心是**双指针**。下面就通过一道最长回文子串的问题来具体理解一下回文串问题：

![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4lLwdm05DtOeOPia4eSQF3HJWKPuI6XXSumtytXXkvgQPwO1szjiaWicF84yMiaIwmFyRic4RmocZz3qvw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

> NOTE: 
>
> 1、LeetCode [5. 最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)



```c++
string longestPalindrome(string s) {}
```

### 双指针思路

下面，就来说一下正确的思路，如何使用双指针。

**寻找回文串的问题核心思想是：从中间开始向两边扩散来判断回文串**。对于最长回文子串，就是这个意思：

```
for 0 <= i < len(s):
    找到以 s[i] 为中心的回文串
    更新答案
```

但是呢，我们刚才也说了，回文串的长度可能是奇数也可能是偶数，如果是`abba`这种情况，没有一个中心字符，上面的算法就没辙了。所以我们可以修改一下：

```
for 0 <= i < len(s):
    找到以 s[i] 为中心的回文串
    找到以 s[i] 和 s[i+1] 为中心的回文串
    更新答案
```

PS：读者可能发现这里的索引会越界，等会会处理。

> NOTE: 
>
> 1、需要罗列所有的可能性

## 二、代码实现

按照上面的思路，先要实现一个函数来寻找最长回文串，这个函数是有点技巧的：

![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4lLwdm05DtOeOPia4eSQF3HJ35jOicswr8BxewicbXvjKK3tpERQqORIqmJwddx7AXwxhjDm4QBicUoQw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)





为什么要传入两个指针`l`和`r`呢？**因为这样实现可以同时处理回文串长度为奇数和偶数的情况**：

```
for 0 <= i < len(s):
    # 找到以 s[i] 为中心的回文串
    palindrome(s, i, i)
    # 找到以 s[i] 和 s[i+1] 为中心的回文串
    palindrome(s, i, i + 1)
    更新答案
```

下面看下`longestPalindrome`的完整代码：

![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4lLwdm05DtOeOPia4eSQF3HJrMaOf73LSz2lXRQZ6kNWibG1ugxn3JH2IzXaMF8etna8F7BLF48iamiag/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



> NOTE: 
>
> 完整测试程序如下:
>
> ```C++
> #include<string>
> #include<iostream>
> using namespace std;
> string palindrome(string &s, int l, int r)
> {
> 	while (l >= 0 && r < s.size() && s[l] == s[r])
> 	{
> 		--l;
> 		++r;
> 	}
> 	return s.substr(l + 1, r - 1 - l);
> }
> string longestPalindrome(string &s)
> {
> 	string res;
> 	size_t len = s.size();
> 	for (int i = 0; i < len; ++i)
> 	{
> 		string s1 = palindrome(s, i, i);
> 		string s2 = palindrome(s, i, i + 1);
> 		res = s1.size() > res.size() ? s1 : res;
> 		res = s2.size() > res.size() ? s2 : res;
> 	}
> 	return res;
> }
> 
> int main()
> {
> 	string s = "babab";
> 	cout << longestPalindrome(s) << "\n";
> 	s = "babad";
> 	cout << longestPalindrome(s) << "\n";
> }
> // g++ test.cpp
> ```
>
> 输出如下:
>
> ```
> babab
> bab
> ```
>
> 上述程序的两个容易出错的地方:
>
> 1、`s.substr(l + 1, r - 1 - l);`
>
> `l` 和 `r`是对称的，两者必须是同步的，因此，前面的`while (l >= 0 && r < s.size() && s[l] == s[r])`条件不满足(要么是因为因为越界了、要么因为值不相等)而退出时，两者都必须要同步地后退一格
>
> 2、`substr`的原型如下:
>
> [`string substr (size_t pos = 0, size_t len = npos) const;`](https://www.cplusplus.com/reference/string/string/substr/) 
>
> 

至此，这道最长回文子串的问题就解决了，时间复杂度 O(N^2)，空间复杂度 O(1)。

值得一提的是，这个问题可以用动态规划方法解决，时间复杂度一样，但是空间复杂度至少要 O(N^2) 来存储 DP table。这道题是少有的动态规划非最优解法的问题。

另外，这个问题还有一个巧妙的解法，时间复杂度只需要 O(N)，不过该解法比较复杂，我个人认为没必要掌握。该算法的名字叫 Manacher's Algorithm（马拉车算法），有兴趣的读者可以自行搜索一下。