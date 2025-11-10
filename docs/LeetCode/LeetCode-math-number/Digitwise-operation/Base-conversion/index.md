# Base conversion(进制转换)

## Base-n representation of a integer in decimal

> NOTE: 将10进制数转换为任意进制数、获得10进制数的n进制表示
> 
> 对应base-n，它的digit的范围是0~n-1
> 
> 这个算法的理解可以基于 number=>digits(不调整进制)，不断地进行剥离
> 
> 它不断地除以base，肯定首先得到的是最低位($base^0$)，然后得到次高位($base^1$)，
> 
> $base^2$, $\dots$ 

Let's explain the general algorithm and provide a Python implementation for **converting a decimal (base-10) integer to any base-n representation**.

---

### Algorithm Explanation

To convert a decimal integer to its base-n representation (where n ≥ 2):

**Steps:**

1. **Initialize** an empty list to store the digits.
2. **Repeat** until the number becomes 0:
   - Divide the number by n.
   - Record the remainder(余数) (which is a digit in base-n).
   - Update the number to the integer quotient of the division.
     - 翻译: 将该数值更新为此次除法运算的整数商
     - “integer quotient” 是数学与编程领域的固定术语，译为 “整数商”，即除法运算后舍去小数部分的结果（如 7÷2 的整数商为 3），区别于 “商”（quotient，可能含小数）
3. The collected remainders, when read in reverse order, give the base-n representation.

**Note**:  
For n > 10, you'll need to use letters ('A' for 10, 'B' for 11, etc.) for digits above 9.

---

### Example Conversion (base-16):

Convert decimal 30 to base 16:

- 30 ÷ 16 = 1 remainder 14 ⇒ 'E'
- 1 ÷ 16 = 0 remainder 1 ⇒ '1'
- Collect [E, 1] ⇒ Reverse to '1E'

So 30 (decimal) is '1E' in hexadecimal (base 16).

---

### Python Implementation

Here's a general function that works for any base (2 ≤ n ≤ 36):

```python
def decimal_to_base_n(n, base):
    if n == 0:
        return '0'
    digits = []
    symbols = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    while n > 0:
        digits.append(symbols[n % base])
        n = n // base
    return ''.join(reversed(digits))

# Example usage:
number = 30
for b in (2, 3, 8, 10, 16):
    print(f"Decimal {number} in base {b} is {decimal_to_base_n(number, b)}")
```

#### Output:

```
Decimal 30 in base 2 is 11110
Decimal 30 in base 3 is 1010
Decimal 30 in base 8 is 36
Decimal 30 in base 10 is 30
Decimal 30 in base 16 is 1E
```

### C++ implementation

```c
#include <iostream>
#include <string>
#include <algorithm>

// Converts a decimal number n to its base 'base' representation as a string
std::string decimal_to_base_n(int n, int base) {
    if (n == 0) return "0";
    std::string symbols = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string result;
    while (n > 0) {
        result += symbols[n % base];
        n /= base;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    int number = 30;
    for (int base : {2, 3, 8, 10, 16}) {
        std::cout << "Decimal " << number << " in base " << base << " is "
                  << decimal_to_base_n(number, base) << std::endl;
    }
    return 0;
}
```

---

### Summary of the algorithm

- Keep dividing by the target base.
- Write down each remainder.
- The base-n result is the remainders read in reverse.

Let me know if you need any tweaks or explanations for other cases (negative numbers, floating points, etc)!

## Convert decimal fraction(十进制小数) to its base-n number

The algorithm to convert a decimal fraction to any base-n is a direct generalization of the binary ("multiply by 2") algorithm.

Instead of multiplying by 2, you simply multiply by **n**.

### The Algorithm: "Multiply by n"

Let's say you want to convert a decimal fraction $F$ to its representation in base $n$. The goal is to find the digits $d_1, d_2, d_3, \dots$ such that:

$$
F = d_1 \times n^{-1} + d_2 \times n^{-2} + d_3 \times n^{-3} + \dots
$$

where each digit $d_i$ is an integer in the range $[0, n-1]$.

Here is the step-by-step algorithm:

1. **Start** with the decimal fraction you want to convert (e.g., `0.84375`). Let's call this `frac`.

2. **Multiply by n:** Calculate `frac * n`, where `n` is your target base.

3. **Extract the Integer Part:** The integer part of the result is the **next digit** of your base-n fraction.

4. **Keep the Fractional Part:** The fractional part of the result becomes your new `frac` for the next step.

5. **Repeat:** Go back to step 2 and repeat the process with the new `frac`.

6. **Stop:** The process stops when either:
   
   1. The fractional part becomes 0 (a terminating fraction).
   
   2. You reach a desired number of precision digits (for non-terminating fractions).

---

### Example Walkthrough: Convert 0.84375 (Decimal) to Base 8 (Octal)

Here, $n=8$.

| Step | Current Fraction | Multiply by 8                      | Integer Part (Octal Digit) | New Fraction | Octal Result So Far |
|:---- |:---------------- |:---------------------------------- |:-------------------------- |:------------ |:------------------- |
| 1    | 0.84375          | $0.84375 \times 8 = \mathbf{6}.75$ | **6**                      | 0.75         | `0.6`               |
| 2    | 0.75             | $0.75 \times 8 = \mathbf{6}.0$     | **6**                      | 0.0          | `0.66`              |

