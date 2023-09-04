# [jianshu-背包问题九讲 超全归纳](https://www.jianshu.com/p/830de6df0207) 

背包问题一般套路：

```cpp
for 物品
    for 体积
        for 决策
```





## 1. 01背包



### 01背包朴素

*状态表示* ： `dp [ i ][ j ]` **只从前 i 个物品中选**，**总体积不超过 j** 的选法的集合。
 *属性*： ![MAX](https://math.jianshu.com/math?formula=MAX)
 *状态计算*：

- $dp[i][j]=max(dp[i-1][j],dp[i-1][j-c[i]]+w[i])$
- ![dp[i-1][j]](https://math.jianshu.com/math?formula=dp%5Bi-1%5D%5Bj%5D)：**不选**第 i 个物品，直接由上一层转移
- $dp[i-1][j-c[i]]+w[i]$：**选**第 i 个物品，由上一层空出体积![c[i]](https://math.jianshu.com/math?formula=c%5Bi%5D)的状态+![w[i]](https://math.jianshu.com/math?formula=w%5Bi%5D)得来



```cpp
#include<iostream>
#include<cstdio>
using namespace std;

int n,v,dp[8000][8000],c[1005],w[1005];
//n物品个数 v总体积 c[i]第i件物品体积 worth[i]第i件物品价值 
int main(){
    scanf("%d%d",&n,&v);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&c[i],&w[i]);
    }
    for(int i=1;i<=n;i++){ // 枚举物品
        for(int j=0;j<=v;j++){ // 枚举体积
            dp[i][j]=dp[i-1][j]; // 上一层状态转移
            if(j>=c[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-c[i]]+w[i]);//曲线救国 
        }
    }
    printf("%d",dp[n][v]);
}
```

### 01背包优化

由于本层状态不受上一层以前的状态影响，故可直接使用**滚动数组**，但注意内层循环要**倒序遍历**，以便保证每个物品只使用过一次（即每次状态更新时使用到的**前一个状态**未被更新）。

 例如 $f[5]$ 由 $f[3]$ 转移得来，倒序遍历在第 i 层更新 $f[5]$ 仍处在第 $i-1$ 层的状态而未被更新，与二维时的状态转移保持一致。

*状态表示* ： $dp[ j ]$ **只从前 i 个物品中选**，**总体积不超过 j** 的选法的集合。

 *属性*： ![MAX](https://math.jianshu.com/math?formula=MAX)

*状态计算*：

- $dp[j]=max(dp[j],dp[j-c[i]]+w[i])$
- $dp[j-c[i]]+w[i]$：**选**第 i 个物品，由上一层空出体积 $c[i]$ 的状态$+w[i]$ 得来

```c
#include<iostream>
#include<cstdio>
using namespace std;

//n物品个数 v总体积 c[i]第i件物品体积 worth[i]第i件物品价值 
int n,v,dp[8000],c[1005],w[1005];

int main(){
    scanf("%d%d",&n,&v);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&c[i],&w[i]);
    }
    for(int i=1;i<=n;i++){ // 枚举物品
        for(int j=v;j>=c[i];j--){//倒序遍历 枚举体积
            dp[j]=max(dp[j],dp[j-c[i]]+w[i]);//曲线救国 
        }
    }
    printf("%d",dp[v]);
}
```



## 2. 完全背包

**题目描述**
有 $N$ 种物品和一个容量是 $V$ 的背包，**每种物品都有无限件**可用。第 $i$种物品的体积是 $v_i$，价值是 $w_i$。求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。输出最大价值。



### 完全背包朴素

*状态表示* ： $dp [ i ][ j ]$  只从前 i 个物品中选，总体积不超过 j 的选法的集合。
 *属性*： ![MAX](https://math.jianshu.com/math?formula=MAX)
 *状态计算*：

- $dp[i][j]=max(dp[i-1][j],dp[i-1][j-k*c[i]]+k*w[i])$
- $dp[i-1][j]$：不选第 i 种物品，直接由上一层转移
- $dp[i-1][j-k*c[i]]+k*w[i]$：**选**第 i 种物品k件，由上一层空出体积$k*c[i]$的状态 $+k*w[i]$ 得来

```c++
#include<iostream>
#include<cstdio>
using namespace std;

//n物品个数 v总体积 c[i]第i件物品体积 worth[i]第i件物品价值 
int n,v,c[1007],w[1007],dp[5000][5000];

int main(){
    scanf("%d%d",&n,&v);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&c[i],&w[i]);

    for(int i=1;i<=n;i++) // 枚举物品
        for(int j=0;j<=v;j++) // 枚举体积
            for(int k=0;k*c[i]<=j;k++) // 三重循环 枚举每种取用件数*c[i]不大于当前总体积j
                dp[i][j]=max(dp[i][j],dp[i-1][j-c[i]*k]+w[i]*k);

    printf("%d",dp[n][v]);
}

```



### 完全背包一级优化

**将时间优化为二重。**

*状态表示* ： $dp [ i ][ j ]$ **只从前 i 个物品中选**，**总体积不超过 j** 的选法的集合。

*属性*： ![MAX](https://math.jianshu.com/math?formula=MAX)

*状态计算*：

- $dp[i][j]=max(dp[i-1][j],dp[i][j-c[i]]+w[i])$
- $dp[i-1][j]$：**不选**第 i 种物品，直接由上一层转移
- $dp[i][j-c[i]]+w[i]$：**选**第 i 种物品+1件，件数由体积的**正序遍历**不断累加



```c++
#include<iostream>
#include<cstdio>
using namespace std;

//n物品个数 v总体积 c[i]第i件物品体积 worth[i]第i件物品价值 
int n,v,c[1007],w[1007],dp[5000][5000];

int main(){
    scanf("%d%d",&n,&v);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&c[i],&w[i]);

    for(int i=1;i<=n;i++) // 枚举物品
        for(int j=0;j<=v;j++){//参照01背包朴素 优化为二重循环 正序枚举体积
            dp[i][j]=dp[i-1][j];
            if(j>=c[i]) dp[i][j]=max(dp[i][j],dp[i][j-c[i]]+w[i]);
        }

    printf("%d",dp[n][v]);
}
```

> NOTE:
>
> 一、不断地将当前物品增加到backpack中



### 完全背包二级优化

**将空间优化为一维。**

*状态表示* ： $dp[ j ]$ **只从前 i 个物品中选**，**总体积不超过 j** 的选法的集合。
*属性*： ![MAX](https://math.jianshu.com/math?formula=MAX)
*状态计算*：

- $dp[j]=max(dp[j],dp[j-c[i]]+w[i])$
- $dp[j-c[i]]+w[i]$：**选**第 i 个物品+1件，件数由体积的**正序遍历**不断累加

```c++
#include<iostream>
#include<cstdio>
using namespace std;

//n物品个数 v总体积 c[i]第i件物品体积 worth[i]第i件物品价值 
int n,v,c[1007],w[1007],dp[5000];

int main(){
    scanf("%d%d",&n,&v);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&c[i],&w[i]);

    for(int i=1;i<=n;i++) // 枚举物品
        for(int j=c[i];j<=v;j++) // 正序枚举体积
            dp[j]=max(dp[j],dp[j-c[i]]+w[i]);

    printf("%d",dp[v]);
}
```

- 注意！！**当空间优化为一维时，只有完全背包是正序遍历**


## 3. 多重背包

**题目描述**
 有 $N$ 种物品和一个容量是 $V$ 的背包。
 **第 i 种物品最多有 si 件**，每件体积是 $v_i$，价值是$w_i$。
 求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
 输出最大价值。

**输入格式**
 第一行两个整数，$N$，$V$，用空格隔开，分别表示物品种数和背包容积。
 接下来有 $N$ 行，每行三个整数 $v_i,w_i,s_i$，用空格隔开，分别表示第 $i$ 种物品的体积、价值和数量。

**输出格式**
 输出一个整数，表示最大价值。

**数据范围**
 $0<N,V≤100$
 $0<v_i,w_i,s_i≤100$

### 多重背包朴素

*状态表示* ： `dp [ i ][ j ]` **只从前 i 个物品中选**，**总体积不超过 j** 的选法的集合。
 *属性*： ![MAX](https://math.jianshu.com/math?formula=MAX)
 *状态计算*：

- `dp[i][j]=max(dp[i-1][j],dp[i-1][j-k*c[i]]+k*w[i])`
- `dp[i-1][j]`：**不选**第 i 种物品，直接由上一层转移
- `dp[i-1][j-k*c[i]]+k*w[i]`：**选**第 i 种物品k件，由上一层空出体积`k*c[i]`的状态+`k*w[i]`得来
   与完全背包状态表示以及转移相同

```c
#include<iostream>
#include<cstdio>
using namespace std;

//n物品个数 v总体积 c[i]第i件物品体积 worth[i]第i件物品价值 
int n,v,c[1500],w[1500],s[1500],dp[1500][1500];

int main(){
    scanf("%d%d",&n,&v);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&c[i],&w[i],&s[i]);
    for(int i=1;i<=n;i++) // 枚举物品
        for(int j=0;j<=v;j++) // 枚举体积
            for(int k=0;k<=s[i]&&k*c[i]<=j;k++) // 枚举决策
                dp[i][j]=max(dp[i][j],dp[i-1][j-k*c[i]]+k*w[i]);
    printf("%d",dp[n][v]);
}
```




### 多重背包二进制优化


由于**每组物品的件数均不一样**，所以**不能使用完全背包的优化方法**（具体件数不可控），因此采用另一种思路——**二进制优化**。

将每一种物品由1.2.4.8.16.128...的件数打包，不足一组的零头重新打包，转化为**01背包问题**

```c++

//多重背包二进制拆分 
#include<iostream>
#include<cstdio>
using namespace std;

//n物品个数 v总体积 c[i]第i件物品体积 worth[i]第i件物品价值 
int n,v,c[12500],w[12500],dp[25000]; 

int cnt;//划分成01背包后的总包数 

int main(){
    scanf("%d%d",&n,&v);
    while(n--){

        // s: 当前物品的件数
        // a: 当前物品的体积
        // b: 当前物品的价值

        int a,b,s; 
        scanf("%d%d%d",&a,&b,&s);
        //倍增思想 
        int k=1; //相当于base(每组件数)：1 2 4 8 16 32 64 128 256...据此打包
        while(k<=s){
            cnt++;
            c[cnt]=k*a;
            w[cnt]=k*b;
            s-=k;
            k*=2;
        }
        if(s>0){ //若拆完之后还有零头
            cnt++; //再分一个包
            c[cnt]=a*s;
            w[cnt]=b*s;
        }
    }
    //相当于将多重背包转化为01背包
    n=cnt;//01物品总个数
    for(int i=1;i<=n;i++) 
        for(int j=v;j>=c[i];j--)//注意倒序遍历 
            dp[j]=max(dp[j],dp[j-c[i]]+w[i]);

    printf("%d",dp[v]);
}

```



### 多重背包单调队列优化

## 4. 分组背包


## 6. 二维费用的背包



## 7. 有依赖的背包问题

**题目描述**
有 $N$ 个物品和一个容量是 $V$ 的背包。**物品之间具有依赖关系**，且**依赖关系**组成一棵树的形状。如果选择一个物品，则必须选择它的父节点。

> NOTE:
>
> 一、是所有的父节点

[图片上传失败...(image-2ed05f-1628507177264)]

如果选择物品5，则必须选择物品1和2。这是因为2是5的父节点，1是2的父节点。

每件物品的编号是$i$，体积是 $v_i$，价值是 $w_i$，依赖的父节点编号是 $p_i$。物品的下标范围是 $1…N$。求解将哪些物品装入背包，可使物品总体积不超过背包容量，且总价值最大。输出最大价值。



**代码**

*状态表示* ： $dp[ u ][ j ]$ 所有从以u为根的子树中选，总体积不超过 j 的选法的集合。

*状态计算*：

- $dp[k][j]=max(dp[k][j],dp[k][j-l]+dp[son][l])$
- $dp[k][j]$ 不选 son 子树
- $dp[k][j-l]+dp[son][l]$ 选了体积为 $l$ 的 son 子树

其实~~很简单~~ 就是**把线性的01背包简单变形为一棵树**

**链式前向星+dfs**

```c++
#include<iostream>
#include<cstdio>
#define maxn 200
#define maxm 400
using namespace std;
//n物品个数 v总体积 c[i]第i件物品体积 worth[i]第i件物品价值 
int n,v,cnt,w[maxn],c[maxn],dp[maxn][maxm];
int root; // 根节点
// head: parent
int head[maxn],dis[maxn],vis[maxn];
struct node{
    int to,next; // to: 指向child, next指向的是兄弟节点
}e[maxm]; // 保存所有的node
// 链式前向星 或者叫 邻接表
//加边操作
// x: parent
// y: child
void add(int x,int y){
    cnt++;
    e[cnt].to=y;
    e[cnt].next=head[x];
    head[x]=cnt;
}

void dfs(int k){ //当前节点k
    for(int i=head[k];i;i=e[i].next){// 枚举物品
        int son=e[i].to; // 记录子节点
        dfs(son);// 向下递归到最末子树 在回溯的过程中从最末更新dp值 直到回到root
        // 由于当前节点k必选 因此体积j需要将c[k]空出来 01背包倒序枚举体积
        for(int j=v-c[k];j>=0;j--){ 
            for(int l=0;l<=j;l++){// 枚举决策
                dp[k][j]=max(dp[k][j],dp[k][j-l]+dp[son][l]);
            }//             不选son子树    选son子树
        }
    }
    for(int i=v;i>=c[k];i--) dp[k][i]=dp[k][i-c[k]]+w[k];
    for(int i=0;i<c[k];i++) dp[k][i]=0;
}

int main(){
    scanf("%d%d",&n,&v);
    for(int i=1;i<=n;i++){
        int p;
        scanf("%d%d%d",&c[i],&w[i],&p);
        if(p==-1) root=i; // 根节点
        add(p,i); // 加边加边 由父节点指向子节点
    }
    dfs(root); // 从根节点开始搜
    printf("%d",dp[root][v]);
}
```

> NOTE:
>
> 一、每个节点只有一个parent，所以通过一个parent array就可以将一颗树给保存下来
