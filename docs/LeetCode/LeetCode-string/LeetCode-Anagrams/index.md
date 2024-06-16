# Anagrams

字母异位词

## [LeetCode-49. Group Anagrams](https://leetcode.cn/problems/group-anagrams/)



### 解法一: 冗杂

```python
from typing import *


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        def get_word_dict(s: str) -> dict:
            d = {}
            for c in s:
                if c not in d:
                    d[c] = 0
                d[c] += 1
            return d

        # word_dict2words = {}
        # for s in strs:
        #     word_d = get_word_dict(s)
        #     if word_d not in word_dict2words:
        #         word_dict2words[word_d] = []
        #     word_dict2words[word_d].append(s)

        word_dicts = [get_word_dict(s) for s in strs]
        anagrams_group = [[strs[0]]]
        anagrams_dicts = [word_dicts[0]]
        for i in range(1, len(strs)):
            word = strs[i]
            word_dict = word_dicts[i]
            is_word_in_anagrams_group = False
            for j in range(0, len(anagrams_group)):
                if word_dict == anagrams_dicts[j]:
                    anagrams_group[j].append(word)
                    is_word_in_anagrams_group = True
                    break
            if not is_word_in_anagrams_group:
                anagrams_group.append([word])
                anagrams_dicts.append(word_dict)
        return anagrams_group

```



### 解法二: 将字符串进行排序

由于互为字母异位词的两个字符串包含的字母相同，因此对两个字符串分别进行排序之后得到的字符串一定是相同的，故可以将排序之后的字符串作为哈希表的键。



#### Python3



```python
from typing import *
import collections


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # https://docs.python.org/3/library/collections.html#collections.defaultdict
        mp = collections.defaultdict(list)

        for st in strs:
            key = "".join(sorted(st))  # https://docs.python.org/3/library/functions.html#sorted
            mp[key].append(st)

        return list(mp.values())

```



#### C++



```C++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string& str: strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};

```





## [LeetCode-242. Valid Anagram](https://leetcode.cn/problems/valid-anagram/)



```python

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)
       
```



## [LeetCode-438. 找到字符串中所有字母异位词-中等](https://leetcode.cn/problems/find-all-anagrams-in-a-string/) 
