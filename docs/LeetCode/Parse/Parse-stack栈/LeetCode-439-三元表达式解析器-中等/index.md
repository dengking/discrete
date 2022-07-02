# [439. 三元表达式解析器](https://leetcode.cn/problems/ternary-expression-parser/) 中等

给定一个表示任意嵌套三元表达式的字符串 `expression` ，求值并返回其结果。

你可以总是假设给定的表达式是有效的，并且只包含数字，`'?'` ， `':'` ， `'T'` 和 `'F'` ，其中 `'T'` 为真， `'F'` 为假。表达式中的所有数字都是 **一位** 数(即在 **[0,9]** 范围内)。

条件表达式从右到左分组(大多数语言中都是这样)，表达式的结果总是为数字 `'T'` 或 `'F'` 。

**示例 1：**

```
输入： expression = "T?2:3"
输出： "2"
解释： 如果条件为真，结果为 2；否则，结果为 3。
```

**示例 2：**

```
输入： expression = "F?1:T?4:5"
输出： "4"
解释： 条件表达式自右向左结合。使用括号的话，相当于：
 "(F ? 1 : (T ? 4 : 5))" --> "(F ? 1 : 4)" --> "4"
or "(F ? 1 : (T ? 4 : 5))" --> "(T ? 4 : 5)" --> "4"
```

**示例 3：**

```
输入： expression = "T?T?F:5:3"
输出： "F"
解释： 条件表达式自右向左结合。使用括号的话，相当于：
"(T ? (T ? F : 5) : 3)" --> "(T ? F : 3)" --> "F"
"(T ? (T ? F : 5) : 3)" --> "(T ? F : 5)" --> "F"
```

## 我的解题

```
Ternary -> (T|F)?(Ternary|[0-9]|T|F):(Ternary|[0-9]|T|F)
```

每匹配一个三元表达式，就evaluation。

下面是一个例子：

```
T?T?T?1:2:F?1:2:F?1:2:2
```

```
"F?T:F?T?1:2:F?3:4"
```

第一次解题，在下面的用例下出现错误 :

```
"(
    F?
        (T)
        :
        (F?(T?1:2):(F?3:4))
 )"
```



```C++
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
using namespace std;


class Solution {
public:
	string parseTernary(string expression) {
		int leftEnd = 0;
		return parseTernaryImpl(expression, 0, leftEnd);
	}
private:

	string parseTernaryImpl(string expression, int start, int& parsedEnd) {
		char firstChar = expression[start];

		string left;
		string right;
		if (start + 3 < expression.size() - 1) { // 是一个完整的ternary 
			// 解析左子树
			if (expression[start + 3] == ':') { // left是一个数
				left = expression[start + 2];
				parsedEnd = start + 2;
			}
			else if (expression[start + 3] == '?') { // left是ternary 
				left = parseTernaryImpl(expression, start + 2, parsedEnd);

			}
			else {
				throw runtime_error("");
			}
			// 解析右子树
			if ((parsedEnd + 3 < expression.size() - 1) && expression[parsedEnd + 3] == '?')  // right是ternary 
			{
				right = parseTernaryImpl(expression, parsedEnd + 2, parsedEnd);

			}
			else {
				right = expression[parsedEnd + 2];
				parsedEnd += 2;

			}

			if (firstChar == 'T') {
				return left;
			}
			else {
				return right;
			}
		}
		else { // 只是一个数
			throw runtime_error("");
		}
	}
};

int main()
{
	Solution s;
	cout << s.parseTernary("F?T:F?T?1:2:F?3:4") << endl;
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```

上述解法是基于recursion的，它需要处理嵌套关系。

## [见习魔法师~](https://leetcode.cn/u/jian-xi-mo-fa-shi-2/) #  [非常简单清晰的非递归O(n)解法](https://leetcode.cn/problems/ternary-expression-parser/solution/python-fei-chang-jian-dan-qing-xi-de-fei-di-gui-on/)

因为三元表达式是**从右向左**结合的, 如果**从左向右**扫描表达式, 则需要根据'`?`'和'`:`'来分离出每一个表达式, 比较复杂.

所以直接**从右向左**扫描表达式, 这样遇到的每一个`?`一定会是一个**最简三元表达式**:

```
T?T?F?7:T?T?F?3:F?T?0:1:0:6:1:0:5
```

> NOTE: 
>
> `T?0:1`就是第一个最简三元表达式

从右向左扫描, 第一个'?'代表的最简三元表达式: `T?0:1`, 得到结果是0:

现在这个源表达式变成了:
```
T?T?F?7:T?T?F?3:F?0:0:6:1:0:5
```
就这样迭代, 我们只需要在遇到'`?`'时直接解析当前这个最简三元表达式即可, 不用去考虑嵌套关系

```Python
class Solution:
    def parseTernary(self, expression: str) -> str:
        # 用来标记下一个遇到的字符是条件
        is_condition = 0
        stk = []
        # 因为是从右至左结合,所以也从右至左遍历
        for i in range(len(expression) - 1, -1, -1):
            if expression[i] == ':':
                continue
            elif expression[i] == '?':  # 标记下一个遇到的字符是条件
                is_condition = 1
            else:
                if is_condition:
                    if expression[i] == 'T':  # 说明栈中的第一个元素是结果, 但要把错误结果删掉
                        res = stk[-1]
                        stk.pop()
                        stk.pop()
                        stk.append(res)
                    else:  # 说明栈中第二个元素是结果, 删掉栈顶元素即可
                        stk.pop()
                    is_condition = 0
                else:  # 当前扫描到的元素不是条件, 就是直接入栈
                    stk.append(expression[i])
        return stk[-1]
```

### c++

```c++
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
using namespace std;


class Solution {
public:
	string parseTernary(string expression) {
		stack<char> st;
		bool is_condition = false;
		for (int i = expression.size() - 1; i >= 0; --i) {
			if (expression[i] == ':') {
				continue;
			}
			else if (expression[i] == '?') {
				is_condition = true;
			}
			else {
				if (is_condition) {
					is_condition = false;
					if (expression[i] == 'T') {
						char res = st.top();
						st.pop();
						st.pop();//将false分支弹出栈
						st.push(res);
					}
					else if (expression[i] == 'F') {
						st.pop();
					}
					else {
						std::abort();
					}
				}
				else {
					st.push(expression[i]);
				}
			}
		}
		string s(1, st.top());
		return s;
	}
};

int main()
{
	Solution s;
	cout << s.parseTernary("F?T:F?T?1:2:F?3:4") << endl;
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```

