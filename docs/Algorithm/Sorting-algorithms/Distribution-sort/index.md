# Distribution sort

"distribution sort"顾名思义是根据数据的分布来进行排序，典型的例子就是counting-sort。



## wikipedia [Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm) # Distribution sort

See also: [External sorting](https://infogalactic.com/info/External_sorting)

*Distribution sort* refers to any sorting algorithm where data are distributed from their input to multiple intermediate structures which are then gathered and placed on the output. For example, both [bucket sort](https://infogalactic.com/info/Bucket_sort) and [flashsort](https://infogalactic.com/info/Flashsort) are distribution based sorting algorithms. Distribution sorting algorithms can be used on a single processor, or they can be a [distributed algorithm](https://infogalactic.com/info/Distributed_algorithm), where individual subsets are separately sorted on different processors, then combined. This allows [external sorting](https://infogalactic.com/info/External_sorting) of data too large to fit into a single computer's memory.

> NOTE: 
>
> divide and conquer

**[Counting sort](https://infogalactic.com/info/Counting_sort)**

**[Bucket sort](https://infogalactic.com/info/Bucket_sort)**

**[Radix sort](https://infogalactic.com/info/Radix_sort)**



## Bucket sort

---

> Reference: 
>
> geeksforgeeks [Bucket Sort](https://www.geeksforgeeks.org/bucket-sort-2/)
>
> csdn [桶排序](https://blog.csdn.net/weixin_38426554/article/details/95931499)

---

### wikipedia [Bucket sort](https://en.wikipedia.org/wiki/Bucket_sort)



## Counting sort



"counting sort"即"计数排序"，它是我在阅读 labuladong [小而美的算法技巧：前缀和数组](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247494095&idx=2&sn=19a2609f33eadbbda1f6b75e2298d931&scene=21#wechat_redirect) 时发现的，其中有这样的介绍:

> 你可以先通过计数排序的方式计算每个分数具体有多少个同学，然后利用前缀和技巧来实现分数段查询的 API：
>
> ```Java
> int[] scores; // 存储着所有同学的分数
> // 试卷满分 100 分
> int[] count = new int[100 + 1]
> // 记录每个分数有几个同学
> for (int score : scores)
>  count[score]++
> // 构造前缀和
> for (int i = 1; i < count.length; i++)
>  count[i] = count[i] + count[i-1];
> 
> // 利用 count 这个前缀和数组进行分数段查询
> ```



### wikipedia [Counting sort](https://en.wikipedia.org/wiki/Counting_sort) 

In [computer science](https://en.wikipedia.org/wiki/Computer_science), **counting sort** is an [algorithm](https://en.wikipedia.org/wiki/Algorithm) for [sorting](https://en.wikipedia.org/wiki/Sorting_algorithm) a collection of objects according to **keys** that are small positive [integers](https://en.wikipedia.org/wiki/Integer); that is, it is an [integer sorting](https://en.wikipedia.org/wiki/Integer_sorting) algorithm. It operates by counting the number of objects that possess distinct key values, and applying **prefix sum** on those counts to determine the positions of each key value in the output sequence.

> NOTE: 
>
> 一、在counting sort中，key是关键，它要求key是单调递增的，它会将key作为index，因此key需要是非负数，以labuladong [小而美的算法技巧：前缀和数组](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247494095&idx=2&sn=19a2609f33eadbbda1f6b75e2298d931&scene=21#wechat_redirect)  中的例子来说，key就是分数。
>
> 二、Counting sort需要和prefix sum一起来进行使用。

It is often used as a subroutine in [radix sort](https://en.wikipedia.org/wiki/Radix_sort), another sorting algorithm, which can handle larger keys more efficiently.



#### Pseudocode

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





## Radix sort

理解 **radix sort** 的前提是理解 "radix" 的含义，下面是 wikipedia [Radix](https://en.wikipedia.org/wiki/Radix) :

> In a [positional numeral system](https://en.wikipedia.org/wiki/Positional_numeral_system), the **radix** (pl.: **radices**) or **base** is the number of unique [digits](https://en.wikipedia.org/wiki/Numerical_digit), including the digit zero, used to represent numbers. For example, for the [decimal system](https://en.wikipedia.org/wiki/Decimal) (the most common system in use today) the **radix** is ten, because it uses the ten digits from 0 through 9.

Radix sort 充分利用了 [positional numeral system](https://en.wikipedia.org/wiki/Positional_numeral_system) 的规律，它的原理很简单，下面以 gpt-4-vision 给出的一个例子来进行说明: 

> Radix Sort is a non-comparative integer sorting algorithm that sorts data with integer keys by grouping the keys by individual digits that share the same significant position and value ([radix](https://en.wikipedia.org/wiki/Radix)). It processes each digit from the **least significant** to the **most significant** (**LSD Radix Sort**) or vice versa (**MSD Radix Sort**).
>
> Here's how LSD Radix Sort works:
>
> 1. *Determine the **Maximum Number of Digits** (k)*: Find the largest number in the array to determine the maximum number of digits any number has.
>
> 2. *Sorting by Each Digit*: For each digit `i` from the **least significant digit** to the **most significant digit** (1 to k):
>    a. Create buckets for each digit (0-9 if the numbers are in base 10).
>
>    b. Place each number in the corresponding bucket based on its i-th digit.
>
>    c. Collect the numbers from the buckets in order and replace the original array with these numbers, which are now sorted by the i-th digit.
>
>    > NOTE:
>    >
>    > 一、上述是使用 **counting sort**，wikipedia [Counting sort](https://en.wikipedia.org/wiki/Counting_sort) 中有介绍:
>    >
>    > > It is often used as a subroutine in [radix sort](https://en.wikipedia.org/wiki/Radix_sort), another sorting algorithm, which can handle larger keys more efficiently.
>
> 3. Repeat: Repeat step 2 for each subsequent digit position until the most significant digit.
>
> 4. Result: After processing all k digits, the array will be sorted.
>
> Here is a step-by-step example of Radix Sort:
>
> Suppose we have an array `A` with values `[170, 45, 75, 90, 802, 24, 2, 66]`.
>
> 1. The maximum number of digits (k) is 3 (since 802 has three digits).
> 2. Start with the **least significant digit** (ones place):
>    - Buckets after sorting by ones place: [170, 90, 802, 2, 24, 45, 75, 66]
>
> 3. Move to the next digit (tens place):
>    - Buckets after sorting by tens place: [802, 2, 24, 45, 66, 170, 75, 90]
>
> 4. Finally, sort by the most significant digit (hundreds place):
>    - Buckets after sorting by hundreds place: [2, 24, 45, 66, 75, 90, 170, 802]
>
> 5. The array is now sorted.
>
> **Radix Sort** has a time complexity of O(nk) for n keys with k digits. It is efficient for sorting large sets of data with a small range of key values. Unlike comparison-based sorting algorithms like quicksort or mergesort, Radix Sort's performance does not depend on the initial order of the elements. It is also [**stable**](https://en.wikipedia.org/wiki/Sorting_algorithm#Stability), which means that it maintains the relative order of equal elements, an important property when sorting data by multiple keys. 



### wikipedia [Radix sort](https://en.wikipedia.org/wiki/Radix_sort)

#### Digit order

Radix sorts can be implemented to start at either the [most significant digit](https://en.wikipedia.org/wiki/Most_significant_digit) (MSD) or [least significant digit](https://en.wikipedia.org/wiki/Least_significant_digit) (LSD). For example, with **1234**, one could start with 1 (MSD) or 4 (LSD).

#### Specialized variants

##### Tree-based radix sort

**Radix sorting** can also be accomplished by building a [tree](https://en.wikipedia.org/wiki/Tree_(data_structure)) (or [radix tree](https://en.wikipedia.org/wiki/Radix_tree)) from the input set, and doing a [pre-order](https://en.wikipedia.org/wiki/Tree_traversal#Pre-order,_NLR) traversal. This is similar to the relationship between [heapsort](https://en.wikipedia.org/wiki/Heapsort) and the [heap](https://en.wikipedia.org/wiki/Heap_(data_structure)) data structure. This can be useful for certain data types, see [burstsort](https://en.wikipedia.org/wiki/Burstsort).
