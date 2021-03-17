#include <iostream>
using namespace std;

int iterative_fib(int n)
{
    int last_last_one = 0; //上上个元素
    int last_one = 1;      // 上个元素
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int fib_number = 0;
    for (int i = 2; i <= n; ++i)
    {
        fib_number = last_one + last_last_one;
        last_last_one = last_one;
        last_one = fib_number;
    }
    return fib_number;
}

int recursive_fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return recursive_fib(n - 1) + recursive_fib(n - 2);
}

int main()
{
    std::cout << "input a number:" << std::endl;
    int N = 0;
    std::cin >> N;
    std::cout << "fib:" << iterative_fib(N) << std::endl;
}