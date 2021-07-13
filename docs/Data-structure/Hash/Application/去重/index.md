# 用hash 去重

主要是基于hash comparison。

一、用checksum来寻找重复的文件

参见: `Use-checksum-to-find-duplicate-file`



二、用hash来寻找重复的值

1、hash能够保证相同值的hash是相同的，这就能够让我们快速地分析重复值，虽然不同值的hash可能相同，即发生collision(碰撞)，但是一般，collision的概率是低的，可以通过"value比较"来判断发生collision的value是否相等。在实现上，是可以结合"hash + value比较"实现较高效的去重的。

## codingforspeed [C++ Coding Example, Using Hash Algorithm to Remove Duplicate Number by O(n)](https://codingforspeed.com/c-coding-example-using-hash-algorithm-to-remove-duplicate-number-by-on/)

