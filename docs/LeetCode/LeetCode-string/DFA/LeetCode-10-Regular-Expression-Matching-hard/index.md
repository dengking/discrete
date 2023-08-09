# [LeetCode-10. Regular Expression Matching-hard](https://leetcode.cn/problems/regular-expression-matching/)



一、对于`*`，需要实现: 

0个

1个

多个

等情况。

二、如何判断是否匹配成功

```c++
s = "aaa"
p = "a*b"
```



显然将所有的字符串都吞完是不能作为判定的方法的。



## 版本1

```c++
struct Node {
    bool isTerminal_{false}; // 是否是终态
    std::unordered_map<char, Node *> children_;
    Node *parent_{nullptr};

    bool isRoot() {
        return parent_ == nullptr;
    }
};

class Solution {
    static constexpr char epsilonChar = 0;
    static constexpr char wildCardChar = '.';
    Node *root_;
    Node *errorNode_;
public:
    Solution() : root_{new Node}, errorNode_{new Node} {
    }

    bool isMatch(string s, string p) {
        buildDFA(p);
        Node *node = root_;
        for (auto &&c: s) {
            char cc;
            if (node->children_.contains(c)) {
                cc = c;
            } else if (node->children_.contains(wildCardChar)) {
                cc = wildCardChar;
            } else if (node->children_.contains(epsilonChar)) {
                cc = epsilonChar;
            } else {
                return false;
            }
            node = node->children_[cc];
        }
        return transition(epsilonChar, node)->isTerminal_;
    }

    Node *transition(char c, Node *node) {
        if (node->children_.contains(c)) {
            return node->children_[c];
        } else {
            return errorNode_;
        }
    }

    void buildDFA(string p) {
        Node *node = root_;
        for (int i = 0; i < p.size(); ++i) {
            char c = p[i];
            /**
             * 对当前node进行修饰
             */
            if (c == '*') {
                node->children_[p[i - 1]] = node; // 自引用: 处理多个
                node->parent_->children_[epsilonChar] = node; // epsilon转换: 处理0个
            } else {
                /**
                 * 需要知道parent、child
                 */
                Node *newNode = new Node;
                newNode->parent_ = node;
                node->children_[c] = newNode;
                node = newNode;//iteration
            }
        }
        Node *newNode = new Node;
        newNode->isTerminal_ = true; // 终态
        newNode->parent_ = node;
        node->children_[epsilonChar] = newNode;
    }
};
```

无法通过的用例:

```c++
"mississippi"
"mis*is*p*."
```

原因: 没有对 `epsilonChar` 进行特殊处理。



## 版本2

```c++
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct Node {
    bool isTerminal_{false}; // 是否是终态
    std::unordered_map<char, Node *> children_;
    Node *parent_{nullptr};

    bool isRoot() {
        return parent_ == nullptr;
    }
};

class Solution {
    static constexpr char epsilonChar = 0;
    static constexpr char wildCardChar = '.';
    Node *root_;
    Node *errorNode_;
public:
    Solution() : root_{new Node}, errorNode_{new Node} {
    }

    bool isMatch(string s, string p) {
        buildDFA(p);
        Node *node = root_;
        for (auto &&c: s) {
            if (!transition(c, node)) {
                return false;
            }
        }
        if (transition(epsilonChar, node)) {
            return node->isTerminal_;
        } else {
            return false;
        }
    }

    bool transition(char c, Node *&node) {
        if (node->children_.contains(c)) {
            node = node->children_[c];
            return true;
        } else if (node->children_.contains(wildCardChar)) { // 必须要先执行通配符的匹配
            node = node->children_[wildCardChar];
            return true;
        } else if (node->children_.contains(epsilonChar)) { // 执行一次空转换，到下一个节点去匹配
            node = node->children_[epsilonChar];
            return transition(c, node);
        } else {
            return false;
        }
    }

    void buildDFA(string p) {
        Node *node = root_;
        for (int i = 0; i < p.size(); ++i) {
            char c = p[i];
            /**
             * 对当前node进行修饰
             */
            if (c == '*') {
                node->children_[p[i - 1]] = node; // 自引用: 处理多个
                node->parent_->children_[epsilonChar] = node; // epsilon转换: 处理0个
            } else {
                /**
                 * 需要知道parent、child
                 */
                Node *newNode = new Node;
                newNode->parent_ = node;
                node->children_[c] = newNode;
                node = newNode;//iteration
            }
        }
        Node *newNode = new Node;
        newNode->isTerminal_ = true; // 终态
        newNode->parent_ = node;
        node->children_[epsilonChar] = newNode;
    }
};


// Driver code
int main() {

    Solution s;
    std::cout << s.isMatch("mississippi", "mis*is*p*.") << std::endl;
    std::cout << s.isMatch("aa", "aa") << std::endl;
    std::cout << s.isMatch("aa", "a") << std::endl;
    return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

无法通过的用例:

```c++
s = "aaa"
p = "a*a"
```



对于同一个字符 `a`，有两个转换。

## 版本3

```c++
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct Node {
    bool isTerminal_{false}; // 是否是终态
    std::unordered_map<char, Node *> children_{};
    Node *parent_{nullptr};

    bool isRoot() {
        return parent_ == nullptr;
    }
};

