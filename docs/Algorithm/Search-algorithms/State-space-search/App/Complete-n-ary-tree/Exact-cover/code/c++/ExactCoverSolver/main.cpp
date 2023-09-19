#include <cstdio>

const int N = 50;
int f[N][N]; //f[i][j] 前i个中选j个1的个数

/**
 * 预处理f
 */
void init() {
    f[0][0] = 1;
    for (int i = 1; i <= 31; ++i) {
        f[i][0] = f[i - 1][0];
        for (int j = 1; j <= i; ++j) {
            f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
        }
    }
}

/**
 * 统计[0..x]内二进制表示含k个1的数的个数
 * @param x 
 * @param k 
 * @return 
 */
int calc(int x, int k) {
    int total = 0, ans = 0;//total记录当前路径上已有的1的数量，ans表示答案
    for (int i = 31; i > 0; --i) {
        if (x & (1 << i)) {
            ++total;
            if (total > k) break;
            x = x ^ (1 << i); // ^ 是 XOR operator，它实现的效果是将x的最高为设置为0
        }
        if ((1 << (i - 1)) <= x) {
            ans += f[i - 1][k - total];
        }
    }
    if (total + x == k) {
        ++ans;
    }
    return ans;
}

int main() {
    init();
    int x, y, k, c;
    while (~scanf("%d%d%d%d", &x, &y, &k, &c)) {
        printf("%d\n", calc(y, k) - calc(x - 1, k));
    }
    return 0;
}