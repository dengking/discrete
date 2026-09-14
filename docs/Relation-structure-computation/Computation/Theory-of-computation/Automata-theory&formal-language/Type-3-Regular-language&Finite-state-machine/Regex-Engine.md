# Regex engine

Thompson's construction algorithm将regex转化为epsilon NFA;

Powerset construction algorithm将epsilon NFA转换为DFA;

epsilon transition在这两个算法中都发挥着非常重要的作用;

## Thompson's construction

### wikipedia [Thompson's construction](https://en.wikipedia.org/wiki/Thompson%27s_construction)

The **empty-expression** ε is converted to

[![inline](https://upload.wikimedia.org/wikipedia/commons/thumb/7/7e/Thompson-epsilon.svg/278px-Thompson-epsilon.svg.png)](https://en.wikipedia.org/wiki/File:Thompson-epsilon.svg)

A **symbol** *a* of the input alphabet is converted to

[![inline](https://upload.wikimedia.org/wikipedia/commons/thumb/9/93/Thompson-a-symbol.svg/278px-Thompson-a-symbol.svg.png)](https://en.wikipedia.org/wiki/File:Thompson-a-symbol.svg)

The **union expression** *s*|*t* is converted to

[![inline](https://upload.wikimedia.org/wikipedia/commons/thumb/2/25/Thompson-or.svg/453px-Thompson-or.svg.png)](https://en.wikipedia.org/wiki/File:Thompson-or.svg)

State *q* goes via ε either to the initial state of *N*(*s*) or *N*(*t*). Their final states become intermediate states of the whole NFA and merge via two ε-transitions into the final state of the NFA.

The **concatenation expression** *st* is converted to

[![inline](https://upload.wikimedia.org/wikipedia/commons/thumb/5/55/Thompson-concat.svg/398px-Thompson-concat.svg.png)](https://en.wikipedia.org/wiki/File:Thompson-concat.svg)

The **[Kleene star](https://en.wikipedia.org/wiki/Kleene_star) expression** $s^*$ is converted to

[![inline](https://upload.wikimedia.org/wikipedia/commons/thumb/8/8e/Thompson-kleene-star.svg/503px-Thompson-kleene-star.svg.png)](https://en.wikipedia.org/wiki/File:Thompson-kleene-star.svg)

An ε-transition connects initial and final state of the NFA with the sub-NFA *N*(*s*) in between. Another ε-transition from the inner final to the inner initial state of *N*(*s*) allows for repetition of expression *s* according to the star operator.



## 素材

codeguru [**Write Your Own Regular Expression Parser**](https://www.codeguru.com/cplusplus/write-your-own-regular-expression-parser/)

https://se.ifmo.ru/~ad/Documentation/Mastering_RegExp/mastregex2-CHP-4.html

https://devopedia.org/regex-engines

wikipedia [Comparison of regular expression engines](https://en.wikipedia.org/wiki/Comparison_of_regular_expression_engines) 

Gregory-Cernera: 

- [niemaattarian](https://github.com/niemaattarian)/**[Thompsons-Construction-on-NFAs](https://github.com/niemaattarian/Thompsons-Construction-on-NFAs)**

- medium [**Visualizing Thompson’s Construction Algorithm for NFAs, step-by-step**](https://medium.com/swlh/visualizing-thompsons-construction-algorithm-for-nfas-step-by-step-f92ef378581b)

- medium [Converting Regular Expressions to Postfix Notation with the Shunting-Yard Algorithm](https://gregorycernera.medium.com/converting-regular-expressions-to-postfix-notation-with-the-shunting-yard-algorithm-63d22ea1cf88)


