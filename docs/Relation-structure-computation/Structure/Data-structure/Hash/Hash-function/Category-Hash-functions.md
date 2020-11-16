

# [Category:Hash functions](https://en.wikipedia.org/wiki/Category:Hash_functions)





# [List of hash functions](https://en.wikipedia.org/wiki/List_of_hash_functions)



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





# TODO

https://security.stackexchange.com/questions/11839/what-is-the-difference-between-a-hash-function-and-a-cryptographic-hash-function



https://crypto.stackexchange.com/questions/879/what-is-the-random-oracle-model-and-why-is-it-controversial/880#880



https://computer.howstuffworks.com/encryption7.htm



https://en.wikipedia.org/wiki/Hash