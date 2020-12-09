# Circular buffer

## 维基百科[Circular buffer](https://en.wikipedia.org/wiki/Circular_buffer)

A **circular buffer**, **circular queue**, **cyclic buffer** or **ring buffer** is a [data structure](https://en.wikipedia.org/wiki/Data_structure) that uses a single, fixed-size [buffer](https://en.wikipedia.org/wiki/Buffer_(computer_science)) as if it were connected end-to-end. This structure lends itself easily to buffering [data streams](https://en.wikipedia.org/wiki/Data_stream).

### Uses

The useful property of a **circular buffer** is that it does not need to have its elements shuffled around(移动) when one is consumed. (If a non-circular buffer were used then it would be necessary to **shift** all elements when one is consumed.) In other words, the circular buffer is well-suited as a [FIFO](https://en.wikipedia.org/wiki/FIFO_(computing_and_electronics)) buffer while a standard, non-circular buffer is well suited as a [LIFO](https://en.wikipedia.org/wiki/LIFO_(computing)) buffer.

**Circular buffering** makes a good implementation strategy for a [queue](https://en.wikipedia.org/wiki/Queue_(data_structure)) that has fixed maximum size. Should a maximum size be adopted for a queue, then a **circular buffer** is a completely ideal implementation; all queue operations are constant time. However, expanding a circular buffer requires shifting memory, which is comparatively costly. For arbitrarily expanding queues, a [linked list](https://en.wikipedia.org/wiki/Linked_list) approach may be preferred instead.

In some situations, overwriting(盖写) circular buffer can be used, e.g. in multimedia. If the buffer is used as the bounded buffer in the [producer-consumer problem](https://en.wikipedia.org/wiki/Producer-consumer_problem) then it is probably desired for the producer (e.g., an audio generator) to overwrite old data if the consumer (e.g., the [sound card](https://en.wikipedia.org/wiki/Sound_card)) is unable to momentarily keep up. Also, the [LZ77](https://en.wikipedia.org/wiki/LZ77) family of lossless data compression algorithms operates on the assumption that strings seen more recently in a data stream are more likely to occur soon in the stream. Implementations store the most recent data in a circular buffer.



### Circular buffer mechanics

A **circular buffer** can be implemented using four [pointers](https://en.wikipedia.org/wiki/Pointer_(computer_programming)), or two pointers and two integers:

- buffer start in memory
- buffer end in memory, or buffer capacity
- **start** of valid data (index or pointer)
- **end** of valid data (index or pointer), or amount of data currently in the buffer (integer)

In utilizing full buffer capacity with pointer-based implementation strategy, the buffer's full or empty state could not be resolved directly from checking the positions of the start and end indexes.[[1\]](https://en.wikipedia.org/wiki/Circular_buffer#cite_note-1) Therefore, an additional mechanism must be implemented for checking this. One common way to deal with this, when using 2 pointers, is to only allow the buffer to hold (size − 1) items. When both pointers are equal, the buffer is empty, and when the end pointer is one less than the start pointer, the buffer is full.

> NOTE: 如何来判定一个circular buffer是full或empty？当start和end指向同一个位置的时候，既有可能表示的是empty，也有可能表示的是full。所以解决这个问题的方式是，必须要明确地区分两者，上面这段话给出了实现思路：当empty时，start对于end，显然这是将start和end指向同一个位置的状态判定为empty状态；那full状态呢？当start在end后，且两者之间间隔一个元素的时候，表示的是full状态，显然这种方式，使用一个元素来作为这种状态的标志。





## Use case

保存最近一段时间内的行情

## Implementation

### [ spdlog](https://github.com/gabime/spdlog) [`circular_q.h`](https://github.com/gabime/spdlog/blob/v1.x/include/spdlog/details/circular_q.h) 

这是实现是按照上述维基百科[Circular buffer](https://en.wikipedia.org/wiki/Circular_buffer)中描述的实现的，在本目录下，收录了它的源代码。



### [CIRCULAR QUEUE IN C](http://www.martinbroadhurst.com/cirque-in-c.html)

这个实现也非常好，在本目录下，收录了它的源代码。

### Others



[Implementing a Queue using a *circular* array](http://www.mathcs.emory.edu/~cheung/Courses/171/Syllabus/8-List/array-queue2.html)

