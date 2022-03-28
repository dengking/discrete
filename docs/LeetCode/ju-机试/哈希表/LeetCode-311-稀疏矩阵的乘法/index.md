# [311. 稀疏矩阵的乘法](https://leetcode-cn.com/problems/sparse-matrix-multiplication/) 中等

给定两个 [稀疏矩阵](https://baike.baidu.com/item/稀疏矩阵) : 大小为 `m x k` 的稀疏矩阵 `mat1` 和大小为 `k x n` 的稀疏矩阵 `mat2`，大小为 `m x k` 的稀疏矩阵 `mat1` 和大小为 `k x n` 的稀疏矩阵 `mat2`。你可以假设乘法总是可能的。

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/03/12/mult-grid.jpg)

```
输入：mat1 = [[1,0,0],[-1,0,3]], mat2 = [[7,0,0],[0,0,0],[0,0,1]]
输出：[[7,0,0],[-7,0,3]]
```

**示例 2:**

```
输入：mat1 = [[0]], mat2 = [[0]]
输出：[[0]]
```

## 我的解题



### 第一次解题 暴力解法

```c++
#include <iostream>
#include <vector>
#include <utility> // std::pair
#include <unordered_map>
#include <string>
#include <map>
#include <climits> // INT_MAX
using namespace std;

class Solution
{
public:
  vector<vector<int> > multiply(vector<vector<int> > &mat1, vector<vector<int> > &mat2)
  {
    int mat1row_n = mat1.size();

    int mat2col_n = mat2[0].size();

    vector<vector<int> > res(mat1row_n, vector<int>(mat2col_n, 0));
    for (int mat1row_i = 0; mat1row_i < mat1row_n; ++mat1row_i)
    {
      for (int mat2col_i = 0; mat2col_i < mat2col_n; ++mat2col_i)
      {
        res[mat1row_i][mat2col_i] = multiply(mat1, mat1row_i, mat2, mat2col_i);
      }
    }
    return res;
  }
  int multiply(vector<vector<int> > &mat1, int row_i, vector<vector<int> > &mat2, int col_i)
  {
    int res = 0;
    int mat1col_n = mat1[0].size();

    // mat1[row_i][];
    // mat2[][col_i];
    for (int i = 0; i < mat1col_n; ++i) // mat2 的每一列
    {
      res += mat1[row_i][i] * mat2[i][col_i];
    }
    return res;
  }
};

int main()
{
}

```

上述解法并没有使用什么技巧，但是也通过了。

### 第二次解题

```c++
#include <iostream>
#include <vector>
#include <utility> // std::pair
#include <unordered_map>
#include <string>
#include <map>
#include <climits> // INT_MAX
using namespace std;

class Solution
{
public:
  vector<vector<int> > multiply(vector<vector<int> > &mat1, vector<vector<int> > &mat2)
  {
    int mat1row_n = mat1.size();
    int mat1col_n = mat1[0].size();
    unordered_map<int, unordered_map<int, int> > mat1_rep; // row、col、val
    for (int i = 0; i < mat1row_n; ++i)
      for (int j = 0; j < mat1col_n; ++j)
      {
        if (mat1[i][j])
        {
          mat1_rep[i][j] = mat1[i][j];
        }
      }
    int mat2row_n = mat2.size();
    int mat2col_n = mat2[0].size();
    unordered_map<int, unordered_map<int, int> > mat2_rep; // col、row、val
    for (int i = 0; i < mat2row_n; ++i)
      for (int j = 0; j < mat2col_n; ++j)
      {
        if (mat2[i][j])
        {
          mat2_rep[j][i] = mat2[i][j];
        }
      }
    vector<vector<int> > res(mat1row_n, vector<int>(mat2col_n, 0));
    for (int mat1row_i = 0; mat1row_i < mat1row_n; ++mat1row_i)
    {
      if (!mat1_rep.count(mat1row_i))
        continue;
      auto &row = mat1_rep[mat1row_i];
      for (int mat2col_i = 0; mat2col_i < mat2col_n; ++mat2col_i)
      {
        if (!mat2_rep.count(mat2col_i))
          continue;
        auto &col = mat2_rep[mat2col_i];
        for (auto &&row_i : row)
        {
          if (col.count(row_i.first))
          {
            res[mat1row_i][mat2col_i] += row_i.second * col[row_i.first];
          }
        }
      }
    }
    return res;
  }
};

int main()
{
}

```



## 稀疏矩阵的乘法优化

首先转换为三元组表示，然后基于三元组表示进行乘法。

在如下文章中给出了稀疏矩阵的三元组表示例子：

