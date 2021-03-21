# [Design a stack that supports getMin() in O(1) time and O(1) extra space](https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/)

## 问题描述

**Question:** Design a Data Structure `SpecialStack` that supports all the stack operations like `push()`, `pop()`, `isEmpty()`, `isFull()` and an additional operation `getMin()` which should return minimum element from the `SpecialStack`. All these operations of `SpecialStack` must be O(1). To implement `SpecialStack`, you should only use standard Stack data structure and no other data structure like arrays, list, .. etc.

Example:

```
Consider the following SpecialStack
16  --> TOP
15
29
19
18

When getMin() is called it should return 15, 
which is the minimum element in the current stack. 

If we do pop two times on stack, the stack becomes
29  --> TOP
19
18

When getMin() is called, it should return 18 
which is the minimum in the current stack.
```



[Recommended: Please solve it on “***PRACTICE\***” first, before moving on to the solution.](https://practice.geeksforgeeks.org/problems/special-stack/1)

## 算法

 An approach that uses O(1) time and O(n) extra space is discussed [here](https://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/). 



 In this article, a new approach is discussed that supports minimum with O(1) extra space. We define a variable **minEle** that stores the **current minimum element** in the stack. Now the interesting part is, how to handle the case when **minimum element** is removed. To handle this, we push “2x – minEle” into the stack instead of `x` so that **previous minimum element** can be retrieved using **current minEle** and its value stored in stack. Below are detailed steps and explanation of working. 

###  Push(x) 

 Inserts x at the top of stack. 

- If stack is empty, insert `x` into the stack and make `minEle` equal to `x`.

- If stack is not empty, compare `x` with `minEle`. Two cases arise:

  - If `x` is greater than or equal to `minEle`, simply insert `x`.

  - If `x` is less than `minEle`, insert `(2*x – minEle)` into the stack and make `minEle` equal to `x`. For example, let previous minEle was 3. Now we want to insert 2. We update minEle as 2 and insert 2*2 – 3 = 1 into the stack.

    ***SUMMARY*** : 因为`x`是小于`minEle`的，所以 `(2*x – minEle)` 是小于`x`的

### Pop()  

Removes an element from top of stack.

- Remove element from top. Let the removed element be y. Two cases arise:
  - If y is greater than or equal to minEle, the minimum element in the stack is still minEle.
  - If y is less than minEle, the minimum element now becomes `(2*minEle – y)`, so update `(minEle = 2*minEle – y)`. This is where we retrieve previous minimum from current minimum and its value in stack. For example, let the element to be removed be 1 and `minEle` be 2. We remove 1 and update `minEle` as 2*2 – 1 = 3.



**Important Points:**

- Stack doesn’t hold actual value of an element if it is minimum so far.
- Actual minimum element is always stored in `minEle`



***SUMMARY*** : 这种实现方式是非常巧妙的，它建立了当前的`minEle` 和last `minEle` 之间的**关联/映射函数**。通过**关联/映射函数**，就可以根据当前的`minEle`计算出last `minEle`，并且使用这个 **关联/映射函数**绕过来空间的限制，我们可以无限往前进行倒推找到很久远之前的 `minEle`。它能够实现和hash function类似的效果，在实现associate array的时候，binary search tree往往是通过存储树结构来实现key-value的映射，而hash function则直接通过一个function就实现了；





# [Find maximum in a stack in O(1) time and O(1) extra space](https://www.geeksforgeeks.org/find-maximum-in-a-stack-in-o1-time-and-o1-extra-space/)





# [Design and Implement Special Stack Data Structure | Added Space Optimized Version](https://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/)