# geeksforgeeks [Binary Indexed Tree or Fenwick Tree](https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/)

## Representation

**Binary Indexed Tree** is represented as an array. Let the array be `BITree[]`. Each node of the **Binary Indexed Tree** stores the sum of some elements of the input array. The size of the **Binary Indexed Tree** is equal to the size of the input array, denoted as `n`. In the code below, we use a size of `n+1` for ease of implementation.



## Construction

We initialize all the values in `BITree[]` as 0. Then we call `update()` for all the indexes, the `update()` operation is discussed below.



## Operations

### `getSum(x)`

```
getSum(x): Returns the sum of the sub-array arr[0,…,x] 
// Returns the sum of the sub-array arr[0,…,x] using BITree[0..n], which is constructed from arr[0..n-1] 
1) Initialize the output sum as 0, the current index as x+1. 
2) Do following while the current index is greater than 0. 
…a) Add BITree[index] to sum 
…b) Go to the parent of BITree[index]. The parent can be obtained by removing 
the last set bit from the current index, i.e., index = index – (index & (-index)) 
3) Return sum.
```



![](BITSum.png)

The diagram above provides an example of how `getSum()` is working. Here are some important observations.

1、`BITree[0]` is a dummy node. 

2、`BITree[y]` is the parent of `BITree[x]`, if and only if `y` can be obtained by removing the last set bit from the binary representation of `x`, that is `y = x – (x & (-x))`.

3、The child node `BITree[x]` of the node `BITree[y]` stores the sum of the elements between `y`(inclusive) and `x`(exclusive): `arr[y,…,x)`. 

> NOTE:
>
> 一、3特别重要
>
> 二、它是典型的**数字树**:
>
> 1、树的层高由下标数字二进制表示中1的个数决定，显然第0层只有一个节点0，第1层都是含有一个1的（2的整数幂）
>
> 2、显然下标更小的位于树的内部，更大的位于树的叶子，这是因为它们拥有共同的数位:
>
> a、The parent can be obtained by removing the last set bit from the current index, i.e., index = index – (index & (-index)) 
>
> b、
>
> 三、求和只需要自底向上沿着path直至root node

### `update(x, val)`

```
update(x, val): Updates the Binary Indexed Tree (BIT) by performing arr[index] += val 
// Note that the update(x, val) operation will not change arr[]. It only makes changes to BITree[] 
1) Initialize the current index as x+1. 
2) Do the following while the current index is smaller than or equal to n. 
…a) Add the val to BITree[index] 
…b) Go to next element of BITree[index]. The next element can be obtained by incrementing the last set bit of the current index, i.e., index = index + (index & (-index))
```



![BITUpdate1](https://media.geeksforgeeks.org/wp-content/cdn-uploads/BITUpdate12.png)

The update function needs to make sure that all the BITree nodes which contain arr[i] within their ranges being updated. We loop over such nodes in the BITree by repeatedly adding the decimal number corresponding to the last set bit of the current index.

## How does Binary Indexed Tree work?

The idea is based on the fact that all positive integers can be represented as the sum of powers of 2. For example 19 can be represented as 16 + 2 + 1. Every node of the BITree stores the sum of n elements where n is a power of 2. For example, in the first diagram above (the diagram for getSum()), the sum of the first 12 elements can be obtained by the sum of the last 4 elements (from 9 to 12) plus the sum of 8 elements (from 1 to 8). The number of set bits in the binary representation of a number n is O(Logn). Therefore, we traverse at-most O(Logn) nodes in both getSum() and update() operations. The time complexity of the construction is O(nLogn) as it calls update() for all n elements. 



