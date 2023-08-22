# [LeetCode-10. Regular Expression Matching-hard](https://leetcode.cn/problems/regular-expression-matching/)-BFS 

epsilon transition 是为了找到所有可能的**起始状态**，这样后续的匹配可以从这些可能的起始状态开始匹配。

这种方式直接将regex看做是NFA，它不需要显示地构造出一个DFA，这样避免对 undeterministic 的讨论: 对于同一状态，遇到相同字符的时候，出现多种转换方式的讨论。



## LeetCode [六硝基六氮杂三环十四](https://leetcode.cn/u/liu-xiao-ji-liu-dan-za-san-huan-shi-si-wan-dui-er-fu-zan/) [10、 正则表达式匹配：有限自动机（FA）算法](https://leetcode.cn/problems/regular-expression-matching/solutions/1532116/10-zheng-ze-biao-da-shi-pi-pei-by-liu-xi-wi4p/)



输入`s = "abcacb", p = "a*b*cb*.*a.b"`，看看算法是怎么工作的。

![1.png](https://pic.leetcode-cn.com/1654156270-ZfRIeG-1.png)



```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        """
        :param s: 待匹配的字符串s.
        :param p: 正则表达式p.
        :return: 是否成功匹配。
        """
        now_state_set = {0}  # 表示现在可能处于的所有状态的集合。状态state表示接下来匹配p[state].

        def update_now_state_set(char: str) -> None:
            """
            :param char: 接续字符char后更新一下now_state_set. 如果char是'~'，表示后继字符为空。
            :return: 无。
            """
            nonlocal now_state_set
            tmp_state_set = set()  # 用一个临时变量tmp_state_set记录结果。
            if char == '~':
                # 将直接跳过_*的所有后继状态加入now_state_set.
                for state in now_state_set:
                    tmp_state_set.add(state)
                    possible_state = state
                    while possible_state + 1 < len(p) and p[possible_state + 1] == '*':
                        possible_state += 2
                        tmp_state_set.add(possible_state)
            else:
                # 接续字符char后的所有后继状态构成now_state_set.
                for state in now_state_set:
                    if state >= len(p) or p[state] not in {char, '.'}:
                        # state是终止状态，或者p[state]不匹配，此时匹配失败。
                        continue
                    if state + 1 < len(p) and p[state + 1] == '*':
                        # 从状态state开始，匹配了一个char*之后，还可以停留在该状态。
                        tmp_state_set.add(state)
                    else:
                        tmp_state_set.add(state + 1)
            now_state_set = tmp_state_set

        update_now_state_set('~')
        for char in s:
            update_now_state_set(char)  # 首先尝试
            update_now_state_set('~')

        if len(p) in now_state_set:
            # 如果now_state可能是终止状态len(p)，即存在一种方法进行匹配，返回True.
            return True
        return False


if __name__ == '__main__':
    s = Solution()
    s.isMatch("aa", "a*")

```



它的这种搜索方式更加类似于BFS，它在每一步只都加入了epsilon transition。

它的这种搜索方式，能够穷举出所有的可能性，即使相同的字符有两种transition，它都会去尝试。



对于每一步，都有两个选择:

1、character transition

2、epsilon transition



思考: 能否DFS来实现呢？



## C++

```c++
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;


class Solution {
    static constexpr char epsilonChar = 0;
    static constexpr char wildCardChar = '.';
    static constexpr char KleenStarChar = '*';
    std::unordered_set<int> states_;
public:
    Solution() {
    }


    bool isMatch(string s, string p) {
        states_ = {0};
        transition(epsilonChar, p); // 这其实是一个初始化，将所有的起始状态全部加入进来
        for (auto &&c: s) {
            transition(c, p);
            transition(epsilonChar, p);
        }
        return states_.contains(p.size());
    }

private:
    void transition(char c, const string &p) {
        std::unordered_set<int> newStates{};
        if (c == epsilonChar) {
            /**
             * 将*的所有后继状态加入 newStates 中，epsilon transition是为了找到所有可能的起始状态，这样后续的匹配可以从这些可能的起始状态开始匹配
             * 需要注意的是: epsilon transition需要保留原来的状态，因为它主要对应的是KleenStarChar的0
             */
            for (auto &&state: states_) {
                newStates.insert(state);// epsilon transition需要保留原来的状态，因为它主要对应的是KleenStarChar的0
                int nextState = state;
                while (nextState + 1 < p.size() && p[nextState + 1] == KleenStarChar) {
                    nextState = nextState + 2;
                    newStates.insert(nextState);
                }
            }
        } else {
            // 接续字符char后的所有后继状态构成newStates
            for (auto &&state: states_) {
                if (state >= p.size() or (p[state] != c && p[state] != wildCardChar)) {
                    // state是终止状态，或者p[state]不匹配，此时匹配失败。
                    continue;
                }
                /**
                 * 对应的是KleenStarChar的+
                 */
                if (state + 1 < p.size() and p[state + 1] == '*') {
                    // 从状态state开始，匹配了一个char*之后，还可以停留在该状态。
                    newStates.insert(state);
                } else {
                    newStates.insert(state + 1);
                }
            }

        }
        states_ = std::move(newStates);
    }
};


// Driver code
int main() {
    Solution s1;
    std::cout << s1.isMatch("aab", "c*a*b") << std::endl;

    /* Solution s2;
     std::cout << s2.isMatch("aa", "aa") << std::endl;

     Solution s3;
     std::cout << s3.isMatch("aa", "a") << std::endl;

     Solution s4;
     std::cout << s4.isMatch("aaa", "a*a") << std::endl;

     Solution s5;
     std::cout << s5.isMatch("bbbaccbbbaababbac", ".b*b*.*...*.*c*.") << std::endl;
 */
    return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

