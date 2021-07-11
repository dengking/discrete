# Quicksort && BST

正如 wikipedia [Quicksort](https://en.wikipedia.org/wiki/Quicksort) 中所总结的:

> To each execution of **quicksort** corresponds the following [binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree) (BST): 
>
> the **initial pivot** is the **root node**; 
>
> the **pivot of the left half** is the **root of the left subtree**, 
>
> the **pivot of the right half** is the **root of the right subtree**, and so on. 



> **Quicksort** is a space-optimized version of the [binary tree sort](https://en.wikipedia.org/wiki/Binary_tree_sort). Instead of inserting items sequentially into an explicit tree, quicksort organizes them concurrently into a tree that is implied by the recursive calls. The algorithms make exactly the same comparisons, but in a different order. 

显然，Quicksort是:

1、隐式地构建BST

2、自顶向下地构建BST