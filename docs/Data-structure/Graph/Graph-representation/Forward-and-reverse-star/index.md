# Forward star and reverse star

一、首先需要搞清楚的是"star"的含义:

1、[wikipedia-Star (graph theory)](https://en.wikipedia.org/wiki/Star_(graph_theory)) 

> [![img](https://upload.wikimedia.org/wikipedia/commons/thumb/4/49/Star_network_7.svg/180px-Star_network_7.svg.png)](https://en.wikipedia.org/wiki/File:Star_network_7.svg)
>
> The star $S_7$. (Some authors index this as $S_8$.)



二、

[youtube-UNSW CVEN4402 Network Representation](https://www.youtube.com/watch?v=MRbqpNBUN9w) 

三、Forward star VS Linked forward star(链式前向星)

a、一个点关联多条边的要求 ( [wikipedia-Star (graph theory)](https://en.wikipedia.org/wiki/Star_(graph_theory)) ):

1、Forward star(前向星): 通过排序的方式

2、Linked forward star(链式前向星): 通过next index将属于同一个节点的多条边给串联起来，非常巧妙，这种方式非常类似于union- find-set中的link index



## Linked forward star(链式前向星)

"linked forward star"即 "链式前向星"，这是我在阅读 [jianshu-背包问题九讲 超全归纳](https://www.jianshu.com/p/830de6df0207) 时发现的，后来百度，都指向了这篇文章: [malash-链式前向星及其简单应用](https://malash.me/200910/linked-forward-star/)，下面是我发现的一些关于此的比较好的素材:

1、[zhihu-链式前向星的发明者是谁？](https://www.zhihu.com/question/306076815)

2、[baike-链式前向星](https://baike.baidu.com/item/%E9%93%BE%E5%BC%8F%E5%89%8D%E5%90%91%E6%98%9F/5970605?fr=ge_ala)

3、[jianshu-前向星与链式前向星](https://www.jianshu.com/p/107a645797a6)

4、[zhihu-如何评价前向星这种存图方式？](https://www.zhihu.com/question/59676094)