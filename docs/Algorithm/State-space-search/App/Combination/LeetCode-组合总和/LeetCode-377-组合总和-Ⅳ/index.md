# leetcode [377. 组合总和 Ⅳ](https://leetcode-cn.com/problems/combination-sum-iv/)





上述做法是否考虑到选取元素的顺序？答案是肯定的。因为外层循环是遍历从 `1` 到 $\textit{target}$ 的值，内层循环是遍历数组 $\textit{nums}$ 的值，在计算 $\textit{dp}[i]$ 的值时，$\textit{nums}$ 中的每个小于等于 $i$ 的元素都可能作为元素之和等于 $i$ 的排列的最后一个元素。例如，$1$ 和 $3$ 都在数组 $\textit{nums}$ 中，计算 $\textit{dp}[4]$ 的时候，排列的最后一个元素可以是 $1$ 也可以是 $3$，因此 $\textit{dp}[1]$ 和 $\textit{dp}[3]$ 都会被考虑到，即不同的顺序都会被考虑到。



## 结合具体的例子

```
nums = [1,2,3], target = 4
```



```
target = 1
num = 1
dp[1] = dp[1-1] = dp[0] = 1
```



```
target = 2

num = 1
dp[2] += dp[2-1] = dp[1] = 0 + 1 = 1 # 对应序列1，1

num = 2
dp[2] += dp[2-2] = dp[0] = 1 + 1 = 2 # 对应序列2
```



```
target = 3

num = 1
dp[3] += dp[3-1] = dp[2] = 2 # 对应序列1，1, 1;2,1

num = 2
dp[3] += dp[3-2] = dp[1] = 1 # 对应序列2,1

num = 3
dp[3] += dp[3-3] = dp[0] = 1 # 对应序列2
```

显然，1，2和2，1分别被计数了一次。



```
target = 4

num = 1
dp[4] += dp[3-1] = dp[2] = 1 # 对应序列1，1

num = 2
dp[4] += dp[3-2] = dp[1] = 1 # 对应序列2

num = 3
dp[4] += dp[3-3] = dp[0] = 1 # 对应序列2
```



```
target = 5

num = 1
dp[5] += dp[3-1] = dp[2] = 1 # 对应序列1，1

num = 2
dp[5] += dp[3-2] = dp[1] = 1 # 对应序列2

num = 3
dp[5] += dp[3-3] = dp[0] = 1 # 对应序列2
```