At Step 2, the new fractional part is 0.0, so we stop.

**Result:** The decimal `0.84375` is equivalent to `0.66` in base 8.

*Check: $(0.66)_8 = 6 \times 8^{-1} + 6 \times 8^{-2} = \frac{6}{8} + \frac{6}{64} = \frac{48}{64} + \frac{6}{64} = \frac{54}{64} = 0.84375$. Correct!*

### Example Walkthrough: Convert 0.7 (Decimal) to Base 16 (Hexadecimal)

Here, $n=16$. We'll need to represent digits greater than 9 with letters (A=10, B=11, C=12, ...).

| Step | Current Fraction | Multiply by 16                  | Integer Part (Hex Digit) | New Fraction | Hex Result So Far |
|:---- |:---------------- |:------------------------------- |:------------------------ |:------------ |:----------------- |
| 1    | 0.7              | $0.7 \times 16 = \mathbf{11}.2$ | **11 (B)**               | 0.2          | `0.B`             |
| 2    | 0.2              | $0.2 \times 16 = \mathbf{3}.2$  | **3**                    | 0.2          | `0.B3`            |
| 3    | 0.2              | $0.2 \times 16 = \mathbf{3}.2$  | **3**                    | 0.2          | `0.B33`           |

We see that the fractional part `0.2` repeats, so the digit `3` will repeat forever.

**Result:** The decimal `0.7` is the non-terminating fraction `0.B333...` in hexadecimal.

---

### Python Code Implementation

This Python function implements the generalized "Multiply by n" algorithm. It can handle bases up to 36 by using letters for digits greater than 9.

```python
def decimal_fraction_to_base_n(num, base, limit=32):
    """Converts the fractional part of a decimal number to its base-n representation.
    Args:
    num (float): The decimal number. The function will only consider its fractional part.
    base (int): The target base (e.g., 2 for binary, 8 for octal, 16 for hex).
    Must be between 2 and 36.
    limit (int): The maximum number of digits to generate after the point.

    Returns:

    str: The base-n representation of the fractional part, e.g., "0.101".

    """
    if not 2 <= base <= 36:
        raise ValueError("Base must be between 2 and 36.")

    # String of characters to represent digits from 0 to 35
    digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    # Isolate the fractional part of the number
    frac = num - int(num)
    if frac < 0:
        frac += 1
    if frac == 0:
        return "0.0"

    result = "0."
    # Loop until the fraction becomes 0 or we hit the precision limit
    while frac > 0:
        # Check if we have reached the precision limit
        if len(result) - 2 >= limit:
            print(f"Warning: Reached precision limit of {limit} digits. The fraction may be non-terminating.")
            break
        # Multiply by the base to shift the next digit into the integer part
        frac *= base
        # The integer part is our next digit
        digit_value = int(frac)
        # Append the character representation of the digit
        result += digits[digit_value]
        # Subtract the integer part to get the new fraction for the next iteration
        frac -= digit_value
    return result


# --- Examples ---


# 1. Decimal 0.84375 to Octal (Base 8) - Terminating
dec_val_1 = 0.84375
base_1 = 8
result_1 = decimal_fraction_to_base_n(dec_val_1, base_1)
print(f"Decimal {dec_val_1} in base {base_1} is: {result_1}")

# Expected output: Decimal 0.84375 in base 8 is: 0.66


# 2. Decimal 0.7 to Hexadecimal (Base 16) - Non-terminating
dec_val_2 = 0.7
base_2 = 16
result_2 = decimal_fraction_to_base_n(dec_val_2, base_2, limit=10)
print(f"Decimal {dec_val_2} in base {base_2} is: {result_2}")

# Expected output: Decimal 0.7 in base 16 is: 0.B333333333


# 3. Decimal 0.1 to Binary (Base 2) - Non-terminating

dec_val_3 = 0.1
base_3 = 2
result_3 = decimal_fraction_to_base_n(dec_val_3, base_3, limit=16)
print(f"Decimal {dec_val_3} in base {base_3} is: {result_3}")

# Expected output: Decimal 0.1 in base 2 is: 0.0001100110011001


# 4. Decimal 0.5 to Base 3 - Non-terminating

dec_val_4 = 0.5
base_4 = 3
result_4 = decimal_fraction_to_base_n(dec_val_4, base_4, limit=10)
print(f"Decimal {dec_val_4} in base {base_4} is: {result_4}")
# Expected output: Decimal 0.5 in base 3 is: 0.1111111111
```

## Why converting decimal fraction to its base-n number will cause infinite repeating decimal

Of course. This is a fantastic question that gets to the heart of how number systems work. The reason a simple, terminating decimal in one base can become an infinite, repeating decimal in another base is all about **prime factors**.

Let's break it down, starting with our familiar base-10 system.

### The Rule for Terminating Decimals in Base-10

First, what *is* a terminating decimal like `0.5` or `0.375`? It's just a fraction where the denominator(分母) is a power of 10.

