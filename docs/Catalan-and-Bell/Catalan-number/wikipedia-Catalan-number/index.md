# wikipedia [Catalan number](https://en.wikipedia.org/wiki/Catalan_number)

In [combinatorial mathematics](https://en.wikipedia.org/wiki/Combinatorics), the **Catalan numbers** form a [sequence](https://en.wikipedia.org/wiki/Sequence) of [natural numbers](https://en.wikipedia.org/wiki/Natural_number) that occur in various [counting problems](https://en.wikipedia.org/wiki/Enumeration), often involving [recursively](https://en.wikipedia.org/wiki/Recursion)-defined objects. They are named after the [Belgian](https://en.wikipedia.org/wiki/Belgium) [mathematician](https://en.wikipedia.org/wiki/Mathematician) [Eugène Charles Catalan](https://en.wikipedia.org/wiki/Eugène_Charles_Catalan) (1814–1894). 

 The *n*th Catalan number is given directly in terms of [binomial coefficients](https://en.wikipedia.org/wiki/Binomial_coefficient) by 

$$
{\displaystyle C_{n}={\frac {1}{n+1}}{2n \choose n}={\frac {(2n)!}{(n+1)!\,n!}}=\prod \limits _{k=2}^{n}{\frac {n+k}{k}}\qquad {\text{for }}n\geq 0.}
$$


> NOTE: 
>
> 注意是连乘，上式给出的是Catalan number的计算方式，但是在实际地解决问题过程中，我们更多的是使用Catalan number的递归表达式；

​	

![](Noncrossing_partitions_5.svg.png.webp)



 The $C_5 = 42$ [noncrossing partitions](https://en.wikipedia.org/wiki/Noncrossing_partition) of a 5-element set (below, the other 10 of the [52](https://en.wikipedia.org/wiki/Bell_number) [partitions](https://en.wikipedia.org/wiki/Partition_of_a_set)) 



## Properties

An alternative expression for $C_n$ is 

 $ C_{n}={2n \choose n}-{2n \choose n+1}={1 \over n+1}{2n \choose n}\quad {\text{ for }}n\geq 0, $ 

which is equivalent to the expression given above because $ {\tbinom {2n}{n+1}}={\tfrac {n}{n+1}}{\tbinom {2n}{n}} $. This shows that  $C_n$is an [integer](https://en.wikipedia.org/wiki/Integer), which is not immediately obvious from the first formula given. This expression forms the basis for a [proof of the correctness of the formula](https://en.wikipedia.org/wiki/Catalan_number#Second_proof). 

The Catalan numbers satisfy the [recurrence relations](https://en.wikipedia.org/wiki/Recurrence_relation)[[1\]](https://en.wikipedia.org/wiki/Catalan_number#cite_note-1) 

 $ C_{0}=1\quad {\text{and}}\quad C_{n+1}=\sum _{i=0}^{n}C_{i}\,C_{n-i}\quad {\text{for }}n\geq 0, $ 

> NOTE: 
>
> 一、为什么是$C_{i}$ 乘以$C_{n-i}$，而不是相加呢？如何来结和具体案例对这个问题进行分析？
>
> 1、结合"矩阵连乘"的例子来理解
>
> 2、需要以"divide and conquer-原问题 子问题"
>
>  在位置`i`初，断开，

 $ \sum _{i_{1}+\cdots +i_{m}=n,i_{1},\ldots ,i_{m}\geq 0}C_{i_{1}}\cdots C_{i_{m}}={\begin{cases}{\dfrac {m(n+1)(n+2)\cdots (n+m/2-1)}{2(n+m/2+2)(n+m/2+3)\cdots (n+m)}}C_{n+m/2},&m{\text{ even}}\\[5pt]{\dfrac {m(n+1)(n+2)\cdots (n+(m-1)/2)}{(n+(m+3)/2)(n+(m+3)/2+1)\cdots (n+m)}}C_{n+(m-1)/2},&m{\text{ odd,}}\end{cases}} $ 

 and 

 $ C_{0}=1\quad {\text{and}}\quad C_{n+1}={\frac {2(2n+1)}{n+2}}C_{n}. $ 



 Asymptotically, the Catalan numbers grow as 

 $ C_{n}\sim {\frac {4^{n}}{n^{3/2}{\sqrt {\pi }}}} $ 

 in the sense that the quotient of the *n*th Catalan number and the expression on the right [tends towards](https://en.wikipedia.org/wiki/Limit_of_a_function) 1 as *n* approaches infinity. This can be proved by using [Stirling's approximation](https://en.wikipedia.org/wiki/Stirling's_approximation) for *n*! or via generating functions; see the [Asymptotic growth of the Catalan numbers](https://en.wikipedia.org/wiki/Generating_function#Asymptotic_growth_of_the_Catalan_numbers) section of the [Generating function](https://en.wikipedia.org/wiki/Generating_function) article. 

 The only Catalan numbers $C_n$ that are odd are those for which $n = 2^k − 1$; all others are even. The only prime Catalan numbers are $C_2 = 2$ and $C_3 = 5$.[[2\]](https://en.wikipedia.org/wiki/Catalan_number#cite_note-2) 

 The Catalan numbers have an integral representation 

 $ C_{n}=\int _{0}^{4}x^{n}\rho (x)\,dx, $ 

 where $ \rho (x)={\tfrac {1}{2\pi }}{\sqrt {\tfrac {4-x}{x}}}. $ This means that the Catalan numbers are a solution of the [Hausdorff moment problem](https://en.wikipedia.org/wiki/Hausdorff_moment_problem) on the interval [0, 4] instead of [0, 1]. The [orthogonal polynomials](https://en.wikipedia.org/wiki/Orthogonal_polynomials) having the weight function $ \rho (x) $ on $ [0,4] $ are 

 $ H_{n}(x)=\sum _{k=0}^{n}{n+k \choose n-k}(-x)^{k}. $ 



## Applications in combinatorics

There are many counting problems in [combinatorics](https://en.wikipedia.org/wiki/Combinatorics) whose solution is given by the **Catalan numbers**. The book *Enumerative Combinatorics: Volume 2* by combinatorialist [Richard P. Stanley](https://en.wikipedia.org/wiki/Richard_P._Stanley) contains a set of exercises which describe 66 different interpretations（解释） of the **Catalan numbers**. Following are some examples, with illustrations of the cases $C_3 = 5$ and $C_4 = 14$. 

- $C_n$ is the number of [Dyck words](https://en.wikipedia.org/wiki/Dyck_word)[[3\]](https://en.wikipedia.org/wiki/Catalan_number#cite_note-3) of length $2n$. A Dyck word is a [string](https://en.wikipedia.org/wiki/String_(computer_science)) consisting of *n* X's and *n* Y's such that no initial segment of the string has more Y's than X's. For example, the following are the Dyck words of length 6:

`XXXYYY   XYXXYY   XYXYXY   XXYYXY   XXYXYY.`

- Re-interpreting the symbol X as an open [parenthesis](https://en.wikipedia.org/wiki/Bracket#Parentheses) and Y as a close parenthesis, $C_n$ counts the number of expressions containing *n* pairs of parentheses which are correctly matched:

 `((()))   ()(())   ()()()   (())()   (()())` 

- $C_n$ is the number of different ways *n* + 1 factors can be completely [parenthesized](https://en.wikipedia.org/wiki/Bracket) (or the number of ways of [associating](https://en.wikipedia.org/wiki/Associativity) *n* applications of a [binary operator](https://en.wikipedia.org/wiki/Binary_operator)). For *n* = 3, for example, we have the following five different parenthesizations of four factors:

 `((ab)c)d   (a(bc))d   (ab)(cd)   a((bc)d)   a(b(cd))` 

- Successive applications of a binary operator can be represented in terms of a full [binary tree](https://en.wikipedia.org/wiki/Binary_tree). (A rooted binary tree is *full* if every vertex has either two children or no children.) It follows that $C_n$ is the number of full binary [trees](https://en.wikipedia.org/wiki/Tree_(graph_theory)) with *n* + 1 leaves:

 [![Catalan number binary tree example.png](https://upload.wikimedia.org/wikipedia/commons/0/01/Catalan_number_binary_tree_example.png)](https://en.wikipedia.org/wiki/File:Catalan_number_binary_tree_example.png) 

***SUMMARY*** : 如果将 `((ab)c)d   (a(bc))d   (ab)(cd)   a((bc)d)   a(b(cd))` 中的字符看做上面树中的leaf node的话，则它们是一一对应的，这说明它们本质上是同一类问题；这说明catalan number和二叉树之间也是存在着一定的关联的；


- $C_n$ is the number of non-isomorphic ordered trees with *n* + 1 vertices. (An ordered tree is a rooted tree in which the children of each vertex are given a fixed left-to-right order.)[[4\]](https://en.wikipedia.org/wiki/Catalan_number#cite_note-4) 

- $C_n$ is the number of monotonic [lattice paths](https://en.wikipedia.org/wiki/Lattice_path) along the edges of a grid with *n* × *n* square cells, which do not pass above the diagonal. A monotonic path is one which starts in the lower left corner, finishes in the upper right corner, and consists entirely of edges pointing rightwards or upwards. Counting such paths is equivalent to counting Dyck words: X stands for "move right" and Y stands for "move up". 



## Proof of the formula

 There are several ways of explaining why the formula 

 $ C_{n}={\frac {1}{n+1}}{2n \choose n} $ 





## Generalizations

The two-parameter sequence of non-negative integers $ {\frac {(2m)!(2n)!}{(m+n)!m!n!}} $ is a generalization of the Catalan numbers. These are named **super-Catalan numbers**, by [Ira Gessel](https://en.wikipedia.org/wiki/Ira_Gessel). These number should not confused with the [Schröder–Hipparchus numbers](https://en.wikipedia.org/wiki/Schröder–Hipparchus_number), which sometimes are also called super-Catalan numbers.

For $ m=1 $, this is just two times the ordinary Catalan numbers, and for $ m=n $, the numbers have an easy combinatorial description. However, other combinatorial descriptions are only known[[15\]](https://en.wikipedia.org/wiki/Catalan_number#cite_note-Chen2012-15) for $ m=2 $ and $ m=3 $, and it is an open problem to find a general combinatorial interpretation.

[Sergey Fomin](https://en.wikipedia.org/wiki/Sergey_Fomin) and Nathan Reading have given a generalized Catalan number associated to any finite crystalographic [Coxeter group](https://en.wikipedia.org/wiki/Coxeter_group), namely the number of fully commutative elements of the group; in terms of the associated [root system](https://en.wikipedia.org/wiki/Root_system), it is the number of anti-chains (or order ideals) in the poset of positive roots. The classical Catalan number $ C_{n} $ corresponds to the root system of type $ A_{n} $. The classical recurrence relation generalizes: the Catalan number of a Coxeter diagram is equal to the sum of the Catalan numbers of all its maximal proper sub-diagrams.[[16\]](https://en.wikipedia.org/wiki/Catalan_number#cite_note-16)

