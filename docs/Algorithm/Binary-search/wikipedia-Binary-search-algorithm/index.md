# wikipedia [Binary search algorithm](https://en.wikipedia.org/wiki/Binary_search_algorithm) 

In [computer science](https://en.wikipedia.org/wiki/Computer_science), **binary search**, also known as **half-interval search**,[[1\]](https://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-Williams1976-1) **logarithmic search**,[[2\]](https://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-FOOTNOTEKnuth1998§6.2.1_("Searching_an_ordered_table"),_subsection_"Binary_search"-2) or **binary chop**,[[3\]](https://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-FOOTNOTEButterfieldNgondi201646-3) is a [search algorithm](https://en.wikipedia.org/wiki/Search_algorithm) that finds the position of a target value within a [sorted array](https://en.wikipedia.org/wiki/Sorted_array).[[4\]](https://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-FOOTNOTECormenLeisersonRivestStein200939-4)[[5\]](https://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-5) Binary search compares the target value to the middle element of the array. If they are not equal, the half in which the target cannot lie is eliminated and the search continues on the remaining half, again taking the middle element to compare to the target value, and repeating this until the target value is found. If the search ends with the remaining half being empty, the target is not in the array.

Binary search runs in [logarithmic time](https://en.wikipedia.org/wiki/Time_complexity#Logarithmic_time) in the [worst case](https://en.wikipedia.org/wiki/Best,_worst_and_average_case), making $ O(\log n) $ comparisons, where $ n $ is the number of elements in the array, the $ O $ is [Big O notation](https://en.wikipedia.org/wiki/Big_O_notation), and $ \log $ is the [logarithm](https://en.wikipedia.org/wiki/Logarithm).[[6\]](https://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-FloresMadpis1971-6) Binary search is faster than [linear search](https://en.wikipedia.org/wiki/Linear_search) except for small arrays. However, the array must be sorted first to be able to apply binary search. There are specialized [data structures](https://en.wikipedia.org/wiki/Data_structures) designed for fast searching, such as [hash tables](https://en.wikipedia.org/wiki/Hash_tables), that can be searched more efficiently than binary search. However, binary search can be used to solve a wider range of problems, such as finding the next-smallest or next-largest element in the array relative to the target even if it is absent from the array.

There are numerous variations of binary search. In particular, [fractional cascading](https://en.wikipedia.org/wiki/Fractional_cascading) speeds up binary searches for the same value in multiple arrays. Fractional cascading efficiently solves a number of search problems in [computational geometry](https://en.wikipedia.org/wiki/Computational_geometry) and in numerous other fields. [Exponential search](https://en.wikipedia.org/wiki/Exponential_search) extends binary search to unbounded lists. The [binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree) and [B-tree](https://en.wikipedia.org/wiki/B-tree) data structures are based on binary search.

> NOTE: 
>
> 总结得非常好

## Algorithm

### Procedure

```pseudocode
function binary_search(A, n, T):
    L := 0
    R := n − 1
    while L <= R:
        m := floor((L + R) / 2)
        if A[m] < T:
            L := m + 1
        else if A[m] > T:
            R := m - 1
        else:
            return m
    return unsuccessful
```

#### Alternative procedure

In the above procedure, the algorithm checks whether the middle element ($ m $) is **equal to** the target ($ T $) in every iteration. Some implementations leave out this check during each iteration. The algorithm would perform this check only when one element is left (when $ L=R $). This results in a faster comparison loop, as one comparison is eliminated per iteration. However, it requires one more iteration on average.[[8\]](https://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-Bottenbruch1962-8)

[Hermann Bottenbruch](https://en.wikipedia.org/wiki/Hermann_Bottenbruch) published the first implementation to leave out this check in 1962.[[8\]](https://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-Bottenbruch1962-8)[[9\]](https://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-FOOTNOTEKnuth1998§6.2.1_("Searching_an_ordered_table"),_subsection_"History_and_bibliography"-9)

1、 Set $ L $ to $ 0 $ and $ R $ to $ n-1 $.

2、 While $ L\neq R $ ,

   1. Set $ m $ (the position of the middle element) to the [ceiling](https://en.wikipedia.org/wiki/Floor_and_ceiling_functions)（天花板） of $ {\frac {L+R}{2}} $, which is the least integer greater than or equal to $ {\frac {L+R}{2}} $.（此处为什么是 [ceiling](https://en.wikipedia.org/wiki/Floor_and_ceiling_functions) of $ {\frac {L+R}{2}} $？如果不是会怎样？）
   2. If $ A_{m}>T $, set $ R $ to $ m-1 $.
   3. Else, $ A_{m}\leq T $; set $ L $ to $ m $.

3、 Now $ L=R $, the search is done. If $ A_{L}=T $, return $ L $. Otherwise, the search terminates as unsuccessful.

Where `ceil` is the ceiling function, the pseudocode for this version is:

```
function binary_search_alternative(A, n, T):
    L := 0
    R := n − 1
    while L != R:
        m := ceil((L + R) / 2)
        if A[m] > T:
            R := m - 1
        else:
            L := m
    if A[L] == T:
        return L
    return unsuccessful
```

> NOTE: 
>
> 这种实现方式和上面那种的实现方式的差异在于上面的那种方式在每次循环中对target和中间元素（后续为了描述遍历，将它称为pivot）进行了两次比较：
>
> - **大于**的比较
> - **小于**的比较
>
> 由于进行了两次的比较所以它能够将整个序列分为三份：pivot、左边一份（不包括pivot）和右边一份（不包括pivot），所以程序可以非常准确地判断要进入到哪个分支中；
>
> 但是这种算法，由于只进行了一次比较，所以它只能够将这个序列分成两部分，并且由于没有进行等于的判断，所以不能够确定pivot是否是target，所以只能够将它归入左边分支后者右边分支。上述算法中将pivot归入了右边分支，所以左边分支就可以不需要考虑pivot了，所以`R := m - 1`；
>
> Set $ m $ (the position of the middle element) to the [ceiling](https://en.wikipedia.org/wiki/Floor_and_ceiling_functions)（天花板） of $ {\frac {L+R}{2}} $是否可以使用floor呢？是有差别的：当最终数组只剩下两个元素的时候，如果使用floor，则此时m会一直等于left，如果`A[m] <= T`，则程序会一直进入到上述伪代码中的else分支中，以下就是例子：
>
> ```C++
> #include<iostream>
> #include<vector>
> using namespace std;
>     
> 
> int search(vector<int>& nums, int target) {
>         int right = nums.size() - 1;
>         int left = 0;
>         int middle = 0;
>         while(left!=right){
>             middle = (left + right) / 2;
>             cout<<middle <<endl;
>             
>             if(nums[middle]>target){
>                 right = middle - 1;
>             } else{
>                 left = middle;
>             }
>         }
>         if(nums[left]==target) return left;
>         return -1;
>     }
> 
> int main(){
> vector<int> nums{-1,0,3,5,9,12};
> int target=9;
> search(nums,target);
> }
> ```
>
> 



### Duplicate elements

The procedure may return any index whose element is equal to the target value, even if there are duplicate elements in the array. For example, if the array to be searched was $ [1,2,3,4,4,5,6,7] $ and the target was $ 4 $, then it would be correct for the algorithm to either return the 4th (index 3) or 5th (index 4) element. The regular procedure would return the 4th element (index 3) in this case. It does not always return the **first** duplicate (consider $ [1,2,4,4,4,5,6,7] $ which still returns the 4th element). However, it is sometimes necessary to find the **leftmost** element or the **rightmost** element for a target value that is duplicated in the array. In the above example, the 4th element is the **leftmost** element of the value 4, while the 5th element is the **rightmost** element of the value 4. The alternative procedure above will always return the index of the **rightmost** element if such an element exists.[[9\]](https://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-FOOTNOTEKnuth1998§6.2.1_("Searching_an_ordered_table"),_subsection_"History_and_bibliography"-9) 

> NOTE: 
>
> 这些其实就是left bound 和 right bound，在 **labuladong** [我作了首诗，保你闭着眼睛也能写对二分查找](https://mp.weixin.qq.com/s/M1KfTfNlu4OCK8i9PSAmug) 中有着非常好的分析

### Approximate matches

The above procedure only performs *exact* matches, finding the position of a target value. However, it is trivial to extend binary search to perform approximate matches because binary search operates on sorted arrays. For example, binary search can be used to compute, for a given value, its 

1、rank (the number of smaller elements), 

> NOTE: 
>
> 一、例子
>
> LeetCode [35. 搜索插入位置](https://leetcode.cn/problems/search-insert-position/) 

2、predecessor (next-smallest element),

3、 successor (next-largest element), and 

4、[nearest neighbor](https://en.wikipedia.org/wiki/Nearest_neighbor_search). 

5、[Range queries](https://en.wikipedia.org/wiki/Range_query_(data_structures)) seeking the number of elements between two values can be performed with two rank queries.

> NOTE: 
>
> 一、例子
>
> LeetCode [34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/)



1、Rank queries can be performed with the [procedure for finding the leftmost element](https://en.wikipedia.org/wiki/Binary_search_algorithm#Procedure_for_finding_the_leftmost_element). The number of elements *less than* the target value is returned by the procedure.

2、Predecessor queries can be performed with rank queries. If the rank of the target value is {\displaystyle r}![r](https://wikimedia.org/api/rest_v1/media/math/render/svg/0d1ecb613aa2984f0576f70f86650b7c2a132538), its predecessor is {\displaystyle r-1}![r-1](https://wikimedia.org/api/rest_v1/media/math/render/svg/1ad04896104e929da32fad148e240b3fd8dfa874).

3、For successor queries, the [procedure for finding the rightmost element](https://en.wikipedia.org/wiki/Binary_search_algorithm#Procedure_for_finding_the_rightmost_element) can be used. If the result of running the procedure for the target value is *{\displaystyle r}![r](https://wikimedia.org/api/rest_v1/media/math/render/svg/0d1ecb613aa2984f0576f70f86650b7c2a132538)*, then the successor of the target value is {\displaystyle r+1}![r+1](https://wikimedia.org/api/rest_v1/media/math/render/svg/7bf1b7e1e8ed2801660c299494ed10e6f18f790d).

4、The nearest neighbor of the target value is either its predecessor or successor, whichever is closer.

5、Range queries are also straightforward.[[12\]](https://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-FOOTNOTEGoldmanGoldman2008461–463-13) Once the ranks of the two values are known, the number of elements greater than or equal to the first value and less than the second is the difference of the two ranks. This count can be adjusted up or down by one according to whether the endpoints of the range should be considered to be part of the range and whether the array contains entries matching those endpoints.

> NOTE: 
>
> 总结得非常好