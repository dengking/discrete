# Complexity of Divide-and-Conquer Algorithms

这是一个比较复杂有难度的问题，需要循序渐进地学习，首先以最最知名的Divide-and-Conquer Algorithm: Binary search为例进行学习，然后推广到更加广泛的范围。

## O(logN)

O(logN)是我们最常见的complexity，它总是和binary一起，比如Binary search，本节对它进行探讨，素材如下: 

- [stackoverflow-how to calculate binary search complexity](https://stackoverflow.com/questions/8185079/how-to-calculate-binary-search-complexity) # [A](https://stackoverflow.com/questions/8185079/how-to-calculate-binary-search-complexity/8185382#8185382) 从binary search algorithm的具体的比较次数来进行分析，准确地计算出了执行binary search所需要执行比较的次数，一个巧合是: bindery search的比较的次数正好和binary search tree的高度相同。那两者背后是否有关联呢？答案是肯定的，在 [stackoverflow-What does O(log n) mean exactly?](https://stackoverflow.com/questions/2307283/what-does-olog-n-mean-exactly)  # [A](https://stackoverflow.com/a/13093274/23877800) 中进行了解释 
- [stackoverflow-What does O(log n) mean exactly?](https://stackoverflow.com/questions/2307283/what-does-olog-n-mean-exactly)  # [A](https://stackoverflow.com/questions/2307283/what-does-olog-n-mean-exactly/2307314#2307314) 相比于 [stackoverflow-how to calculate binary search complexity](https://stackoverflow.com/questions/8185079/how-to-calculate-binary-search-complexity) # [A](https://stackoverflow.com/questions/8185079/how-to-calculate-binary-search-complexity/8185382#8185382) 进行了一点扩展，比在局限于binary search，但是其实也差不多



### stackoverflow [how to calculate binary search complexity](https://stackoverflow.com/questions/8185079/how-to-calculate-binary-search-complexity) 

I heard somebody say that since **binary search** halves the input required to search hence it is log(n) algorithm. Since I am not from a mathematics background I am not able to relate to it. Can somebody explain it in a little more detail? does it have to do something with the logarithmic series? 

#### [A](https://stackoverflow.com/questions/8185079/how-to-calculate-binary-search-complexity/8185382#8185382)

Here a more mathematical way of seeing it, though not really complicated. IMO much clearer as informal ones:

The question is, how many times can you divide N by 2 until you have 1? This is essentially saying, do a **binary search** (half the elements) until you found it. In a formula this would be this:

$$
1 = N / 2^x
$$

> NOTE:
>
> 一. 上述公式是对 "how many times can you divide N by 2 until you have 1?"的数学表达，$x$ 就是需要进行求解的未知数

multiply by $2^x$:

$$
2^x = N
$$


now do the $log_2$:


$$
log_2{(2^x)}    = log_2{ N} \\
    x * log_2{(2)} = log_2{ N} \\
    x * 1         = log_2{ N}\\
$$


this means you can divide log N times until you have everything divided. Which means you have to divide $log N$ ("do the binary search step") until you found your element.

### stackoverflow [What does O(log n) mean exactly?](https://stackoverflow.com/questions/2307283/what-does-olog-n-mean-exactly) 

I am learning about Big O Notation running times and amortized(均摊) times.  I understand the notion of *O(n)* linear time, meaning that the size of the input affects the growth of the algorithm proportionally...and the same goes for, for example, quadratic time $O(n^2)$ etc..even algorithms, such as permutation generators, with *O(n!)* times, that grow by factorials.

For example, the following function is *O(n)* because the algorithm grows in proportion to its input *n*:  

```c
f(int n) {
  int i;
  for (i = 0; i < n; ++i)
    printf("%d", i);
}
```

Similarly, if there was a nested loop, the time would be $O(n^2)$.

But what exactly is *O(log n)*?  For example, what does it mean to say that the height of a **complete binary tree** is *O(log n)*?

I do know (maybe not in great detail) what Logarithm is, in the sense that:  $log_{10}{ 100} = 2$, but I cannot understand how to identify a function with a logarithmic time.



#### [A](https://stackoverflow.com/questions/2307283/what-does-olog-n-mean-exactly/2307314#2307314) 

> I cannot understand how to identify a function with a log time.

> NOTE:
>
> 一. 关于这个问题，下面是作者的解答。作者的回答比较抽象，具有一定的概括性，但是它所描述的其实和binary search类似，或者是binary search符合作者所描述的。
>
> > the choice of the next element on which to perform some action is one of several possibilities, and only one will need to be chosen.
>
> 这段话结合binary search algorithm、"looking up people in a phone book"其实是非常好理解的，但是后面这句"the elements on which the action is performed are digits of n"中的"digits of n"要如何理解呢？
>
> 从search space的角度来分析: 充分用用sorted的特性，来减少搜索空间

The most common attributes of logarithmic running-time function are that:  

- the choice of the next element on which to perform some action is one of several possibilities, and
- only one will need to be chosen.

or

- the elements on which the action is performed are digits of n

  

This is why, for example, looking up people in a phone book is O(log n). You don't need to check *every* person in the phone book to find the right one; instead, you can simply **divide-and-conquer** by looking based on where their name is alphabetically, and in every section you only need to explore a subset of each section before you eventually find someone's phone number.

Of course, a bigger phone book will still take you a longer time, but it won't grow as quickly as the proportional increase in the additional size.  

------

We can expand the phone book example to compare other kinds of operations and *their* running time. We will assume our phone book has *businesses*(企业) (the "Yellow Pages") which have unique names and *people* (the "White Pages") which may not have unique names. A phone number is assigned to at most one person or business. We will also assume that it takes constant time to flip(翻阅) to a specific page.

Here are the running times of some operations we might perform on the phone book, from best to worst:

  

- **O(1) (best case):** Given the page that a business's name is on and the business name, find the phone number.

- **O(1) (average case):** Given the page that a person's name is on and their name, find the phone number.

- **O(log n):** Given a person's name, find the phone number by picking a random point about halfway through the part of the book you haven't searched yet, then checking to see whether the person's name is at that point. Then repeat the process about halfway through the part of the book where the person's name lies. (This is a **binary search** for a person's name.)

- **O(n):** Find all people whose phone numbers contain the digit "5".

- **O(n):** Given a phone number, find the person or business with that number.

- **O(n log n):** There was a mix-up(混乱、打架) at the printer's office, and our phone book had all its pages inserted in a random order. Fix the ordering so that it's correct by looking at the first name on each page and then putting that page in the appropriate spot in a new, empty phone book.

  

For the below examples, we're now at the printer's office. Phone books are waiting to be mailed to each resident or business, and there's a sticker on each phone book identifying where it should be mailed to. Every person or business gets one phone book.

  

- **O(n log n):** We want to personalize the phone book, so we're going to find each person or business's name in their designated copy, then circle their name in the book and write a short thank-you note for their patronage.

- **$O(n^2)$:** A mistake occurred at the office, and every entry in each of the phone books has an extra "0" at the end of the phone number. Take some white-out and remove each zero.

- **O(n · n!):** We're ready to load the phonebooks onto the shipping dock. Unfortunately, the robot that was supposed to load the books has gone haywire: it's putting the books onto the truck in a random order! Even worse, it loads all the books onto the truck, then checks to see if they're in the right order, and if not, it unloads them and starts over. (This is the dreaded **bogo sort**.)

- **$O(n^n)$:** You fix the robot so that it's loading things correctly. The next day, one of your co-workers plays a prank on you and wires the loading dock robot to the automated printing systems. Every time the robot goes to load an original book, the factory printer makes a duplicate run of all the phonebooks! Fortunately, the robot's bug-detection systems are sophisticated enough that the robot doesn't try printing even more copies when it encounters a duplicate book for loading, but it still has to load every original and duplicate book that's been printed.

  

For more mathematical explanation you can checkout how the time complexity arrives to `log n` here. https://hackernoon.com/what-does-the-time-complexity-o-log-n-actually-mean-45f94bb5bfbf 

#### [A](https://stackoverflow.com/a/2307330/23877800)

`O(log N)` basically means time goes up linearly while the `n` goes up exponentially. So if it takes `1` second to compute `10` elements, it will take `2` seconds to compute `100` elements, `3` seconds to compute `1000` elements, and so on.

It is `O(log n)` when we do divide and conquer type of algorithms e.g binary search. Another example is quick sort where each time we divide the array into two parts and each time it takes `O(N)` time to find a pivot element. Hence it `N O(log N)`



## Master theorem

### chatgpt

The Master Theorem is a mathematical tool used to analyze the time complexity of recursive algorithms. It provides a framework for determining the asymptotic behavior of algorithms that follow a specific recursive form.

The Master Theorem is typically used for divide-and-conquer algorithms that can be expressed in the form:

$T(n) = a * T(n/b) + f(n)$

where:
- T(n) represents the time complexity of the algorithm for an input of size n.
- a represents the number of recursive subproblems.
- n/b represents the size of each subproblem.
- f(n) represents the time complexity of the work done outside the recursive calls.

The Master Theorem provides three cases based on the relationship between a, b, and f(n):

1. If $f(n) = O(n^c)$ for some constant $c < log_b(a)$, then the time complexity is dominated by the recursive calls. In this case, the time complexity is T(n) = Θ(n^log_b(a)).

2. If f(n) = Θ(n^c * log^k(n)) for some constant c and k ≥ 0, and if a * f(n/b) ≤ c * f(n) for sufficiently large n, then the time complexity is balanced between the recursive calls and the work done outside. In this case, the time complexity is T(n) = Θ(n^c * log^(k+1)(n)).

3. If f(n) = Ω(n^c) for some constant c > log_b(a), and if a * f(n/b) ≥ c * f(n) for sufficiently large n, then the time complexity is dominated by the work done outside the recursive calls. In this case, the time complexity is T(n) = Θ(f(n)).

The Master Theorem provides a convenient way to analyze the time complexity of recursive algorithms without explicitly solving the recurrence relation. However, it is important to note that the Master Theorem is applicable only to a specific form of recursive algorithms and may not be applicable to all recursive algorithms.

I hope this explanation helps! Let me know if you have any further questions.

### wikipedia [Master theorem (analysis of algorithms)](https://en.wikipedia.org/wiki/Master_theorem_(analysis_of_algorithms))

In the [analysis of algorithms](https://en.wikipedia.org/wiki/Analysis_of_algorithms), the **master theorem for divide-and-conquer recurrences** provides an [asymptotic analysis](https://en.wikipedia.org/wiki/Asymptotic_analysis) for many [recurrence relations](https://en.wikipedia.org/wiki/Recurrence_relation) that occur in the [analysis](https://en.wikipedia.org/wiki/Analysis_of_algorithms) of [divide-and-conquer algorithms](https://en.wikipedia.org/wiki/Divide_and_conquer_algorithm). The approach was first presented by [Jon Bentley](https://en.wikipedia.org/wiki/Jon_Bentley_(computer_scientist)), [Dorothea Blostein](https://en.wikipedia.org/wiki/Dorothea_Blostein) (née Haken), and [James B. Saxe](https://en.wikipedia.org/wiki/James_B._Saxe) in 1980, where it was described as a "unifying method" for solving such recurrences.

The name "master theorem" was popularized by the widely-used algorithms textbook *[Introduction to Algorithms](https://en.wikipedia.org/wiki/Introduction_to_Algorithms)* by [Cormen](https://en.wikipedia.org/wiki/Thomas_H._Cormen), [Leiserson](https://en.wikipedia.org/wiki/Charles_E._Leiserson), [Rivest](https://en.wikipedia.org/wiki/Ron_Rivest), and [Stein](https://en.wikipedia.org/wiki/Clifford_Stein).

Not all recurrence relations can be solved by this theorem; its generalizations include the [Akra–Bazzi method](https://en.wikipedia.org/wiki/Akra–Bazzi_method).

#### Introduction

Consider a problem that can be solved using a [recursive algorithm](https://en.wikipedia.org/wiki/Recursive_algorithm) such as the following:

```pseudocode
procedure p(input x of size n):
    if n < some constant k:
        Solve x directly without recursion
    else:
        Create a subproblems of x, each having size n/b
        Call procedure p recursively on each subproblem
        Combine the results from the subproblems
```

The above algorithm divides the problem into a number of subproblems recursively, each subproblem being of size *n*/*b*. Its [solution tree](https://en.wikipedia.org/w/index.php?title=Solution_tree&action=edit&redlink=1) has a node for each recursive call, with the children of that node being the other calls made from that call. The leaves of the tree are the **base cases** of the recursion, the subproblems (of size less than *k*) that do not recurse. The above example would have *a* child nodes at each non-leaf node. Each node does an amount of work that corresponds to the size of the subproblem *n* passed to that instance of the recursive call and given by $f(n)$​. **The total amount of work done by the entire algorithm is the sum of the work performed by all the nodes in the tree**.

> NOTE:
>
> 一、最后一段话是关键核心所在

The runtime of an algorithm such as the *p* above on an input of size *n*, usually denoted $T(n)$​, can be expressed by the [recurrence relation](https://en.wikipedia.org/wiki/Recurrence_relation)
$$
T(n)=a\;T\left({\frac {n}{b}}\right)+f(n)
$$
where $f(n)$ is the time to create the subproblems and combine their results in the above procedure. 



#### Application to common algorithms

|                          Algorithm                           |                   Recurrence relationship                    |                           Run time                           |                           Comment                            |
| :----------------------------------------------------------: | :----------------------------------------------------------: | :----------------------------------------------------------: | :----------------------------------------------------------: |
| [Binary search](https://en.wikipedia.org/wiki/Binary_search) | ![{\displaystyle T(n)=T\left({\frac {n}{2}}\right)+O(1)}](https://wikimedia.org/api/rest_v1/media/math/render/svg/a78716370c21c74f1808d4ca9fe1d7b2786986d5) | ![{\displaystyle O(\log n)}](https://wikimedia.org/api/rest_v1/media/math/render/svg/aae0f22048ba6b7c05dbae17b056bfa16e21807d) | Apply Master theorem case ![{\displaystyle c=\log _{b}a}](https://wikimedia.org/api/rest_v1/media/math/render/svg/14dbd9a5745548d218886b959ce7f2d30df50e3b), where ![{\displaystyle a=1,b=2,c=0,k=0}](https://wikimedia.org/api/rest_v1/media/math/render/svg/f2febcf46a2897811ef7ab88631084fb7dfe4419)[[5\]](https://en.wikipedia.org/wiki/Master_theorem_(analysis_of_algorithms)#cite_note-dartmouth-5) |
|                    Binary tree traversal                     | ![{\displaystyle T(n)=2T\left({\frac {n}{2}}\right)+O(1)}](https://wikimedia.org/api/rest_v1/media/math/render/svg/ce3306e42dc12660a749b44498cb94b0e496c225) | ![{\displaystyle O(n)}](https://wikimedia.org/api/rest_v1/media/math/render/svg/34109fe397fdcff370079185bfdb65826cb5565a) | Apply Master theorem case ![{\displaystyle c<\log _{b}a}](https://wikimedia.org/api/rest_v1/media/math/render/svg/8b4a15e60b3fbd322ffcde801ea55cc90bd93252) where ![{\displaystyle a=2,b=2,c=0}](https://wikimedia.org/api/rest_v1/media/math/render/svg/fb42f5ac8573f25fcd0ada3b53a6618a076053df)[[5\]](https://en.wikipedia.org/wiki/Master_theorem_(analysis_of_algorithms)#cite_note-dartmouth-5) |
|                 Optimal sorted matrix search                 | ![{\displaystyle T(n)=2T\left({\frac {n}{2}}\right)+O(\log n)}](https://wikimedia.org/api/rest_v1/media/math/render/svg/fa51b8f69be9eacd7ac514e93dae29735317f6c6) | ![{\displaystyle O(n)}](https://wikimedia.org/api/rest_v1/media/math/render/svg/34109fe397fdcff370079185bfdb65826cb5565a) | Apply the [Akra–Bazzi theorem](https://en.wikipedia.org/wiki/Akra–Bazzi_theorem) for ![{\displaystyle p=1}](https://wikimedia.org/api/rest_v1/media/math/render/svg/c29a2f2fb3f642618036ed7a79712202e7ada924) and ![{\displaystyle g(u)=\log(u)}](https://wikimedia.org/api/rest_v1/media/math/render/svg/18ecd7b025eaf55f801352edb8b73a04c20915ed) to get ![{\displaystyle \Theta (2n-\log n)}](https://wikimedia.org/api/rest_v1/media/math/render/svg/64e79f6ddb2bea76af7ed8f3723cc5a9e17ed73d) |
|    [Merge sort](https://en.wikipedia.org/wiki/Merge_sort)    | ![{\displaystyle T(n)=2T\left({\frac {n}{2}}\right)+O(n)}](https://wikimedia.org/api/rest_v1/media/math/render/svg/25880508f084e0d3d814505ec1a7b744e340ac81) | ![{\displaystyle O(n\log n)}](https://wikimedia.org/api/rest_v1/media/math/render/svg/9d2320768fb54880ca4356e61f60eb02a3f9d9f1) | Apply Master theorem case ![{\displaystyle c=\log _{b}a}](https://wikimedia.org/api/rest_v1/media/math/render/svg/14dbd9a5745548d218886b959ce7f2d30df50e3b), where ![{\displaystyle a=2,b=2,c=1,k=0}](https://wikimedia.org/api/rest_v1/media/math/render/svg/a86bbc9ac0d52f9759706f1495dc2f290aba469d) |



### 读物

stackoverflow [algorithms: how do divide-and-conquer and time complexity O(nlogn) relate?](https://stackoverflow.com/questions/29927439/algorithms-how-do-divide-and-conquer-and-time-complexity-onlogn-relate)

zhihu [主定理 Master Theorem](https://zhuanlan.zhihu.com/p/100531135)

zhihu [如何理解算法时间复杂度的表示法，例如 O(n²)、O(n)、O(1)、O(nlogn) 等？](https://www.zhihu.com/question/21387264)

https://www.cs.cornell.edu/courses/cs3110/2012sp/lectures/lec20-master/mm-proof.pdf

zhihu [主定理(Master Theorem)](https://www.zhihu.com/people/lewis-3-99)

YSC2229 [4.4. Complexity of Divide-and-Conquer Algorithms](https://ilyasergey.net/YSC2229/week-04-divide-and-conquer-complexity.html#complexity-of-divide-and-conquer-algorithms)



