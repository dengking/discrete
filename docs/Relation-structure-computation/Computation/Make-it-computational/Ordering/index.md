# Ordering

## Thoughts

### Thought1

对于无序、混乱、不可重复、随机、二义性，这些都是不可计算的，这些是需要被克服的，需要programmer进行显式的控制。只有**有序**才能够实现computation，才能够实现可靠性。

> NOTE: "显式的控制"可以从control-theory来进行分析，角度是: 加入control以使之有序，从而是computational的。

### Thought2

Order是一种abstract relation，通过order这个relation来构造出abstract structure，然后对 这个abstract structure进行计算，从而实现computation。其实ordering也是属于"structuralization"的。

比如stream等结构，它天然就是有序的。

### Thought3

这其实是control theory的理论，对于无序的，必须要进行control，否则系统是不可控的、存在错误的。

## Example

下面是一些例子:

1) TensorFlow `tf.control_dependencies`

在阅读TensorFlow whitepaper的时候，其中有这样的描述:

> Our implementation also sometimes inserts **control dependencies** to enforce **orderings** between otherwise independent operations as a way of, for example, controlling the peak memory usage.

由于computational graph是可能存在歧义的，即它可能无法准确地表达dependency关系，因此TF的`tf.control_dependencies`就显式地对dependency关系进行控制，从而使它具备了准确的ordering。

参见工程machine-learning。

2) memory barrier

参见工程parallel-computing

3) Ordering in distributed system

参见工程parallel-computing

4) type ordering

参见工程programming-language的`Theory\Type-system\Type-relation`章节。

5) ordering and object lifetime

参见 `./Ordering-and-object-lifetime`。

## Order theory

关于order theory，参见`Relation-structure-computation\Relation\Order-theory`章节。

## Ordering的维度

### 基于空间维度

### 基于时间维度

时间是一种非常有效的order维度，在诸多领域中都有着基于time的ordering:

1) 工程parallel-computing的`Concurrent-computing\Concurrency-control\Time-based-concurrency-control`章节。

2) logical clock