# Stream

“stream”即“流”，stream是一种非常强大的**抽象结构**，在computer science中被广泛应用：计算机科学是关于**数据**的科学，我们的计算机系统处理着各种各样的**数据**，我们可以形象地将**数据**的传递看做是"**水流**"一般: **数据**就像**水流**的流转一般在**计算机系统**中进行流转。

> NOTE: 上面这段话中的**数据**、**计算机系统**都是抽象概念，它们可以指代很多内容

Stream可以用做描述**数据流**的**抽象结构**。



## wikipedia [Stream (computing)](https://en.wikipedia.org/wiki/Stream_(computing))

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a **stream** is a [sequence](https://en.wikipedia.org/wiki/Sequence) of [data elements](https://en.wikipedia.org/wiki/Data_element) made available over time. A stream can be thought of as items on a [conveyor belt](https://en.wikipedia.org/wiki/Conveyor_belt) (传送带) being processed one at a time rather than in large batches.

> TRANSLATION: 在计算机科学中，stream是随时间推移可用的一系列数据元素。 可以将stream视为传送带上的物品，一次一个地处理，而不是大批量处理。

**Streams** are processed differently from [batch data](https://en.wikipedia.org/wiki/Batch_processing) – normal functions cannot operate on streams as a whole(不能够整个的操作stream), as they have potentially **unlimited data**, and formally, streams are [*codata*](https://en.wikipedia.org/wiki/Codata_(computer_science)) (potentially unlimited), not data (which is finite). 

> NOTE: 上面这段话所论述的是stream 和 batch。

Functions that operate on a stream, producing another stream, are known as [filters](https://en.wikipedia.org/wiki/Filter_(software)), and can be connected in [pipelines](https://en.wikipedia.org/wiki/Pipeline_(computing)), analogously to [function composition](https://en.wikipedia.org/wiki/Function_composition_(computer_science)). Filters may operate on one item of a stream at a time, or may base an item of output on multiple items of input, such as a [moving average](https://en.wikipedia.org/wiki/Moving_average).

> NOTE: 上面这段话其实给出了stream的programming model，显然，它非常类似于functional programming的。

### Examples

The term "stream" is used in a number of similar ways:

1) "Stream editing", as with [sed](https://en.wikipedia.org/wiki/Sed), [awk](https://en.wikipedia.org/wiki/Awk), and [perl](https://en.wikipedia.org/wiki/Perl). Stream editing processes a file or files, in-place, without having to load the file(s) into a user interface. One example of such use is to do a search and replace on all the files in a directory, from the command line.

2) On [Unix](https://en.wikipedia.org/wiki/Unix) and related systems based on the [C language](https://en.wikipedia.org/wiki/C_(programming_language)), a stream is a source or [sink](https://en.wikipedia.org/wiki/Sink_(computing)) of data, usually individual bytes or [characters](https://en.wikipedia.org/wiki/Character_(computing)). Streams are an **abstraction** used when reading or writing files, or communicating over [network sockets](https://en.wikipedia.org/wiki/Network_socket). The **standard streams** are three streams made available to all programs.

3) I/O devices can be interpreted as **streams**, as they produce or consume potentially unlimited data over time.

> NOTE: 2、3所指为stream-based IO。

4) In [object-oriented programming](https://en.wikipedia.org/wiki/Object-oriented_programming), input streams are generally implemented as [iterators](https://en.wikipedia.org/wiki/Iterator).

> NOTE: 如何对iterator进行操作？

5) In the [Scheme language](https://en.wikipedia.org/wiki/Scheme_(programming_language)) and some others, a stream is a [lazily evaluated](https://en.wikipedia.org/wiki/Lazy_evaluation) or *delayed* sequence of data elements. A stream can be used similarly to a list, but later elements are only calculated when needed. Streams can therefore represent infinite [sequences](https://en.wikipedia.org/wiki/Sequence) and [series](https://en.wikipedia.org/wiki/Series_(mathematics)). 

6) In the [Smalltalk](https://en.wikipedia.org/wiki/Smalltalk) [standard library](https://en.wikipedia.org/wiki/Standard_library) and in other [programming languages](https://en.wikipedia.org/wiki/Programming_language) as well, a stream is an **external iterator**. As in Scheme, streams can represent finite or infinite sequences.

7) [Stream processing](https://en.wikipedia.org/wiki/Stream_processing) — in [parallel processing](https://en.wikipedia.org/wiki/Parallel_computing), especially in graphic processing, the term stream is applied to [hardware](https://en.wikipedia.org/wiki/Computer_hardware) as well as [software](https://en.wikipedia.org/wiki/Software). There it defines the quasi-continuous flow of data that is processed in a [dataflow programming](https://en.wikipedia.org/wiki/Dataflow_programming) language as soon as the [program state](https://en.wikipedia.org/wiki/Program_state) meets the starting condition of the stream.

> NOTE: stream processing是parallel computing中的重要model，参见工程parallel-computing的`Model\Stream-model`章节。

### Applications

Streams can be used as the underlying data type for [channels](https://en.wikipedia.org/wiki/Channel_(programming)) in [interprocess communication](https://en.wikipedia.org/wiki/Interprocess_communication).

### [Other uses](https://en.wikipedia.org/wiki/Stream_(computing)#Other_uses)

> NOTE: 非常重要的描述

## Stream的单位

对stream的单位、组成的分析是非常重要的，一般将单位放到具体stream的命名中，下面是我目前所遇到的具体stream: 

| 具体stream                                           | 说明                                                         |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| [Bitstream](https://en.wikipedia.org/wiki/Bitstream) | 单位是bit                                                    |
| byte stream                                          | 单位是byte                                                   |
| character stream                                     | 单位是character                                              |
| data stream                                          | 单位是data，显然data是一个抽象的概念，它是big data、parallel computing等时代背景的产物。<br>另外与它相关的是: dataflow programming paradigm，其实dataflow就是data stream |
| message/event stream                                 | 单位是message/event，参见下面的`Stream-based message/event processing system`章节 |

需要注意的是，上面这些stream并不是具体的分类，更多的是在具体的实际应用中的抽象。

### Byte stream VS character stream

geeksforgeeks [Character Stream Vs Byte Stream in Java](https://www.geeksforgeeks.org/character-stream-vs-byte-stream-java/)

stackoverflow [Byte Stream and Character stream](https://stackoverflow.com/questions/3013996/byte-stream-and-character-stream)

iitk [Character Streams versus Byte Streams](http://www.iitk.ac.in/esc101/05Aug/tutorial/post1.0/converting/charVsByteStreams.html)

通过上述文章可以总结：byte stream和character stream的主要差别在于每次处理的unit不同：

byte stream的unit是byte，character stream的unit是character；一个character由一个或者多个byte组成。

### Byte stream VS bit stream

stackoverflow [Difference between byte stream and bit stream](https://stackoverflow.com/questions/35627938/difference-between-byte-stream-and-bit-stream)

### wikipedia [Bitstream](https://en.wikipedia.org/wiki/Bitstream)

A **bitstream** (or **bit stream**), also known as **binary sequence**, is a [sequence](https://en.wikipedia.org/wiki/Sequence) of [bits](https://en.wikipedia.org/wiki/Bit).

A **bytestream** is a sequence of [bytes](https://en.wikipedia.org/wiki/Byte). Typically, each byte is an 8-bit quantity ([octets](https://en.wikipedia.org/wiki/Octet_(computing))), and so the term **octet stream** is sometimes used interchangeably. An octet may be encoded as a sequence of 8 bits in multiple different ways (see [endianness](https://en.wikipedia.org/wiki/Endianness)) so there is no unique and direct translation between **bytestreams** and **bitstreams**.

**Bitstreams** and **bytestreams** are used extensively in [telecommunications](https://en.wikipedia.org/wiki/Telecommunications) and [computing](https://en.wikipedia.org/wiki/Computing). For example, [synchronous](https://en.wikipedia.org/wiki/Synchronous) bitstreams are carried by [SONET](https://en.wikipedia.org/wiki/SONET), and [Transmission Control Protocol](https://en.wikipedia.org/wiki/Transmission_Control_Protocol) transports an [asynchronous](https://en.wikipedia.org/wiki/Asynchronous_communication) bytestream.





## Stream的方向

在使用stream来进行抽象的时候，我们可以考虑stream的方向：

- 源: 数据从何处流入
- 目的: 数据流向何处



## 特性

stream有着非常好的特性，这些优良的特性决定了它在computer science中的广泛应用。

### 结构的简单

stream的结构是非常简单的: 相邻关系，这就决定了它是线性的，这种结构是一个非常普遍的结构，在computer science中广泛存在。

### 有序性

stream中的元素默认是有序的。

### Computation的简单

stream结构的简单决定了对它进行computation是非常简单的。stream结构是discrete的，我们可以one-by-one地来对它计算，一种最最常见的方式就是iteration，关于此，参见工程discrete的`Relation-structure-computation\Computation\Iteration`章节，关于此，在维基百科[Stream (computing)](https://en.wikipedia.org/wiki/Stream_(computing))中也进行了详细地介绍。



## Application

### Stream-base IO

参见:

1) 工程Linux-OS的`Programming\IO\IO-流派\Stream`章节。

2) 工程programming-language的`C-family-language\C++\Library\Standard-library\IO-library`章节。

### Stream-oriented protocol

TCP就是典型的例子，参见工程Linux-OS的`Network\Theory\TCP`章节。



### Parallel computing

参见工程parallel-computing的`Model\Stream-model`章节。

#### Stream-based message/event processing system

参见工程parallel-computing的`Application\Message-processing-system\Stream-based-message-processing-system`章节。



### Dataflow programming paradigm

关于Dataflow programming paradigm，参见工程programming-language的`Theory\Programming-paradigm\Dataflow-programming`章节。

#### TensorFlow

TensorFlow就是典型的采用dataflow programming的，在TensorFlow的中，显然它的stream的单位是tensor。

## Programming model

在维基百科 [Stream (computing)](https://en.wikipedia.org/wiki/Stream_(computing))中，其实已经涉及了对stream的programming model的描述，从中可以看出，stream的programming model可以采用functional programming paradigm的思想。

在下面章节中，描述了相关内容:

1) 工程parallel-computing的`Programming-model`章节。