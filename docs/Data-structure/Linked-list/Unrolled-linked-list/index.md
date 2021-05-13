# Unrolled linked list

## wikipedia [Unrolled linked list](https://en.wikipedia.org/wiki/Unrolled_linked_list)

> NOTE: 
>
> 1、展开的链表 
>
> 2、我使用过这种data structure来实现内存表

In computer programming, an **unrolled linked list** is a variation on the [linked list](https://en.wikipedia.org/wiki/Linked_list) which stores multiple elements in each node. It can dramatically increase [cache](https://en.wikipedia.org/wiki/CPU_cache) performance, while decreasing the memory overhead associated with storing list metadata such as [references](https://en.wikipedia.org/wiki/Reference). It is related to the [B-tree](https://en.wikipedia.org/wiki/B-tree). 

### Overview

A typical unrolled linked list node looks like this:

```c++
 record node {
     node next       // reference to next node in list
     int numElements // number of elements in this node, up to maxElements
     array elements  // an array of numElements elements,
                     //   with space allocated for maxElements elements
 }
```

Each node holds up to a certain maximum number of elements, typically just large enough so that the node fills a single [cache line](https://en.wanweibaike.com/wiki-Cache_line) or a small multiple thereof. A position in the list is indicated by both a reference to the node and a position in the elements array. It is also possible to include a *previous* pointer for an unrolled [doubly linked list](https://en.wanweibaike.com/wiki-Doubly_linked_list).

> NOTE:
>
> 1、"align-to-cache line-optimization"

To insert a new element, we simply find the node the element should be in and insert the element into the `elements` array, incrementing `numElements`. If the array is already full, we first insert a new node either preceding or following the current one and move half of the elements in the current node into it.

To remove an element, we simply find the node it is in and delete it from the `elements` array, decrementing `numElements`. If this reduces the node to less than half-full, then we move elements from the next node to fill it back up above half. If this leaves the next node less than half full, then we move all its remaining elements into the current node, then bypass and delete it.

> NOTE: 
>
> 1、通过上面的描述来看，unrolled linked list的实现还是有点复杂的

### Performance

> NOTE: 
>
> 一、原文这一段主要是和 linked list进行对比，从如下两个方面: 
>
> 1、space: 相比之下，linked list是比较耗费空间的，unrolled linked list是能够更加节省空间的
>
> 2、time: cache performance，cache miss更少

