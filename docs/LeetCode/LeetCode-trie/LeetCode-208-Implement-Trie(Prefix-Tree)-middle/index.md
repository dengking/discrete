# [LeetCode-208. Implement Trie (Prefix Tree)-Middle](https://leetcode.cn/problems/implement-trie-prefix-tree/)



参考的 宫水三叶[【设计数据结构】实现 Trie (前缀树)](https://mp.weixin.qq.com/s/DBTQyNYsEgmN0Vb5fbolUg)



## `TrieNode`的方式



```c++
#include <vector>
#include <string>

using namespace std;

class Trie {
    struct TrieNode {
        bool isEnd_{false};
        std::vector<TrieNode *> children_ = std::vector<TrieNode *>(26);
    };
    TrieNode *root_;
public:
    Trie() : root_{new TrieNode} {

    }

    void insert(string word) {
        TrieNode *node = root_;
        for (auto &&c: word) {
            if (node->children_[c - 'a'] == nullptr) node->children_[c - 'a'] = new TrieNode;
            node = node->children_[c - 'a']; // move to next
        }
        node->isEnd_ = true;
    }

    bool search(string word) {
        TrieNode *node = root_;
        for (auto &&c: word) {
            if (node->children_[c - 'a'] == nullptr) return false;
            node = node->children_[c - 'a'];
        }
        return node->isEnd_;
    }

    bool startsWith(string prefix) {
        TrieNode *node = root_;
        for (auto &&c: prefix) {
            if (node->children_[c - 'a'] == nullptr) return false;
            node = node->children_[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {


}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```



## 2D-array



```c++
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Trie {
    static constexpr std::size_t MAX_NODE_CNT = 1e5; // 最大节点个数

    std::vector<std::vector<int>> nodes;
    std::vector<int> isEnd; // 记录节点是否是end node
    int rowCnt{0};
public:
    Trie() : nodes(MAX_NODE_CNT, std::vector<int>(26, 0)), isEnd(MAX_NODE_CNT, 0) {

    }

    void insert(string word) {
        int nodeIdx = 0;
        for (auto &&c: word) {
            if (nodes[nodeIdx][c - 'a'] == 0)nodes[nodeIdx][c - 'a'] = ++rowCnt;
            nodeIdx = nodes[nodeIdx][c - 'a'];
        }
        ++isEnd[nodeIdx];
    }

    bool search(string word) {
        int nodeIdx = 0;
        for (auto &&c: word) {
            if (nodes[nodeIdx][c - 'a'] == 0)return false;
            nodeIdx = nodes[nodeIdx][c - 'a'];
        }
        return isEnd[nodeIdx];
    }

    bool startsWith(string prefix) {
        int nodeIdx = 0;
        for (auto &&c: prefix) {
            if (nodes[nodeIdx][c - 'a'] == 0)return false;
            nodeIdx = nodes[nodeIdx][c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

