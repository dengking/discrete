# Differ strings

## gpt-4-vision: how to stat the diff cnt of characters of two string in python

In Python, you can calculate the difference in the count of characters between two strings by using a `Counter` from the `collections` module. Here's a step-by-step guide on how to do this:

1. Import the `Counter` class from the `collections` module.
2. Create a `Counter` object for each string to get the count of each character.
3. Subtract one `Counter` object from the other to get the difference in counts.
4. Sum the absolute values of the differences to get the total difference count.

Here's an example function that implements the above steps:

```python
from collections import Counter


def diff_char_count(str1: str, str2: str) -> int:
    # Create Counter objects for both strings
    counter1 = Counter(str1)
    counter2 = Counter(str2)

    # Calculate the difference in character counts
    diff_counter = counter1 - counter2  # 计算在str1中，不在str2中的字符

    # Add the difference from the second string as well
    diff_counter += counter2 - counter1  # 计算在str2中，不在str1中的字符

    # Calculate the total difference by summing the absolute values of the differences
    total_diff = sum(diff_counter.values())

    return total_diff


if __name__ == '__main__':
    # Example usage:
    str1 = "hello"
    str2 = "billion"
    diff = diff_char_count(str1, str2)
    print(f"The total difference in character count is: {diff}")

```

> NOTE:
>
> 一、需要注意: 上述实现方式是相互做差
>
> 结果为 6

This function will return the total count of characters that are different between the two strings. Note that this counts each instance of a differing character. For example, if `str1` has 2 'a's and `str2` has 1 'a', the difference count for 'a' will be 1.

If you want to count each character only once regardless of how many more or fewer times it appears in one string compared to the other, you can use the following modification:

```python
def diff_unique_char_count(str1, str2):
    # Create sets of characters for both strings
    set1 = set(str1)
    set2 = set(str2)

    # Calculate the symmetric difference of both sets
    unique_diff = set1 ^ set2

    # The length of the symmetric difference is the count of unique differing characters
    total_diff = len(unique_diff)

    return total_diff


if __name__ == '__main__':
    # Example usage:
    str1 = "hello"
    str2 = "billion"
    diff = diff_unique_char_count(str1, str2)
    print(f"The total difference in unique character count is: {diff}")
```

> NOTE:
>
> 一、结果为5

This function will return the count of unique characters that are present in one string but not in the other.