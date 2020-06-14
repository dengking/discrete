## 关于本章

本章的标题是“Relation-structure-computation”，它的含义是关系、结构、计算”，它们是discrete math涉及的之一课题。

“relation”将在[Relation](./Relation/index.md)中进行描述；

“structure”将在[Structure](./Structure/index.md)中进行描述；

“computation”将在[Computation](./Computation/index.md)中进行描述；

本文对本章的内容进行综述，以从一个较高的角度来掌握本章的内容。

## 综述

如果discrete object之间没有relation，那么它们就是一堆杂乱无章、毫无规律可言的混沌系统，无法使用精简的数学语言对其进行描述（formal description），我们所关注的是那些具备中**relation**的discrete objects。

对于具备relation的discrete objects（可以看做是**node**），通过relation将discrete objects进行关联，显然它们形成了一个一个的**ordered pair**（可以看做是edge），这些order pair就形成了一定的structure。

graph是表示relation的有效工具，后面我们会看到graph的定义和relation的定义是非常类似的，基于graph的algorithm，可以解决很多relation的问题。

作为software engineer，我们需要思考的问题是：“哪些问题是可计算的？”、“该如何实现计算”。

### relation and structure

将讨论如下问题：

- 有哪些structure

  

### relation and computation

将讨论如下问题：

- iteration
- recursion



### 结构化思维



在当我们使用relation来描述事物的时候（即按照上面描述的node、orderd-pair的方式来进行组织），我们会发现它们会形成一定的structure，比如graph、tree、chain，我们建这种思维称为“结构化思维”。

结构，可以是有形的结构，也可以是无形的、逻辑的结构。



#### 离散结构来描述物理结构和数学公式

数学使用relation来描述结构，relation是一个一个的ordered pair，

[recurrence relation](./Recursion/Recurrence-relation.md)其实所描述的是两个元素的关系，这种关系可能是线性的。

[recurrence relation](./Recursion/Recurrence-relation.md)是非常适合于使用computer algorithm来实现的，因为它是离散的，它是可以使用one-by-one来计算出来的，我们也可以说它具有离散结构。

其实上面这段话已经体现了使用结构的思维来看待数学公式了，我觉得计算机科学是需要这种思维的，只有结构化了之后，计算机才能够进行计算，这里所说的结构化如果往更高层面来思考的话，其实是：形式化，只有形式化后才能够使用计算机算法来进行计算，或者更加通俗地来说：结构化是形式化的一种。

基本上目前我碰到的这些离散的结构，都可以使用one-by-one的方式来设计算法。

