#if defined KNAPSACK
#define KNAPSACK

class Object//����������¼��Ʒ��Ϣ
{
public:
	int operator<=(Object &x)const
	{
		return d <= x.d;
	}

private:
	int ID;//��ƷId
	float d;//��λ�����ļ�ֵ
};

#endif