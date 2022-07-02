# LeetCode [279. 完全平方数](https://leetcode.cn/problems/perfect-squares/) 中等

leetcode [一篇文章吃透背包问题！（细致引入+解题模板+例题分析+代码呈现](https://leetcode.cn/problems/partition-equal-subset-sum/solution/yi-pian-wen-zhang-chi-tou-bei-bao-wen-ti-a7dd/) 

> 完全平方数：对于一个正整数n,找出若干个完全平方数使其和为n,返回完全平方数最少数量
> 完全背包的最值问题：完全平方数最小为1,最大为sqrt(n),故题目转换为在nums=[1,2.....sqrt(n)]中选任意数平方和为target=n
> 外循环nums,内循环target正序,应用转移方程1

