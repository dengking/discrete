# Algorithm





### [Newick format](https://en.wikipedia.org/wiki/Newick_format) *and* [Dyck language](https://en.wikipedia.org/wiki/Dyck_language)，

可以使用括号来表示树，这是源于[Newick format](https://en.wikipedia.org/wiki/Newick_format) *and* [Dyck language](https://en.wikipedia.org/wiki/Dyck_language)，如下是一些简单的例子：

`[[[]]]`对应的tree如下：

```
   
       []
      /
     /
   []
  /
 /
[]
```



可以看到，它已经退化成了一个list，这种属于使用tree来描述具有hierarchy structure的数据。

对于[Dyck language](https://en.wikipedia.org/wiki/Dyck_language)，在对其进行parsing的时候，需要使用stack，其实我们进行parsing的时候，是沿着树进行深度优先遍历，一般我们进行parsing时候，遇到开括号`[`是要继续压栈，其实看上图就可以知道，压栈对应着是沿着树路径向下，即不断地向下遍历。遇到闭括号`]`，其实是出栈，开始向上了。

### parenthesis and stack

|        |      |
| ------ | ---- |
| 正括号 | 入栈 |
| 反括号 | 出栈 |

stack的入栈与出栈是一对户逆的操作，所以stack非常适合于解决哪些存在着互逆操作的问题；



### 思考：如何使用递归来实现括号匹配？？

一般我们都是使用一个显示的stack，那么如何使用递归来使用call stack呢？



### TODO

geeksforgeeks [Binary tree to string with brackets](https://www.geeksforgeeks.org/binary-tree-string-brackets/)

geeksforgeeks [Construct Binary Tree from String with bracket representation](https://www.geeksforgeeks.org/construct-binary-tree-string-bracket-representation/)

