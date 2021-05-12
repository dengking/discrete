# Compared with brute-force search

通过与brute-force search来进行对比能够更加深入地理解backtracing、Branch-and-bound的思想：

总的来说，无论是backtracing还是branch-and-bound，都是充分运用已知信息来进行剪枝、进行优化、加速搜索，进而避免像暴力搜索那样搜索完整的解空间。

## 如何避免回溯

如何避免回溯？下面结合了例子进行了说明：

- KMP算法: https://www.cnblogs.com/dusf/p/kmp.html

