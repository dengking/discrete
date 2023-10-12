# Hash function

## 综述

正如在[List of hash functions](https://en.wikipedia.org/wiki/List_of_hash_functions)中所罗列的，有着形形色色的hash function。那我们应该如何来把我hash function呢？我觉得从数学上对[function](https://en.wikipedia.org/wiki/Function_(mathematics))的定义入手较好。

一、 hash function和普通的function一样，有[domain](https://en.wikipedia.org/wiki/Domain_of_a_function) 和[codomain](https://en.wikipedia.org/wiki/Codomain)。在hash function中，domain的同义词有：key space

二、 在设计一个hash function的时候，需要考虑它的[domain](https://en.wikipedia.org/wiki/Domain_of_a_function)要容纳哪些数据。比如：

  - 对于使用[cryptographic hash function](https://en.wikipedia.org/wiki/Cryptographic_hash_function)来加密密码的function，它的[domain](https://en.wikipedia.org/wiki/Domain_of_a_function)要容纳就是所有可以用于密码的字符的组合而成的字符串
  - 可能hash数字

三、 在设计一个hash function的时候，需要考虑它的[domain](https://en.wikipedia.org/wiki/Domain_of_a_function)中数据的特征，比如：

  - [identity hash function](https://en.wikipedia.org/wiki/Hash_function#Identity_hash_function)就是使用的[domain](https://en.wikipedia.org/wiki/Domain_of_a_function)中数据是identity的特征
  - [trivial hash function](https://en.wikipedia.org/wiki/Hash_function#Trivial_hash_function)就是使用domain中的数据是uniformly or sufficiently uniformly distributed 的特征
  - [modulo division hash function](https://en.wikipedia.org/wiki/Hash_function#Hashing_integer_data_types)一般选择一个big prime来作为[**modulo**](https://en.wikipedia.org/wiki/Modulo_operation) ，具体原因，参见[Why is it best to use a prime number as a mod in a hashing function?](https://cs.stackexchange.com/questions/11029/why-is-it-best-to-use-a-prime-number-as-a-mod-in-a-hashing-function)。

四、 [domain](https://en.wikipedia.org/wiki/Domain_of_a_function) 和[codomain](https://en.wikipedia.org/wiki/Codomain)之间的映射关系：

  - [Injective function](https://en.wikipedia.org/wiki/Injective_function)，显然[perfect hash function](https://en.wikipedia.org/wiki/Perfect_hash_function)具备这种性质。

    

## wikipedia [Hash table#Hashing](https://en.wikipedia.org/wiki/Hash_table#Hashing)

> NOTE: [Hash table#Hashing](https://en.wikipedia.org/wiki/Hash_table#Hashing)中关于hash的介绍比较精简。

## wikipedia [Hash function](https://en.wikipedia.org/wiki/Hash_function)

A **hash function** is any [function](https://en.wikipedia.org/wiki/Function_(mathematics)) that can be used to map [data](https://en.wikipedia.org/wiki/Data_(computing)) of arbitrary size to fixed-size values. The values returned by a hash function are called *hash values*, *hash codes*, *digests*, or simply *hashes*. 

> NOTE: "digests" means 摘要 in Chinese.

### Overview

> NOTE: Although this article is named [Hash function](https://en.wikipedia.org/wiki/Hash_function), what this chapter talks about is hash table. 

A **hash function** takes as input a key, which is associated with a datum or record and used to identify it to the data storage and retrieval application. The keys may be **fixed length**, like an integer, or **variable length**, like a name. In some cases, the key is the datum itself. The output is a hash code used to index a hash table holding the data or records, or pointers to them.

A hash function **may be** considered to perform three functions:

一、Convert variable length keys into **fixed length** (usually machine word length or less) values, by folding them by words or other units using a **parity-preserving operator** like ADD or XOR.

> NOTE: Folding means bitwise operation.

> NOTE: What is parity-preserving operator?
>
> [Parity bit](https://en.wikipedia.org/wiki/Parity_bit)

二、Scramble the bits of the key so that the resulting values are uniformly distributed over the **key space**.

> NOTE: What is the key space? ASCII code?

三、Map the key values into ones less than or equal to the size of the table

> NOTE: This function will be used only when it is used as index of the table in [hash table](https://en.wikipedia.org/wiki/Hash_table). In other applications, this function may be omitted.

A good hash function satisfies two basic properties: 

1) it should be very fast to compute; 

> NOTE: This is [efficiency](#Efficiency)

2) it should minimize duplication of output values (collisions). 

> NOTE: This is [uniformity](#Uniformity)



Hash functions rely on generating favorable probability distributions for their effectiveness, reducing access time to nearly constant. High table loading factors, [pathological](https://en.wikipedia.org/wiki/Pathological_(mathematics)) key sets and poorly designed hash functions can result in access times approaching linear in the number of items in the table. Hash functions can be designed to give best worst-case performance, good performance under high table loading factors, and in special cases, perfect (collisionless) mapping of keys into hash codes. Implementation is based on parity-preserving bit operations (XOR and ADD), multiply, or divide. A necessary adjunct to the hash function is a collision-resolution method that employs an auxiliary data structure like [linked lists](https://en.wikipedia.org/wiki/Linked_list), or systematic probing of the table to find an empty slot.



### Properties

> Note: Properties determine their usage, it is necessary to know the properties a hash function possess. 

#### Uniformity

> Note: 均匀性，按照维基百科[Hash table#Choosing a hash function](https://en.wikipedia.org/wiki/Hash_table#Choosing_a_hash_function)的说法：
>
> A basic requirement is that the function should provide a [uniform distribution](https://en.wikipedia.org/wiki/Uniform_distribution_(discrete)) of hash values.

A good hash function should map the expected inputs as evenly as possible over its output range. That is, every **hash value** in the **output range** should be generated with roughly the same [probability](https://en.wikipedia.org/wiki/Probability). The reason for this last requirement is that the cost of hashing-based methods goes up sharply as the number of *collisions*—pairs of inputs that are mapped to the same **hash value**—increases. If some hash values are more likely to occur than others, a larger fraction of the lookup operations will have to search through a larger set of colliding table entries.

Note that this criterion only requires the value to be *uniformly distributed*, not *random* in any sense. A good **randomizing function** is (barring computational efficiency concerns) generally a good choice as a **hash function**, but the converse need not be true.

> NOTE: hash function VS **randomizing function**

Hash tables often contain only a small subset of the valid inputs. For instance, a club membership list may contain only a hundred or so member names, out of the very large set of all possible names. In these cases, the uniformity criterion should hold for almost all **typical subsets** of entries that may be found in the table, not just for the global set of all possible entries.

> NOTE: **Typical subset** VS **global set**



#### Efficiency

In most applications, it is highly desirable that the hash function be computable with minimum latency and secondarily in a minimum number of instructions.



#### Universality

[Universal hashing](https://en.wikipedia.org/wiki/Universal_hashing)

#### Applicability

A hash function should be applicable to all situations in which a hash function might be used. A hash function that allows only certain table sizes, strings only up to a certain length, or can't accept a seed (i.e. allow double hashing) isn't as useful as one that does.

> NOTE: The seed in the paragraph is [salt (cryptography)](https://en.wikipedia.org/wiki/Salt_(cryptography)). Reference the [Deterministic](#Deterministic) to see the value of the seed.

#### Deterministic

A hash procedure must be [deterministic](https://en.wikipedia.org/wiki/Deterministic_algorithm)—meaning that for a given input value it **must** always generate the same hash value. In other words, it must be a [function](https://en.wikipedia.org/wiki/Function_(mathematics)) of the data to be hashed, in the mathematical sense of the term. This requirement excludes hash functions that depend on external variable parameters, such as [pseudo-random number generators](https://en.wikipedia.org/wiki/Pseudo-random_number_generator) or the time of day. It also excludes functions that depend on the memory address of the object being hashed in cases that the address may change during execution (as may happen on systems that use certain methods of [garbage collection](https://en.wikipedia.org/wiki/Garbage_collection_(computer_science))), although sometimes rehashing of the item is possible.

The determinism is in the **context** of the reuse of the function. For example, [Python](https://en.wikipedia.org/wiki/Python_(programming_language)) adds the feature that hash functions make use of a randomized seed that is generated once when the Python process starts in addition to the input to be hashed. The Python hash is still a valid hash function when used within a single run. But if the values are persisted (for example, written to disk) they can no longer be treated as valid hash values, since in the next run the random value might differ.

> Note: Reference python doc: `object.__hash__`(*self*)[¶](https://docs.python.org/3/reference/datamodel.html#object.__hash__)



#### Defined range

##### Fixed-length hash

It is often desirable that the output of a hash function have fixed size (but see below). If, for example, the output is constrained to 32-bit integer values, the hash values can be used to index into an array. Such hashing is commonly used to accelerate data searches. Producing **fixed-length** output from **variable length** input can be accomplished by breaking the input data into chunks of specific size. Hash functions used for data searches use some arithmetic expression which iteratively processes chunks of the input (such as the characters in a string) to produce the hash value. 



##### Variable range

In many applications, the range of hash values may be different for each run of the program, or may change along the same run (for instance, when a hash table needs to be expanded). In those situations, one needs a hash function which takes two parameters—the input data *z*, and the number *n* of allowed hash values.

> NOTE: `n`是[codomain](https://en.wikipedia.org/wiki/Codomain)的[cardinality](https://en.wikipedia.org/wiki/Cardinality)

A common solution is to compute a fixed hash function with a very large range (say, 0 to $2^{32} − 1$), divide the result by *n*, and use the division's [remainder](https://en.wikipedia.org/wiki/Modulo_operation). If *n* is itself a power of 2, this can be done by [bit masking](https://en.wikipedia.org/wiki/Mask_(computing)) and [bit shifting](https://en.wikipedia.org/wiki/Bit_shifting). When this approach is used, the hash function must be chosen so that the result has fairly uniform distribution between 0 and *n* − 1, for any value of *n* that may occur in the application. Depending on the function, the remainder may be uniform only for certain values of *n*, e.g. [odd](https://en.wikipedia.org/wiki/Odd_number) or [prime numbers](https://en.wikipedia.org/wiki/Prime_number).



##### Variable range with minimal movement (dynamic hash function)

When the hash function is used to store values in a hash table that outlives the run of the program, and the hash table needs to be expanded or shrunk, the hash table is referred to as a **dynamic hash table**.

A hash function that will relocate the minimum number of records when the table is resized is desirable. What is needed is a hash function *H*(*z*,*n*) – where *z* is the key being hashed and *n* is the number of allowed hash values – such that *H*(*z*,*n* + 1) = *H*(*z*,*n*) with probability close to *n*/(*n* + 1).

[Linear hashing](https://en.wikipedia.org/wiki/Linear_hashing) and spiral storage are examples of dynamic hash functions that execute in constant time but relax the property of uniformity to achieve the minimal movement property. [Extendible hashing](https://en.wikipedia.org/wiki/Extendible_hashing) uses a dynamic hash function that requires space proportional to *n* to compute the hash function, and it becomes a function of the previous keys that have been inserted. Several algorithms that preserve the uniformity property but require time proportional to *n* to compute the value of *H*(*z*,*n*) have been invented.

A hash function with minimal movement is especially useful in [distributed hash tables](https://en.wikipedia.org/wiki/Distributed_hash_table).

### [Hashing integer data types](https://en.wikipedia.org/wiki/Hash_function#Hashing_integer_data_types)

#### [Identity hash function](https://en.wikipedia.org/wiki/Hash_function#Identity_hash_function)

#### [identity function](https://en.wikipedia.org/wiki/Identity_function) 

#### [Trivial hash function](https://en.wikipedia.org/wiki/Hash_function#Trivial_hash_function)

#### [Folding](https://en.wikipedia.org/wiki/Hash_function#Folding)

> NOTE: 到底在哪个级别进行fold？是在bit级别还是digit级别？在[What is Folding technique in hashing and how to implement it?](https://stackoverflow.com/questions/36565101/what-is-folding-technique-in-hashing-and-how-to-implement-it)中给出的解释是在digit级别进行fold的。但是Wikipedia给出的解释是在bit级别进行fold的。
>
> 这其实是由hash function的domain决定的，如果要hash的是数字，则就在digit级别进行fold；如果要hash的是字符串，则就在bit级别进行fold。

### Hashing variable-length dat



## wikipedia [Category:Hash functions](https://en.wikipedia.org/wiki/Category:Hash_functions)





## wikipedia [List of hash functions](https://en.wikipedia.org/wiki/List_of_hash_functions)



| Application                                                  | Property of hash function | length |
| ------------------------------------------------------------ | ------------------------- | ------ |
| [Hash table](https://en.wikipedia.org/wiki/Hash_table)       |                           |        |
| [Cryptographic hash function](https://en.wikipedia.org/wiki/Cryptographic_hash_function) |                           | 固定   |
| [Distributed hash tables](https://en.wikipedia.org/wiki/Distributed_hash_table) |                           |        |



## VS-check-sum-VS-cryptographic-hash

https://security.stackexchange.com/a/194602

A **checksum** (such as CRC32) is to prevent *accidental* changes. If one byte changes, the checksum changes. The checksum is not safe to protect against malicious changes: it is pretty easy to create a file with a particular checksum.

A **hash function** maps some data to other data. It is often used to speed up comparisons or create a hash table. Not all hash functions are secure and the hash does not necessarily changes when the data changes.

A **cryptographic hash function** (such as SHA1) is a checksum that is secure against malicious changes. It is pretty hard to create a file with a specific cryptographic hash.

To make things more complicated, cryptographic hash functions are sometimes simply referred to as hash functions.



## VS-cryptographic-hash-function-VS-perfect hash function?

[Are cryptographic hash functions perfect hash functions?](https://crypto.stackexchange.com/questions/8092/are-cryptographic-hash-functions-perfect-hash-functions)



## TODO

https://security.stackexchange.com/questions/11839/what-is-the-difference-between-a-hash-function-and-a-cryptographic-hash-function



https://crypto.stackexchange.com/questions/879/what-is-the-random-oracle-model-and-why-is-it-controversial/880#880



https://computer.howstuffworks.com/encryption7.htm



https://en.wikipedia.org/wiki/Hash
