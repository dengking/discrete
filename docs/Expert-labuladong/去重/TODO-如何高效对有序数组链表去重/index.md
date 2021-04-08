# labuladong [如何高效对有序数组/链表去重？](https://mp.weixin.qq.com/s/6Eb7gKqNqXH9B0hSZvMs5A)

> NOTE: 
>
> 1、典型的double pointer-fast slow pointer
>
> 2、使用这个algorithm的前提是: 数组是有序的，如果数组无序，则无法使用此算法
>
> 3、让`[0、slow]`包含所有的不重复元素，fast指针在前进过程中，一旦发现了`array[fast]`和`array[slow]`不相等，则说明需要扩展`[0、slow]`区间了
>
> 4、这个算法让我想到了C++remove erase idiom