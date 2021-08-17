# 前言

在阅读[Neural Networks Tutorial – A Pathway to Deep Learning](https://adventuresinmachinelearning.com/neural-networks-tutorial/)的[4.1 A simple example in code](https://adventuresinmachinelearning.com/neural-networks-tutorial/#simple-example)小节的时候，其中的例子：

```python
x_old = 0 # The value does not matter as long as abs(x_new - x_old) > precision
x_new = 6 # The algorithm starts at x=6
gamma = 0.01 # step size
precision = 0.00001

def df(x):
    y = 4 * x**3 - 9 * x**2
    return y

while abs(x_new - x_old) > precision:
    x_old = x_new
    x_new += -gamma * df(x_old)

print("The local minimum occurs at %f" % x_new)
```

这是典型的通过不断进行迭代，从而计算得到最值的方法；在algorithm领域这叫什么呢？以我的直觉来看，我暂时叫做它：iterative optimization algorithm；它有些贪心算法的意味；