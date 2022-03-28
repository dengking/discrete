# [**HJ1** **字符串最后一个单词的长度**](https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da?tpId=37&tqId=21224&rp=1&ru=/ta/huawei&qru=/ta/huawei&difficulty=&judgeStatus=&tags=/question-ranking)

这个题目需要处理的是只有一个单词。



https://blog.nowcoder.net/n/44bba0e30b954762a6147342dbeef7fe

```c++
#include <iostream>
#include <string>
using namespace std;
int main(){
    char a;
    int size = 0;
    do{
        a = getchar();
        if (a == ' '){
            size = 0;
        }
        else if (a != '\n'){ // 如果不加上这个处理，换行也会被记入
            size ++;
        }
        else{

        }
    }while(a!='\n');
    cout<<size;
}
```



https://blog.nowcoder.net/n/dc0bd2b6d1574e97914993cf2528e7bb

```c++
#include<iostream>
int main()
{
	  //考虑到极限情况，最好将字符串长度设置为5001
    char receivedBuffer[5001]={0};
    //读取到buffer中，包含空格制表符等
    cin.getline(receivedBuffer, 5001);
    //转换成string
    string changeToString = receivedBuffer;
    //利用string类中的函数find查找空格的索引
    int indexOfBlank= changeToString.find(" ");
    //用来保存上一个索引
    int saveIndex = indexOfBlank;
    //当找到空格的时候执行
    while (indexOfBlank !=-1)
    {
    	//保存上一个索引
        saveIndex = indexOfBlank;
        //从下一个位置继续查找空格
        indexOfBlank = changeToString.find(" ", indexOfBlank +1);
    }
    //找不到空格的时候，将上一个索引位置的子串抽出，打印长度信息
    cout << changeToString.substr(saveIndex + 1).length();
    return 0;
}

```



## 错误写法

```c++
#include <iostream>
#include <string>
using namespace std;
//!!!不区分大小写，所以进行ascll码+32一样也++
int main()
{
  string str;
  int count = 0;
  cin >> str;
  cout << str << endl;
  for (auto &&c : str)
  {
    if (c == ' ')
    {
      count = 0;
    }
    else
    {
      ++count;
    }
  }
  cout << count << endl;
  return 0;
}
```

输出如下：

```
abc dd
abc
3
```

