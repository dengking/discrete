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





## relation and circular
可以使用graph来表示relation

当relation是dependency关系、reference关系（[Reference counting](https://en.wikipedia.org/wiki/Reference_counting)）的时候，如果图成环，则就会导致一些列问题





## relation
维基百科Many-to-many (data model)：https://en.wikipedia.org/wiki/Many-to-many_(data_model)

维基百科Cardinality (data modeling)：https://en.wikipedia.org/wiki/Cardinality_(data_modeling)

维基百科One-to-one (data model)：https://en.wikipedia.org/wiki/One-to-one_(data_model)

https://fmhelp.filemaker.com/help/18/fmp/en/index.html#page/FMP_Help/many-to-many-relationships.html

https://support.airtable.com/hc/en-us/articles/218734758-A-beginner-s-guide-to-many-to-many-relationships

https://dzone.com/articles/how-to-handle-a-many-to-many-relationship-in-datab