# [LeetCode-17. Letter Combinations of a Phone Number-middle](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/)



## DFS+backtrack+path



```c++
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
    vector<string> result;
    vector<string> letters;
public:
    vector<string> letterCombinations(string digits) {
        initLetters();
        string path;
        dfs(digits, 0, path);
        return result;
    }

private:
    void initLetters() {
        letters = vector<string>(10);
        for (int digit = 2; digit < 7; ++digit) {
            for (int j = 0; j < 3; ++j) {
                char c = (digit - 2) * 3 + 'a' + j;
                letters[digit].push_back(c);
            }
        }
        letters[7] = "pqrs";
        letters[8] = "tuv";
        letters[9] = "wxyz";
    }

    void dfs(const string &digits, int i, string &path) {
        if (i >= digits.size()) {
            if (!path.empty()) {
                result.push_back(path);
            }
            return;
        }
        int digit = digits[i] - '0';
        const string &lettersOfDigit = letters[digit];

        for (auto &&c: lettersOfDigit) {
            path.push_back(c);
            dfs(digits, i + 1, path);
            path.pop_back();
        }
    }
};

// Driver code
int main() {

    Solution s;
    return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

