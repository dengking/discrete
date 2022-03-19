# [**HJ13** **句子逆序**](https://www.nowcoder.com/practice/48b3cb4e3c694d9da5526e6255bb73c3?tpId=37&tqId=21236&rp=1&ru=/ta/huawei&qru=/ta/huawei&difficulty=&judgeStatus=&tags=/question-ranking)



```c++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;

int main()
{
  string input;
  getline(cin, input);
  std::size_t find_index = std::string::npos;
  std::size_t start_index = 0;
  std::size_t end_index = 0;
  std::size_t len = input.size();
  stack<string> st;
  do
  {
    find_index = input.find(" ", start_index);
    end_index = find_index == std::string::npos ? len : find_index; //
    st.push(input.substr(start_index, end_index - start_index));
    start_index = end_index + 1; // 此处必须要加上1，否则会陷入死循环
  } while (find_index != std::string::npos);

  while (!st.empty())
  {
    cout << st.top() << " ";
    st.pop();
  }
}
```





https://blog.nowcoder.net/n/540451a641ca47cdb8a8abceb624173c

```c++
int main()
{
    string s;
    stack<string> temp;
    while(cin>>s)
        temp.push(s);
    while(!temp.empty())
    {
        cout<<temp.top()<<" ";
        temp.pop();
    }
    return 0;
}
```

