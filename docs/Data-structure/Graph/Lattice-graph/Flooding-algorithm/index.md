# Flooding algorithm

一、给一个/多个seed、probe，按照connectivity，沿着topology，找到它的所有的connected component。

过于seed，在 labuladong [Flood Fill 算法详解](https://mp.weixin.qq.com/s/Y7snQIraCC6PRhj9ZSnlzw) 中给出了扫雷、开心消消乐的例子:

> 这种算法思想还在许多其他地方有应用。比如说扫雷游戏，有时候你点一个方格，会一下子展开一片区域，这个展开过程，就是 FloodFill 算法实现的。
>
> 
>
> ![Image](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4nLjUb2ib1Ys4MdicUpkJTvM6MR9NKB3efdpdfChkMe0UE82QD1jIHt2Kcma3p510aKGicYcZd4icJpww/640?wx_fmt=png&wxfrom=5&wx_lazy=1&wx_co=1)
>
> 
>
> 类似的，像消消乐这类游戏，相同方块积累到一定数量，就全部消除，也是 FloodFill 算法的功劳。
>
> 
>
> ![Image](https://mmbiz.qpic.cn/mmbiz_jpg/map09icNxZ4nLjUb2ib1Ys4MdicUpkJTvM6fZicV5b8Y9qOWCvPoqubl0WGGu2hicnetibrGjVZicyTnUvWl713xl7cxw/640?wx_fmt=jpeg&wxfrom=5&wx_lazy=1&wx_co=1)



二、"泛洪"，这翻译是非常形象的、"浸染"、flood水流流过相邻区域

三、 [lattice graph](https://en.wikipedia.org/wiki/Lattice_graph) 

四、watershed algorithm(分水岭算法)

wikipedia [Watershed (image processing)](https://en.wikipedia.org/wiki/Watershed_(image_processing))



## wikipedia [Flooding algorithm](https://en.wikipedia.org/wiki/Flooding_algorithm)

A **flooding algorithm** is an [algorithm](https://en.wikipedia.org/wiki/Algorithm) for distributing material to every part of a [graph](https://en.wikipedia.org/wiki/Graph_(discrete_mathematics)). The name derives from the concept of inundation by a [flood](https://en.wikipedia.org/wiki/Flood).

> NOTE:
>
> 一、翻译如下: "泛洪算法是一种将材料分布到图的每个部分的算法。这个名字来源于洪水泛滥的概念"

Flooding algorithms are used in [computer networking](https://en.wikipedia.org/wiki/Flooding_(computer_networking)) and [graphics](https://en.wikipedia.org/wiki/Flood_fill). **Flooding algorithms** are also useful for solving many mathematical problems, including [maze](https://en.wikipedia.org/wiki/Maze) problems and many problems in [graph theory](https://en.wikipedia.org/wiki/Graph_theory).

> NOTE:
>
> 一、"maze"即"迷宫"

Different flooding algorithms can be applied for different problems, and run with different [time complexities](https://en.wikipedia.org/wiki/Time_complexities): 

一、[flood fill](https://en.wikipedia.org/wiki/Flood_fill) algorithm 

For example, the [flood fill](https://en.wikipedia.org/wiki/Flood_fill) algorithm is a simple but relatively robust algorithm that works for intricate(复杂的) geometries and can determine which part of the (target) area that is [connected](https://en.wikipedia.org/wiki/Glossary_of_graph_theory#Connectivity) to a given (source) node in a multi-dimensional [array](https://en.wikipedia.org/wiki/Array_data_structure), and is trivially generalized to arbitrary graph structures.

> NOTE:
>
> 一、翻译如下: "例如，洪水填充算法是一种简单但相对健壮的算法，适用于复杂的几何形状，可以确定(目标)区域的哪一部分与多维数组中的给定(源)节点相连，并且可以简单地推广到任意图结构。"
>
> "which part of the (target) area that is [connected](https://en.wikipedia.org/wiki/Glossary_of_graph_theory#Connectivity) to a given (source) node in a multi-dimensional [array](https://en.wikipedia.org/wiki/Array_data_structure)" 其实就是 "connected-component"
>
> 上面这段话中的 "multi-dimensional [array](https://en.wikipedia.org/wiki/Array_data_structure)"，显然是一种表示 geometry 的方式，类似于 [lattice graph](https://en.wikipedia.org/wiki/Lattice_graph) 。  

二、[jump flooding algorithm](https://en.wikipedia.org/wiki/Jump_flooding_algorithm) 

If there instead are several **source nodes**, there are no obstructions(障碍物) in the geometry represented in the multi-dimensional array, and one wishes to segment the area based on which of the **source nodes** the target nodes are closest to, while the flood fill algorithm can still be used, the [jump flooding algorithm](https://en.wikipedia.org/wiki/Jump_flooding_algorithm) is potentially much faster as it has a lower time complexity. Unlike the **flood fill algorithm**, however, the jump flooding algorithm cannot trivially be generalized to unstructured graphs.



### See also

[Category](https://en.wikipedia.org/wiki/Help:Category): [Flooding algorithms](https://en.wikipedia.org/wiki/Category:Flooding_algorithms)