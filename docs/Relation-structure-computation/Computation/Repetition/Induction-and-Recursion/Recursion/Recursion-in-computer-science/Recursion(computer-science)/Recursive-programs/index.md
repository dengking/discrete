## wikipedia [Recursion (computer science)](https://en.wikipedia.org/wiki/Recursion_(computer_science)) # Recursive programs

### Recursive procedures

##### Factorial

##### Greatest common divisor

The [Euclidean algorithm](https://en.wikipedia.org/wiki/Euclidean_algorithm), which computes the [greatest common divisor](https://en.wikipedia.org/wiki/Greatest_common_divisor) of two integers, can be written recursively.

Function definition*:*

$ \gcd(x,y)={\begin{cases}x&{\mbox{if }}y=0\\\gcd(y,\operatorname {remainder} (x,y))&{\mbox{if }}y>0\\\end{cases}} $



[Pseudocode](https://en.wikipedia.org/wiki/Pseudocode) **(recursive):**

```
function gcd is:
input: integer x, integer y such that x > 0 and y >= 0


    1. if y is 0, return x
    2. otherwise, return [ gcd( y, (remainder of x/y) ) ]


end gcd
```



[Recurrence relation](https://en.wikipedia.org/wiki/Recurrence_relation) for greatest common divisor, where $ x\%y $ expresses the [remainder](https://en.wikipedia.org/wiki/Remainder) of $ x/y $:



$ \gcd(x,y)=\gcd(y,x\%y) $ if $ y\neq 0 $

$ \gcd(x,0)=x $

Computing the recurrence relation for x = 27 and y = 9:

```
gcd(27, 9)   = gcd(9, 27% 9)
             = gcd(9, 0)
             = 9	
```

The **recursive program** above is [tail-recursive](https://en.wikipedia.org/wiki/Tail-recursive); it is equivalent to an **iterative algorithm**, and the computation shown above shows the steps of evaluation that would be performed by a language that eliminates **tail calls**. Below is a version of the same algorithm using explicit iteration, suitable for a language that does not eliminate tail calls. By maintaining its state entirely in the variables *x* and *y* and using a looping construct, the program avoids making recursive calls and growing the call stack.

**Pseudocode (iterative):**

```
function gcd is:
input: integer x, integer y such that x >= y and y >= 0

    1. create new variable called remainder

    2. begin loop
          1. if y is zero, exit loop
          2. set remainder to the remainder of x/y
          3. set x to y
          4. set y to remainder
          5. repeat loop

    3. return x

end gcd
```

The iterative algorithm requires a temporary variable, and even given knowledge of the Euclidean algorithm it is more difficult to understand the process by simple inspection, although the two algorithms are very similar in their steps.

##### Towers of Hanoi

*Main article:* [Towers of Hanoi](https://en.wikipedia.org/wiki/Towers_of_Hanoi)

The Towers of Hanoi is a mathematical puzzle whose solution illustrates recursion.[[6\]](https://en.wikipedia.org/wiki/Recursion_(computer_science)#cite_note-6)[[7\]](https://en.wikipedia.org/wiki/Recursion_(computer_science)#cite_note-7) There are three pegs which can hold stacks of disks of different diameters. A larger disk may never be stacked on top of a smaller. Starting with *n* disks on one peg, they must be moved to another peg one at a time. What is the smallest number of steps to move the stack?



*Function definition*:



$ \operatorname {hanoi} (n)={\begin{cases}1&{\mbox{if }}n=1\\2\cdot \operatorname {hanoi} (n-1)+1&{\mbox{if }}n>1\\\end{cases}} $





*Recurrence relation for hanoi*:

$ h_{n}=2h_{n-1}+1 $

$ h_{1}=1 $

**Computing the recurrence relation for n = 4:**

```
hanoi(4)     = 2*hanoi(3) + 1
             = 2*(2*hanoi(2) + 1) + 1
             = 2*(2*(2*hanoi(1) + 1) + 1) + 1
             = 2*(2*(2*1 + 1) + 1) + 1
             = 2*(2*(3) + 1) + 1
             = 2*(7) + 1
             = 15
```

Example implementations:







##### Binary search



The [binary search](https://en.wikipedia.org/wiki/Binary_search) algorithm is a method of searching a [sorted array](https://en.wikipedia.org/wiki/Sorted_array) for a single element by cutting the array in half with each recursive pass. The trick is to pick a midpoint near the center of the array, compare the data at that point with the data being searched and then responding to one of three possible conditions: the data is found at the midpoint, the data at the midpoint is greater than the data being searched for, or the data at the midpoint is less than the data being searched for.

Recursion is used in this algorithm because with each pass a new array is created by cutting the old one in half. The binary search procedure is then called recursively, this time on the new (and smaller) array. Typically the array's size is adjusted by manipulating a beginning and ending index. The algorithm exhibits a logarithmic order of growth because it essentially divides the problem domain in half with each pass.

Example implementation of binary search in C:

```c
 /*
  Call binary_search with proper initial conditions.

  INPUT:
    data is an array of integers SORTED in ASCENDING order,
    toFind is the integer to search for,
    count is the total number of elements in the array

  OUTPUT:
    result of binary_search

 */
 int search(int *data, int toFind, int count)
 {
    //  Start = 0 (beginning index)
    //  End = count - 1 (top index)
    return binary_search(data, toFind, 0, count-1);
 }

 /*
   Binary Search Algorithm.

   INPUT:
        data is a array of integers SORTED in ASCENDING order,
        toFind is the integer to search for,
        start is the minimum array index,
        end is the maximum array index
   OUTPUT:
        position of the integer toFind within array data,
        -1 if not found
 */
 int binary_search(int *data, int toFind, int start, int end)
 {
    //Get the midpoint.
    int mid = start + (end - start)/2;   //Integer division

    //Stop condition.
    if (start > end)
       return -1;
    else if (data[mid] == toFind)        //Found?
       return mid;
    else if (data[mid] > toFind)         //Data is greater than toFind, search lower half
       return binary_search(data, toFind, start, mid-1);
    else                                 //Data is less than toFind, search upper half
       return binary_search(data, toFind, mid+1, end);
 }
```





#### Recursive data structures (structural recursion)

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



写递归函数的核心在于把我递归的本质：自顶向下，只有子问题都解了，才能够解上一层的问题。使用系统堆栈来实现该过程，因为系统堆栈能够不断地按照递归的顺序进行入栈，直到达到最小的子问题，从而将子问题解决，然后出栈，然后解决上一层子问题，直至最顶层的问题解决了；

每个递归调用都是一条直线，如果递归函数中，出现了两次递归调用，则就是两条线了；

对于有递归性质的问题或者结构，我们可以按照上述递归的思想去编写程序。当谈及需要验证或者模拟递归函数的执行过程的时候，就需要从相反的方向来解决问题了，我们需要从底向上来执行。