# Linear hash

在阅读 时，其中提及了linear hash:

> Linear hash sharding is a hybrid between hash and range sharding that preserves the sort order of the rows by utilizing a [linear hash function](https://xlinux.nist.gov/dads/HTML/linearhash.html) instead of a regular random hash function to compute how to shard the rows. A linear hash function, sometimes referred to as an order preserving hash, is a hash function that maintains the relative ordering of input values while changing their distribution spacing. This type of sharding preserves the sort ordering of the rows, while redistributing these rows across a larger key space. The idea is that the larger key space over which the redistribution of rows is done can be pre-sharded, enabling the table to be spread across multiple nodes.
>
> ![img](https://blog.yugabyte.com/wp-content/uploads/2020/01/image5.png)

显然，linear hash的一个显著的特性是: 输出和深入是保持相同的order。

# xlinux [linear hash](https://xlinux.nist.gov/dads/HTML/linearhash.html)

**Definition:** A numeric function that maintains the order of input [*keys*](https://xlinux.nist.gov/dads/HTML/key.html) while changing their spacing.

