# Jump game系列

|                                                              |      |      |
| ------------------------------------------------------------ | ---- | ---- |
| [LeetCode-55. 跳跃游戏-中等](https://leetcode.cn/problems/jump-game/) |      |      |
| [LeetCode-45. 跳跃游戏 II-中等](https://leetcode.cn/problems/jump-game-ii/) |      |      |
| [LeetCode-1306. 跳跃游戏 III-中等](https://leetcode.cn/problems/jump-game-iii/) |      |      |
| [LeetCode-1345. 跳跃游戏 IV-困难](https://leetcode.cn/problems/jump-game-iv/) |      |      |
| [LeetCode-1340. 跳跃游戏 V-困难](https://leetcode.cn/problems/jump-game-v/) |      |      |
| [LeetCode-1696. 跳跃游戏 VI-中等](https://leetcode.cn/problems/jump-game-vi/) |      |      |
| [LeetCode-1871. 跳跃游戏 VII-中等](https://leetcode.cn/problems/jump-game-vii/) |      |      |
| [LeetCode-1871. 跳跃游戏 VII-中等](https://leetcode.cn/problems/jump-game-vii/) |      |      |



towardsdatascience [Tackling Jump Game Problems (LeetCode)](https://towardsdatascience.com/tackling-jump-game-problems-leetcode-e0a718e7dfba)

tutorialcup [Jump Game Leetcode Solution](https://www.tutorialcup.com/leetcode-solutions/jump-game-leetcode-solution.htm)



## [LeetCode-55. Jump Game-middle](https://leetcode.cn/problems/jump-game/)



### BFS

```C++
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        std::set<int> states;
        states.insert(0);
        while (!states.empty()) {
            int idx = *states.rbegin();
            for (int step = nums[idx]; step >= 0; --step) {
                int next = idx + step;
                if (next >= nums.size() - 1) {
                    return true;
                }
                if (!states.contains(next)) {
                    states.insert(next);
                }
            }
            states.erase(states.find(idx));
        }
        return false;
    }
};

// Driver code
int main() {

    Solution s;
    return 0;

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

上述程序在如下用例超时: 

https://leetcode.cn/problems/jump-game/submissions/455780415/



### DFS + memoization + prune

这是一个存在性问题，所以找到一个解即可，所以优先使用DFS，如果已经明确某个状态无法到达目标，则记录它，那么后续只要遇到它，就直接返回false。

```c++
#include <vector>

using namespace std;

class Solution {
    vector<bool> canReachTarget; // 能否到达目标
public:
    bool canJump(vector<int> &nums) {
        canReachTarget = vector<bool>(nums.size(), true);
        return dfs(nums, 0);
    }

    bool dfs(vector<int> &nums, int i) {
        if (i >= nums.size() - 1) { // 必须先检查i的值，否则后面使用它来access vector会发生越界
            return true;
        }
        if (!canReachTarget[i]) {
            return false;
        }

        for (int step = nums[i]; step > 0; --step) { // 需要注意的是: step不能够取到0，否则就会原地踏步陷入死循环
            if (dfs(nums, i + step)) {
                return true;
            }
        }
        canReachTarget[i] = false;
        return false;
    }
};

// Driver code
int main() {

    Solution s;
    vector<int> nums{2, 3, 1, 1, 4};
    s.canJump(nums);
    return 0;

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



## [LeetCode-45. Jump Game II-middle](https://leetcode.cn/problems/jump-game-ii/)



### DFS + memoization + prune



```c++
#include <vector>

using namespace std;

class Solution {
    vector<bool> canReachTarget; // 能否到达目标
    int minStep{INT_MAX};
public:
    int jump(vector<int> &nums) {
        canReachTarget = vector<bool>(nums.size(), true);
        int stepCnt = 0;
        dfs(nums, 0, stepCnt);
        return minStep;
    }

    bool dfs(vector<int> &nums, int numsIdx, int &stepCnt) {
        if (numsIdx >= nums.size() - 1) { // 必须先检查i的值，否则后面使用它来access vector会发生越界
            minStep = min(minStep, stepCnt);

            return true;
        }
        if (!canReachTarget[numsIdx]) {
            return false;
        }
        ++stepCnt;
        int successCnt = 0;
        for (int step = nums[numsIdx]; step > 0; --step) { // 需要注意的是: step不能够取到0，否则就会原地踏步陷入死循环
            if (dfs(nums, numsIdx + step, stepCnt)) {
                ++successCnt;
            }
        }
        --stepCnt;
        canReachTarget[numsIdx] = successCnt > 0;
        return canReachTarget[numsIdx];
    }
};

// Driver code
int main() {

    Solution s;
    vector<int> nums{2, 3, 1, 1, 4};
    s.jump(nums);
    return 0;

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

在如下用例超出时间限制:

https://leetcode.cn/problems/jump-game-ii/submissions/455827768/

```c++
[5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5]
```

