# Counting sort

"counting sort"即"计数排序"，它是我在阅读 labuladong [小而美的算法技巧：前缀和数组](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247494095&idx=2&sn=19a2609f33eadbbda1f6b75e2298d931&scene=21#wechat_redirect) 时发现的，其中有这样的介绍:

> 你可以先通过计数排序的方式计算每个分数具体有多少个同学，然后利用前缀和技巧来实现分数段查询的 API：
>
> ```Java
> int[] scores; // 存储着所有同学的分数
> // 试卷满分 100 分
> int[] count = new int[100 + 1]
> // 记录每个分数有几个同学
> for (int score : scores)
>     count[score]++
> // 构造前缀和
> for (int i = 1; i < count.length; i++)
>     count[i] = count[i] + count[i-1];
> 
> // 利用 count 这个前缀和数组进行分数段查询
> ```

## cnblogs [一文弄懂计数排序算法！](https://www.cnblogs.com/xiaochuan94/p/11198610.html)

### 03 基础版代码实现

```Java
public int[] countSort(int[] A) {
    // 找出数组A中的最大值
    int max = Integer.MIN_VALUE;
    for (int num : A) {
        max = Math.max(max, num);
    }
    // 初始化计数数组count
    int[] count = new int[max+1];
    // 对计数数组各元素赋值
    for (int num : A) {
        count[num]++;
    }
    // 创建结果数组
    int[] result = new int[A.length];
    // 创建结果数组的起始索引
    int index = 0;
    // 遍历计数数组，将计数数组的索引填充到结果数组中
    for (int i=0; i<count.length; i++) {
        while (count[i]>0) {
            result[index++] = i;
            count[i]--;
        }
    }
    // 返回结果数组
    return result;
}
```

> NOTE: 
>
> 一、上述是最最简单的，它假定数组`A`的元素的范围是: `[0, max]`
>
> 最后要按照count数组将原数组进行排序，它使用原数组中的元素作为count array的index

### 04 优化版: 空间优化

```Java
public int[] countSort2(int[] A) {
    // 找出数组A中的最大值、最小值
    int max = Integer.MIN_VALUE;
    int min = Integer.MAX_VALUE;
    for (int num : A) {
        max = Math.max(max, num);
        min = Math.min(min, num);
    }
    // 初始化计数数组count
    // 长度为最大值减最小值加1
    int[] count = new int[max-min+1];
    // 对计数数组各元素赋值
    for (int num : A) {
        // A中的元素要减去最小值，再作为新索引
        count[num-min]++;
    }
    // 创建结果数组
    int[] result = new int[A.length];
    // 创建结果数组的起始索引
    int index = 0;
    // 遍历计数数组，将计数数组的索引填充到结果数组中
    for (int i=0; i<count.length; i++) {
        while (count[i]>0) {
            // 再将减去的最小值补上
            result[index++] = i+min;
            count[i]--;
        }
    }
    // 返回结果数组
    return result;
}
```



### 05 进阶版步骤: prefix sum

> NOTE: 
>
> 使用了prefix sum

## wikipedia [Counting sort](https://en.wikipedia.org/wiki/Comparison_sort)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), **counting sort** is an [algorithm](https://en.wikipedia.org/wiki/Algorithm) for [sorting](https://en.wikipedia.org/wiki/Sorting_algorithm) a collection of objects according to **keys** that are small positive [integers](https://en.wikipedia.org/wiki/Integer); that is, it is an [integer sorting](https://en.wikipedia.org/wiki/Integer_sorting) algorithm. It operates by counting the number of objects that possess distinct key values, and applying **prefix sum** on those counts to determine the positions of each key value in the output sequence.

> NOTE: 
>
> 一、在counting sort中，key是关键，它要求key是单调递增的，它会将key作为index，因此key需要是非负数，以labuladong [小而美的算法技巧：前缀和数组](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247494095&idx=2&sn=19a2609f33eadbbda1f6b75e2298d931&scene=21#wechat_redirect)  中的例子来说，key就是分数。
>
> 

### Pseudocode

```C++
function CountingSort(input, k)
    
    count ← array of k + 1 zeros // 计数
    output ← array of same length as input // 输出
    
    for i = 0 to length(input) - 1 do
        j = key(input[i])
        count[j] += 1
    //  计算prefix sum，其实是计算次序
    for i = 1 to k do 
        count[i] += count[i - 1] 

    for i = length(input) - 1 downto 0 do
        j = key(input[i])
        count[j] -= 1
        output[count[j]] = input[i]

    return output
```

> NOTE: 
>
> 一、key是单调递增的，因此可以作为排序的标准
>
> 二、上面这一版就是使用了prefix sum的



