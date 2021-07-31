# Generate permutation

"generate permutation" 即 "生成排列"。



## wikipedia [Permutations in computing](https://en.wikipedia.org/wiki/Permutation#Permutations_in_computing) # Algorithms to generate permutations

In computing it may be required to generate permutations of a given sequence of values. The methods best adapted to do this depend on whether one wants some randomly chosen permutations, or all permutations, and in the latter case if a specific **ordering** is required. Another question is whether possible **equality** among entries in the given sequence is to be taken into account; if so, one should only generate distinct multiset permutations of the sequence.

An obvious way to generate permutations of *n* is to generate values for the **Lehmer code** (possibly using the [factorial number system](https://en.wikipedia.org/wiki/Factorial_number_system) representation of integers up to *n*!), and convert those into the corresponding permutations. However, the latter step, while straightforward, is hard to implement efficiently, because it requires *n* operations each of selection from a sequence and deletion from it, at an arbitrary position; of the obvious representations of the sequence as an [array](https://en.wikipedia.org/wiki/Array_data_structure) or a [linked list](https://en.wikipedia.org/wiki/Linked_list), both require (for different reasons) about *n*2/4 operations to perform the conversion. With *n* likely to be rather small (especially if generation of all permutations is needed) that is not too much of a problem, but it turns out that both for random and for systematic generation there are simple alternatives that do considerably better. For this reason it does not seem useful, although certainly possible, to employ a special data structure that would allow performing the conversion from Lehmer code to permutation in [*O*(*n* log *n*)](https://en.wikipedia.org/wiki/Big_O_notation) time.

> NOTE: 
>
> 生成n的排列的一个明显的方法是生成Lehmer代码的值(可能使用到n的整数的阶乘数字系统表示)，并将它们转换成相应的排列。
> 但是，后面的步骤虽然简单，但是很难有效地实现，因为它需要在任意位置对序列进行n次选择和删除操作;
> 序列的明显表示形式为数组或链表，两者都需要(出于不同的原因)大约n2/4操作来执行转换。
> n可能很小(特别是如果需要生成所有排列)，这不是什么大问题，但事实证明，无论是随机生成还是系统生成，都有简单的替代方法可以做得更好。
> 因此，使用一种特殊的数据结构，允许在O(n log n)时间内执行从Lehmer代码到置换的转换，虽然这种数据结构肯定是可行的，但似乎并不有用。
>
> 



## TODO



geeksforgeeks [Write a program to print all permutations of a given string](https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/)



geeksforgeeks [Iterative program to generate distinct Permutations of a String](https://www.geeksforgeeks.org/iterative-program-to-generate-distinct-permutations-of-a-string/)



geeksforgeeks [Print all possible combinations of r elements in a given array of size n](https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/)



geeksforgeeks [Print all possible strings of length k that can be formed from a set of n characters](https://www.geeksforgeeks.org/print-all-combinations-of-given-length/)



geeksforgeeks [Write a program to print all permutations of a given string](https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/)



stackoverflow [Generating all permutations of a given string](https://stackoverflow.com/questions/4240080/generating-all-permutations-of-a-given-string)



stackoverflow [Generate list of all possible permutations of a string](https://stackoverflow.com/questions/361/generate-list-of-all-possible-permutations-of-a-string)

