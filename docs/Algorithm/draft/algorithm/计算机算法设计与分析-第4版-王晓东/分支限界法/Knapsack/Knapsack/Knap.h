#if defined KNAP
#define KNAP


//��������ݳ�Ա������¼��ռ����еĽ����Ϣ
template<class Typew,class Typev>
class Knap{
	friend Typev Knapsack(Typew *,Typev *,Typew,int);//�˺������Ƚ��г�ʼ����Ȼ����ú���Backtrack����������ֵ��Ȼ�������ֵ����
private:
	Typep Bound(int i);//�˺����������㵱ǰ��㼰�������ļ�ֵ�Ͻ�
	void Backtrack(int i);//���ݺ������������Ž�
	Typew c;//����������
	int n;//��Ʒ��
	Typew *w;//��Ʒ��������
	Typev *v;//��Ʒ��ֵ����
	Typew cw;//��ǰ����
	Typev cv;//��ǰ��ֵ
	Typev bestv;//��ǰ���ż�ֵ
};
#endif
