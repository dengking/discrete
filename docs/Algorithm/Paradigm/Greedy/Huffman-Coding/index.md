# Huffman Coding

---

> References
>
> - wikipedia [Huffman coding](https://en.wikipedia.org/wiki/Huffman_coding) 
> - geeksforgeeks [Huffman Coding | Greedy Algo-3](https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/) 

---



## wikipedia [Huffman coding](https://en.wikipedia.org/wiki/Huffman_coding) 



## C++

```C++
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

class HuffmanTree
{

    // A Tree node
    struct Node
    {
        char ch;
        int freq;
        Node *left, *right;

        Node(char ch, int freq, Node *left, Node *right)
        {
            this->ch = ch;
            this->freq = freq;
            this->left = left;
            this->right = right;
        }
    };

    // Comparison object to be used to order the heap
    struct comp
    {
        bool operator()(Node *l, Node *r)
        {
            // highest priority item has lowest frequency
            return l->freq > r->freq;
        }
    };
    Node *root_{nullptr};
    std::unordered_map<char, std::string> huffmanCode_;

private:
    // traverse the Huffman Tree and store Huffman Codes
    // in a map.
    void initHuffmanCode(Node *root, std::string str)
    {
        if (root == nullptr)
            return;

        // found a leaf node
        if (!root->left && !root->right)
        {
            huffmanCode_[root->ch] = str;
        }

        initHuffmanCode(root->left, str + "0");
        initHuffmanCode(root->right, str + "1");
    }

    // traverse the Huffman Tree and decode the encoded string
    void decodeImpl(Node *root, int &index, const std::string &str)
    {
        if (root == nullptr)
        {
            return;
        }
        if (index > str.size())
        {
            return;
        }
        // found a leaf node
        if (!root->left && !root->right)
        {
            return;
        }
        ++index;
        if (str[index] == '0')
        {
            decodeImpl(root->left, index, str);
        }
        else
        {
            decodeImpl(root->right, index, str);
        }
    }

public:
    // Builds Huffman Tree and decode given input text
    HuffmanTree(const std::string &text)
    {
        // count frequency of appearance of each character
        // and store it in a map
        std::unordered_map<char, int> freq;
        for (char ch : text)
        {
            freq[ch]++;
        }

        // Create a priority queue to store live nodes of
        // Huffman tree;
        std::priority_queue<Node *, std::vector<Node *>, comp> pq;

        // Create a leaf node for each character and add it
        // to the priority queue.
        for (auto &&[c, f] : freq)
        {
            pq.push(new Node(c, f, nullptr, nullptr));
        }

        // do till there is more than one node in the queue
        while (pq.size() != 1)
        {
            // Remove the two nodes of highest priority
            // (lowest frequency) from the queue
            Node *left = pq.top();
            pq.pop();
            Node *right = pq.top();
            pq.pop();

            // Create a new internal node with these two nodes
            // as children and with frequency equal to the sum
            // of the two nodes' frequencies. Add the new node
            // to the priority queue.
            int sum = left->freq + right->freq;
            pq.push(new Node('\0', sum, left, right));
        }

        // root stores pointer to root of Huffman Tree
        root_ = pq.top();

        initHuffmanCode(root_, "");
    }

    std::string encode(const std::string &text)
    {
        // print encoded string
        std::string str;
        for (auto &&ch : text)
        {
            str += huffmanCode_[ch];
        }
    }

    void decode(const std::string &str)
    {
        // traverse the Huffman Tree again and this time
        // decode the encoded string
        int index = -1;
        while (index < (int)str.size() - 2)
        {
            decodeImpl(root_, index, str);
        }
    }
};

// Huffman coding algorithm
int main()
{
    std::string text = "Huffman coding is a data compression algorithm.";

    HuffmanTree t(text);

    return 0;
}
```





## Huffman-tree-vs-trie

一、stackexchange [Is huffman coding tree a heap or a trie?](https://cs.stackexchange.com/questions/96009/is-huffman-coding-tree-a-heap-or-a-trie) 