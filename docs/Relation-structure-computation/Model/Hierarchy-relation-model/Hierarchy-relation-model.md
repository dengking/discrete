# Hierarchy

## 本文动机

在写作本文的时候，主要有如下两个动机：

### 写作动机一

对文章[Structure](./Structure.md)的“结构的形状”章节中的话题“深入分析我们肉眼看到的各种形状背后的relation的性质”进行解答。

### 写作动机二

本文想搞清楚hierarchy structure和tree structure之间的关联，因为在此之前我一直将hierarchy structure看做是tree structure的同义词，即hierarchy structure就一定是tree structure，这个观念是源自于[Tree structure](https://en.wikipedia.org/wiki/Tree_structure)中这样的描述：

> A **tree structure** or **tree diagram** is a way of representing the [hierarchical](https://en.wikipedia.org/wiki/Hierarchy) nature of a [structure](https://en.wikipedia.org/wiki/Structure) in a graphical form. 

促使我对这个观念产生怀疑的是在文章[Structure](./Structure.md)中提出的一个问题：

> 按照inheritance关系来组织类，如果不允许多继承的话，则最终形成的是树；如果允许多继承的话，则最终形成的是图

按照inheritance关系来组织类，如果支持多继承的话，则它依然是hierarchy结构，但是它不能是tree了，因为它成环了（关于这一点，参见[Discrete Mathematics and Its Applications](https://www.amazon.com/Discrete-Mathematics-Applications-Kenneth-Rosen/dp/125967651X)中Tree章节），如下图所示：

```
          |---Class 2-------------|          
          |                       |
class 1---|						  |-class 4
          |	                      |
          |---Class 3-------------|           	
```

上图从左至右表示继承关系，上图不是一个tree，而是graph。但是上图是满足hierarchy结构的。



维基百科的[Hierarchy](https://en.wikipedia.org/wiki/Hierarchy)基本上能够回答上述问题，所以一下正文部分是基于维基百科的[Hierarchy](https://en.wikipedia.org/wiki/Hierarchy)。

## 正文

如下是阅读维基百科的[Hierarchy](https://en.wikipedia.org/wiki/Hierarchy)的笔记。

A **hierarchy** (from the [Greek](https://en.wikipedia.org/wiki/Ancient_Greek) *hierarkhia*, "rule of a high priest", from *[hierarkhes](https://en.wikipedia.org/wiki/Ordinary_(officer))*, "president of sacred rites") is an arrangement of items (objects, names, values, categories, etc.) in which the items are represented as being "above", "below", or "at the same level as" one another. 

A hierarchy can link entities either directly or indirectly, and either vertically or diagonally. The only direct links in a hierarchy, insofar as they are hierarchical, are to one's immediate superior（上级） or to one of one's subordinates（下属）, although a system that is largely hierarchical can also incorporate alternative hierarchies. Hierarchical links can extend "vertically" upwards or downwards via multiple links in the same direction, following a [path](https://en.wikipedia.org/wiki/Path_(graph_theory)). All parts of the hierarchy that are not linked vertically to one another nevertheless can be "horizontally" linked through a path by traveling up the hierarchy to find a common direct or indirect superior, and then down again. This is akin to two [co-workers](https://en.wikipedia.org/wiki/Co-worker) or [colleagues](https://en.wikipedia.org/wiki/Comrade) （同一层）; each reports to a common superior, but they have the same relative amount of authority. Organizational forms exist that are both alternative and complementary to hierarchy. [Heterarchy](https://en.wikipedia.org/wiki/Heterarchy) is one such form.

“hierarchy”的中文意思是“层级”，我们平时常常所说的“等级”与它的含义类似，其实。Hierarchy概念所强调的是level以及level之间的关系（above-below关系或superior-subordinates关系）。可以将Hierarchy看做是一种结构（元素和元素之间的关系），Hierarchy的关系为above-below关系、superior-subordinates关系。

Hierarchy结构，如果使用computer science 语言来描述的话，那么它类似于graph structure。

Hierarchy结构，如果使用math 语言来描述的话，那么它类似于[partially ordered set](https://en.wikipedia.org/wiki/Partially_ordered_set) ，参见原文[Mathematical representation](https://en.wikipedia.org/wiki/Hierarchy#Mathematical_representation)章节。

Hierarchy结构并没有限制两层元素之间的link，按照上述的描述，它是允许某一层中的某个元素同时有两个superior，这种情况就是本文开头所列举的多继承。



### [Nomenclature](https://en.wikipedia.org/wiki/Hierarchy#Nomenclature) 命名法

稍微浏览了一下，原文这一段中给出的一些术语是比较好理解的。

### [Informal representation](https://en.wikipedia.org/wiki/Hierarchy#Informal_representation)

In plain English, a hierarchy can be thought of as a [set](https://en.wikipedia.org/wiki/Set_(mathematics)) in which: 

1. No element is superior to itself, and
2. One element, the *hierarch*（教主）, is superior to all of the other elements in the set.

The first requirement is also interpreted to mean that a hierarchy can have no [circular relationships](https://en.wikipedia.org/wiki/Cycle_(graph_theory)); the association between two objects is always [transitive](https://en.wikipedia.org/wiki/Transitive_relation). The second requirement asserts that a hierarchy must have a leader or [root](https://en.wikipedia.org/wiki/Root_node) that is common to all of the objects.

关于第一点，原文给出的解释是“a hierarchy can have no [circular relationships](https://en.wikipedia.org/wiki/Cycle_(graph_theory))”，“[circular relationships](https://en.wikipedia.org/wiki/Cycle_(graph_theory))"指向的是图论中的[circle](https://en.wikipedia.org/wiki/Cycle_(graph_theory))，作者所想要表达的是，一个hierarchy是不能够存在环的，否则无法严格地形成一层一层的hierarchy结构。就第一点的原话，我觉得使用relation的理论来理解的话，它表示的是这个关系不能够是一个[reflexive relation](https://en.wikipedia.org/wiki/Reflexive_relation)，否则就会出现环而无法形成一层一层的hierarchy结构。



### [Mathematical representation](https://en.wikipedia.org/wiki/Hierarchy#Mathematical_representation)

Mathematically, in its most general form, a hierarchy is a [partially ordered set](https://en.wikipedia.org/wiki/Partially_ordered_set) or *poset*.

### [Subtypes](https://en.wikipedia.org/wiki/Hierarchy#Subtypes)

“subtype”即子类，所以原文的这一节所描述的是特殊类型的hierarchy。

#### Nested hierarchy

A nested hierarchy or *inclusion hierarchy* is a hierarchical ordering of [nested sets](https://en.wikipedia.org/wiki/Nested_set).

A nested hierarchy or *inclusion hierarchy* is a hierarchical ordering of [nested sets](https://en.wikipedia.org/wiki/Nested_set).  The concept of nesting is exemplified in Russian [matryoshka dolls](https://en.wikipedia.org/wiki/Matryoshka_doll)（俄罗斯套娃）. Each doll is encompassed by another doll, all the way to the outer doll. The outer doll holds all of the inner dolls, the next outer doll holds all the remaining inner dolls, and so on. Matryoshkas represent a nested hierarchy where each level contains only one object, i.e., there is only one of each size of doll; **a generalized nested hierarchy allows for multiple objects within levels but with each object having only one parent at each level**. 

**Nested hierarchies** are the organizational schemes behind [taxonomies](https://en.wikipedia.org/wiki/Taxonomy_(general)) （分类学）and systematic classifications. 

In many programming taxonomies and syntax models (as well as fractals in mathematics), nested hierarchies, including Russian dolls, are also used to illustrate the properties of [self-similarity](https://en.wikipedia.org/wiki/Self-similarity) and [recursion](https://en.wikipedia.org/wiki/Recursion). Recursion itself is included as a subset of hierarchical programming, and recursive thinking can be synonymous with a form of hierarchical thinking and logic.

Nested hierarchy structure在hierarchy structure上添加的限制是nested ，它保证了“**each object having only one parent at each level**"，显然，这个限制就是graph中不再可能产生环了，一个不带环的图就是tree，所以nested hierarchy structure是tree structure，相比于hierarchy而言，nesting更加能够体现tree的结构特征。

nested hierarchy structure是一种特殊的hierarchy structure，tree是一种特殊的graph。

思考：怎样的关系才能够产生nested hierarchy structure？这个问题在[Tree-structure](../Tree/Tree-structure.md)中会进行详细讨论。



原文这一节后面的内容pass掉了。

## 讨论

### 按照哪种relation来组织元素会形成hierarchy？

在原文的[Informal representation](https://en.wikipedia.org/wiki/Hierarchy#Informal_representation)中有非严格的描述。其实简而言之就是元素之间需要存在着[**partial order**](https://en.wikipedia.org/wiki/Partially_ordered_set#Formal_definition)。



### Hierarchy and data structure

Hierarchy structure可以使用graph来进行表示。

Nested hierarchy structure可以是要弄tree来进行表示。



### [Hierarchy](https://en.wikipedia.org/wiki/Hierarchy) structure and recursion

具备[hierarchical](https://en.wikipedia.org/wiki/Hierarchical)结构的往往具备recursive的特征。

从数学的角度来看，[Hierarchy](https://en.wikipedia.org/wiki/Hierarchy) structure是一个[partially ordered set](https://en.wikipedia.org/wiki/Partially_ordered_set)，所以讨论hierarchy structure的递归性最终应该还是归于讨论poset的递归性。我觉得是可以使用tree的递归性来思考poset的递归性的，一个poset的subset也应该是一个poset。另外一个就是poset各层使用的是同一个relation。