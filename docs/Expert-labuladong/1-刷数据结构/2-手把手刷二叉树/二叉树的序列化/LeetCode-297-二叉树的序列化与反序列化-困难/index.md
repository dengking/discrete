# leetcode [297. 二叉树的序列化与反序列化](https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/) 困难



## 我的解题

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode *root)
	{
		stringstream ss;
		do_serialize(root, ss);
		return ss.str();
	}
	void do_serialize(TreeNode *root, stringstream &ss)
	{
		if (root)
		{
			ss << root->val << ",";
			do_serialize(root->left, ss);
			do_serialize(root->right, ss);
		}
		else
		{
			ss << "N" << ",";
		}
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data)
	{
		list<string> nodes;
		string temp;
		for (auto &&c : data)
		{
			if (c == ',')
			{
				nodes.emplace_back(temp);
				temp.clear();
			}
			else
			{
				temp.push_back(c);
			}
		}
		return do_deserialize(nodes);
	}
	TreeNode* do_deserialize(list<string> &nodes)
	{
		if (nodes.front() == "N")
		{
            nodes.pop_front();
			return nullptr;
		}
		else
		{
			int val = stoi(nodes.front());
			TreeNode *n = new TreeNode { val };
			nodes.pop_front();
			n->left = do_deserialize(nodes);
			n->right = do_deserialize(nodes);
			return n;
		}
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```

