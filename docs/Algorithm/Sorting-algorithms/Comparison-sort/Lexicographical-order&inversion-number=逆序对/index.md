# Lexicographical order&inversion-number

lexicographical order: 字典序

inversion-number: 逆序对

## Lexicographical order

素材: 

[LeetCode-下一个排列算法详解：思路+推导+步骤，看不懂算我输！](https://leetcode.cn/problems/next-permutation/solution/xia-yi-ge-pai-lie-suan-fa-xiang-jie-si-lu-tui-dao-/) 

[baike-字典序](https://baike.baidu.com/item/%E5%AD%97%E5%85%B8%E5%BA%8F/7786229?fr=aladdin) 

[wikipedia-Lexicographical order](https://en.wikipedia.org/wiki/Lexicographic_order) 

[stackoverflow0What is lexicographical order?](https://stackoverflow.com/questions/45950646/what-is-lexicographical-order) # [A](https://stackoverflow.com/a/45950665) 

> lexicographical order **is** alphabetical order. The other type is numerical ordering. Consider the following values,
>
> ```
> 1, 10, 2
> ```
>
> Those values are in lexicographical order. 10 comes after 2 in numerical order, but 10 comes before 2 in "alphabetical" order.
>

例子:

```c++
[
1,10,100,101,102,103,104,105,106,107,108,109,11,110,111,112,113,12,13,14,15,16,17,18,19,
2,20,21,22,23,24,25,26,27,28,29,
3,30,31,32,33,34,35,36,37,38,39,
4,40,41,42,43,44,45,46,47,48,49,
5,50,51,52,53,54,55,56,57,58,59,
6,60,61,62,63,64,65,66,67,68,69,
7,70,71,72,73,74,75,76,77,78,79,
8,80,81,82,83,84,85,86,87,88,89,
9,90,91,92,93,94,95,96,97,98,99
]
```



### [baike-字典序](https://baike.baidu.com/item/%E5%AD%97%E5%85%B8%E5%BA%8F/7786229?fr=aladdin) 

对于数字1、2、3......n的排列，不同排列的先后关系是从左到右逐个比较对应的数字的先后来决定的。例如对于5个数字的排列 12354和12345，排列12345在前，排列12354在后。按照这样的规定，5个数字的所有的排列中最前面的是12345，最后面的是 54321。



### [wikipedia-Lexicographical order](https://en.wikipedia.org/wiki/Lexicographic_order) 





### Lexicographical order trie(digital tree) 

理解"lexicographical order trie(digital tree)"，是解决基于它的问题的基础。

"lexicographical order trie(digital tree)"使用trie来将所有的数字组织起来: 所有以1打头的数字位于同一棵子树、所有以2打头的数字位于同一棵子树、所有以3打头的数字位于同一棵子树......

![](./[lexicographic-order=字典序-trie](digital-radix-tree)-LeetCode-386-Lexicographical-Numbers-Medium.png)

> Reference: [PPPPjcute](https://leetcode.cn/u/ppppjcute/)  # [java 字典序的遍历](https://leetcode.cn/problems/lexicographical-numbers/solution/java-zi-dian-xu-de-bian-li-by-ppppjqute/) 

[pre-order](https://en.wikipedia.org/wiki/Tree_traversal#Pre-order,_NLR) DFS "lexicographical order trie(digital tree)"就能够得到所有以字典序排列的序列。

#### [LeetCode-386. 字典序排数-中等](https://leetcode.cn/problems/lexicographical-numbers/) 

[PPPPjcute](https://leetcode.cn/u/ppppjcute/)  # [java 字典序的遍历](https://leetcode.cn/problems/lexicographical-numbers/solution/java-zi-dian-xu-de-bian-li-by-ppppjqute/) 

- 这个算法的本质是通过**剪枝**一棵完全十叉树来生成字典树，它的第一棵子树是所有以1打头的，第二棵子树是所有以2打头的; 需要注意的是，这个tree的特殊性: 它的第一层节点的范围是1-9，后面的是0-9

- 它采用的是pre-order即先序遍历，它的模式非常类似于append-to-tail模式，即将每个node（一个数）append到result中去

##### 递归

python

```python
import unittest
from typing import *


class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        ans = []
        for digit in range(1, 10):
            self.dfs(digit, n, ans)
        return ans

    def dfs(self, num, n, ans: List[int]):
        if num > n:
            return
        ans.append(num)
        for digit in range(0, 10):
            self.dfs(num * 10 + digit, n, ans)


class TestSolution(unittest.TestCase):
    def test_solution(self):
        solution = Solution()
        ans = solution.lexicalOrder(13)
        self.assertEqual(ans, [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9])
        ans = solution.lexicalOrder(2)
        self.assertEqual(ans, [1, 2])


if __name__ == "__main__":
    solu = Solution()
    solu.lexicalOrder(10)

```



C++

```C++
//#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret; // 结果
        for (int number = 1; number <= 9; ++number) {
            DFS(number, n, ret);
        }
        return ret;
    }

    void DFS(int number, int n, vector<int> &ret) // pre-order
    {
        if (number > n) {
            return;
        }
        ret.push_back(number);
        for (int i = 0; i <= 9; ++i) {
            DFS(number * 10 + i, n, ret);
        }
    }
};

int main() {
    Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```



##### 迭代

```c++
// #include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int curr = 1;
        // 10叉树的先序遍历
        for (int i = 0; i < n; i++) {
            res.push_back(curr);
            if (curr * 10 <= n) {
                curr *= 10; //进入下一层
            } else {
                if (curr >= n)
                    curr /= 10; //如果这一层结束了
                curr += 1;
                while (curr % 10 == 0)
                    curr /= 10; //如果>10就要返回上一层
            }
        }
        return res;
    }
};

int main() {
    Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```



### Monotonic-stack解Max-min字典序subsequence(子序列)

[LeetCode-316. 去除重复字母](https://leetcode.cn/problems/remove-duplicate-letters/) ( LeetCode [1081. 不同字符的最小子序列](https://leetcode.cn/problems/smallest-subsequence-of-distinct-characters/) )

[LeetCode-402. 移掉K位数字](https://leetcode.cn/problems/remove-k-digits/)

[LeetCode-321. 拼接最大数](https://leetcode.cn/problems/create-maximum-number/)



参见:

1、labuladong [啊这，一道数组去重的算法题把东哥整不会了…](https://mp.weixin.qq.com/s/Yq49ZBEW3DJx6nXk1fMusw)

2、`Data-structure\Stack\Monotonic-stack单调栈\Monotonic-stack解Max-min-subsequence(子序列)`

3、[LeetCode-402. 移掉K位数字](https://leetcode.cn/problems/remove-k-digits/) # [一招吃遍力扣四道题，妈妈再也不用担心我被套路啦～](https://leetcode.cn/problems/remove-k-digits/solution/yi-zhao-chi-bian-li-kou-si-dao-ti-ma-ma-zai-ye-b-5/)



### 生成字典序序列

如何按照字典序来生成排列？

[LeetCode-31. 下一个排列](https://leetcode.cn/problems/next-permutation/) 

[LeetCode-556. 下一个更大元素 III](https://leetcode.cn/problems/next-greater-element-iii/)  

[LeetCode-386. 字典序排数](https://leetcode.cn/problems/lexicographical-numbers/)  

[LeetCode-440. 字典序的第K小数字](https://leetcode.cn/problems/k-th-smallest-in-lexicographical-order/) 



## LeetCode-逆序对、逆序数

[baike-反序数](https://baike.baidu.com/item/%E5%8F%8D%E5%BA%8F%E6%95%B0/8674073?fromtitle=%E9%80%86%E5%BA%8F%E6%95%B0&fromid=3334502&fr=aladdin)



### [wikipedia-Inversion (discrete mathematics)](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics))

In [computer science](https://en.wikipedia.org/wiki/Computer_science) and [discrete mathematics](https://en.wikipedia.org/wiki/Discrete_mathematics), an **inversion** in a sequence is a pair of elements that are out of their natural [order](https://en.wikipedia.org/wiki/Total_order).

[![img](https://upload.wikimedia.org/wikipedia/commons/thumb/8/80/Inversion_qtl1.svg/220px-Inversion_qtl1.svg.png)](https://en.wikipedia.org/wiki/File:Inversion_qtl1.svg)

Permutation with one of its inversions highlighted. An inversion may be denoted by the pair of places (2, 4) or the pair of elements (5, 2). The inversions of this permutation using element-based notation are: (3, 1), (3, 2), (5, 1), (5, 2), and (5,4).



### Example



https://qb.zuoyebang.com/xfe-question/question/7d0dad98b783f55d32ba3a4924d08c90.html



> 跟标准列相反序数的总和
> 比如说
> 标准列是1 2 3 4 5
> 那么 5 4 3 2 1 的逆序数算法：
> 看第二个,4之前有一个5,在标准列中5在4的后面,所以记1个
> 类似的,第三个 3 之前有 4 5 都是在标准列中3的后面,所以记2个
> 同样的,2 之前有3个,1之前有4个
> 将这些数加起来就是逆序数=1+2+3+4=10
> 再举一个 2 4 3 1 5
> 4 之前有0个
> 3 之前有1个
> 1 之前有3个
> 5 之前有0个
> 所以逆序数就是1+3=4
> 这样能明白吗



### LeetCode

[LeetCode-剑指 Offer 51. 数组中的逆序对-困难](https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/) 

[LeetCode-629. K个逆序对数组-困难](https://leetcode.cn/problems/k-inverse-pairs-array/) 

[LeetCode-LCR 170. 交易逆序对的总数-困难](https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/)	

[LeetCode-3193. 统计逆序对的数目-困难](https://leetcode.cn/problems/count-the-number-of-inversions/) 

[LeetCode-99. 恢复二叉搜索树-中等](https://leetcode.cn/problems/recover-binary-search-tree/) 

通过inorder-DFS(中序遍历)得到一个有序数组，这样将这个问题转换为有序数组中中调换两个数，找出被调换的两个数字(逆序对)。

