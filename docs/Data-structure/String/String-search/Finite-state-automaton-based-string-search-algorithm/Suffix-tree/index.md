# Suffix tree、Suffix array、

---

> Reference:
>
> - [CS166 String](https://web.stanford.edu/class/cs166/) 
>  - [Tries and Suffix Trees](https://web.stanford.edu/class/cs166/lectures/04/Slides04.pdf) 
>   - [Suffix and LCP Arrays](https://web.stanford.edu/class/cs166/lectures/05/Slides05.pdf)  
> 
>---

[CS166 String](https://web.stanford.edu/class/cs166/) # [Tries and Suffix Trees](https://web.stanford.edu/class/cs166/lectures/04/Slides04.pdf) 

> On Thursday, we’ll see the **suffix array** and **LCP array**, which are a more space- efficient way of encoding **suffix trees**.



## Suffix tree



### wikipedia [Suffix tree](https://en.wikipedia.org/wiki/Suffix_tree)



### gpt-4-vision Ukkonen's algorithm

Building a suffix tree is a more complex task than building a suffix array. A suffix tree is a compressed trie containing all the suffixes of the given text as their keys and positions in the text as their values. Suffix trees are a powerful data structure for many string processing and computational biology tasks.

Here's a basic Python implementation of a suffix tree using Ukkonen's algorithm, which builds the suffix tree in O(n) time complexity:





## Suffix array



### wikipedia [Suffix array](https://en.wikipedia.org/wiki/Suffix_array)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a **suffix array** is a sorted [array](https://en.wikipedia.org/wiki/Array_data_structure) of all [suffixes](https://en.wikipedia.org/wiki/Suffix_(computer_science)) of a [string](https://en.wikipedia.org/wiki/String_(computer_science)). It is a data structure used in, among others, full-text indices, data-compression algorithms, and the field of [bibliometrics](https://en.wikipedia.org/wiki/Bibliometrics).

#### Construction algorithms

One of the first algorithms to achieve all goals is the SA-IS algorithm of [Nong, Zhang & Chan (2009)](https://en.wikipedia.org/wiki/Suffix_array#CITEREFNongZhangChan2009). The algorithm is also rather simple (< 100 [LOC](https://en.wikipedia.org/wiki/Source_lines_of_code)) and can be enhanced to simultaneously construct the [LCP array](https://en.wikipedia.org/wiki/LCP_array).[[7\]](https://en.wikipedia.org/wiki/Suffix_array#cite_note-FOOTNOTEFischer2011-7) The SA-IS algorithm is one of the fastest known suffix array construction algorithms. A careful implementation by Yuta Mori[[8\]](https://en.wikipedia.org/wiki/Suffix_array#cite_note-8) outperforms most other linear or super-linear construction approaches.



### chatgpt SA-IS (Suffix Array Induced Sorting) algorithm

The SA-IS (Suffix Array Induced Sorting) algorithm is an efficient algorithm for constructing the suffix array of a string. It was introduced by Ge Nong, Sen Zhang, and Wai Hong Chan in 2009. The SA-IS algorithm has a linear time complexity of O(n), where n is the length of the input string.

Here is a high-level overview of the SA-IS algorithm:

1. Identify the type of each character in the string as either S-type or L-type. An S-type character is smaller than the character to its right, while an L-type character is larger.
2. Identify the LMS (leftmost S-type) characters in the string.
3. Sort the LMS characters using a **bucket sort** or any other stable sorting algorithm.
4. Assign unique names to the sorted LMS substrings.
5. Construct the reduced string by replacing each LMS substring with its corresponding name.
6. Recursively construct the suffix array of the reduced string.
7. Use the suffix array of the reduced string to induce the suffix array of the original string.
8. Merge the sorted LMS substrings to obtain the final sorted suffix array.

The SA-IS algorithm is more efficient than other suffix array construction algorithms, such as the naive sorting-based approach or the prefix-doubling algorithm. It achieves linear time complexity by utilizing the properties of LMS substrings and performing efficient sorting and merging operations.

Implementing the SA-IS algorithm from scratch can be complex, but there are open-source libraries and existing implementations available in various programming languages that you can use. These libraries often provide optimized and well-tested implementations of the SA-IS algorithm.

I hope this gives you a good understanding of the SA-IS algorithm. Let me know if you have any further questions!

## LCP array

### wikipedia [LCP array](https://en.wikipedia.org/wiki/LCP_array)



## LeetCode

https://leetcode.cn/tag/suffix-array/problemset/