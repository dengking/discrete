# labuladong [回溯算法详解](https://mp.weixin.qq.com/s/nMUHqvwzG2LmWA9jMIHwQQ)

废话不多说，直接上回溯算法框架。**解决一个回溯问题，实际上就是一个决策树的遍历过程**。你只需要思考 3 个问题：

**1、路径**：也就是已经做出的选择。

> NOTE: path=选择

**2、选择列表**：也就是你当前可以做的选择。



**3、结束条件**：也就是到达决策树底层，无法再做选择的条件。

> NOTE: stop condition

如果你不理解这三个词语的解释，没关系，我们后面会用「全排列」和「N 皇后问题」这两个经典的回溯算法问题来帮你理解这些词语是什么意思，现在你先留着印象。

代码方面，回溯算法的框架：

```python
result = [] # solution
def backtrack(路径, 选择列表):
    if 满足结束条件: # stop condition
        result.add(路径)
        return

    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择
```

**其核心就是 for 循环里面的递归，在递归调用之前「做选择」，在递归调用之后「撤销选择」**，特别简单。

什么叫做选择和撤销选择呢，这个框架的底层原理是什么呢？下面我们就通过「全排列」这个问题来解开之前的疑惑，详细探究一下其中的奥妙！

## 一、全排列问题

> NOTE: 
>
> [LeetCode-46. 全排列](https://leetcode.cn/problems/permutations/) 中等
>
> 

而所谓的前序遍历和后序遍历，他们只是两个很有用的时间点，我给你画张图你就明白了：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdF1umAdyXuPq54ibw7X23mnajTgCl3dL1z2wJpbvdfiaM1dMuCqPOO5JxicOgiaQAmQBJfZCwAbIxfFmQ/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

**前序遍历的代码在进入某一个节点之前的那个时间点执行，后序遍历代码在离开某个节点之后的那个时间点执行**。

回想我们刚才说的，「路径」和「选择」是每个节点的属性，函数在树上游走要正确维护节点的属性，那么就要在这两个特殊时间点搞点动作：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdF1umAdyXuPq54ibw7X23mnaR2cbSJabtrWQtib7OP5ZrSicZY2IOZibsia5dlibcvWhlQC1TibO97yia6mQA/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

现在，你是否理解了回溯算法的这段核心框架？

```
for 选择 in 选择列表:
    # 做选择
    将该选择从选择列表移除
    路径.add(选择)
    backtrack(路径, 选择列表)
    # 撤销选择
    路径.remove(选择)
    将该选择再加入选择列表
```

**我们只要在递归之前做出选择，在递归之后撤销刚才的选择**，就能正确得到每个节点的选择列表和路径。

下面，直接看全排列代码：

```Java
List<List<Integer>> res = new LinkedList<>();

/* 主函数，输入一组不重复的数字，返回它们的全排列 */
List<List<Integer>> permute(int[] nums) {
    // 记录「路径」
    LinkedList<Integer> track = new LinkedList<>();
    backtrack(nums, track);
    return res;
}

// 路径：记录在 track 中
// 选择列表：nums 中不存在于 track 的那些元素
// 结束条件：nums 中的元素全都在 track 中出现
void backtrack(int[] nums, LinkedList<Integer> track) {
    // 触发结束条件
    if (track.size() == nums.length) {
        res.add(new LinkedList(track));
        return;
    }

    for (int i = 0; i < nums.length; i++) {
        // 排除不合法的选择
        if (track.contains(nums[i]))
            continue;
        // 做选择
        track.add(nums[i]);
        // 进入下一层决策树
        backtrack(nums, track);
        // 取消选择
        track.removeLast();
    }
}
```

我们这里稍微做了些变通，没有显式记录「选择列表」，而是通过`nums`和`track`推导出当前的选择列表：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdF1umAdyXuPq54ibw7X23mnaWuNCGdIXFoeBp1U7IA4tSEz1Pia9VvK2H9mSib1Mch3Yb5V8PCHib8dog/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

至此，我们就通过全排列问题详解了回溯算法的底层原理。当然，这个算法解决全排列不是很高效，因为对链表使用`contains`方法需要 O(N) 的时间复杂度。有更好的方法通过交换元素达到目的，但是难理解一些，这里就不写了，有兴趣可以自行搜索一下。

但是必须说明的是，不管怎么优化，都符合回溯框架，而且时间复杂度都不可能低于 O(N!)，因为穷举整棵决策树是无法避免的。**这也是回溯算法的一个特点，不像动态规划存在重叠子问题可以优化，回溯算法就是纯暴力穷举，复杂度一般都很高**。

明白了全排列问题，就可以直接套回溯算法框架了，下面简单看看 N 皇后问题。

## 二、N 皇后问题

> NOTE: 
>
> [LeetCode-51. N 皇后](https://leetcode.cn/problems/n-queens/) 困难
>
> 

