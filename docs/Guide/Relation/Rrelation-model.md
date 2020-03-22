# Relation model

使用关系理论可以描述非常多在计算机科学的问题，我将此称为relation model

## 一对多relation model

多态

race condition

一对多关系使用有向图来表示就是一个节点与多个节点相邻，相邻节点都有边指向它。

对于单核CPU、支持multitask的OS，则多个process共享一个CPU，这也是一种one-to-many relation

thread共享process的resource

多个process共享computer resource。

## many-to-many relation model

一个典型的例子就是多核CPU