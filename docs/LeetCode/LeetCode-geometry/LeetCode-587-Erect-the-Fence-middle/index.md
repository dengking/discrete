# [LeetCode 587. Erect the Fence](https://leetcode.cn/problems/erect-the-fence/)



## Andrew 算法

下面程序是参考 [LeetCode-【宫水三叶】二维凸包模板题](https://leetcode.cn/problems/erect-the-fence/solution/by-ac_oier-4xuu/) 写的。

一、由于题目所给的点的顺序未知，因此首先需要对输入的点进行排序以保证点序列，这是使用Andrew 算法的前提:

[LeetCode-【宫水三叶】二维凸包模板题](https://leetcode.cn/problems/erect-the-fence/solution/by-ac_oier-4xuu/) : 

> 根据 *x* 排升序的目的，是为了我们能够往一个方向画出凸包边缘（从左往后画出一半凸壳，从右往左画出另外一半），而将 *y* 升序目的是可以确保一旦我们现在从 *a* 到 *b* 进行连线，那么 *a* 到 *b* 之间的所有点能够确保被围住；

二、该算法处理的单位是edge，存在在stack中的本质上是edge

三、需要注意的是: `stk` 保存的是index而不是坐标，这是因为它`vis`需要被不断地更新，如果`stk`保存的是坐标的话，那么无法根据坐标去更新 `vis` 

四、在构建upper half和downer half的时候，都会涉及起点，容易写错的是在构建upper half的时候就直接将 `isInUpperHalf[0]` 设置为true，这样做是会导致在构建downer half的时候，无法使用到起点，在一些情况下是会导致错误的，下面是一个由于这个错误而无法通过的bad case，在这个case中，如果在构建downer half的时候能够使用到起点的话，那么 `[50,50]` 将会被淘汰掉。为了避免这种更浓错误，需要对起点进行特殊处理: 直接将它放到栈中，但是将 `isInUpperHalf[0]` 设置为false。

输入

```
trees =
[[0,0],[0,100],[100,100],[100,0],[50,50]]
```

输出

```
[[0,0],[0,100],[100,100],[100,0],[50,50]]
```

预期结果

```
[[0,100],[100,0],[100,100],[0,0]]
```

![](./bad-case.png)



### 错误解题

```c++

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > outerTrees(vector<vector<int> > &trees) {
        std::sort(trees.begin(), trees.end(), [](vector<int> &left, vector<int> &right) {
            if (left[0] == right[0]) {
                return left[1] < right[1];
            } else {
                return left[0] < right[0];
            }
        });
        vector<vector<int> > convexHull;
        convexHull.reserve(trees.size() * 2);
        for (auto &&tree: trees) {
            while (convexHull.size() >= 2
                   && crossProduct(convexHull.rbegin()[1], convexHull.rbegin()[0], tree) > 0) {
                convexHull.pop_back();
            }
            convexHull.push_back(tree);
        }
        if (trees.size() > 1) {
            for (auto &&itor = trees.rbegin() + 1; itor != trees.rend() - 1; ++itor) {
                while (convexHull.size() >= 2
                       && crossProduct(convexHull.rbegin()[1], convexHull.rbegin()[0], *itor) > 0) {
                    convexHull.pop_back();
                }
                convexHull.push_back(*itor);
            }
        }
        return convexHull;
    }

    /// @brief  OA、OB 的cross product
    /// OA counter clock wise 旋转到 OB，则返回值大于0，or 小于0
    /// @param O
    /// @param A
    /// @param B
    /// @return
    int crossProduct(const vector<int> &o, const vector<int> &a, const vector<int> &b) {
        int x_a = a[0] - o[0];
        int y_a = a[1] - o[1];

        int x_b = b[0] - o[0];
        int y_b = b[1] - o[1];
        return x_a * y_b - y_a * x_b;
    }
};

int main() {
    vector<vector<int> > trees{{1, 1},
                               {2, 2},
                               {2, 0},
                               {2, 4},
                               {3, 3},
                               {4, 2}};
    Solution s;
    s.outerTrees(trees);
    return 0;
}
```

1、vector

无法通过如下用例:

```
[[1,2],[2,2],[4,2]]
```



see also: [【宫水三叶】二维凸包模板题](https://leetcode.cn/problems/erect-the-fence/solution/by-ac_oier-4xuu/)
