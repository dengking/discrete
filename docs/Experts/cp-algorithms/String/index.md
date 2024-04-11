# [String Processing](https://cp-algorithms.com/string/string-hashing.html)



## [String Hashing](https://cp-algorithms.com/string/string-hashing.html)

We want to solve the problem of comparing strings efficiently. 

> NOTE:
>
> 一、如果有**多个**字符串需要进行**多次**、**重复**的比较，那么string hashing的方式将非常具有优势，它相当于一个预处理($O(n)$)，将字符串转换为integer，那么后续基于integer的comparison的complexity就是$O(1)$​。
>
> string hashing也展示了合理的预处理为后续的计算带来的非常巨大的提升。



```
string---(hash functin)--->hash
```



### Hash collision

> NOTE:
>
> 一、既然使用hashing，那么就不可避免地需要考虑 [Hash collision](https://en.wikipedia.org/wiki/Hash_collision)  ，即不同的string，它们的hash可能相同；由于 [Hash function](https://en.wikipedia.org/wiki/Hash_function) 的 [Deterministic](https://en.wikipedia.org/wiki/Hash_function#Deterministic) 特性，可以保证相同的string，它们的hash肯定相同；因此:
>
> 1、如果hash不同，那么strings肯定不同
>
> 2、如果hahs相同，strings可能不同

The following condition has to hold: if two strings  $s$  and  $t$  are equal ( $s = t$ ), then also their hashes have to be equal ($\text{hash}(s) = \text{hash}(t)$​​ ). Otherwise, we will not be able to compare strings.

> NOTE:
>
> 一、 [Hash function](https://en.wikipedia.org/wiki/Hash_function) 的 [Deterministic](https://en.wikipedia.org/wiki/Hash_function#Deterministic) 特性

Notice, the opposite direction doesn't have to hold. If the hashes are equal ( $\text{hash}(s) = \text{hash}(t)$ ), then the strings do not necessarily have to be equal. The reason why the opposite direction doesn't have to hold, is because there are exponentially many strings. If we only want this hash function to distinguish between all strings consisting of lowercase characters of length smaller than 15, then already the hash wouldn't fit into a 64-bit integer (e.g. unsigned long long) any more, because there are so many of them. And of course, we don't want to compare arbitrary long integers, because this will also have the complexity  
$O(n)$​ .

> NOTE:
>
> 一、 [Hash collision](https://en.wikipedia.org/wiki/Hash_collision)  

So usually we want the hash function to map strings onto numbers of a fixed range  $[0, m)$ , then comparing strings is just a comparison of two integers with a fixed length. And of course, we want  $\text{hash}(s) \neq \text{hash}(t)$  to be very likely if  $s \neq t$ .

> NOTE:
>
> 一、最后一段话的意思其实就是降低 [Hash collision](https://en.wikipedia.org/wiki/Hash_collision)  的概率
>
> 二、tradeoff

That's the important part that you have to keep in mind. Using hashing will not be 100% deterministically correct, because two complete different strings might have the same hash (the hashes collide). However, in a wide majority of tasks, this can be safely ignored as the probability of the hashes of two different strings colliding is still very small. And we will discuss some techniques in this article how to keep the probability of collisions very low.

> NOTE:
>
> 一、直接忽视小概率事件是否是正确的？



### Polynomial rolling hash function