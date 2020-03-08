# [Enumerative combinatorics](https://en.wikipedia.org/wiki/Enumerative_combinatorics)

**Enumerative combinatorics** is an area of [combinatorics](https://en.wikipedia.org/wiki/Combinatorics) that deals with the number of ways that certain patterns can be formed. Two examples of this type of problem are counting [combinations](https://en.wikipedia.org/wiki/Combinations) and counting [permutations](https://en.wikipedia.org/wiki/Permutations). More generally, given an infinite collection of finite sets $S_i$ indexed by the [natural numbers](https://en.wikipedia.org/wiki/Natural_number), **enumerative combinatorics** seeks to describe a *counting function* which counts the number of objects in $S_n$ for each *n*. Although [counting](https://en.wikipedia.org/wiki/Counting#Counting_in_mathematics) the number of elements in a set is a rather broad [mathematical problem](https://en.wikipedia.org/wiki/Mathematical_problem), many of the problems that arise in applications have a relatively simple [combinatorial](https://en.wikipedia.org/wiki/Combinatorial) description. The [twelvefold way](https://en.wikipedia.org/wiki/Twelvefold_way) provides a unified framework for **counting** [permutations](https://en.wikipedia.org/wiki/Permutations), [combinations](https://en.wikipedia.org/wiki/Combinations) and [partitions](https://en.wikipedia.org/wiki/Partition_of_a_set).

***SUMMARY*** : 对于program而言，[Enumeration](https://en.wikipedia.org/wiki/Enumeration)比 [counting](https://en.wikipedia.org/wiki/Counting#Counting_in_mathematics) 更加重要，尤其是在optimization问题中，只有经过[Enumeration](https://en.wikipedia.org/wiki/Enumeration)、比较才能够得到最优的解； [counting](https://en.wikipedia.org/wiki/Counting#Counting_in_mathematics) 往往是在进行complexity分析的时候需要使用的；

The simplest such functions are *[closed formulas](https://en.wikipedia.org/wiki/Closed_formula)*, which can be expressed as a composition of elementary functions such as [factorials](https://en.wikipedia.org/wiki/Factorial), powers, and so on. For instance, as shown below, the number of different possible orderings of a deck of *n* cards is *f*(*n*) = *n*!. The problem of finding a closed formula is known as [algebraic enumeration](https://en.wikipedia.org/wiki/Algebraic_enumeration), and frequently involves deriving a [recurrence relation](https://en.wikipedia.org/wiki/Recurrence_relation) or [generating function](https://en.wikipedia.org/wiki/Generating_function) and using this to arrive at the desired closed form.

Often, a complicated closed formula yields little insight into the behavior of the counting function as the number of counted objects grows. In these cases, a simple [asymptotic](https://en.wikipedia.org/wiki/Asymptotic_analysis) approximation may be preferable. A function $ g(n) $ is an asymptotic approximation to $ f(n) $ if $ f(n)/g(n)\rightarrow 1 $ as $ n\rightarrow \infty $. In this case, we write $ f(n)\sim g(n).\, $



## Generating functions

 Generating functions are used to describe families of combinatorial objects. Let $ {\mathcal {F}} $ denote the family of objects and let *F*(*x*) be its generating function. Then 

 $ F(x)=\sum _{n=0}^{\infty }f_{n}x^{n} $ 

 where $ f_{n} $ denotes the number of combinatorial objects of size *n*. The number of combinatorial objects of size *n* is therefore given by the coefficient of $ x^{n} $. Some common operation on families of combinatorial objects and its effect on the generating function will now be developed. The exponential generating function is also sometimes used. In this case it would have the form 

 $ F(x)=\sum _{n=0}^{\infty }f_{n}{\frac {x^{n}}{n!}} $ 

 Once determined, the generating function yields the information given by the previous approaches. In addition, the various natural operations on generating functions such as addition, multiplication, differentiation, etc., have a combinatorial significance; this allows one to extend results from one combinatorial problem in order to solve others. 

### Union

 Given two combinatorial families, $ {\mathcal {F}} $ and $ {\mathcal {G}} $ with generating functions *F*(*x*) and *G*(*x*) respectively, the disjoint union of the two families ($ {\mathcal {F}}\cup {\mathcal {G}} $) has generating function *F*(*x*) + *G*(*x*). 

### Pairs

 For two combinatorial families as above the Cartesian product (pair) of the two families ($ {\mathcal {F}}\times {\mathcal {G}} $) has generating function *F*(*x*)*G*(*x*). 



### Sequences

 A sequence generalizes the idea of the pair as defined above. Sequences are arbitrary [Cartesian products](https://en.wikipedia.org/wiki/Cartesian_product) of a combinatorial object with itself. Formally: 

 $ {\mbox{Seq}}({\mathcal {F}})=\epsilon \ \cup \ {\mathcal {F}}\ \cup \ {\mathcal {F}}\times {\mathcal {F}}\ \cup \ {\mathcal {F}}\times {\mathcal {F}}\times {\mathcal {F}}\ \cup \cdots $ 

 To put the above in words: An empty sequence or a sequence of one element or a sequence of two elements or a sequence of three elements, etc. The generating function would be: 

 $ 1+F(x)+[F(x)]^{2}+[F(x)]^{3}+\cdots ={\frac {1}{1-F(x)}} $ 

## Combinatorial structures

 The above operations can now be used to enumerate common combinatorial objects including trees (binary and plane), [Dyck paths](https://en.wikipedia.org/wiki/Dyck_path) and cycles. A combinatorial structure is composed of atoms. For example, with trees the atoms would be the nodes. The atoms which compose the object can either be labeled or unlabeled. Unlabeled atoms are indistinguishable from each other, while labelled atoms are distinct. Therefore, for a **combinatorial object** consisting of labeled atoms a new object can be formed by simply swapping two or more atoms. 

### Binary and plane trees

 Binary and plane [trees](https://en.wikipedia.org/wiki/Tree_(mathematics)) are examples of an unlabeled combinatorial structure. Trees consist of nodes linked by edges in such a way that there are no cycles. There is generally a node called the root, which has no parent node. In Plane trees each node can have an arbitrary number of children. In binary trees, a special case of plane trees, each node can have either two or no children. Let $ {\mathcal {P}} $ denote the family of all plane trees. Then this family can be recursively defined as follows: 

 $ {\mathcal {P}}=\{\bullet \}\times {\mbox{Seq}}({\mathcal {P}}) $ 

 In this case $ \{\bullet \} $ represents the family of objects consisting of one node. This has generating function *x*. Let *P*(*x*) denote the generating function $ {\mathcal {P}} $. Putting the above description in words: A plane tree consists of a node to which is attached an arbitrary number of subtrees, each of which is also a plane tree. Using the operation on families of combinatorial structures developed earlier this translates to a recursive generating function: 

 $ P(x)=x{\frac {1}{1-P(x)}} $ 

 After solving for *P*(*x*): 

 $ P(x)={\frac {1-{\sqrt {1-4x}}}{2}} $ 

 An explicit formula for the number of plane trees of size *n* can now be determined by extracting the coefficient of $x^n$. 

 $ {\begin{aligned}p_{n}&=[x^{n}]P(x)=[x^{n}]{\frac {1-{\sqrt {1-4x}}}{2}}\\[6pt]&=[x^{n}]{\frac {1}{2}}-[x^{n}]{\frac {1}{2}}{\sqrt {1-4x}}\\[6pt]&=-{\frac {1}{2}}[x^{n}]\sum _{k=0}^{\infty }{{\frac {1}{2}} \choose k}(-4x)^{k}\\[6pt]&=-{\frac {1}{2}}{{\frac {1}{2}} \choose n}(-4)^{n}\\[6pt]&={\frac {1}{n}}{2n-2 \choose n-1}\end{aligned}} $ 

 Note: The notation [*x**n*] *f*(*x*) refers to the coefficient of *x**n* in *f*(*x*). The series expansion of the square root is based on Newton's generalization of the [binomial theorem](https://en.wikipedia.org/wiki/Binomial_theorem#Newton's_generalised_binomial_theorem). To get from the fourth to fifth line manipulations using the [generalized binomial coefficient](https://en.wikipedia.org/wiki/Binomial_coefficient#Generalization_and_connection_to_the_binomial_series) is needed. 

 The expression on the last line is equal to the (*n* − 1)th [Catalan number](https://en.wikipedia.org/wiki/Catalan_number). Therefore *p**n* = *c**n*−1. 

