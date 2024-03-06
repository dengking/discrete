# [CS166-Graph connectivity](https://web.stanford.edu/class/cs166/) 

[wikipedia-Dynamic connectivity](https://en.wikipedia.org/wiki/Dynamic_connectivity)

> In [computing](https://en.wikipedia.org/wiki/Computing) and [graph theory](https://en.wikipedia.org/wiki/Graph_theory), a **dynamic connectivity** structure is a data structure that dynamically maintains information about the connected components of a graph.
>
> The set *V* of vertices of the graph is fixed, but the set *E* of edges can change. The three cases, in order of difficulty, are:
>
> - Edges are only added to the graph (this can be called *incremental connectivity*);
> - Edges are only deleted from the graph (this can be called *decremental connectivity*);
> - Edges can be either added or deleted (this can be called *fully dynamic connectivity*).



## Disjoint Set Forests(Lecture-14)

May 23

Checking if two nodes are connected in a graph (whether there's a path between them) is a very easy problem to solve if the graph is given to you in advance. But what if the graph can change by having edges added in dynamically? This problem requires a more clever solution, one that's trivial to code up but whose analysis is one of the most surprising of the quarter.

Slides:

- [Lecture Slides](https://web.stanford.edu/class/cs166/lectures/14/Slides14.pdf)
- [Condensed Slides](https://web.stanford.edu/class/cs166/lectures/14/Small14.pdf)

Readings:

- CLRS, Chapter 21.
- Seidel, Raimund and Sharir, Micha. [Top-Down Analysis of Path Compression](https://web.stanford.edu/class/cs166/restricted/papers/SeidelSharirUnionFind.pdf).





## Euler Tour Trees(Lecture-15)

May 25

The **dynamic connectivity** problem is the following: maintain connectivity information about a graph as edges are added and deleted. (Contrast this with what **disjoint-set forests** do, where edges can only be added.) In the restricted case of maintaining a forest, there's a surprisingly elegant and versatile data structure for this problem: the Euler tour tree, based on a creative perspective for representing a tree as a sequence.

Slides:

- [Lecture Slides](https://web.stanford.edu/class/cs166/lectures/15/Slides15.pdf)
- [Condensed Slides](https://web.stanford.edu/class/cs166/lectures/15/Small15.pdf)

Readings:

- Tarjan, Robert. [Dynamic trees as search trees via Euler tours, applied to the network simplex algorithm](https://web.stanford.edu/class/cs166/restricted/papers/TarjanEulerTourTrees.pdf).





## Holm Forests(Lecture-16)

May 30

Maintaining connectivity information in a fully dynamic graph efficiently is a challenge. Today we see one data structure that elegantly solves the problem, giving excellent amortized time bounds.

Slides:

- [Lecture Slides](https://web.stanford.edu/class/cs166/lectures/16/Slides16.pdf)
- [Condensed Slides](https://web.stanford.edu/class/cs166/lectures/16/Small16.pdf)

Readings:

- Holm, Jacob et al. [Poly-logarithmic deterministic fully-dynamic algorithms for connectivity, minimum spanning tree, 2-edge, and biconnectivity.](https://web.stanford.edu/class/cs166/restricted/papers/HolmEtAlDynamicConnectivity.pdf)