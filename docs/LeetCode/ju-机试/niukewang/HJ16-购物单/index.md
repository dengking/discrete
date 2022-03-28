# [**HJ16** **购物单**](https://www.nowcoder.com/practice/f9c6f980eeec43ef85be20755ddbeaf4?tpId=37&tqId=21239&rp=1&ru=/ta/huawei&qru=/ta/huawei&difficulty=&judgeStatus=&tags=/question-ranking)



```c++
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

struct Thing // 物品信息
{
  int id{0}; // 从i还是编号
  int price{0};
  int weight{0};
  int master_id{0};
  bool is_master() // 判定是否是master物品
  {
    return master_id == 0;
  }
};

struct DpNodeInfo // dp 节点信息
{
  int satisfy{0};            // 满意度
  unordered_set<int> things; // 当前选中的物品，便于判定
};
int main()
{
  int money_count;
  int thing_count;
  cin >> money_count >> thing_count;

  unordered_map<int, Thing> things(thing_count);
  for (int i = 0; i < thing_count; ++i)
  {
    Thing t;
    cin >> t.price >> t.weight >> t.master_id;
    t.id = i;
    things[i] = t;
  }
  vector<vector<DpNodeInfo>> dp(thing_count + 1, vector<DpNodeInfo>(money_count + 1));
  for (int j = 1; j <= money_count; ++j)
  {
    Thing &cur_thing = things[0];
    if (j >= cur_thing.price)
    {
      dp[0][j].satisfy = cur_thing.price * cur_thing.weight;
      dp[0][j].things.insert(0);
    }
  }
  for (int i = 1; i < thing_count; ++i)
  {
    Thing &cur_thing = things[i];
    for (int j = 1; j <= money_count; ++j)
    {
      if (cur_thing.price <= j) // 当前的钱数可以买下当前物品
      {
        DpNodeInfo &last_dp_node_when_select = dp[i - 1][j - cur_thing.price];
        DpNodeInfo &last_dp_node_when_not_select = dp[i - 1][j];

        int select_satisfy = last_dp_node_when_select.satisfy + cur_thing.weight * cur_thing.price;
        int not_select_satisfy = last_dp_node_when_not_select.satisfy;
        if (cur_thing.is_master())
        {
          if (select_satisfy > not_select_satisfy)
          {
            dp[i][j] = last_dp_node_when_select;
            dp[i][j].satisfy = select_satisfy;
            dp[i][j].things.insert(i);
          }
          else
          {
            dp[i][j] = last_dp_node_when_not_select;
          }
        }
        else
        {
          if (last_dp_node_when_select.things.count(cur_thing.master_id))
          {
            if (select_satisfy > not_select_satisfy)
            {
              dp[i][j] = last_dp_node_when_select;
              dp[i][j].satisfy = select_satisfy;
              dp[i][j].things.insert(i);
            }
            else
            {
              dp[i][j] = last_dp_node_when_not_select;
            }
          }
          else
          {
            dp[i][j] = last_dp_node_when_not_select;
          }
        }
      }
      else
      {
        dp[i][j].satisfy = dp[i - 1][j].satisfy;
        dp[i][j].things = dp[i - 1][j].things;
      }
    }
  }
  cout << dp[thing_count - 1][money_count].satisfy << endl;
}

```

