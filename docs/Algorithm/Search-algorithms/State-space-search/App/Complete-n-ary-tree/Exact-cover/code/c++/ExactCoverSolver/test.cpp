#include <cstdio>
#include <vector>

using namespace std;
const int N = 50;
int f[N][N];

void init() {
    f[0][0] = 1;
    for (int i = 1; i < 33; i++) {
        f[i][0] = f[i - 1][0];
        for (int j = 1; j <= i; j++)
            f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
    }
}

/**
 * 将数num转换为base进制
 * @param num
 * @param base
 * @return
 */
std::vector<int> getDigits(int num, int base) {
    std::vector<int> digits;
    while (num) {
        digits.push_back(num % base);
        num /= base;
    }
    return digits;
}

/**
 * 求x转化为 c 进制 1 的个数为 k 的数的出现次数。
 * @param x
 * @param k
 * @param c
 * @return
 */
int solve(int x, int k, int c) {
    vector<int> digits = getDigits(x, c);

    int cnt = 0, ans = 0;// cnt记录当前路径上已有的1的数量
    for (int i = digits.size() - 1; i >= 0; i--) {
        //为1，则依次求解
        if (digits[i] == 1) {
            ans += f[i][k - cnt];
            cnt++;
            if (cnt == k)
                break;
        } else if (digits[i] > 1) { //假如大于1的话，相当于所有的位有可以为1，所以直接求解跳出
            ans += f[i + 1][k - cnt];
            break;
        }
    }
    if (cnt == k)
        ans++;
    return ans;
}


int main() {
    init();
    int x, y, k, c;
    while (~scanf("%d%d%d%d", &x, &y, &k, &c)) {
        printf("%d\n", solve(y, k, c) - solve(x - 1, k, c));
    }
    return 0;
}