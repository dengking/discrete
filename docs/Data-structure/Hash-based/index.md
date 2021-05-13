# 关于本章

本章描述hash-based data structure相关内容。



## wikipedia [Category:Hash based data structures](https://en.wikipedia.org/wiki/Category:Hash_based_data_structures)





## draft

如何让程序算得更快？这对于一些应用是非常重要的，比如[hash function](https://en.wikipedia.org/wiki/Hash_function)，[efficiency](https://en.wikipedia.org/wiki/Hash_function#Efficiency)即算得快是hash function最最基本的要求之一。

> Division-based implementations can be of particular concern, because division is microprogrammed on nearly all chip architectures. Divide (modulo) by a constant can be inverted to become a multiply by the word-size multiplicative-inverse of the constant. This can be done by the programmer, or by the compiler. Divide can also be reduced directly into a series of shift-subtracts and shift-adds, though minimizing the number of such operations required is a daunting problem; the number of assembly instructions resulting may be more than a dozen, and swamp the pipeline. If the architecture has a hardware multiply functional unit, the multiply-by-inverse is likely a better approach.

