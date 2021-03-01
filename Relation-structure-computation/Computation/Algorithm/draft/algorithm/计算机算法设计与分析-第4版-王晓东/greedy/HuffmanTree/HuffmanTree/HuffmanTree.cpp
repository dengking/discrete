#include "G:\C++\数据结构\MinHeap\MinHeap.cpp"
#include "HuffmanTree.H"
#include <fstream.>
#include <math.h>
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

HuffmanTree::HuffmanTree()
{
	sort = 1;
	root = NULL;
	width = 10;
	height = 50;
	treeRoot = 1;
}
////////////////////
HuffmanTree::~HuffmanTree()
{
	destroy(root);
}
//////////////
void HuffmanTree::destroy()
{
	destroy(root);
}
/////////////////
void HuffmanTree::destroy(HuffmanNode* p)
{
	if (p != NULL)
	{
		destroy(p->leftChild);
		destroy(p->rightChild);
		delete p;
	}
}
////////////////////////////////////
