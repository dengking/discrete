#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;
#define Del(a, b) memset(a,b,sizeof(a))
typedef long long LL;
const double esp = 1e-10;
const int N = 50;
int f[N][N]; //f[i][j] 前i个中选j个1的个数
void isit() {
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

int solve(int x, int k, int c) {
    vector<int> v = getDigits(x, c);

    int cnt = 0, ans = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] == 1) //为1，则依次求解
        {
            ans += f[i][k - cnt];
            cnt++;
            if (cnt == k)
                break;
        } else if (v[i] > 1) //假如大于1的话，相当于所有的位有可以为1，所以直接求解跳出
        {
            ans += f[i + 1][k - cnt];
            break;
        }
    }
    if (cnt == k)
        ans++;
    return ans;
}


int main() {
    isit();
    int x, y, k, c;
    while (~scanf("%d%d%d%d", &x, &y, &k, &c)) {
        printf("%d\n", solve(y, k, c) - solve(x - 1, k, c));
    }
    return 0;
}