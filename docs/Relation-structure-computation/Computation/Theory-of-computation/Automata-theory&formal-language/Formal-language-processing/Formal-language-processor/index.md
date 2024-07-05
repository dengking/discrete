# Formal language processor

讨论language processor的实现。

以下面三种implementation为例来进行说明:

|        | 章节                                                         |
| ------ | ------------------------------------------------------------ |
| sqlite | 工程DB的`Implementation\SQLite\doc\Technical-and-Design-Documentation\Architecture-of-SQLite`章节 |
| clang  | 工程`programming-language`的`C-family-language\C-and-C++\From-source-code-to-exec\Compile\Implementation\LLVM\Clang`章节 |
| Python | 工程`programming-language`的`Python`章节                     |

## 层次化结构

一般，formal language processor都是采用的**层次化结构**

在工程compiler-principle中也有关于**层次化结构**的讨论

> TODO: 关于clang的架构中中间表示的重要意义，参见龙书chapter6的第一段。
>
> 如何描述之间表示？ASDL是一种方式
>
> 

## 中间表示

不同层次之间需要使用**中间表示**

## Interpreter/VM and hook function

Interpreter/VM 执行 bytecode，bytecode 有 Interpreter/VM 来进行执行，bytecode的一些operation往往对应于一个function。为了支持可扩展，一般都支持user defined hook function。

Python 和 sqlite都是典型的基于interpreter的，它们的interpreter/virtual machine支持执行hook function:

|        | 注解                                                         |
| ------ | ------------------------------------------------------------ |
| Python | 3. Data model[¶](https://docs.python.org/3/reference/datamodel.html#data-model) |
| sqlite | sqlite virtual table: [The Virtual Table Mechanism Of SQLite](https://sqlite.org/vtab.html) |



我们将此称为interpreter model。