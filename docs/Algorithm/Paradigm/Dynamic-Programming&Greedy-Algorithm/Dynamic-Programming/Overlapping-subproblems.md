[TOC]

# [Overlapping subproblems](https://en.wikipedia.org/wiki/Overlapping_subproblems)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a [problem](https://en.wikipedia.org/wiki/Problem) is said to have **overlapping subproblems** if the problem can be broken down into subproblems which are reused several times or a recursive algorithm for the problem solves the same subproblem over and over rather than always generating new subproblems.[[1\]](https://en.wikipedia.org/wiki/Overlapping_subproblems#cite_note-1)[[2\]](https://en.wikipedia.org/wiki/Overlapping_subproblems#cite_note-2) [[3\]](https://en.wikipedia.org/wiki/Overlapping_subproblems#cite_note-3)

For example, the problem of computing the [Fibonacci sequence](https://en.wikipedia.org/wiki/Fibonacci_sequence) exhibits overlapping subproblems. The problem of computing the *n*th [Fibonacci number](https://en.wikipedia.org/wiki/Fibonacci_number) *F*(*n*), can be broken down into the subproblems of computing *F*(*n* − 1) and *F*(*n* − 2), and then adding the two. The subproblem of computing *F*(*n* − 1) can itself be broken down into a subproblem that involves computing *F*(*n* − 2). Therefore, the computation of *F*(*n* − 2) is reused, and the Fibonacci sequence thus exhibits overlapping subproblems.

A naive [recursive](https://en.wikipedia.org/wiki/Recursive) approach to such a problem generally fails due to an [exponential complexity](https://en.wikipedia.org/wiki/Exponential_time). If the problem also shares an [optimal substructure](https://en.wikipedia.org/wiki/Optimal_substructure) property, [dynamic programming](https://en.wikipedia.org/wiki/Dynamic_programming) is a good way to work it out.

