# External sorting



## 面试题

### csdn [腾讯社招面试经历](https://blog.csdn.net/hong2511/article/details/81284498)

之后就问我一道算法题：10亿个整数，随机生成，可重复，求最大的前1万个。

10亿个整数选前1万个大数，其实可以用：分治法+hash+多路归并排序来做，比如说，先把10亿个整数对1000取模，存储到1000个文件中，然后对每一个文件进行内部排序(比如快速排序，从大到小排序)，然后再对这1000个文件进行多路归并，取出前1万个最大的数即可。

> NOTE: 
>
> 1、"divide and conquer and merge"思想
>
> 2、"K way merge algorithm-多路合并"

### LeetCode [文件中存在亿级数据，按某个字段进行排序，输出前100万数据](https://leetcode.cn/circle/discuss/fW1wqB/) 

文件中存在亿级数据，并且每条数据是多个字段，如何按某个字段进行排序后，输出前100万数据(需要写出代码)

文件中存在大量数据，亿级别的数据，需要按照某一列进行排序。
样例：
buyer1,item1,13812348765,123,2020-01-01 01:00:00,1…
buyer2,item2,13812348765,123,2020-01-01 01:00:00,2…
buyer2,item2,13812348765,123,2020-01-01 01:00:00,3…
要求：
1：可以按照其中某几列进行排序，按照手机号码或者用户ID进行排序
2：内存使用限制不超过64M，高效快速完成排序，并输出前100万数据

主要考察点：

1：文件处理
2：排序处理
3：线程处理
4：NIO

### LeetCode [这可能不只是一篇面经](https://leetcode.cn/circle/discuss/alVTol/)



### LeetCode [海量数据处理方法](https://leetcode.cn/circle/article/qlkHuN/)



## weixin [海量数据处理](https://mp.weixin.qq.com/s?__biz=Mzg5OTU3MjQ4Ng==&mid=2247485150&idx=1&sn=6df5f452631bc81005f08c04c01e8904&chksm=c05070b7f727f9a106b22158148e3ce8f1ff33627bac6f92b52dffa70fd8a705abae0f4c1d25&scene=132#wechat_redirect)



## wanweibaike [External sorting](https://en.wanweibaike.com/wiki-External%20sorting)

**External sorting** is a class of [sorting](https://en.wanweibaike.com/wiki-Sorting) [algorithms](https://en.wanweibaike.com/wiki-Algorithm) that can handle massive amounts of [data](https://en.wanweibaike.com/wiki-Data). External sorting is required when the data being sorted do not fit into the [main memory](https://en.wanweibaike.com/wiki-Main_memory) of a computing device (usually [RAM](https://en.wanweibaike.com/wiki-RAM)) and instead they must reside in the slower [external memory](https://en.wanweibaike.com/wiki-Auxiliary_memory), usually a [hard disk drive](https://en.wanweibaike.com/wiki-Hard_disk_drive). Thus, external sorting algorithms are [external memory algorithms](https://en.wanweibaike.com/wiki-External_memory_algorithm) and thus applicable in the [external memory](https://en.wanweibaike.com/wiki-External_memory_model) [model of computation](https://en.wanweibaike.com/wiki-Model_of_computation).

> NOTE: 
>
> 1、" [external memory algorithms](https://en.wanweibaike.com/wiki-External_memory_algorithm) " 是第一次听说的概念

External sorting algorithms generally fall into two types:

1、distribution sorting, which resembles [quicksort](https://en.wanweibaike.com/wiki-Quicksort), and 

2、external merge sort, which resembles [merge sort](https://en.wanweibaike.com/wiki-Merge_sort). The latter typically uses a [hybrid](https://en.wanweibaike.com/wiki-Hybrid_algorithm) sort-merge strategy. In the sorting phase, chunks of data small enough to fit in main memory are read, sorted, and written out to a temporary file. In the merge phase, the sorted subfiles are combined into a single larger file.

### External merge sort

> NOTE: 
>
> 这种是常用的

