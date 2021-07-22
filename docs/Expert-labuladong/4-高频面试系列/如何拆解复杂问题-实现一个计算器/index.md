# labuladong [如何拆解复杂问题：实现一个计算器](https://mp.weixin.qq.com/s/ds0guq9gPTLIHLEQnFxZVQ)



那么，我们最终要实现的计算器功能如下：

***1、***输入一个字符串，可以包含`+ - * / ()`、数字、空格，你的算法返回运算结果。

***2、***要符合运算法则，括号的优先级最高，先乘除后加减。

***3、***除号是整数除法，无论正负都向 0 取整（`5/2=2`，`-5/2=-2`）。

***4、***可以假定输入的算式一定合法，且计算过程不会出现**整型溢出**，不会出现除数为 0 的意外情况。

比如输入如下字符串，算法会返回 9：

```c++
3 * (2-6 /(3 -7))
```

那么本文就来聊聊怎么实现上述一个功能完备的计算器功能，**关键在于层层拆解问题，化整为零，逐个击破**，相信这种思维方式能帮大家解决各种复杂问题。

下面就来拆解，从最简单的一个问题开始。

## 一、字符串转整数

是的，就是这么一个简单的问题，首先告诉我，怎么把一个字符串形式的**正**整数，转化成 int 型？

```c++
string s = "458";

int n = 0;
for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    n = 10 * n + (c - '0');
}
// n 现在就等于 458
```

这个还是很简单的吧，老套路了。但是即便这么简单，依然有坑：**`(c - '0')`的这个括号不能省略，否则可能造成整型溢出**。

因为变量`c`是一个 ASCII 码，如果不加括号就会先加后减，想象一下`n`如果接近 `INT_MAX`，就会溢出。所以用括号保证先减后加才行。

## 二、处理加减法

现在进一步，**如果输入的这个算式只包含加减法，而且不存在空格**，你怎么计算结果？我们拿字符串算式`1-12+3`为例，来说一个很简单的思路：

***1、***先给第一个数字加一个默认符号`+`，变成`+1-12+3`。

***2、***把一个运算符和数字组合成一对儿，也就是三对儿`+1`，`-12`，`+3`，把它们转化成数字，然后放到一个栈中。

***3、***将栈中所有的数字求和，就是原算式的结果。

我们直接看代码，结合一张图就看明白了：

```C++
/**
 * @brief 对于形如 "-1+2" 的这种情况，按照下面的程序逻辑，会先将  `num` 的初始值即"0" 加入到栈中，显然这不会对结果造成任何的影响
 *
 * @param s
 * @return
 */
int calculate(string s)
{
	stack<int> stk;
	int num = 0; // 记录算式中的数字
	char sign = '+'; // 记录 num 前的符号, 初始化为 +
	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];

		if (isdigit(c)) // 如果是数字, 连续读取到 num
		{
			num = 10 * num + (c - '0');
		}
		else
		{
			// 如果不是数字, 就是遇到了下一个符号,
			// 之前的数字和符号就要存进栈中
			if (!isdigit(c) || i == s.size() - 1)
			{
				// 将之前的数字和符号存进栈中
				switch (sign)
				{
					case '+':
						stk.push(num);
						break;
					case '-':
						stk.push(-num);
						break;
				}
				// 更新符号为当前符号, 数字清零
				sign = c;
				num = 0;
			}
		}
	}
	// 将栈中所有结果求和就是答案
	int res = 0;
	while (!stk.empty())
	{
		res += stk.top();
		stk.pop();
	}
	return res;
}

```

> NOTE: 
>
> 一、下面是根据上述code进行改写的，相对而言，可读性更佳:
>
> ```C++
> /**
>  * @brief 对于形如 "-1+2" 的这种情况，按照下面的程序逻辑，会先将  `num` 的初始值即"0" 加入到栈中，显然这不会对结果造成任何的影响
>  *
>  * @param s
>  * @return
>  */
> int calculate(string s)
> {
> 	stack<int> stk;
> 	int num = 0; // 记录算式中的数字
> 	char sign = '+'; // 记录 num 前的符号, 初始化为 +
> 	for (int i = 0; i < s.size(); i++)
> 	{
> 		char c = s[i];
> 
> 		if (isdigit(c)) // 如果是数字, 连续读取到 num
> 		{
> 			num = 10 * num + (c - '0');
> 		}
> 		else
> 		{
> 			// 如果不是数字, 就是遇到了下一个符号,
> 			// 之前的数字和符号就要存进栈中
> 			if (!isdigit(c) || i == s.size() - 1) // 遇到新的符号、到达了末尾都触发进栈
> 			{
> 				// 将之前的数字和符号存进栈中
> 				switch (sign)
> 				{
> 					case '+':
> 						stk.push(num);
> 						break;
> 					case '-':
> 						stk.push(-num);
> 						break;
> 				}
> 				// 更新符号为当前符号, 数字清零
> 				sign = c;
> 				num = 0;
> 			}
> 		}
> 	}
> 	// 将栈中所有结果求和就是答案
> 	int res = 0;
> 	while (!stk.empty())
> 	{
> 		res += stk.top();
> 		stk.pop();
> 	}
> 	return res;
> }
> 
> ```
>
> 

