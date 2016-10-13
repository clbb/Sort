#include<iostream>
using namespace std;

//两个元素比较，后面的小了交换，每次少排一个
//o(n^2)
//n趟 
void BubbleSort(int* a,int n)
{
	if(a == NULL || n == 0 || n == 1)
		return;
	for(int i = 1; i < n; ++i)
	{
		for(int j = 0; j < n-i; ++j)
			if(a[j+1] < a[j])
				std::swap(a[j+1],a[j]);
	}
}
int main()
{
	int a[8] = {4,2,3,5,7,9,0,1};
	BubbleSort(a,8);
	for(int i = 0; i<8; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
