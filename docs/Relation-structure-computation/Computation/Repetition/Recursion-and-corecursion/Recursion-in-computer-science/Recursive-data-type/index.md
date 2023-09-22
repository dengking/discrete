# Recursive data type、Recursive data structure

本文是wikipedia [Recursive data type](https://en.wikipedia.org/wiki/Recursive_data_type)的阅读笔记。

如果将各种data structure看做是一种类型，那些具备 [**递归性**](https://en.wikipedia.org/wiki/Recursive) 的data structure，就是本节标题所述“[recursive data type](https://en.wikipedia.org/wiki/Recursive_data_type)”，这个术语表达了数据类型的递归性特征。对于recursive data type，都可以给出它的[recursive definition](https://en.wikipedia.org/wiki/Recursive_definition)。

wikipedia [Recursive data type](https://en.wikipedia.org/wiki/Recursive_data_type)中关于它的描述是使用的wikipedia [Recursive definition](https://en.wikipedia.org/wiki/Recursive_definition)中“recursively defined set”的描述方式。

最最典型的recursive data type就是：

1、[list](https://en.wikipedia.org/wiki/List_(computing))

2、[tree](https://en.wikipedia.org/wiki/Tree_(data_structure))

在维基百科[Recursive data type](https://en.wikipedia.org/wiki/Recursive_data_type)的[Example](https://en.wikipedia.org/wiki/Recursive_data_type#Example)节给出了上述两种recursive data type的[recursive definition](https://en.wikipedia.org/wiki/Recursive_definition)。

除此之外，下面的也是Recursive data type:

1、multiple level pointer

2、multiple level array

[Recursive data type](https://en.wikipedia.org/wiki/Recursive_data_type)和[Structural induction](https://en.wikipedia.org/wiki/Structural_induction)紧密相关；





## wikipedia [Recursion (computer science)](https://en.wikipedia.org/wiki/Recursion_(computer_science)) # Recursive data structures (structural recursion)

*Main article:* [Recursive data type](https://en.wikipedia.org/wiki/Recursive_data_type)



An important application of recursion in computer science is in defining dynamic **data structures** such as [lists](https://en.wikipedia.org/wiki/List_(abstract_data_type)) and [trees](https://en.wikipedia.org/wiki/Tree_(data_structure)). **Recursive data structures** can dynamically grow to a theoretically infinite size in response to runtime requirements; in contrast, the size of a static array must be set at compile time.



> "**Recursive algorithms** are particularly appropriate when the underlying problem or the data to be treated are defined in recursive terms."[[9\]](https://en.wikipedia.org/wiki/Recursion_(computer_science)#cite_note-9)

The examples in this section illustrate what is known as "[structural recursion](https://en.wikipedia.org/wiki/Structural_recursion)". This term refers to the fact that the **recursive procedures** are acting on data that is defined recursively.

> As long as a programmer derives the template from a data definition, functions employ structural recursion. That is, the recursions in a function's body consume some immediate piece of a given compound value.[[5\]](https://en.wikipedia.org/wiki/Recursion_(computer_science)#cite_note-Felleisen_2002_108-5)

##### Linked lists

*Main article:* [Linked list](https://en.wikipedia.org/wiki/Linked_list)

Below is a C definition of a linked list node structure. Notice especially how the node is defined in terms of itself. The "next" element of *struct node* is a pointer to another *struct node*, effectively creating a list type.

```c
struct node
{
  int data;           // some integer data
  struct node *next;  // pointer to another struct node
};
```

Because the *struct node* data structure is defined **recursively**, procedures that operate on it can be implemented naturally as **recursive procedures**. The *list_print* procedure defined below walks down the list until the list is empty (i.e., the list pointer has a value of NULL). For each node it prints the data element (an integer). In the C implementation, the list remains unchanged by the *list_print* procedure.

```c
void list_print(struct node *list)
{
    if (list != NULL)               // base case
    {
       printf ("%d ", list->data);  // print integer data followed by a space
       list_print (list->next);     // recursive call on the next node
    }
}
```



##### Binary trees

*Main article:* [Binary tree](https://en.wikipedia.org/wiki/Binary_tree)

Below is a simple definition for a binary tree node. Like the node for linked lists, it is defined in terms of itself, recursively. There are two self-referential pointers: left (pointing to the left sub-tree) and right (pointing to the right sub-tree).

```c
struct node
{
  int data;            // some integer data
  struct node *left;   // pointer to the left subtree
  struct node *right;  // point to the right subtree
};
```

Operations on the tree can be implemented using recursion. Note that because there are two self-referencing pointers (left and right), tree operations may require two recursive calls:

```c
// Test if tree_node contains i; return 1 if so, 0 if not.
int tree_contains(struct node *tree_node, int i) {
    if (tree_node == NULL)
        return 0;  // base case
    else if (tree_node->data == i)
        return 1;
    else
        return tree_contains(tree_node->left, i) || tree_contains(tree_node->right, i);
}
```



At most two recursive calls will be made for any given call to *tree_contains* as defined above.



```C
// Inorder traversal:
void tree_print(struct node *tree_node) {
        if (tree_node != NULL) {                  // base case
                tree_print(tree_node->left);      // go left
                printf("%d ", tree_node->data);   // print the integer followed by a space
                tree_print(tree_node->right);     // go right
        }
}
```



```
                              5
                        3              7
                  2          4    6            8
```

```
P(5)
    P(3)
        P(2)
            P(NULL) return 
            printf(2)
            P(NULL) return
        printf(3)
        p(4)
            P(NULL) return 
            printf(4)
            P(NULL) return
            
```

