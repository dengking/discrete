# Longest common substring





## wikipedia [Longest common substring problem](https://en.wikipedia.org/wiki/Longest_common_substring_problem)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), the **longest common substring problem** is to find a longest [string](https://en.wikipedia.org/wiki/String_(computer_science)) that is a [substring](https://en.wikipedia.org/wiki/Substring) of two or more strings. The problem may have multiple solutions. Applications include [data deduplication](https://en.wikipedia.org/wiki/Data_deduplication) and [plagiarism detection](https://en.wikipedia.org/wiki/Plagiarism_detection).



### Algorithms

> Draft:
>
> 一、algorithm to judge whether two string has substring in common 
>
> [Finding all the common substrings of given two strings](https://stackoverflow.com/questions/34805488/finding-all-the-common-substrings-of-given-two-strings)
>
> [Check if two strings have a common substring](https://www.geeksforgeeks.org/check-two-strings-common-substring/)
>
> [longest common substring problem](https://en.wikipedia.org/wiki/Longest_common_substring_problem)
>
> suffix tree
>
> 

#### Suffix tree

> Draft:
>
> 一、suffix tree
>
> [Ukkonen's suffix tree algorithm in plain English](https://stackoverflow.com/questions/9452701/ukkonens-suffix-tree-algorithm-in-plain-english)
>
> https://stackoverflow.com/questions/tagged/suffix-tree?tab=Active
>
> 

#### Dynamic programming



#### Draft

1. 使用编辑距离

2. 一种python实现

```python
def get_num_of_word_in_common(word1, word2):
    """公共词的个数"""
    return len(Counter(word1) & Counter(word2))
```







## [LeetCode-Longest Common Substring](https://leetcode.com/discuss/interview-question/1273766/longest-common-substring)