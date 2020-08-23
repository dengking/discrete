# Search: Cost & Heuristics

graph search algorithm是非常之多的，需要首先建立起一个完整的视图。

## [Search: Cost & Heuristics](https://courses.cs.washington.edu/courses/cse473/14au/slides/03-hsearch.pdf)

### Search thru a Problem Space / State Space 

#### Input

- Set of states
- Operators [and costs]
- Start state
- Goal state [test] 

#### Output

- Path: start ⇒ a state satisfying goal test 
- [May require shortest path] 
- [Sometimes just need state passing test] 



### Search Methods 

#### Blind search

- Depth first search (DFS) 
- Breadth first search (BFS)
- Iterative deepening depth-first search (IDS) 

#### Heuristic search

- Best first search
- Uniform cost search (UCS) 
- Greedy search 
- `A*` 
- Iterative Deepening `A*` (`IDA*`) 
- Beam search 
- Hill climbing 



### Depth First Search 

