# architecture-performance [Forward and reverse star representation of a digraph](https://www.architecture-performance.fr/ap_blog/forward-and-reverse-star-representation-of-a-digraph/)

In this Python notebook, we are going to focus on a graph representation of directed graphs : the forward star representation [and its opposite, the reverse star]. The motivation here is to access a network topology and associated data efficiently, without using a large amount of memory space. In many **shortest path algorithms**, one needs to quickly access the outgoing or incoming edges of the graph vertices, as well as the associated edge attributes. This is why the data structure used to represent the graph is very important regarding the efficiency of graph algorithms. Note that we only consider static graphs here, where the topology does not change.