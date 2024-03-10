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

> 你可以先通过**计数排序**的方式计算每个分数具体有多少个同学，然后利用前缀和技巧来实现分数段查询的 API：
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

### gpt-4-vision

**Counting Sort** is an **integer sorting algorithm** that operates by counting the number of objects that have each distinct key value. It is a non-comparative sorting algorithm, meaning it does not compare the elements directly to sort them. Instead, it uses the actual values of the elements to index into an array. **Counting Sort** is most effective when the range of potential items (the keys) is not significantly greater than the number of items to be sorted.

> NOTE:
>
> 一、"it uses the actual values of the elements to index into an array" 将element作为array的index，那么这就是在无形中进行排序，并且后续直接用element进行查询。借助于prefix sum，可以得到每个element的最终的次序(order、position)，由此可见这个算法的本质是首先得到每个element的最终的次序(order、position)。

Here's how **Counting Sort** works:

1. **Find the Range**: Determine the range of input values, i.e., the **minimum** and **maximum** values (min and max).

2. **Create Count Array**: Create an array `count` of size `max - min + 1` to hold the count of each value in the input array. Initialize all elements of the `count` array to 0.

3. **Count Occurrences**: Iterate through the input array and, for each element `x`, increment `count[x - min]`. This step counts the occurrences of each value.

4. **Calculate Prefix Sum**: Modify the `count` array by replacing each element with the sum of the previous counts. This step accumulates the counts and determines the **position** of each value in the sorted array.

   > NOTE:
   >
   > 一、上面这段话中的 "**position**" 所表示的就是**次序**、**位次**的意思

5. **Sort**: Create an output array `sorted` of the same size as the input array. Iterate through the input array in **reverse order** (to maintain stability), and for each element `x`, place it in the sorted array at the index indicated by `count[x - min]`, then decrement `count[x - min]` by 1.

   > NOTE:
   >
   > 一、典型的stack order: 装进去的时候是从前到后，取出来的时候需要从后往前才能够保证相同元素之间的stable。
   >
   > Counting sort的过程可以形象地看作是将数字放到依次排开的柱子上(每个柱子可以看作是一个stack)，显然为了保持相对次序，取出的时候需要从后往前取出。

6. **Copy Back**: Copy the `sorted` array back into the original input array.

Here is a step-by-step example of Counting Sort:

Suppose we have an array `A` with values `[4, 2, 2, 8, 3, 3, 1]`.

1. The range of values is 1 to 8 (min to max).
2. We create a `count` array of size `8 - 1 + 1 = 8` and initialize it to `[0, 0, 0, 0, 0, 0, 0, 0]`.
3. We count the occurrences: `[1, 2, 2, 1, 0, 0, 0, 1]`.
4. We calculate the **prefix sum**: `[1, 3, 5, 6, 6, 6, 6, 7]`.
5. We sort the array. Starting from the end of the input array, we place each element in its correct position in the sorted array and decrement the corresponding count.
6. Finally, we copy the sorted array [1, 2, 2, 3, 3, 4, 8] back into the original array A.

**Counting Sort** has a time complexity of `O(n + k)`, where `n` is the number of elements in the **input array** and `k` is the range of the input values. It is efficient when `k` is not significantly larger than `n`. It is also a **stable sort**, meaning that it maintains the relative order of equal elements, which is an important property when sorting data by multiple keys.



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

### Code

```python

def counting_sort(arr: MutableSequence[int]):
    # Find the maximum element in the array
    min_val, max_val = min(arr), max(arr)

    # Create a count array to store the count of each element
    count = [0] * (max_val - min_val + 1)

    # Count the occurrences of each element
    for num in arr:
        count[num - min_val] += 1

    # Calculate the cumulative count
    for i in range(1, len(count)):
        count[i] += count[i - 1]

    # Create an output array to store the sorted elements
    output = [0] * len(arr)

    # Build the output array in sorted order
    for num in reversed(arr):
        output[count[num] - 1] = num
        count[num] -= 1

    return output


class TestCountingSort(unittest.TestCase):
    def test_counting_sort(self):
        arr = [999, 888, 777, 666, 555, 444, 333, 222, 111, 0]
        sorted_arr = counting_sort(arr)
        for num in sorted_arr:
            print(num)
        self.assertEqual(sorted_arr, sorted(arr))

```





## Radix sort

