[TOC]



# [Linear programming](https://en.wikipedia.org/wiki/Linear_programming)


  

**Linear programming** (**LP**, also called **linear optimization**) is a method to achieve the best outcome (such as maximum profit or lowest cost) in a [mathematical model](https://en.wikipedia.org/wiki/Mathematical_model) whose requirements are represented by [linear relationships](https://en.wikipedia.org/wiki/Linear_function#As_a_polynomial_function). Linear programming is a special case of mathematical programming (also known as [mathematical optimization](https://en.wikipedia.org/wiki/Mathematical_optimization)).

More formally, linear programming is a technique for the [optimization](https://en.wikipedia.org/wiki/Mathematical_optimization) of a [linear](https://en.wikipedia.org/wiki/Linear) [objective function](https://en.wikipedia.org/wiki/Objective_function), subject to [linear equality](https://en.wikipedia.org/wiki/Linear_equality) and [linear inequality](https://en.wikipedia.org/wiki/Linear_inequality) [constraints](https://en.wikipedia.org/wiki/Constraint_(mathematics)). Its [feasible region](https://en.wikipedia.org/wiki/Feasible_region) is a [convex polytope](https://en.wikipedia.org/wiki/Convex_polytope), which is a set defined as the [intersection](https://en.wikipedia.org/wiki/Intersection_(mathematics)) of finitely many [half spaces](https://en.wikipedia.org/wiki/Half-space_(geometry)), each of which is defined by a linear inequality. Its objective function is a [real](https://en.wikipedia.org/wiki/Real_number)-valued [affine (linear) function](https://en.wikipedia.org/wiki/Affine_function) defined on this polyhedron. A linear programming [algorithm](https://en.wikipedia.org/wiki/Algorithm) finds a point in the polyhedron where this function has the smallest (or largest) value if such a point exists.

Linear programs are problems that can be expressed in [canonical form](https://en.wikipedia.org/wiki/Canonical_form) as



where **x** represents the vector of variables (to be determined), **c** and **b** are [vectors](https://en.wikipedia.org/wiki/Vector_space) of (known) coefficients, *A* is a (known) [matrix](https://en.wikipedia.org/wiki/Matrix_(mathematics)) of coefficients, and $ (\cdot )^{\mathrm {T} } $ is the [matrix transpose](https://en.wikipedia.org/wiki/Matrix_transpose). The expression to be maximized or minimized is called the [objective function](https://en.wikipedia.org/wiki/Objective_function) (**c**T**x** in this case). The inequalities *A***x** ≤ **b** and **x** ≥ **0** are the constraints which specify a [convex polytope](https://en.wikipedia.org/wiki/Convex_polytope) over which the objective function is to be optimized. In this context, two vectors are [comparable](https://en.wikipedia.org/wiki/Comparability) when they have the same dimensions. If every entry in the first is less-than or equal-to the corresponding entry in the second, then it can be said that the first vector is less-than or equal-to the second vector.

Linear programming can be applied to various fields of study. It is widely used in mathematics, and to a lesser extent in business, [economics](https://en.wikipedia.org/wiki/Economics), and for some engineering problems. Industries that use linear programming models include transportation, energy, telecommunications, and manufacturing. It has proven useful in modeling diverse types of problems in [planning](https://en.wikipedia.org/wiki/Automated_planning_and_scheduling), [routing](https://en.wikipedia.org/wiki/Routing), [scheduling](https://en.wikipedia.org/wiki/Scheduling_(production_processes)), [assignment](https://en.wikipedia.org/wiki/Assignment_problem), and design.