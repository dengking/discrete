# Flooding algorithm

一. 在 labuladong [Flood Fill 算法详解](https://mp.weixin.qq.com/s/Y7snQIraCC6PRhj9ZSnlzw) 中，发现了这个算法，第一感觉就是 "探针"、"试探": 给一个/多个seed、probe，按照connectivity，沿着topology，找到它的所有的connected component。

对于seed，在 labuladong [Flood Fill 算法详解](https://mp.weixin.qq.com/s/Y7snQIraCC6PRhj9ZSnlzw) 中给出了扫雷、开心消消乐的例子:

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



二. "泛洪"，这翻译是非常形象的、"浸染"、flood水流流过相邻区域

三. [lattice graph](https://en.wikipedia.org/wiki/Lattice_graph) 

四、watershed algorithm(分水岭算法)

wikipedia [Watershed (image processing)](https://en.wikipedia.org/wiki/Watershed_(image_processing))



## wikipedia [Flooding algorithm](https://en.wikipedia.org/wiki/Flooding_algorithm)

A **flooding algorithm** is an [algorithm](https://en.wikipedia.org/wiki/Algorithm) for distributing material to every part of a [graph](https://en.wikipedia.org/wiki/Graph_(discrete_mathematics)). The name derives from the concept of inundation by a [flood](https://en.wikipedia.org/wiki/Flood).

> NOTE:
>
> 一. 翻译如下: "泛洪算法是一种将材料分布到图的每个部分的算法。这个名字来源于洪水泛滥的概念"

Flooding algorithms are used in [computer networking](https://en.wikipedia.org/wiki/Flooding_(computer_networking)) and [graphics](https://en.wikipedia.org/wiki/Flood_fill). **Flooding algorithms** are also useful for solving many mathematical problems, including [maze](https://en.wikipedia.org/wiki/Maze) problems and many problems in [graph theory](https://en.wikipedia.org/wiki/Graph_theory).

> NOTE:
>
> 一. "maze"即"迷宫"

Different flooding algorithms can be applied for different problems, and run with different [time complexities](https://en.wikipedia.org/wiki/Time_complexities): 

一. [flood fill](https://en.wikipedia.org/wiki/Flood_fill) algorithm 

For example, the [flood fill](https://en.wikipedia.org/wiki/Flood_fill) algorithm is a simple but relatively robust algorithm that works for intricate(复杂的) geometries and can determine which part of the (target) area that is [connected](https://en.wikipedia.org/wiki/Glossary_of_graph_theory#Connectivity) to a given (source) node in a multi-dimensional [array](https://en.wikipedia.org/wiki/Array_data_structure), and is trivially generalized to arbitrary graph structures.

> NOTE:
>
> 一. 翻译如下: "例如，洪水填充算法是一种简单但相对健壮的算法，适用于复杂的几何形状，可以确定(目标)区域的哪一部分与多维数组中的给定(源)节点相连，并且可以简单地推广到任意图结构。"
>
> "which part of the (target) area that is [connected](https://en.wikipedia.org/wiki/Glossary_of_graph_theory#Connectivity) to a given (source) node in a multi-dimensional [array](https://en.wikipedia.org/wiki/Array_data_structure)" 其实就是 "connected-component"
>
> 上面这段话中的 "multi-dimensional [array](https://en.wikipedia.org/wiki/Array_data_structure)"，显然是一种表示 geometry 的方式，类似于 [lattice graph](https://en.wikipedia.org/wiki/Lattice_graph) 。  

二. [jump flooding algorithm](https://en.wikipedia.org/wiki/Jump_flooding_algorithm) 

If there instead are several **source nodes**, there are no obstructions(障碍物) in the geometry represented in the multi-dimensional array, and one wishes to segment the area based on which of the **source nodes** the target nodes are closest to, while the flood fill algorithm can still be used, the [jump flooding algorithm](https://en.wikipedia.org/wiki/Jump_flooding_algorithm) is potentially much faster as it has a lower time complexity. Unlike the **flood fill algorithm**, however, the jump flooding algorithm cannot trivially be generalized to unstructured graphs.



### See also

[Category](https://en.wikipedia.org/wiki/Help:Category): [Flooding algorithms](https://en.wikipedia.org/wiki/Category:Flooding_algorithms)



## Flood fill 泛洪算法



### wikipedia [Flood fill](https://en.wikipedia.org/wiki/Flood_fill)

**Flood fill**, also called **seed fill**, is a [flooding algorithm](https://en.wikipedia.org/wiki/Flooding_algorithm) that determines and alters the area [connected](https://en.wikipedia.org/wiki/Glossary_of_graph_theory#Connectivity) to a given node in a multi-dimensional [array](https://en.wikipedia.org/wiki/Array_data_structure) with some matching attribute. It is used in the "bucket" fill tool of [paint programs](https://en.wikipedia.org/wiki/Paint_program) to fill connected, similarly-colored areas with a different color, and in games such as [Go](https://en.wikipedia.org/wiki/Go_(game)) and [Minesweeper](https://en.wikipedia.org/wiki/Minesweeper_(video_game)) for determining which pieces are cleared. A variant called **boundary fill** uses the same algorithms but is defined as the area [connected](https://en.wikipedia.org/wiki/Glossary_of_graph_theory#Connectivity) to a given node that does not have a particular attribute.[[1\]](https://en.wikipedia.org/wiki/Flood_fill#cite_note-79Smith-1)



## Jump flooding algorithm



### wikipedia [Jump flooding algorithm](https://en.wikipedia.org/wiki/Jump_flooding_algorithm)

The **jump flooding algorithm** (**JFA**) is a [flooding algorithm](https://en.wikipedia.org/wiki/Flooding_algorithm) used in the construction of [Voronoi diagrams](https://en.wikipedia.org/wiki/Voronoi_diagram) and [distance transforms](https://en.wikipedia.org/wiki/Distance_transform). The JFA was introduced at an [ACM](https://en.wikipedia.org/wiki/Association_for_Computing_Machinery) symposium in 2006.

The JFA has desirable attributes in [GPU](https://en.wikipedia.org/wiki/GPU) computation, notably constant-time performance. However, it is only an approximate algorithm and does not always compute the correct result for every pixel, although in practice errors are few and the magnitude of errors is generally small.

#### Implementation

The JFA original formulation is simple to implement.

Take an $N\times N$ grid of pixels[[2\]](https://en.wikipedia.org/wiki/Jump_flooding_algorithm#cite_note-2) (like an image or texture). All pixels will start with an "undefined" color unless it is a uniquely-colored "seed" pixel. As the JFA progresses, each undefined pixel will be filled with a color corresponding to that of a **seed pixel**.

For each step size ${\displaystyle k\in \{{\frac {N}{2}},{\frac {N}{4}},\dots ,1\}}$, run one iteration of the JFA:

​    Iterate over every pixel $p$ at $(x,y)$.

​        For each neighbor $q$ at ${\displaystyle (x+i,y+j)}$ where ${\displaystyle i,j\in \{-k,0,k\}}$:

​            if $p$ is undefined and $q$  is colored, change $p$'s color to $q$'s

​            if $p$ is colored and $q$ is colored, if ${\displaystyle dist(p,s)>dist(p,s')}$ where $s$ and $s'$ are the **seed pixels** for $p$ and $q$, respectively, then change $p$'s color to $q$'s.



Note that pixels may change color more than once in each step, and that the JFA does not specify a method for resolving cases where distances are equal, therefore the last-checked pixel's color is used above.

The JFA finishes after evaluating the last pixel in the last step size. Regardless of the content of the initial data, the innermost loop runs a total of ${\displaystyle 9\log _{2}(N)}$ times over each pixel, for an overall computational complexity of ${\displaystyle O(N^{2}\log _{2}(N))}$



#### Uses

The jump flooding algorithm and its variants may be used for:

1. calculating [Voronoi maps](https://en.wikipedia.org/wiki/Voronoi_map)[[1\]](https://en.wikipedia.org/wiki/Jump_flooding_algorithm#cite_note-Rong2006-1)[[3\]](https://en.wikipedia.org/wiki/Jump_flooding_algorithm#cite_note-Rong2007-3) 

2. [centroidal Voronoi tessellations](https://en.wikipedia.org/wiki/Centroidal_Voronoi_tessellation) (CVT),[[4\]](https://en.wikipedia.org/wiki/Jump_flooding_algorithm#cite_note-4) 

3. generating [distance fields](https://en.wikipedia.org/wiki/Distance_field),[[5\]](https://en.wikipedia.org/wiki/Jump_flooding_algorithm#cite_note-5)[*[how?](https://en.wikipedia.org/wiki/Wikipedia:Please_clarify)*] 

4. [point-cloud](https://en.wikipedia.org/wiki/Point-cloud) rendering,[[6\]](https://en.wikipedia.org/wiki/Jump_flooding_algorithm#cite_note-6)

5. [feature matching](https://en.wikipedia.org/wiki/Feature_matching),[[7\]](https://en.wikipedia.org/wiki/Jump_flooding_algorithm#cite_note-7) 

6. the computation of [power diagrams](https://en.wikipedia.org/wiki/Power_diagram),[[8\]](https://en.wikipedia.org/wiki/Jump_flooding_algorithm#cite_note-8) 

7. [soft shadow](https://en.wikipedia.org/wiki/Soft_shadows) rendering.[[9\]](https://en.wikipedia.org/wiki/Jump_flooding_algorithm#cite_note-9) 

8. The [grand strategy game](https://en.wikipedia.org/wiki/Grand_strategy_wargame) developer [Paradox Interactive](https://en.wikipedia.org/wiki/Paradox_Interactive) uses the JFA to render borders between countries and provinces.



## LeetCode

### [LeetCode-733. 图像渲染-简单](https://leetcode.cn/problems/flood-fill/) 

英文原题: [LeetCode-733. Flood Fill](https://leetcode.com/problems/flood-fill/) 
