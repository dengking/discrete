# leetcode [1201. 丑数 III](https://leetcode-cn.com/problems/ugly-number-iii/)



## [珊璞桑](https://leetcode.cn/u/bloodborne/) # [想到二分法，成功一大半](https://leetcode.cn/problems/ugly-number-iii/solution/xiang-dao-er-fen-fa-cheng-gong-yi-da-ban-by-bloodb/)

### 解题思路

本题如果能想到用二分法，就已经解答出了一大半，然后如果能知道怎么求指定数字范围内包含了多少丑数，就成功了另一小半。



### 二分法思路

思路如下：

1、我们先找到`a,b,c`里最小的那个数，比如是a，那么第n个丑数肯定是小于等于`n * a`的对不对？

因为 0 到 `n*a`范围内是有可能出现数字，可以被b或c整除的

2、然后就开始二分法的做法了，将`n * a`置为上限ceil，`0`置为下限0。

3、我们求解`mid = (ceil+floor)/2`这个数里包含了多少丑数，具体解法下面另外说。

4、

如果上一步的数字等于n, 判断当前的mid是否是丑数，如果是，直接返回mid，如果不是，将`ceil`置为mid - 1；

如果上一步的数字大于n,将`ceil`置为mid - 1；

如果上一步的数字小于n,将`floor`置为mid + 1；

### 求指定数字范围内的丑数数量

指定数字num范围内的丑数数量为：

```
num/a + num/b + num/c - num/lcm(ab) - num/lcm(ac) -  num/lcm(bc) + num/lcm(abc)
```

具体为啥是这个公式，咱们看下面的图就懂了

![image.png](https://pic.leetcode-cn.com/c3aad0c521cefbf9c8d40c93c58b51f27108939637dc4ca97dfce415270c105b-image.png)





```c++
func nthUglyNumber(n int, a int, b int, c int) int {
	ab, ac, bc := lcm(a, b), lcm(a, c), lcm(b, c)
	abc := lcm(ab, c)
	left, right := 0, n*min(a, b, c)
	for left <= right {
		mid := (left + right) / 2
		num := mid/a + mid/b + mid/c - mid/ab - mid/ac - mid/bc + mid/abc
		if num == n {
			if mid%a == 0 || mid%b == 0 || mid%c == 0 {
				return mid
			} else {
				right = mid - 1
			}
		} else if num > n {
			right = mid - 1
		} else {
			left = mid + 1
		}
	}
	return left
}

// 求最小数
func min(a int, args ...int) (result int) {
	result = a
	for _, v := range args {
		if v < result {
			result = v
		}
	}
	return result
}

// 求最小公倍数
func lcm(x, y int) int {
	return x * y / gcd(x, y)
}

// 求最大公约数
func gcd(x, y int) int {
	tmp := x % y
	if tmp > 0 {
		return gcd(y, tmp)
	}
	return y
}

```

