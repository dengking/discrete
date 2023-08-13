# LeetCode Integer and Roman



## [LeetCode-12. Integer to Roman-middle](https://leetcode.cn/problems/integer-to-roman/)



```c++
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
            pos += 1;
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
                {1, "I"}, // 1
                {2, "X"}, // 10
                {3, "C"}, // 100
                {4, "M"}, // 1000
        };
        static std::unordered_map<int, std::string> pos2five{
                {1, "V"}, // 5
                {2, "L"}, // 50
                {3, "D"}, // 500
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
            return unit + pos2unit[pos + 1];
        }
    }
};

```



## [LeetCode-13. Roman to Integer-easy](https://leetcode.cn/problems/roman-to-integer/)



```c++
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        static std::unordered_map<char, int> roman2int{
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000},
        };
        static std::unordered_map<char, std::unordered_set<char>> fourAndNine{
                {'I', {'V', 'X'}},
                {'X', {'L', 'C'}},
                {'C', {'D', 'M'}},
        };
        int result = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            char c = s[i];
            if (fourAndNine.contains(c) && fourAndNine[c].contains(s[i + 1])) {
                result -= roman2int[c];
            } else {
                result += roman2int[c];
            }
        }
        return result;
    }

};

// Driver code
int main() {

    Solution s;
    return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

