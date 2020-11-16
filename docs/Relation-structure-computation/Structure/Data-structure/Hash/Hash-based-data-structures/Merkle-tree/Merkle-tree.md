# 前言

是在学习[git](https://en.wikipedia.org/wiki/Git)的时候，发现[Merkle tree](https://en.wikipedia.org/wiki/Merkle_tree)的。在学习[Merkle tree](https://en.wikipedia.org/wiki/Merkle_tree)之前，先学习[Hash list](https://en.wikipedia.org/wiki/Hash_list)和[Hash chain](https://en.wikipedia.org/wiki/Hash_chain)，两者是深刻掌握[Merkle tree](https://en.wikipedia.org/wiki/Merkle_tree)的基础。



# [Hash list](https://en.wikipedia.org/wiki/Hash_list)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a **hash list** is typically a [list](https://en.wikipedia.org/wiki/List_(computing)) of [hashes](https://en.wikipedia.org/wiki/Hash_function) of the data blocks in a file or set of files. 

> NOTE: hash list的含义其实非常简单，就是上面这段话所说的list of hash，仅此而已。当然可以在它上面再进行扩展，比如下面将要介绍的Root hash。

## Root hash

Often, an additional **hash** of the **hash list** itself (a *top hash*, also called *root hash* or *master hash*) is used. 

![img](https://upload.wikimedia.org/wikipedia/commons/thumb/7/7d/Hash_list.svg/350px-Hash_list.svg.png)

> A hash list with a top hash
>
> 上述就是一个带有root hash的hash list。

> NOTE: 思考：root hash的价值何在呢？如果将hash list中的每个hash都对应的是一个data block，而root hash则对应的是所有的data block，也就是说它其实所对应的是整体data，而非局部。下面的例子就描述的是这种含义。

Before downloading a file on a p2p network, in most cases the top hash is acquired from a trusted source, for instance a friend or a web site that is known to have good recommendations of files to download. When the top hash is available, the hash list can be received from any non-trusted source, like any peer in the p2p network. Then the received hash list is checked against the trusted top hash, and if the hash list is damaged or fake, another hash list from another source will be tried until the program finds one that matches the top hash.

## Applications

Hash lists can be used to protect any kind of data stored, handled and transferred in and between computers. An important use of hash lists is to make sure that data blocks received from other peers in a [peer-to-peer network](https://en.wikipedia.org/wiki/Peer-to-peer) are received undamaged and unaltered, and to check that the other peers do not "lie" and send fake blocks.

Usually a [cryptographic hash function](https://en.wikipedia.org/wiki/Cryptographic_hash_function) such as [SHA-256](https://en.wikipedia.org/wiki/SHA-256) is used for the hashing. If the hash list only needs to protect against unintentional damage unsecured [checksums](https://en.wikipedia.org/wiki/Checksum) such as [CRCs](https://en.wikipedia.org/wiki/Cyclic_redundancy_check) can be used.

> NOTE: 上述其实是hash的常见用法，并无什么特殊之处。下面则强调hash list的特殊之处。

Hash lists are better than a simple hash of the entire file since, in the case of a data block being damaged, this is noticed, and only the damaged block needs to be redownloaded. With only a hash of the file, many undamaged blocks would have to be redownloaded, and the file reconstructed and tested until the correct hash of the entire file is obtained. Hash lists also protect against nodes that try to sabotage by sending fake blocks, since in such a case the damaged block can be acquired from some other source.



# [Hash chain](https://en.wikipedia.org/wiki/Hash_chain)

A **hash chain** is the successive application of a [cryptographic hash function](https://en.wikipedia.org/wiki/Cryptographic_hash_function) to a piece of data.

## Definition

A **hash chain** is a successive application of a [cryptographic hash function](https://en.wikipedia.org/wiki/Cryptographic_hash_function) $ h $ to a string $ x $.

For example,

$ h(h(h(h(x)))) $ gives a hash chain of length 4, often denoted $ h^{4}(x) $

> NOTE:  显然，hash chain的定义所强调的是重复迭代地使用hash function。显然它所描述的其实是一个数学过程。

## Features

本文给出的hash chain的介绍是非常简单的， 运用hash chain还能够带来其他的非常优良的特性，这就使得hash chain有着非常广泛的应用，下面就来探讨运用hash chain可以带来的优良特性：

### [Pre-image resistance](https://en.wikipedia.org/wiki/Cryptographic_hash_function#Properties) / [one-way](https://en.wikipedia.org/wiki/One-way_function)

由于hash chain所使用的是[cryptographic hash function](https://en.wikipedia.org/wiki/Cryptographic_hash_function)，[cryptographic hash function](https://en.wikipedia.org/wiki/Cryptographic_hash_function)是[one-way function](https://en.wikipedia.org/wiki/One-way_function),所有hash chain就具备了[cryptographic hash function](https://en.wikipedia.org/wiki/Cryptographic_hash_function)的[Pre-image resistance](https://en.wikipedia.org/wiki/Cryptographic_hash_function#Properties)特性，即根据函数值无法逆向计算出它的自变量的值，说的更加形象一些就是hash chain只能够顺推而不能够逆推。



下面这段话是摘自[Hash Chain](https://github.com/DLTcollab/hashchain#hash-chain)项目的文档，目的是帮助理解：

The idea of a **hash chain** is simple: you start with a base (could be a password, or just a number, or some other data) and **hash**( [cryptographic hash function](https://en.wikipedia.org/wiki/Cryptographic_hash_function) ) it. You then take the result and hash that too. You continue hashing the results repeatedly, till you have a series of hashes like this:

```
Base -> Hash0 = H(Base) -> Hash1 = H(Hash0) -> ... -> HashN = H(HashN-1)
```

The exciting property of these hash chains is that given the last hash in the chain, HashN, it is very difficult to determine any of the **previous** hashes, or the base. However, given the last hash, it is trivial to verify whether another hash is part of the chain.

This means that a **hash chain** has the potential to be a limited source of authentication. You can deploy a resource in public along with the last hash of the chain. Then you can give commands to this resource, passing along each previous hash as authentication of your identity.



### Immutable 

篡改[Hash chain](https://en.wikipedia.org/wiki/Hash_chain)中的任何一个node（节点）的hash value都会导致这个节点后的所有的节点的hash value都必须重新计算一遍才能够重新组成链，否则就无法形成hash chain了。这意味中整个[Hash chain](https://en.wikipedia.org/wiki/Hash_chain)是immutable的。

下面是寻找到的一些与此相关的内容：

[Where did the idea of blockchain come from? Git was already using it since 2005](https://bitcoin.stackexchange.com/questions/43624/where-did-the-idea-of-blockchain-come-from-git-was-already-using-it-since-2005)

> With bitcoin's blockchain, each block's hash is computed with the previous block's hash. That makes all blocks an **immutable chain**.
>
> This is not the first time people used a hash-chain. As far as I know, Git was already used it since 2005 for the commit-hash computing.
>
> So, what is the earliest use of hash chains? Where did the idea of blockchain come from?

这种immutable的特性有着非常重要的价值，比如：

[原文链接](https://bitcoin.stackexchange.com/a/43627)

> According to [Bitcoin and Cryptocurrency Technologies (BaCT)](https://freedom-to-tinker.com/blog/randomwalker/the-princeton-bitcoin-textbook-is-now-freely-available/), the Princeton Bitcoin textbook, the block chain dates back to a "paper by Haber and Stornetta in 1991. Their proposal was a method for **secure** timestamping of digitaldocuments, rather than a digital money scheme." (BaCT p.15)
>
> The chaining of Merkle trees instead of single documents was proposed in a later paper. (BaCT p.16)



## [Applications](https://en.wikipedia.org/wiki/Hash_chain#Applications)

### [one-time keys](https://en.wikipedia.org/wiki/One-time_password)

In [computer security](https://en.wikipedia.org/wiki/Computer_security), a hash chain is a method to produce many [one-time keys](https://en.wikipedia.org/wiki/One-time_password) from a single [key](https://en.wikipedia.org/wiki/Key_(cryptography)) or [password](https://en.wikipedia.org/wiki/Password).  For [non-repudiation](https://en.wikipedia.org/wiki/Non-repudiation)（不可抵赖） a hash function can be applied successively to additional pieces of data in order to record the chronology of data's existence.

see also:  [S/KEY](https://en.wikipedia.org/wiki/S/KEY)

## Binary hash chains

*Main article:* [Merkle tree](https://en.wikipedia.org/wiki/Merkle_tree)

![Hash tree and hash chain](https://upload.wikimedia.org/wikipedia/commons/2/28/Hashtreehashchainjux.png)

## [Hash chain vs. blockchain](https://en.wikipedia.org/wiki/Hash_chain#Hash_chain_vs._blockchain)

A hash chain is similar to a [blockchain](https://en.wikipedia.org/wiki/Blockchain), as they both utilize a cryptographic hash function for creating a link between two nodes. However, a blockchain (as used by [Bitcoin](https://en.wikipedia.org/wiki/Bitcoin) and related systems) is generally intended to support distributed consensus around a public ledger (data), and incorporates a set of rules for encapsulation of data and associated data permissions.

> NOTE:  [Blockchain](https://en.wikipedia.org/wiki/Blockchain)肯定远比Hash chain复杂，关于两者的关联，有太多太多的文章进行剖析了。
>
> [Blockchain](https://en.wikipedia.org/wiki/Blockchain)运用了多种技术，其中之一就是Hash chain，[Blockchain](https://en.wikipedia.org/wiki/Blockchain)使用Hash chain来将它的block链接起来。关于[Blockchain](https://en.wikipedia.org/wiki/Blockchain)中Hash chain的应用，还需要参见[Blockchain](https://en.wikipedia.org/wiki/Blockchain)文章。
>
> 下面是检索到的关于两者的文章：
>
> https://www.researchgate.net/figure/The-Bitcoin-blockchain-is-a-hash-chain-of-blocks-Each-block-has-a-Merkle-tree-of_fig1_316789505
>
> The Bitcoin blockchain is a hash chain of blocks. Each block has a Merkle tree of transactions. Efficient membership proofs of transactions can be constructed with respect to the Merkle root. 
>
> 这篇文章将block chain的简单模型，通过这个简单模型可以看出hash chain在block chain中的使用。
>
> https://crypto.stackexchange.com/questions/68290/when-was-hash-chain-first-used
>
> Hash linking is used to prove the **integrity** of a blockchain, or similar systems. When was that technique first used? I would guess it was early, maybe 1950s/1960s?



## [Hash list](https://en.wikipedia.org/wiki/Hash_list) VS  [Hash chain](https://en.wikipedia.org/wiki/Hash_chain)

在[Hash chain](https://en.wikipedia.org/wiki/Hash_chain)中对两者进行了对比：

> In contrast to the recursive structure of hash chains, the elements of a hash list are independent of each other.

TO READ

[When was hash chain first used?](https://crypto.stackexchange.com/questions/68290/when-was-hash-chain-first-used)

https://www.techopedia.com/definition/32920/hash-chain

https://link.springer.com/referenceworkentry/10.1007%2F978-1-4419-5906-5_780



# [Merkle tree](https://en.wikipedia.org/wiki/Merkle_tree)

In [cryptography](https://en.wikipedia.org/wiki/Cryptography) and [computer science](https://en.wikipedia.org/wiki/Computer_science), a **hash tree** or **Merkle tree** is a [tree](https://en.wikipedia.org/wiki/Tree_(data_structure)) in which every leaf node is labelled with the [cryptographic hash](https://en.wikipedia.org/wiki/Cryptographic_hash_function) of a data block, and every non-leaf node is labelled with the [hash](https://en.wikipedia.org/wiki/Cryptographic_hash_function) of the labels of its child nodes. 

Hash trees are a generalization of [hash lists](https://en.wikipedia.org/wiki/Hash_list) and [hash chains](https://en.wikipedia.org/wiki/Hash_chain).

> NOTE: 有了前面[Hash list](https://en.wikipedia.org/wiki/Hash_list)和[Hash chain](https://en.wikipedia.org/wiki/Hash_chain)的基础现在来理解上面这段话其实就相对比较容易了。hash chain是线性结构，hash tree则是hierarchy结构。

![img](https://upload.wikimedia.org/wikipedia/commons/thumb/9/95/Hash_Tree.svg/310px-Hash_Tree.svg.png)

> An example of a binary hash tree. Hashes 0-0 and 0-1 are the hash values of data blocks L1 and L2, respectively, and hash 0 is the hash of the concatenation of hashes 0-0 and 0-1.

## Uses

Hash trees can be used to verify any kind of data stored, handled and transferred in and between computers. They can help ensure that data blocks received from other peers in a [peer-to-peer network](https://en.wikipedia.org/wiki/Peer-to-peer) are received undamaged and unaltered, and even to check that the other peers do not lie and send fake blocks.

Hash trees are used in [hash-based cryptography](https://en.wikipedia.org/wiki/Hash-based_cryptography). Hash trees are also used in

- file systems:  [IPFS](https://en.wikipedia.org/wiki/InterPlanetary_File_System), [Btrfs](https://en.wikipedia.org/wiki/Btrfs) and [ZFS](https://en.wikipedia.org/wiki/ZFS)

- distributed revision control systems: [Git](https://en.wikipedia.org/wiki/Git_(software)) and [Mercurial](https://en.wikipedia.org/wiki/Mercurial) 
- peer-to-peer network: [Bitcoin](https://en.wikipedia.org/wiki/Bitcoin)
- [NoSQL](https://en.wikipedia.org/wiki/NoSQL) systems such as [Apache Cassandra](https://en.wikipedia.org/wiki/Apache_Cassandra)

> NOTE: 通过上述例子可以看出[Merkle tree](https://en.wikipedia.org/wiki/Merkle_tree)在distributed application中有着广泛运用。

## Overview

A hash tree is a [tree](https://en.wikipedia.org/wiki/Binary_tree) of [hashes](https://en.wikipedia.org/wiki/Hash_function) in which the leaves are hashes of data blocks in, for instance, a file or set of files. Nodes further up in the tree are the hashes of their respective children. For example, in the picture *hash 0* is the result of hashing the [concatenation](https://en.wikipedia.org/wiki/Concatenation) of *hash 0-0* and *hash 0-1*. That is, *hash 0 = hash( hash(0-0) + hash(0-1) )* where *+* denotes **concatenation**.

Usually, a [cryptographic hash function](https://en.wikipedia.org/wiki/Cryptographic_hash_function) such as [SHA-2](https://en.wikipedia.org/wiki/SHA-2) is used for the hashing. If the hash tree only needs to protect against unintentional damage, unsecured [checksums](https://en.wikipedia.org/wiki/Checksum) such as [CRCs](https://en.wikipedia.org/wiki/Cyclic_redundancy_check) can be used.

In the top of a hash tree there is a *top hash* (or *root hash* or *master hash*). Before downloading a file on a p2p network, in most cases the top hash is acquired from a trusted source, for instance a friend or a web site that is known to have good recommendations of files to download. When the top hash is available, the hash tree can be received from any non-trusted source, like any peer in the p2p network. Then, the received **hash tree** is checked against the **trusted top hash**, and if the **hash tree** is damaged or fake, another hash tree from another source will be tried until the program finds one that matches the top hash.

# Merkel DAG

DAG的含义是directed acyclic graph。Merkel DAG是我在阅读[Is Git a Block Chain?](https://news.ycombinator.com/item?id=9436847)发现它们提出的一个概念。

# TO READ

https://blockchainlabs.ai/the-merkle-tree/



# Linked timestamping

https://en.wikipedia.org/wiki/Linked_timestamping