1、[先生成稀疏的三元组表示，再逐对运算](https://leetcode-cn.com/problems/sparse-matrix-multiplication/solution/xian-sheng-cheng-xi-shu-de-san-yuan-zu-biao-shi-za/)

2、[Java 哈希表解法详细题解](https://leetcode-cn.com/problems/sparse-matrix-multiplication/solution/java-ha-xi-biao-jie-fa-xiang-xi-ti-jie-b-jtie/)

相比之下，我觉得 [先生成稀疏的三元组表示，再逐对运算](https://leetcode-cn.com/problems/sparse-matrix-multiplication/solution/xian-sheng-cheng-xi-shu-de-san-yuan-zu-biao-shi-za/) 中的解法更优。

## [Java 哈希表解法详细题解](https://leetcode-cn.com/problems/sparse-matrix-multiplication/solution/java-ha-xi-biao-jie-fa-xiang-xi-ti-jie-b-jtie/)

1、什么是稀疏矩阵？

在矩阵中，若数值为0的元素数目远远多于非0元素的数目，并且非0元素分布没有规律时，则称该矩阵为**稀疏矩阵**

2、稀疏矩阵可以用三元组存储 （行标， 列标， 值）

因为矩阵的乘法是第一个矩阵的行和第二个矩阵的列相乘，所以我们建立两个哈希表分别存储第一个矩阵的值和第二个矩阵的值。

矩阵1的哈希表格式`Map<行标, Map<列标，值>>`

矩阵2的哈希表格式`Map<列标, Map<行标，值>>`

> NOTE: 
>
> 一、上述定义是按照第一个矩阵的行会和第二个矩阵的列进行相乘来定义的

```C++
class Solution {
    public int[][] multiply(int[][] mat1, int[][] mat2) {
        Map<Integer, Map<Integer, Integer>> map1 = new HashMap<>();
        Map<Integer, Map<Integer, Integer>> map2 = new HashMap<>();
        //构造矩阵1的哈希表        
        //矩阵1的哈希表格式Map<行标, Map<列标，值>>
        for(int i = 0; i < mat1.length; i++){
            map1.put(i, new HashMap<>());
            for(int j = 0; j < mat1[i].length; j++){
                if(mat1[i][j] != 0){
                    map1.get(i).put(j, mat1[i][j]);
                }
            }
        }
        //构造矩阵2的哈希表        
        //矩阵2的哈希表格式Map<列标, Map<行标，值>> 
        for(int i = 0; i < mat2.length; i++){
            for(int j = 0; j < mat2[i].length; j++){
                if(mat2[i][j] != 0){
                    if(!map2.containsKey(j))
                        map2.put(j, new HashMap<>());
                    map2.get(j).put(i, mat2[i][j]);
                }
            }
        }

        int[][] res = new int[mat1.length][mat2[0].length];
        for(int i = 0; i < mat1.length; i++){
            for(int j = 0; j < mat2[0].length; j++){
                Map<Integer, Integer> row = map1.get(i);
                Map<Integer, Integer> col = map2.get(j);
                for(int rowIndex : row.keySet()){
                    if(col != null && col.containsKey(rowIndex))
                        res[i][j] += row.get(rowIndex) * col.get(rowIndex);
                }
            }
        }
        return res;
    }
}

```



## [先生成稀疏的三元组表示，再逐对运算](https://leetcode-cn.com/problems/sparse-matrix-multiplication/solution/xian-sheng-cheng-xi-shu-de-san-yuan-zu-biao-shi-za/)

```c++
class Solution(object):
    def multiply(self, A, B):
        """
        :type A: List[List[int]]
        :type B: List[List[int]]
        :rtype: List[List[int]]
        """
        m = len(A)
        n = len(B[0])
        posA = self.getSparseRepresentation(A)
        posB = self.getSparseRepresentation(B)
        res = [[0 for i in range(n)] for j in range(m)]
        for valA, xA, yA in posA:
            for valB, xB, yB in posB:
                if yA == xB: # 表示两者是需要相乘
                    res[xA][yB] += valA * valB
        return res

    def getSparseRepresentation(self, A):
        posList = []
        m = len(A)
        n = len(A[0])
        for i in range(m):
            for j in range(n):
                if A[i][j] != 0:
                    posList.append([A[i][j], i, j])
        return posList

```

> NOTE:
>
> 上述代码简介清晰



## [两种方法，一种直接实现矩阵乘法，一种基于稀疏矩阵实现](https://leetcode-cn.com/problems/sparse-matrix-multiplication/solution/liang-chong-fang-fa-yi-chong-zhi-jie-shi-xian-ju-z/)

[https://blog.csdn.net/weixin_44171872/article/details/108670985](https://leetcode-cn.com/link/?target=https://blog.csdn.net/weixin_44171872/article/details/108670985)

### 方法1：

主要思路：
（1）直接模拟矩阵的乘法，计算出结果即可；

```c++
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res(A.size(),vector<int>(B[0].size()));//定义需要的特定大小的矩阵
        //实现矩阵的乘法
        for(int i=0;i<A.size();++i){
            for(int j=0;j<B[0].size();++j){
                for(int k=0;k<A[0].size();++k){
                    res[i][j]+=A[i][k]*B[k][j];
                }
            }
        }
        return res;
    }
};

```

### 方法2：

既然稀疏矩阵中的大部分元素是0，而0的乘法是可以忽略的，故可以先对两个数组中的非零元素进行统计，获得非零元素的位置，然后再在乘法中，只处理这些非零元素即可；