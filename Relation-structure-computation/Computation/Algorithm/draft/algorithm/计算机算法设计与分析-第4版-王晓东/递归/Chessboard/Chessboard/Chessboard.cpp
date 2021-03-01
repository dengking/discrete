

int tile = 1;
const int max = 20;
int board[max][max];

void Chessboard(int tr, int tc, int dr, int dc, int size);
/*对参数的解释如下：
  1.tr和tc用来定位左上角方格位置
  2.dr和dc用来定位特殊方格位置
  3.size表示棋盘的规模，注意size=2的k次方*/



void Chessboard(int tr, int tc, int dr, int dc, int size)
{
	if (size == 1)return;
	int t = tile++;//此处tile首先赋值给t然后tile自加，则下次递归函数进入
	int s = size / 2;
	//覆盖左上角子棋盘
	if (dr < tr + s&&dc < tc + s){//说明特殊方格在这个子棋盘中
		Chessboard(tr, tc, dr, dc, s);//可以直接把问题规模减小到左上角子棋盘
	}
	else{//特殊方格不在左上角子棋盘中，则用L型骨牌覆盖左上角子棋盘的右下角
		board[tr + s - 1][tc + s - 1] = t;
		Chessboard(tr, tc, tr + s - 1, tc + s - 1, s);
	}
}