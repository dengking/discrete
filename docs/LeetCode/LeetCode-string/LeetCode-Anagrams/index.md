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



```python

from typing import *


class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        def char_ord2index(c: str):
            return ord(c) - ord('a')

        s_len, p_len = len(s), len(p)

        if s_len < p_len:
            return []

        ans = []
        # 记录need和window的各个字符差距的个数
        # count[i] == 0: 表示need 和 window相同
        # count[i] >  0: 表示need 比 window多
        # count[i] <  0: 表示need 比 window少
        count = [0] * 26
        for i in range(p_len):
            count[char_ord2index(s[i])] += 1  # 要求则加1
            count[char_ord2index(p[i])] -= 1  # 满足了要求则减去1

        # window 和 need 中，不匹配(字符数量不相同)的字符的个数
        differ = [c != 0 for c in count].count(True)

        if differ == 0:
            ans.append(0)

        for left in range(s_len - p_len):
            left_c = s[left]  # 即将移出window
            left_c_idx = char_ord2index(left_c)  # 即将移出window
            # count[left_c_idx] == 1表示:
            # need中的left_c的个数比window中的left_c的个数多一个，此时left_c即将移入到window中，显然这个字符的差异即将消除
            if count[left_c_idx] == 1:
                differ -= 1
            # count[left_c_idx] == 0表示:
            # need中的left_c的个数和window中的left_c的个数相同
            elif count[left_c_idx] == 0:
                differ += 1
            count[left_c_idx] -= 1

            right_c = s[left + p_len]  # 即将移入window
            right_c_idx = char_ord2index(right_c)  # 即将移入window
            if count[right_c_idx] == -1:  # 窗口中字母 s[i+p_len] 的数量与字符串 p 中的数量从不同变得相同
                differ -= 1
            elif count[right_c_idx] == 0:  # 窗口中字母 s[i+p_len] 的数量与字符串 p 中的数量从相同变得不同
                differ += 1
            count[right_c_idx] += 1

            if differ == 0:
                ans.append(left + 1)

        return ans

```