我估计就是中间带`switch`语句的部分有点不好理解吧，**`i`就是从左到右扫描，`sign`和`num`跟在它身后。**当`s[i]`遇到一个运算符时，情况是这样的：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdHkrHcjbgpQW7OC3rxGgxibfCkNiazWFpovic0DB9o2sNyXBZr6mDqrGsicba4IdOUlNyibKCmRjsPGEOQ/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

所以说，此时要根据`sign`的 case 不同选择`nums`的正负号，存入栈中，然后更新`sign`并清零`nums`记录下一对儿符合和数字的组合。

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdHkrHcjbgpQW7OC3rxGgxibfqkywd9icVBLmRlGcAKcXOV6VpcgEUzx9sv3mLGgOgibOq2JN6xVzIF3A/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

另外注意，不只是遇到新的符号会触发入栈，当`i`走到了算式的尽头（`i == s.size() - 1`），也应该将前面的数字入栈，方便后续计算最终结果。

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdHkrHcjbgpQW7OC3rxGgxibfNXQaESlGibtuQBPof76RRBzJZuzeDHCVdP2zNU9GpTgOZhTicMohuKbg/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

至此，仅处理紧凑加减法字符串的算法就完成了，请确保理解以上内容，后续的内容就基于这个框架修修改改就完事儿了。

## 三、处理乘除法

其实思路跟仅处理加减法没啥区别，拿字符串`2-3*4+5`举例，核心思路依然是把字符串分解成符号和数字的组合。

比如上述例子就可以分解为`+2`，`-3`，`*4`，`+5`几对儿，我们刚才不是没有处理乘除号吗，很简单，**其他部分都不用变**，在`switch`部分加上对应的 case 就行了：





### 如何处理空格字符

现在我们**思考一下****如何处理字符串中可能出现的空格字符**。其实也非常简单，想想空格字符的出现，会影响我们现有代码的哪一部分？

```c++
// 如果 c 非数字
if (!isdigit(c) || i == s.size() - 1) {
    switch (c) {...}
    sign = c;
    num = 0;
}
```

显然空格会进入这个 if 语句，但是我们并不想让空格的情况进入这个 if，因为这里会更新`sign`并清零`nums`，空格根本就不是运算符，应该被忽略。

那么只要多加一个条件即可：

```C++
if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
    ...
}
```

好了，现在我们的算法已经可以按照正确的法则计算加减乘除，并且自动忽略空格符，剩下的就是如何让算法正确识别括号了。

## 四、处理括号

处理算式中的括号看起来应该是最难的，但真没有看起来那么难。

为了规避编程语言的繁琐细节，我把前面解法的代码翻译成 Python 版本：

```python
def calculate(s: str) -> int:

    def helper(s: List) -> int:
        stack = []
        sign = '+'
        num = 0

        while len(s) > 0:
            c = s.pop(0)
            if c.isdigit():
                num = 10 * num + int(c)

            if (not c.isdigit() and c != ' ') or len(s) == 0:
                if sign == '+':
                    stack.append(num)
                elif sign == '-':
                    stack.append(-num)
                elif sign == '*':
                    stack[-1] = stack[-1] * num
                elif sign == '/':
                    # python 除法向 0 取整的写法
                    stack[-1] = int(stack[-1] / float(num))                    
                num = 0
                sign = c

        return sum(stack)
    # 需要把字符串转成列表方便操作
    return helper(list(s))
```

这段代码跟刚才 C++ 代码完全相同，唯一的区别是，不是从左到右遍历字符串，而是不断从左边`pop`出字符，本质还是一样的。

