# External sorting



## 面试题

csdn [腾讯社招面试经历](https://blog.csdn.net/hong2511/article/details/81284498)

之后就问我一道算法题：10亿个整数，随机生成，可重复，求最大的前1万个。

10亿个整数选前1万个大数，其实可以用：分治法+hash+多路归并排序来做，比如说，先把10亿个整数对1000取模，存储到1000个文件中，然后对每一个文件进行内部排序(比如快速排序，从大到小排序)，然后再对这1000个文件进行多路归并，取出前1万个最大的数即可。

> NOTE: 
>
> 1、"divide and conquer and merge"思想
>
> 2、"K way merge algorithm-多路合并"



## wanweibaike [External sorting](https://en.wanweibaike.com/wiki-External%20sorting)

**External sorting** is a class of [sorting](https://en.wanweibaike.com/wiki-Sorting) [algorithms](https://en.wanweibaike.com/wiki-Algorithm) that can handle massive amounts of [data](https://en.wanweibaike.com/wiki-Data). External sorting is required when the data being sorted do not fit into the [main memory](https://en.wanweibaike.com/wiki-Main_memory) of a computing device (usually [RAM](https://en.wanweibaike.com/wiki-RAM)) and instead they must reside in the slower [external memory](https://en.wanweibaike.com/wiki-Auxiliary_memory), usually a [hard disk drive](https://en.wanweibaike.com/wiki-Hard_disk_drive). Thus, external sorting algorithms are [external memory algorithms](https://en.wanweibaike.com/wiki-External_memory_algorithm) and thus applicable in the [external memory](https://en.wanweibaike.com/wiki-External_memory_model) [model of computation](https://en.wanweibaike.com/wiki-Model_of_computation).

> NOTE: 
>
> 1、" [external memory algorithms](https://en.wanweibaike.com/wiki-External_memory_algorithm) " 是第一次听说的概念

External sorting algorithms generally fall into two types:

1、distribution sorting, which resembles [quicksort](https://en.wanweibaike.com/wiki-Quicksort), and 

2、external merge sort, which resembles [merge sort](https://en.wanweibaike.com/wiki-Merge_sort). The latter typically uses a [hybrid](https://en.wanweibaike.com/wiki-Hybrid_algorithm) sort-merge strategy. In the sorting phase, chunks of data small enough to fit in main memory are read, sorted, and written out to a temporary file. In the merge phase, the sorted subfiles are combined into a single larger file.