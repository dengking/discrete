# labuladong [团灭 LeetCode 股票买卖问题](https://mp.weixin.qq.com/s/lQEj_K1lUY83QtIzqTikGA) 

> NOTE: 
> 1、作者的思路还是穷举，它使用的是基于**finite state machin**e的方式来进行**穷举**的，它将问题的所有的可能性都进行了**穷举**，他使用了一个三维的**状态转移方**程来对这个问题进行统一的建模，这个三维的**状态转移方程**初看起来是稍微有些复杂，但是结合具体的问题后，是容易理解的。
>
> 2、展示了状态压缩的技巧
>
> 3、这篇文章让我想起来 finite state machine 和 dynamic programming
>
> 状态转移方程 可以看做是对 finite state machine 的数学描述；
>
> dynamic programming则告诉我们如何使用程序来进行实现；
>
> 4、股票买卖问题的选择是buy、sell、rest，这是由programer进行挖掘的；
>
> 5、这个题目的K次和 LeetCode [787. K 站中转内最便宜的航班](https://leetcode.cn/problems/cheapest-flights-within-k-stops/) 中的K次非常类似，在LeetCode [787. K 站中转内最便宜的航班](https://leetcode.cn/problems/cheapest-flights-within-k-stops/) 中，每增加一个中转节点，则可供选择的节点就多一些了，其中会穷举从0-K；
>
> 在本文给出的股票买卖问题的状态转移方程中，每一次买入，则交易次数增加一次，显然根据此就可以控制交易次数了。
>
> 这样的类比让我有这样的想法：graph的状态转移可以和节点沿着边进行转移这样的具体过程进行关联，因此便于我们理解抽象的过程；这道题再和 LeetCode [787. K 站中转内最便宜的航班](https://leetcode.cn/problems/cheapest-flights-within-k-stops/) 中的K进行对比，显然是能够帮助理解的。
>
> 6、这道题和 LeetCode [487. 最大连续1的个数 II](https://leetcode.cn/problems/max-consecutive-ones-ii/) 有一个相同点就是，需要分情况讨论，列两个状态转移方程，在这里，作者是根据股票持有状况来进行分类的。
>
> 两个状态转移方程，其实就意味着有两个DP table。
>
> 7、股票买卖问题其实也可以归入子序列问题范畴，因为它是选择非连续的prices来进行交易；但是它的递归方程其实和**子数组问题**的递归方程有关系，我们知道子数组的递归方程描述的就是`dp[i]` 和 `dp[i-1]`之间的关系，而股票买卖的递归方程也是如此，这是因为股票买卖问题要求"sell 必须在 buy 之后，buy 必须在 sell 之后"，并且buy的时候，需要基于之前收益进行buy。
>
> 八、为什么这个动态规划方程能够求解出最大的收益呢？
>
> 动态规划方程非常巧妙，看似简单，其实演算过程还是蛮复杂的。
>
> 总的思想: 两个max能够保证: 以更低的价格买入(`dp[i][k][1]`)，以更高的价格卖出(`dp[i][k][0]`)，尽可能地多进行交易。
>
> 更加具体的说: 
>
> 对于 `dp[i][1]`，它有两个选择：
>
> 1、rest
>
> 2、buy
>
> max保证: 只有当当前持有的利润扣除买入的成本比rest(之前)要更好的时候，才会选择buy
>
> 对于 `dp[i][0]`，它有两个选择：
>
> 1、rest
>
> 2、sell
>
> max保证: 只有当以当前价格进行交易赚取的利润比之前的(rest)要更好的时候，才会选择sell
>
> 需要注意的是：具体的买卖动作其实是由最大的收益来驱动的，并且按照上述递归方程，买入卖出串联进行的:
>
> `dp[i][k][1] = dp[i-1][k-1][0] - prices[i]`
>
> 即它是拿之前赚的钱来买新的股票，这就保证是串联的。买入是减，卖出是加，最终收益其实就是它们的综合。
>
> 在这个算法背后的真实的交易过程如下:
>
> ```
> 买入 dp[0][0][1]->卖出->买入->卖出
> ```
>
> 补充内容
>
> leetcode [『 动态规划 』 DP模板解决一众买卖股票问题](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/solution/by-flix-us00/)



上篇文章 [LeetCode 股票问题的一种通用解法](http://mp.weixin.qq.com/s?__biz=MzU0MDg5OTYyOQ==&mid=2247484032&idx=1&sn=cafed934bd5d8a733de3b3bc675e6a19&chksm=fb3362c2cc44ebd4c5eb7bc41baf540f55ee6f4d855bfcca7ebc4a5d2fea9a3b827bef5c18eb&scene=21#wechat_redirect) 用递归的方法实现了一套简单易懂的可行解，但是时间复杂度略高，不能通过全部测试用例。

这篇文章用「状态机」的技巧给出最优解，可以全部提交通过。不要觉得这个名词高大上，文学词汇而已，实际上就是 **DP table**，等会儿一讲就明白了。

本文就来告诉你处理这类问题的框架，拒绝奇技淫巧，稳扎稳打，以不变应万变。

这 6 道题目是有共性的，本文通过对第四道题的分析，逐步解决所有问题。



## 一、穷举框架

> NOTE: 
>
> 一、关于本文中提及的状态、选择、base case，都是在作者的 labuladong [动态规划详解](https://mp.weixin.qq.com/s/Cw39C9MY9Wr2JlcvBQZMcA) 中提出的



### 利用「**状态**」进行穷举

首先，还是一样的思路：如何穷举？这里的穷举思路和上篇文章递归的思想不太一样。

而这里，我们不用**递归思想**进行**穷举**，而是利用「**状态**」进行穷举。

看看总共有几种「**状态**」，再找出每个「**状态**」对应的「**选择**」。我们要穷举所有「**状态**」，穷举的目的是根据对应的「**选择**」更新**状态**。看图，就是这个意思。



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4nPicwNq5syrSwnBc02yxG3aeibzourMAl7wGxtQfWTMtHs5QVdLYibrKZ2RgrqujZkLJEnrn7DibNBbg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



### 选择

具体到当前问题，**每天都有三种「选择」**：买入、卖出、无操作，我们用 buy, sell, rest 表示这三种选择。



但问题是，并不是每天都可以任意选择这三种选择的，因为 sell 必须在 buy 之后，buy 必须在 sell 之后（第一次除外）。那么 rest 操作还应该分两种状态，一种是 buy 之后的 rest（持有了股票），一种是 sell 之后的 rest（没有持有股票）。而且别忘了，我们还有交易次数 k 的限制，就是说你 buy 还只能在 k > 0 的前提下操作。

> NOTE: 
>
> 一、其实这是leetcode上很多问题的相同点：增加很多的限制条件，比如在打家劫舍系列问题中，就要求不能够抢连续两家；本题的限制是：必须要先buy然后sell然后再buy，它的规则有些不相交区间的意味

很复杂对吧，不要怕，我们现在的目的只是穷举，你有再多的状态，老夫要做的就是一把梭全部列举出来。**这个问题的「状态」有三个**，第一个是天数，第二个是当天允许交易的最大次数，第三个是当前的持有状态（即之前说的 rest 的状态，我们不妨用 1 表示持有，0 表示没有持有）。

### dp table 三维数组 `dp` 以及 穷举框架

我们用一个三维数组 `dp` 就可以装下这几种状态的全部组合，用 for 循环就能完成穷举：



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4nPicwNq5syrSwnBc02yxG3aSvQTuRMLrsMKSB8BQteEbiakEP2fJyNjyVUiaZQLjJ8mlQ7dM4hLYfeQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

> NOTE: 
>
> 一、`max(buy, sell, rest)` 的含义是 今天执行buy 或者 今天执行sell 或者 今天执行rest
>
> 二、后面的"第五题，k = 2"、"第六题，k = any integer" 都是使用的上述穷举框架



而且我们可以用自然语言描述出每一个状态的含义，比如说 `dp[3][2][1]`的含义就是：今天是第三天，我现在手上持有着股票，至今最多进行 2 次交易。再比如 `dp[2][3][0]` 的含义：今天是第二天，我现在手上没有持有股票，至今最多进行 3 次交易。很容易理解，对吧？

### 最终答案

我们想求的最终答案是 `dp[n - 1][K][0]`，即最后一天，最多允许 `K` 次交易，所能获取的最大利润。读者可能问为什么不是 `dp[n - 1][K][1]`？因为 `[1]` 代表手上还持有股票，`[0]` 表示手上的股票已经卖出去了，很显然后者得到的利润一定大于前者。



记住如何解释「状态」，一旦你觉得哪里不好理解，把它翻译成自然语言就容易理解了。



## 二、状态转移框架

现在，我们完成了「状态」的穷举，我们开始思考每种「状态」有哪些「选择」，应该如何更新「状态」。

因为我们的选择是 buy, sell, rest，而这些选择是和「持有状态」相关的，所以只看「持有状态」，可以画个状态转移图。



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4nPicwNq5syrSwnBc02yxG3auom48UuPXWBQV7IRsa59yHe1TRQicDquqyRFOoia62BqHzofboyiay5IA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



通过这个图可以很清楚地看到，每种状态（0 和 1）是如何转移而来的。根据这个图，我们来写一下状态转移方程：



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4nPicwNq5syrSwnBc02yxG3aLFHicK3LhVZXEJvHzEOgGpjp8RzCxIkQpW0K7qGkqYKcCP5jdJIrpibA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



这个解释应该很清楚了，如果 buy，就要从利润中减去 `prices[i]`，如果 sell，就要给利润增加 `prices[i]`。今天的最大利润就是这两种可能选择中较大的那个。而且注意 k 的限制，我们在选择 buy 的时候，把最大交易数 `k` 减小了 1，很好理解吧，当然你也可以在 sell 的时候减 1，一样的。



现在，我们已经完成了动态规划中最困难的一步：状态转移方程。**如果之前的内容你都可以理解，那么你已经可以秒杀所有问题了，只要套这个框架就行了。**不过还差最后一点点，就是定义 base case，即最简单的情况。

### Base case



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4nPicwNq5syrSwnBc02yxG3akByqn8e7kyr0hSKS6iaVkicDsZrc08oic4wp5c7sPk7LzicGJm3xlBRSew/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

> NOTE:
>
> 一、DP table中存在空值和无意义的值两种情况，这是特别需要注意的。
>
> 因为这道题是求解最大值，作者使用 `-infinity` 来表示无效值。



### 状态转移方程

把上面的状态转移方程总结一下：



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4nPicwNq5syrSwnBc02yxG3aewN24fa7UR8G7byHOb7lUfrlgCkUN1KsL5PYsIicKfE0mQ2OCibCXiajA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

读者可能会问，这个数组索引是 -1 怎么编程表示出来呢，负无穷怎么表示呢？这都是细节问题，有很多方法实现。现在整体框架已经完成，下面开始具体化。



## 三、秒杀题目



### 第一题，k = 1

> NOTE: 
>
> 一、LeetCode [121. 买卖股票的最佳时机](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/) 简单
>
> 二、其实下面的状态转移方程能够cover LeetCode [121. 买卖股票的最佳时机](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/) 简单 所有的可能状态：在第i天，只有两种持有状态：
>
> 1、持有股票
>
> 2、不持有股票
>
> 所以，所有可能性的个数为: `n * 2`，再看看dp table，它的大小也是如此。
>
> 三、其实初读对于下面的算法能否成功计算出最优值是持怀疑态度的，可以参加 LeetCode [121. 买卖股票的最佳时机](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/) 简单
>
> 中记录的结合具体例子的推演过程，这样才能够完整地理解这个algorithm。



直接套**状态转移**方程，根据 base case，可以做一些化简：



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4nPicwNq5syrSwnBc02yxG3aIO5XoTDAoKiajdPuJ01ysZo8TxkefNMwu6MWF4r82qZ77Q3lBQQKiaew/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



直接翻译成代码：



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4nPicwNq5syrSwnBc02yxG3av8TAoT0mb4LFdmNNoNDEeqo1ylkzJdjNQeia3vLlos4ewn9gKkc1TTw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



显然 `i = 0` 时 `dp[i-1]` 是不合法的。这是因为我们没有对 `i` 的 base case 进行处理。那就简单粗暴地处理一下：



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4nPicwNq5syrSwnBc02yxG3ajuXPgiaAurIiadqSu1NXTRT3Y60xuYdGxsAOiciaPZ0fMKzpceick1WdMicQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



第一题就解决了，但是这样处理 base case 很麻烦，而且注意一下状态转移方程，新状态只和相邻的一个状态有关，其实不用整个 dp 数组，只需要两个变量储存所需的状态就足够了，这样可以把空间复杂度降到 O(1):



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4nPicwNq5syrSwnBc02yxG3aKcD7yXPDtaxqs4nWLo1KblfHJeSAF8KsWVe803VlwY8WXpicwhJ30wA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



两种方式都是一样的，不过这种编程方法简洁很多。但是如果没有前面状态转移方程的引导，是肯定看不懂的。后续的题目，我主要写这种空间复杂度 O(1) 的解法。

> NOTE:
>
> leetcode [121. 买卖股票的最佳时机](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/) # [Gnakuw](https://leetcode.cn/u/nehzil/) # [121. 买卖股票的最佳时机（详细C++代码注释学习代码随想录的风格写的）](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/solution/gu-piao-dong-tai-gui-hua-jie-fa-by-kino-7qh40/)  的初始化过程更加容易理解：
>
> ```c++
> class Solution {
> public:
>     int maxProfit(vector<int>& prices) {
>         if(prices.size() == 0) return 0;
>         /* 定义dp数组 */
>         vector<vector<int>> dp(prices.size(),vector<int>(2,0));
>         /* dp数组初始化 */
>         dp[0][0] = -prices[0];
>         dp[0][1] = 0;
> 
>         for(int i = 1; i < prices.size(); i++) {
>             dp[i][0] = max(dp[i-1][0], -prices[i]);
>             dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
>         }
>         return dp[prices.size()-1][1];
>     }
> };
> ```
>
> 

### 第二题，k = +infinity



如果 k 为正无穷，那么就可以认为 k 和 k - 1 是一样的。可以这样改写框架：

> NOTE: 
>
> 一、上面这段话是容易产生误解的，比较容易理解的方式是: 当k = +infinity时，对应的情况是状态转移是和k无关的，是可以直接从状态转移方程中，将k维度去除，这和k=1是一致的。
>
> 其实从这个角度来看，作者在状态转移方程中添加上k这个维度其实是为了使用同一个状态转移方程来对所有的可能情况进行统一的描述，但是，这会造成理解的困难。



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4nPicwNq5syrSwnBc02yxG3aEREdMkvxJMoHQHxP0YicFODNzPaetJMFPMVkYRgXfoIe4XQZFwuYu4Q/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



直接翻译成代码即可：



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4nPicwNq5syrSwnBc02yxG3aSaibjrDSib8aY6ib3LYZqKI1DtHmTQdUrSlA1oYU8YuxwWnmrDdg80RpA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



> NOTE: 
>
> 一、由于没有使用dp table，所有无法使用dp table来查询`dp[i-1][0]`，上述程序的做法是使用一个临时变量temp来记录。

### 第三题，k = +infinity with cooldown



每次 sell 之后要等一天才能继续交易。只要把这个特点融入上一题的状态转移方程即可：



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4nPicwNq5syrSwnBc02yxG3azWLan2cK2oEe3u3hFWEyyjBzBjYnf3yk2ia9ERqcynyNopqvPJHIySw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



直接翻译成代码即可：



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4nPicwNq5syrSwnBc02yxG3awg3iarSu0kyM83Nv1xItUibpWvyoayrOh2YZz9mnIoVmJubZ4ycqtaIg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



### 第四题，k = +infinity with fee



每次交易要支付手续费，只要把手续费从利润中减去即可：



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4nPicwNq5syrSwnBc02yxG3a2aQB65TqicARNbgzX9PxHllvTERt2PeIxCg4Bmm0kiaphjCibcB5ccFicQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



直接翻译成代码即可：



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4nPicwNq5syrSwnBc02yxG3aXBSLuVEuWKVNC0PKxQed49wekrkuCWUPqbJsXpXN2sRzlnPuQ8SkaA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



### 第五题，k = 2

> NOTE:
>
> k = 2 

k = 2 和前面题目的情况稍微不同，因为上面的情况都和 k 的关系不太大。要么 k 是正无穷，状态转移和 k 没关系了；要么 k = 1，跟 k = 0 这个 base case 挨得近，最后也被消掉了。

这道题 k = 2 和后面要讲的 k 是任意正整数的情况中，对 k 的处理就凸显出来了。我们直接写代码，边写边分析原因。



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4nPicwNq5syrSwnBc02yxG3aFQZg8teuph4U4tnayeCerbpByNgOsKxWGLHZk4NYDI9SeDFBlPK4aA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

#### 穷举的错误的写法

按照之前的代码，我们可能想当然这样写代码（错误的）：



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4nPicwNq5syrSwnBc02yxG3auu8RByaI40g7YfZczWSL4ceec71iaoiaeUkF6aIlxza9N7NpYXIhvn7A/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

为什么错误？我这不是照着状态转移方程写的吗？

还记得前面总结的「穷举框架」吗？就在强调必须穷举所有状态。其实我们之前的解法，都在穷举所有状态，只是之前的题目中 k 都被化简掉了，所以没有对 k 的穷举。比如说第一题，k = 1：



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4nPicwNq5syrSwnBc02yxG3aAfehqTCribLX230FrJWmuZxTSAicpI7j8KWN7BMTmg7FVgdBf4tNibhaQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

#### 穷举的正确的写法

> NOTE: 
>
> 穷举框架参见前面的 "dp table 三维数组 `dp` 以及 穷举框架"章节

这道题由于没有消掉 k 的影响，所以必须要用 for 循环对 k 进行穷举才是正确的：



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4nPicwNq5syrSwnBc02yxG3aR5pVxlDFNmHT21ic8Wwvvx43sWhh1KiaTk6LeGcprql8ahuUpSdGdsgw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



如果你不理解，可以返回第一点「穷举框架」重新阅读体会一下。

#### 状态压缩的写法

第二种解法：因为这里 k 取值范围比较小，所以也可以不用 for 循环，直接把 k = 1 和 2 的情况手动列举出来也是一样的：



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4nPicwNq5syrSwnBc02yxG3aLibiadibb4MudsY5OD1OYibvicvQt9H3R2uWL134bONIP5mC1js4mMTkiaBQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



有状态转移方程和含义明确的变量名引导，相信你很容易看懂。如我我们想故弄玄虚，可以把上述四个变量换成 a, b, c, d。这样当别人看到你的解法时就会大惊失色，一头雾水，不得不对你肃然起敬。



### 第六题，k = any integer

这题和 k = 2 没啥区别，可以直接套上一题的第一个解法。但是提交之后会出现一个超内存的错误，原来是传入的 k 值可以任意大，导致 dp 数组太大了。现在想想，交易次数 k 最多能有多大呢？

一次交易由买入和卖出构成，至少需要两天。所以说有效的限制次数 k 应该不超过 n/2，如果超过，就没有约束作用了，相当于 k = +infinity。这种情况是之前解决过的。



直接把之前的代码重用：



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4nPicwNq5syrSwnBc02yxG3abqMrkkbwrcNS4bOY4KrSHpibzf5XFokkJWgm5MN8hz7OBF7Cs2CZYvg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



至此，6 道题目通过一个状态转移方程全部解决。



## 四、最后总结

本文给大家讲了如何通过状态转移的方法解决复杂的问题，用一个状态转移方程秒杀了 6 道股票买卖问题，现在想想，其实也不算难对吧？而这已经属于动态规划问题中较困难的了。

关键就在于找到所有可能的「状态」，然后想想怎么更新这些「状态」。一般用一个多维 dp 数组储存这些状态，从 base case 开始向后推进，推进到最后的状态，就是我们想要的答案。想想这个过程，你是不是有点理解「动态规划」这个名词的意义了呢？



具体到股票买卖问题，我们发现了三个状态，使用了一个三维数组，无非还是穷举 + 更新，不过我们可以说的高大上一点，这叫「三维 DP」，怕不怕？这个大实话一说，立刻显得你高人一等有没有？