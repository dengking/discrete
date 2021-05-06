# Monotonic stack

一、由于栈的操作只有`push`、`pop`、`top`，无法进行swap，因此对于当使用栈进行排序的时候，一般采用的是如下方式: 

1、坚持"monotonic order"，即保持当前stack中的element的"monotonic order"，一旦，待`push`的element和`top`之间不满足"monotonic order"，那么就需要将当前stack中待`push`的element不满足"monotonic order"的元素全部"pop"掉。

