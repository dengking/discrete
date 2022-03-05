# [360. 有序转化数组](https://leetcode-cn.com/problems/sort-transformed-array/) 中等



## 我的解题

这道题需要有高中数学知识， `f(x)`是典型的抛物线函数，它的对称轴是 (`2 * a / b`)，因此最终结果，由跟对称轴的距离远近决定。

1、如果`a`大于0，则越近越小

2、如果`a`小于0，则越远越小

其实题目已经非常明显地提示用双指针了：

1、抛物线

2、`nums = [-4,-2,2,4]`

可以看到，它有正有负，正好中轴线位于两者之间



## [卖码翁](https://leetcode-cn.com/u/jyj407/) [【中规中矩】又是面试官装B的一题（两种解法）](https://leetcode-cn.com/problems/sort-transformed-array/solution/zhong-gui-zhong-ju-you-shi-mian-shi-guan-awen/)

解法1：先计算再暴力排序

解法2：**双指针**从两头开始计算，保存两端值较小的一个到结果。

利用高中数学**抛物线**性质:

1、`a>0`，向上的抛物线，两端大中间小，从后往前存储结算结果。

2、`a<0`，向下的抛物线，两端小中间大，从前往后存储结算结果。

3、`a=0`的情况时直线，单调增加或减少（取决于b的正负）。直接跟a>0或者a<0合并即可。

```C++
/ O(NlgN)
class Solution1 {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res;
        for (const auto& x : nums) {
            int t = a * x * x + b * x + c;
            res.push_back(t);
        }

        sort(res.begin(), res.end());

        return res;
    }
};

// O(N)
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        if (nums.empty()) {
            return {};
        }

        int N = nums.size();
        vector<int> res(N, 0);
        auto fx = [&](const auto& x) {
            return a * x * x + b * x + c;
        };

        int i = 0;
        int j = N - 1;
        int index = a >= 0 ? N - 1 : 0; // a > 0, backward, a < 0, forward
        while (i <= j) {
            if (a >= 0) { //向上的抛物线,合并a=0为直线，单调增减情况到a>0（合并到a < 0也行）
                res[index--] = fx(nums[i]) >= fx(nums[j]) ? fx(nums[i++]) : fx(nums[j--]); // 取大值
            } else { // (a < 0)
                res[index++] = fx(nums[i]) > fx(nums[j]) ? fx(nums[j--]) : fx(nums[i++]); // 取小值
            }
        }
        return res;
    }
};

```

> NOTE: 
>
> 上述基于双指针的写法是非常统一的，因为它cover了多种情况: 
>
> 一、函数`f(x)`是直线
>
> 二、函数`f(x)`是抛物线
>
> 1、数组的元素位于两侧，即非单调
>
> 2、数组的元素位于一侧，单调的
>
> 对于上面的情况，它都能够实现`O(N)`算法，由此可见双指针的灵活。



