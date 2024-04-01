# A walk through the SA-IS Suffix Array Construction Algorithm[¶](https://zork.net/~st/jottings/sais.html#a-walk-through-the-sa-is-suffix-array-construction-algorithm)



## What’s a suffix array?[¶](https://zork.net/~st/jottings/sais.html#whats-a-suffix-array)



```python
from typing import *
import unittest


def naivelyMakeSuffixArray(source: str) -> List:
    """
    A naive, slow suffix-array construction algorithm.
    :param source:
    :return:
    """
    # Construct a list of suffixes of the source string.
    suffixes = []
    for offset in range(len(source) + 1):
        suffixes.append(source[offset:])
    # Sort the suffixes
    suffixes.sort()
    # Calculate the start offset of each suffix, storing them in
    # sorted order into the suffix array.
    suffixArray = []
    for suffix in suffixes:
        offset = len(source) - len(suffix)
        suffixArray.append(offset)
    return suffixArray


class TestNaivelyMakeSuffixArray(unittest.TestCase):
    def test_naivelyMakeSuffixArray(self):
        suffix_array = naivelyMakeSuffixArray('cabbage')
        print(suffix_array)
        self.assertEqual(suffix_array, [7, 1, 4, 3, 2, 0, 6, 5])

```

Note that although the indexes of the characters run 0 to 6, for a total of seven characters, the suffix array has *eight* offsets. The suffix beginning just after the last character and continuing to the end of the string is the **empty suffix**, containing no characters. Because it’s the shortest possible suffix, it always winds up sorted to the beginning of the suffix array. Most people who want to use suffix arrays don’t care about the empty suffix, but it turns out to be important for the **SA-IS algorithm**.

The naive algorithm above just re-uses a standard O(n log n) sorting algorithm, plus it adds the overhead of building a list of suffixes and building a new array of offsets at the end. **SA-IS** manages to do the whole thing in O(n) time, faster than just the standard sorting on its own, a massive improvement. To achieve this speed, SA-IS takes advantage of certain features of suffix arrays that are not necessarily true of any old array of strings.

## Concepts in SA-IS[¶](https://zork.net/~st/jottings/sais.html#concepts-in-sa-is)



```python
from typing import *
import unittest


def naivelyMakeSuffixArray(source: str) -> List:
    """
    A naive, slow suffix-array construction algorithm.
    :param source:
    :return:
    """
    # Construct a list of suffixes of the source string.
    suffixes = []
    for offset in range(len(source) + 1):
        suffixes.append(source[offset:])
    # Sort the suffixes
    suffixes.sort()
    # Calculate the start offset of each suffix, storing them in
    # sorted order into the suffix array.
    suffixArray = []
    for suffix in suffixes:
        offset = len(source) - len(suffix)
        suffixArray.append(offset)
    return suffixArray


class TestNaivelyMakeSuffixArray(unittest.TestCase):
    def test_naivelyMakeSuffixArray(self):
        suffix_array = naivelyMakeSuffixArray('cabbage')
        print(suffix_array)
        self.assertEqual(suffix_array, [7, 1, 4, 3, 2, 0, 6, 5])


S_TYPE = ord("S")
L_TYPE = ord("L")


def buildTypeMap(data: str):
    """
    Builds a map marking each suffix of the data as S_TYPE or L_TYPE.
    :param data:
    :return:
    """
    # The map should contain one more entry than there are characters
    # in the string, because we also need to store the type of the
    # empty suffix between the last character and the end of the
    # string.
    res = bytearray(len(data) + 1)
    # The empty suffix after the last character is S_TYPE
    res[-1] = S_TYPE
    # If this is an empty string...
    if not len(data):
        # ...there are no more characters, so we're done.
        return res
    # The suffix containing only the last character must necessarily
    # be larger than the empty suffix.
    res[-2] = L_TYPE
    # Step through the rest of the string from right to left.
    for i in range(len(data) - 2, -1, -1):
        if data[i] > data[i + 1]:
            res[i] = L_TYPE
        elif data[i] == data[i + 1] and res[i + 1] == L_TYPE:
            res[i] = L_TYPE
        else:
            res[i] = S_TYPE
    return res


class TestBuildTypeMap(unittest.TestCase):
    def testBuildTypeMap(self):
        typeMap: str = buildTypeMap('cabbage').decode('ascii')
        print(typeMap)
        self.assertEqual(typeMap, "LSLLSLLS")

```



## LMS characters[¶](https://zork.net/~st/jottings/sais.html#lms-characters)