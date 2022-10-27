# labuladong [3 分钟看懂如何判断括号的合法性](https://mp.weixin.qq.com/s/o2MjTSIC4FkPscF5MnLXMQ)



## 一、处理一种括号



```c++
bool isValid(string str) {
    // 待匹配的左括号数量
    int left = 0;
    for (char c : str) {
        if (c == '(')
            left++;
        else // 遇到右括号
            left--;

        if (left < 0)
            return false;
    }
    return left == 0;
}
```

> NOTE:
>
> 需要注意，上述算法中
>
> ```c++
>         if (left < 0)
>             return false;
> ```
>
> 是非常重要的，因为它能够处理处理如下情况：
>
> ```c++
> ))((
> ```
>
> 如果不加上述情况，则会判断为true。
>
> 显然如果复合情况，则left是一直 >= 0 的。

## 二、处理多种括号



```c++
bool isValid(string str) {
    stack<char> left;
    for (char c : str) {
        if (c == '(' || c == '{' || c == '[')
            left.push(c);
        else // 字符 c 是右括号
            if (!left.empty() && leftOf(c) == left.top())
                left.pop();
            else
                // 和最近的左括号不匹配
                return false;
    }
    // 是否所有的左括号都被匹配了
    return left.empty();
}

char leftOf(char c) {
    if (c == '}') return '{';
    if (c == ')') return '(';
    return '[';
}
```

