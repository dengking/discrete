# [随机增量法](https://oi-wiki.org/geometry/random-incremental/)

随机增量算法是计算几何的一个重要算法，它对理论知识要求不高，算法时间复杂度低，应用范围广大。

增量法 (Incremental Algorithm) 的思想与第一数学归纳法类似，它的本质是将一个问题化为规模刚好小一层的子问题。解决子问题后加入当前的对象。写成递归式是：

$$
T(n)=T(n-1)+g(n)
$$
 

增量法形式简洁，可以应用于许多的几何题目中。

增量法往往结合随机化，可以避免最坏情况的出现。



## 最小圆覆盖问题

> NOTE:
>
> 1、https://en.wikipedia.org/wiki/Smallest-circle_problem#:~:text=The%20smallest%2Dcircle%20problem%20(also,points%20in%20the%20Euclidean%20plane.
>
> 2、https://www.cs.princeton.edu/courses/archive/spr09/cos226/checklist/circle.html
>
> 3、http://www.doc88.com/p-007257893177.html
>
> 4、https://www.luogu.com.cn/problem/P1742
>
> 5、https://wenku.baidu.com/view/162699d63186bceb19e8bbe6.html?_wkts_=1688992891211