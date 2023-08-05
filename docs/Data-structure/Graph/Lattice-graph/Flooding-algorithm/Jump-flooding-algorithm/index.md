# Jump flooding algorithm



## wikipedia [Jump flooding algorithm](https://en.wikipedia.org/wiki/Jump_flooding_algorithm)

The **jump flooding algorithm** (**JFA**) is a [flooding algorithm](https://en.wikipedia.org/wiki/Flooding_algorithm) used in the construction of [Voronoi diagrams](https://en.wikipedia.org/wiki/Voronoi_diagram) and [distance transforms](https://en.wikipedia.org/wiki/Distance_transform). The JFA was introduced at an [ACM](https://en.wikipedia.org/wiki/Association_for_Computing_Machinery) symposium in 2006.

The JFA has desirable attributes in [GPU](https://en.wikipedia.org/wiki/GPU) computation, notably constant-time performance. However, it is only an approximate algorithm and does not always compute the correct result for every pixel, although in practice errors are few and the magnitude of errors is generally small.

### Implementation

The JFA original formulation is simple to implement.

Take an $N\times N$ grid of pixels[[2\]](https://en.wikipedia.org/wiki/Jump_flooding_algorithm#cite_note-2) (like an image or texture). All pixels will start with an "undefined" color unless it is a uniquely-colored "seed" pixel. As the JFA progresses, each undefined pixel will be filled with a color corresponding to that of a **seed pixel**.

For each step size ${\displaystyle k\in \{{\frac {N}{2}},{\frac {N}{4}},\dots ,1\}}$, run one iteration of the JFA:

​    Iterate over every pixel $p$ at $(x,y)$.

​        For each neighbor $q$ at ${\displaystyle (x+i,y+j)}$ where ${\displaystyle i,j\in \{-k,0,k\}}$:

​            if $p$ is undefined and $q$  is colored, change $p$'s color to $q$'s

​            if $p$ is colored and $q$ is colored, if ${\displaystyle dist(p,s)>dist(p,s')}$ where $s$ and $s'$ are the **seed pixels** for $p$ and $q$, respectively, then change $p$'s color to $q$'s.



Note that pixels may change color more than once in each step, and that the JFA does not specify a method for resolving cases where distances are equal, therefore the last-checked pixel's color is used above.

The JFA finishes after evaluating the last pixel in the last step size. Regardless of the content of the initial data, the innermost loop runs a total of ${\displaystyle 9\log _{2}(N)}$ times over each pixel, for an overall computational complexity of ${\displaystyle O(N^{2}\log _{2}(N))}$



### Uses

The jump flooding algorithm and its variants may be used for:

1、calculating [Voronoi maps](https://en.wikipedia.org/wiki/Voronoi_map)[[1\]](https://en.wikipedia.org/wiki/Jump_flooding_algorithm#cite_note-Rong2006-1)[[3\]](https://en.wikipedia.org/wiki/Jump_flooding_algorithm#cite_note-Rong2007-3) 

2、[centroidal Voronoi tessellations](https://en.wikipedia.org/wiki/Centroidal_Voronoi_tessellation) (CVT),[[4\]](https://en.wikipedia.org/wiki/Jump_flooding_algorithm#cite_note-4) 

3、generating [distance fields](https://en.wikipedia.org/wiki/Distance_field),[[5\]](https://en.wikipedia.org/wiki/Jump_flooding_algorithm#cite_note-5)[*[how?](https://en.wikipedia.org/wiki/Wikipedia:Please_clarify)*] 

4、[point-cloud](https://en.wikipedia.org/wiki/Point-cloud) rendering,[[6\]](https://en.wikipedia.org/wiki/Jump_flooding_algorithm#cite_note-6)

5、[feature matching](https://en.wikipedia.org/wiki/Feature_matching),[[7\]](https://en.wikipedia.org/wiki/Jump_flooding_algorithm#cite_note-7) 

6、the computation of [power diagrams](https://en.wikipedia.org/wiki/Power_diagram),[[8\]](https://en.wikipedia.org/wiki/Jump_flooding_algorithm#cite_note-8) 

7、[soft shadow](https://en.wikipedia.org/wiki/Soft_shadows) rendering.[[9\]](https://en.wikipedia.org/wiki/Jump_flooding_algorithm#cite_note-9) 

8、The [grand strategy game](https://en.wikipedia.org/wiki/Grand_strategy_wargame) developer [Paradox Interactive](https://en.wikipedia.org/wiki/Paradox_Interactive) uses the JFA to render borders between countries and provinces.