# Permutation 



## wikipedia [Permutation](https://en.wikipedia.org/wiki/Permutation#Algorithms_to_generate_permutations)



## wikipedia [Permutations in computing](https://en.wikipedia.org/wiki/Permutation#Permutations_in_computing)





## Parity of a permutation

在wikipedia [Leibniz formula for determinants](https://en.wikipedia.org/wiki/Leibniz_formula_for_determinants) 中有如下内容:

> 
> $$
> \det(A)=\sum _{\tau \in S_{n}}\operatorname {sgn}(\tau )\prod _{i=1}^{n}a_{i,\,\tau (i)}=\sum _{\sigma \in S_{n}}\operatorname {sgn}(\sigma )\prod _{i=1}^{n}a_{\sigma (i),\,i}
> $$
> where ![\operatorname {sgn} ](https://wikimedia.org/api/rest_v1/media/math/render/svg/ec838dfd8a4a659b2877f93a6b53f22fc7777d07) is the [sign function](https://en.wikipedia.org/wiki/Even_and_odd_permutations) of [permutations](https://en.wikipedia.org/wiki/Permutation) in the [permutation group](https://en.wikipedia.org/wiki/Permutation_group) ![S_{n}](https://wikimedia.org/api/rest_v1/media/math/render/svg/9f049ac28d4ac8097b625f9d71c1f22b2ebd1bc4), which returns ![+1](https://wikimedia.org/api/rest_v1/media/math/render/svg/d04cf05c67d41d9f39dabf6a90722ce860a76958) and ![-1](https://wikimedia.org/api/rest_v1/media/math/render/svg/704fb0427140d054dd267925495e78164fee9aac) for [even and odd permutations](https://en.wikipedia.org/wiki/Even_and_odd_permutations), respectively.



### zhihu [全排列-逆序数-排列的奇偶性](https://zhuanlan.zhihu.com/p/405028673)



## 逆序数、反序数



### baike [反序数](https://baike.baidu.com/item/%E5%8F%8D%E5%BA%8F%E6%95%B0/8674073?fromtitle=%E9%80%86%E5%BA%8F%E6%95%B0&fromid=3334502&fr=aladdin)



### wikipedia [Inversion (discrete mathematics)](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics))



### Example



https://qb.zuoyebang.com/xfe-question/question/7d0dad98b783f55d32ba3a4924d08c90.html



> 跟标准列相反序数的总和
> 比如说
> 标准列是1 2 3 4 5
> 那么 5 4 3 2 1 的逆序数算法：
> 看第二个,4之前有一个5,在标准列中5在4的后面,所以记1个
> 类似的,第三个 3 之前有 4 5 都是在标准列中3的后面,所以记2个
> 同样的,2 之前有3个,1之前有4个
> 将这些数加起来就是逆序数=1+2+3+4=10
> 再举一个 2 4 3 1 5
> 4 之前有0个
> 3 之前有1个
> 1 之前有3个
> 5 之前有0个
> 所以逆序数就是1+3=4
> 这样能明白吗
