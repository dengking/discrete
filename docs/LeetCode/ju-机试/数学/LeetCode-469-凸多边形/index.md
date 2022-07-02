# [469. 凸多边形](https://leetcode.cn/problems/convex-polygon/) 中等

给定 **X-Y** 平面上的一组点 `points` ，其中 `points[i] = [xi, yi]`。这些点按顺序连成一个多边形。

如果该多边形为 **凸** 多边形[（凸多边形的定义）](https://baike.baidu.com/item/凸多边形/)则返回 `true` ，否则返回 `false` 。

你可以假设由给定点构成的多边形总是一个 简单的多边形[（简单多边形的定义）](https://baike.baidu.com/item/简单多边形)。你可以假设由给定点构成的多边形总是一个 简单的多边形[（简单多边形的定义）](https://baike.baidu.com/item/简单多边形)。

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/04/09/covpoly1-plane.jpg)

```
输入: points = [[0,0],[0,5],[5,5],[5,0]]
输出: true
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2021/04/09/covpoly2-plane.jpg)

```
输入: points = [[0,0],[0,10],[10,10],[10,0],[5,5]]
输出: false
```

## 原理

如下内容中讲述了原理：

1、[凸多边形](https://leetcode.cn/problems/convex-polygon/solution/tu-duo-bian-xing-by-617076674/)

2、[严谨点 不是斜率 不是内积 而是叉乘](https://leetcode.cn/problems/convex-polygon/solution/yan-jin-dian-bu-shi-xie-lu-bu-shi-nei-ji-er-shi-ch/)

### baike [凸多边形](https://baike.baidu.com/item/%E5%87%B8%E5%A4%9A%E8%BE%B9%E5%BD%A2/6608474)

任意一条边向两方无限延长成为一[直线](https://baike.baidu.com/item/直线/4876)时，其他各边都在此直线的同旁，那么这个多边形就叫做凸多边形

> NOTE: 
>
> 上面这段话非常重要，它可以作为判断凸多边形的一种方式

#### 判断

3）顶点凹凸性法

利用以当前顶点为中心的矢量叉乘或者计算三角形的有符号面积判断多边形的方向以及当前顶点的凹凸性。

假设当前连续的三个顶点分别是P1，P2，P3。计算向量P1P2,P2P3的叉乘，也可以计算三角形P1P2P3的面积，得到的结果如果大于0，则表示P3点在线段P1和P2的左侧，多边形的顶点是逆时针序列。然后依次计算下一个前后所组成向量的叉乘，如果在计算时，出现负值，则此多边形时凹多边形，如果所有顶点计算完毕，其结果都是大于0，则多边形时凸多边形。

> NOTE:
>
> 其实这种判定方式相对而言是比较容易理解的，其实就是沿着一个方向旋转，如果是凸多边形，则相邻边叉乘的符号一致，否则就是不一致的。

### baike [向量积](https://baike.baidu.com/item/%E5%90%91%E9%87%8F%E7%A7%AF/4601007?fr=aladdin)

#### 坐标运算

设 ![img](https://bkimg.cdn.bcebos.com/formula/bb2c1068e052b198e5408d5c2a5d9b03.svg) 。**i**，**j**，**k**分别是X，Y，Z轴方向的单位向量，则 [1] ：

**a**×**b**=（![img](https://bkimg.cdn.bcebos.com/formula/7526803cc41620428ca98daf1ec30e7d.svg) ）**i+**（![img](https://bkimg.cdn.bcebos.com/formula/c4b6a750031de374d85cc45aebeb4e24.svg)）**j**+（ ![img](https://bkimg.cdn.bcebos.com/formula/a0f91e3144890a6dcf844ecd4dd77a9d.svg) ）**k**，为了帮助记忆，利用三阶[行列式](https://baike.baidu.com/item/行列式)，

写成det ![img](https://bkimg.cdn.bcebos.com/formula/8e096262cb70ac0fcad351e3322e0c0d.svg)  

![img](https://bkimg.cdn.bcebos.com/formula/dfc47920fd226ea5f96e5c0119e38535.svg)

利用三阶行列式，写成det

![img](https://bkimg.cdn.bcebos.com/formula/b5bd4e3f359243f96092c0e72a140fc4.svg)





### CSDN [向量点乘（内积）和叉乘（外积、向量积）概念及几何意义解读](https://blog.csdn.net/houyichaochao/article/details/81141893?spm=1001.2101.3001.4242)

**叉乘公式**

两个向量的[叉乘](https://so.csdn.net/so/search?q=叉乘&spm=1001.2101.3001.7020)，又叫向量积、外积、叉积，叉乘的运算结果是一个向量而不是一个标量。并且两个向量的叉积与这两个向量组成的坐标平面垂直。

## [powcai](https://leetcode.cn/u/powcai/) [叉乘](https://leetcode.cn/problems/convex-polygon/solution/cha-cheng-by-powcai/)

叉乘判断

设`A(x1,y1),B(x2,y2),C(x3,y3)`,则三角形两边的矢量分别是:

`AB=(x2-x1,y2-y1), AC=(x3-x1,y3-y1)`

则`AB`和`AC`的叉积为：(`2*2`的行列式) 值为：`(x2-x1)*(y3-y1) - (y2-y1)*(x3-x1)`

利用右手法则进行判断：

如果`AB*AC>0`,则三角形ABC是逆时针的

如果`AB*AC<0`,则三角形ABC是顺时针的

因为不知道顶点是顺时针输入，还是逆时针输入，所以要记录符号，后面点叉乘如果一样就是凸多边形。

```python
class Solution:
    def isConvex(self, points: List[List[int]]) -> bool:
        def cal_cross_product(A, B, C):
            AB = [B[0] - A[0], B[1] - A[1]]
            AC = [C[0] - A[0], C[1] - A[1]]
            return AB[0] * AC[1] - AB[1] * AC[0]

        flag = 0
        n = len(points)
        for i in range(n):
            # cur > 0 表示points是按逆时针输出的;cur < 0,顺时针
            cur = cal_cross_product(points[i], points[(i + 1) % n], points[(i + 2) % n])
            if cur != 0:
                # 说明异号, 说明有个角大于180度
                if cur * flag < 0:
                    return False
                else:
                    flag = cur
        return True

```



## 我的解题

参考的：[powcai](https://leetcode.cn/u/powcai/) [叉乘](https://leetcode.cn/problems/convex-polygon/solution/cha-cheng-by-powcai/)

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
  bool isConvex(vector<vector<int> > &points)
  {
    int N = points.size();
    long prev = 0;
    for (int i = 0; i < N; ++i)
    {
      // 每个点和它后面的两个点所组成的两条边
      long cur = crossProduct(points[i], points[(i + 1) % N], points[(i + 2) % N]);
      if (cur != 0)
      {
        if (prev * cur < 0) // 两者异号
          return false;
        else
          prev = cur;
      }
    }
    return true;
  }

  long crossProduct(vector<int> &a, vector<int> &b, vector<int> &c)
  {
    long ac_x = c[0] - a[0];
    long ac_y = c[1] - a[1];

    long ab_x = b[0] - a[0];
    long ab_y = b[1] - a[1];
    return ab_x * ac_y - ab_y * ac_x;
  }
};

int main()
{
  Solution s;
}

```

