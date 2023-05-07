# geeksforgeeks [Building Heap from Array](https://www.geeksforgeeks.org/building-heap-from-array/)



- Root is at index 0 in array.
- Left child of i-th node is at (2*i + 1)th index.
- Right child of i-th node is at (2*i + 2)th index.
- Parent of i-th node is at (i-1)/2 index.



**Efficient Approach**: To solve the problem using this approach follow the below idea:

The above approach can be optimized by observing the fact that the leaf nodes need not to be *heapified* as they already follow the **heap property**. Also, the array representation of the complete binary tree contains the **level order traversal** of the tree. So the idea is to find the position of the **last non-leaf node** and perform the heapify operation of each non-leaf node in **reverse level order**. 

> NOTE:
>
> 一、其实就是reverse-BFS

**Last non-leaf node** *= parent of last-node.*
*or, Last non-leaf node = parent of node at (n-1)th index.*
*or, Last non-leaf node = Node at index ((n-1) – 1)/2 = (n/2) – 1.*



```
Array = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17}
Corresponding Complete Binary Tree is:

                 1
              /     \
            3         5
          /    \     /  \
         4      6   13  10
        / \    / \
       9   8  15 17

The task to build a Max-Heap from above array.

Total Nodes = 11.
Last Non-leaf node index = (11/2) – 1 = 4.
Therefore, last non-leaf node = 6.

To build the heap, heapify only the nodes: [1, 3, 5, 4, 6] in reverse order.

Heapify 6: Swap 6 and 17.

                 1
              /     \
            3         5
         /    \      /  \
       4      17   13  10
      / \    /  \
     9   8  15   6

Heapify 4: Swap 4 and 9.

                 1
              /     \
            3         5
          /    \      /  \
         9      17   13  10
       / \    /  \
      4   8  15   6

Heapify 5: Swap 13 and 5.

                 1
              /     \
            3         13
          /    \      /  \
         9      17   5   10
       / \    /  \
      4   8  15   6

Heapify 3: First Swap 3 and 17, again swap 3 and 15.

                 1
              /     \
           17         13
         /    \      /  \
        9      15   5   10
       / \    /  \
      4   8  3   6

Heapify 1: First Swap 1 and 17, again swap 1 and 15, finally swap 1 and 6.

                 17
              /      \
            15         13
          /    \      /  \
         9      6    5   10
        / \    /  \
       4   8  3    1
```

