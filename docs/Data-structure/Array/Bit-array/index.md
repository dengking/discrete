# [Bit array](https://en.wikipedia.org/wiki/Bit_array)

A **bit array** (also known as **bit map**, **bit set**, **bit string**, or **bit vector**) is an [array data structure](https://en.wikipedia.org/wiki/Array_data_structure) that compactly stores [bits](https://en.wikipedia.org/wiki/Bit). It can be used to implement a simple [set data structure](https://en.wikipedia.org/wiki/Set_data_structure). A bit array is effective at exploiting bit-level parallelism in hardware to perform operations quickly. A typical bit array stores *kw* bits, where *w* is the number of bits in the unit of storage, such as a [byte](https://en.wikipedia.org/wiki/Byte) or [word](https://en.wikipedia.org/wiki/Word_(computer_architecture)), and *k* is some nonnegative integer. If *w* does not divide the number of bits to be stored, some space is wasted due to [internal fragmentation](https://en.wikipedia.org/wiki/Fragmentation_(computing)).

> NOTE: 有 如下问题：
> - 如何使用binary literal来初始化bit array？
> - 如何index bit array？
> - 使用什么类型来表示bit array？

## Definition

A bit array is a mapping from some domain (almost always a range of integers) to values in the set {0, 1}. The values can be interpreted as dark/light, absent/present, locked/unlocked, valid/invalid, et cetera. The point is that there are only two possible values, so they can be stored in one bit. As with other arrays, the access to a **single bit** can be managed by applying an **index** to the **array**. Assuming its size (or length) to be *n* bits, the array can be used to specify a subset of the domain (e.g. {0, 1, 2, ..., *n*−1}), where a 1-bit indicates the presence and a 0-bit the absence of a number in the set. This set data structure uses about *n*/*w* words of space, where *w* is the number of bits in each [machine word](https://en.wikipedia.org/wiki/Word_(computer_architecture)). Whether the least significant bit (of the word) or the most significant bit indicates the smallest-index number is largely irrelevant, but the former tends to be preferred (on [little-endian](https://en.wikipedia.org/wiki/Endianness) machines).

## Basic operations

Although most machines are not able to address individual bits in memory, nor have instructions to manipulate single bits, each bit in a word can be singled out and manipulated using [bitwise operations](https://en.wikipedia.org/wiki/Bitwise_operation). In particular:

- OR can be used to set a bit to one: 11101010 OR 00000100 = 11101110
- AND can be used to set a bit to zero: 11101010 AND 11111101 = 11101000
- AND together with zero-testing can be used to determine if a bit is set:

11101010 AND 00000001 = 00000000 = 0

11101010 AND 00000010 = 00000010 ≠ 0

- XOR can be used to invert or toggle a bit:

11101010 XOR 00000100 = 11101110

11101110 XOR 00000100 = 11101010

- NOT can be used to invert all bits.

NOT 10110010 = 01001101

To obtain the [bit mask](https://en.wikipedia.org/wiki/Mask_(computing)) needed for these operations, we can use a [bit shift](https://en.wikipedia.org/wiki/Bitwise_operation#Bit_shifts) operator to shift the number 1 to the left by the appropriate number of places, as well as [bitwise negation](https://en.wikipedia.org/wiki/Bitwise_negation) if necessary.

Given two bit arrays of the same size representing sets, we can compute their [union](https://en.wikipedia.org/wiki/Union_(set_theory)), [intersection](https://en.wikipedia.org/wiki/Intersection_(set_theory)), and [set-theoretic difference](https://en.wikipedia.org/wiki/Complement_(set_theory)) using *n*/*w* simple bit operations each (2*n*/*w* for difference), as well as the [complement](https://en.wikipedia.org/wiki/Signed_number_representations#Ones'_complement) of either:

```
for i from 0 to n/w-1
    complement_a[i] := not a[i]
    union[i]        := a[i] or b[i]
    intersection[i] := a[i] and b[i]
    difference[i]   := a[i] and (not b[i])
```

> NOTE: 上述算法是一次操作一个byte，而不是bit

If we wish to iterate through the bits of a bit array, we can do this efficiently using a doubly nested loop that loops through each word, one at a time. Only *n*/*w* memory accesses are required:

```
for i from 0 to n/w-1
    index := 0    // if needed
    word := a[i]
    for b from 0 to w-1
        value := word and 1 ≠ 0
        word := word shift right 1
        // do something with value
        index := index + 1    // if needed
```

Both of these code samples exhibit ideal [locality of reference](https://en.wikipedia.org/wiki/Locality_of_reference), which will subsequently receive large performance boost from a data cache. If a cache line is *k* words, only about *n*/*wk* cache misses will occur.



## More complex operations

As with [character strings](https://en.wikipedia.org/wiki/String_(computer_science)) it is straightforward to define *length*, *substring*, [lexicographical](https://en.wikipedia.org/wiki/Lexicographical_order) *compare*, *concatenation*, *reverse* operations. The implementation of some of these operations is sensitive to [endianness](https://en.wikipedia.org/wiki/Endianness).

### Population / Hamming weight

If we wish to find the number of 1 bits in a bit array, sometimes called the population count or Hamming weight, there are efficient branch-free algorithms that can compute the number of bits in a word using a series of simple bit operations. We simply run such an algorithm on each word and keep a running total. Counting zeros is similar. See the [Hamming weight](https://en.wikipedia.org/wiki/Hamming_weight) article for examples of an efficient implementation.

### Inversion

Vertical flipping of a one-bit-per-pixel image, or some FFT algorithms, requires flipping the bits of individual words (so `b31 b30 ... b0` becomes `b0 ... b30 b31`). When this operation is not available on the processor, it's still possible to proceed by successive passes, in this example on 32 bits:

```
exchange two 16bit halfwords
exchange bytes by pairs (0xddccbbaa -> 0xccddaabb)
...
swap bits by pairs
swap bits (b31 b30 ... b1 b0 -> b30 b31 ... b0 b1)

The last operation can be written ((x&0x55555555)<<1) | (x&0xaaaaaaaa)>>1)).
```

### Find first one

The [find first set](https://en.wikipedia.org/wiki/Find_first_set) or *find first one* operation identifies the index or position of the 1-bit with the smallest index in an array, and has widespread hardware support (for arrays not larger than a word) and efficient algorithms for its computation. When a [priority queue](https://en.wikipedia.org/wiki/Priority_queue) is stored in a bit array, find first one can be used to identify the highest priority element in the queue. To expand a word-size *find first one* to longer arrays, one can find the first nonzero word and then run *find first one* on that word. The related operations *find first zero*, *count leading zeros*, *count leading ones*, *count trailing zeros*, *count trailing ones*, and *log base 2* (see [find first set](https://en.wikipedia.org/wiki/Find_first_set)) can also be extended to a **bit array** in a straightforward manner.



## 开源库

[BitArray](https://github.com/noporpoise/BitArray)