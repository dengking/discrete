# Recursive program



写递归函数的核心在于把我递归的本质：自顶向下，只有子问题都解了，才能够解上一层的问题。使用系统堆栈来实现该过程，因为系统堆栈能够不断地按照递归的顺序进行入栈，直到达到最小的子问题，从而将子问题解决，然后出栈，然后解决上一层子问题，直至最顶层的问题解决了；

每个递归调用都是一条直线，如果递归函数中，出现了两次递归调用，则就是两条线了；

对于有递归性质的问题或者结构，我们可以按照上述递归的思想去编写程序。当谈及需要验证或者模拟递归函数的执行过程的时候，就需要从相反的方向来解决问题了，我们需要从底向上来执行。



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


