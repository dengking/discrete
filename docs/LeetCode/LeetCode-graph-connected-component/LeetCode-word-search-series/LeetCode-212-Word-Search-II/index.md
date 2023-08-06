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

