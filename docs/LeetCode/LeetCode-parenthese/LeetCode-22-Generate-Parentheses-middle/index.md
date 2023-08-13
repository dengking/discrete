# [LeetCode-22. Generate Parentheses-middle](https://leetcode.cn/problems/generate-parentheses/)



## DFS+backtrack+path+prunc

labuladong [回溯算法最佳实践：合法括号生成](https://mp.weixin.qq.com/s/XVnoX-lBzColVvVXNkGc5g) 

```c++
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
    vector<string> result;
public:
    vector<string> generateParenthesis(int n) {
        string path;
        path.reserve(n * 2);
        dfs(0, n, path, 0, 0);
        return result;
    }

private:
    void dfs(int i, int n, string &path, int leftCnt, int rightCnt) {
        /**
         * 剪枝
         */
        if (leftCnt < rightCnt) {
            return;
        }
        /**
         * 剪枝
         */
        if (leftCnt > n) {
            return;
        }
        if (i == 2 * n) {
            if (leftCnt == rightCnt) {
                result.push_back(path);
            }
            return;
        }
        /**
         * 选择: 插入(
         */
        path.push_back('(');
        dfs(i + 1, n, path, leftCnt + 1, rightCnt);
        path.pop_back();
        /**
         * 选择: 插入)
         */
        path.push_back(')');
        dfs(i + 1, n, path, leftCnt, rightCnt + 1);
        path.pop_back();
    }
};

// Driver code
int main() {

    Solution s;
    return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



