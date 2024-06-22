# Set theory

“set”是数学的基石，数学中的大部分概念都是建立于set之上的。

很多math object（数学对象）的本质都是：

- relation
- function
- ......



set是枚举、概括。

## wikipedia [Set theory](https://en.wikipedia.org/wiki/Set_theory)



## Set 

### wikipedia [Set (mathematics)](https://en.wikipedia.org/wiki/Set_(mathematics))

There is a unique set with no elements, called the [empty set](https://en.wikipedia.org/wiki/Empty_set); a set with a single element is a [singleton](https://en.wikipedia.org/wiki/Singleton_(mathematics)).



#### Basic operations

##### Difference

[![img](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e6/Venn0100.svg/220px-Venn0100.svg.png)](https://en.wikipedia.org/wiki/File:Venn0100.svg)

The **set difference** *A* \ *B*

> NOTE:
>
> 一. You can perform a set difference using the `-` operator or the `.difference()` method. Here's how you can use both:
>
> Using the `-` operator:
>
> ```python
> set1 = {1, 2, 3, 4}
> set2 = {3, 4, 5, 6}
> 
> diff = set1 - set2
> print(diff)  # Output will be {1, 2}
> ```
>
> Using the `.difference()` method:
>
> ```python
> set1 = {1, 2, 3, 4}
> set2 = {3, 4, 5, 6}
> 
> diff = set1.difference(set2)
> print(diff)  # Output will be {1, 2}
> ```
>
> 

##### Symmetric difference

> NOTE:
>
> 一、对称差，两个集合中，只属于其中一个集合的元素



[![img](https://upload.wikimedia.org/wikipedia/commons/thumb/4/46/Venn0110.svg/220px-Venn0110.svg.png)](https://en.wikipedia.org/wiki/File:Venn0110.svg)

The **symmetric difference** of *A* and *B*

> NOTE:
>
> 一. application:
>
> - stat the diff cnt of characters of two string
>
>   In Python, you can find the symmetric difference between two sets using the `^` operator or the `.symmetric_difference()` method. Here's how you can do it:
>
>   Using the `^` operator:
>
>   ```python
>   set1 = {1, 2, 3, 4}
>   set2 = {3, 4, 5, 6}
>   
>   sym_diff = set1 ^ set2
>   print(sym_diff)  # Output will be {1, 2, 5, 6}
>   ```
>
>   Using the `.symmetric_difference()` method:
>
>   ```python
>   set1 = {1, 2, 3, 4}
>   set2 = {3, 4, 5, 6}
>   
>   sym_diff = set1.symmetric_difference(set2)
>   print(sym_diff)  # Output will be {1, 2, 5, 6}
>   ```
>
>   Using the `.symmetric_difference()` method:
>
>   ```python
>   set1 = {1, 2, 3, 4}
>   set2 = {3, 4, 5, 6}
>   
>   sym_diff = set1.symmetric_difference(set2)
>   print(sym_diff)  # Output will be {1, 2, 5, 6}
>   ```
>
>   