# [LeetCode-74. Search a 2D Matrix](https://leetcode.cn/problems/search-a-2d-matrix/)



## Binary search



```c++
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
    int rowCnt{0};
    int colCnt{0};

public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        rowCnt = matrix.size();
        colCnt = matrix[0].size();
        int left = 0, right = rowCnt * colCnt - 1;
        while (left <= right)
        {
            int midIdx = left + (right - left) / 2;
            int mid = getNum(midIdx, matrix);
            if (mid == target)
            {
                return true;
            }
            else if (mid > target)
            {
                right = midIdx - 1;
            }
            else
            {
                left = midIdx + 1;
            }
        }
        return false;
    }

private:
    int getNum(int idx, vector<vector<int>> &matrix)
    {
        int rowIdx = idx / colCnt;
        int colIdex = idx - rowIdx * colCnt;
        return matrix[rowIdx][colIdex];
    }
};

// Driver code
int main()
{

    Solution s;

    vector<vector<int>> matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    s.searchMatrix(matrix, 3);

    vector<vector<int>> matrix1{{1}, {3}};
    s.searchMatrix(matrix1, 2);
    return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

