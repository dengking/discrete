# [LeetCode-12. Integer to Roman-middle](https://leetcode.cn/problems/integer-to-roman/)





```c++
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {

public:
    string intToRoman(int num) {
        string result;
        int pos = 1;
        while (num) {
            int digit = num % 10;
            string romanDigit = getRomanDigit(digit, pos);
            romanDigit += result;
            result.swap(romanDigit);
            num /= 10;
            pos *= 10;
        }
        return result;
    }

private:
    /**
     *
     * @param digit
     * @param pos 1-个位，10-十位，100-百位
     * @return
     */
    string getRomanDigit(int digit, int pos) {
        static std::unordered_map<int, std::string> pos2unit{
                {1,    "I"}, // 1
                {10,   "X"}, // 10
                {100,  "C"}, // 100
                {1000, "M"}, // 1000
        };
        static std::unordered_map<int, std::string> pos2five{
                {1,   "V"}, // 5
                {10,  "L"}, // 50
                {100, "D"}, // 500
        };
        string unit = pos2unit[pos];
        string five = pos2five[pos];

        if (digit <= 3) {
            string result;
            result.reserve(digit);
            for (int i = 0; i < digit; ++i) {
                result += unit;
            }
            return result;
        }
        if (digit == 4) {
            return unit + pos2five[pos];
        }
        if (digit == 5) {
            return pos2five[pos];
        }
        if (digit < 9) {
            string result;
            result.reserve(digit);
            result += five;
            for (int i = 0; i < digit - 5; ++i) {
                result += unit;
            }
            return result;
        }
        {
            return unit + pos2unit[pos * 10];
        }
    }
};

// Driver code
int main() {

    Solution s;
    s.intToRoman(1994);
    return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

