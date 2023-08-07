# [LeetCode-212. Word Search II-Hard](https://leetcode.cn/problems/word-search-ii/)



## 超时



```c++
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
    int rowCnt{0}, colCnt{0};
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        vector<string> result;
        unordered_set<string> resultSet;
        rowCnt = board.size(), colCnt = board[0].size();
        for (int rowIdx = 0; rowIdx < rowCnt; ++rowIdx) {
            for (int colIdx = 0; colIdx < colCnt; ++colIdx) {
                for (auto &&word: words) {
                    if (resultSet.contains(word)) {
                        continue;
                    }
                    /**
                     * https://stackoverflow.com/a/12377502
                     */
                    vector<vector<bool>> visited(rowCnt, vector<bool>(colCnt, false));
                    if (match(visited, rowIdx, colIdx, board, 0, word)) {
                        result.push_back(word);
                        resultSet.insert(word);
                    }
                }
            }
        }
        return result;
    }

    bool match(vector<vector<bool>> &visited, int rowIdx, int colIdx,
               const vector<vector<char>> &board, int wordIdx, const string &word) {
        if (wordIdx == word.size()) {
            return true;
        }
        if (rowIdx < 0 || rowIdx >= rowCnt) {
            return false;
        }
        if (colIdx < 0 || colIdx >= colCnt) {
            return false;
        }
        if (visited[rowIdx][colIdx]) {
            return false;
        }

        if (board[rowIdx][colIdx] == word[wordIdx]) {
            visited[rowIdx][colIdx] = true;

            bool result = match(visited, rowIdx, colIdx - 1, board, wordIdx + 1, word) ||
                          match(visited, rowIdx, colIdx + 1, board, wordIdx + 1, word) ||
                          match(visited, rowIdx - 1, colIdx, board, wordIdx + 1, word) ||
                          match(visited, rowIdx + 1, colIdx, board, wordIdx + 1, word);
            if (!result) {
                visited[rowIdx][colIdx] = false;
            }
            return result;
        }
        return false;

    }

};

int main() {
    vector<vector<char>> image{{'A', 'B', 'C', 'E'},
                               {'S', 'F', 'C', 'S'},
                               {'A', 'D', 'E', 'E'}};

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```



在一个matrix中搜索一个trie。



```c++
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct TrieNode
{
    bool isEnd_{false};
    std::string word_;
    std::vector<TrieNode *> children_{26, nullptr};
};

class Trie
{
    TrieNode *root_;

public:
    Trie() : root_{new TrieNode}
    {
    }
    void insert(const std::string &word)
    {
        TrieNode *node = root_;
        for (auto &&c : word)
        {
            if (node->children_[c - 'a'] == nullptr)
                node->children_[c - 'a'] = new TrieNode;
            node = node->children_[c - 'a'];
        }
        node->isEnd_ = true;
        node->word_ = word;
    }

    TrieNode *transition(const TrieNode *node, char c)
    {
        return node->children_[c - 'a'];
    }
    TrieNode *getRoot()
    {
        return root_;
    }
};
class Solution
{
    Trie trie;
    vector<string> foundWords;
    int rowCnt{0};
    int colCnt{0};

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        for (auto &&word : words)
        {
            trie.insert(word);
        }
        rowCnt = board.size();
        colCnt = board[0].size();
        for (int m = 0; m < rowCnt; ++m)
        {
            for (int n = 0; n < colCnt; ++n)
            {
                std::vector<std::vector<bool>> visited(rowCnt, std::vector<bool>(colCnt, false));
                dfs(board, m, n, visited, trie.getRoot());
            }
        }
        return foundWords;
    }

private:
    void dfs(const vector<vector<char>> &board, int rowIdx, int colIdx, vector<vector<bool>> &visited, const TrieNode *parentNode)
    {
        if (parentNode == nullptr)
        {
            return;
        }

        if (rowIdx < 0 || rowIdx >= rowCnt)
        {
            return;
        }
        if (colIdx < 0 || colIdx >= colCnt)
        {
            return;
        }
        if (visited[rowIdx][colIdx])
        {
            return;
        }
        TrieNode *node = trie.transition(parentNode, board[rowIdx][colIdx]);
        if (node == nullptr)
        {
            return;
        }
        if (node->isEnd_)
        {
            foundWords.push_back(node->word_);
        }
        visited[rowIdx][colIdx] = true;
        dfs(board, rowIdx, colIdx + 1, visited, node);
        dfs(board, rowIdx, colIdx - 1, visited, node);
        dfs(board, rowIdx + 1, colIdx, visited, node);
        dfs(board, rowIdx - 1, colIdx, visited, node);
        visited[rowIdx][colIdx] = false;
    }
};

// Driver code
int main()
{

    Solution s;

    return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

