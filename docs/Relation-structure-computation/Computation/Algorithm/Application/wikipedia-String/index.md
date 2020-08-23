# 关于本章

本章讲述与字符串相关的算法。



## algorithm to judge whether two string has substring in common 

[Finding all the common substrings of given two strings](https://stackoverflow.com/questions/34805488/finding-all-the-common-substrings-of-given-two-strings)

[Check if two strings have a common substring](https://www.geeksforgeeks.org/check-two-strings-common-substring/)

[longest common substring problem](https://en.wikipedia.org/wiki/Longest_common_substring_problem)

suffix tree



### suffix tree

[Ukkonen's suffix tree algorithm in plain English](https://stackoverflow.com/questions/9452701/ukkonens-suffix-tree-algorithm-in-plain-english)

https://stackoverflow.com/questions/tagged/suffix-tree?tab=Active



### 使用编辑距离



### 一种python实现

```python
def get_num_of_word_in_common(word1, word2):
    """公共词的个数"""
    return len(Counter(word1) & Counter(word2))
```