* $0.5 = \frac{5}{10}$
* $0.375 = \frac{375}{1000}$
* $0.12 = \frac{12}{100}$

Now, let's look at the prime factors of the base, which is 10.


$$
10 = 2 \times 5
$$



This means any power of 10 will only have prime factors of 2 and 5.


$$
1000 = 10^3 = (2 \times 5)^3 = 2^3 \times 5^3
$$

A fraction $\frac{p}{q}$ (in its simplest form) can only be written as a terminating decimal in base-10 if its denominator `q` can be turned into a power of 10 by multiplying it by some integer. This is only possible if the prime factors of `q` are **exclusively 2s and/or 5s**.

**Examples in Base-10:**

* $\frac{1}{8}$: The denominator is $8 = 2^3$. The only prime factor is 2. **Result: Terminates** ($0.125$).
* $\frac{3}{20}$: The denominator is $20 = 2^2 \times 5$. The prime factors are 2 and 5. **Result: Terminates** ($0.15$).
* $\frac{1}{3}$: The denominator is $3$. The prime factor is 3, which is **not** 2 or 5. It's impossible to multiply 3 by any integer to get a power of 10. **Result: Repeats** ($0.333...$).
* $\frac{1}{7}$: The denominator is $7$. The prime factor is 7, which is **not** 2 or 5. **Result: Repeats** ($0.142857142857...$).

### Generalizing the Rule to Any Base-n

We can now generalize this rule for any number base `n`.

> A fraction $\frac{p}{q}$ will have a **terminating** representation in base-`n` if and only if all the prime factors of its denominator `q` are also prime factors of the base `n`.

If the denominator `q` has even a single prime factor that is *not* a prime factor of the base `n`, the representation in that base will be **infinite and repeating**.

### The "Why" of Your Question

Let's apply this rule to answer your specific question: "Why does converting a decimal fraction to its base-n number cause an infinite repeating decimal?"

Let's take the simple decimal fraction `0.1` (which is $\frac{1}{10}$) and try to convert it to binary (base-2).

1. **The Fraction:** $\frac{1}{10}$
2. **The Target Base:** Base-2.
3. **Prime Factors of the Base (2):** The only prime factor is `{2}`.
4. **Prime Factors of the Denominator (10):** The prime factors are `{2, 5}`.

Now, we check the rule: Does the denominator `10` have any prime factors that are *not* in the set of the base's prime factors?

* Yes. The denominator has a prime factor of **5**.
* The base-2 system only "understands" powers of 2. It has no way to perfectly represent a division by 5.

Because of this mismatch in prime factors, the fraction $\frac{1}{10}$ **cannot terminate** in base-2. It is forced to become an infinite, repeating sequence.

**The Calculation:**
If you perform the conversion of $\frac{1}{10}$ to binary, you get:
$$
0.0001100110011..._2
$$
The block `0011` repeats forever.

### More Examples to Make it Clear

**Example 1: Convert $\frac{1}{3}$ to Base-3 (Ternary)**

* **Fraction:** $\frac{1}{3}$

* **Target Base:** Base-3

* **Prime factors of base (3):** `{3}`

* **Prime factors of denominator (3):** `{3}`

* **Check:** All prime factors of the denominator are also prime factors of the base.

* **Result:** It **terminates**.
  
  $$
  \frac{1}{3} \text{ in base-3 is } 0.1_3
  $$
  
  (Just like $\frac{1}{10}$ in base-10 is $0.1_{10}$)

**Example 2: Convert $\frac{1}{2}$ to Base-3 (Ternary)**

* **Fraction:** $\frac{1}{2}$

* **Target Base:** Base-3

* **Prime factors of base (3):** `{3}`

* **Prime factors of denominator (2):** `{2}`

* **Check:** The denominator has a prime factor (2) that is not a prime factor of the base.

* **Result:** It **repeats**.
  
  $$
  \frac{1}{2} \text{ in base-3 is } 0.1111..._3 
  $$

### Summary

| Conversion                       | Fraction               | Prime Factors of Denominator | Prime Factors of Base | Mismatch? | Result                   |
|:-------------------------------- |:---------------------- |:---------------------------- |:--------------------- |:--------- |:------------------------ |
| $\frac{1}{8}$ to Base-10         | $\frac{1}{2^3}$        | `{2}`                        | `{2, 5}`              | No        | **Terminates** (0.125)   |
| $\frac{1}{3}$ to Base-10         | $\frac{1}{3}$          | `{3}`                        | `{2, 5}`              | Yes (3)   | **Repeats** (0.333...)   |
| `0.1` ($\frac{1}{10}$) to Base-2 | $\frac{1}{2 \times 5}$ | `{2, 5}`                     | `{2}`                 | Yes (5)   | **Repeats** (0.00011...) |
| `0.5` ($\frac{1}{2}$) to Base-3  | $\frac{1}{2}$          | `{2}`                        | `{3}`                 | Yes (2)   | **Repeats** (0.111...)   |

The phenomenon of a number being terminating in one base but repeating in another is a direct consequence of the **relationship between the prime factors of the fraction's denominator and the prime factors of the number base itself.**
