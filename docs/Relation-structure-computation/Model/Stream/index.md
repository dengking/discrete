# Stream

“stream”即“流”，stream是一种非常强大的**抽象结构**，在computer science中被广泛应用：计算机科学是关于**数据**的科学，我们的计算机系统处理着各种各样的**数据**，我们可以形象地将**数据**的传递看做是"**水流**"一般: **数据**就像**水流**的流转一般在**计算机系统**中进行流转。

> NOTE: 上面这段话中的**数据**、**计算机系统**都是抽象概念，它们可以指代很多内容

Stream可以用做描述**数据流**的**抽象结构**。



## 维基百科[Stream (computing)](https://en.wikipedia.org/wiki/Stream_(computing))

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a **stream** is a [sequence](https://en.wikipedia.org/wiki/Sequence) of [data elements](https://en.wikipedia.org/wiki/Data_element) made available over time. A stream can be thought of as items on a [conveyor belt](https://en.wikipedia.org/wiki/Conveyor_belt) (传送带) being processed one at a time rather than in large batches.

> TRANSLATION: 在计算机科学中，stream是随时间推移可用的一系列数据元素。 可以将stream视为传送带上的物品，一次一个地处理，而不是大批量处理。

**Streams** are processed differently from [batch data](https://en.wikipedia.org/wiki/Batch_processing) – normal functions cannot operate on streams as a whole(不能够整个的操作stream), as they have potentially **unlimited data**, and formally, streams are [*codata*](https://en.wikipedia.org/wiki/Codata_(computer_science)) (potentially unlimited), not data (which is finite). Functions that operate on a stream, producing another stream, are known as [filters](https://en.wikipedia.org/wiki/Filter_(software)), and can be connected in [pipelines](https://en.wikipedia.org/wiki/Pipeline_(computing)), analogously to [function composition](https://en.wikipedia.org/wiki/Function_composition_(computer_science)). Filters may operate on one item of a stream at a time, or may base an item of output on multiple items of input, such as a [moving average](https://en.wikipedia.org/wiki/Moving_average).



### Examples

The term "stream" is used in a number of similar ways:

- "Stream editing", as with [sed](https://en.wikipedia.org/wiki/Sed), [awk](https://en.wikipedia.org/wiki/Awk), and [perl](https://en.wikipedia.org/wiki/Perl). Stream editing processes a file or files, in-place, without having to load the file(s) into a user interface. One example of such use is to do a search and replace on all the files in a directory, from the command line.
- On [Unix](https://en.wikipedia.org/wiki/Unix) and related systems based on the [C language](https://en.wikipedia.org/wiki/C_(programming_language)), a stream is a source or [sink](https://en.wikipedia.org/wiki/Sink_(computing)) of data, usually individual bytes or [characters](https://en.wikipedia.org/wiki/Character_(computing)). Streams are an abstraction used when reading or writing files, or communicating over [network sockets](https://en.wikipedia.org/wiki/Network_socket). The **standard streams** are three streams made available to all programs.
- I/O devices can be interpreted as **streams**, as they produce or consume potentially unlimited data over time.
- In [object-oriented programming](https://en.wikipedia.org/wiki/Object-oriented_programming), input streams are generally implemented as [iterators](https://en.wikipedia.org/wiki/Iterator).
- In the [Scheme language](https://en.wikipedia.org/wiki/Scheme_(programming_language)) and some others, a stream is a [lazily evaluated](https://en.wikipedia.org/wiki/Lazy_evaluation) or *delayed* sequence of data elements. A stream can be used similarly to a list, but later elements are only calculated when needed. Streams can therefore represent infinite [sequences](https://en.wikipedia.org/wiki/Sequence) and [series](https://en.wikipedia.org/wiki/Series_(mathematics)). 
- In the [Smalltalk](https://en.wikipedia.org/wiki/Smalltalk) [standard library](https://en.wikipedia.org/wiki/Standard_library) and in other [programming languages](https://en.wikipedia.org/wiki/Programming_language) as well, a stream is an **external iterator**. As in Scheme, streams can represent finite or infinite sequences.
- **Stream processing** — in [parallel processing](https://en.wikipedia.org/wiki/Parallel_computing), especially in graphic processing, the term stream is applied to [hardware](https://en.wikipedia.org/wiki/Computer_hardware) as well as [software](https://en.wikipedia.org/wiki/Software). There it defines the quasi-continuous flow of data that is processed in a [dataflow programming](https://en.wikipedia.org/wiki/Dataflow_programming) language as soon as the [program state](https://en.wikipedia.org/wiki/Program_state) meets the starting condition of the stream.

### Applications

Streams can be used as the underlying data type for [channels](https://en.wikipedia.org/wiki/Channel_(programming)) in [interprocess communication](https://en.wikipedia.org/wiki/Interprocess_communication).

### [Other uses](https://en.wikipedia.org/wiki/Stream_(computing)#Other_uses)

## Stream的单位

[Bitstream](https://en.wikipedia.org/wiki/Bitstream)

## Stream的方向

在使用stream来进行抽象的时候，我们可以考虑stream的方向：

- 源: 数据从何处流入
- 目的: 数据流向何处

## 特性

它有着非常好的特性:

1) stream的结构是非常简单的: 

相邻关系，这就决定了它是线性的，这种结构是一个非常普遍的结构，在computer science中广泛存在。

2) computation的简单:

stream结构的简单决定了对它进行computation是非常简单的。

stream模型的另外一个非常重要的特性是它是discrete的，所以我们可以one-by-one地来对它计算，一种最最常见的方式就是iteration，关于此，参见工程[discrete-math](https://dengking.github.io/discrete-math/)的iteration章节，关于此，在维基百科[Stream (computing)](https://en.wikipedia.org/wiki/Stream_(computing))中也进行了详细地介绍。

IO即输入、输出，就是典型的可以使用stream来进行描述的。





Stream的上述特性决定了它在computer science中的广泛应用。

## Application

### Stream-base IO

stream模型抽象了数据的流动（流出、流入），stream模型可以抽象 input/output device，它能够抽象file、network device、custom adaptor device，所以使用stream模型构建的程序，允许我们实现使用抽象的stream来完成对多种device的IO。这个思想就是[abstraction](https://dengking.github.io/Post/Abstraction/Abstraction/)思想。

stream模型基本上统治了IO领域：

- 在[Everything-is-a-file](../../../Philosophy/Everything-is-a-file/Everything-is-a-file.md)中，我们其实已经探讨了linux的file descriptor其实代表的就是一个stream，它使用的就是stream模型，并且维基百科[Everything is a file](https://en.wikipedia.org/wiki/Everything_is_a_file)描述的思想和上一段中的思想一致。
- C++的[Input/output library](Input/output library)就是基于stream模型创建的。

### Stream-oriented protocol



