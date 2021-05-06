# yufeizhao [Bijections](http://yufeizhao.com/olympiad/bijections.pdf) 

 In this lecture, we will look at using **bijections** to solve **combinatorics problems**. Given two sets A and B, a ***bijection*** (also called ***bijective correspondence***) is a map f : A → B that is both **injective**（单射） and **surjective**（满射）, meaning that no two elements of A get mapped onto the same element in B, and every element of B is the image of some element of A . This gives us a way of pairing up every element from A with some element of B. In particular, when the sets are finite, the existence of a bijection implies that |A | = |B|. 

 This explanation of a bijection may seem a little abstract. Let us take a look at some examples of how bijections can be used 

##  Problem 1. 

### Q:

 Determine the number of walks from (0, 0) to (m, n) allowing only unit steps up or to the right 

### A

 The idea of using **bijection** is that we want to tranform the problem into something that we know better how to count. In this case, we can encode the path as a sequence letters U and R, correponding to whether the step taken was a unit up step (U) or a unit right step (R). The path displayed above, for instance, is encoded as 

>  RRURRUURRURRUUURRU 

 Note that the resulting sequence of letters always has m copies of R and n copies of U, since it takes in total of m right unit steps and n up unit steps to move from (0, 0) to   (m, n). Also, you can check that for any sequence consisting of m copies of R and n copies of U, we can construct a corresponding path encoded by this sequence. Thus we have constructed a bijection between the following two sets: 

> the set of walks from (0, 0) to (m, n) using only unit up or right steps 

​								/\

​								|								

​								\/

> the set of sequences consisting of m copies of R and n copies of U. 

We know how to count the latter set. It has exactly $\tbinom {m+n} {m}$ elements, which can be thought of as choosing m spots to place the R’s in a sequence of length m+n. Therefore, the number of lattice walks from (0, 0) to (m, n) must be $\tbinom {m+n} {n}$ as wel 





Next, let us explore the **Catalan numbers**, which is a sequence is that comes up in many counting problems, which provide a rich source for bijections.  



## Problem 5 

### Q

Let $n$ be a positive integer. Determine the number of lattice paths from (0, 0) to (n, n) using only unit up and right steps, such that the path stays in the region x ≥ y.  

### A

We saw previously that the total number of lattice paths from (0, 0) to (n, n) without the x ≥ y restriction is equal is $\tbinom {2 \times n} {n}$. Let us count the number of paths that goes into the x < y region. Call these paths **bad path** 



 Suppose that P is a bad path. Since P goes into the region x < y, it must hit the line y = x + 1 at some point. Let X be the first point on the path P that lies on the line y = x + 1. Now, reflect the portion of path P up to X about the line y = x + 1, keeping the latter portion of P the same. This gives us a new path P 0 . 

## Problem 6 

### Q

Show that the n-th Catalan number counts the number of expressions containing n pairs of parentheses which are correctly matched. E.g., for n = 3, 

```
((())) (()()) (())() ()(()) ()()()
```

We could solve this problem by counting it using techniques similar to the one used to count paths above. A much quicker solution is to find a bijection between these parentheses expressions and the **lattice paths** counted in the previous problem. Indeed, note that by interpretating each ( as a unit right step and each ) as a unit up step, we obtain the desired **bijection**. The condition that the parentheses expression is correctedly matched corresponds exactly to the condition that the lattice path do not go into the x < y region (why?). This bijection shows that the number of expressions of n pairs of parentheses which are correctly matched is also equal to n-th Catalan number, as desired. 





The previous **bijection** was rather simple. Let us look at a more involved Catalan number bijection. 

A ***plane tree***（平面树） is an object with the following structure. We start with a **root vertex** (drawn at the top), and then with each node we attach a number of new vertices (possibly none), where the order of the attached vertices matters. For instance, there are exactly 5 plane trees with 4 vertices:  

##  Problem 7 

### Q

 Show that the n-th Catalan number counts the number of plane trees with n + 1 vertices.  

### A

 We will produce a **bijection** between **plane trees** and the **parentheses expressions** considered in the previous problem. We first describe an algorithm to turn a **plane tree** into a **parentheses expression**. 

 Given a **plane tree**（平面树）, starting from the **top vertex**, let us perform a depth-first search walk, meaning that we go as further down as possible until we hit a dead-end, and then backtrack to a branch point, where we then explore a new branch. We will always explore the branches of a vertex in order from left to right. For instance, starting with the plane 

图略

 we obtain the following walk, where the steps are labeled in order. 

图略

 Now we record the sequence of steps we took, writing down a `(` each time we stepped downward along an edge, and a `)` every time we stepped upward along an edge. For example, the above walk corresponds to 





 A plane tree with n + 1 vertices always produces a correctly matched expression of n pairs of parentheses correctly matched (why is it correctly matched?). Conversely, given an expression of n pairs of correctly matched parentheses, it is possible to reverse this construction to produce a plane tree that corresponds to it. You should first convince yourself that this is the case why writing down a few parentheses expressions and then figure out what the corresponding tree is. Then, you should write down a description of this bijection.  

***SUMMARY*** : n + 1个节点共有n条边，在遍历过程中，肯定会沿着每条边下一次然后上一次，所以这就对应了一对括号了；