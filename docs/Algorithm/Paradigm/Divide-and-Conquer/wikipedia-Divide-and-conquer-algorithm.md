# wikipedia [Divide-and-conquer algorithm](https://en.wikipedia.org/wiki/Divide-and-conquer_algorithm)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), **divide and conquer** is an [algorithm design paradigm](https://en.wikipedia.org/wiki/Algorithm_design_paradigm) based on multi-branched [recursion](https://en.wikipedia.org/wiki/Recursion). A divide-and-conquer [algorithm](https://en.wikipedia.org/wiki/Algorithm) works by recursively breaking down a problem into two or more sub-problems of the same or related type, until these become simple enough to be solved directly. The solutions to the sub-problems are then combined to give a solution to the original problem.

This divide-and-conquer technique is the basis of efficient algorithms for all kinds of problems, such as [sorting](https://en.wikipedia.org/wiki/Sorting_algorithm) (e.g., [quicksort](https://en.wikipedia.org/wiki/Quicksort), [merge sort](https://en.wikipedia.org/wiki/Merge_sort)), [multiplying large numbers](https://en.wikipedia.org/wiki/Multiplication_algorithm) (e.g. the [Karatsuba algorithm](https://en.wikipedia.org/wiki/Karatsuba_algorithm)), finding the [closest pair of points](https://en.wikipedia.org/wiki/Closest_pair_of_points_problem), [syntactic analysis](https://en.wikipedia.org/wiki/Syntactic_analysis)(e.g., [top-down parsers](https://en.wikipedia.org/wiki/Top-down_parser)), and computing the [discrete Fourier transform](https://en.wikipedia.org/wiki/Discrete_Fourier_transform) ([FFT](https://en.wikipedia.org/wiki/Fast_Fourier_transform)).[*citation needed*]

Understanding and designing divide-and-conquer algorithms is a complex skill that requires a good understanding of the nature of the underlying problem to be solved. As when proving a [theorem](https://en.wikipedia.org/wiki/Theorem) by [induction](https://en.wikipedia.org/wiki/Mathematical_induction), it is often necessary to replace the original problem with a more general or complicated problem in order to initialize the recursion, and there is no systematic method for finding the proper generalization.[*clarification needed*] These divide-and-conquer complications are seen when optimizing the calculation of a [Fibonacci number with efficient double recursion](https://en.wikipedia.org/wiki/Fibonacci_number#Matrix_form).[*why?*][*citation needed*]

> NOTE:正如使用induction来
证明一个定理，为了初始化递归，需要使用一个更加general或者更加complicate问题来替换原问题。


The correctness of a divide-and-conquer algorithm is usually proved by [mathematical induction](https://en.wikipedia.org/wiki/Mathematical_induction), and its computational cost is often determined by solving [recurrence relations](https://en.wikipedia.org/wiki/Recurrence_relation).

> NOTE: [recurrence relations](https://en.wikipedia.org/wiki/Recurrence_relation) 的意思是：递推关系

