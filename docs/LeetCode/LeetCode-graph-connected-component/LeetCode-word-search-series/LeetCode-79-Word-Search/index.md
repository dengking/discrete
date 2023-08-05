# [LeetCode-79. Word Search-middle](https://leetcode.cn/problems/word-search/)



## DFS、backtrack

本质上是在graph中寻找一条path，非常类似于泛洪水算法。

```c++
#include <vector>
#include <string>

using namespace std;

class Solution {
    int rowCnt{0}, colCnt{0};
public:
    bool exist(vector<vector<char>> &board, string word) {
        rowCnt = board.size(), colCnt = board[0].size();
        for (int rowIdx = 0; rowIdx < rowCnt; ++rowIdx) {
            for (int colIdx = 0; colIdx < colCnt; ++colIdx) {
                /**
                 * https://stackoverflow.com/a/12377502
                 */
                vector<vector<bool>> visited(rowCnt, vector<bool>(colCnt, false));
                if (match(visited, rowIdx, colIdx, board, 0, word)) {
                    return true;
                }
            }
        }
        return false;
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
            if (!result) { // 不要忘记回溯
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
    Solution s;
    s.exist(image, "ABCCED");

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

