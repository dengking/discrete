# Graph representation



## 维基百科[Graph (abstract data type)#Representations](https://en.wikipedia.org/wiki/Graph_(abstract_data_type))



## [Representing weighted graphs](http://www.mathcs.emory.edu/~cheung/Courses/171/Syllabus/11-Graph/weighted.html)

> NOTE: 如何来表示一个weighted graph？正如在Summary章节所述，即需要考虑structure也需要考虑property（也就是这里说的weight）

### Weighted graphs

**Weighted graph** = a **graph** whose **edges** have **weights**

![](./weight01.gif)



The **weight** of an **edge** can **represent**:

- **Cost or distance**
- **Capacity** = the **maximim amount of flow** that can be **transported** from one place to another

#### Representing weighted graphs using an adjacency list

Each **node** in the **adjacency graph** will **contain:**

- A **neighbor node ID** (this **field** was **already** discussed previously)
- A `cost` field (this field is new)

##### Example

**Graph:**

![](./weight01 (1).gif)

**Representation:**

![](./weight02.gif)



Class used to represent (define) **edges**:

```java


   /* ==========================================
      Edges is stored as Node of a linked list
      ========================================== */         
   public class Edge
   {
      int  NodeID;     // The neighbor node
      double Weight;   // Weight of edge
      Node next;       // Link variable
   }  
```



Class used to represent (define) a graph:

```java
   /* =============================================================
      The graph is an array of Edge (Edge[i] = all edges of node i)
      ============================================================== */         
   public class Graph
   {
       public Edge[] graph;    // Array of Edges      
   }
```

#### Representing weighted graphs using an adjacency array

Representing a weighted graph using an adjacency array:

- If there is no edge between node i and node j, the value of the array element `a[i][j] = some very large value`

- Otherwise, `a[i][j]` is a floating value that is equal to the weight of the `edge (i, j)`

Example:

![](./weight01 (2).gif)

Representation:

```

           0  1  2  3  4  5  6  7  8
         +-                         -+
         | *  3  *  2  *  *  *  *  4 |    // 0         
         | 3  *  *  *  *  *  *  4  * |    // 1
         | *  *  *  6  *  1  *  2  * |    // 2
         | 2  *  6  *  1  *  *  *  * |    // 3
    M =  | *  *  *  1  *  *  *  *  8 |    // 4
         | *  *  1  *  *  *  8  *  * |    // 5
         | *  *  *  *  *  8  *  *  * |    // 6
         | *  4  2  *  *  *  *  *  * |    // 7
         | 4  *  *  *  8  *  *  *  * |    // 8
         +-                         -+

                   * = a very large value (infinite)
```



Class used to represent a graph using an adjacency matrix:

```java
   public class Graph
   {

      /* =======================================
         The edges of the graph
         ======================================= */
      double[][] M;      // M[i][j] = weight of edge (i,j)      

      ...
   }
```



## [Representing graphs](https://www.khanacademy.org/computing/computer-science/algorithms/graph-representation/a/representing-graphs)



## Summary

正如一个web page涉及structure和是type，一个graph涉及到structure和property（edge的property和vertex的property），所以graph representation就涉及两者。

关于graph representation，可以阅读boost graph library。

### 从relation的角度来分析graph representation

使用graph来表示relation，relation是有属性的，所以graph需要能够表示出这些relation的属性，各种algorithm其实就是基于relation和relation的属性的。

这就是graph、representation、property、algorithm。

