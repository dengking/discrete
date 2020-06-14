# Entity–relationship model

使用Entity–relationship model可以描述非常多在计算机科学、实际生活中的问题。

## 维基百科[Entity–relationship model](https://en.wikipedia.org/wiki/Entity%E2%80%93relationship_model)



## 维基百科[Cardinality (data modeling)](https://en.wikipedia.org/wiki/Cardinality_(data_modeling))

> NOTE: Cardinality 的中文意思是“基数”



## One-to-one relation model

### 维基百科[One-to-one (data model](https://en.wikipedia.org/wiki/One-to-one_(data_model)))



## One-to-many relation model

### 维基百科[One-to-many (data model)](https://en.wikipedia.org/wiki/One-to-many_(data_model))



### Example

多态

race condition

一对多关系使用有向图来表示就是一个节点与多个节点相邻，相邻节点都有边指向它。

对于单核CPU、支持multitask的OS，则多个process共享一个CPU，这也是一种one-to-many relation

thread共享process的resource

多个process共享computer resource。

## many-to-many relation model



### 维基百科[Many-to-many (data model)](https://en.wikipedia.org/wiki/Many-to-many_(data_model))



### Example

一个典型的例子就是多核CPU



### READING LIST

https://fmhelp.filemaker.com/help/18/fmp/en/index.html#page/FMP_Help/many-to-many-relationships.html

https://support.airtable.com/hc/en-us/articles/218734758-A-beginner-s-guide-to-many-to-many-relationships

https://dzone.com/articles/how-to-handle-a-many-to-many-relationship-in-datab

## relation and circular
可以使用graph来表示relation

当relation是dependency关系、reference关系（[Reference counting](https://en.wikipedia.org/wiki/Reference_counting)）的时候，如果图成环，则就会导致一些列问题


