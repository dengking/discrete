# [LeetCode-6. Zigzag Conversion-middle](https://leetcode.cn/problems/zigzag-conversion/)



这其实是一道数学题，需要建立下标和坐标之间的映射关系。

正方形:

周期性: n+n-1

给定下标，首先判断它属于第几周期

每个周期的第0个点，位于



```c++
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string res;
        int period = numRows * 2 - 2; // 每个周期元素的个数
        // int periodCnt = std::ceil(s.size() / period); // 周期数
        /**
         * 结果测试，上面的ceil函数返回失败，所以采用下面的等价的实现方式
         */
        int periodCnt = s.size() / period; // 周期数
        if (s.size() % period) {
            ++periodCnt;
        }

        res.reserve(s.size());
        int maxIdx = s.size() - 1;
        /**
         * 从上到下每一行，需要将从左到右的每个周期中属于该行数按照顺序添加到其中
         */
        for (int rowIdx = 0; rowIdx < numRows; ++rowIdx) {
            for (int periodIdx = 0; periodIdx < periodCnt; ++periodIdx) {
                int startIdxOfCurPeriod = periodIdx * period; // 第j周期的起始下标
                int startIdxOfNextPeriod = (periodIdx + 1) * period; // 第j周期的起始下标
                /**
                 * 第0行，每个周期只有一个数属于该行
                 */
                if (rowIdx == 0) {
                    res.push_back(s[startIdxOfCurPeriod]);
                } else {
                    /**
                     * 对于其它行，每个周期最多有两个数属于该行
                     */
                    int leftIdx = startIdxOfCurPeriod + rowIdx, rightIdx = startIdxOfNextPeriod - rowIdx;
                    if (leftIdx == rightIdx && leftIdx <= maxIdx) {
                        res.push_back(s[leftIdx]);
                    } else {
                        if (leftIdx <= maxIdx) {
                            res.push_back(s[leftIdx]);
                        }
                        if (rightIdx <= maxIdx) {
                            res.push_back(s[rightIdx]);
                        }
                    }
                }
            }
        }
        return res;
    }
};


// Driver code
int main() {

    Solution s;
    std::cout << s.convert("PAYPALISHIRING", 3) << '\n';
    return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

