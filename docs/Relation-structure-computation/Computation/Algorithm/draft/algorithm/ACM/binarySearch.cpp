//下面的这种二分查找的写法所返回的值是middle，所以他不能够保证middle是数组中第一个和x相等的元素的下标
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