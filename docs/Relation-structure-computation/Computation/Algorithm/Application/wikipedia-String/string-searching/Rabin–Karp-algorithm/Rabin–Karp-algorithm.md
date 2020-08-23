# [Rabin–Karp algorithm](https://en.wikipedia.org/wiki/Rabin%E2%80%93Karp_algorithm)

> NOTE: 这个算法展示了进行字符串比较的另外一种思路： [hashing](https://en.wikipedia.org/wiki/Hash_function) 

In [computer science](https://en.wikipedia.org/wiki/Computer_science), the **Rabin–Karp algorithm** or **Karp–Rabin algorithm** is a [string-searching algorithm](https://en.wikipedia.org/wiki/String-searching_algorithm) created by [Richard M. Karp](https://en.wikipedia.org/wiki/Richard_M._Karp) and [Michael O. Rabin](https://en.wikipedia.org/wiki/Michael_O._Rabin) ([1987](https://en.wikipedia.org/wiki/Rabin–Karp_algorithm#CITEREFKarpRabin1987)) that uses [hashing](https://en.wikipedia.org/wiki/Hash_function) to find an exact match of a pattern string in a text. It uses a [rolling hash](https://en.wikipedia.org/wiki/Rolling_hash) to quickly filter out positions of the text that cannot match the pattern, and then checks for a match at the remaining positions. Generalizations of the same idea can be used to find more than one match of a single pattern, or to find matches for more than one pattern.

A practical application of the algorithm is [detecting plagiarism](https://en.wikipedia.org/wiki/Plagiarism_detection). Given source material, the algorithm can rapidly search through a paper for instances of sentences from the source material, ignoring details such as case and punctuation. Because of the abundance of the sought strings, single-string searching algorithms are impractical.

> NOTE:  [Detecting plagiarism](https://en.wikipedia.org/wiki/Plagiarism_detection)的一个特点就是它并不要求一字不差的精准匹配。

## Overview

Several string-matching algorithms, including the [Knuth–Morris–Pratt algorithm](https://en.wikipedia.org/wiki/Knuth–Morris–Pratt_algorithm) and the [Boyer–Moore string-search algorithm](https://en.wikipedia.org/wiki/Boyer–Moore_string-search_algorithm), reduce the worst-case time for string matching by extracting more information from each mismatch, allowing them to skip over positions of the text that are guaranteed not to match the pattern. The Rabin–Karp algorithm instead achieves its speedup by using a [hash function](https://en.wikipedia.org/wiki/Hash_function) to quickly perform an approximate check for each position, and then only performing an exact comparison at the positions that pass this approximate check.

A hash function is a function which converts every string into a numeric value, called its *hash value*; for example, we might have `hash("hello")=5`. If two strings are equal, their hash values are also equal. For a well-designed hash function, the opposite is true, in an approximate sense: strings that are unequal are very unlikely to have equal hash values. The Rabin–Karp algorithm proceeds by computing, at each position of the text, the hash value of a string starting at that position with the same length as the pattern. If this hash value equals the hash value of the pattern, it performs a full comparison at that position.

## The algorithm

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

This simple function works, but will result in statement 5 being executed more often than other more sophisticated rolling hash functions such as those discussed in the next section.

> NOTE: 上面这段话的意思是上面展示的rolling hash function是不够好的，在下一节中会介绍更好的同时也更加复杂的hash function

Good performance requires a good hashing function for the encountered data. If the hashing is poor (such as producing the same hash value for every input), then line 6 would be executed [O](https://en.wikipedia.org/wiki/Big-O_notation)(*n*) times (i.e. on every iteration of the loop). Because character-by-character comparison of strings with length *m* takes [O](https://en.wikipedia.org/wiki/Big-O_notation)(m) time, the whole algorithm then takes a worst-case [O](https://en.wikipedia.org/wiki/Big-O_notation)(*mn*) time.



## Hash function used

