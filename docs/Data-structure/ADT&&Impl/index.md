# ADT 以及 它的implementation

wikipedia [abstract data type](https://en.wikipedia.org/wiki/Abstract_data_type) 对 ADT 的含义解释的非常到位，[abstract data type](https://en.wikipedia.org/wiki/Abstract_data_type) 是典型的在computer science中的model、abstraction和implementation分离，[abstract data type](https://en.wikipedia.org/wiki/Abstract_data_type)是model，比如queue，dict，等等；对于每一种model，都可以有多种实现，比如我们可以使用hash来实现dict，我们可以使用skip list来实现sorted set；每一种实现所表现出的性能是不同的；

在各种编程语言的标准库中都会提供的各种容器，比如`C++`的[STL](https://en.wikipedia.org/wiki/Standard_Template_Library)，python的[`collections`](https://docs.python.org/3/library/collections.html#module-collections) ，软件工程师对于它们非常熟系，往往直接使用而无需关系它们的实现细节（抽象的好处）。

用户在使用这些各种programming language所提供的各种data structure的时候，其实所谈论的都是ADT，我们往往不会关注这些ADT的实现方式是怎样的；



## wikipedia [Abstract data type](https://en.wikipedia.org/wiki/Abstract_data_type)

