# geeksforgeeks [KMP Algorithm for Pattern Searching](https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/)



## KMP (Knuth Morris Pratt) Pattern Searching

The [Naive pattern searching algorithm](https://www.geeksforgeeks.org/searching-for-patterns-set-1-naive-pattern-searching/) doesn’t work well in cases where we see many matching characters followed by a mismatching character. Following are some examples.

```
   txt[] = "AAAAAAAAAAAAAAAAAB"
   pat[] = "AAAAB"

   txt[] = "ABABABCABABABCABABABC"
   pat[] =  "ABABAC" (not a worst case, but a bad case for Naive)
```

The KMP matching algorithm uses **degenerating property** (pattern having same **sub-patterns** appearing more than once in the pattern) of the pattern and improves the worst case complexity to `O(n)`. The basic idea behind KMP’s algorithm is: whenever we detect a mismatch (after some matches), we already know some of the characters in the text of the **next window**. We take advantage of this information to avoid matching the characters that we know will anyway match. Let us consider below example to understand this.

> NOTE:
>
> 一、翻译如下:
>
> "KMP 匹配算法使用模式的退化特性（具有相同子模式的模式在模式中出现不止一次），并将最坏情况复杂度提高到 O(n)。 KMP 算法背后的基本思想是：每当我们检测到不匹配时（在一些匹配之后），我们已经知道下一个窗口文本中的一些字符。我们利用这些信息来避免匹配我们知道无论如何都会匹配的字符。让我们考虑下面的例子来理解这一点。"

```
Matching Overview
txt = "AAAAABAAABA" 
pat = "AAAA"

We compare first window of txt with pat
txt = "AAAAABAAABA" 
pat = "AAAA"  [Initial position]
We find a match. This is same as Naive String Matching.

In the next step, we compare next window of txt with pat.
txt = "AAAAABAAABA" 
pat =  "AAAA" [Pattern shifted one position]
This is where KMP does optimization over Naive. In this second window, we only compare fourth A of pattern
with fourth character of current window of text to decide whether current window matches or not. Since we know first three characters will anyway match, we skipped matching first three characters. 

Need of Preprocessing?
An important question arises from the above explanation, how to know how many characters to be skipped. To know this, we pre-process pattern and prepare an integer array lps[] that tells us the count of characters to be skipped. 
```

> NOTE: 上述例子是比较特殊的，它给出的是一个完整匹配的例子而不是一般文章中举出的部分匹配的例子

## Preprocessing Overview:

1、KMP algorithm preprocesses `pat[]` and constructs an auxiliary `lps[]` of size `m` (same as size of pattern) which is used to skip characters while matching.

2、**name `lps` indicates longest proper prefix which is also suffix.**. A proper prefix is prefix with whole string **not** allowed. For example, prefixes of “ABC” are “”, “A”, “AB” and “ABC”. Proper prefixes are “”, “A” and “AB”. Suffixes of the string are “”, “C”, “BC” and “ABC”.

> NOTE: 
>
> 一、上面这段话区分了如下两个概念:
>
> 1、proper prefix
>
> 2、prefix
>
> 二、需要注意上面这段话中的suffix的概念，它并不要求是以它结尾的

3、We search for `lps` in sub-patterns. More clearly we focus on sub-strings of patterns that are either prefix and suffix.

4、For each sub-pattern `pat[0..i]` where `i = 0` to `m-1`, `lps[i]` stores length of the maximum matching proper prefix which is also a suffix of the sub-pattern `pat[0..i]`.

```
   lps[i] = the longest proper prefix of pat[0..i] 
              which is also a suffix of pat[0..i]. 
```



**Note :** `lps[i]` could also be defined as longest prefix which is also proper suffix. We need to use properly at one place to make sure that the whole substring is not considered.

## Examples of `lps[]` construction:

```c++
Examples of lps[] construction:
For the pattern “AAAA”, 
lps[] is [0, 1, 2, 3]

For the pattern “ABCDE”, 
lps[] is [0, 0, 0, 0, 0]

For the pattern “AABAACAABAA”, 
lps[] is [0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5]

For the pattern “AAACAAAAAC”, 
lps[] is [0, 1, 2, 0, 1, 2, 3, 3, 3, 4] 

For the pattern “AAABAAA”, 
lps[] is [0, 1, 2, 0, 1, 2, 3]
```




## Searching Algorithm:

Unlike [Naive algorithm](https://www.geeksforgeeks.org/searching-for-patterns-set-1-naive-pattern-searching/), where we slide the pattern by one and compare all characters at each shift, we use a value from `lps[]` to decide the next characters to be matched. The idea is to not match a character that we know will anyway match.

How to use `lps[]` to decide next positions (or to know a number of characters to be skipped)?

1、We start comparison of `pat[j]` with `j = 0` with characters of current window of text.

2、We keep matching characters `txt[i]` and `pat[j]` and keep incrementing `i` and `j` while `pat[j]` and `txt[i]` keep **matching**.

3、When we see a mismatch

- We know that characters `pat[0..j-1]` match with `txt[i-j…i-1]` (Note that `j` starts with `0` and increment it only when there is a match).
- We also know (from above definition) that `lps[j-1]` is count of characters of `pat[0…j-1]` that are both proper prefix and suffix.
- From above two points, we can conclude that we do not need to match these `lps[j-1]` characters with `txt[i-j…i-1]` because we know that these characters will anyway match. Let us consider above example to understand this.

