# [**HJ20** **密码验证合格程序**](https://www.nowcoder.com/practice/184edec193864f0985ad2684fbc86841?tpId=37&tqId=21243&rp=1&ru=/ta/huawei&qru=/ta/huawei&difficulty=&judgeStatus=&tags=/question-ranking)



```C++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;

int is_lower_character(char c)
{
  return (c >= 'a' && c <= 'z');
}
int is_upper_character(char c)
{
  return (c >= 'A' && c <= 'Z');
}
int is_number(char c)
{
  return c >= '0' && c <= '9';
}
int is_other_char(char c)
{
  return !is_lower_character(c) &&
         !is_upper_character(c) &&
         !is_number(c);
}

bool is_ok(string &pw)
{
  int n = pw.size();
  if (n < 8)
  {
    return false;
  }
  int is_lower_character_flag = 0;
  int is_upper_character_flag = 0;
  int is_number_character_flag = 0;
  int is_other_character_flag = 0;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  int duplicate_len = 0;
  for (int i = 1; i < n + 1; ++i)
  {
    is_lower_character_flag = is_lower_character_flag == 0 ? is_lower_character(pw[i - 1]) : is_lower_character_flag;
    is_upper_character_flag = is_upper_character_flag == 0 ? is_upper_character(pw[i - 1]) : is_upper_character_flag;
    is_number_character_flag = is_number_character_flag == 0 ? is_number(pw[i - 1]) : is_number_character_flag;
    is_other_character_flag = is_other_character_flag == 0 ? is_other_char(pw[i - 1]) : is_other_character_flag;
    for (int j = i + 1; j < n + 1; ++j)
    {
      if (pw[i - 1] == pw[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      duplicate_len = max(duplicate_len, dp[i][j]);
      if (duplicate_len > 2)
        return false;
    }
  }
  return is_lower_character_flag + is_upper_character_flag + is_number_character_flag + is_other_character_flag >= 3;
}
int main()
{
  string input;
  while (cin >> input)
  {
    if (is_ok(input))
      cout << "OK" << endl;
    else
    {
      cout << "NG" << endl;
    }
  }
}
```

https://blog.nowcoder.net/n/72453d6bba2f4945af91ac81d7b6cd25



```C++
#include <iostream>
#include <string>

using namespace std;

const string Err = "NG";
const string Ok = "OK";

enum type {
    LOWER,
    UPPER,
    DIGIT,
    OTHER,
    MAX,
};

int main(void)
{
    string s;

    while (cin >> s){
        //cout << "s : " << s << endl;

        if (s.size() <= 8){
            cout << Err << endl;
            continue;
        }

        int State[type::MAX] = {0};
        for (char c : s){
            if (islower(c)){
                State[type::LOWER] += 1;
            }else if (isupper(c)){
                State[type::UPPER] += 1;
            }else if (isdigit(c)){
                State[type::DIGIT] += 1;
            }else{
                State[type::OTHER] += 1;
            }
        }
        int typenum = 0;
        for (int i = 0; i < type::MAX; ++i){
            if (State[i] > 0) typenum += 1;
        }

        if (typenum < 3){
            cout << Err << endl;
            continue;
        }

        // 判断有没有长度超过 2 的子串
        int max_substr_len = 3;
        string target;
        bool isFound = false;
        for (int i = 0; i < s.size()-max_substr_len; i ++){
            for (int j = i + max_substr_len; j < s.size()-max_substr_len; j ++){
                // 如果字符串相同
                if (0 == s.compare(i, max_substr_len, s, j, max_substr_len)){
                    isFound = true;
                    break;
                }
            }
            if (isFound) break;
        }
        if (isFound)
            cout << Err << endl;
        else
            cout << Ok << endl;

    }

    return 0;
}
```