class Solution {
    static constexpr char epsilonChar = 0;
    static constexpr char wildCardChar = '.';
    Node *root_;
    Node *errorNode_;
public:
    Solution() : root_{new Node}, errorNode_{new Node} {
    }

    bool isMatch(string s, string p) {
        buildDFA(p);
        Node *node = root_;
        for (auto &&c: s) {
            if (!transition(c, node)) {
                return false;
            }
        }
        if (transition(epsilonChar, node)) {
            return node->isTerminal_;
        } else {
            return false;
        }
    }

    bool transition(char c, Node *&node) {
        if (node->children_.contains(c)) {
            node = node->children_[c];
            return true;
        } else if (node->children_.contains(wildCardChar)) { // 必须要先执行通配符的匹配
            node = node->children_[wildCardChar];
            return true;
        } else if (node->children_.contains(epsilonChar)) { // 执行一次空转换，到下一个节点去匹配
            node = node->children_[epsilonChar];
            return transition(c, node);
        } else {
            return false;
        }
    }

    bool transition2Self(Node *node, char c) {
        if (node->children_.contains(c)) {
            Node *node1 = node->children_[c];
            if (node == node1) {
                return true;
            }
        }
        return false;
    }

    bool epsilonTransition2Me(Node *node) {
        if (node->parent_->children_.contains(epsilonChar)) {
            return node == node->parent_->children_[epsilonChar];
        }
        return false;
    }

    void buildDFA(string p) {
        Node *node = root_;
        for (int i = 0; i < p.size(); ++i) {
            char c = p[i];
            /**
             * 对当前node进行修饰
             */
            if (c == '*') {
                node->children_[p[i - 1]] = node; // 自引用: 处理多个
                node->parent_->children_[epsilonChar] = node; // epsilon转换: 处理0个
            } else {
                /**
                 * 处理诸如 "a*a" 的case，将它转换为 "a+" 的
                 */
                if (transition2Self(node, c) && epsilonTransition2Me(node)) {
                    node->parent_->children_.erase(node->parent_->children_.find(epsilonChar));
                } else {
                    /**
                     * 需要知道parent、child
                     */
                    Node *newNode = new Node;
                    newNode->parent_ = node;
                    node->children_[c] = newNode;
                    node = newNode;//iteration
                }
            }
        }
        Node *newNode = new Node;
        newNode->isTerminal_ = true; // 终态
        newNode->parent_ = node;
        node->children_[epsilonChar] = newNode;
    }
};


