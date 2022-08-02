# Iterative method

一、"Iterative method"可以看做是一种"approximation"。

二、最最典型的"Iterative method"是[Gradient descent](https://en.wikipedia.org/wiki/Gradient_descent)

> In mathematics, **gradient descent** (also often called **steepest descent**) is a [first-order](https://en.wikipedia.org/wiki/Category:First_order_methods) [iterative](https://en.wikipedia.org/wiki/Iterative_algorithm) [optimization](https://en.wikipedia.org/wiki/Mathematical_optimization) [algorithm](https://en.wikipedia.org/wiki/Algorithm) for finding a [local minimum](https://en.wikipedia.org/wiki/Local_minimum) of a [differentiable function](https://en.wikipedia.org/wiki/Differentiable_function). 



## wikipedia [Iterative method](https://en.wikipedia.org/wiki/Iterative_method)

In [computational mathematics](https://en.wikipedia.org/wiki/Computational_mathematics), an **iterative method** is a [mathematical procedure](https://en.wikipedia.org/wiki/Algorithm) that uses an **initial guess** to generate a sequence of improving approximate solutions for a class of problems, in which the *n*-th approximation is derived from the previous ones. A specific implementation of an iterative method, including the [termination](https://en.wikipedia.org/wiki/Algorithm#Termination) criteria, is an [algorithm](https://en.wikipedia.org/wiki/Algorithm) of the iterative method. An iterative method is called **convergent** if the corresponding sequence converges for given initial approximations. A mathematically rigorous(严谨的) convergence analysis of an iterative method is usually performed; however, [heuristic](https://en.wikipedia.org/wiki/Heuristic)-based iterative methods are also common.

> NOTE: 
>
> 一些highlight:
>
> 1、"initial guess"
>
> 2、"approximate solutions"
>
> 近似解
>
> 3、"[termination](https://en.wikipedia.org/wiki/Algorithm#Termination) criteria"
>
> 停止条件
>
> 4、"converges"
>
> 收敛

In contrast, **direct methods** attempt to solve the problem by a finite sequence of operations. In the absence of [rounding errors](https://en.wikipedia.org/wiki/Rounding_error), direct methods would deliver an exact solution (like solving a linear system of equations $ A\mathbf {x} =\mathbf {b} $ by [Gaussian elimination](https://en.wikipedia.org/wiki/Gaussian_elimination)). Iterative methods are often the only choice for [nonlinear equations](https://en.wikipedia.org/wiki/Nonlinear_equation). However, iterative methods are often useful even for linear problems involving a large number of variables (sometimes of the order of millions), where direct methods would be prohibitively expensive (and in some cases impossible) even with the best available computing power.





