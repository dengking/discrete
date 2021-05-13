[TOC]



# [Cryptographic hash function](https://en.wikipedia.org/wiki/Cryptographic_hash_function)

A **cryptographic hash function** (**CHF**) is a [hash function](https://en.wikipedia.org/wiki/Hash_function) that is suitable for use in [cryptography](https://en.wikipedia.org/wiki/Cryptography). It is a mathematical [algorithm](https://en.wikipedia.org/wiki/Algorithm) that [maps](https://en.wikipedia.org/wiki/Map_(mathematics)) data of arbitrary size (often called the "message") to a [bit string](https://en.wikipedia.org/wiki/Bit_string) of a fixed size (the "hash value", "hash", or "message digest") and is a [one-way function](https://en.wikipedia.org/wiki/One-way_function), that is, a function which is practically infeasible to invert. Ideally, the only way to find a message that produces a given hash is to attempt a [brute-force search](https://en.wikipedia.org/wiki/Brute-force_search) of possible inputs to see if they produce a match, or use a [rainbow table](https://en.wikipedia.org/wiki/Rainbow_table) of matched hashes. Cryptographic hash functions are a basic tool of modern cryptography. 

## Properties

The ideal cryptographic hash function has the following main properties:

- it is [deterministic](https://en.wikipedia.org/wiki/Deterministic_algorithm), meaning that the same message always results in the same hash
- it is quick to compute the hash value for any given message

> Note: The above two properties are the basic properties a good hash function should satisfy, which is introduced in [Hash function](https://en.wikipedia.org/wiki/Hash_function). The below three properties are necessary for a ideal cryptographic hash function:

- it is infeasible to generate a message that yields a given hash value
- it is infeasible to find two different messages with the same hash value
- a small change to a message should change the hash value so extensively that the new hash value appears uncorrelated with the old hash value ([avalanche effect](https://en.wikipedia.org/wiki/Avalanche_effect)) 

A cryptographic hash function must be able to withstand all known [types of cryptanalytic attack](https://en.wikipedia.org/wiki/Cryptanalysis#Types_of_cryptanalytic_attack). In theoretical cryptography, the **security level** of a cryptographic hash function has been defined using the following properties:

- Pre-image resistance

  Given a hash value *h* it should be difficult to find any message *m* such that *h* = hash(*m*). This concept is related to that of a [one-way function](https://en.wikipedia.org/wiki/One-way_function). Functions that lack this property are vulnerable to [preimage attacks](https://en.wikipedia.org/wiki/Preimage_attack).

- Second pre-image resistance

  Given an input *m*1, it should be difficult to find a different input *m*2 such that hash(*m*1) = hash(*m*2). This property is sometimes referred to as *weak collision resistance*. Functions that lack this property are vulnerable to [second-preimage attacks](https://en.wikipedia.org/wiki/Preimage_attack).

- [Collision resistance](https://en.wikipedia.org/wiki/Collision_resistance)

  It should be difficult to find two different messages *m*1 and *m*2 such that hash(*m*1) = hash(*m*2). Such a pair is called a cryptographic [hash collision](https://en.wikipedia.org/wiki/Hash_collision). This property is sometimes referred to as *strong collision resistance*. It requires a hash value at least twice as long as that required for pre-image resistance; otherwise collisions may be found by a [birthday attack](https://en.wikipedia.org/wiki/Birthday_attack).

Collision resistance implies **second pre-image resistance**, but does not imply **pre-image resistance**.

Informally, these properties mean that a [malicious adversary](https://en.wikipedia.org/wiki/Adversary_(cryptography)) cannot replace or modify the input data without changing its **digest**. Thus, if two strings have the same digest, one can be very confident that they are identical. **Second pre-image resistance** prevents an attacker from crafting a document with the same hash as a document the attacker cannot control. **Collision resistance** prevents an attacker from creating two distinct documents with the same hash.

In practice, **collision resistance** is insufficient for many practical uses. In addition to collision resistance, it should be impossible for an adversary to find two messages with substantially similar digests; or to infer any useful information about the data, given only its digest. In particular, a hash function should behave as much as possible like a [random function](https://en.wikipedia.org/wiki/Random_function) (often called a [random oracle](https://en.wikipedia.org/wiki/Random_oracle) in proofs of security) while still being deterministic and efficiently computable. This rules out functions like the [SWIFFT](https://en.wikipedia.org/wiki/SWIFFT) function, which can be rigorously proven to be collision resistant assuming that certain problems on ideal lattices are computationally difficult, but as a linear function, does not satisfy these additional properties.

Checksum algorithms, such as [CRC32](https://en.wikipedia.org/wiki/CRC32) and other [cyclic redundancy checks](https://en.wikipedia.org/wiki/Cyclic_redundancy_check), are designed to meet much weaker requirements, and are generally unsuitable as cryptographic hash functions. For example, a CRC was used for message integrity in the [WEP](https://en.wikipedia.org/wiki/Wired_Equivalent_Privacy) encryption standard, but an attack was readily discovered which exploited the linearity of the checksum.

## Applications

Cryptographic hash functions have many [information-security](https://en.wikipedia.org/wiki/Information_security) applications, notably in [digital signatures](https://en.wikipedia.org/wiki/Digital_signature), [message authentication codes](https://en.wikipedia.org/wiki/Message_authentication_codes) (MACs), and other forms of [authentication](https://en.wikipedia.org/wiki/Authentication). They can also be used as ordinary [hash functions](https://en.wikipedia.org/wiki/Hash_function), to index data in [hash tables](https://en.wikipedia.org/wiki/Hash_table), for [fingerprinting](https://en.wikipedia.org/wiki/Fingerprint_(computing)), to detect duplicate data or uniquely identify files, and as [checksums](https://en.wikipedia.org/wiki/Checksum) to detect accidental data corruption. Indeed, in information-security contexts, cryptographic hash values are sometimes called (*digital*) *fingerprints*, *checksums*, or just *hash values*, even though all these terms stand for more general functions with rather different properties and purposes.



## Cryptographic hash algorithms

- [MD5](https://en.wikipedia.org/wiki/MD5)
- [SHA-1](https://en.wikipedia.org/wiki/SHA-1)
- [RIPEMD-160](https://en.wikipedia.org/wiki/RIPEMD-160)
- [Bcrypt](https://en.wikipedia.org/wiki/Bcrypt)
- [Whirlpool (cryptography)](https://en.wikipedia.org/wiki/Whirlpool_(cryptography))
- [SHA-2](https://en.wikipedia.org/wiki/SHA-2)
- [SHA-3](https://en.wikipedia.org/wiki/SHA-3)
- [BLAKE2](https://en.wikipedia.org/wiki/BLAKE2)