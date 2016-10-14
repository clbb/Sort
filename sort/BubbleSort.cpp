#include<iostream>
using namespace std;
void Print(int a[],int n,int j)
{
	cout<<j<<":";
	for(int i = 0; i<n; ++i)
		cout<<a[i]<<" ";
	cout<<endl;
}
//后面的小于前面，交换
void BubbleSort(int a[],int n)
{
	if(a == NULL || n == 1 || n == 0)
		return;
	
	for(int i = 1; i<n; i++){
		for(int j = 0; j < n-i; ++j)
			if(a[j] > a[j+1])
				std::swap(a[j],a[j+1]);
		Print(a,8,i);
}
}

int main()
{
	int a[8] = {4,2,3,5,7,9,0,1};
	BubbleSort(a,8);
	for(int i = 0; i<8; ++i)
		cout<<a[i]<<" ";
	cout<<endl;	
	return 0;
}
