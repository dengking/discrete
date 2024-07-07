# baike [catalan](https://baike.baidu.com/item/catalan/7605685?fr=aladdin)

 

 **卡塔兰数**是[组合数学](https://baike.baidu.com/item/组合数学/821134)中一个常在各种计数问题中出现的[数列](https://baike.baidu.com/item/数列/731531)。以[比利时](https://baike.baidu.com/item/比利时/421128)的数学家欧仁·查理·卡塔兰（1814–1894）命名。历史上，清代数学家[明安图](https://baike.baidu.com/item/明安图/24682)(1692年－1763年)在其《[割圜密率捷法](https://baike.baidu.com/item/割圜密率捷法/14592102)》最早用到“卡塔兰数”，远远早于卡塔兰。有中国学者建议将此数命名为“明安图数”或“明安图-卡塔兰数”。卡塔兰数的一般公式为 C(2n,n)/(n+1)。 

## 性质

令h(0)=1,h(1)=1，卡塔兰数满足[递归](https://baike.baidu.com/item/递归/1740695)式：

**h(n)= h(0)\*h(n-1) + h(1)\*h(n-2) + ... + h(n-1)h(0) (其中n>=2),这是n阶[递推](https://baike.baidu.com/item/递推/4506973)关系;**

**还可以化简为1阶递推关系: 如h(n)=(4n-2)/(n+1)\*h(n-1)(n>1) h(0)=1**

该递推关系的解为：**h(n)=****C(2n,n)/(n+1)=P(2n,n)/(n+1)!=(2n)!/(n!\*(n+1)!)** **(n=1,2,3,...)**

卡塔兰数列的前几项为(sequence A 0 0 0 1 0 8 in OEIS) [注： n = 0, 1, 2, 3, … n]

## 理解应用和公式推导

### 出栈次序问题

 一个栈([无穷大](https://baike.baidu.com/item/无穷大))的进栈序列为1,2,3,..n,有多少个不同的出栈序列? 

### 关于这个问题的5种变型

####  (2).找零钱（找一半） 

 有2n个人排成一行进入剧场。入场费5元。其中只有n个人有一张5元钞票，另外n人只有10元钞票，剧院无其它钞票，问有多少中方法使得只要有10元的人买票，售票处就有5元的钞票找零？ 

####  (3).三角网格 

[![img](https://gss0.bdstatic.com/94o3dSag_xI4khGkpoWK1HF6hhy/baike/s%3D220/sign=2b7d4be5f6dcd100c99cff23428947be/83025aafa40f4bfbeb577fbc0d4f78f0f6361856.jpg)](https://baike.baidu.com/pic/catalan/7605685/0/83025aafa40f4bfbeb577fbc0d4f78f0f6361856?fr=lemma&ct=single)

形如这样的直角三角形网格，从左上角开始，只能向右走和向下走，问总共有多少种走法？

####  (4).括号排列 

矩阵连乘：

![img](https://gss3.bdstatic.com/7Po3dSag_xI4khGkpoWK1HF6hhy/baike/pic/item/d043ad4bd11373f08d958b77aa0f4bfbfaed04ab.jpg)

 ，共有（n+1）项，依据[乘法结合律](https://baike.baidu.com/item/乘法结合律)