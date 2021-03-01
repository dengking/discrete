

int tile = 1;
const int max = 20;
int board[max][max];

void Chessboard(int tr, int tc, int dr, int dc, int size);
/*�Բ����Ľ������£�
  1.tr��tc������λ���ϽǷ���λ��
  2.dr��dc������λ���ⷽ��λ��
  3.size��ʾ���̵Ĺ�ģ��ע��size=2��k�η�*/



void Chessboard(int tr, int tc, int dr, int dc, int size)
{
	if (size == 1)return;
	int t = tile++;//�˴�tile���ȸ�ֵ��tȻ��tile�Լӣ����´εݹ麯������
	int s = size / 2;
	//�������Ͻ�������
	if (dr < tr + s&&dc < tc + s){//˵�����ⷽ���������������
		Chessboard(tr, tc, dr, dc, s);//����ֱ�Ӱ������ģ��С�����Ͻ�������
	}
	else{//���ⷽ�������Ͻ��������У�����L�͹��Ƹ������Ͻ������̵����½�
		board[tr + s - 1][tc + s - 1] = t;
		Chessboard(tr, tc, tr + s - 1, tc + s - 1, s);
	}
}