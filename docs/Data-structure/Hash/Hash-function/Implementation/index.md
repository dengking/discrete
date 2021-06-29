# Implementation of hash function

非常多的programming language中都支持Customizing hash，比如

- python `object.__hash__`(*self*)[¶](https://docs.python.org/3/reference/datamodel.html#object.__hash__)
- java [hashCode](https://docs.oracle.com/javase/7/docs/api/java/lang/Object.html)
- c# [Object.GetHashCode Method](https://docs.microsoft.com/en-us/dotnet/api/system.object.gethashcode?view=netframework-4.8)

所以了解一下实现hash function的一些细节是比较重要的。

## stackexchange [Why is it best to use a prime number as a mod in a hashing function?](https://cs.stackexchange.com/questions/11029/why-is-it-best-to-use-a-prime-number-as-a-mod-in-a-hashing-function)

[A](https://cs.stackexchange.com/a/64191)

> NOTE: “bucket”是[hash table](https://en.wikipedia.org/wiki/Hash_table)中的术语，其实它就是slot

Consider the set of keys `K={0,1,...,100}` and a hash table where the number of buckets is `m=12`. Since 3 is a factor of 12, the keys that are multiples of 3 will be hashed to buckets that are multiples of 3:

- Keys {0,12,24,36,...} will be hashed to bucket 0.
- Keys {3,15,27,39,...} will be hashed to bucket 3.
- Keys {6,18,30,42,...} will be hashed to bucket 6.
- Keys {9,21,33,45,...} will be hashed to bucket 9.

If `K` is uniformly distributed (i.e., every key in `K` is equally likely to occur), then the choice of `m` is not so critical. But, what happens if `K` is not uniformly distributed? Imagine that the keys that are most likely to occur are the multiples of 3. In this case, all of the buckets that are not multiples of 3 will be empty with high probability (which is really bad in terms of hash table performance).

This situation is more common that it may seem. Imagine, for instance, that you are keeping track of objects based on where they are stored in memory. If your computer's **word size** is four bytes, then you will be hashing keys that are multiples of 4. Needless to say that choosing `m` to be a multiple of 4 would be a terrible choice: you would have `3m/4` buckets completely empty, and all of your keys colliding in the remaining `m/4` buckets.

> NOTE:
>
> key：`0=4*0`、`4=4*1`、`8=4*2`、`12=4*3`、`16=4*4`、`20=4*5`、`24=4*6`、`28=4*7`
>
> bracket：`12=4*3`
>
> | key  | bracket |
> | ---- | ------- |
> | 0    | 0       |
> | 4    | 1       |
> | 8    | 2       |
> | 12   | 0       |
> | 16   | 1       |
> | 20   | 2       |
> | 24   | 3       |
>
> 也就是说提供了12个bracket，但是实际上只会有`12/4=3`个bracket会被使用，剩余的`12-3=(12*4)/4 - 12/4= 12 * 3 /4`个bracket不会被使用，这就是上述的`3m/4` buckets completely empty。



In general:

> Every key in K that shares a common factor with the number of buckets m will be hashed to a bucket that is a multiple of this factor.

Therefore, to minimize collisions, it is important to reduce the number of common factors between m and the elements of K. How can this be achieved? By choosing m to be a number that has very few factors: a **prime number**.

> ***SUMMARY*** : 上述验证了在[综述](#综述)中提出的：
>
> 在设计一个hash function的时候，需要考虑它的[domain](https://en.wikipedia.org/wiki/Domain_of_a_function)中数据的特征

## [Why is XOR the default way to combine hashes?](https://stackoverflow.com/questions/5889238/why-is-xor-the-default-way-to-combine-hashes)

[A](https://stackoverflow.com/a/5889254)

Assuming uniformly random (1-bit) inputs, the AND function output probability distribution is 75% `0` and 25% `1`. Conversely, OR is 25% `0` and 75% `1`.

The XOR function is 50% `0` and 50% `1`, therefore it is good for combining uniform probability distributions.

This can be seen by writing out truth tables:

```
 a | b | a AND b
---+---+--------
 0 | 0 |    0
 0 | 1 |    0
 1 | 0 |    0
 1 | 1 |    1

 a | b | a OR b
---+---+--------
 0 | 0 |    0
 0 | 1 |    1
 1 | 0 |    1
 1 | 1 |    1

 a | b | a XOR b
---+---+--------
 0 | 0 |    0
 0 | 1 |    1
 1 | 0 |    1
 1 | 1 |    0
```

Exercise: How many logical functions of two 1-bit inputs `a` and `b` have this uniform output distribution? Why is XOR the most suitable for the purpose stated in your question?



## [What is the best algorithm for overriding GetHashCode?](https://stackoverflow.com/questions/263400/what-is-the-best-algorithm-for-overriding-gethashcode)



## [Writing a hash function in Java: a practical guide to implementing `hashCode()`](https://www.javamex.com/tutorials/collections/hash_function_guidelines.shtml)







## CPython [`hashlib`](https://docs.python.org/3/library/hashlib.html#module-hashlib) 



## redis hash

https://github.com/antirez/redis/blob/unstable/src/sha1.h

https://github.com/antirez/redis/blob/unstable/src/sha256.h

https://github.com/antirez/redis/blob/unstable/src/siphash.c