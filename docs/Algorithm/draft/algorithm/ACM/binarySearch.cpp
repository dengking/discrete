//��������ֶ��ֲ��ҵ�д�������ص�ֵ��middle�����������ܹ���֤middle�������е�һ����x��ȵ�Ԫ�ص��±�
int binarySearch(int a[],const int &x,int n){
	int left=0,right=n-1;
	while(left<=right){
		int middle=(left+right)/2;
		if(x==a[middle])return middle;
		if(x<a[middle])right=middle-1;
		else left=middle+1;
	}
	return -1;
}