// Driver code
int main() {

    Solution s1;
    std::cout << s1.isMatch("mississippi", "mis*is*p*.") << std::endl;

    Solution s2;
    std::cout << s2.isMatch("aa", "aa") << std::endl;

    Solution s3;
    std::cout << s3.isMatch("aa", "a") << std::endl;

    Solution s4;
    std::cout << s4.isMatch("aaa", "a*a") << std::endl;
    return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

无法通过的用例

```c++
s = "aaa"
p = "ab*a*c*a"
```

这个bad case其实和上面的bad case相同。

```c++
s = "aaa"
p = "a*a"
```



本质上是有多条到达终止状态的path，应该尽可能的选择其中的一条，所以这个地方也需要加上一个回溯，所以这道题其实和 [LeetCode-212. Word Search II-Hard](https://leetcode.cn/problems/word-search-ii/) 有点类似。



## 版本4

```c++
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct Node {
    bool isTerminal_{false}; // 是否是终态
    std::unordered_map<char, Node *> children_{};
    Node *parent_{nullptr};

    bool isRoot() {
        return parent_ == nullptr;
    }
};

class Solution {
    static constexpr char epsilonChar = 0;
    static constexpr char wildCardChar = '.';
    Node *root_;
public:
    Solution() : root_{new Node} {
    }

    bool isMatch(string s, string p) {
        buildDFA(std::move(p));
        return dfsDFA(s, 0, root_);
    }

    bool dfsDFA(const string &s, int i, Node *&node) {
        if (i >= s.size()) {
            if (node->children_.contains(epsilonChar)) {
                return node->children_[epsilonChar]->isTerminal_;
            } else {
                return false;
            }
        }
        char c = s[i];
        for (auto&&[transitionChar, nextNode]: node->children_) {
            if (transitionChar == c) {
                if (dfsDFA(s, i + 1, nextNode)) {
                    return true;
                }
            }
            if (transitionChar == wildCardChar) {
                if (dfsDFA(s, i + 1, nextNode)) {
                    return true;
                }
            }
            /**
             * 匹配 *
             */
            if (transitionChar == epsilonChar && transition2Self(nextNode)) {
                if (dfsDFA(s, i, nextNode)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool transition2Self(Node *node) {
        for (auto&&[transitionChar, nextNode]: node->children_) {
            if (node == nextNode) {
                return true;
            }
        }
        return false;
    }

    bool transition2Self(Node *node, char c) {
        if (node->children_.contains(c)) {
            Node *node1 = node->children_[c];
            if (node == node1) {
                return true;
            }
        }
        return false;
    }

    bool epsilonTransition2Me(Node *node) {
        if (node->parent_->children_.contains(epsilonChar)) {
            return node == node->parent_->children_[epsilonChar];
        }
        return false;
    }

    void buildDFA(string p) {
        Node *node = root_;
        for (int i = 0; i < p.size(); ++i) {
            char c = p[i];
            /**
             * 对当前node进行修饰
             */
            if (c == '*') {
                node->children_[p[i - 1]] = node; // 自引用: 处理多个
                node->parent_->children_[epsilonChar] = node; // epsilon转换: 处理0个
            } else {
                /**
                * 处理诸如 "a*a" 的case，将它转换为 "a+" 的
                */
                /*
                if (transition2Self(node, c) && epsilonTransition2Me(node)) {
                    node->parent_->children_.erase(node->parent_->children_.find(epsilonChar));
                } else {*/
                /**
                 * 需要知道parent、child
                 */
                Node *newNode = new Node;
                newNode->parent_ = node;
                node->children_[c] = newNode;
                node = newNode;//iteration
                /*}*/
            }
            /**
            * 处理诸如 "a*a" 的case，将它转换为 "a+" 的
            */
            Node *newNode = new Node;
            newNode->isTerminal_ = true; // 终态
            newNode->parent_ = node;
            node->children_[epsilonChar] = newNode;
        }
    }
};


// Driver code
int main() {

    Solution s1;
    std::cout << s1.isMatch("mississippi", "mis*is*p*.") << std::endl;

    Solution s2;
    std::cout << s2.isMatch("aa", "aa") << std::endl;

    Solution s3;
    std::cout << s3.isMatch("aa", "a") << std::endl;

    Solution s4;
    std::cout << s4.isMatch("aaa", "a*a") << std::endl;
    return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```





