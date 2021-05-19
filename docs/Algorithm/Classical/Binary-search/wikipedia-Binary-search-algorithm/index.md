# wikipedia [Binary search algorithm](https://en.wikipedia.org/wiki/Binary_search_algorithm)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), **binary search**, also known as **half-interval search**,[[1\]](https://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-Williams1976-1) **logarithmic search**,[[2\]](https://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-FOOTNOTEKnuth1998§6.2.1_("Searching_an_ordered_table"),_subsection_"Binary_search"-2) or **binary chop**,[[3\]](https://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-FOOTNOTEButterfieldNgondi201646-3) is a [search algorithm](https://en.wikipedia.org/wiki/Search_algorithm) that finds the position of a target value within a [sorted array](https://en.wikipedia.org/wiki/Sorted_array).[[4\]](https://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-FOOTNOTECormenLeisersonRivestStein200939-4)[[5\]](https://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-5) Binary search compares the target value to the middle element of the array. If they are not equal, the half in which the target cannot lie is eliminated and the search continues on the remaining half, again taking the middle element to compare to the target value, and repeating this until the target value is found. If the search ends with the remaining half being empty, the target is not in the array.

Binary search runs in [logarithmic time](https://en.wikipedia.org/wiki/Time_complexity#Logarithmic_time) in the [worst case](https://en.wikipedia.org/wiki/Best,_worst_and_average_case), making $ O(\log n) $ comparisons, where $ n $ is the number of elements in the array, the $ O $ is [Big O notation](https://en.wikipedia.org/wiki/Big_O_notation), and $ \log $ is the [logarithm](https://en.wikipedia.org/wiki/Logarithm).[[6\]](https://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-FloresMadpis1971-6) Binary search is faster than [linear search](https://en.wikipedia.org/wiki/Linear_search) except for small arrays. However, the array must be sorted first to be able to apply binary search. There are specialized [data structures](https://en.wikipedia.org/wiki/Data_structures) designed for fast searching, such as [hash tables](https://en.wikipedia.org/wiki/Hash_tables), that can be searched more efficiently than binary search. However, binary search can be used to solve a wider range of problems, such as finding the next-smallest or next-largest element in the array relative to the target even if it is absent from the array.

There are numerous variations of binary search. In particular, [fractional cascading](https://en.wikipedia.org/wiki/Fractional_cascading) speeds up binary searches for the same value in multiple arrays. Fractional cascading efficiently solves a number of search problems in [computational geometry](https://en.wikipedia.org/wiki/Computational_geometry) and in numerous other fields. [Exponential search](https://en.wikipedia.org/wiki/Exponential_search) extends binary search to unbounded lists. The [binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree) and [B-tree](https://en.wikipedia.org/wiki/B-tree) data structures are based on binary search.



## Algorithm

### Procedure

```
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
> Set $ m $ (the position of the middle element) to the [ceiling](https://en.wikipedia.org/wiki/Floor_and_ceiling_functions)（天花板） of $ {\frac {L+R}{2}} $是否可以使用floor呢？是有差别的：当最终数组只剩下两个元素的时候，如果使用floor，则此时m会一直等于left，如果`A[m] <= T`，则程序会一直进入到上述伪代码中的else分支中，一下就是也例子：

```c
#include<iostream>
#include<vector>
using namespace std;
    

int search(vector<int>& nums, int target) {
        int right = nums.size() - 1;
        int left = 0;
        int middle = 0;
        while(left!=right){
            middle = (left + right) / 2;
            cout<<middle <<endl;
            
            if(nums[middle]>target){
                right = middle - 1;
            } else{
                left = middle;
            }
        }
        if(nums[left]==target) return left;
        return -1;
    }

int main(){
vector<int> nums{-1,0,3,5,9,12};
int target=9;
search(nums,target);
}
```

```
2
3
4
4
4
4
4
4
......
```





### Duplicate elements

The procedure may return any index whose element is equal to the target value, even if there are duplicate elements in the array. For example, if the array to be searched was $ [1,2,3,4,4,5,6,7] $ and the target was $ 4 $, then it would be correct for the algorithm to either return the 4th (index 3) or 5th (index 4) element. The regular procedure would return the 4th element (index 3) in this case. It does not always return the **first** duplicate (consider $ [1,2,4,4,4,5,6,7] $ which still returns the 4th element). However, it is sometimes necessary to find the **leftmost** element or the **rightmost** element for a target value that is duplicated in the array. In the above example, the 4th element is the **leftmost** element of the value 4, while the 5th element is the **rightmost** element of the value 4. The alternative procedure above will always return the index of the **rightmost** element if such an element exists.[[9\]](https://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-FOOTNOTEKnuth1998§6.2.1_("Searching_an_ordered_table"),_subsection_"History_and_bibliography"-9) 

#### Procedure for finding the leftmost element

 To find the **leftmost** element, the following procedure can be used:[[10\]](https://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-FOOTNOTEKasaharaMorishita20068–9-10) 

1. Set $ L $ to $ 0 $ and $ R $ to $ n $.

2. While $ L<R $ ,

   1. Set $ m $ (the position of the middle element) to the [floor](https://en.wikipedia.org/wiki/Floor_and_ceiling_functions) of $ {\frac {L+R}{2}} $, which is the greatest integer less than or equal to $ {\frac {L+R}{2}} $.
   2. If $ A_{m}<T $, set $ L $ to $ m+1 $.
   3. Else, $ A_{m}\geq T $; set *$ R $* to $ m $.

3. Return $ L $.

 If $ L<n $ and $ A_{L}=T $, then $ A_{L} $ is the leftmost element that equals $ T $. Even if $ T $ is not in the array, $ L $ is the [rank](https://en.wikipedia.org/wiki/Binary_search_algorithm#Approximate_matches) of $ T $ in the array, or the number of elements in the array that are less than $ T $. 

 Where `floor` is the floor function, the pseudocode for this version is: 

```
function binary_search_leftmost(A, n, T):
    L := 0
    R := n
    while L < R:
        m := floor((L + R) / 2)
        if A[m] < T:
            L := m + 1
        else:
            R := m
    return L
```

#### Procedure for finding the rightmost element

 To find the rightmost element, the following procedure can be used:[[10\]](https://en.wikipedia.org/wiki/Binary_search_algorithm#cite_note-FOOTNOTEKasaharaMorishita20068–9-10) 

1. Set $ L $ to $ 0 $ and $ R $ to $ n $.

2. While $ L<R $ ,

   1. Set $ m $ (the position of the middle element) to the [floor](https://en.wikipedia.org/wiki/Floor_and_ceiling_functions) of $ {\frac {L+R}{2}} $, which is the greatest integer less than or equal to $ {\frac {L+R}{2}} $.
   2. If $ A_{m}>T $, set $ R $ to $ m $.
   3. Else, $ A_{m}\leq T $; set *$ L $* to $ m+1 $.

3. Return $ L-1 $.

If $ L>0 $ and $ A_{L-1}=T $, then $ A_{L-1} $ is the rightmost element that equals $ T $. Even if *$ T $* is not in the array, $ n-L $ is the number of elements in the array that are greater than *$ T $*.

Where `floor` is the floor function, the pseudocode for this version is:

```
function binary_search_rightmost(A, n, T):
    L := 0
    R := n
    while L < R:
        m := floor((L + R) / 2)
        if A[m] > T:
            R := m
        else:
            L := m + 1
    return L - 1
```

***SUMMARY*** : 请问不要被这两种算法的表现所蒙蔽了，要从本质上来对算法进行分析，然后才能够写出对应的伪代码，下面从功能出发进行分析：

这两种算法本质都是二分法，所不同的是在于对$A_{m}==T$的处理上：

- 在leftmost中，将T归入到left分支，所以，当$A_{m}==T$时，要将`R`设置为`m`，由于是二分法，所以当$T<A_{m}$时，也要将`R`设置为`m`，综合起来，当$T <= A_{m}$时，将`R`设置为`m`；

  ```
  if A[m] == T:
      R := m
  else:
      if T < A[m] :
          R := m - 1
      else:
          L := m + 1
  ```

  

- 在rightmost中，将T归入到right分支，所以，当$A_{m}==T$时，要将`L`设置为`m`，由于是二分法，所以当$A_{m} < T$时，也要将`L`设置为`m`，综合起来，当$A_{m} <= T$时，将`L`设置为`m`；

  ```
  if A[m] == T:
      L := m
  else:
      if A[m] < T:
          L := m + 1
      else:
          R := m - 1
  ```

  

两种算法最终的终止条件都是L==R，即序列L-R中只剩下一个元素了。

| L-R     |      | L-R     |      |
| ------- | ---- | ------- | ---- |
| 0-7,m=3 | R=3  | 0-7,m=3 | L=4  |
|         |      |         |      |
|         |      |         |      |
|         |      |         |      |
|         |      |         |      |
|         |      |         |      |
|         |      |         |      |
|         |      |         |      |

显著的差异在于当`array[m]`与target相等的情况下，

