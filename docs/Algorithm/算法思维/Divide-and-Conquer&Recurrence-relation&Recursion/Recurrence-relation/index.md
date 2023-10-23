# Recurrence relation 递归关系



1、使用数学来描述算法，根据数学公式写出算法：

递推公式

现在需要对每个算法都写出其递归公式。

2、要写出算法的形式化描述(formal description)

## 书写递归公式

书写递归公式的几个要素：

1、初始条件

2、递归关系，递归关系往往对应这如下几种情况：

- 新加一个元素



在[Knuth–Morris–Pratt algorithm](https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm)中对算法的描述：

> The most straightforward algorithm, known as the "[Brute-force](https://en.wikipedia.org/wiki/Brute-force_search)" or "Naive" algorithm, is to look for a **word match** at each index `m`, the position in the string being searched, i.e. `S[m]`. At each position `m` the algorithm first checks for equality of the first character in the word being searched, i.e. `S[m] =? W[0]`. If a match is found, the algorithm tests the other characters in the word being searched by checking successive values of the word position index, `i`. The algorithm retrieves the character `W[i]` in the word being searched and checks for equality of the expression `S[m+i] =? W[i]`. If all successive characters match in `W` at position `m`, then a match is found at that position in the search string. If the index `m` reaches the end of the string then there is no match, in which case the search is said to "fail".





### 递归公式

## [n-Cubes](https://en.wikipedia.org/wiki/Hypercube)

《Discrete Mathematics and Its Applications》的10.2 Graph Terminology and Special Types of Graphs中有这样的描述：

> Note that you can construct the (n + 1)-cube $Q_{n+1}$ from the n-cube $Q_n$ by making two copies of $Q_n$ , prefacing the labels on the vertices with a 0 in one copy of $Q_n$ and with a 1 in the other copy of $Q_n$ , and adding edges connecting two vertices that have labels differing only in the first bit. 



### KMP failure function

KMP failure function的计算也有赖于递归关系的建立，参见[Computing the KMP failure function (f(k))](http://www.mathcs.emory.edu/~cheung/Courses/323/Syllabus/Text/Matching-KMP2.html)。



## One by one

一次处理一个元素，这是很多算法的运作方式：

- parsing
- [Knuth–Morris–Pratt algorithm](https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm)



这背后是算法和离散数学。



### 循环次数的确定

按照one by one的思路，非常多的算法最终都能够形式化成循环的处理，可能会嵌套多层循环。当将算法形式化为循环后进行实现的时候，一个非常重要的问题就是循环语句的实现：

- `for`语句一个非常重要的就是循环次数的确定，只有先确定好循环次数后，才能够写出正确的for循环
- ``while`语句可能涉及到的有：
  - 循环次数的确定
  - 终止条件的确定



下面以结合一些具体的算法来进行说明

### naive string search

Given a text `txt` and a pattern `pat`, prints all occurrences of `pat` in `txt`.

这个问题最终是可以形式化为两次`for`循环的，要想写出正确的`for`语句第一个问题就是：在`txt`一共要`pat`将进行多少次匹配？

其实回答这个问题并不是非常难，一个非常简单的技巧是进行**枚举**，我们可以从最最简单的情况进行枚举，设`txt`的长度是`txt_len`，`pat`的长度是`pat_len`：

- `txt_len`为2， `pat_len`为1，显然要进行2次匹配
- `txt_len`为4， `pat_len`为2，显然要进行3次匹配
- `txt_len`为4， `pat_len`为3，显然要进行2次匹配



显然要进行`txt_len - pat_len + 1`次匹配，所以第一层`for`循环就需要产生`txt_len - pat_len + 1`次循环。所以最终我们可以写出如下代码

```python
def brute_force_search(txt, pat):
    """
    Given a text txt and a pattern pat, prints all occurrences of pat in txt.
    https://www.geeksforgeeks.org/naive-algorithm-for-pattern-searching/
    :param txt:
    :param pat:
    :return:
    """
    txt_len = len(txt)
    pat_len = len(pat)
    for i in range(txt_len - pat_len + 1):
        for j in range(pat_len):
            if txt[i + j] != pat[j]:
                break
        if j == pat_len - 1:
            print(txt[i:i + pat_len])
        j = 0
```



## 建立递归关系

KMP算法也存在递归关系。


