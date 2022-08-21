# Rabin–Karp algorithm

核心思想:

一、approximate check 

wikipedia [Rabin–Karp algorithm](https://en.wikipedia.org/wiki/Rabin%E2%80%93Karp_algorithm) :

> It uses a [rolling hash](https://en.wikipedia.org/wiki/Rolling_hash) to quickly filter out positions of the text that cannot match the pattern, and then checks for a match at the remaining positions.



> The Rabin–Karp algorithm instead achieves its speedup by using a [hash function](https://en.wikipedia.org/wiki/Hash_function) to quickly perform an approximate check for each position, and then only performing an exact comparison at the positions that pass this approximate check.



> allowing them to skip over positions of the text that are guaranteed not to match the pattern

二、rolling hash

wikipedia [Rabin–Karp algorithm](https://en.wikipedia.org/wiki/Rabin%E2%80%93Karp_algorithm) # The algorithm

## wikipedia [Rabin–Karp algorithm](https://en.wikipedia.org/wiki/Rabin%E2%80%93Karp_algorithm)

> NOTE: 
>
> 这个算法展示了进行字符串比较的另外一种思路： [hashing](https://en.wikipedia.org/wiki/Hash_function) 

In [computer science](https://en.wikipedia.org/wiki/Computer_science), the **Rabin–Karp algorithm** or **Karp–Rabin algorithm** is a [string-searching algorithm](https://en.wikipedia.org/wiki/String-searching_algorithm) created by [Richard M. Karp](https://en.wikipedia.org/wiki/Richard_M._Karp) and [Michael O. Rabin](https://en.wikipedia.org/wiki/Michael_O._Rabin) ([1987](https://en.wikipedia.org/wiki/Rabin–Karp_algorithm#CITEREFKarpRabin1987)) that uses [hashing](https://en.wikipedia.org/wiki/Hash_function) to find an exact match of a pattern string in a text. It uses a [rolling hash](https://en.wikipedia.org/wiki/Rolling_hash) to quickly filter out positions of the text that cannot match the pattern, and then checks for a match at the remaining positions. Generalizations of the same idea can be used to find more than one match of a single pattern, or to find matches for more than one pattern.

> NOTE:
>
> 一、它过滤掉的是肯定不匹配的，剩余的地方就是可能匹配的，然后它在剩余的地方中进行精准的匹配，这个思想就是后面提及的"approximate check"

A practical application of the algorithm is [detecting plagiarism](https://en.wikipedia.org/wiki/Plagiarism_detection). Given source material, the algorithm can rapidly search through a paper for instances of sentences from the source material, ignoring details such as case(大小写) and punctuation(标点符号). Because of the abundance of the sought strings, single-string searching algorithms are impractical.

> NOTE:  
>
> 一、[Detecting plagiarism](https://en.wikipedia.org/wiki/Plagiarism_detection) 链接的是 "Content similarity detection"，显然它的一个特点就是它并不要求一字不差的精准匹配。
>
> 二、"Given source material, the algorithm can rapidly search through a paper for instances of sentences from the source material, ignoring details such as case and punctuation. Because of the abundance of the sought strings, single-string searching algorithms are impractical."
>
> "给定源材料，该算法可以快速搜索源材料中的句子实例，而忽略大小写和标点等细节。由于搜索字符串的丰富性，单字符串搜索算法是不切实际的。"

### Overview

Several string-matching algorithms, including the [Knuth–Morris–Pratt algorithm](https://en.wikipedia.org/wiki/Knuth–Morris–Pratt_algorithm) and the [Boyer–Moore string-search algorithm](https://en.wikipedia.org/wiki/Boyer–Moore_string-search_algorithm), reduce the worst-case time for string matching by extracting more information from each mismatch, allowing them to skip over positions of the text that are guaranteed not to match the pattern. The Rabin–Karp algorithm instead achieves its speedup by using a [hash function](https://en.wikipedia.org/wiki/Hash_function) to quickly perform an approximate check for each position, and then only performing an exact comparison at the positions that pass this approximate check.

> NOTE:
>
> 一、其实Rabin–Karp algorithm 的 "approximate check" 本质上也是 "skip over positions of the text that are guaranteed not to match the pattern"。
>
> 

A hash function is a function which converts every string into a numeric value, called its *hash value*; for example, we might have `hash("hello")=5`. If two strings are equal, their hash values are also equal. For a well-designed hash function, the opposite is true, in an approximate sense: strings that are unequal are very unlikely to have equal hash values. The Rabin–Karp algorithm proceeds by computing, at each position of the text, the hash value of a string starting at that position with the same length as the pattern. If this hash value equals the hash value of the pattern, it performs a full comparison at that position.

### The algorithm

The algorithm is as shown:

```pseudocode
1function RabinKarp(string s[1..n], string pattern[1..m])
2     hpattern := hash(pattern[1..m]);
3     for i from 1 to n-m+1
4         hs := hash(s[i..i+m-1])
5         if hs = hpattern
6             if s[i..i+m-1] = pattern[1..m]
7                 return i
8     return not found
```

Lines 2, 4, and 6 each require [O](https://en.wikipedia.org/wiki/Big-O_notation)(*m*) time. However, line 2 is only executed once, and line 6 is only executed if the hash values match, which is unlikely to happen more than a few times. Line 5 is executed O(*n*) times, but each comparison only requires constant time, so its impact is O(*n*). The issue is line 4.

Naively computing the hash value for the substring `s[i+1..i+m]` requires [O](https://en.wikipedia.org/wiki/Big-O_notation)(*m*) time because each character is examined. Since the hash computation is done on each loop, the algorithm with a naïve hash computation requires [O](https://en.wikipedia.org/wiki/Big-O_notation)(mn) time, the same complexity as a straightforward string matching algorithms. For speed, the hash must be computed in constant time. The trick is the variable `hs` already contains the previous hash value of `s[i..i+m-1]`. If that value can be used to compute the next hash value in constant time, then computing successive hash values will be fast.

The trick can be exploited using a [rolling hash](https://en.wikipedia.org/wiki/Rolling_hash). A rolling hash is a hash function specially designed to enable this operation. A trivial (but not very good) rolling hash function just adds the values of each character in the substring. This rolling hash formula can compute the next hash value from the previous value in constant time:

```
s[i+1..i+m] = s[i..i+m-1] - s[i] + s[i+m]
```

> NOTE:
>
> 一、通过前面的描述可知: rolling hash 属于 sliding window algorithm

This simple function works, but will result in statement 5 being executed more often than other more sophisticated rolling hash functions such as those discussed in the next section.

> NOTE: 
>
> 上面这段话的意思是上面展示的rolling hash function是不够好的，在下一节中会介绍更好的同时也更加复杂的hash function

Good performance requires a good hashing function for the encountered data. If the hashing is poor (such as producing the same hash value for every input), then line 6 would be executed [O](https://en.wikipedia.org/wiki/Big-O_notation)(*n*) times (i.e. on every iteration of the loop). Because character-by-character comparison of strings with length *m* takes [O](https://en.wikipedia.org/wiki/Big-O_notation)(m) time, the whole algorithm then takes a worst-case [O](https://en.wikipedia.org/wiki/Big-O_notation)(*mn*) time.



### Hash function used

*Main article:* [Rabin fingerprint](https://en.wikipedia.org/wiki/Rabin_fingerprint)



## Rabin fingerprint



### [LeetCode-1392. 最长快乐前缀](https://leetcode.cn/problems/longest-happy-prefix/) # 方法一：Rabin-Karp 字符串编码

Rabin-Karp 字符串编码是一种将字符串映射成整数的编码方式，可以看成是一种哈希算法。具体地，假设字符串包含的字符种类不超过 $\Sigma$（其中 $\Sigma$ 表示字符集），那么我们选一个大于等于 $|\Sigma|$ 的整数 \textit{base}base，就可以将字符串看成 $\textit{base}$ 进制的整数，将其转换成十进制数后，就得到了字符串对应的编码。

例如给定字符串 $s = abcas$，其包含的字符种类为 $3$（即 $abc$ 三种）。我们取 $\textit{base} = 9$，将字符串 $s$ 看成九进制数 $(0120)_9$，转换为十进制为 $99$，也就是说字符串 $abca$ 的编码为 $99$。一般地，计算编码值的公式如下：
$$
\textit{encrypt} = \sum_{i=0}^{|S|-1} s[i] * \textit{base}^{|S|-i-1}
$$

> NOTE:
>
> 一、上述公式是存在错误的，它的正确形式应该是:
> $$
> \textit{encrypt} = \sum_{i=0}^{|s|-1} s[i] * \textit{base}^{|s|-i-1}
> $$
> 在 [LeetCode-『 字符串哈希、KMP 』掌握模板，快乐其实很简单 🤣](https://leetcode.cn/problems/longest-happy-prefix/solution/by-flix-k4p3/) 中，也是使用的上述表达




这样做的好处是什么？我们可以发现一个结论：

> 两个字符串 $s$ 和 $t$ 相等，当且仅当它们的**长度相等**且**编码值**相等。

对于长度为 $k$ 的所有字符串，我们会将它们编码成位数为 $k$（包含前导零）的 $base$ 进制数，这是一个**单射**，因此结论成立。这样一来，我们就可以通过比较两个字符串的编码值判断它们是否相等了。

但聪明的读者有没有发现什么问题呢？当字符串的长度很长时，对应的编码值也会很大，这样可能就无法用一般语言中的整数类型（例如 `int`，`long long` 等）存储编码值了。对此，一般的解决方法是将**编码值**对一个数 $\textit{mod}$ 进行**取模**，使得其保持在**整数类型**的范围之内。

但这样就带来了一个问题，两个不相同但长度相等的字符串在取模前会有不同的编码值，在取模后的编码值就有可能相同了。换句话说，我们的编码方式不是**单射**，这种哈希算法会产生**碰撞**。然而我们并不需要过分担心这个问题：

1、假设读者为**防御者**，本题的作者为**攻击者**，**攻击者**希望构造出一些长度相等的字符串，使得其中存在两个字符串，它们不相同，但取模后的**编码值**相同；

2、由于**防御者**取模使用的数 $\textit{mod}$ 对于攻击者是未知的，因此攻击者的策略可以看成是随机产生长度相等的字符串，然后期望它们中会产生碰撞。

3、熟悉 [生日攻击](https://leetcode.cn/link/?target=https%3A%2F%2Fbaike.baidu.com%2Fitem%2F生日攻击) 或 [生日悖论](https://leetcode.cn/link/?target=https%3A%2F%2Fbaike.baidu.com%2Fitem%2F生日悖论) 的防御者可以知道，对于一个模数 $\textit{mod}$，攻击者在随机产生 $O(\sqrt{\textit{mod}})$ 个字符串时，会有大概率（超过 50%）产生碰撞，因此防御者可以将模数设置地尽量大来避免碰撞。防御者甚至可以设置多个模数 $\textit{mod}_1, \textit{mod}_2, \cdots, \textit{mod}_n$ ，只有两个字符串的编码值对这 $n$ 个数取模的值都分别相等，才会判定这两个字符串相同。

因此，只要我们将模数设置得很大，并且多选择一些模数，Rabin-Karp 字符串编码产生哈希碰撞的概率就微乎其微。一般来说，对于算法题而言，我们只需要选择一个模数即可，并且它最好是一个质数，例如 $10^9+7$。如有需要，还可以选择第二个模数 $10^9+9$。对于前文提到的 $\textit{base}$，一般也选择一个**质数**，例如本题中 $|\Sigma|=26$（即所有小写英文字母），我们可以选择 $\textit{base}=31$。

> NOTE: 
>
> 一、题目说明了只包含小写英文字母，所以 $|\Sigma|=26$ 

**算法**

我们从小到大枚举**前缀**的长度。对于枚举的长度 $i$，我们计算字符串 $s$ 长度为 $i$ 的前缀和后缀在 $\textit{base}=31, \textit{mod}=10^9+7$ 时的编码值。如果这两个编码值相等，我们就可以判定该前缀和后缀相等。

注意，我们可以使用 $O(1)$ 的时间通过长度为 $i-1$ 的前/后缀编码值计算出长度为 $i$ 的前/后缀编码值：

1、对于**前缀**而言，每在字符串最后多出一个新的字符，就相当于原编码值乘以 $\textit{base}$ 再加上新的字符的编码值；

2、对于**后缀**而言，每在字符串最前多出一个新的字符，就相当于原编码值加上新的字符的编码值乘以 $\textit{base}$ 的 $i-1$ 次幂。

> NOTE: 
>
> 一、上面这段话描述的是rolling hash的优势

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
    string longestPrefix(string s)
    {
        int n = s.size();
        int prefix = 0, suffix = 0;
        int base = 31, mod = 1000000007, mul = 1;
        int happy = 0;
        for (int i = 1; i < n; ++i) // i 表示的是长度
        {
            prefix = ((long long)prefix * base + (s[i - 1] - 97)) % mod;
            suffix = (suffix + (long long)(s[n - i] - 97) * mul) % mod;
            if (prefix == suffix)
            {
                happy = i;
            }
            // else // 对于用例 "ababab" ，它是无法通过的
            // {
            //     break;
            // }
            mul = (long long)mul * base % mod;
        }
        return s.substr(0, happy);
    }
};

// Driver program to test above functions
int main()
{
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

> NOTE:
>
> 一、在阅读上述code的时候，我的疑问:
>
> 1、为什么 `(long long)mul * base % mod` 需要 `% mode` ？
>
> 首先是因为 $1 <= s.length <= 10^5$ ，显然会导致 $mul * base$ 的值非常大

### wikipedia [Rabin fingerprint](https://en.wikipedia.org/wiki/Rabin_fingerprint)

The **Rabin fingerprinting scheme** is a method for implementing [fingerprints](https://en.wikipedia.org/wiki/Fingerprint_(computing)) using [polynomials](https://en.wikipedia.org/wiki/Polynomial) over a [finite field](https://en.wikipedia.org/wiki/Finite_field). 

#### Scheme

Given an *n*-bit message $m_{0},...,m_{n-1}$, we view it as a polynomial of degree *n*-1 over the [finite field](https://en.wikipedia.org/wiki/Finite_field) [GF(2)](https://en.wikipedia.org/wiki/Galois_field).
$$
f(x)=m_{0}+m_{1}x+\ldots +m_{{n-1}}x^{{n-1}}
$$
We then pick a random [irreducible polynomial](https://en.wikipedia.org/wiki/Irreducible_polynomial) $p(x)$ of degree *k* over GF(2), and we define the fingerprint of the message *m* to be the remainder $r(x)$ after division of $f(x)$ by $p(x)$ over GF(2) which can be viewed as a polynomial of degree *k* − 1 or as a *k*-bit number.

> NOTE:
>
> 一、" [irreducible polynomial](https://en.wikipedia.org/wiki/Irreducible_polynomial) "  中 "irreducible" 的意思是"不可约的"，显然它的含义和素数类似

