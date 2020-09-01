#if defined HUFFMANTREE_H
#define HUFFMANTREE_H

const int maxBit = 255;
struct HuffmanCode          //存储哈弗曼编码，表示从树根到叶子结点的一条路
{
	int bit[maxBit];
	int weight;
	int length;     //哈弗曼码的长度,从1开始记
	char character;
};


struct HuffmanNode //这是霍夫曼树中的结点
{
	int weight;
	char character;
	bool isLeaf; //是否是叶子结点
	int createSort;   //用于标记节点创建顺序
	int position;   //用于记录节点在树中的位置。以完全二叉树计算的
	//POINT nodePt;   //结点坐标，用于绘图
	HuffmanNode *selfAddress;//存储自身地址
	HuffmanNode *leftChild, *rightChild, *parent;//存储左子节点，右子结点，和父母结点
	HuffmanNode() :leftChild(NULL), rightChild(NULL), parent(NULL){}
	HuffmanNode(int elem, HuffmanNode* left = NULL, HuffmanNode* right = NULL, HuffmanNode* ptr = NULL) :weight(elem),
		leftChild(left), rightChild(right), parent(ptr){}
	bool operator <=(HuffmanNode& R){ return weight <= R.weight; }
	bool operator > (HuffmanNode& R){ return weight > R.weight; }
};




class HuffmanTree
{
public:
	HuffmanTree();
	~HuffmanTree();
	void enCode(char letter[], int n);   //对文章进行编码  ,文章字符与字符总个数
	void deCode();                 //解码，通过给定数据，构建哈弗曼树，然后进行解码
	void createHuffTree(char ch[], int w[], int n);   //创建哈弗曼树
	//void drawTree(CDC* dc);       //图形绘制

	void destroy();
	bool isEmpty(){ return (root == NULL) ? true : false; }
protected:
	//void getNodePt();      //用于得到该节点在图像中应该出现的位置
	//void drawTree(CDC* dc, HuffmanNode* p);

	void mergeTree(HuffmanNode & ht1, HuffmanNode & ht2, HuffmanNode* & parent);//合并两颗子树
	void getHuffmanNode(HuffmanCode huffCode[], int n);   // huffCode[]是赫夫曼编码，此函数的功能是根据编码，找到对应的结点
	HuffmanNode* getNodePostion(int n);
	bool writeHuffNode(HuffmanCode huffCode[], int n);    //编码节点与不重复字符的个数

	void destroy(HuffmanNode* p); //删除树
	int  getHeight(HuffmanNode* subTree);  //求树的高度
	HuffmanNode* getNodeSort(int n);   //取得创建顺序的节点的地址


private:
	HuffmanCode huffCode[128];  //用来存储每个字符的编码
	HuffmanNode* root;  //创建树时规定头节点坐标
	HuffmanNode* deRoot;     //解码时候生成树的树根
	int codeTotal;     //编码节点的个数，即需要多少个huffmancode
	HuffmanNode* rootFull;   //绘画时候需要的满二叉树
	int width;    //绘图左右节点的宽度
	int height;   //绘图上下节点的高度差
	int treeRoot;  //树高度
	int sort;     //创建顺序

public:
	bool isUseTime;
};

#endif 