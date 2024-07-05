# Kleene star

一、这是regex中的一种常规操作，在龙书的"3.3.2-Operations on Languages"章节中有着非常好的描述。

二、在regex中，Kleene star一般使用`*` 来表示，需要注意的是: 它和 [Wildcard character](https://en.wikipedia.org/wiki/Wildcard_character) 不同

三、需要注意的是: 它和 [Closure (mathematics)](https://en.wikipedia.org/wiki/Closure_(mathematics)) 有种密切的关系，在wikipedia [Closure (mathematics)](https://en.wikipedia.org/wiki/Closure_(mathematics)) 中，有着这样的描述:

> In [formal languages](https://en.wikipedia.org/wiki/Formal_language), the [Kleene closure](https://en.wikipedia.org/wiki/Kleene_closure) of a language can be described as the set of strings that can be made by concatenating zero or more strings from that language.



## wikipedia [Kleene star](https://en.wikipedia.org/wiki/Kleene_star)



In [mathematical logic](https://en.wikipedia.org/wiki/Mathematical_logic) and [computer science](https://en.wikipedia.org/wiki/Computer_science), the **Kleene star** (or **Kleene operator** or **Kleene closure**) is a [unary operation](https://en.wikipedia.org/wiki/Unary_operation), either on [sets](https://en.wikipedia.org/wiki/Set_(mathematics)) of [strings](https://en.wikipedia.org/wiki/String_(computer_science)) or on sets of symbols or characters. 

### Examples

> NOTE: 在regex中，我们通常是将Kleene star作用于只有一个元素的集合，因此非常简单，原文本节给出的例子则是将Kleene star作用于有多个元素的集合，会稍微复杂一点。

Example of Kleene star applied to set of strings:

```
{"ab","c"}* = { ε, "ab", "c", "abab", "abc", "cab", "cc", "ababab", "ababc", "abcab", "abcc", "cabab", "cabc", "ccab", "ccc", ...}.
```



