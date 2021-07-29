# DFA

在 LeetCode [8. 字符串转换整数 (atoi)](https://leetcode-cn.com/problems/string-to-integer-atoi/)  # [官方解题](https://leetcode-cn.com/problems/string-to-integer-atoi/solution/zi-fu-chuan-zhuan-huan-zheng-shu-atoi-by-leetcode-/) 中，[Edward Elric](https://leetcode-cn.com/u/zdxiq125/) 有如下评论:

> 准确地说，这是确定有限状态机（deterministic finite automaton, DFA）。其实这题已经不算是容易写“出臃肿代码”的了。考虑清楚边界（主要是溢出处理）和输入种类（+, -, 0-9以及其他），大概在20行内完成代码不难。说实话LC官方题解里很少见给出标准DFA解法的，点个赞。另外看到评论区乌烟瘴气的，真让人唏嘘（没有一点基本的敬畏心、浮躁功利、认为题目边界太复杂导致自己不能AC，那是何其自负）。给两个更加需要DFA的题目吧：[utf-8-validation](https://leetcode-cn.com/problems/utf-8-validation/) ( [附dfa解法](https://leetcode-cn.com/problems/utf-8-validation/solution/java-dfa-by-zdxiq125/) ) 以及 [valid-number](https://leetcode-cn.com/problems/valid-number/)

 这让我发现了DFA在LeetCode中的应用，下面是相关试题:

1、LeetCode [8. 字符串转换整数 (atoi)](https://leetcode-cn.com/problems/string-to-integer-atoi/)  中等

2、LeetCode [393. UTF-8 编码验证](https://leetcode-cn.com/problems/utf-8-validation/) 中等

3、LeetCode [65. 有效数字](https://leetcode-cn.com/problems/valid-number/) 困难



## 分析 与 实现

DFA是一个graph，DFA的构成: 

一、输入的种类

从深入的种类入手是最快的，思考在各种输入的情况下，状态如何进行转换

二、节点: 状态

三、edge: 状态的转换 

