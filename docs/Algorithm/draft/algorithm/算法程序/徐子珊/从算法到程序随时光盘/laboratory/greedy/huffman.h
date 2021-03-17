#ifndef _HUFFMAN_H
#define	_HUFFMAN_H
#ifdef	__cplusplus
extern "C" {
#endif
	typedef struct{
		int ch;
		int f;
		int parent;
		int *child;
		char code[16];
	}Node;
	typedef struct{
		Node *Nodes;
		int R;
		int N;
	}HTree;
	void clrHTree(HTree *t);
	HTree Huffman(char *C, int *f, int n, int r);
#ifdef	__cplusplus
}
#endif

#endif	/* _HUFFMAN_H */

