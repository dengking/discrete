# IPOPT



## wikipedia [IPOPT](https://en.wikipedia.org/wiki/IPOPT)



## [coin-or](https://github.com/coin-or)/**[Ipopt](https://github.com/coin-or/Ipopt)**



## Ipopt Documentation # [Overview](https://coin-or.github.io/Ipopt/index.html)

It can be used to solve general nonlinear programming problems of the form
$$
\begin{align} \min_{x\in\mathbb{R}^n} && f(x) \nonumber \\ \text{s.t.} \; && g^L \leq g(x) \leq g^U \tag{NLP} \\ && x^L \leq x \leq x^U, \nonumber \end{align}
$$
where $x \in \mathbb{R}^n$ are the **optimization variables** (possibly with lower and upper bounds, $x^L\in(\mathbb{R}\cup\{-\infty\})^n$ and $x^U\in(\mathbb{R}\cup\{+\infty\})^n$ with $f:\mathbb{R}^n \to \mathbb{R}$ 

## Ipopt Documentation # [**Interfacing your NLP to Ipopt**](https://coin-or.github.io/Ipopt/INTERFACES.html#INTERFACE_CODE)



In order to solve a problem, Ipopt needs more information than just the problem definition (for example, the derivative information). If you are using a modeling language like AMPL, the extra information is provided by the modeling tool and the Ipopt interface. When interfacing with Ipopt through your own code, however, you must provide this additional information. The following information is required by Ipopt:

1. Problem dimensions

   - number of variables
   - number of constraints

2. Problem bounds

   - variable bounds
   - constraint bounds

3. Initial starting point

   - Initial values for the primal 𝑥 variables
   - Initial values for the multipliers (only required for a warm start option)

4. Problem Structure

   - number of nonzeros in the Jacobian of the constraints
   - number of nonzeros in the Hessian of the Lagrangian function
   - sparsity structure of the Jacobian of the constraints
   - sparsity structure of the Hessian of the Lagrangian function

5. Evaluation of Problem Functions

   Information evaluated using a given point ( coming from Ipopt)

   - Objective function, 𝑓(𝑥)
   - Gradient of the objective, ∇𝑓(𝑥)
   - Constraint function values, 𝑔(𝑥)
   - Jacobian of the constraints, ∇𝑔(𝑥)𝑇
   - Hessian of the Lagrangian function, 𝜎𝑓∇2𝑓(𝑥)+∑𝑚𝑖=1𝜆𝑖∇2𝑔𝑖(𝑥)
     (this is not required if a quasi-Newton options is chosen to approximate the second derivatives)

> NOTE:
>
> 一、关于 Lagrangian function，参见zhihu [学习笔记 - 拉格朗日函数](https://zhuanlan.zhihu.com/p/26890210) 
