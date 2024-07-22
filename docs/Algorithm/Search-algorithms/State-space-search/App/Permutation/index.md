# Permutation 



## wikipedia [Permutation](https://en.wikipedia.org/wiki/Permutation) 



### [Permutations in computing](https://en.wikipedia.org/wiki/Permutation#Permutations_in_computing)



## Parity of a permutation

在wikipedia [Leibniz formula for determinants](https://en.wikipedia.org/wiki/Leibniz_formula_for_determinants) 中有如下内容:

> 
> $$
> \det(A)=\sum _{\tau \in S_{n}}\operatorname {sgn}(\tau )\prod _{i=1}^{n}a_{i,\,\tau (i)}=\sum _{\sigma \in S_{n}}\operatorname {sgn}(\sigma )\prod _{i=1}^{n}a_{\sigma (i),\,i}
> $$
> where ![\operatorname {sgn} ](https://wikimedia.org/api/rest_v1/media/math/render/svg/ec838dfd8a4a659b2877f93a6b53f22fc7777d07) is the [sign function](https://en.wikipedia.org/wiki/Even_and_odd_permutations) of [permutations](https://en.wikipedia.org/wiki/Permutation) in the [permutation group](https://en.wikipedia.org/wiki/Permutation_group) ![S_{n}](https://wikimedia.org/api/rest_v1/media/math/render/svg/9f049ac28d4ac8097b625f9d71c1f22b2ebd1bc4), which returns ![+1](https://wikimedia.org/api/rest_v1/media/math/render/svg/d04cf05c67d41d9f39dabf6a90722ce860a76958) and ![-1](https://wikimedia.org/api/rest_v1/media/math/render/svg/704fb0427140d054dd267925495e78164fee9aac) for [even and odd permutations](https://en.wikipedia.org/wiki/Even_and_odd_permutations), respectively.

## Numbering permutations

> NOTE:
>
> 给排列进行编号

One way to represent **permutations** of *n* things is by an integer *N* with 0 ≤ *N* < *n*!, provided convenient methods are given to convert between the **number** and the **representation of a permutation as an ordered arrangement (sequence)**(这段话的意思是number和permutation的相互转换). This gives the most compact representation of arbitrary permutations, and in computing is particularly attractive when *n* is small enough that *N* can be held in a machine word:

- for 32-bit words this means *n* ≤ 12
- for 64-bit words this means *n* ≤ 20. 

The conversion can be done via the intermediate form of a sequence of numbers $d_n, d_{n-1, \dots ,d_2, d_1}$, where $d_i$ is a non-negative integer less than *i* (one may omit *d*1, as it is always 0, but its presence makes the subsequent conversion to a permutation easier to describe): 

1. The first step then is to simply express *N* in the *[factorial number system](https://en.wikipedia.org/wiki/Factorial_number_system)*, which is just a particular [mixed radix](https://en.wikipedia.org/wiki/Mixed_radix) representation, where, for numbers less than *n*!, the bases (place values or multiplication factors) for successive digits are (*n* − 1)!, (*n* − 2)!, ..., 2!, 1!. 
2. The second step interprets this sequence as a [Lehmer code](https://en.wikipedia.org/wiki/Lehmer_code) or (almost equivalently) as an inversion table.



### Lehmer code



#### gpt Lehmer code

The **Lehmer code**, also known as the **Lehmer sequence**, is a way of encoding permutations. It is named after the mathematician Derrick Henry Lehmer. The Lehmer code for a permutation is a sequence of integers that uniquely represents the permutation's position in the lexicographic ordering of all permutations of a given size.

To compute the **Lehmer code** for a permutation, you follow these steps:

1. For each position `i` in the permutation (starting from the leftmost position), count the number of elements to the right of `i` that are smaller than the element at `i`. This count is the `i`-th element of the **Lehmer code**.
2. The **Lehmer code** is then a sequence of these counts.

> NOTE:
>
> 1. 这种count，有什么意义？

For example, consider the **permutation** `[3, 1, 4, 2]` of the set `{1, 2, 3, 4}`. The **Lehmer code** for this permutation is computed as follows:

- Position 1: The value is `3`, and there are two elements to the right that are smaller (`1` and `2`), so the first element of the **Lehmer code** is `2`.
- Position 2: The value is `1`, and there are no elements to the right that are smaller, so the second element of the **Lehmer code** is `0`.
- Position 3: The value is `4`, and there is one element to the right that is smaller (`2`), so the third element of the **Lehmer code** is `1`.
- Position 4: The value is `2`, and there are no elements to the right that are smaller, so the fourth element of the **Lehmer code** is `0`.

Thus, the **Lehmer code** for the permutation `[3, 1, 4, 2]` is `[2, 0, 1, 0]`.

The **Lehmer code** can also be used to convert back to the original permutation, and it is useful in various combinatorial algorithms, including ranking and unranking permutations.

- **Lehmer code => Permutation**: The function `lehmer_code(permutation: List)` iterates through each element of the permutation, counts the number of elements to the right that are smaller, and stores these counts in the corresponding positions of the Lehmer code array.
- **Permutation => Lehmer code**: The function `permutation_from_lehmer_code` starts with a sorted list of numbers from 1 to `n` and then applies the **Lehmer code** to swap elements and reconstruct the original permutation.

```python
from typing import *


def lehmer_code(permutation: List):
    n = len(permutation)
    lehmer_code = [0] * n

    for i in range(n):
        count = 0
        for j in range(i + 1, n):
            if permutation[i] > permutation[j]:
                count += 1
        lehmer_code[i] = count

    return lehmer_code


def permutation_from_lehmer_code(code: List):
    n = len(code)
    permutation = list(range(1, n + 1))

    for i in range(n):
        count = code[i]
        for j in range(i + 1, n):
            if permutation[j] > permutation[i]:
                count -= 1
            if count == 0:
                permutation[i], permutation[j] = permutation[j], permutation[i]
                break

    return permutation


if __name__ == '__main__':
    # Example usage:
    permutation = [3, 1, 4, 2]
    code = lehmer_code(permutation)
    print("Permutation:", permutation)
    print("Lehmer code:", code)
    permutation = permutation_from_lehmer_code(code)
    print("Lehmer code:", code)
    print("Permutation:", permutation)

```


