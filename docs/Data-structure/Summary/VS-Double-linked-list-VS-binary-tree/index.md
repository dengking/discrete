# Double linked list and tree

double和binary都是2，两者的节点都可以使用如下struct来表示

```c
struct Node{
    void *value;
    struct Node* next; // left
    struct Node* prev; // right
}
```

https://stackoverflow.com/questions/11392922/what-is-the-difference-between-node-structures-of-double-linked-list-and-binary

https://cs.stackexchange.com/questions/74372/is-binary-tree-just-a-two-dimension-doubly-linked-list


https://www.ritambhara.in/convert-a-binary-tree-to-a-doubly-linked-list/


在https://en.wikipedia.org/wiki/Linked_list#Related_data_structures有提及这个问题


## binary search tree 退化为 linked list
binary search tree是可能退化为linked list的；