理解 **radix sort** 的前提是理解 "radix" 的含义，下面是 wikipedia [Radix](https://en.wikipedia.org/wiki/Radix) :

> In a [positional numeral system](https://en.wikipedia.org/wiki/Positional_numeral_system), the **radix** (pl.: **radices**) or **base** is the number of unique [digits](https://en.wikipedia.org/wiki/Numerical_digit), including the digit zero, used to represent numbers. For example, for the [decimal system](https://en.wikipedia.org/wiki/Decimal) (the most common system in use today) the **radix** is ten, because it uses the ten digits from 0 through 9.

Radix sort 充分利用了 [positional numeral system](https://en.wikipedia.org/wiki/Positional_numeral_system) 的规律，它的原理很简单，下面以 gpt-4-vision 给出的一个例子来进行说明。

### gpt-4-vision

Radix Sort is a non-comparative integer sorting algorithm that sorts data with integer keys by grouping the keys by individual digits that share the same significant position and value ([radix](https://en.wikipedia.org/wiki/Radix)). It processes each digit from the **least significant** to the **most significant** (**LSD Radix Sort**) or vice versa (**MSD Radix Sort**).

Here's how LSD Radix Sort works:

1. *Determine the **Maximum Number of Digits** (k)*: Find the largest number in the array to determine the maximum number of digits any number has.

2. *Sorting by Each Digit*: For each digit `i` from the **least significant digit** to the **most significant digit** (1 to k):
   a. Create buckets for each digit (0-9 if the numbers are in base 10).

   b. Place each number in the corresponding bucket based on its i-th digit.

   c. Collect the numbers from the buckets in order and replace the original array with these numbers, which are now sorted by the i-th digit.

   > NOTE:
   >
   > 一、上述是使用 **counting sort**，wikipedia [Counting sort](https://en.wikipedia.org/wiki/Counting_sort) 中有介绍:
   >
   > > It is often used as a subroutine in [radix sort](https://en.wikipedia.org/wiki/Radix_sort), another sorting algorithm, which can handle larger keys more efficiently.

3. Repeat: Repeat step 2 for each subsequent digit position until the most significant digit.

4. Result: After processing all k digits, the array will be sorted.

Here is a step-by-step example of Radix Sort:

Suppose we have an array `A` with values `[170, 45, 75, 90, 802, 24, 2, 66]`.

1. The maximum number of digits (k) is 3 (since 802 has three digits).
2. Start with the **least significant digit** (ones place):
   - Buckets after sorting by ones place: [170, 90, 802, 2, 24, 45, 75, 66]

3. Move to the next digit (tens place):
   - Buckets after sorting by tens place: [802, 2, 24, 45, 66, 170, 75, 90]

4. Finally, sort by the most significant digit (hundreds place):
   - Buckets after sorting by hundreds place: [2, 24, 45, 66, 75, 90, 170, 802]

5. The array is now sorted.

**Radix Sort** has a time complexity of O(nk) for n keys with k digits. It is efficient for sorting large sets of data with a small range of key values. Unlike comparison-based sorting algorithms like quicksort or mergesort, Radix Sort's performance does not depend on the initial order of the elements. It is also [**stable**](https://en.wikipedia.org/wiki/Sorting_algorithm#Stability), which means that it maintains the relative order of equal elements, an important property when sorting data by multiple keys. 



### wikipedia [Radix sort](https://en.wikipedia.org/wiki/Radix_sort)

#### Digit order

Radix sorts can be implemented to start at either the [most significant digit](https://en.wikipedia.org/wiki/Most_significant_digit) (MSD) or [least significant digit](https://en.wikipedia.org/wiki/Least_significant_digit) (LSD). For example, with **1234**, one could start with 1 (MSD) or 4 (LSD).

#### Specialized variants

##### Tree-based radix sort

**Radix sorting** can also be accomplished by building a [tree](https://en.wikipedia.org/wiki/Tree_(data_structure)) (or [radix tree](https://en.wikipedia.org/wiki/Radix_tree)) from the input set, and doing a [pre-order](https://en.wikipedia.org/wiki/Tree_traversal#Pre-order,_NLR) traversal. This is similar to the relationship between [heapsort](https://en.wikipedia.org/wiki/Heapsort) and the [heap](https://en.wikipedia.org/wiki/Heap_(data_structure)) data structure. This can be useful for certain data types, see [burstsort](https://en.wikipedia.org/wiki/Burstsort).

> NOTE:
>
> 一、
>
> 将这种树称之为trie-digital-radix-tree
>
> 在 wikipedia [Trie#Sorting](https://en.wikipedia.org/wiki/Trie#Sorting) 中也有对上述主题的说明
>
> [LeetCode-386. Lexicographical Numbers-Medium](https://leetcode.cn/problems/lexicographical-numbers/) 

### Code

```python
import unittest
from typing import MutableSequence


class RadixSort:
    @classmethod
    def sort(cls, arr: MutableSequence[int]):
        # Find the maximum number to determine the number of digits
        max_num = max(arr)
        # Perform counting sort for every digit
        exp = 1  # exponent, LSB-radix-sort
        while max_num // exp > 0:  # floor div
            cls.counting_sort(arr, exp)
            exp *= 10
        return arr

    @classmethod
    def counting_sort(cls, arr: MutableSequence[int], exp: int):
        n = len(arr)
        output = [0] * n
        count = [0] * 10  # radix=10

        # Count the occurrences of each digit
        for i in range(n):
            index = arr[i] // exp
            count[index % 10] += 1

        # Calculate the cumulative count
        for i in range(1, 10):
            count[i] += count[i - 1]

        # Build the output array
        i = n - 1
        while i >= 0:
            index = arr[i] // exp
            output[count[index % 10] - 1] = arr[i]
            count[index % 10] -= 1
            i -= 1

        # Copy the sorted elements back to the original array
        for i in range(n):
            arr[i] = output[i]


class TestRadixSort(unittest.TestCase):
    def test_radix_sort(self):
        arr = [999, 888, 777, 666, 555, 444, 333, 222, 111, 0]
        sorted_arr = RadixSort.sort(arr)
        for num in sorted_arr:
            print(num)
        self.assertEqual(sorted_arr, sorted(arr))

```

