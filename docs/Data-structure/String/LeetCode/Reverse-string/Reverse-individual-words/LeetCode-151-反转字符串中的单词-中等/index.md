# [LeetCode-151. 反转字符串中的单词-中等](https://leetcode.cn/problems/reverse-words-in-a-string/)



## 我的解题



```c++

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> st;
        string tmp;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
            {
                if (!tmp.empty())
                {
                    st.push_back(std::move(tmp));
                }
            }
            else
            {
                tmp.push_back(s[i]);
            }
        }
        if (!tmp.empty())
        {
            st.push_back(std::move(tmp));
        }
        string res;

        for (int i = st.size() - 1; i >= 0; --i)
        {
            res += st[i];
            if (i != 0)
            {
                res += " ";
            }
        }
        return res;
    }
};

int main()
{
    string s = "  hello world  ";
    Solution solu;
    cout << solu.reverseWords(s) << endl;
}
```



## [官方解题](https://leetcode.cn/problems/reverse-words-in-a-string/solution/fan-zhuan-zi-fu-chuan-li-de-dan-ci-by-leetcode-sol/)



```c++

#include <iostream>
#include <string>
#include <deque>

using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        int left = 0, right = s.size() - 1;
        // 去掉字符串开头的空白字符
        while (left <= right && s[left] == ' ')
            ++left;

        // 去掉字符串末尾的空白字符
        while (left <= right && s[right] == ' ')
            --right;

        deque<string> d;
        string word;

        while (left <= right)
        {
            char c = s[left];
            if (word.size() && c == ' ')
            {
                // 将单词 push 到队列的头部
                d.push_front(move(word));
                word = "";
            }
            else if (c != ' ')
            {
                word += c;
            }
            ++left;
        }
        d.push_front(move(word));

        string ans;
        while (!d.empty())
        {
            ans += d.front();
            d.pop_front();
            if (!d.empty())
                ans += ' ';
        }
        return ans;
    }
};

int main()
{
    string s = "  hello world  ";
    Solution solu;
    cout << solu.reverseWords(s) << endl;
}
```

