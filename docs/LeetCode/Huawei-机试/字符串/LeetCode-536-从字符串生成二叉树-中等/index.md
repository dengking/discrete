# [536. 从字符串生成二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-string/) 中等

你需要用一个包括括号和整数的字符串构建一棵二叉树。

输入的字符串代表一棵二叉树。它包括整数和随后的 0 、1 或 2 对括号。整数代表根的值，一对括号内表示同样结构的子树。

## 我的解题

这道题和根据遍历结果恢复二叉树有些类似。

## 自顶向下

### 程序一

```C++
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};
class Solution {
	int char2int(char c) {
		return c - '0';
	}
	// 确定左子树
	int split(string s, int start, int end) {
		int count = 0;
		int pos = -1; // 左子树的终止位置，显然-1表示没有左子树，没有左子树，其实也就意味着没有右子树
		for (int i = start; i <= end; ++i) {
			if (s[i] == '(') {
				++count;
			}
			if (s[i] == ')') {
				--count;
			}
			if (count == 0) {
				pos = i;
				break;
			}
		}
		return pos;
	}
public:
	TreeNode* str2tree(string s) {
		if (s.size() == 0) {
			return nullptr;
		}
		return str2treeImpl(s, 0, s.size() - 1);
	}

	TreeNode* str2treeImpl(string s, int start, int end) {
		if (start <= end) {
			TreeNode* root = new TreeNode(char2int(s[start]));
			int leftEnd = split(s, start + 1, end);
			if (leftEnd != -1) { // 有子树，必须要加上这个判断，否则是会导致错误的
				root->left = str2treeImpl(s, start + 2, leftEnd - 1);
				root->right = str2treeImpl(s, leftEnd + 2, end - 1);
			}
			else {
				/*	cout << "危险:" << start + 2 << "," << leftEnd - 1 << endl;
					cout << "危险:" << leftEnd + 2 << "," << end - 1 << endl;*/
			}

			return root;
		}
		else {
			return nullptr;
		}
	}
};

int main()
{
	Solution s;
	s.str2tree("4(2(3)(1))(6(5))");
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```

一、典型的先序遍历。

二、典型的递归，需要注意的是:

在调入子树的时候，需要剥离掉外层的括号，这样才能够保持原问题和子问题的一致

三、`split`用于确定左子树的位置

四、上述程序缺少对 负数的处理，所以对于测试用例  "-4(2(3)(1))(6(5)(7))" 无法通过

### 程序二

```C++
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};
class Solution {

	// 确定左子树
	int split(string s, int start, int end) {
		int count = 0;
		int pos = -1; // 左子树的终止位置，显然-1表示没有左子树，没有左子树，其实也就意味着没有右子树
		for (int i = start; i <= end; ++i) {
			if (s[i] == '(') {
				++count;
			}
			if (s[i] == ')') {
				--count;
			}
			if (count == 0) {
				pos = i;
				break;
			}
		}
		return pos;
	}
public:
	TreeNode* str2tree(string s) {
		if (s.size() == 0) {
			return nullptr;
		}
		return str2treeImpl(s, 0, s.size() - 1);
	}

	TreeNode* str2treeImpl(string s, int start, int end) {
		if (start <= end) {
			int valIndex = start; // root的值的起始位置
			while (valIndex <= end && s[valIndex] != '(') {
				++valIndex;
			}
			int valLen = valIndex - start ;
			int val = stoi(s.substr(start, valLen));
			TreeNode* root = new TreeNode(val);
			int leftEnd = split(s, valIndex, end);
			if (leftEnd != -1) { // 有子树，必须要加上这个判断，否则是会导致错误的
				root->left = str2treeImpl(s, valIndex + 1, leftEnd - 1);
				root->right = str2treeImpl(s, leftEnd + 2, end - 1);
			}
			else {
				/*	cout << "危险:" << start + 2 << "," << leftEnd - 1 << endl;
					cout << "危险:" << leftEnd + 2 << "," << end - 1 << endl;*/
			}

			return root;
		}
		else {
			return nullptr;
		}
	}

};

int main()
{
	Solution s;
	s.str2tree("4(2(3)(1))(6(5))");
	s.str2tree("-4(2(3)(1))(6(5)(7))");
	s.str2tree("51(232)(434)");
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```



## 自底向上

