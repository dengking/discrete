# Cycle in graph

graph是允许存在cycle的，这就引出了一系列问题:

- 如何判断graph中是否存在cycle: cycle detection
- 对于存在cycle的graph，在对它进行traverse的时候，如何避免陷入dead loop: 这在 `Traverse-graph` 章节中进行介绍
- 对于存在cycle的graph，如何找到最大的cycle: `Max-cycle` 