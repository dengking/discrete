# Fisher–Yates shuffle

在 labuladong [洗牌算法详解：你会排序，但你会打乱吗？](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484503&idx=1&sn=e30ef74eb16ad385c16681cd6dfe15cf&chksm=9bd7fa5faca07349c6877bc69f9a27e13585f2c5ed2237ad37ac5b272611039391acc1dcd33d&scene=21#wechat_redirect) 中介绍的算法其实就是 Fisher–Yates shuffle algorithm，在  labuladong [洗牌算法详解：你会排序，但你会打乱吗？](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484503&idx=1&sn=e30ef74eb16ad385c16681cd6dfe15cf&chksm=9bd7fa5faca07349c6877bc69f9a27e13585f2c5ed2237ad37ac5b272611039391acc1dcd33d&scene=21#wechat_redirect) 中，将这种算法称之为"随机转换算法"，其实更加的反映了这个算法的运算过程。

## wikipedia [Fisher–Yates shuffle](https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle)

The **Fisher–Yates shuffle** is an [algorithm](https://en.wikipedia.org/wiki/Algorithm) for generating a [random permutation](https://en.wikipedia.org/wiki/Random_permutation) of a finite [sequence](https://en.wikipedia.org/wiki/Sequence)—in plain terms, the algorithm [shuffles](https://en.wikipedia.org/wiki/Shuffling) the sequence. The algorithm effectively puts all the elements into a hat; it continually determines the next element by randomly drawing an element from the hat until no elements remain. The algorithm produces an [unbiased](https://en.wikipedia.org/wiki/Biased_sample) permutation: every permutation is equally likely. The modern version of the algorithm is efficient: it takes time proportional to the number of items being shuffled and shuffles them [in place](https://en.wikipedia.org/wiki/In-place_algorithm).

### The modern algorithm

```pseudocode
-- To shuffle an array a of n elements (indices 0..n-1):
for i from n−1 downto 1 do
     j ← random integer such that 0 ≤ j ≤ i
     exchange a[j] and a[i]
```



```pseudocode
-- To shuffle an array a of n elements (indices 0..n-1):
for i from 0 to n−2 do
     j ← random integer such that i ≤ j < n
     exchange a[i] and a[j]
```

