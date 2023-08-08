# [LeetCode-211. Design Add and Search Words Data Structure-middle](https://leetcode.cn/problems/design-add-and-search-words-data-structure/)



## dfs



```c++
#include <vector>
#include <iostream>

using namespace std;

class WordDictionary {
    struct TrieNode {
        bool isEnd_{false};
        std::vector<TrieNode *> children_ = std::vector<TrieNode *>(26);
    };
    TrieNode *root_;
public:
    WordDictionary() : root_{new TrieNode} {

    }

    void addWord(string word) {
        TrieNode *node = root_;
        for (auto &&c: word) {
            if (node->children_[c - 'a'] == nullptr) node->children_[c - 'a'] = new TrieNode;
            node = node->children_[c - 'a']; // move to next
        }
        node->isEnd_ = true;
    }

    bool search(string word) {
        return search(root_, word, 0);
    }

    /**
     * node在word[idx]下的转移
     * @param node
     * @param word
     * @param idx
     * @return
     */
    bool search(TrieNode *node, const string &word, int idx) {
        if (idx == word.size()) { // 匹配完成；需要注意的是: 它需要放在下个stop condition之上，比如匹配a..
            if (node == nullptr) {
                return false;
            } else {
                return node->isEnd_;
            }
        }
        if (node == nullptr) {
            return false;
        }
        char c = word[idx];
        if (c == '.') {
            for (auto &&child: node->children_) {
                if (search(child, word, idx + 1)) {
                    return true;
                } else {
                    continue;
                }
            }
            return false;
        } else {
            if (node->children_[c - 'a'] == nullptr) return false;
            return search(node->children_[c - 'a'], word, idx + 1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {

    WordDictionary w;
    w.addWord("a");
    std::cout << w.search(".a") << std::endl;
    //w.search("a.");
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

see also: [宫水三叶【设计数据结构】Trie 运用题](https://mp.weixin.qq.com/s/TPVBlNBLlUpQKXK_XkR-3Q)