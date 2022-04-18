# labuladong [单调栈 Monotonic Stack 的使用](https://mp.weixin.qq.com/s/_b_QzXkL4e0y5241betVSg)



> #### NOTE: 
>
> leetcode [496. 下一个更大元素 I](https://leetcode-cn.com/problems/next-greater-element-i/) 简单
>
> leetcode [503. 下一个更大元素 II](https://leetcode-cn.com/problems/next-greater-element-ii/) 中等
>
> 带循环数组的
>
> leetcode [556. 下一个更大元素 III](https://leetcode-cn.com/problems/next-greater-element-iii/) 中等
>
> leetcode [739. 每日温度](https://leetcode-cn.com/problems/daily-temperatures/) 中等

首先，讲解 Next Greater Number 的原始问题：给你一个数组，返回一个等长的数组，对应索引存储着下一个更大元素，如果没有更大的元素，就存 -1。不好用语言解释清楚，直接上一个例子：

给你一个数组 [2,1,2,4,3]，你返回数组 [4,2,4,-1,-1]。

解释：第一个 2 后面比 2 大的数是 4; 1 后面比 1 大的数是 2；第二个 2 后面比 2 大的数是 4; 4 后面没有比 4 大的数，填 -1；3 后面没有比 3 大的数，填 -1。

这个问题可以这样抽象思考：把数组的元素想象成并列站立的人，元素大小想象成人的身高。这些人面对你站成一列，如何求元素「2」的 Next Greater Number 呢？很简单，如果能够看到元素「2」，那么他后面可见的第一个人就是「2」的 Next Greater Number，因为比「2」小的元素身高不够，都被「2」挡住了，第一个露出来的就是答案。



![Image](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4m0R7ibYasslicsCB3k0kk0BOpGAbwAh1xpoN1LOKvWjjZx3KTxH3TQ08IFdLdSlJlYuLGtJrLBt9Lg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



这个情景很好理解吧？带着这个抽象的情景，先来看下代码。



```c++
vector<int> nextGreaterElement(vector<int>& nums) {
    vector<int> ans(nums.size()); // 存放答案的数组
    stack<int> s;
    for (int i = nums.size() - 1; i >= 0; i--) { // 倒着往栈里放
        while (!s.empty() && s.top() <= nums[i]) { // 判定个子高矮
            s.pop(); // 矮个起开，反正也被挡着了。。。
        }
        ans[i] = s.empty() ? -1 : s.top(); // 这个元素身后的第一个高个
        s.push(nums[i]); // 进队，接受之后的身高判定吧！
    }
    return ans;
}
```

分析它的时间复杂度，要从整体来看：总共有 n 个元素，每个元素都被 push 入栈了一次，而最多会被 pop 一次，没有任何冗余操作。所以总的计算规模是和元素规模 n 成正比的，也就是 O(n) 的复杂度。



## LeetCode [739. 每日温度](https://leetcode-cn.com/problems/daily-temperatures/) 中等

现在，你已经掌握了单调栈的使用技巧，来一个简单的变形来加深一下理解。

给你一个数组 T = [73, 74, 75, 71, 69, 72, 76, 73]，这个数组存放的是近几天的天气气温（这气温是铁板烧？不是的，这里用的华氏度）。你返回一个数组，计算：对于每一天，你还要至少等多少天才能等到一个更暖和的气温；如果等不到那一天，填 0 。

举例：给你 T = [73, 74, 75, 71, 69, 72, 76, 73]，你返回 [1, 1, 4, 2, 1, 1, 0, 0]。

解释：第一天 73 华氏度，第二天 74 华氏度，比 73 大，所以对于第一天，只要等一天就能等到一个更暖和的气温。后面的同理。

你已经对 Next Greater Number 类型问题有些敏感了，这个问题本质上也是找 Next Greater Number，只不过现在不是问你 Next Greater Number 是多少，而是问你当前距离 Next Greater Number 的距离而已。



相同类型的问题，相同的思路，直接调用单调栈的算法模板，稍作改动就可以啦，直接上代码把。



```C++
vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> ans(T.size());
    stack<int> s; // 这里放元素索引，而不是元素
    for (int i = T.size() - 1; i >= 0; i--) {
        while (!s.empty() && T[s.top()] <= T[i]) {
            s.pop();
        }
        ans[i] = s.empty() ? 0 : (s.top() - i); // 得到索引间距
        s.push(i); // 加入索引，而不是元素
    }
    return ans;
}
```

## 循环数组、LeetCode [503. 下一个更大元素 II](https://leetcode-cn.com/problems/next-greater-element-ii/) 中等

单调栈讲解完毕。下面开始另一个重点：**如何处理「循环数组」**。

同样是 Next Greater Number，现在假设给你的数组是个环形的，如何处理？

给你一个数组 [2,1,2,4,3]，你返回数组 [4,2,4,-1,4]。拥有了环形属性，最后一个元素 3 绕了一圈后找到了比自己大的元素 4 。



![Image](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4m0R7ibYasslicsCB3k0kk0BOcjoO1w8DM7Reib59JniaXMSf4TB7KW98Dkq6biawEoiaynMV3LnqY5Iz7Q/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



首先，计算机的内存都是线性的，没有真正意义上的环形数组，但是我们可以模拟出环形数组的效果，一般是通过 % 运算符求模（余数），获得环形特效：



```Java
int[] arr = {1,2,3,4,5};
int n = arr.length, index = 0;
while (true) {
    print(arr[index % n]);
    index++;
}
```

回到 Next Greater Number 的问题，增加了环形属性后，问题的难点在于：这个 Next 的意义不仅仅是当前元素的右边了，有可能出现在当前元素的左边（如上例）。

明确问题，问题就已经解决了一半了。我们可以考虑这样的思路：将原始数组“翻倍”，就是在后面再接一个原始数组，这样的话，按照之前“比身高”的流程，每个元素不仅可以比较自己**右边**的元素，而且也可以和**左边**的元素比较了。

> NOTE:
>
> 上面这段话是问题的关键所在，上述思路可以简单概括为将环形数组摊平。
>
> Q: 这种摊平行为会带来问题？
>
> A: 同一个元素会被处理两次。
>
> Q: 同一个元素会被处理两次会对这个问题的最终结果产生影响吗？
>
> 对于next greater number在右边的元素，它其实是**不会**产生影响的，因为将原数组克隆一遍后，对于next greater number在右边的元素，它的next greater number未改变。
>
> 对于next greater number在左边的元素，它其实是**会**产生影响的



![Image](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4m0R7ibYasslicsCB3k0kk0BOpnkMMbH694fmtpUNgypvZzztIgg9VKmmAQY9DtC9mVO2qnJLJRJBXA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



怎么实现呢？你当然可以把这个双倍长度的数组构造出来，然后套用算法模板。但是，我们可以不用构造新数组，而是利用循环数组的技巧来模拟。直接看代码吧：



```c++
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n); // 存放结果
    stack<int> s;
    // 假装这个数组长度翻倍了
    for (int i = 2 * n - 1; i >= 0; i--) { // 数组长度为 2 * n
        while (!s.empty() && s.top() <= nums[i % n])
            s.pop();
        res[i % n] = s.empty() ? -1 : s.top();
        s.push(nums[i % n]);
    }
    return res;
}
```



至此，你已经完全掌握了单调栈的设计方法，学会解决 Next Greater Number 这类问题，并且能够应付循环数组了。
